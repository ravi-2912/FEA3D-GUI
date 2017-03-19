#pragma once
#include <OgreRoot.h>
#include <OgreEntity.h>
#include <OgreManualObject.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>

enum ElementTypes
{
	PIPE, REDUCER, BEND, TEE, RIGID
};

/*enum BendTypes
{
FORGED, FIELD, MITRE
};

enum TeeTypes
{
FORGED, FIELD
};

enum RigidTypes
{
FLANGE, FLANGEPAIR, WELDED_BALLVALVE, WELDED_GATEVALVE, WELDED_BUTTERFLYVALVE,
FLANGED_BALLVALVE, FLANGED_GATEVALVE, FLANGED_BUTTERFLYVALVE,
};*/

class OgrePipelineElement
{
public:
	OgrePipelineElement(ElementTypes elementType);
	~OgrePipelineElement();

	// Getters and setter
	virtual void			setElementType(ElementTypes elementType);
	virtual ElementTypes	getElementType();

	virtual Ogre::String	getElementName();
	virtual void			setElementID(unsigned int elementID);
	virtual unsigned int	getElementID();
	virtual void			setStartCoordID(unsigned int startID);
	virtual unsigned int	getStartCoordID();
	virtual void			setEndCoordID(unsigned int endID);
	virtual unsigned int	getEndCoordID();

	virtual void			setOuterDiameter(Ogre::Real outerDiameter);
	virtual Ogre::Real		getOuterDiameter();
	virtual void			setWallThickness(Ogre::Real wallThickness);
	virtual Ogre::Real		getWallThickness();

	//virtual Ogre::ManualObject*		getElementSceneNode() = 0;
	virtual Ogre::ManualObject*		getElementObject() = 0;
	virtual void					updateElementObject() = 0;
	virtual void					destroyElementObject() = 0;


protected:
	ElementTypes			m_ElementType;
	unsigned int			m_ElementID;
	Ogre::String			m_ElementName;

	Ogre::Real				m_OuterDiameter;
	Ogre::Real				m_WallThickness;

	unsigned int			m_CircleSubDivision;

	Ogre::Vector3			m_StartCoordinate;
	Ogre::Vector3			m_EndCoordinate;
	unsigned int			m_StartCoordinateID;
	unsigned int			m_EndCoordinateID;

	Ogre::ManualObject*		m_ElementObject;
	Ogre::SceneNode*		m_ElementSeneNode;

};

