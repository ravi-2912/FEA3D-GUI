#pragma once

// Includes
#include <OgreRenderTargetlistener.h>
#include <OgreColourValue.h>
#include <OgreMath.h>
#include <OgreManualObject.h>
#include <OgreViewport.h>
#include <OgreRenderTarget.h>
#include <OgreSceneManager.h>
#include <OgreStringConverter.h>
#include <OgreMaterialManager.h>
#include <OgreSceneNode.h>
#include <OgreRoot.h>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreViewport.h>
#include <OgreException.h>
#include <OgreLogManager.h>
#include <OgreConfigFile.h>

#include <OgreRenderWindow.h>
#include <OgreTextureManager.h>

#include <OgreWindowEventUtilities.h>

namespace Ogre
{
	/** Use this class to render a dynamically adjusting grid inside an Ogre viewport.
	@todo
	Make the grid work with an arbitrary rotated orthogonal camera (e.g. for working in object space mode).
	Or should the grid be rendered in object space too then?
	*/
	class ViewportGrid : public RenderTargetListener
	{
	public:
		//! The render layer of the grid in orthogonal view
		enum RenderLayer
		{
			RL_BEHIND, //!< Behind all objects
			RL_INFRONT //!< In front of all objects
		};

	protected:
		// Member variables
		SceneManager *m_pSceneMgr;
		Viewport *m_pViewport;
		bool m_enabled;
		RenderLayer m_layer;

		Camera *m_pPrevCamera;
		bool m_prevOrtho;
		Vector3 m_prevCamPos;
		Real m_prevNear;
		Radian m_prevFOVy;
		Real m_prevAspectRatio;
		bool m_forceUpdate;

		ManualObject *m_pGrid;
		bool m_created;
		SceneNode *m_pNode;

		ColourValue m_colour1, m_colour2;
		unsigned int m_division;
		Real m_perspSize;
		bool m_renderScale, m_renderMiniAxes;

	public:
		// Constructors and destructor
		ViewportGrid(SceneManager *pSceneMgr, Viewport *pViewport);
		virtual ~ViewportGrid();

		//! Grid colour
		const ColourValue &getColour() const { return m_colour1; }
		void setColour(const ColourValue &colour);

		//! Grid division (the number of new lines that are created when zooming in).
		unsigned int getDivision() const { return m_division; }
		void setDivision(unsigned int division);

		//! Grid render layer (behind of in front of the objects).
		RenderLayer getRenderLayer() const { return m_layer; }
		void setRenderLayer(RenderLayer layer);

		//! Size of the grid in perspective view
		Real getPerspectiveSize() const { return m_perspSize; }
		void setPerspectiveSize(Real size);

		//! Render scaling info? Defaults to true.
		//! @todo Implement this
		bool getRenderScale() const { return m_renderScale; }
		void setRenderScale(bool enabled = true);

		//! Render mini axes? Defaults to true.
		//! @todo Implement this
		bool getRenderMiniAxes() const { return m_renderMiniAxes; }
		void setRenderMiniAxes(bool enabled = true);

		// Enable / disable
		bool isEnabled() const;
		void enable();
		void disable();
		void toggle();
		void setEnabled(bool enabled);

		// Other functions
		void forceUpdate() { m_forceUpdate = true; }

	protected:
		// RenderTargetListener
		void preViewportUpdate(const RenderTargetViewportEvent &evt);
		void postViewportUpdate(const RenderTargetViewportEvent &evt);

		// Other protected functions
		void createGrid();
		void destroyGrid();

		void update();
		void updateOrtho();
		void updatePersp();

		bool checkUpdate();
		bool checkUpdateOrtho();
		bool checkUpdatePersp();
	};
}



