#pragma once

#include "Element.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace DemoSFLpro {

	/// <summary>
	/// Summary for BendElementControl
	/// </summary>
	public ref class BendElementControl : public System::Windows::Forms::UserControl
	{
	public: void UpdateControl(BendElement^ bendelm);
	public: BendElement^ GetBendElement();
	private: BendElement^ mBendElm;

	public:
		BendElementControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->mBendElm = gcnew BendElement();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BendElementControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grpBxBendElem;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  lblRotationAngle;
	private: System::Windows::Forms::TextBox^  txtBxRotationAngle;
	private: System::Windows::Forms::Label^  lblBendAngle;
	private: System::Windows::Forms::TextBox^  txtBxBendAngle;
	private: System::Windows::Forms::Label^  lblBendRadius;
	private: System::Windows::Forms::TextBox^  txtBxBendRadius;
	private: System::Windows::Forms::TextBox^  txtBxBendWallThickness;
	private: System::Windows::Forms::Label^  lblBendWallThickness;
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
			this->grpBxBendElem = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->txtBxBendWallThickness = (gcnew System::Windows::Forms::TextBox());
			this->lblRotationAngle = (gcnew System::Windows::Forms::Label());
			this->txtBxRotationAngle = (gcnew System::Windows::Forms::TextBox());
			this->lblBendAngle = (gcnew System::Windows::Forms::Label());
			this->txtBxBendAngle = (gcnew System::Windows::Forms::TextBox());
			this->lblBendRadius = (gcnew System::Windows::Forms::Label());
			this->txtBxBendRadius = (gcnew System::Windows::Forms::TextBox());
			this->lblBendWallThickness = (gcnew System::Windows::Forms::Label());
			this->grpBxBendElem->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpBxBendElem
			// 
			this->grpBxBendElem->Controls->Add(this->tableLayoutPanel1);
			this->grpBxBendElem->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBxBendElem->Location = System::Drawing::Point(0, 0);
			this->grpBxBendElem->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->grpBxBendElem->Name = L"grpBxBendElem";
			this->grpBxBendElem->Padding = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->grpBxBendElem->Size = System::Drawing::Size(207, 162);
			this->grpBxBendElem->TabIndex = 30;
			this->grpBxBendElem->TabStop = false;
			this->grpBxBendElem->Text = L"Bend Element";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				65)));
			this->tableLayoutPanel1->Controls->Add(this->txtBxBendWallThickness, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->lblRotationAngle, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->txtBxRotationAngle, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->lblBendAngle, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->txtBxBendAngle, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->lblBendRadius, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->txtBxBendRadius, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->lblBendWallThickness, 0, 3);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 25);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(201, 132);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// txtBxBendWallThickness
			// 
			this->txtBxBendWallThickness->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxBendWallThickness->Location = System::Drawing::Point(73, 103);
			this->txtBxBendWallThickness->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxBendWallThickness->Name = L"txtBxBendWallThickness";
			this->txtBxBendWallThickness->Size = System::Drawing::Size(125, 27);
			this->txtBxBendWallThickness->TabIndex = 7;
			this->txtBxBendWallThickness->Text = L"2";
			// 
			// lblRotationAngle
			// 
			this->lblRotationAngle->AutoSize = true;
			this->lblRotationAngle->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblRotationAngle->Location = System::Drawing::Point(3, 66);
			this->lblRotationAngle->Name = L"lblRotationAngle";
			this->lblRotationAngle->Size = System::Drawing::Size(64, 33);
			this->lblRotationAngle->TabIndex = 4;
			this->lblRotationAngle->Text = L"Rotation Angle [°]";
			this->lblRotationAngle->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBxRotationAngle
			// 
			this->txtBxRotationAngle->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxRotationAngle->Location = System::Drawing::Point(73, 70);
			this->txtBxRotationAngle->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxRotationAngle->Name = L"txtBxRotationAngle";
			this->txtBxRotationAngle->Size = System::Drawing::Size(125, 27);
			this->txtBxRotationAngle->TabIndex = 5;
			this->txtBxRotationAngle->Text = L"2";
			// 
			// lblBendAngle
			// 
			this->lblBendAngle->AutoSize = true;
			this->lblBendAngle->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblBendAngle->Location = System::Drawing::Point(3, 33);
			this->lblBendAngle->Name = L"lblBendAngle";
			this->lblBendAngle->Size = System::Drawing::Size(52, 33);
			this->lblBendAngle->TabIndex = 2;
			this->lblBendAngle->Text = L"Bend Angle [°]";
			this->lblBendAngle->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBxBendAngle
			// 
			this->txtBxBendAngle->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxBendAngle->Location = System::Drawing::Point(73, 37);
			this->txtBxBendAngle->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxBendAngle->Name = L"txtBxBendAngle";
			this->txtBxBendAngle->Size = System::Drawing::Size(125, 27);
			this->txtBxBendAngle->TabIndex = 3;
			this->txtBxBendAngle->Text = L"2";
			// 
			// lblBendRadius
			// 
			this->lblBendRadius->AutoSize = true;
			this->lblBendRadius->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblBendRadius->Location = System::Drawing::Point(3, 0);
			this->lblBendRadius->Name = L"lblBendRadius";
			this->lblBendRadius->Size = System::Drawing::Size(57, 33);
			this->lblBendRadius->TabIndex = 0;
			this->lblBendRadius->Text = L"Bend Radius [mm]";
			this->lblBendRadius->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBxBendRadius
			// 
			this->txtBxBendRadius->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxBendRadius->Location = System::Drawing::Point(73, 4);
			this->txtBxBendRadius->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxBendRadius->Name = L"txtBxBendRadius";
			this->txtBxBendRadius->Size = System::Drawing::Size(125, 27);
			this->txtBxBendRadius->TabIndex = 1;
			this->txtBxBendRadius->Text = L"2";
			// 
			// lblBendWallThickness
			// 
			this->lblBendWallThickness->AutoSize = true;
			this->lblBendWallThickness->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblBendWallThickness->Location = System::Drawing::Point(3, 99);
			this->lblBendWallThickness->Name = L"lblBendWallThickness";
			this->lblBendWallThickness->Size = System::Drawing::Size(61, 33);
			this->lblBendWallThickness->TabIndex = 6;
			this->lblBendWallThickness->Text = L"Wall Thickness [mm]";
			this->lblBendWallThickness->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BendElementControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->grpBxBendElem);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"BendElementControl";
			this->Size = System::Drawing::Size(207, 161);
			this->grpBxBendElem->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
