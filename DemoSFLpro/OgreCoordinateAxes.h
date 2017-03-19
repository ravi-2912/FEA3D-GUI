#pragma once

//#include "Soft_Models.h"
#include <OgreRoot.h>
#include <OgreEntity.h>
#include <OgreManualObject.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

enum AxisLabel
{
	X, Y, Z
};

class OgreCoordinateAxes
{
public:
	OgreCoordinateAxes(Ogre::SceneManager* sceneManager);
	~OgreCoordinateAxes();

private:
	void	generateCoordinateAxes();
	void	axisCone(AxisLabel axis, Ogre::Real coneLength, Ogre::Real coneRadius, Ogre::String colorName);
	void	axisLine(Ogre::Vector3 start, Ogre::Vector3 end, Ogre::String colorName);
	void	setAxisMaterials();
private:
	Ogre::SceneNode*		m_CoordinateAxesSceneNode;
	Ogre::ManualObject*		m_CoordinateAxesManualObject;
	Ogre::SceneManager*		m_SceneManager;
	Ogre::MaterialPtr		m_xAxisMat, m_yAxisMat, m_zAxisMat;

};


