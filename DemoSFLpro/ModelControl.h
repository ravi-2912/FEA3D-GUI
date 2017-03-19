#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace DemoSFLpro {

	/// <summary>
	/// Summary for ModelControl
	/// </summary>
	public ref class ModelControl : public System::Windows::Forms::UserControl
	{
	public:
		ModelControl(void)
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
		~ModelControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Label^  lblProjectDescription;
	private: System::Windows::Forms::TextBox^  txtBxProjectDescription;
	private: System::Windows::Forms::Label^  lblProjectLead;
	private: System::Windows::Forms::TextBox^  tctBxProjectLead;
	private: System::Windows::Forms::Label^  lblProjectName;
	private: System::Windows::Forms::TextBox^  txtBxProjectName;
	private: System::Windows::Forms::Label^  lblModelName;
	private: System::Windows::Forms::TextBox^  txtBxModelName;

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
			this->lblProjectDescription = (gcnew System::Windows::Forms::Label());
			this->txtBxProjectDescription = (gcnew System::Windows::Forms::TextBox());
			this->lblProjectLead = (gcnew System::Windows::Forms::Label());
			this->tctBxProjectLead = (gcnew System::Windows::Forms::TextBox());
			this->lblProjectName = (gcnew System::Windows::Forms::Label());
			this->txtBxProjectName = (gcnew System::Windows::Forms::TextBox());
			this->lblModelName = (gcnew System::Windows::Forms::Label());
			this->txtBxModelName = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->lblProjectDescription, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->txtBxProjectDescription, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->lblProjectLead, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->tctBxProjectLead, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->lblProjectName, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->txtBxProjectName, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->lblModelName, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->txtBxModelName, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Padding = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->tableLayoutPanel1->RowCount = 10;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 150)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(448, 421);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// lblProjectDescription
			// 
			this->lblProjectDescription->AutoSize = true;
			this->lblProjectDescription->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblProjectDescription->Location = System::Drawing::Point(6, 198);
			this->lblProjectDescription->Name = L"lblProjectDescription";
			this->lblProjectDescription->Size = System::Drawing::Size(135, 33);
			this->lblProjectDescription->TabIndex = 6;
			this->lblProjectDescription->Text = L"Project Description";
			this->lblProjectDescription->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxProjectDescription
			// 
			this->txtBxProjectDescription->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtBxProjectDescription->Location = System::Drawing::Point(6, 234);
			this->txtBxProjectDescription->Multiline = true;
			this->txtBxProjectDescription->Name = L"txtBxProjectDescription";
			this->txtBxProjectDescription->Size = System::Drawing::Size(436, 144);
			this->txtBxProjectDescription->TabIndex = 7;
			// 
			// lblProjectLead
			// 
			this->lblProjectLead->AutoSize = true;
			this->lblProjectLead->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblProjectLead->Location = System::Drawing::Point(6, 132);
			this->lblProjectLead->Name = L"lblProjectLead";
			this->lblProjectLead->Size = System::Drawing::Size(91, 33);
			this->lblProjectLead->TabIndex = 4;
			this->lblProjectLead->Text = L"Project Lead";
			this->lblProjectLead->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// tctBxProjectLead
			// 
			this->tctBxProjectLead->Dock = System::Windows::Forms::DockStyle::Top;
			this->tctBxProjectLead->Location = System::Drawing::Point(6, 168);
			this->tctBxProjectLead->Name = L"tctBxProjectLead";
			this->tctBxProjectLead->Size = System::Drawing::Size(436, 27);
			this->tctBxProjectLead->TabIndex = 5;
			// 
			// lblProjectName
			// 
			this->lblProjectName->AutoSize = true;
			this->lblProjectName->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblProjectName->Location = System::Drawing::Point(6, 66);
			this->lblProjectName->Name = L"lblProjectName";
			this->lblProjectName->Size = System::Drawing::Size(99, 33);
			this->lblProjectName->TabIndex = 2;
			this->lblProjectName->Text = L"Project Name";
			this->lblProjectName->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxProjectName
			// 
			this->txtBxProjectName->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxProjectName->Location = System::Drawing::Point(6, 102);
			this->txtBxProjectName->Name = L"txtBxProjectName";
			this->txtBxProjectName->Size = System::Drawing::Size(436, 27);
			this->txtBxProjectName->TabIndex = 3;
			// 
			// lblModelName
			// 
			this->lblModelName->AutoSize = true;
			this->lblModelName->Dock = System::Windows::Forms::DockStyle::Left;
			this->lblModelName->Location = System::Drawing::Point(6, 0);
			this->lblModelName->Name = L"lblModelName";
			this->lblModelName->Size = System::Drawing::Size(96, 33);
			this->lblModelName->TabIndex = 0;
			this->lblModelName->Text = L"Model Name";
			this->lblModelName->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// txtBxModelName
			// 
			this->txtBxModelName->Dock = System::Windows::Forms::DockStyle::Top;
			this->txtBxModelName->Location = System::Drawing::Point(6, 36);
			this->txtBxModelName->Name = L"txtBxModelName";
			this->txtBxModelName->Size = System::Drawing::Size(436, 27);
			this->txtBxModelName->TabIndex = 1;
			// 
			// ModelControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->tableLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"ModelControl";
			this->Size = System::Drawing::Size(448, 694);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
