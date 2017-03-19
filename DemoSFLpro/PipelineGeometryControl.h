#pragma once

#include "Element.h"
#include "PipeElementCtrl.h"
#include "BendElementControl.h"
#include "ReducerElementControl.h"
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
	/// Summary for PipelineGeometryControl
	/// </summary>
	public ref class PipelineGeometryControl : public System::Windows::Forms::UserControl
	{
	private: PipeElementCtrl^ mPipeElemCtrl;
	private: BendElementControl ^mBendElemCtrl;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: ReducerElementControl^ mReducerElemCtrl;
	public: void UpdateControl(Element^ elm);
	public: Element^ GetElement();
	public: void UpdateMatCmbBx(const array<String^>^ matstr);

	public: event EventHandler^ MaterialDropDownCmbBx;
	public: event EventHandler^ AddUpdateBtnClk;
	public: event EventHandler^ CancelRemoveBtnClk;
	public: event EventHandler^ CancelResetBtnClk;
	private: Element^ mElement;
	public: void UpdateIDtxtBx(unsigned int id);

	public:
		PipelineGeometryControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//mElement = gcnew Element();

			this->mPipeElemCtrl = gcnew PipeElementCtrl();
			this->tableLayoutPanel1->Controls->Add(this->mPipeElemCtrl, 0, 13);
			this->mPipeElemCtrl->Dock = Windows::Forms::DockStyle::Top;
			this->mPipeElemCtrl->Enabled = true;
			this->mPipeElemCtrl->Show();

			this->mBendElemCtrl = gcnew BendElementControl();
			this->tableLayoutPanel1->Controls->Add(this->mBendElemCtrl, 0, 13);
			this->mBendElemCtrl->Dock = Windows::Forms::DockStyle::Top;
			this->mBendElemCtrl->Enabled = false;
			this->mBendElemCtrl->Hide();

			this->mReducerElemCtrl = gcnew ReducerElementControl();
			this->tableLayoutPanel1->Controls->Add(this->mReducerElemCtrl, 0, 13);
			this->mReducerElemCtrl->Dock = Windows::Forms::DockStyle::Top;
			this->mReducerElemCtrl->Enabled = false;
			this->mReducerElemCtrl->Hide();

			//TEMP
			this->cmbBxDiameterType->SelectedIndex = 1;
			this->cmbBxMaterial->SelectedIndex = 1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PipelineGeometryControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grpBxElementType;
	private: System::Windows::Forms::RadioButton^  rdBtnRigid;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  btnCancelReset;

	private: System::Windows::Forms::Button^  btnCancelRemove;
	private: System::Windows::Forms::Button^  btnAddUpdate;
	private: System::Windows::Forms::Label^  lblMaterial;
	private: System::Windows::Forms::ComboBox^  cmbBxMaterial;
	private: System::Windows::Forms::RadioButton^  rdBtnTee;
	private: System::Windows::Forms::RadioButton^  rdBtmReducer;
	private: System::Windows::Forms::RadioButton^  rdBtnBend;
	private: System::Windows::Forms::RadioButton^  rdBtnPipe;
	private: System::Windows::Forms::ComboBox^  cmbBxDiameterType;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  lblUnderTolerance;
	private: System::Windows::Forms::TextBox^  txtBxUnderTolerance;
	private: System::Windows::Forms::Label^  lblWallThickness;
	private: System::Windows::Forms::TextBox^  txtBxWallThickness;
	private: System::Windows::Forms::Label^  lblDiameterType;
	private: System::Windows::Forms::Label^  lblDiameter;
	private: System::Windows::Forms::TextBox^  txtBxDiameter;
	private: System::Windows::Forms::Label^  lblElementID;
	private: System::Windows::Forms::TextBox^  txtBxElementID;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;

	protected:

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
			this->grpBxElementType = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->rdBtnRigid = (gcnew System::Windows::Forms::RadioButton());
			this->rdBtnPipe = (gcnew System::Windows::Forms::RadioButton());
			this->rdBtnBend = (gcnew System::Windows::Forms::RadioButton());
			this->rdBtnTee = (gcnew System::Windows::Forms::RadioButton());
			this->rdBtmReducer = (gcnew System::Windows::Forms::RadioButton());
			this->cmbBxDiameterType = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblUnderTolerance = (gcnew System::Windows::Forms::Label());
			this->txtBxUnderTolerance = (gcnew System::Windows::Forms::TextBox());
			this->lblWallThickness = (gcnew System::Windows::Forms::Label());
			this->txtBxWallThickness = (gcnew System::Windows::Forms::TextBox());
			this->lblDiameterType = (gcnew System::Windows::Forms::Label());
			this->lblDiameter = (gcnew System::Windows::Forms::Label());
			this->txtBxDiameter = (gcnew System::Windows::Forms::TextBox());
			this->lblElementID = (gcnew System::Windows::Forms::Label());
			this->txtBxElementID = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnCancelReset = (gcnew System::Windows::Forms::Button());
			this->btnCancelRemove = (gcnew System::Windows::Forms::Button());
			this->btnAddUpdate = (gcnew System::Windows::Forms::Button());
			this->lblMaterial = (gcnew System::Windows::Forms::Label());
			this->cmbBxMaterial = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->grpBxElementType->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpBxElementType
			// 
			this->grpBxElementType->Controls->Add(this->tableLayoutPanel3);
			this->grpBxElementType->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grpBxElementType->Location = System::Drawing::Point(6, 69);
			this->grpBxElementType->Name = L"grpBxElementType";
			this->grpBxElementType->Size = System::Drawing::Size(508, 90);
			this->grpBxElementType->TabIndex = 4;
			this->grpBxElementType->TabStop = false;
			this->grpBxElementType->Text = L"Element Type";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel3->Controls->Add(this->rdBtnRigid, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->rdBtnPipe, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->rdBtnBend, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->rdBtnTee, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->rdBtmReducer, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 23);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(502, 64);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// rdBtnRigid
			// 
			this->rdBtnRigid->AutoSize = true;
			this->rdBtnRigid->Dock = System::Windows::Forms::DockStyle::Left;
			this->rdBtnRigid->Location = System::Drawing::Point(170, 35);
			this->rdBtnRigid->Name = L"rdBtnRigid";
			this->rdBtnRigid->Size = System::Drawing::Size(65, 26);
			this->rdBtnRigid->TabIndex = 4;
			this->rdBtnRigid->TabStop = true;
			this->rdBtnRigid->Text = L"Rigid";
			this->rdBtnRigid->UseVisualStyleBackColor = true;
			// 
			// rdBtnPipe
			// 
			this->rdBtnPipe->AutoSize = true;
			this->rdBtnPipe->Checked = true;
			this->rdBtnPipe->Dock = System::Windows::Forms::DockStyle::Left;
			this->rdBtnPipe->Location = System::Drawing::Point(3, 3);
			this->rdBtnPipe->Name = L"rdBtnPipe";
			this->rdBtnPipe->Size = System::Drawing::Size(59, 26);
			this->rdBtnPipe->TabIndex = 0;
			this->rdBtnPipe->TabStop = true;
			this->rdBtnPipe->Text = L"Pipe";
			this->rdBtnPipe->UseVisualStyleBackColor = true;
			this->rdBtnPipe->CheckedChanged += gcnew System::EventHandler(this, &PipelineGeometryControl::radioButton1_CheckedChanged);
			// 
			// rdBtnBend
			// 
			this->rdBtnBend->AutoSize = true;
			this->rdBtnBend->Dock = System::Windows::Forms::DockStyle::Left;
			this->rdBtnBend->Location = System::Drawing::Point(170, 3);
			this->rdBtnBend->Name = L"rdBtnBend";
			this->rdBtnBend->Size = System::Drawing::Size(64, 26);
			this->rdBtnBend->TabIndex = 1;
			this->rdBtnBend->TabStop = true;
			this->rdBtnBend->Text = L"Bend";
			this->rdBtnBend->UseVisualStyleBackColor = true;
			this->rdBtnBend->CheckedChanged += gcnew System::EventHandler(this, &PipelineGeometryControl::radioButton2_CheckedChanged);
			// 
			// rdBtnTee
			// 
			this->rdBtnTee->AutoSize = true;
			this->rdBtnTee->Dock = System::Windows::Forms::DockStyle::Left;
			this->rdBtnTee->Location = System::Drawing::Point(3, 35);
			this->rdBtnTee->Name = L"rdBtnTee";
			this->rdBtnTee->Size = System::Drawing::Size(53, 26);
			this->rdBtnTee->TabIndex = 3;
			this->rdBtnTee->TabStop = true;
			this->rdBtnTee->Text = L"Tee";
			this->rdBtnTee->UseVisualStyleBackColor = true;
			// 
			// rdBtmReducer
			// 
			this->rdBtmReducer->AutoSize = true;
			this->rdBtmReducer->Dock = System::Windows::Forms::DockStyle::Left;
			this->rdBtmReducer->Location = System::Drawing::Point(337, 3);
			this->rdBtmReducer->Name = L"rdBtmReducer";
			this->rdBtmReducer->Size = System::Drawing::Size(84, 26);
			this->rdBtmReducer->TabIndex = 2;
			this->rdBtmReducer->TabStop = true;
			this->rdBtmReducer->Text = L"Reducer";
			this->rdBtmReducer->UseVisualStyleBackColor = true;
			this->rdBtmReducer->CheckedChanged += gcnew System::EventHandler(this, &PipelineGeometryControl::rdBtmReducer_CheckedChanged);
			// 
			// cmbBxDiameterType
			// 
			this->cmbBxDiameterType->Dock = System::Windows::Forms::DockStyle::Top;
			this->cmbBxDiameterType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBxDiameterType->FormattingEnabled = true;
			this->cmbBxDiameterType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Inner", L"Outer", L"Nominal" });
			this->cmbBxDiameterType->Location = System::Drawing::Point(6, 264);
			this->cmbBxDiameterType->Name = L"cmbBxDiameterType";
			this->cmbBxDiameterType->Size = System::Drawing::Size(508, 28);
			this->cmbBxDiameterType->TabIndex = 27;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->lblUnderTolerance, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->txtBxUnderTolerance, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->lblWallThickness, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->cmbBxDiameterType, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->txtBxWallThickness, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->lblDiameterType, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->lblDiameter, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->txtBxDiameter, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->lblElementID, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->txtBxElementID, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->grpBxElementType, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 14);
			this->tableLayoutPanel1->Controls->Add(this->lblMaterial, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->cmbBxMaterial, 0, 12);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Padding = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->tableLayoutPanel1->RowCount = 16;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 96)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 118)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 24)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(520, 869);
			this->tableLayoutPanel1->TabIndex = 29;
			// 
			// lblUnderTolerance
			// 
			this->lblUnderTolerance->AutoSize = true;
			this->lblUnderTolerance->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblUnderTolerance->Location = System::Drawing::Point(6, 360);
			this->lblUnderTolerance->Name = L"lblUnderTolerance";
			this->lblUnderTolerance->Size = System::Drawing::Size(172, 33);
			this->lblUnderTolerance->TabIndex = 11;
			this->lblUnderTolerance->Text = L"Mill Under Tolerance [%]";
			this->lblUnderTolerance->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxUnderTolerance
			// 
			this->txtBxUnderTolerance->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxUnderTolerance->Location = System::Drawing::Point(6, 396);
			this->txtBxUnderTolerance->Name = L"txtBxUnderTolerance";
			this->txtBxUnderTolerance->Size = System::Drawing::Size(508, 27);
			this->txtBxUnderTolerance->TabIndex = 12;
			this->txtBxUnderTolerance->Text = L"1";
			// 
			// lblWallThickness
			// 
			this->lblWallThickness->AutoSize = true;
			this->lblWallThickness->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblWallThickness->Location = System::Drawing::Point(6, 294);
			this->lblWallThickness->Name = L"lblWallThickness";
			this->lblWallThickness->Size = System::Drawing::Size(144, 33);
			this->lblWallThickness->TabIndex = 9;
			this->lblWallThickness->Text = L"Wall Thickness [mm]";
			this->lblWallThickness->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxWallThickness
			// 
			this->txtBxWallThickness->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxWallThickness->Location = System::Drawing::Point(6, 330);
			this->txtBxWallThickness->Name = L"txtBxWallThickness";
			this->txtBxWallThickness->Size = System::Drawing::Size(508, 27);
			this->txtBxWallThickness->TabIndex = 10;
			this->txtBxWallThickness->Text = L"1";
			// 
			// lblDiameterType
			// 
			this->lblDiameterType->AutoSize = true;
			this->lblDiameterType->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblDiameterType->Location = System::Drawing::Point(6, 228);
			this->lblDiameterType->Name = L"lblDiameterType";
			this->lblDiameterType->Size = System::Drawing::Size(106, 33);
			this->lblDiameterType->TabIndex = 6;
			this->lblDiameterType->Text = L"Diameter Type";
			this->lblDiameterType->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// lblDiameter
			// 
			this->lblDiameter->AutoSize = true;
			this->lblDiameter->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblDiameter->Location = System::Drawing::Point(6, 162);
			this->lblDiameter->Name = L"lblDiameter";
			this->lblDiameter->Size = System::Drawing::Size(111, 33);
			this->lblDiameter->TabIndex = 4;
			this->lblDiameter->Text = L"Diameter [mm]";
			this->lblDiameter->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxDiameter
			// 
			this->txtBxDiameter->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxDiameter->Location = System::Drawing::Point(6, 198);
			this->txtBxDiameter->Name = L"txtBxDiameter";
			this->txtBxDiameter->Size = System::Drawing::Size(508, 27);
			this->txtBxDiameter->TabIndex = 5;
			// 
			// lblElementID
			// 
			this->lblElementID->AutoSize = true;
			this->lblElementID->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblElementID->Location = System::Drawing::Point(6, 0);
			this->lblElementID->Name = L"lblElementID";
			this->lblElementID->Size = System::Drawing::Size(82, 33);
			this->lblElementID->TabIndex = 0;
			this->lblElementID->Text = L"Element ID";
			this->lblElementID->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxElementID
			// 
			this->txtBxElementID->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxElementID->Enabled = false;
			this->txtBxElementID->Location = System::Drawing::Point(6, 36);
			this->txtBxElementID->Name = L"txtBxElementID";
			this->txtBxElementID->Size = System::Drawing::Size(508, 27);
			this->txtBxElementID->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33334F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33334F)));
			this->tableLayoutPanel2->Controls->Add(this->button3, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->button2, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->button1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->btnCancelReset, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnCancelRemove, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->btnAddUpdate, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(6, 495);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(508, 112);
			this->tableLayoutPanel2->TabIndex = 28;
			// 
			// btnCancelReset
			// 
			this->btnCancelReset->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnCancelReset->Location = System::Drawing::Point(341, 3);
			this->btnCancelReset->Name = L"btnCancelReset";
			this->btnCancelReset->Size = System::Drawing::Size(164, 50);
			this->btnCancelReset->TabIndex = 2;
			this->btnCancelReset->Text = L"Reset";
			this->btnCancelReset->UseVisualStyleBackColor = true;
			this->btnCancelReset->Click += gcnew System::EventHandler(this, &PipelineGeometryControl::btnCancelReset_Click);
			// 
			// btnCancelRemove
			// 
			this->btnCancelRemove->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnCancelRemove->Location = System::Drawing::Point(172, 3);
			this->btnCancelRemove->Name = L"btnCancelRemove";
			this->btnCancelRemove->Size = System::Drawing::Size(163, 50);
			this->btnCancelRemove->TabIndex = 1;
			this->btnCancelRemove->Text = L"Cancel/Remove";
			this->btnCancelRemove->UseVisualStyleBackColor = true;
			this->btnCancelRemove->Click += gcnew System::EventHandler(this, &PipelineGeometryControl::btnCancelRemove_Click);
			// 
			// btnAddUpdate
			// 
			this->btnAddUpdate->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnAddUpdate->Location = System::Drawing::Point(3, 3);
			this->btnAddUpdate->Name = L"btnAddUpdate";
			this->btnAddUpdate->Size = System::Drawing::Size(163, 50);
			this->btnAddUpdate->TabIndex = 0;
			this->btnAddUpdate->Text = L"Add/Update";
			this->btnAddUpdate->UseVisualStyleBackColor = true;
			this->btnAddUpdate->Click += gcnew System::EventHandler(this, &PipelineGeometryControl::btnAddUpdate_Click);
			// 
			// lblMaterial
			// 
			this->lblMaterial->AutoSize = true;
			this->lblMaterial->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblMaterial->Location = System::Drawing::Point(6, 426);
			this->lblMaterial->Name = L"lblMaterial";
			this->lblMaterial->Size = System::Drawing::Size(64, 33);
			this->lblMaterial->TabIndex = 29;
			this->lblMaterial->Text = L"Material";
			this->lblMaterial->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// cmbBxMaterial
			// 
			this->cmbBxMaterial->Dock = System::Windows::Forms::DockStyle::Top;
			this->cmbBxMaterial->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBxMaterial->FormattingEnabled = true;
			this->cmbBxMaterial->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"a", L"b", L"c" });
			this->cmbBxMaterial->Location = System::Drawing::Point(6, 462);
			this->cmbBxMaterial->Name = L"cmbBxMaterial";
			this->cmbBxMaterial->Size = System::Drawing::Size(508, 28);
			this->cmbBxMaterial->TabIndex = 30;
			this->cmbBxMaterial->DropDown += gcnew System::EventHandler(this, &PipelineGeometryControl::cmbBxMaterial_DropDown);
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(341, 59);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 50);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Remove All";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button2->Location = System::Drawing::Point(172, 59);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 50);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Insert After";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->Location = System::Drawing::Point(3, 59);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(163, 50);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Insert Before";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// PipelineGeometryControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"PipelineGeometryControl";
			this->Size = System::Drawing::Size(520, 938);
			this->grpBxElementType->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (this->rdBtnPipe->Checked)
			{
				this->mPipeElemCtrl->Enabled = true;
				this->mPipeElemCtrl->Show();
			}
			else
			{
				this->mPipeElemCtrl->Enabled = false;
				this->mPipeElemCtrl->Hide();
			}
		}
		private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (this->rdBtnBend->Checked)
			{
				this->mBendElemCtrl->Enabled = true;
				this->mBendElemCtrl->Show();
			}
			else
			{
				this->mBendElemCtrl->Enabled = false;
				this->mBendElemCtrl->Hide();
			}
		}
		private: System::Void rdBtmReducer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (this->rdBtmReducer->Checked)
			{
				this->mReducerElemCtrl->Enabled = true;
				this->mReducerElemCtrl->Show();
			}
			else
			{
				this->mReducerElemCtrl->Enabled = false;
				this->mReducerElemCtrl->Hide();
			}
		}
		private: System::Void cmbBxMaterial_DropDown(System::Object^  sender, System::EventArgs^  e) {
			this->MaterialDropDownCmbBx(this, e);			
		}
		private: System::Void btnAddUpdate_Click(System::Object^  sender, System::EventArgs^  e) {
			this->AddUpdateBtnClk(this, e);
		}
		private: System::Void btnCancelRemove_Click(System::Object^  sender, System::EventArgs^  e) {
			this->CancelRemoveBtnClk(this, e);
		}
		private: System::Void btnCancelReset_Click(System::Object^  sender, System::EventArgs^  e) {
			this->CancelResetBtnClk(this, e);
		}

	};
}
