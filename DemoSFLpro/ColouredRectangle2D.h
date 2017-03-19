#pragma once

#include <OgreRectangle2D.h>

class ColouredRectangle2D : public Ogre::Rectangle2D
{
public:
public:
	ColouredRectangle2D(bool includeTextureCoordinates = false);
	~ColouredRectangle2D();

	void setColours(const Ogre::ColourValue &topLeft,
		const Ogre::ColourValue &bottomLeft,
		const Ogre::ColourValue &topRight,
		const Ogre::ColourValue &bottomRight);
};