#include "TrackBall.h"

TrackBall::TrackBall(Ogre::Real NewWidth, Ogre::Real NewHeight)

{
	m_StVec = Ogre::Vector3::ZERO;
	m_EnVec = Ogre::Vector3::ZERO;
	SetBounds(NewWidth, NewHeight);
}
TrackBall::~TrackBall()
{

}

Ogre::Vector3 TrackBall::mapToSphere(Ogre::Vector2 point)
{
	Ogre::Vector2 tempPoint(point);
	Ogre::Vector3 vector;
	//Adjust point coords and scale down to range of [-1 ... 1]
	tempPoint.x = -((tempPoint.x * this->m_adjustWidth) - 1.0f);
	tempPoint.y = -(0.50f - (tempPoint.y * this->m_adjustWidth));

	//Compute square of the length of the vector from this point to the center
	float length = (tempPoint.x * tempPoint.x) + (tempPoint.y * tempPoint.y);

	//If the point is mapped outside the sphere... (length > radius squared)
	if (length > 1.0f)
	{
		//Compute a normalizing factor (radius / sqrt(length))
		float norm = safe_cast<float>(1.0 / Math::Sqrt(length));

		//Return the "normalized" vector, a point on the sphere
		vector.x = tempPoint.x * norm;
		vector.y = tempPoint.y * norm;
		vector.z = 0.0f;
	}
	//Else it's inside
	else
	{
		//Return a vector to a point mapped inside the sphere sqrt(radius squared - length)
		vector.x = tempPoint.x;
		vector.y = tempPoint.y;
		vector.z = Ogre::Math::Sqrt(1.0f - length);
	}
	return vector;
}

void TrackBall::SetBounds(Ogre::Real NewWidth, Ogre::Real NewHeight)
{
	//Set adjustment factor for width/height
	this->m_adjustWidth = 1.0f / ((NewWidth - 1.0f) * 0.5f);
	this->m_adjustHeight = 1.0f / ((NewHeight - 1.0f) * 0.5f);

	m_TopLeft = mapToSphere(Ogre::Vector2(0, 0));
	m_TopRight = mapToSphere(Ogre::Vector2(NewWidth, 0));
	m_BotLeft = mapToSphere(Ogre::Vector2(0, NewHeight));
	m_BotRight = mapToSphere(Ogre::Vector2(NewWidth, NewHeight));
	PanSclX = (m_BotRight - m_BotLeft).length();
	PanSclY = (m_TopLeft - m_BotLeft).length();
}

//Mouse down
void TrackBall::Click(Ogre::Vector2 NewPt)
{
	this->m_StVec = mapToSphere(NewPt);
}

Ogre::Quaternion TrackBall::Drag(Ogre::Vector2 NewPt)
{
	//Map the point to the sphere
	this->m_EnVec = mapToSphere(NewPt);
	Ogre::Quaternion NewRot;
	//Return the quaternion equivalent to the rotation
	//if (!(NewRot->isNaN()))
	{
		Ogre::Vector3 Perp = Ogre::Vector3::ZERO;

		//Compute the vector perpendicular to the begin and end vectors
		Perp = this->m_StVec.crossProduct(this->m_EnVec);

		//Compute the length of the perpendicular vector
		if (Perp.length() > m_Epsilon)
			//if its non-zero
		{
			//We're ok, so return the perpendicular vector as the transform after all
			NewRot.x = Perp.x;
			NewRot.y = Perp.y;
			NewRot.z = Perp.z;
			//In the quaternion values, w is cosine (theta / 2), where theta is the rotation angle
			NewRot.w = this->m_StVec.dotProduct(this->m_EnVec);
		}
		//if it is zero
		else
		{
			//The begin and end vectors coincide, so return an identity transform
			NewRot.x = NewRot.y = NewRot.z = NewRot.w = 0.0f;
		}
	}
	return NewRot;
}







