#include "OgrePipelineElement.h"


OgrePipelineElement::OgrePipelineElement(ElementTypes elementType)
{
	this->m_ElementType = elementType;
}

OgrePipelineElement::~OgrePipelineElement()
{
}

Ogre::String OgrePipelineElement::getElementName()
{
	return this->m_ElementName;
}

void OgrePipelineElement::setElementID(unsigned int elementID)
{

}

unsigned int OgrePipelineElement::getElementID()
{
	return this->m_ElementID;
}

void OgrePipelineElement::setStartCoordID(unsigned int startID)
{

}

unsigned int OgrePipelineElement::getStartCoordID()
{
	return this->m_StartCoordinateID;
}

void OgrePipelineElement::setEndCoordID(unsigned int endID)
{

}

unsigned int OgrePipelineElement::getEndCoordID()
{
	return this->m_EndCoordinateID;;
}

void OgrePipelineElement::setOuterDiameter(Ogre::Real outerDiameter)
{

}

Ogre::Real OgrePipelineElement::getOuterDiameter()
{
	return this->m_OuterDiameter;
}

void OgrePipelineElement::setWallThickness(Ogre::Real wallThickness)
{

}

Ogre::Real OgrePipelineElement::getWallThickness()
{
	return this->m_WallThickness;
}

void OgrePipelineElement::setElementType(ElementTypes elementType)
{
	this->m_ElementType = elementType;
}

ElementTypes OgrePipelineElement::getElementType()
{
	return this->m_ElementType;
}