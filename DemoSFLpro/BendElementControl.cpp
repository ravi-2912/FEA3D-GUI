#include "BendElementControl.h"

namespace DemoSFLpro
{

	BendElement^ BendElementControl::GetBendElement()
	{
		this->mBendElm->BendRadius = double::Parse(this->txtBxBendRadius->Text);
		this->mBendElm->BendAngle = double::Parse(this->txtBxBendAngle->Text);
		this->mBendElm->RotationAngle = double::Parse(this->txtBxRotationAngle->Text);
		this->mBendElm->BendWallThickness = double::Parse(this->txtBxBendWallThickness->Text);

		return this->mBendElm;
	}

	void BendElementControl::UpdateControl(BendElement^ bendelm)
	{
		if (bendelm != nullptr)
		{
			this->txtBxBendRadius->Text = bendelm->BendRadius.ToString();
			this->txtBxBendAngle->Text = bendelm->BendAngle.ToString();
			this->txtBxRotationAngle->Text = bendelm->RotationAngle.ToString();
			this->txtBxBendWallThickness->Text = bendelm->BendWallThickness.ToString();
		}
		else
		{
			this->txtBxBendRadius->Text = "";
			this->txtBxBendAngle->Text = "";
			this->txtBxRotationAngle->Text = "";
			this->txtBxBendWallThickness->Text = "";
		}
	}
}