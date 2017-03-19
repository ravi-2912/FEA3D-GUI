#include "OgreCoordinateAxes.h"
#include "OgreMaterial.h"
#include "OgreMaterialManager.h"


#define LEN		5.0f

OgreCoordinateAxes::OgreCoordinateAxes(Ogre::SceneManager* sceneManager)
	: m_SceneManager(sceneManager)
	, m_CoordinateAxesSceneNode(0)
	, m_CoordinateAxesManualObject(0)
{
	setAxisMaterials();
	generateCoordinateAxes();
}


OgreCoordinateAxes::~OgreCoordinateAxes()
{
}

void OgreCoordinateAxes::setAxisMaterials()
{
	m_xAxisMat = Ogre::MaterialManager::getSingleton().create("xAxisMat", "General");
	Ogre::ColourValue blue = Ogre::ColourValue(0.0f, 0.0f, 0.8f);
	m_xAxisMat->setReceiveShadows(false);
	m_xAxisMat->setLightingEnabled(true);
	m_xAxisMat->setDiffuse(blue);
	m_xAxisMat->setAmbient(blue);
	m_xAxisMat->setSelfIllumination(blue);

	m_yAxisMat = Ogre::MaterialManager::getSingleton().create("yAxisMat", "General");
	Ogre::ColourValue green = Ogre::ColourValue(0.0f, 0.5f, 0.0f);
	m_yAxisMat->setReceiveShadows(false);
	m_yAxisMat->setLightingEnabled(true);
	m_yAxisMat->setDiffuse(green);
	m_yAxisMat->setAmbient(green);
	m_yAxisMat->setSelfIllumination(green);

	m_zAxisMat = Ogre::MaterialManager::getSingleton().create("zAxisMat", "General");
	Ogre::ColourValue red = Ogre::ColourValue(0.75f, 0.0f, 0.0f);
	m_zAxisMat->setReceiveShadows(false);
	m_zAxisMat->setLightingEnabled(true);
	m_zAxisMat->setDiffuse(red);
	m_zAxisMat->setAmbient(red);
	m_zAxisMat->setSelfIllumination(red);
}

void OgreCoordinateAxes::generateCoordinateAxes()
{
	m_CoordinateAxesManualObject = m_SceneManager->createManualObject("RootCoordinateAxes");
	m_CoordinateAxesSceneNode = m_SceneManager->getRootSceneNode()->createChildSceneNode("RootCoordinateAxesSceneNode");

	axisLine(Ogre::Vector3::ZERO, Ogre::Vector3(LEN, 0, 0), "xAxisMat");
	axisCone(X, 3.0f*LEN / 5.0f, 0.5f*LEN / 5.0f, "xAxisMat");
	axisLine(Ogre::Vector3::ZERO, Ogre::Vector3(0, LEN, 0), "yAxisMat");
	axisCone(Y, 3.0f*LEN / 5.0f, 0.5f*LEN / 5.0f, "yAxisMat");
	axisLine(Ogre::Vector3::ZERO, Ogre::Vector3(0, 0, LEN), "zAxisMat");
	axisCone(Z, 3.0f*LEN / 5.0f, 0.5f*LEN / 5.0f, "zAxisMat");

	m_CoordinateAxesManualObject->setCastShadows(false);
	m_CoordinateAxesSceneNode->attachObject(this->m_CoordinateAxesManualObject);
}


void OgreCoordinateAxes::axisLine(Ogre::Vector3 start, Ogre::Vector3 end, Ogre::String colorName)
{
	m_CoordinateAxesManualObject->begin(colorName, Ogre::RenderOperation::OT_LINE_LIST);
	m_CoordinateAxesManualObject->position(start);
	m_CoordinateAxesManualObject->position(end);
	m_CoordinateAxesManualObject->end();
}

void OgreCoordinateAxes::axisCone(AxisLabel axis, Ogre::Real coneLength, Ogre::Real coneRadius, Ogre::String colorName)
{

	// v2 should be (0, 1, 0)
	const int circle_resolution = 72;
	int loop_count;

	Ogre::Real cone_start = LEN;
	Ogre::Real cone_length = coneLength;
	Ogre::Real cone_radius = coneRadius;

	Ogre::Degree theta = (Ogre::Degree)0;
	Ogre::Degree alpha = (Ogre::Degree)360 / circle_resolution;

	Ogre::Vector3 cone_circle[circle_resolution];
	Ogre::Vector3 cone_circle_center;

	switch (axis)
	{
	case X:
		cone_circle_center.x = cone_start;
		cone_circle_center.y = 0.0f;
		cone_circle_center.z = 0.0f;
		break;
	case Y:
		cone_circle_center.x = 0.0f;
		cone_circle_center.y = cone_start;
		cone_circle_center.z = 0.0f;
		break;
	case Z:
		cone_circle_center.x = 0.0f;
		cone_circle_center.y = 0.0f;
		cone_circle_center.z = cone_start;
		break;
	default:
		break;
	}

	for (loop_count = 0; loop_count < circle_resolution; loop_count++)
	{
		theta += alpha;
		switch (axis)
		{
		case X:
			cone_circle[loop_count].x = cone_start;
			cone_circle[loop_count].y = Ogre::Math::Sin(theta) * cone_radius;
			cone_circle[loop_count].z = Ogre::Math::Cos(theta) * cone_radius;
			break;
		case Y:
			cone_circle[loop_count].x = Ogre::Math::Sin(theta) * cone_radius;
			cone_circle[loop_count].y = cone_start;
			cone_circle[loop_count].z = Ogre::Math::Cos(theta) * cone_radius;
			break;
		case Z:
			cone_circle[loop_count].x = Ogre::Math::Sin(theta) * cone_radius;
			cone_circle[loop_count].y = Ogre::Math::Cos(theta) * cone_radius;
			cone_circle[loop_count].z = cone_start;
			break;
		default:
			break;
		}

	}

	/*********************** Cone circular base **********************/
	m_CoordinateAxesManualObject->begin(colorName, Ogre::RenderOperation::OT_TRIANGLE_FAN);

	m_CoordinateAxesManualObject->position(cone_circle_center);

	for (loop_count = 0; loop_count < circle_resolution; loop_count++)
		m_CoordinateAxesManualObject->position(cone_circle[loop_count]);

	m_CoordinateAxesManualObject->position(cone_circle[0]);
	m_CoordinateAxesManualObject->end();

	/********************** Cone curved surface **********************/
	m_CoordinateAxesManualObject->begin(colorName, Ogre::RenderOperation::OT_TRIANGLE_FAN);
	m_CoordinateAxesManualObject->colour(Ogre::ColourValue(0.2f, 0.6f, 1.0f));
	Ogre::Vector3 cone_point = cone_circle_center;
	switch (axis)
	{
	case X:
		cone_point.x += cone_length;
		break;
	case Y:
		cone_point.y += cone_length;
		break;
	case Z:
		cone_point.z += cone_length;
		break;
	default:
		break;
	}

	m_CoordinateAxesManualObject->position(cone_point);

	for (loop_count = circle_resolution - 1; loop_count >= 0; --loop_count)
		m_CoordinateAxesManualObject->position(cone_circle[loop_count]);

	m_CoordinateAxesManualObject->position(cone_circle[circle_resolution - 1]);
	m_CoordinateAxesManualObject->end();


}