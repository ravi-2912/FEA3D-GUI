#include "PipelineGeometryControl.h"

namespace DemoSFLpro
{
	void PipelineGeometryControl::UpdateControl(Element^ elm)
	{
		if (elm != nullptr)
		{
			this->txtBxElementID->Text = elm->ID.ToString();
			switch (elm->ElementType)
			{
			case ElementTypes::PIPE:
			{
				this->rdBtnPipe->Checked = true;
				PipeElement^ pipelm = safe_cast<PipeElement^>(elm);
				this->mPipeElemCtrl->UpdateControl(pipelm);
			}
				break;
			case ElementTypes::BEND:
			{
				this->rdBtnBend->Checked = true;
				BendElement^ bendelm = dynamic_cast<BendElement^>(elm);
				this->mBendElemCtrl->UpdateControl(bendelm);
			}
				break;
			case ElementTypes::REDUCER:
				this->rdBtmReducer->Checked = true;
				break;
			case ElementTypes::TEE:
				this->rdBtnTee->Checked = true;
				break;
			case ElementTypes::RIGID:
				this->rdBtnRigid->Checked = true;
				break;
			default:
				this->rdBtnPipe->Checked = false;
				this->rdBtnBend->Checked = false;
				this->rdBtmReducer->Checked = false;
				this->rdBtnTee->Checked = false;
				this->rdBtnRigid->Checked = false;
				break;
			}
			this->txtBxDiameter->Text = elm->Diameter.ToString();
			this->txtBxUnderTolerance->Text = elm->UnderTolerance.ToString();
			this->txtBxWallThickness->Text = elm->WallThickness.ToString();
			switch (elm->DiameterType)
			{
			case DiameterTypes::ID:
				this->cmbBxDiameterType->Text = "Inner";
				break;
			case DiameterTypes::OD:
				this->cmbBxDiameterType->Text = "Outer";
				break;
			case DiameterTypes::ND:
				this->cmbBxDiameterType->Text = "Nominal";
				break;
			}
			this->cmbBxMaterial->Text = elm->Material;

			this->btnAddUpdate->Text = "Update";
			this->btnCancelRemove->Text = "Remove";
			this->btnCancelReset->Enabled = true;
			this->btnCancelReset->Show();
			this->btnCancelReset->Text = "Reset";
		}
		else
		{
			//this->txtBxElementID->Text = "";
			//this->txtBxDiameter->Text = "";
			//this->txtBxUnderTolerance->Text = "";
			//this->txtBxWallThickness->Text = "";
			////this->cmbBxDiameterType->Text = "";
			////this->cmbBxMaterial->Text = "";
			//this->cmbBxDiameterType->SelectedIndex = -1;
			//this->cmbBxMaterial->SelectedIndex = -1;
			//this->rdBtnPipe->Checked = false;
			//this->rdBtnBend->Checked = false;
			//this->rdBtmReducer->Checked = false;
			//this->rdBtnTee->Checked = false;
			//this->rdBtnRigid->Checked = false;
			this->btnAddUpdate->Text = "Add Element";
			this->btnCancelRemove->Text = "Cancel";
			this->btnCancelReset->Enabled = false;
			this->btnCancelReset->Hide();
			//this->mPipeElemCtrl->UpdateControl(nullptr);
			//this->mBendElemCtrl->UpdateControl(nullptr);
		}
	}

	void PipelineGeometryControl::UpdateMatCmbBx(const array<String^>^ matstr)
	{
		if (matstr != nullptr)
		{
			this->cmbBxMaterial->Items->Clear();
			for each(String^ s in matstr)
				this->cmbBxMaterial->Items->Add(s);			
		}
	}

	Element^ PipelineGeometryControl::GetElement()
	{
		//for each (Control^ c in this->grpBxElementType->GetContainerControl())
		if (this->rdBtnPipe->Checked)
		{
			mElement = gcnew PipeElement(this->mPipeElemCtrl->GetPipeElement());
			mElement->ID = int::Parse(this->txtBxElementID->Text);
			mElement->ElementType = ElementTypes::PIPE;
			mElement->Diameter = double::Parse(this->txtBxDiameter->Text);
			mElement->DiameterType = (this->cmbBxDiameterType->Text->Equals("Inner")) ? DiameterTypes::ID :
				((this->cmbBxDiameterType->Text->Equals("Outer")) ? DiameterTypes::OD : DiameterTypes::ND);
			mElement->WallThickness = double::Parse(this->txtBxWallThickness->Text);
			mElement->UnderTolerance = double::Parse(this->txtBxUnderTolerance->Text);
			mElement->Material = this->cmbBxMaterial->Text;
			return mElement;
		}
		if (this->rdBtnBend->Checked)
		{
			mElement = gcnew BendElement(this->mBendElemCtrl->GetBendElement());
			mElement->ID = int::Parse(this->txtBxElementID->Text);
			mElement->ElementType = ElementTypes::BEND;
			mElement->Diameter = double::Parse(this->txtBxDiameter->Text);
			mElement->DiameterType = (this->cmbBxDiameterType->Text->Equals("Inner")) ? DiameterTypes::ID :
				((this->cmbBxDiameterType->Text->Equals("Outer")) ? DiameterTypes::OD : DiameterTypes::ND);
			mElement->WallThickness = double::Parse(this->txtBxWallThickness->Text);
			mElement->UnderTolerance = double::Parse(this->txtBxUnderTolerance->Text);
			mElement->Material = this->cmbBxMaterial->Text;
			return mElement;
		}
		else
		{
			return nullptr;
		}
	}

	void PipelineGeometryControl::UpdateIDtxtBx(unsigned int id)
	{
		this->txtBxElementID->Text = id.ToString();
	}
}