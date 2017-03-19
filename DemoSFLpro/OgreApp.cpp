#include "OgreApp.h"
#include "ColouredRectangle2D.h"
#include "OgreCoordinateAxes.h"
#include "ViewportGrid.h"
#include "OgrePipe.h"

OgreApp::OgreApp(System::Windows::Forms::Panel^ panel)
	: m_Root(0)
	, m_PluginsCfg(Ogre::BLANKSTRING)
	, m_ResourcesCfg(Ogre::BLANKSTRING)
	, m_Log(0)
	, m_RenderSystem(0)
	, m_RenderWindow(0)
	//, m_PanelHandle(0)
	, m_RenderWindowWidth(panel->Width)
	, m_RenderWindowHeight(panel->Height)
	, m_SceneManager(0)
	, m_Viewport(0)
	, m_Camera(0)
	, m_CameraNode(0)
	, m_Target(0)
	, m_CoordinateAxesSceneNode(0)
	, m_IsLeftDrag(false)
	, m_IsMiddleDrag(false)
	, m_IsRightDrag(false)
	, m_TabPage(nullptr)

{
	this->m_Panel = panel;
	this->m_usePanel = true;
#ifdef _DEBUG
	m_ResourcesCfg = "resources_d.cfg";
	m_PluginsCfg = "plugins_d.cfg";
#else
	m_ResourcesCfg = "resources.cfg";
	m_PluginsCfg = "plugins.cfg";
#endif
}

OgreApp::OgreApp(System::Windows::Forms::TabPage^ tabPage)
	: m_Root(0)
	, m_PluginsCfg(Ogre::BLANKSTRING)
	, m_ResourcesCfg(Ogre::BLANKSTRING)
	, m_Log(0)
	, m_RenderSystem(0)
	, m_RenderWindow(0)
	//, m_PanelHandle(0)
	, m_RenderWindowWidth(tabPage->Width)
	, m_RenderWindowHeight(tabPage->Height)
	, m_SceneManager(0)
	, m_Viewport(0)
	, m_Camera(0)
	, m_CameraNode(0)
	, m_Target(0)
	, m_CoordinateAxesSceneNode(0)
	, m_IsLeftDrag(false)
	, m_IsMiddleDrag(false)
	, m_IsRightDrag(false)
	, m_Panel(nullptr)

{
	this->m_TabPage = tabPage;
	this->m_usePanel = false;
#ifdef _DEBUG
	m_ResourcesCfg = "resources_d.cfg";
	m_PluginsCfg = "plugins_d.cfg";
#else
	m_ResourcesCfg = "resources.cfg";
	m_PluginsCfg = "plugins.cfg";
#endif
}


OgreApp::~OgreApp()
{
}

int OgreApp::GetFPS()
{
	// get the stats from the render window
	const Ogre::RenderTarget::FrameStats & frameStats = m_RenderWindow->getStatistics();

	// send it back
	return int(frameStats.avgFPS);
}

bool OgreApp::InitializeRoot()
{
	// create the root node
	m_Root = new Ogre::Root(m_PluginsCfg);
	m_Log = Ogre::LogManager::getSingletonPtr()->getDefaultLog();
	return true;
}


bool OgreApp::InitializeRenderer()
{

	// initialize the render window
	if (!(m_Root->restoreConfig() || m_Root->showConfigDialog()))
		return false;
	else
	{
		HWND hWnd = nullptr;
		Ogre::NameValuePairList params;
		if (this->m_usePanel)
			hWnd = (HWND)m_Panel->Handle.ToPointer();//m_PanelHandle;
		else
			hWnd = (HWND)m_TabPage->Handle.ToPointer();
		params["externalWindowHandle"] = Ogre::StringConverter::toString(reinterpret_cast<unsigned int>(hWnd));

		// initialise root
		this->m_Root->initialise(false);

		// create main window
		this->m_RenderWindow = m_Root->createRenderWindow("OgreRenderWindow",
			m_RenderWindowWidth,
			m_RenderWindowHeight,
			false,
			&params);
		this->m_RenderWindow->setActive(true);
		this->m_SceneManager = m_Root->createSceneManager(Ogre::ST_GENERIC);


		//Camera		
		m_Camera = m_SceneManager->createCamera("PlayerCam");
		m_Camera->setNearClipDistance(0.01f);
		m_Target = m_SceneManager->getRootSceneNode()->createChildSceneNode();
		m_Target->setPosition(Ogre::Vector3(0.0f, 1.0f, 0.0f));
		m_CameraNode = m_Target->createChildSceneNode();
		m_CameraNode->translate(Ogre::Vector3(0.0f, 0.0f, 100.0f), Ogre::Node::TS_PARENT);
		m_Camera->setPosition(m_Target->convertLocalToWorldPosition(m_CameraNode->getPosition()));
		m_Camera->lookAt(m_Target->getPosition());
		m_CameraNode->attachObject(m_Camera);
		m_TrackBall = new TrackBall(m_Panel->Width, m_Panel->Height);
		m_OldOrientation = m_NewOrientation = m_Target->getOrientation();
		m_OldMousePos = Ogre::Vector2::ZERO;;

		// Create one viewport, entire window
		this->m_Viewport = m_RenderWindow->addViewport(m_Camera);
		this->m_Viewport->setBackgroundColour(Ogre::ColourValue(0, 0, 1.0f));
		// Alter the camera aspect ratio to match the viewport
		this->m_Camera->setAspectRatio(Ogre::Real(m_Viewport->getActualWidth()) / Ogre::Real(m_Viewport->getActualHeight()));

		// set default mipmap level
		Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
		return true;
	}
}

bool OgreApp::ReadResources()
{
	// load resource paths from config file
	Ogre::ConfigFile cf;
	cf.load(m_ResourcesCfg);

	// go through all sections & settings in the file
	Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

	Ogre::String secName, typeName, archName;

	while (seci.hasMoreElements())
	{
		secName = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator i;

		for (i = settings->begin(); i != settings->end(); ++i)
		{
			typeName = i->first;
			archName = i->second;
			Ogre::ResourceGroupManager::getSingleton().
				addResourceLocation(archName, typeName, secName);
		}
	}

	return true;
}

bool OgreApp::LoadResources(void)
{
	// initialise, parse scripts etc
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	Ogre::MaterialPtr lMaterial = Ogre::MaterialManager::getSingleton().create("M_LightingColor", "General");
	Ogre::Technique* lFirstTechnique = lMaterial->getTechnique(0);
	Ogre::Pass* lFirstPass = lFirstTechnique->getPass(0);
	lFirstPass->setLightingEnabled(true);
	Ogre::ColourValue lSelfIllumnationColour(0.1f, 0.0f, 0.0f, 1.0f);
	//lFirstPass->setSelfIllumination(lSelfIllumnationColour);
	Ogre::ColourValue lDiffuseColour(1.0f, 0.4f, 0.4f, 1.0f);
	lFirstPass->setDiffuse(lDiffuseColour);
	Ogre::ColourValue lAmbientColour(0.4f, 0.1f, 0.1f, 1.0f);
	lFirstPass->setAmbient(lAmbientColour);
	Ogre::ColourValue lSpecularColour(1.0f, 1.0f, 1.0f, 1.0f);
	lFirstPass->setSpecular(lSpecularColour);
	Ogre::Real lShininess = 128.0f;
	lFirstPass->setShininess(lShininess);
	//lMaterial->setCullingMode(Ogre::CULL_NONE);
	//lMaterial->setReceiveShadows(true);
	return true;
}

void OgreApp::SetupEnvironment(void)
{


	Ogre::Entity* ogreEntity = m_SceneManager->createEntity("ogrehead.mesh");
	Ogre::SceneNode* ogreNode = m_SceneManager->getRootSceneNode()->createChildSceneNode("roothead");
	ogreNode->attachObject(ogreEntity);
	m_SceneManager->setAmbientLight(Ogre::ColourValue(.5, .5, .5));
	Ogre::Light* light = m_SceneManager->createLight("MainLight");
	light->setPosition(20000, 80000, 50000);

	/********* GRADIENT BACKGROUND *********/
	//Create background material
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Background", "General");
	material->setDepthCheckEnabled(false);
	material->setDepthWriteEnabled(false);
	material->setLightingEnabled(false);
	// Create background rectangle covering the whole screen
	ColouredRectangle2D* rect = new ColouredRectangle2D();
	rect->setCorners(-1.0, 1.0, 1.0, -1.0);
	rect->setMaterial("Background");
	// Set the colours
	rect->setColours(Ogre::ColourValue(0.670588f, 0.937255f, 1.0f, 0.8f), Ogre::ColourValue(0.772549f, 1.0f, 0.772549f, 0.3f),
		Ogre::ColourValue(0.670588f, 0.937255f, 1.0f, 0.8f), Ogre::ColourValue(0.772549f, 1.0f, 0.772549f, 0.3f));
	// Render the background before everything else
	rect->setRenderQueueGroup(Ogre::RENDER_QUEUE_BACKGROUND);
	// Use infinite AAB to always stay visible
	Ogre::AxisAlignedBox aabInf;
	aabInf.setInfinite();
	rect->setBoundingBox(aabInf);
	// Attach background to the scene
	Ogre::SceneNode* node = m_SceneManager->getRootSceneNode()->createChildSceneNode("Background");
	node->attachObject(rect);

	/********* WORLD COORDINATE AXES *********/
	OgreCoordinateAxes* coordAxes = new OgreCoordinateAxes(m_SceneManager);

	/********* DYNAMIC VIEWPORT GRID *********/
	Ogre::ViewportGrid* vg = new Ogre::ViewportGrid(m_SceneManager, m_Viewport);
	vg->setRenderMiniAxes();
	vg->setRenderScale();
	vg->enable();


	addPipe(Ogre::Vector3(-20, -10, 10), "003");

	m_Root->addFrameListener(this);

}

void OgreApp::ResizeRenderWindow(int pWidth, int pHeight)
{
	m_RenderWindowWidth = m_RenderWindow->getWidth();
	m_RenderWindowHeight = m_RenderWindow->getHeight();

	m_RenderWindow->resize(pWidth, pHeight);
	m_RenderWindow->windowMovedOrResized();

	m_RenderWindowWidth = m_RenderWindow->getWidth();
	m_RenderWindowHeight = m_RenderWindow->getHeight();
}

int OgreApp::getFPS(void)
{
	// get the stats from the render window
	const Ogre::RenderTarget::FrameStats & frameStats = m_RenderWindow->getStatistics();

	// send it back
	return int(frameStats.avgFPS);
}

bool OgreApp::frameRenderingQueued(const Ogre::FrameEvent& evt)
{

	if (m_Panel->IsDisposed) return false;
	return this->UpdateFrameRenderingQueued(evt);
}

void OgreApp::LaunchOgre()
{
	if (SetupOgre())
	{
		this->OgreStarted = true;
		m_Root->startRendering();

		// Clean up
		this->DisposeOgre();
	}
}

bool OgreApp::SetupOgre()
{
	bool isRoot = this->InitializeRoot();
	bool isReadRes = this->ReadResources();
	bool isRender = this->InitializeRenderer();
	bool isLoadRes = this->LoadResources();

	if (m_Root->isInitialised())
	{
		this->SetupEnvironment();
		return true;
	}
	else return false;
}


void OgreApp::DisposeOgre()
{

}

bool OgreApp::UpdateFrameRenderingQueued(const Ogre::FrameEvent& evt)
{
	(void)evt;
	return true;
}



void OgreApp::OnMouseDown(System::Object^ sender, Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == MouseButtons::Middle)
	{
		this->m_IsMiddleDrag = true;
		m_OldOrientation = m_NewOrientation;
		m_TrackBall->Click(Ogre::Vector2(Ogre::Real(e->X), Ogre::Real(e->Y)));
	}
	if (e->Button == MouseButtons::Right)
	{
		this->m_IsRightDrag = true;
		m_OldMousePos = Ogre::Vector2(Ogre::Real(e->X), Ogre::Real(e->Y));
	}
}



void OgreApp::OnMouseUp(System::Object^ sender, Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == MouseButtons::Middle)
		this->m_IsMiddleDrag = false;
	if (e->Button == MouseButtons::Right)
		this->m_IsRightDrag = false;

}

void OgreApp::OnMouseMove(System::Object^ sender, Windows::Forms::MouseEventArgs^ e)
{


	if (m_IsMiddleDrag)
	{
		Ogre::Quaternion RotQuat = m_TrackBall->Drag(Ogre::Vector2(Ogre::Real(e->X), Ogre::Real(e->Y)));
		m_NewOrientation = m_OldOrientation * RotQuat;
		m_Target->setOrientation(m_NewOrientation);
	}
	if (m_IsRightDrag)
	{
		Ogre::Real len = m_CameraNode->getPosition().length();
		if (len < 1) len = 1;

		Ogre::Real deltaX = len * (Ogre::Real(e->X) - m_OldMousePos.x) / m_Panel->Width;
		Ogre::Real deltaY = len * (Ogre::Real(e->Y) - m_OldMousePos.y) / m_Panel->Height;
		Ogre::Real fx = (m_TrackBall->m_BotRight - m_TrackBall->m_BotLeft).length();
		Ogre::Real fy = (m_TrackBall->m_BotRight - m_TrackBall->m_TopRight).length();
		//fx = fy = 1;
		m_Target->translate(-fx * deltaX, fy * deltaY, 0, Ogre::Node::TS_LOCAL);
		m_OldMousePos.x = e->X; m_OldMousePos.y = e->Y;
	}
}

void OgreApp::OnMouseWheel(System::Object^ sender, Windows::Forms::MouseEventArgs^ e)
{
	Ogre::Real len = m_CameraNode->getPosition().length();
	Ogre::Real zCoord = 30.0f * (len / Ogre::Math::Abs(e->Delta)) > 5.0f ? (30.0f * len / e->Delta) : (5.0f * e->Delta / Ogre::Math::Abs(e->Delta));
	Ogre::Vector3 trans = Ogre::Vector3(0, 0, zCoord);
	m_CameraNode->translate(trans, Ogre::Node::TS_PARENT);
}

void OgreApp::OnPanelResize(System::Object^  sender, System::EventArgs^  e, System::Windows::Forms::Panel^ panel)
{
	m_Panel = panel;
	this->m_Camera->setAspectRatio(Ogre::Real(m_Panel->Width) / Ogre::Real(m_Panel->Height));
	m_TrackBall->SetBounds(m_Panel->Width, m_Panel->Height);
}

void OgreApp::addPipe(Ogre::Vector3 pos, Ogre::String name)
{


	//m_Camera->lookAt(0, 0, 0);
	//mCameraMan->setLookAt(Ogre::Vector3(0, 0, 0));
	//mAddPipe = false;
	OgrePipe* op1 = new OgrePipe(1, 10, 20);
	OgrePipe* op2 = new OgrePipe(1, 20, 30);
	OgrePipe* op3 = new OgrePipe(1, 30, 40);
	Ogre::Real r = 20.0f;
	op1->useSceneManager(this->m_SceneManager);
	//Ogre::MeshPtr sph = ogrePipe->createSphere("Sphere", r,100,100);// , const int nRings = 16, const int nSegments = 16)
	//Ogre::MeshPtr cyl = ogrePipe->createCylinder("Cylinder", r, 50.0);// , const int nRings = 16, const int nSegments = 16)
	//Ogre::MeshPtr ann = ogrePipe->createAnnulus("Annulus", r, r-5);// , const int nRings = 16, const int nSegments = 16)
	Ogre::MeshPtr b1 = op1->createTorus("bend45", r, 3.0 * r, 45, 25, 25);
	Ogre::MeshPtr p1 = op2->createCylinder("pipe50m", r, 500, 25, 25);
	Ogre::MeshPtr p2 = op3->createCylinder("pipe5m", r, 100, 25, 25);
	//Ogre::MeshPtr con = ogrePipe->createCone("Cone", r, r, 50.0);
	Ogre::Entity* e1 = m_SceneManager->createEntity(p1);
	Ogre::Entity* e2 = m_SceneManager->createEntity(b1);
	Ogre::Entity* e3 = m_SceneManager->createEntity(p2);
	Ogre::Entity* e4 = m_SceneManager->createEntity(b1);
	Ogre::Entity* e5 = m_SceneManager->createEntity(p1);

	const Ogre::String& matName = "M_LightingColor";
	e1->setMaterialName(matName);
	//e1->setCastShadows(true);
	e2->setMaterialName(matName);
	e2->setCastShadows(true);
	e3->setMaterialName(matName);
	e3->setCastShadows(true);
	e4->setMaterialName(matName);
	e4->setCastShadows(true);
	e5->setMaterialName(matName);
	e5->setCastShadows(true);

	

	Ogre::SceneNode* n1 = m_SceneManager->getRootSceneNode()->createChildSceneNode();
	Ogre::SceneNode* n2 = n1->createChildSceneNode();
	Ogre::SceneNode* n3 = n2->createChildSceneNode();
	Ogre::SceneNode* n4 = n3->createChildSceneNode();
	Ogre::SceneNode* n5 = n4->createChildSceneNode();

	n1->attachObject(e1);
	n2->attachObject(e2);
	n3->attachObject(e3);
	n2->translate(0, 0, 500);
	n2->rotate(Ogre::Vector3(0, 0, 1), Ogre::Degree(-90));
	n2->rotate(Ogre::Vector3(0, 1, 0), Ogre::Degree(-90));
	n3->rotate(Ogre::Vector3(0, 1, 0), Ogre::Degree(135));
	
	//n1->rotate(Ogre::Vector3(0, 1, 0), Ogre::Degree(90));
	//n1->translate(0, 100, 0);
	//n2->attachObject(e2);
	//n3->attachObject(e3);
	//n4->attachObject(e4);
	//n5->attachObject(e5);


	//nn->rotate(Ogre::Vector3(0, 1, 0), Ogre::Degree(90));
	//nn->translate(Ogre::Vector3(-25,0, 0)); 

}