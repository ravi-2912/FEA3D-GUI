#include "PipeElementCtrl.h"

namespace DemoSFLpro
{
	PipeElement^ PipeElementCtrl::GetPipeElement()
	{
		this->mPipElm->Length = double::Parse(this->txtBxLength->Text);
		this->mPipElm->Lx = double::Parse(this->txtBxLx->Text);
		this->mPipElm->Ly = double::Parse(this->txtBxLy->Text);
		this->mPipElm->Lz = double::Parse(this->txtBxLz->Text);
		this->mPipElm->Alpha = double::Parse(this->txtBxAlpha->Text);
		this->mPipElm->Beta = double::Parse(this->txtBxBeta->Text);
		this->mPipElm->Gamma = double::Parse(this->txtBxGamma->Text);

		return this->mPipElm;
	}
	
	void PipeElementCtrl::UpdateControl(PipeElement^ pipelm)
	{
		if (pipelm != nullptr)
		{
			this->txtBxLength->Text = pipelm->Length.ToString();
			this->txtBxLx->Text = pipelm->Lx.ToString();
			this->txtBxLy->Text = pipelm->Ly.ToString();
			this->txtBxLz->Text = pipelm->Lz.ToString();
			this->txtBxAlpha->Text = pipelm->Alpha.ToString();
			this->txtBxBeta->Text = pipelm->Beta.ToString();
			this->txtBxGamma->Text = pipelm->Gamma.ToString();
		}
		else
		{
			this->txtBxLength->Text = "";
			this->txtBxLx->Text = "";
			this->txtBxLy->Text = "";
			this->txtBxLz->Text = "";
			this->txtBxAlpha->Text = "";
			this->txtBxBeta->Text = "";
			this->txtBxGamma->Text = "";
		}
	}
}