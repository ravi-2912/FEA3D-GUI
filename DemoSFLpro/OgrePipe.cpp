#include "OgrePipe.h"

#include "Ogre.h"
#include "OgrePass.h"
#include "OgreTechnique.h"
#include "OgreMaterial.h"
#include "OgreMaterialManager.h"
#include "OgreManualObject.h"
#include "OgreNode.h"
#include "OgreSceneNode.h"


OgrePipe::OgrePipe(unsigned int elementID, unsigned int startID, unsigned int endID)
	: OgrePipelineElement(PIPE)
	, m_PipeLength(0)
	, m_DX(0), m_DY(0), m_DZ(0)
	, m_theta(0), m_phi(0), m_gamma(0)
{
	this->m_ElementID = elementID;
	this->m_StartCoordinateID = startID;
	this->m_EndCoordinateID = endID;
	this->m_ElementName = "Pipe" + Ogre::StringConverter::toString(m_ElementID);

	this->m_ElementObject = new Ogre::ManualObject(m_ElementName);

	this->m_OuterDiameter = 0;
	this->m_WallThickness = 0;

	//m_xAxisMat = Ogre::MaterialManager::getSingleton().create("pipecolor", "General");
	//Ogre::ColourValue blue = Ogre::ColourValue(1.0f, 0.0f, 0.0f, 1.0f);
	//m_xAxisMat->setReceiveShadows(true);
	//m_xAxisMat->setLightingEnabled(true);
	//m_xAxisMat->setAmbient(Ogre::ColourValue(0.0f, 0.0f, 0.0f, 1.0f));
	//m_xAxisMat->setDiffuse(Ogre::ColourValue(0.0f, 0.0f, 1.0f, 1.0f));
	//m_xAxisMat->setSpecular(Ogre::ColourValue(0.1f, 0.1f, 0.1f, 1.0f));
	//m_xAxisMat->
	//m_xAxisMat->setAmbient(blue);
	//m_xAxisMat->setSelfIllumination(blue);


}

OgrePipe::~OgrePipe()
{

}

void OgrePipe::setPipeLenth(Ogre::Real pipeLength)
{
	this->m_PipeLength = pipeLength;
}

Ogre::Real OgrePipe::getPipeLength()
{
	return this->m_PipeLength;
}

void OgrePipe::setPipeGeometry(Ogre::Real outerDiameter, Ogre::Real wallThickness,
	Ogre::Real pipelength, unsigned int circleSubDivision /*=120*/)
{
	this->m_OuterDiameter = outerDiameter;
	this->m_WallThickness = wallThickness;
	this->m_PipeLength = pipelength;
	this->m_CircleSubDivision = circleSubDivision;
	this->m_StartCoordinate = this->m_EndCoordinate = Ogre::Vector3(Ogre::Vector3::ZERO);
	this->m_EndCoordinate.x = this->m_PipeLength;
}

Ogre::ManualObject* OgrePipe::getElementObject()
{
	int circle_resolution = this->m_CircleSubDivision;
	int loop_count;

	Ogre::Real od = this->m_OuterDiameter;
	Ogre::Real id = od - 2 * this->m_WallThickness;

	Ogre::Degree theta = (Ogre::Degree)0.0f;
	Ogre::Degree alpha = (Ogre::Degree)360.0f / circle_resolution;

	std::vector<Ogre::Vector3> cylinder_circle1od(m_CircleSubDivision, Ogre::Vector3::ZERO);
	std::vector<Ogre::Vector3> cylinder_circle1id(m_CircleSubDivision, Ogre::Vector3::ZERO);
	std::vector<Ogre::Vector3> cylinder_circle2od(m_CircleSubDivision, Ogre::Vector3::ZERO);
	std::vector<Ogre::Vector3> cylinder_circle2id(m_CircleSubDivision, Ogre::Vector3::ZERO);

	Ogre::Vector3 cylinder_circle1_center = this->m_StartCoordinate;
	Ogre::Vector3 cylinder_circle2_center = this->m_EndCoordinate;


	for (loop_count = 0; loop_count < circle_resolution; loop_count++)
	{
		theta += alpha;
		cylinder_circle1od.at(loop_count).x = cylinder_circle1_center.x;
		cylinder_circle1od.at(loop_count).y = Ogre::Math::Sin(theta) * od / 2.0f;
		cylinder_circle1od.at(loop_count).z = Ogre::Math::Cos(theta) * od / 2.0f;
		cylinder_circle1id.at(loop_count).x = cylinder_circle1_center.x;
		cylinder_circle1id.at(loop_count).y = Ogre::Math::Sin(theta) * id / 2.0f;
		cylinder_circle1id.at(loop_count).z = Ogre::Math::Cos(theta) * id / 2.0f;

		cylinder_circle2od.at(loop_count).x = cylinder_circle2_center.x;
		cylinder_circle2od.at(loop_count).y = Ogre::Math::Sin(theta) * od / 2.0f;
		cylinder_circle2od.at(loop_count).z = Ogre::Math::Cos(theta) * od / 2.0f;
		cylinder_circle2id.at(loop_count).x = cylinder_circle2_center.x;
		cylinder_circle2id.at(loop_count).y = Ogre::Math::Sin(theta) * id / 2.0f;
		cylinder_circle2id.at(loop_count).z = Ogre::Math::Cos(theta) * id / 2.0f;
	}



	/******************* Left circular base of pipe ******************/
	this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	this->m_ElementObject->colour(Ogre::ColourValue(0.0f, 0.0f, 1.0f));

	for (loop_count = 0; loop_count < circle_resolution / 2; loop_count++)
	{
		this->m_ElementObject->position(cylinder_circle1id.at(loop_count));
		this->m_ElementObject->normal(cylinder_circle1id.at(loop_count).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle1od.at(loop_count));
		this->m_ElementObject->normal(cylinder_circle1od.at(loop_count).normalisedCopy());

		this->m_ElementObject->index(loop_count);
		this->m_ElementObject->index(loop_count + 1);
		this->m_ElementObject->index(loop_count + 2);
		this->m_ElementObject->index(loop_count + 2);
		this->m_ElementObject->index(loop_count + 1);
		this->m_ElementObject->index(loop_count + 3);

		this->m_ElementObject->index(loop_count + circle_resolution);
		this->m_ElementObject->index(loop_count + 1 + circle_resolution);
		this->m_ElementObject->index(loop_count + 2 + circle_resolution);
		this->m_ElementObject->index(loop_count + 2 + circle_resolution);
		this->m_ElementObject->index(loop_count + 1 + circle_resolution);
		this->m_ElementObject->index(loop_count + 3 + circle_resolution);
	}

	this->m_ElementObject->index(loop_count);
	this->m_ElementObject->index(loop_count + 1);
	this->m_ElementObject->index(loop_count + 2);
	this->m_ElementObject->index(loop_count + 2);
	this->m_ElementObject->index(loop_count + 1);
	this->m_ElementObject->index(loop_count + 3);

	this->m_ElementObject->index(loop_count + circle_resolution);
	this->m_ElementObject->index(loop_count + 1 + circle_resolution);
	this->m_ElementObject->index(loop_count + 2 + circle_resolution);
	this->m_ElementObject->index(loop_count + 2 + circle_resolution);
	this->m_ElementObject->index(loop_count + 1 + circle_resolution);
	this->m_ElementObject->index(loop_count + 3 + circle_resolution);



	this->m_ElementObject->end();

	/******************** Cylinder curved surfaces *******************/
	// Outer Surface
	this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	this->m_ElementObject->colour(Ogre::ColourValue(0.2f, 0.6f, 1.0f));


	for (loop_count = 0; loop_count < circle_resolution - 1; loop_count++)
	{
		// Outer Surface
		this->m_ElementObject->position(cylinder_circle1od.at(loop_count));
		this->m_ElementObject->normal(cylinder_circle1od.at(loop_count).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle2od.at(loop_count));
		this->m_ElementObject->normal(cylinder_circle2od.at(loop_count).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle1od.at(loop_count + 1));
		this->m_ElementObject->normal(cylinder_circle1od.at(loop_count + 1).normalisedCopy());

		this->m_ElementObject->position(cylinder_circle1od.at(loop_count + 1));
		this->m_ElementObject->normal(cylinder_circle1od.at(loop_count + 1).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle2od.at(loop_count));
		this->m_ElementObject->normal(cylinder_circle2od.at(loop_count).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle2od.at(loop_count + 1));
		this->m_ElementObject->normal(cylinder_circle2od.at(loop_count + 1).normalisedCopy());

		// Inner Surface
		this->m_ElementObject->position(cylinder_circle1id.at(loop_count + 1));
		this->m_ElementObject->normal(cylinder_circle1id.at(loop_count + 1).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle2id.at(loop_count));
		this->m_ElementObject->normal(cylinder_circle2id.at(loop_count).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle1id.at(loop_count));
		this->m_ElementObject->normal(cylinder_circle1id.at(loop_count).normalisedCopy());

		this->m_ElementObject->position(cylinder_circle2id.at(loop_count + 1));
		this->m_ElementObject->normal(cylinder_circle2id.at(loop_count + 1).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle2id.at(loop_count));
		this->m_ElementObject->normal(cylinder_circle2id.at(loop_count).normalisedCopy());
		this->m_ElementObject->position(cylinder_circle1id.at(loop_count + 1));
		this->m_ElementObject->normal(cylinder_circle1id.at(loop_count + 1).normalisedCopy());
	}
	// Outer surface
	this->m_ElementObject->position(cylinder_circle1od.at(loop_count));
	this->m_ElementObject->normal(cylinder_circle1od.at(loop_count).normalisedCopy());
	this->m_ElementObject->position(cylinder_circle2od.at(loop_count));
	this->m_ElementObject->normal(cylinder_circle2od.at(loop_count).normalisedCopy());
	this->m_ElementObject->position(cylinder_circle1od.at(0));
	this->m_ElementObject->normal(cylinder_circle1od.at(0).normalisedCopy());

	this->m_ElementObject->position(cylinder_circle1od.at(0));
	this->m_ElementObject->normal(cylinder_circle1od.at(0).normalisedCopy());
	this->m_ElementObject->position(cylinder_circle2od.at(loop_count));
	this->m_ElementObject->normal(cylinder_circle2od.at(loop_count).normalisedCopy());
	this->m_ElementObject->position(cylinder_circle2od.at(0));
	this->m_ElementObject->normal(cylinder_circle2od.at(0).normalisedCopy());

	//Inner Surface
	this->m_ElementObject->position(cylinder_circle1id.at(0));
	this->m_ElementObject->normal(cylinder_circle1id.at(0).normalisedCopy());
	this->m_ElementObject->position(cylinder_circle2id.at(loop_count));
	this->m_ElementObject->normal(cylinder_circle2id.at(loop_count).normalisedCopy());
	this->m_ElementObject->position(cylinder_circle1id.at(loop_count));
	this->m_ElementObject->normal(cylinder_circle1id.at(loop_count).normalisedCopy());

	this->m_ElementObject->position(cylinder_circle2id.at(0));
	this->m_ElementObject->normal(cylinder_circle2id.at(0).normalisedCopy());
	this->m_ElementObject->position(cylinder_circle2id.at(loop_count));
	this->m_ElementObject->normal(cylinder_circle2id.at(loop_count).normalisedCopy());
	this->m_ElementObject->position(cylinder_circle1id.at(0));
	this->m_ElementObject->normal(cylinder_circle1id.at(0).normalisedCopy());

	this->m_ElementObject->end();

	/****************** Right circular base of pipe ******************/
	this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	this->m_ElementObject->colour(Ogre::ColourValue(0.0f, 0.0f, 1.0f));


	for (loop_count = circle_resolution - 1; loop_count > 0; --loop_count)
	{
		this->m_ElementObject->position(cylinder_circle2id.at(loop_count));
		this->m_ElementObject->position(cylinder_circle2od.at(loop_count - 1));
		this->m_ElementObject->position(cylinder_circle2id.at(loop_count - 1));

		this->m_ElementObject->position(cylinder_circle2od.at(loop_count));
		this->m_ElementObject->position(cylinder_circle2od.at(loop_count - 1));
		this->m_ElementObject->position(cylinder_circle2id.at(loop_count));

	}

	this->m_ElementObject->position(cylinder_circle2id.at(loop_count));
	this->m_ElementObject->position(cylinder_circle2od.at(circle_resolution - 1));
	this->m_ElementObject->position(cylinder_circle2id.at(circle_resolution - 1));

	this->m_ElementObject->position(cylinder_circle2od.at(loop_count));
	this->m_ElementObject->position(cylinder_circle2od.at(circle_resolution - 1));
	this->m_ElementObject->position(cylinder_circle2id.at(loop_count));

	this->m_ElementObject->end();

	return this->m_ElementObject;
}


void OgrePipe::updateElementObject()
{

}

void OgrePipe::destroyElementObject()
{

}

Ogre::MeshPtr OgrePipe::createSphere(const Ogre::String& strName, const float r, const int nRings, const int nSegments)
{
	//ManualObject * manual = sceneMgr->createManualObject(strName);
	this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

	float fDeltaRingAngle = (Ogre::Math::PI / nRings);
	float fDeltaSegAngle = (2 * Ogre::Math::PI / nSegments);
	unsigned short wVerticeIndex = 0;
	float x0, y0, z0, r0;
	// Generate the group of rings for the sphere
	for (int ring = 0; ring <= nRings; ring++) {
		r0 = r * sinf(ring * fDeltaRingAngle);
		y0 = r * cosf(ring * fDeltaRingAngle);

		// Generate the group of segments for the current ring
		for (int seg = 0; seg <= nSegments; seg++) {
			x0 = r0 * sinf(seg * fDeltaSegAngle);
			z0 = r0 * cosf(seg * fDeltaSegAngle);

			// Add one vertex to the strip which makes up the sphere
			this->m_ElementObject->position(x0, y0, z0);
			this->m_ElementObject->normal(Ogre::Vector3(x0, y0, z0).normalisedCopy());
			this->m_ElementObject->textureCoord((Ogre::Real)seg / (Ogre::Real)nSegments, (Ogre::Real)ring / (Ogre::Real)nRings);

			if (ring != nRings) {
				// each vertex (except the last) has six indicies pointing to it
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex);
				this->m_ElementObject->index(wVerticeIndex + nSegments);
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex + 1);
				this->m_ElementObject->index(wVerticeIndex);
				wVerticeIndex++;
			}
		}; // end for seg
	} // end for ring
	this->m_ElementObject->end();

	Ogre::MeshPtr msh = this->m_ElementObject->convertToMesh(strName);
	msh->_setBounds(Ogre::AxisAlignedBox(Ogre::Vector3(-r, -r, -r), Ogre::Vector3(r, r, r)), false);
	msh->_setBoundingSphereRadius(r);
	unsigned short src, dest;
	if (!msh->suggestTangentVectorBuildParams(Ogre::VES_TANGENT, src, dest))
	{
		msh->buildTangentVectors(Ogre::VES_TANGENT, src, dest);
	}

	return msh;
}

Ogre::MeshPtr OgrePipe::createCylinder(const Ogre::String& strName, const float r, const float len, const int nRings, const int nSegments)
{
	//ManualObject * manual = sceneMgr->createManualObject(strName);
	this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

	float fDeltaRingAngle = (2 * Ogre::Math::PI / nRings);
	float fDeltaSeg = (len / nSegments);
	unsigned short wVerticeIndex = 0;
	float x0, y0, z0;
	// Generate the group of rings for the sphere
	for (int ring = 0; ring <= nRings; ring++) {

		y0 = r * cosf(ring * fDeltaRingAngle);
		x0 = r * sinf(ring *fDeltaRingAngle);
		// Generate the group of segments for the current ring
		for (int seg = 0; seg <= nSegments; seg++) {
			//float x0 = r * sinf(seg * fDeltaSeg);
			z0 = seg * fDeltaSeg;

			// Add one vertex to the strip which makes up the sphere
			this->m_ElementObject->position(x0, y0, z0);
			this->m_ElementObject->normal(Ogre::Vector3(x0, y0, z0).normalisedCopy());
			this->m_ElementObject->textureCoord((Ogre::Real)seg / (Ogre::Real)nSegments, (Ogre::Real)ring / (Ogre::Real)nRings);

			if (ring != nRings) {
				// each vertex (except the last) has six indicies pointing to it
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex);
				this->m_ElementObject->index(wVerticeIndex + nSegments);
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex + 1);
				this->m_ElementObject->index(wVerticeIndex);
				wVerticeIndex++;
			}
		}; // end for seg
	} // end for ring
	this->m_ElementObject->end();

	Ogre::MeshPtr msh = this->m_ElementObject->convertToMesh(strName);
	msh->_setBounds(Ogre::AxisAlignedBox(Ogre::Vector3(-r, -r, 0), Ogre::Vector3(r, r, len)), false);
	msh->_setBoundingSphereRadius((r>(len / 2.0f)) ? r : (len / 2.0f));
	unsigned short src, dest;
	if (!msh->suggestTangentVectorBuildParams(Ogre::VES_TANGENT, src, dest))
	{
		msh->buildTangentVectors(Ogre::VES_TANGENT, src, dest);
	}

	return msh;
}

Ogre::MeshPtr OgrePipe::createAnnulus(const Ogre::String& strName, const float ro, const float ri, const int nRings, const int nSegments)
{
	//ManualObject * manual = sceneMgr->createManualObject(strName);
	this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

	float fDeltaSegAngle = 2 * Ogre::Math::PI / nSegments;
	float fDeltaRing = (ro - ri) / nRings;
	unsigned short wVerticeIndex = 0;
	float x0, y0, z0, r0;
	// Generate the group of rings for the sphere
	for (int ring = 0; ring <= nRings; ring++) {
		r0 = ri + ring * fDeltaRing;// *sinf(ring * fDeltaRingAngle);

		// Generate the group of segments for the current ring
		for (int seg = 0; seg <= nSegments; seg++) {
			//float x0 = r * sinf(seg * fDeltaSeg);
			y0 = r0 * cosf(seg * fDeltaSegAngle);
			x0 = r0 * sinf(seg * fDeltaSegAngle);
			z0 = 0.0f;

			// Add one vertex to the strip which makes up the sphere
			this->m_ElementObject->position(x0, y0, z0);
			this->m_ElementObject->normal(Ogre::Vector3(x0, y0, z0).normalisedCopy());
			this->m_ElementObject->textureCoord((Ogre::Real)seg / (Ogre::Real)nSegments, (Ogre::Real)ring / (Ogre::Real)nRings);

			if (ring != nRings) {
				// each vertex (except the last) has six indicies pointing to it
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex);
				this->m_ElementObject->index(wVerticeIndex + nSegments);
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex + 1);
				this->m_ElementObject->index(wVerticeIndex);
				wVerticeIndex++;
			}
		}; // end for seg
	} // end for ring
	this->m_ElementObject->end();

	Ogre::MeshPtr msh = this->m_ElementObject->convertToMesh(strName);
	msh->_setBounds(Ogre::AxisAlignedBox(Ogre::Vector3(-ro, -ro, -1), Ogre::Vector3(ro, ro, 1)), false);
	msh->_setBoundingSphereRadius(ro);
	unsigned short src, dest;
	if (!msh->suggestTangentVectorBuildParams(Ogre::VES_TANGENT, src, dest))
	{
		msh->buildTangentVectors(Ogre::VES_TANGENT, src, dest);
	}

	return msh;
}

Ogre::MeshPtr OgrePipe::createTorus(const Ogre::String& strName, const float r, const float R, const float angle, const int nRings, const int nSegments)
{
	//ManualObject * manual = sceneMgr->createManualObject(strName);
	this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

	float fDeltaSegAngle = 2 * Ogre::Math::PI / nSegments;
	float fDeltaRingAngle = angle * Ogre::Math::PI / 180.0f / nRings;
	unsigned short wVerticeIndex = 0;
	float x0, y0, z0;
	// Generate the group of rings for the sphere
	for (int ring = 0; ring <= nRings; ring++) {
		//float r0 = ri + ring * fDeltaRing;// *sinf(ring * fDeltaRingAngle);

		// Generate the group of segments for the current ring
		for (int seg = 0; seg <= nSegments; seg++) {
			//float x0 = r * sinf(seg * fDeltaSeg);
			y0 = r * Ogre::Math::Sin(seg * fDeltaSegAngle);
			x0 = (R + r * Ogre::Math::Cos(seg * fDeltaSegAngle)) * Ogre::Math::Sin(ring * fDeltaRingAngle);
			z0 = (R + r * Ogre::Math::Cos(seg * fDeltaSegAngle)) * Ogre::Math::Cos(ring * fDeltaRingAngle) - R;;

			// Add one vertex to the strip which makes up the sphere
			this->m_ElementObject->position(x0, y0, z0);
			this->m_ElementObject->normal(Ogre::Vector3(x0, y0, z0).normalisedCopy());
			this->m_ElementObject->textureCoord((Ogre::Real)seg / (Ogre::Real)nSegments, (Ogre::Real)ring / (Ogre::Real)nRings);

			if (ring != nRings) {
				// each vertex (except the last) has six indicies pointing to it
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex);
				this->m_ElementObject->index(wVerticeIndex + nSegments);
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex + 1);
				this->m_ElementObject->index(wVerticeIndex);
				wVerticeIndex++;
			}
		}; // end for seg
	} // end for ring
	this->m_ElementObject->setVisible(true);
	this->m_ElementObject->setCastShadows(true);

	this->m_ElementObject->end();


	//((Ogre::VertexData*)(m_ElementObject->getEdgeList()->edgeGroups.at(0).vertexData))->prepareForShadowVolume();


	Ogre::MeshPtr msh = this->m_ElementObject->convertToMesh(strName);
	msh->buildEdgeList();
	msh->_setBounds(Ogre::AxisAlignedBox(Ogre::Vector3(-(R + r), -r, -(R + r)), Ogre::Vector3((R + r), r, (R + r))), false);
	msh->_setBoundingSphereRadius(R + r);
	unsigned short src, dest;
	if (!msh->suggestTangentVectorBuildParams(Ogre::VES_TANGENT, src, dest))
	{
		msh->buildTangentVectors(Ogre::VES_TANGENT, src, dest);
	}

	return msh;
}

Ogre::MeshPtr OgrePipe::createCone(const Ogre::String& strName, const float rl, const float rs, const float len, const int nRings, const int nSegments)
{
	//ManualObject * manual = sceneMgr->createManualObject(strName);
	this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

	float fDeltaSegAngle = 2 * Ogre::Math::PI / nSegments;
	float fDeltaRing = len / nRings;
	unsigned short wVerticeIndex = 0;
	float x0, y0, z0, r0;
	// Generate the group of rings for the sphere
	for (int ring = 0; ring <= nRings; ring++) {
		r0 = rs + (rl - rs) * ring / nRings;// *sinf(ring * fDeltaRingAngle);

		// Generate the group of segments for the current ring
		for (int seg = 0; seg <= nSegments; seg++) {
			y0 = r0 * cosf(seg * fDeltaSegAngle);
			x0 = r0 * sinf(seg * fDeltaSegAngle);;
			z0 = ring * fDeltaRing;

			// Add one vertex to the strip which makes up the sphere
			this->m_ElementObject->position(x0, y0, z0);
			this->m_ElementObject->normal(Ogre::Vector3(x0, y0, z0).normalisedCopy());
			this->m_ElementObject->textureCoord((Ogre::Real)seg / (Ogre::Real)nSegments, (Ogre::Real)ring / (Ogre::Real)nRings);

			if (ring != nRings) {
				// each vertex (except the last) has six indicies pointing to it

				this->m_ElementObject->quad(wVerticeIndex + 1, wVerticeIndex,
					wVerticeIndex + nSegments, wVerticeIndex + nSegments + 1);
				//this->m_ElementObject->triangle(wVerticeIndex + nSegments + 1, wVerticeIndex,
				//	wVerticeIndex + nSegments);
				//this->m_ElementObject->triangle(wVerticeIndex + nSegments + 1, wVerticeIndex + 1,
				//	wVerticeIndex);
				/*this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex);
				this->m_ElementObject->index(wVerticeIndex + nSegments);
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex + 1);
				this->m_ElementObject->index(wVerticeIndex);*/

				//this->m_ElementObject->quad(wVerticeIndex + 1, wVerticeIndex + nSegments + 1,
				//	wVerticeIndex + nSegments, wVerticeIndex);
				//this->m_ElementObject->triangle(wVerticeIndex + nSegments, wVerticeIndex,
				//	wVerticeIndex + nSegments + 1);
				//this->m_ElementObject->triangle(wVerticeIndex, wVerticeIndex + 1,
				//	wVerticeIndex + nSegments + 1);
				/*this->m_ElementObject->index(wVerticeIndex + nSegments);
				this->m_ElementObject->index(wVerticeIndex);
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex);
				this->m_ElementObject->index(wVerticeIndex + 1);
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);*/


				/*this->m_ElementObject->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST);
				this->m_ElementObject->colour(Ogre::ColourValue(0.0f, 0.0f, 0.0f, 1.0f));
				this->m_ElementObject->index(wVerticeIndex + 1);
				this->m_ElementObject->index(wVerticeIndex);
				this->m_ElementObject->index(wVerticeIndex + nSegments);
				this->m_ElementObject->index(wVerticeIndex + nSegments + 1);
				this->m_ElementObject->index(wVerticeIndex + 1);
				this->m_ElementObject->end();*/

				wVerticeIndex++;
			}
		}; // end for seg
	} // end for ring



	this->m_ElementObject->end();
	this->m_ElementObject->setVisible(true);
	this->m_ElementObject->setCastShadows(true);

	((Ogre::VertexData*)(m_ElementObject->getEdgeList()->edgeGroups.at(0).vertexData))->prepareForShadowVolume();

	Ogre::MeshPtr msh = this->m_ElementObject->convertToMesh(strName);
	msh->_setBounds(Ogre::AxisAlignedBox(Ogre::Vector3(-rl, -rl, 0), Ogre::Vector3(rl, rl, len)), false);
	msh->_setBoundingSphereRadius((rl > len / 2.0f) ? rl : len / 2.0f);
	unsigned short src, dest;
	if (!msh->suggestTangentVectorBuildParams(Ogre::VES_TANGENT, src, dest))
	{
		msh->buildTangentVectors(Ogre::VES_TANGENT, src, dest);
	}

	//Ogre::Entity* ent = m_ScnMgr->createEntity(msh);
	//Ogre::Entity* ent = ;
	//const Ogre::String& matName = "M_LightingColor";
	//ent->setMaterialName(matName);

	//Ogre::SceneNode* node = new Ogre::SceneNode();
	//node->attachObject(ent);
	//
	//node->attachObject(ent);
	return msh;
}