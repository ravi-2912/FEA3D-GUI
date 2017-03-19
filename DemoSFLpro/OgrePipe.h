#pragma once

#include "OgrePipelineElement.h"


class OgrePipe : public OgrePipelineElement
{
public:
	OgrePipe(unsigned int elementID, unsigned int startID, unsigned int endID);
	~OgrePipe();

	// Getters and setters
	void			setPipeLenth(Ogre::Real pipeLength);
	Ogre::Real		getPipeLength();

	virtual void	setPipeGeometry(Ogre::Real outerDiameter, Ogre::Real wallThickness,
		Ogre::Real length, unsigned int circleSubDivision = 120);

	Ogre::MeshPtr createSphere(const std::string& strName, const float r, const int nRings = 100, const int nSegments = 100);
	Ogre::MeshPtr createCylinder(const Ogre::String& strName, const float r, const float len, const int nRings = 100, const int nSegments = 100);
	Ogre::MeshPtr createAnnulus(const Ogre::String& strName, const float ro, const float ri, const int nRings = 10, const int nSegments = 100);
	Ogre::MeshPtr createTorus(const Ogre::String& strName, const float r, const float R, const float angle, const int nRings = 100, const int nSegments = 100);
	Ogre::MeshPtr createCone(const Ogre::String& strName, const float rl, const float rs, const float len, const int nRings = 100, const int nSegments = 100);

	void useSceneManager(Ogre::SceneManager* scnMgr) { this->m_ScnMgr = scnMgr; }
	//virtual void	setPipeGeometry(Ogre::Real outerDiameter, Ogre::Real wallThickness,
	//					Ogre::Real dx, Ogre::Real dy, Ogre::Real dz, unsigned int circleSubDivision = 120);

	virtual void	updateElementObject();
	virtual void	destroyElementObject();


	virtual Ogre::ManualObject*		getElementObject();
	//virtual void					updateElementObject();
	//virtual void					destroyElementObject();

private:
	Ogre::Real m_PipeLength;
	Ogre::Real m_DX, m_DY, m_DZ;
	Ogre::Real m_theta, m_phi, m_gamma;
	Ogre::SceneManager* m_ScnMgr;
	Ogre::MaterialPtr m_xAxisMat;

};

