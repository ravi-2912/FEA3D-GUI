#include "PipelineMaterialControl.h"

namespace DemoSFLpro
{
	System::Void PipelineMaterialControl::chkAddPlasticProperties_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->chkBxAddPlasticProperties->Checked)
		{
			this->lblHardeningCoeff->Enabled = true;
			this->lblHardeningPower->Enabled = true;
			this->txtBxHardeningCoeff->Enabled = true;
			this->txtBxHardeningPower->Enabled = true;
			this->txtBxHardeningCoeff->Text = "";
			this->txtBxHardeningPower->Text = "";
		}
		else
		{
			this->lblHardeningCoeff->Enabled = false;
			this->lblHardeningPower->Enabled = false;
			this->txtBxHardeningCoeff->Enabled = false;
			this->txtBxHardeningPower->Enabled = false;
			this->txtBxHardeningCoeff->Text = "";
			this->txtBxHardeningPower->Text = "";
		}
	}

	System::Void PipelineMaterialControl::btnAddUpdate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->AddUpdateBtnClk(this, e);
	}


	System::Void PipelineMaterialControl::btnCancelReset_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->CancelResetBtnClk(this, e);
	}

	System::Void PipelineMaterialControl::btnRemoveCancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->RemoveCancelBtnClk(this, e);
	}

	void PipelineMaterialControl::UpdateControl(const PipelineMaterial^ mat)
	{
		if (mat != nullptr)
		{
			this->txtBxMaterialName->Text = mat->MaterialName;
			this->txtBxElasticModulus->Text = mat->ElasticModulus.ToString();
			this->txtBxPoissonsRatio->Text = mat->PoissonsRatio.ToString();
			this->txtBxThermalExpCoeff->Text = mat->ThermalExpCoeff.ToString();
			if (mat->IsPlastic)
			{
				this->chkBxAddPlasticProperties->Checked = true;
				this->lblHardeningCoeff->Enabled = true;
				this->lblHardeningPower->Enabled = true;
				this->txtBxHardeningCoeff->Enabled = true;
				this->txtBxHardeningPower->Enabled = true;
				this->txtBxHardeningCoeff->Text = mat->HardeningCoeff.ToString();
				this->txtBxHardeningPower->Text = mat->HardeningPower.ToString();
			}
			else
			{
				this->chkBxAddPlasticProperties->Checked = false;
				this->lblHardeningCoeff->Enabled = false;
				this->lblHardeningPower->Enabled = false;
				this->txtBxHardeningCoeff->Enabled = false;
				this->txtBxHardeningPower->Enabled = false;
				this->txtBxHardeningCoeff->Text = "";
				this->txtBxHardeningPower->Text = "";
			}
			this->btnAddUpdate->Text = "Update Material";
			this->btnRemoveCancel->Text = "Remove Material";
			this->btnCancelReset->Enabled = true;
			this->btnCancelReset->Show();
			this->btnCancelReset->Text = "Reset Values";
		}	
		else
		{
			this->txtBxMaterialName->Text = "";
			this->txtBxElasticModulus->Text = "";
			this->txtBxPoissonsRatio->Text = "";
			this->txtBxThermalExpCoeff->Text = "";
			this->chkBxAddPlasticProperties->Checked = false;
			this->txtBxHardeningCoeff->Text = "";
			this->txtBxHardeningPower->Text = "";
			this->btnAddUpdate->Text = "Add New Material";
			this->btnRemoveCancel->Text = "Cancel";
			this->btnCancelReset->Enabled = false;
			this->btnCancelReset->Hide();
		}
	}



	PipelineMaterial^ PipelineMaterialControl::GetMaterial()
	{
		//PipelineMaterial^ m = gcnew PipelineMaterial();
		this->mPipeMat->MaterialName = this->txtBxMaterialName->Text;
		this->mPipeMat->ElasticModulus = double::Parse(this->txtBxElasticModulus->Text);
		this->mPipeMat->PoissonsRatio = double::Parse(this->txtBxPoissonsRatio->Text);
		this->mPipeMat->ThermalExpCoeff = double::Parse(this->txtBxThermalExpCoeff->Text);
		if (this->chkBxAddPlasticProperties->Checked)
		{
			this->mPipeMat->IsPlastic = true;
			this->mPipeMat->HardeningCoeff = double::Parse(this->txtBxHardeningCoeff->Text);
			this->mPipeMat->HardeningPower = double::Parse(this->txtBxHardeningPower->Text);
		}
		else
		{
			this->mPipeMat->IsPlastic = false;
			this->mPipeMat->HardeningCoeff = 0.0;
			this->mPipeMat->HardeningPower = 0.0;
		}
		return this->mPipeMat;
	}
}