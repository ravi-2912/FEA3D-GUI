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
	/// Summary for PipeElement
	/// </summary>
	public ref class PipeElementCtrl : public System::Windows::Forms::UserControl
	{
	public: void UpdateControl(PipeElement^ pipelm);
	public: PipeElement^ GetPipeElement();
	private: PipeElement^ mPipElm;

	public:
		PipeElementCtrl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->mPipElm = gcnew PipeElement();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PipeElementCtrl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grpBxPipeElem;
	protected:

	protected:
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  lblLength;
	private: System::Windows::Forms::TextBox^  txtBxLength;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::TextBox^  txtBxGamma;



	private: System::Windows::Forms::Label^  lblLx;
	private: System::Windows::Forms::Label^  lblLy;
	private: System::Windows::Forms::TextBox^  txtBxBeta;




	private: System::Windows::Forms::Label^  lblLz;
	private: System::Windows::Forms::TextBox^  txtBxAlpha;

	private: System::Windows::Forms::Label^  lblAlpha;
	private: System::Windows::Forms::Label^  lblBeta;






	private: System::Windows::Forms::TextBox^  txtBxLz;
	private: System::Windows::Forms::Label^  lblGamma;



	private: System::Windows::Forms::TextBox^  txtBxLy;

	private: System::Windows::Forms::TextBox^  txtBxLx;


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
			this->grpBxPipeElem = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblLength = (gcnew System::Windows::Forms::Label());
			this->txtBxLength = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->txtBxGamma = (gcnew System::Windows::Forms::TextBox());
			this->lblLx = (gcnew System::Windows::Forms::Label());
			this->lblLy = (gcnew System::Windows::Forms::Label());
			this->txtBxBeta = (gcnew System::Windows::Forms::TextBox());
			this->lblLz = (gcnew System::Windows::Forms::Label());
			this->txtBxAlpha = (gcnew System::Windows::Forms::TextBox());
			this->lblAlpha = (gcnew System::Windows::Forms::Label());
			this->lblBeta = (gcnew System::Windows::Forms::Label());
			this->txtBxLz = (gcnew System::Windows::Forms::TextBox());
			this->lblGamma = (gcnew System::Windows::Forms::Label());
			this->txtBxLy = (gcnew System::Windows::Forms::TextBox());
			this->txtBxLx = (gcnew System::Windows::Forms::TextBox());
			this->grpBxPipeElem->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpBxPipeElem
			// 
			this->grpBxPipeElem->Controls->Add(this->tableLayoutPanel2);
			this->grpBxPipeElem->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpBxPipeElem->Location = System::Drawing::Point(0, 0);
			this->grpBxPipeElem->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->grpBxPipeElem->Name = L"grpBxPipeElem";
			this->grpBxPipeElem->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->grpBxPipeElem->Size = System::Drawing::Size(284, 179);
			this->grpBxPipeElem->TabIndex = 29;
			this->grpBxPipeElem->TabStop = false;
			this->grpBxPipeElem->Text = L"Pipe Element";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel5, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 24);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 110)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 175)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(278, 156);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel4->Controls->Add(this->lblLength, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->txtBxLength, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 4);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 36)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(272, 36);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// lblLength
			// 
			this->lblLength->AutoSize = true;
			this->lblLength->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblLength->Location = System::Drawing::Point(3, 0);
			this->lblLength->Name = L"lblLength";
			this->lblLength->Size = System::Drawing::Size(94, 36);
			this->lblLength->TabIndex = 5;
			this->lblLength->Text = L"Length [mm]";
			this->lblLength->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBxLength
			// 
			this->txtBxLength->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxLength->Location = System::Drawing::Point(103, 5);
			this->txtBxLength->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->txtBxLength->Name = L"txtBxLength";
			this->txtBxLength->Size = System::Drawing::Size(166, 27);
			this->txtBxLength->TabIndex = 6;
			this->txtBxLength->Text = L"1";
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 5;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				75)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->Controls->Add(this->txtBxGamma, 4, 2);
			this->tableLayoutPanel5->Controls->Add(this->lblLx, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->lblLy, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->txtBxBeta, 4, 1);
			this->tableLayoutPanel5->Controls->Add(this->lblLz, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->txtBxAlpha, 4, 0);
			this->tableLayoutPanel5->Controls->Add(this->lblAlpha, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->lblBeta, 3, 1);
			this->tableLayoutPanel5->Controls->Add(this->txtBxLz, 1, 2);
			this->tableLayoutPanel5->Controls->Add(this->lblGamma, 3, 2);
			this->tableLayoutPanel5->Controls->Add(this->txtBxLy, 1, 1);
			this->tableLayoutPanel5->Controls->Add(this->txtBxLx, 1, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 48);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 4;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 34)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(272, 102);
			this->tableLayoutPanel5->TabIndex = 1;
			// 
			// txtBxGamma
			// 
			this->txtBxGamma->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxGamma->Location = System::Drawing::Point(211, 71);
			this->txtBxGamma->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->txtBxGamma->Name = L"txtBxGamma";
			this->txtBxGamma->Size = System::Drawing::Size(58, 27);
			this->txtBxGamma->TabIndex = 22;
			this->txtBxGamma->Text = L"1";
			// 
			// lblLx
			// 
			this->lblLx->AutoSize = true;
			this->lblLx->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblLx->Location = System::Drawing::Point(3, 0);
			this->lblLx->Name = L"lblLx";
			this->lblLx->Size = System::Drawing::Size(63, 34);
			this->lblLx->TabIndex = 7;
			this->lblLx->Text = L"Lx [mm]";
			this->lblLx->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lblLy
			// 
			this->lblLy->AutoSize = true;
			this->lblLy->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblLy->Location = System::Drawing::Point(3, 34);
			this->lblLy->Name = L"lblLy";
			this->lblLy->Size = System::Drawing::Size(62, 32);
			this->lblLy->TabIndex = 9;
			this->lblLy->Text = L"Ly [mm]";
			this->lblLy->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBxBeta
			// 
			this->txtBxBeta->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxBeta->Location = System::Drawing::Point(211, 39);
			this->txtBxBeta->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->txtBxBeta->Name = L"txtBxBeta";
			this->txtBxBeta->Size = System::Drawing::Size(58, 27);
			this->txtBxBeta->TabIndex = 21;
			this->txtBxBeta->Text = L"1";
			// 
			// lblLz
			// 
			this->lblLz->AutoSize = true;
			this->lblLz->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblLz->Location = System::Drawing::Point(3, 66);
			this->lblLz->Name = L"lblLz";
			this->lblLz->Size = System::Drawing::Size(63, 33);
			this->lblLz->TabIndex = 11;
			this->lblLz->Text = L"Lz [mm]";
			this->lblLz->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBxAlpha
			// 
			this->txtBxAlpha->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxAlpha->Location = System::Drawing::Point(211, 5);
			this->txtBxAlpha->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->txtBxAlpha->Name = L"txtBxAlpha";
			this->txtBxAlpha->Size = System::Drawing::Size(58, 27);
			this->txtBxAlpha->TabIndex = 20;
			this->txtBxAlpha->Text = L"1";
			// 
			// lblAlpha
			// 
			this->lblAlpha->AutoSize = true;
			this->lblAlpha->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblAlpha->Location = System::Drawing::Point(161, 0);
			this->lblAlpha->Name = L"lblAlpha";
			this->lblAlpha->Size = System::Drawing::Size(38, 34);
			this->lblAlpha->TabIndex = 13;
			this->lblAlpha->Text = L"α [°]";
			this->lblAlpha->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblBeta
			// 
			this->lblBeta->AutoSize = true;
			this->lblBeta->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblBeta->Location = System::Drawing::Point(161, 34);
			this->lblBeta->Name = L"lblBeta";
			this->lblBeta->Size = System::Drawing::Size(37, 32);
			this->lblBeta->TabIndex = 15;
			this->lblBeta->Text = L"β [°]";
			this->lblBeta->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBxLz
			// 
			this->txtBxLz->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxLz->Location = System::Drawing::Point(78, 71);
			this->txtBxLz->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->txtBxLz->Name = L"txtBxLz";
			this->txtBxLz->Size = System::Drawing::Size(57, 27);
			this->txtBxLz->TabIndex = 19;
			this->txtBxLz->Text = L"1";
			// 
			// lblGamma
			// 
			this->lblGamma->AutoSize = true;
			this->lblGamma->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblGamma->Location = System::Drawing::Point(161, 66);
			this->lblGamma->Name = L"lblGamma";
			this->lblGamma->Size = System::Drawing::Size(37, 33);
			this->lblGamma->TabIndex = 17;
			this->lblGamma->Text = L"γ [°]";
			this->lblGamma->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtBxLy
			// 
			this->txtBxLy->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxLy->Location = System::Drawing::Point(78, 39);
			this->txtBxLy->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->txtBxLy->Name = L"txtBxLy";
			this->txtBxLy->Size = System::Drawing::Size(57, 27);
			this->txtBxLy->TabIndex = 18;
			this->txtBxLy->Text = L"1";
			// 
			// txtBxLx
			// 
			this->txtBxLx->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxLx->Location = System::Drawing::Point(78, 5);
			this->txtBxLx->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->txtBxLx->Name = L"txtBxLx";
			this->txtBxLx->Size = System::Drawing::Size(57, 27);
			this->txtBxLx->TabIndex = 8;
			this->txtBxLx->Text = L"1";
			// 
			// PipeElementCtrl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->grpBxPipeElem);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"PipeElementCtrl";
			this->Size = System::Drawing::Size(284, 184);
			this->grpBxPipeElem->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
