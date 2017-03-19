#pragma once
#include <Ogre.h>
#include <vcclr.h>
#include "TrackBall.h"

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;


class OgreApp : Ogre::FrameListener
{
	public:
		bool OgreStarted = false;
		//OgreApp(void * panelHandle, unsigned int width, unsigned int height);
		OgreApp(System::Windows::Forms::Panel^ panel);
		OgreApp(System::Windows::Forms::TabPage^ tabPage);
		//OgreApp();
		~OgreApp();

		int OgreApp::GetFPS();
		void LaunchOgre();

		void OnMouseDown(System::Object^ sender, Windows::Forms::MouseEventArgs^ e);
		void OnMouseUp(System::Object^ sender, Windows::Forms::MouseEventArgs^ e);
		void OnMouseMove(System::Object^ sender, Windows::Forms::MouseEventArgs^ e);
		void OnMouseWheel(System::Object^ sender, Windows::Forms::MouseEventArgs^ e);
		void OnPanelResize(System::Object^  sender, System::EventArgs^  e, System::Windows::Forms::Panel^ panel);

	protected:
		bool SetupOgre();
		void DisposeOgre();
		bool InitializeRoot();
		bool InitializeRenderer();
		bool ReadResources();
		bool LoadResources();
		void SetupEnvironment();

		virtual bool UpdateFrameRenderingQueued(const Ogre::FrameEvent& evt);
		int  getFPS();

		void ResizeRenderWindow(int pWidth, int pHeight);

		virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

		void addPipe(Ogre::Vector3 pos, Ogre::String name);



	private:
		Ogre::Root*				m_Root;
		Ogre::String			m_ResourcesCfg;
		Ogre::String			m_PluginsCfg;
		Ogre::Log*				m_Log;

		Ogre::RenderSystem*		m_RenderSystem;
		Ogre::RenderWindow*		m_RenderWindow;
		unsigned int			m_RenderWindowWidth;
		unsigned int			m_RenderWindowHeight;
		Ogre::SceneManager*		m_SceneManager;
		Ogre::Viewport*			m_Viewport;

		Ogre::SceneNode*		m_CoordinateAxesSceneNode;

		gcroot<Forms::Panel^>	m_Panel;
		bool					m_usePanel;
		gcroot<Forms::TabPage^>	m_TabPage;


		//////////////////////////////////////////////////////
		// Camera
		Ogre::Camera*			m_Camera;
		Ogre::SceneNode*		m_Target;
		Ogre::SceneNode*		m_CameraNode;
		TrackBall*				m_TrackBall;
		Ogre::Quaternion		m_OldOrientation;
		Ogre::Quaternion		m_NewOrientation;
		Ogre::Vector2			m_OldMousePos; // Used in Pan
		Ogre::Vector3			m_OldTargetPos; // USed in PAn
		bool					m_IsLeftDrag;
		bool					m_IsMiddleDrag;
		bool					m_IsRightDrag;



};

