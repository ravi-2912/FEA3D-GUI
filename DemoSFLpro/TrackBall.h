#pragma once

#include <Ogre.h>

using namespace System;
using namespace System::Windows::Forms;

class TrackBall
{
public:
	TrackBall(Ogre::Real NewWidth, Ogre::Real NewHeight);
	~TrackBall();

	void SetBounds(Ogre::Real NewWidth, Ogre::Real NewHeight);
	virtual void Click(Ogre::Vector2 NewPt);//Mouse down
	Ogre::Quaternion Drag(Ogre::Vector2 NewPt);//Mouse drag, calculate rotation

	//private:
	Ogre::Vector3 mapToSphere(Ogre::Vector2 point);

private:
	const Ogre::Real		m_Epsilon = 1.0e-5f;

	Ogre::Vector3			m_StVec; //Saved click vector
	Ogre::Vector3			m_EnVec; //Saved drag vector

	Ogre::Real				m_adjustWidth; //Mouse bounds width
	Ogre::Real				m_adjustHeight; //Mouse bounds height
	//////////////////////////////////////////////////////////////////
	// For Pan


public:
	Ogre::Real				PanSclX;
	Ogre::Real				PanSclY;
	Ogre::Vector3			m_TopLeft;
	Ogre::Vector3			m_BotLeft;
	Ogre::Vector3			m_BotRight;
	Ogre::Vector3			m_TopRight;
};


