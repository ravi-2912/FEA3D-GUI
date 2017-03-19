#include "Element.h"

namespace DemoSFLpro
{
	Element::Element()
		: ID(0)
		, ElementType(ElementTypes::PIPE)
		, Diameter(0)
		, DiameterType(DiameterTypes::OD)
		, WallThickness(0)
		, UnderTolerance(0)
		, Material("")
	{

	}
	
	Element::Element(Element^ elm)
		: ID(elm->ID)
		, ElementType(elm->ElementType)
		, Diameter(elm->Diameter)
		, DiameterType(elm->DiameterType)
		, WallThickness(elm->WallThickness)
		, UnderTolerance(elm->UnderTolerance)
		, Material(elm->Material)
	{
		
	}

	Element::~Element()
	{
	}

	void Element::CalcEndCoord()
	{

	}


	PipeElement::PipeElement() 
		: Element()
		, Length(0)
		, Lx(0), Ly(0), Lz(0)
		, Alpha(0), Beta(0), Gamma(0)
	{
		double		Length;
		double		Lx, Ly, Lz;
		double		Alpha, Beta, Gamma;
	}

	PipeElement::PipeElement(PipeElement^ pipelm) 
		: Element(pipelm)
		, Length(pipelm->Length)
		, Lx(pipelm->Lx)
		, Ly(pipelm->Ly)
		, Lz(pipelm->Lz)
		, Alpha(pipelm->Alpha)
		, Beta(pipelm->Beta)
		, Gamma(pipelm->Gamma)
	{

	}

	PipeElement::~PipeElement()
	{

	}


	void PipeElement::CalcEndCoord()
	{
		this->EndCoord->x = this->StartCoord->x + this->Lx;
		this->EndCoord->y = this->StartCoord->y + this->Ly;
		this->EndCoord->z = this->StartCoord->z + this->Lz;
	}


	BendElement::BendElement()
		: Element()
		, BendRadius(0)
		, BendAngle(0)
		, RotationAngle(0)
		, BendWallThickness(0)
	{

	}

	BendElement::BendElement(BendElement^ bendelm)
		:Element(bendelm)
		, BendRadius(bendelm->BendRadius)
		, BendAngle(bendelm->BendAngle)
		, RotationAngle(bendelm->RotationAngle)
		, BendWallThickness(bendelm->BendWallThickness)
	{

	}

	BendElement::~BendElement()
	{

	}


	void BendElement::CalcEndCoord()
	{
		
	}

	ReducerElement::ReducerElement()
	{

	}

	ReducerElement::~ReducerElement()
	{

	}


	void ReducerElement::CalcEndCoord()
	{

	}

}