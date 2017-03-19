#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace DemoSFLpro {

	/// <summary>
	/// Summary for PipelineControl
	/// </summary>
	public ref class PipelineControl : public System::Windows::Forms::UserControl
	{
	public:
		PipelineControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PipelineControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  lblPipelineID;
	private: System::Windows::Forms::TextBox^  txtBxPipelineID;
	protected:


	private: System::Windows::Forms::Label^  lblPipelineSystem;


	private: System::Windows::Forms::Label^  lblPipelineOwner;
	private: System::Windows::Forms::TextBox^  txtBxPipelineOwner;


	private: System::Windows::Forms::Label^  lblPipelineName;
	private: System::Windows::Forms::TextBox^  txtBxPipelineName;
	private: System::Windows::Forms::ComboBox^  cmbBxPipelineSystem;
	private: System::Windows::Forms::Label^  lblEndLocation;
	private: System::Windows::Forms::TextBox^  txtBxStartChainage;
	private: System::Windows::Forms::Label^  lblStartChainage;
	private: System::Windows::Forms::TextBox^  txtBxStartLocation;
	private: System::Windows::Forms::Label^  lblStartLocation;
	private: System::Windows::Forms::TextBox^  txtBxEndLocation;
	private: System::Windows::Forms::TextBox^  xtBxEndChainage;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblNearestPostcode;
	private: System::Windows::Forms::TextBox^  txtBxNearestPostcode;

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
			this->lblEndLocation = (gcnew System::Windows::Forms::Label());
			this->txtBxStartChainage = (gcnew System::Windows::Forms::TextBox());
			this->lblStartChainage = (gcnew System::Windows::Forms::Label());
			this->txtBxStartLocation = (gcnew System::Windows::Forms::TextBox());
			this->lblPipelineID = (gcnew System::Windows::Forms::Label());
			this->txtBxPipelineID = (gcnew System::Windows::Forms::TextBox());
			this->lblPipelineSystem = (gcnew System::Windows::Forms::Label());
			this->lblPipelineOwner = (gcnew System::Windows::Forms::Label());
			this->txtBxPipelineOwner = (gcnew System::Windows::Forms::TextBox());
			this->lblPipelineName = (gcnew System::Windows::Forms::Label());
			this->txtBxPipelineName = (gcnew System::Windows::Forms::TextBox());
			this->cmbBxPipelineSystem = (gcnew System::Windows::Forms::ComboBox());
			this->lblStartLocation = (gcnew System::Windows::Forms::Label());
			this->txtBxEndLocation = (gcnew System::Windows::Forms::TextBox());
			this->xtBxEndChainage = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblNearestPostcode = (gcnew System::Windows::Forms::Label());
			this->txtBxNearestPostcode = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->lblEndLocation, 0, 12);
			this->tableLayoutPanel1->Controls->Add(this->txtBxStartChainage, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->lblStartChainage, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->txtBxStartLocation, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->lblPipelineID, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->txtBxPipelineID, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->lblPipelineSystem, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->lblPipelineOwner, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->txtBxPipelineOwner, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->lblPipelineName, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->txtBxPipelineName, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->cmbBxPipelineSystem, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->lblStartLocation, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->txtBxEndLocation, 0, 13);
			this->tableLayoutPanel1->Controls->Add(this->xtBxEndChainage, 0, 15);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 14);
			this->tableLayoutPanel1->Controls->Add(this->lblNearestPostcode, 0, 16);
			this->tableLayoutPanel1->Controls->Add(this->txtBxNearestPostcode, 0, 17);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Padding = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->tableLayoutPanel1->RowCount = 19;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 34)));
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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(522, 609);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// lblEndLocation
			// 
			this->lblEndLocation->AutoSize = true;
			this->lblEndLocation->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblEndLocation->Location = System::Drawing::Point(6, 397);
			this->lblEndLocation->Name = L"lblEndLocation";
			this->lblEndLocation->Size = System::Drawing::Size(95, 33);
			this->lblEndLocation->TabIndex = 13;
			this->lblEndLocation->Text = L"End Location";
			this->lblEndLocation->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxStartChainage
			// 
			this->txtBxStartChainage->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxStartChainage->Location = System::Drawing::Point(6, 368);
			this->txtBxStartChainage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxStartChainage->Name = L"txtBxStartChainage";
			this->txtBxStartChainage->Size = System::Drawing::Size(510, 27);
			this->txtBxStartChainage->TabIndex = 12;
			// 
			// lblStartChainage
			// 
			this->lblStartChainage->AutoSize = true;
			this->lblStartChainage->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblStartChainage->Location = System::Drawing::Point(6, 331);
			this->lblStartChainage->Name = L"lblStartChainage";
			this->lblStartChainage->Size = System::Drawing::Size(106, 33);
			this->lblStartChainage->TabIndex = 11;
			this->lblStartChainage->Text = L"Start Chainage";
			this->lblStartChainage->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxStartLocation
			// 
			this->txtBxStartLocation->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxStartLocation->Location = System::Drawing::Point(6, 302);
			this->txtBxStartLocation->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxStartLocation->Name = L"txtBxStartLocation";
			this->txtBxStartLocation->Size = System::Drawing::Size(510, 27);
			this->txtBxStartLocation->TabIndex = 10;
			// 
			// lblPipelineID
			// 
			this->lblPipelineID->AutoSize = true;
			this->lblPipelineID->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblPipelineID->Location = System::Drawing::Point(6, 199);
			this->lblPipelineID->Name = L"lblPipelineID";
			this->lblPipelineID->Size = System::Drawing::Size(81, 33);
			this->lblPipelineID->TabIndex = 6;
			this->lblPipelineID->Text = L"Pipeline ID";
			this->lblPipelineID->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxPipelineID
			// 
			this->txtBxPipelineID->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxPipelineID->Location = System::Drawing::Point(6, 236);
			this->txtBxPipelineID->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxPipelineID->Name = L"txtBxPipelineID";
			this->txtBxPipelineID->Size = System::Drawing::Size(510, 27);
			this->txtBxPipelineID->TabIndex = 7;
			// 
			// lblPipelineSystem
			// 
			this->lblPipelineSystem->AutoSize = true;
			this->lblPipelineSystem->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblPipelineSystem->Location = System::Drawing::Point(6, 132);
			this->lblPipelineSystem->Name = L"lblPipelineSystem";
			this->lblPipelineSystem->Size = System::Drawing::Size(113, 33);
			this->lblPipelineSystem->TabIndex = 4;
			this->lblPipelineSystem->Text = L"Pipeline System";
			this->lblPipelineSystem->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// lblPipelineOwner
			// 
			this->lblPipelineOwner->AutoSize = true;
			this->lblPipelineOwner->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblPipelineOwner->Location = System::Drawing::Point(6, 66);
			this->lblPipelineOwner->Name = L"lblPipelineOwner";
			this->lblPipelineOwner->Size = System::Drawing::Size(109, 33);
			this->lblPipelineOwner->TabIndex = 2;
			this->lblPipelineOwner->Text = L"Pipeline Owner";
			this->lblPipelineOwner->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxPipelineOwner
			// 
			this->txtBxPipelineOwner->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxPipelineOwner->Location = System::Drawing::Point(6, 103);
			this->txtBxPipelineOwner->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxPipelineOwner->Name = L"txtBxPipelineOwner";
			this->txtBxPipelineOwner->Size = System::Drawing::Size(510, 27);
			this->txtBxPipelineOwner->TabIndex = 3;
			// 
			// lblPipelineName
			// 
			this->lblPipelineName->AutoSize = true;
			this->lblPipelineName->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblPipelineName->Location = System::Drawing::Point(6, 0);
			this->lblPipelineName->Name = L"lblPipelineName";
			this->lblPipelineName->Size = System::Drawing::Size(106, 33);
			this->lblPipelineName->TabIndex = 0;
			this->lblPipelineName->Text = L"Pipeline Name";
			this->lblPipelineName->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxPipelineName
			// 
			this->txtBxPipelineName->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxPipelineName->Location = System::Drawing::Point(6, 37);
			this->txtBxPipelineName->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxPipelineName->Name = L"txtBxPipelineName";
			this->txtBxPipelineName->Size = System::Drawing::Size(510, 27);
			this->txtBxPipelineName->TabIndex = 1;
			// 
			// cmbBxPipelineSystem
			// 
			this->cmbBxPipelineSystem->BackColor = System::Drawing::SystemColors::Window;
			this->cmbBxPipelineSystem->Dock = System::Windows::Forms::DockStyle::Top;
			this->cmbBxPipelineSystem->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBxPipelineSystem->FormattingEnabled = true;
			this->cmbBxPipelineSystem->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"High Pressure", L"Intermediate Pressure",
					L"Medium Pressure", L"Low Pressure"
			});
			this->cmbBxPipelineSystem->Location = System::Drawing::Point(6, 168);
			this->cmbBxPipelineSystem->Name = L"cmbBxPipelineSystem";
			this->cmbBxPipelineSystem->Size = System::Drawing::Size(510, 28);
			this->cmbBxPipelineSystem->TabIndex = 8;
			// 
			// lblStartLocation
			// 
			this->lblStartLocation->AutoSize = true;
			this->lblStartLocation->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblStartLocation->Location = System::Drawing::Point(6, 265);
			this->lblStartLocation->Name = L"lblStartLocation";
			this->lblStartLocation->Size = System::Drawing::Size(101, 33);
			this->lblStartLocation->TabIndex = 9;
			this->lblStartLocation->Text = L"Start Location";
			this->lblStartLocation->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxEndLocation
			// 
			this->txtBxEndLocation->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxEndLocation->Location = System::Drawing::Point(6, 434);
			this->txtBxEndLocation->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxEndLocation->Name = L"txtBxEndLocation";
			this->txtBxEndLocation->Size = System::Drawing::Size(510, 27);
			this->txtBxEndLocation->TabIndex = 14;
			// 
			// xtBxEndChainage
			// 
			this->xtBxEndChainage->Dock = System::Windows::Forms::DockStyle::Top;
			this->xtBxEndChainage->Location = System::Drawing::Point(6, 500);
			this->xtBxEndChainage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->xtBxEndChainage->Name = L"xtBxEndChainage";
			this->xtBxEndChainage->Size = System::Drawing::Size(510, 27);
			this->xtBxEndChainage->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Left;
			this->label1->Location = System::Drawing::Point(6, 463);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 33);
			this->label1->TabIndex = 16;
			this->label1->Text = L"End Chainage";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// lblNearestPostcode
			// 
			this->lblNearestPostcode->AutoSize = true;
			this->lblNearestPostcode->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblNearestPostcode->Location = System::Drawing::Point(6, 529);
			this->lblNearestPostcode->Name = L"lblNearestPostcode";
			this->lblNearestPostcode->Size = System::Drawing::Size(124, 33);
			this->lblNearestPostcode->TabIndex = 17;
			this->lblNearestPostcode->Text = L"Nearest Postcode";
			this->lblNearestPostcode->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxNearestPostcode
			// 
			this->txtBxNearestPostcode->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxNearestPostcode->Location = System::Drawing::Point(6, 566);
			this->txtBxNearestPostcode->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBxNearestPostcode->Name = L"txtBxNearestPostcode";
			this->txtBxNearestPostcode->Size = System::Drawing::Size(510, 27);
			this->txtBxNearestPostcode->TabIndex = 18;
			// 
			// PipelineControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"PipelineControl";
			this->Size = System::Drawing::Size(522, 704);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
