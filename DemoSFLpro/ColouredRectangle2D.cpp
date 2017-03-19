#include "ColouredRectangle2D.h"
#include <OgreHardwareBufferManager.h>
//#define POSITION_BINDING 0
//#define NORMAL_BINDING 1
//#define TEXCOORD_BINDING 2
#define COLOUR_BINDING 3


ColouredRectangle2D::ColouredRectangle2D(bool includeTextureCoordinates /*= false*/)
	: Ogre::Rectangle2D(includeTextureCoordinates)
{
	Ogre::VertexDeclaration* decl = mRenderOp.vertexData->vertexDeclaration;
	decl->addElement(COLOUR_BINDING, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
	Ogre::VertexBufferBinding* bind = mRenderOp.vertexData->vertexBufferBinding;

	Ogre::HardwareVertexBufferSharedPtr vbuf =
		Ogre::HardwareBufferManager::getSingleton().
		createVertexBuffer(decl->getVertexSize(COLOUR_BINDING),
		mRenderOp.vertexData->vertexCount,
		Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY);

	// Bind buffer
	bind->setBinding(COLOUR_BINDING, vbuf);
}

ColouredRectangle2D::~ColouredRectangle2D()
{
}

void ColouredRectangle2D::setColours(const Ogre::ColourValue &topLeft,
	const Ogre::ColourValue &bottomLeft,
	const Ogre::ColourValue &topRight,
	const Ogre::ColourValue &bottomRight)
{
	Ogre::HardwareVertexBufferSharedPtr vbuf =
		mRenderOp.vertexData->vertexBufferBinding->getBuffer(COLOUR_BINDING);
	unsigned int* pUint32 = static_cast<unsigned int*>(vbuf->lock(Ogre::HardwareBuffer::HBL_DISCARD));
	const Ogre::VertexElementType srcType = Ogre::VertexElement::getBestColourVertexElementType();

	*pUint32++ = Ogre::VertexElement::convertColourValue(topLeft, srcType);
	*pUint32++ = Ogre::VertexElement::convertColourValue(bottomLeft, srcType);
	*pUint32++ = Ogre::VertexElement::convertColourValue(topRight, srcType);
	*pUint32++ = Ogre::VertexElement::convertColourValue(bottomRight, srcType);

	vbuf->unlock();
}
