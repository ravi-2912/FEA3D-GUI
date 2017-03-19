#pragma once

#include "PipelineMaterial.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace System::Collections::Generic;

namespace DemoSFLpro {

	/// <summary>
	/// Summary for MaterialControl
	/// </summary>
	public ref class PipelineMaterialControl : public System::Windows::Forms::UserControl
	{
	public: event EventHandler^ AddUpdateBtnClk;
	public: event EventHandler^ RemoveCancelBtnClk;
	public: event EventHandler^ CancelResetBtnClk;
	private: PipelineMaterial^ mPipeMat;
	public: void UpdateControl(const PipelineMaterial^ mat);
	public: PipelineMaterial^ GetMaterial();

	public:
		PipelineMaterialControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			this->mPipeMat = gcnew PipelineMaterial();

			this->btnCancelReset->Enabled = false;
			this->btnCancelReset->Hide();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PipelineMaterialControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  lblThermalExpCoeff;
	private: System::Windows::Forms::TextBox^  txtBxThermalExpCoeff;
	private: System::Windows::Forms::Label^  lblPoissonsRatio;
	private: System::Windows::Forms::TextBox^  txtBxPoissonsRatio;
	private: System::Windows::Forms::Label^  lblElasticModulus;
	private: System::Windows::Forms::TextBox^  txtBxElasticModulus;
	private: System::Windows::Forms::Label^  lblMaterialName;
	private: System::Windows::Forms::TextBox^  txtBxMaterialName;
	private: System::Windows::Forms::CheckBox^  chkBxAddPlasticProperties;

	private: System::Windows::Forms::Label^  lblHardeningCoeff;
	private: System::Windows::Forms::TextBox^  txtBxHardeningCoeff;
	private: System::Windows::Forms::Label^  lblHardeningPower;
	private: System::Windows::Forms::TextBox^  txtBxHardeningPower;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  btnAddUpdate;
	private: System::Windows::Forms::Button^  btnCancelReset;

	private: System::Windows::Forms::Button^  btnRemoveCancel;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblHardeningCoeff = (gcnew System::Windows::Forms::Label());
			this->txtBxHardeningCoeff = (gcnew System::Windows::Forms::TextBox());
			this->lblHardeningPower = (gcnew System::Windows::Forms::Label());
			this->txtBxHardeningPower = (gcnew System::Windows::Forms::TextBox());
			this->lblThermalExpCoeff = (gcnew System::Windows::Forms::Label());
			this->txtBxThermalExpCoeff = (gcnew System::Windows::Forms::TextBox());
			this->lblPoissonsRatio = (gcnew System::Windows::Forms::Label());
			this->txtBxPoissonsRatio = (gcnew System::Windows::Forms::TextBox());
			this->lblElasticModulus = (gcnew System::Windows::Forms::Label());
			this->txtBxElasticModulus = (gcnew System::Windows::Forms::TextBox());
			this->lblMaterialName = (gcnew System::Windows::Forms::Label());
			this->txtBxMaterialName = (gcnew System::Windows::Forms::TextBox());
			this->chkBxAddPlasticProperties = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnRemoveCancel = (gcnew System::Windows::Forms::Button());
			this->btnAddUpdate = (gcnew System::Windows::Forms::Button());
			this->btnCancelReset = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->lblHardeningCoeff, 0, 12);
			this->tableLayoutPanel1->Controls->Add(this->txtBxHardeningCoeff, 0, 13);
			this->tableLayoutPanel1->Controls->Add(this->lblHardeningPower, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->txtBxHardeningPower, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->lblThermalExpCoeff, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->txtBxThermalExpCoeff, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->lblPoissonsRatio, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->txtBxPoissonsRatio, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->lblElasticModulus, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->txtBxElasticModulus, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->lblMaterialName, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->txtBxMaterialName, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->chkBxAddPlasticProperties, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 15);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Padding = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->tableLayoutPanel1->RowCount = 17;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 11)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 59)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 27)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(471, 554);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// lblHardeningCoeff
			// 
			this->lblHardeningCoeff->AutoSize = true;
			this->lblHardeningCoeff->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblHardeningCoeff->Enabled = false;
			this->lblHardeningCoeff->Location = System::Drawing::Point(6, 383);
			this->lblHardeningCoeff->Name = L"lblHardeningCoeff";
			this->lblHardeningCoeff->Size = System::Drawing::Size(155, 33);
			this->lblHardeningCoeff->TabIndex = 11;
			this->lblHardeningCoeff->Text = L"Hardening Coefficient";
			this->lblHardeningCoeff->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxHardeningCoeff
			// 
			this->txtBxHardeningCoeff->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxHardeningCoeff->Enabled = false;
			this->txtBxHardeningCoeff->Location = System::Drawing::Point(6, 419);
			this->txtBxHardeningCoeff->Name = L"txtBxHardeningCoeff";
			this->txtBxHardeningCoeff->Size = System::Drawing::Size(459, 27);
			this->txtBxHardeningCoeff->TabIndex = 12;
			// 
			// lblHardeningPower
			// 
			this->lblHardeningPower->AutoSize = true;
			this->lblHardeningPower->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblHardeningPower->Enabled = false;
			this->lblHardeningPower->Location = System::Drawing::Point(6, 317);
			this->lblHardeningPower->Name = L"lblHardeningPower";
			this->lblHardeningPower->Size = System::Drawing::Size(123, 33);
			this->lblHardeningPower->TabIndex = 9;
			this->lblHardeningPower->Text = L"Hardening Power";
			this->lblHardeningPower->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxHardeningPower
			// 
			this->txtBxHardeningPower->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxHardeningPower->Enabled = false;
			this->txtBxHardeningPower->Location = System::Drawing::Point(6, 353);
			this->txtBxHardeningPower->Name = L"txtBxHardeningPower";
			this->txtBxHardeningPower->Size = System::Drawing::Size(459, 27);
			this->txtBxHardeningPower->TabIndex = 10;
			// 
			// lblThermalExpCoeff
			// 
			this->lblThermalExpCoeff->AutoSize = true;
			this->lblThermalExpCoeff->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblThermalExpCoeff->Location = System::Drawing::Point(6, 198);
			this->lblThermalExpCoeff->Name = L"lblThermalExpCoeff";
			this->lblThermalExpCoeff->Size = System::Drawing::Size(283, 33);
			this->lblThermalExpCoeff->TabIndex = 6;
			this->lblThermalExpCoeff->Text = L"Coefficient of Thermal Expansion [m/mK]";
			this->lblThermalExpCoeff->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxThermalExpCoeff
			// 
			this->txtBxThermalExpCoeff->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxThermalExpCoeff->Location = System::Drawing::Point(6, 234);
			this->txtBxThermalExpCoeff->Name = L"txtBxThermalExpCoeff";
			this->txtBxThermalExpCoeff->Size = System::Drawing::Size(459, 27);
			this->txtBxThermalExpCoeff->TabIndex = 7;
			// 
			// lblPoissonsRatio
			// 
			this->lblPoissonsRatio->AutoSize = true;
			this->lblPoissonsRatio->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblPoissonsRatio->Location = System::Drawing::Point(6, 132);
			this->lblPoissonsRatio->Name = L"lblPoissonsRatio";
			this->lblPoissonsRatio->Size = System::Drawing::Size(106, 33);
			this->lblPoissonsRatio->TabIndex = 4;
			this->lblPoissonsRatio->Text = L"Poisson\'s Ratio";
			this->lblPoissonsRatio->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxPoissonsRatio
			// 
			this->txtBxPoissonsRatio->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxPoissonsRatio->Location = System::Drawing::Point(6, 168);
			this->txtBxPoissonsRatio->Name = L"txtBxPoissonsRatio";
			this->txtBxPoissonsRatio->Size = System::Drawing::Size(459, 27);
			this->txtBxPoissonsRatio->TabIndex = 5;
			// 
			// lblElasticModulus
			// 
			this->lblElasticModulus->AutoSize = true;
			this->lblElasticModulus->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblElasticModulus->Location = System::Drawing::Point(6, 66);
			this->lblElasticModulus->Name = L"lblElasticModulus";
			this->lblElasticModulus->Size = System::Drawing::Size(151, 33);
			this->lblElasticModulus->TabIndex = 2;
			this->lblElasticModulus->Text = L"Elastic Modulus [GPa]";
			this->lblElasticModulus->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxElasticModulus
			// 
			this->txtBxElasticModulus->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxElasticModulus->Location = System::Drawing::Point(6, 102);
			this->txtBxElasticModulus->Name = L"txtBxElasticModulus";
			this->txtBxElasticModulus->Size = System::Drawing::Size(459, 27);
			this->txtBxElasticModulus->TabIndex = 3;
			// 
			// lblMaterialName
			// 
			this->lblMaterialName->AutoSize = true;
			this->lblMaterialName->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblMaterialName->Location = System::Drawing::Point(6, 0);
			this->lblMaterialName->Name = L"lblMaterialName";
			this->lblMaterialName->Size = System::Drawing::Size(108, 33);
			this->lblMaterialName->TabIndex = 0;
			this->lblMaterialName->Text = L"Material Name";
			this->lblMaterialName->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxMaterialName
			// 
			this->txtBxMaterialName->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxMaterialName->Location = System::Drawing::Point(6, 36);
			this->txtBxMaterialName->Name = L"txtBxMaterialName";
			this->txtBxMaterialName->Size = System::Drawing::Size(459, 27);
			this->txtBxMaterialName->TabIndex = 1;
			// 
			// chkBxAddPlasticProperties
			// 
			this->chkBxAddPlasticProperties->AutoSize = true;
			this->chkBxAddPlasticProperties->Dock = System::Windows::Forms::DockStyle::Left;
			this->chkBxAddPlasticProperties->Location = System::Drawing::Point(6, 287);
			this->chkBxAddPlasticProperties->Name = L"chkBxAddPlasticProperties";
			this->chkBxAddPlasticProperties->Size = System::Drawing::Size(176, 27);
			this->chkBxAddPlasticProperties->TabIndex = 8;
			this->chkBxAddPlasticProperties->Text = L"Add Plastic Properties";
			this->chkBxAddPlasticProperties->UseVisualStyleBackColor = true;
			this->chkBxAddPlasticProperties->CheckedChanged += gcnew System::EventHandler(this, &PipelineMaterialControl::chkAddPlasticProperties_CheckedChanged);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->Controls->Add(this->btnRemoveCancel, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnAddUpdate, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnCancelReset, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(6, 463);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(459, 53);
			this->tableLayoutPanel2->TabIndex = 13;
			// 
			// btnRemoveCancel
			// 
			this->btnRemoveCancel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnRemoveCancel->Location = System::Drawing::Point(156, 3);
			this->btnRemoveCancel->Name = L"btnRemoveCancel";
			this->btnRemoveCancel->Size = System::Drawing::Size(147, 47);
			this->btnRemoveCancel->TabIndex = 2;
			this->btnRemoveCancel->Text = L"Remove Material";
			this->btnRemoveCancel->UseVisualStyleBackColor = true;
			this->btnRemoveCancel->Click += gcnew System::EventHandler(this, &PipelineMaterialControl::btnRemoveCancel_Click);
			// 
			// btnAddUpdate
			// 
			this->btnAddUpdate->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnAddUpdate->Location = System::Drawing::Point(3, 3);
			this->btnAddUpdate->Name = L"btnAddUpdate";
			this->btnAddUpdate->Size = System::Drawing::Size(147, 47);
			this->btnAddUpdate->TabIndex = 0;
			this->btnAddUpdate->Text = L"Add New Material";
			this->btnAddUpdate->UseVisualStyleBackColor = true;
			this->btnAddUpdate->Click += gcnew System::EventHandler(this, &PipelineMaterialControl::btnAddUpdate_Click);
			// 
			// btnCancelReset
			// 
			this->btnCancelReset->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnCancelReset->Location = System::Drawing::Point(309, 3);
			this->btnCancelReset->Name = L"btnCancelReset";
			this->btnCancelReset->Size = System::Drawing::Size(147, 47);
			this->btnCancelReset->TabIndex = 1;
			this->btnCancelReset->Text = L"Cancel";
			this->btnCancelReset->UseVisualStyleBackColor = true;
			this->btnCancelReset->Click += gcnew System::EventHandler(this, &PipelineMaterialControl::btnCancelReset_Click);
			// 
			// PipelineMaterialControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"PipelineMaterialControl";
			this->Size = System::Drawing::Size(471, 616);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void chkAddPlasticProperties_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnAddUpdate_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCancelReset_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnRemoveCancel_Click(System::Object^  sender, System::EventArgs^  e);



};



}
