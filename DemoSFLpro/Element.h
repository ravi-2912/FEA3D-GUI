#pragma once

#include "PipelineMaterial.h"

namespace DemoSFLpro
{
	public ref class Vec3
	{
	public:
		Vec3() {}
		Vec3(double x, double y, double z)
		{
			this->x = x; this->y = y; this->z = z;
		}
		~Vec3() {}
		Vec3^ operator = (Vec3^ t)
		{
			Vec3^ tt;
			//this->x = t.x; this->y = t.y; this->z = t.z;
			tt->x = t->x; tt->y = t->y; tt->z = t->z;
			return tt;
		}
	public:
		double x, y, z;
	};

	public enum ElementTypes
	{
		PIPE, BEND, REDUCER, TEE, RIGID
	};
	public enum DiameterTypes
	{
		ID, OD, ND
	};

	public ref class Element
	{
	public:
		Element();
		Element(Element^ elm);
		~Element();
		virtual void CalcEndCoord();

	public:
		unsigned int		ID;
		ElementTypes		ElementType;
		double				Diameter;
		DiameterTypes		DiameterType;
		double				WallThickness;
		double				UnderTolerance;
		String^				Material;
		Vec3^				StartCoord;
		Vec3^				EndCoord;
	};

	public ref class PipeElement : public Element
	{
	public:
		PipeElement();
		PipeElement(PipeElement^ pipelm);
		~PipeElement();
		//void CalcL();
		//void CalcLx();
		//void CalcLy();
		//void CalcLz();
		//void CalcAlpha();
		//void CalcBeta();
		//void CalcGamma();
		void CalcEndCoord() override;/********** REVISIT ************/

	public:
		double		Length;
		double		Lx, Ly, Lz;
		double		Alpha, Beta, Gamma;
	};

	public ref class BendElement : public Element
	{
	public:
		BendElement();
		BendElement(BendElement^ bendelm);
		~BendElement();
		void CalcEndCoord() override;

	public:
		double		BendRadius;
		double		BendAngle;
		double		RotationAngle;
		double		BendWallThickness;
	};

	public ref class ReducerElement : public Element /** Can also derive from PipeElement**/
	{
	public:
		ReducerElement();
		~ReducerElement();
		void CalcEndCoord() override;

	public:
		double			EndDiameter;
		DiameterTypes	EndDiameterTypes;
		double			EndWallThickness;
		double			Length, Alpha; // CAN also have direction cosines
		double			r1, l1, r2, l2;
	};
}

