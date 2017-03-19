#pragma once

#include "ModelControl.h"
#include "PipelineControl.h"
#include "PipelineMaterialControl.h"
#include "PipelineMaterial.h"
#include "PipelineGeometryControl.h"
#include "Element.h"
#include "OgreApp.h"

namespace DemoSFLpro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	private: ModelControl^ mMdlCtrl;
	private: PipelineControl^ mPipeCtrl;

	private: PipelineMaterialControl^ mPipeMatCtrl;
	private: Dictionary<String^, PipelineMaterial^>^ mModPipMatDb;

	private: PipelineGeometryControl^ mPipeGeomCtrl;


	private: Dictionary<unsigned int, Element^>^ mModPipElemDb;
	private: static unsigned int ELEM_COUNT = 0;
	private: System::Windows::Forms::Button^  button1;

	private: static bool geomTreeChildIndexing = false;
	private: System::Windows::Forms::Panel^  panel1;

	private: OgreApp* m_OA;
	private: bool m_OA_init = false;

	//private: PipelineMaterial^ m;

	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->treVwModelTree->ExpandAll();
			

			this->mMdlCtrl = gcnew ModelControl();
			this->tbPgModelDynamic->Controls->Add(this->mMdlCtrl);
			this->mMdlCtrl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mMdlCtrl->Location = System::Drawing::Point(0, 0);
			this->mMdlCtrl->Name = L"uiCtrlModel";
			this->mMdlCtrl->Enabled = false;
			this->mMdlCtrl->Hide();

			this->mPipeCtrl = gcnew PipelineControl();
			this->tbPgModelDynamic->Controls->Add(this->mPipeCtrl);
			this->mPipeCtrl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mPipeCtrl->Location = System::Drawing::Point(0, 0);
			this->mPipeCtrl->Name = L"uiCtrlPipeline";
			this->mPipeCtrl->Enabled = false;
			this->mPipeCtrl->Hide();

			this->mPipeMatCtrl = gcnew PipelineMaterialControl();
			this->tbPgModelDynamic->Controls->Add(this->mPipeMatCtrl);
			this->mPipeMatCtrl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mPipeMatCtrl->Location = System::Drawing::Point(0, 0);
			this->mPipeMatCtrl->Name = L"uiCtrlPipelineMaterials";
			this->mPipeMatCtrl->Enabled = false;
			this->mPipeMatCtrl->Hide();
			this->mPipeMatCtrl->AddUpdateBtnClk += gcnew System::EventHandler(this, &MainWindow::mPipeMatCtrl_AddUpdateBtnClk);
			this->mPipeMatCtrl->RemoveCancelBtnClk += gcnew System::EventHandler(this, &MainWindow::mPipeMatCtrl_RemoveCancelBtnClk);
			this->mPipeMatCtrl->CancelResetBtnClk += gcnew System::EventHandler(this, &MainWindow::mPipeMatCtrl_CancelResetBtnClk);
			this->mModPipMatDb = gcnew Dictionary<String^, PipelineMaterial^>();

			this->mPipeGeomCtrl = gcnew PipelineGeometryControl();
			this->tbPgModelDynamic->Controls->Add(this->mPipeGeomCtrl);
			this->mPipeGeomCtrl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mPipeGeomCtrl->Location = System::Drawing::Point(0, 0);
			this->mPipeGeomCtrl->Name = L"uiCtrlPipelineGeometry";
			this->mPipeGeomCtrl->Enabled = false;
			this->mPipeGeomCtrl->Hide();
			this->mPipeGeomCtrl->MaterialDropDownCmbBx += gcnew System::EventHandler(this, &DemoSFLpro::MainWindow::mPipeGeomCtrl_OnMatDrpDnnCmbBx);
			this->mPipeGeomCtrl->AddUpdateBtnClk += gcnew System::EventHandler(this, &DemoSFLpro::MainWindow::mPipeGeomCtrl_AddUpdateBtnClk);
			this->mPipeGeomCtrl->CancelRemoveBtnClk += gcnew System::EventHandler(this, &DemoSFLpro::MainWindow::mPipeGeomCtrl_CancelRemoveBtnClk);
			this->mPipeGeomCtrl->CancelResetBtnClk += gcnew System::EventHandler(this, &DemoSFLpro::MainWindow::mPipeGeomCtrl_CancelResetBtnClk);
			this->mModPipElemDb = gcnew Dictionary<unsigned int, Element^>();
			this->mPipeGeomCtrl->UpdateIDtxtBx(ELEM_COUNT + 1);

			//this->mPipeGeomCtrl->AddUpdateButtonClick += gcnew System::EventHandler(this, &MainWindow::mPipeMatCtrl_AddUpdateButtonClick);

			m_OA = new OgreApp(this->panel1);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripContainer^  toolStripContainer1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::SplitContainer^  splitContainer3;
	private: System::Windows::Forms::TabControl^  tbCtrModelVisualAccessTree;
	private: System::Windows::Forms::TabPage^  tbPgModelTree;
	private: System::Windows::Forms::TabPage^  tbPgVisualization;
	private: System::Windows::Forms::TabControl^  tbCtrlDynamicInput;
	private: System::Windows::Forms::TabPage^  tbPgModelDynamic;
	private: System::Windows::Forms::TabPage^  tbPgElementDynamic;
	private: System::Windows::Forms::TabControl^  tbCtrlGraphics;
	private: System::Windows::Forms::TabPage^  tbPg3DGraphics;
	private: System::Windows::Forms::TabPage^  tbPg2DGraphics1;
	private: System::Windows::Forms::TabControl^  tbCtrlSystemConsole;
	private: System::Windows::Forms::TabPage^  tbPgSolver;
	private: System::Windows::Forms::TabPage^  tbPgGraphics;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  newToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  openToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  saveToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  printToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripButton^  cutToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  copyToolStripButton;
	private: System::Windows::Forms::ToolStripButton^  pasteToolStripButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  helpToolStripButton;
	private: System::Windows::Forms::ToolStripMenuItem^  newModelToolStripMenuItem;
	private: System::Windows::Forms::TabPage^  tbPgOutput;
	private: System::Windows::Forms::TreeView^  treVwModelTree;

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
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"Materials"));
			System::Windows::Forms::TreeNode^  treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"Geometry"));
			System::Windows::Forms::TreeNode^  treeNode3 = (gcnew System::Windows::Forms::TreeNode(L"Loads"));
			System::Windows::Forms::TreeNode^  treeNode4 = (gcnew System::Windows::Forms::TreeNode(L"Constraints"));
			System::Windows::Forms::TreeNode^  treeNode5 = (gcnew System::Windows::Forms::TreeNode(L"Pipeline", gcnew cli::array< System::Windows::Forms::TreeNode^  >(4) {
				treeNode1,
					treeNode2, treeNode3, treeNode4
			}));
			System::Windows::Forms::TreeNode^  treeNode6 = (gcnew System::Windows::Forms::TreeNode(L"Ground"));
			System::Windows::Forms::TreeNode^  treeNode7 = (gcnew System::Windows::Forms::TreeNode(L"Mesh"));
			System::Windows::Forms::TreeNode^  treeNode8 = (gcnew System::Windows::Forms::TreeNode(L"Solver/Solution"));
			System::Windows::Forms::TreeNode^  treeNode9 = (gcnew System::Windows::Forms::TreeNode(L"Job/Cases/etc"));
			System::Windows::Forms::TreeNode^  treeNode10 = (gcnew System::Windows::Forms::TreeNode(L"Model", gcnew cli::array< System::Windows::Forms::TreeNode^  >(5) {
				treeNode5,
					treeNode6, treeNode7, treeNode8, treeNode9
			}));
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newModelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->tbCtrModelVisualAccessTree = (gcnew System::Windows::Forms::TabControl());
			this->tbPgModelTree = (gcnew System::Windows::Forms::TabPage());
			this->treVwModelTree = (gcnew System::Windows::Forms::TreeView());
			this->tbPgVisualization = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->tbCtrlDynamicInput = (gcnew System::Windows::Forms::TabControl());
			this->tbPgModelDynamic = (gcnew System::Windows::Forms::TabPage());
			this->tbPgElementDynamic = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->tbCtrlGraphics = (gcnew System::Windows::Forms::TabControl());
			this->tbPg3DGraphics = (gcnew System::Windows::Forms::TabPage());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tbPg2DGraphics1 = (gcnew System::Windows::Forms::TabPage());
			this->tbCtrlSystemConsole = (gcnew System::Windows::Forms::TabControl());
			this->tbPgSolver = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tbPgGraphics = (gcnew System::Windows::Forms::TabPage());
			this->tbPgOutput = (gcnew System::Windows::Forms::TabPage());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->newToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->openToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->saveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->printToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->cutToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->copyToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->pasteToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->helpToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1->SuspendLayout();
			this->toolStripContainer1->ContentPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tbCtrModelVisualAccessTree->SuspendLayout();
			this->tbPgModelTree->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->tbCtrlDynamicInput->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->tbCtrlGraphics->SuspendLayout();
			this->tbPg3DGraphics->SuspendLayout();
			this->tbCtrlSystemConsole->SuspendLayout();
			this->tbPgSolver->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->viewToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1425, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->newModelToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// newModelToolStripMenuItem
			// 
			this->newModelToolStripMenuItem->Name = L"newModelToolStripMenuItem";
			this->newModelToolStripMenuItem->Size = System::Drawing::Size(161, 26);
			this->newModelToolStripMenuItem->Text = L"New Model";
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(47, 24);
			this->editToolStripMenuItem->Text = L"&Edit";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(53, 24);
			this->viewToolStripMenuItem->Text = L"&View";
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Location = System::Drawing::Point(0, 607);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1425, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripContainer1
			// 
			this->toolStripContainer1->BottomToolStripPanelVisible = false;
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Controls->Add(this->splitContainer1);
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(1425, 552);
			this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer1->LeftToolStripPanelVisible = false;
			this->toolStripContainer1->Location = System::Drawing::Point(0, 28);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->RightToolStripPanelVisible = false;
			this->toolStripContainer1->Size = System::Drawing::Size(1425, 579);
			this->toolStripContainer1->TabIndex = 2;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStrip1);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->tbCtrModelVisualAccessTree);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(1425, 552);
			this->splitContainer1->SplitterDistance = 134;
			this->splitContainer1->TabIndex = 0;
			// 
			// tbCtrModelVisualAccessTree
			// 
			this->tbCtrModelVisualAccessTree->Controls->Add(this->tbPgModelTree);
			this->tbCtrModelVisualAccessTree->Controls->Add(this->tbPgVisualization);
			this->tbCtrModelVisualAccessTree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbCtrModelVisualAccessTree->Location = System::Drawing::Point(0, 0);
			this->tbCtrModelVisualAccessTree->Name = L"tbCtrModelVisualAccessTree";
			this->tbCtrModelVisualAccessTree->SelectedIndex = 0;
			this->tbCtrModelVisualAccessTree->Size = System::Drawing::Size(134, 552);
			this->tbCtrModelVisualAccessTree->TabIndex = 0;
			// 
			// tbPgModelTree
			// 
			this->tbPgModelTree->Controls->Add(this->treVwModelTree);
			this->tbPgModelTree->Location = System::Drawing::Point(4, 29);
			this->tbPgModelTree->Name = L"tbPgModelTree";
			this->tbPgModelTree->Padding = System::Windows::Forms::Padding(3);
			this->tbPgModelTree->Size = System::Drawing::Size(126, 519);
			this->tbPgModelTree->TabIndex = 0;
			this->tbPgModelTree->Text = L"Model";
			this->tbPgModelTree->UseVisualStyleBackColor = true;
			// 
			// treVwModelTree
			// 
			this->treVwModelTree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treVwModelTree->Location = System::Drawing::Point(3, 3);
			this->treVwModelTree->Name = L"treVwModelTree";
			treeNode1->Name = L"nodeMaterials";
			treeNode1->Text = L"Materials";
			treeNode2->Name = L"nodeGeometry";
			treeNode2->Text = L"Geometry";
			treeNode3->Name = L"nodeLoads";
			treeNode3->Text = L"Loads";
			treeNode4->Name = L"nodeConstraints";
			treeNode4->Text = L"Constraints";
			treeNode5->Name = L"nodePipeline";
			treeNode5->Text = L"Pipeline";
			treeNode6->Name = L"nodeGround";
			treeNode6->Text = L"Ground";
			treeNode7->Name = L"nodeMesh";
			treeNode7->Text = L"Mesh";
			treeNode8->Name = L"nodeSolver";
			treeNode8->Text = L"Solver/Solution";
			treeNode9->Name = L"nodeJob";
			treeNode9->Text = L"Job/Cases/etc";
			treeNode10->Name = L"nodeModel";
			treeNode10->Text = L"Model";
			this->treVwModelTree->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode10 });
			this->treVwModelTree->Size = System::Drawing::Size(120, 513);
			this->treVwModelTree->TabIndex = 0;
			this->treVwModelTree->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainWindow::treeViewModelTree_AfterSelect);
			// 
			// tbPgVisualization
			// 
			this->tbPgVisualization->Location = System::Drawing::Point(4, 29);
			this->tbPgVisualization->Name = L"tbPgVisualization";
			this->tbPgVisualization->Padding = System::Windows::Forms::Padding(3);
			this->tbPgVisualization->Size = System::Drawing::Size(126, 519);
			this->tbPgVisualization->TabIndex = 1;
			this->tbPgVisualization->Text = L"Visualization";
			this->tbPgVisualization->UseVisualStyleBackColor = true;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->tbCtrlDynamicInput);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer2->Size = System::Drawing::Size(1287, 552);
			this->splitContainer2->SplitterDistance = 384;
			this->splitContainer2->TabIndex = 0;
			// 
			// tbCtrlDynamicInput
			// 
			this->tbCtrlDynamicInput->Controls->Add(this->tbPgModelDynamic);
			this->tbCtrlDynamicInput->Controls->Add(this->tbPgElementDynamic);
			this->tbCtrlDynamicInput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbCtrlDynamicInput->Location = System::Drawing::Point(0, 0);
			this->tbCtrlDynamicInput->Name = L"tbCtrlDynamicInput";
			this->tbCtrlDynamicInput->SelectedIndex = 0;
			this->tbCtrlDynamicInput->Size = System::Drawing::Size(384, 552);
			this->tbCtrlDynamicInput->TabIndex = 0;
			// 
			// tbPgModelDynamic
			// 
			this->tbPgModelDynamic->AutoScroll = true;
			this->tbPgModelDynamic->Location = System::Drawing::Point(4, 29);
			this->tbPgModelDynamic->Name = L"tbPgModelDynamic";
			this->tbPgModelDynamic->Padding = System::Windows::Forms::Padding(3);
			this->tbPgModelDynamic->Size = System::Drawing::Size(376, 519);
			this->tbPgModelDynamic->TabIndex = 0;
			this->tbPgModelDynamic->Text = L"Model";
			this->tbPgModelDynamic->UseVisualStyleBackColor = true;
			// 
			// tbPgElementDynamic
			// 
			this->tbPgElementDynamic->Location = System::Drawing::Point(4, 29);
			this->tbPgElementDynamic->Name = L"tbPgElementDynamic";
			this->tbPgElementDynamic->Padding = System::Windows::Forms::Padding(3);
			this->tbPgElementDynamic->Size = System::Drawing::Size(376, 519);
			this->tbPgElementDynamic->TabIndex = 1;
			this->tbPgElementDynamic->Text = L"Element";
			this->tbPgElementDynamic->UseVisualStyleBackColor = true;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->tbCtrlGraphics);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->tbCtrlSystemConsole);
			this->splitContainer3->Size = System::Drawing::Size(899, 552);
			this->splitContainer3->SplitterDistance = 430;
			this->splitContainer3->TabIndex = 0;
			// 
			// tbCtrlGraphics
			// 
			this->tbCtrlGraphics->Controls->Add(this->tbPg3DGraphics);
			this->tbCtrlGraphics->Controls->Add(this->tbPg2DGraphics1);
			this->tbCtrlGraphics->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbCtrlGraphics->Location = System::Drawing::Point(0, 0);
			this->tbCtrlGraphics->Name = L"tbCtrlGraphics";
			this->tbCtrlGraphics->SelectedIndex = 0;
			this->tbCtrlGraphics->Size = System::Drawing::Size(899, 430);
			this->tbCtrlGraphics->TabIndex = 0;
			// 
			// tbPg3DGraphics
			// 
			this->tbPg3DGraphics->Controls->Add(this->panel1);
			this->tbPg3DGraphics->Location = System::Drawing::Point(4, 29);
			this->tbPg3DGraphics->Name = L"tbPg3DGraphics";
			this->tbPg3DGraphics->Padding = System::Windows::Forms::Padding(3);
			this->tbPg3DGraphics->Size = System::Drawing::Size(891, 397);
			this->tbPg3DGraphics->TabIndex = 0;
			this->tbPg3DGraphics->Text = L"3D Graphics";
			this->tbPg3DGraphics->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(885, 391);
			this->panel1->TabIndex = 0;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::panel1_MouseUp);
			this->panel1->Resize += gcnew System::EventHandler(this, &MainWindow::panel1_Resize);
			this->panel1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::panel1_MouseWheel);
			// 
			// tbPg2DGraphics1
			// 
			this->tbPg2DGraphics1->Location = System::Drawing::Point(4, 29);
			this->tbPg2DGraphics1->Name = L"tbPg2DGraphics1";
			this->tbPg2DGraphics1->Padding = System::Windows::Forms::Padding(3);
			this->tbPg2DGraphics1->Size = System::Drawing::Size(891, 397);
			this->tbPg2DGraphics1->TabIndex = 1;
			this->tbPg2DGraphics1->Text = L"2D Graphics 01";
			this->tbPg2DGraphics1->UseVisualStyleBackColor = true;
			// 
			// tbCtrlSystemConsole
			// 
			this->tbCtrlSystemConsole->Controls->Add(this->tbPgSolver);
			this->tbCtrlSystemConsole->Controls->Add(this->tbPgGraphics);
			this->tbCtrlSystemConsole->Controls->Add(this->tbPgOutput);
			this->tbCtrlSystemConsole->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbCtrlSystemConsole->Location = System::Drawing::Point(0, 0);
			this->tbCtrlSystemConsole->Name = L"tbCtrlSystemConsole";
			this->tbCtrlSystemConsole->SelectedIndex = 0;
			this->tbCtrlSystemConsole->Size = System::Drawing::Size(899, 118);
			this->tbCtrlSystemConsole->TabIndex = 0;
			// 
			// tbPgSolver
			// 
			this->tbPgSolver->Controls->Add(this->button1);
			this->tbPgSolver->Location = System::Drawing::Point(4, 29);
			this->tbPgSolver->Name = L"tbPgSolver";
			this->tbPgSolver->Padding = System::Windows::Forms::Padding(3);
			this->tbPgSolver->Size = System::Drawing::Size(891, 85);
			this->tbPgSolver->TabIndex = 0;
			this->tbPgSolver->Text = L"Solver";
			this->tbPgSolver->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(109, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// tbPgGraphics
			// 
			this->tbPgGraphics->Location = System::Drawing::Point(4, 29);
			this->tbPgGraphics->Name = L"tbPgGraphics";
			this->tbPgGraphics->Padding = System::Windows::Forms::Padding(3);
			this->tbPgGraphics->Size = System::Drawing::Size(891, 85);
			this->tbPgGraphics->TabIndex = 1;
			this->tbPgGraphics->Text = L"Graphics";
			this->tbPgGraphics->UseVisualStyleBackColor = true;
			// 
			// tbPgOutput
			// 
			this->tbPgOutput->Location = System::Drawing::Point(4, 29);
			this->tbPgOutput->Name = L"tbPgOutput";
			this->tbPgOutput->Padding = System::Windows::Forms::Padding(3);
			this->tbPgOutput->Size = System::Drawing::Size(891, 85);
			this->tbPgOutput->TabIndex = 2;
			this->tbPgOutput->Text = L"Output";
			this->tbPgOutput->UseVisualStyleBackColor = true;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip1->GripMargin = System::Windows::Forms::Padding(0);
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->newToolStripButton,
					this->openToolStripButton, this->saveToolStripButton, this->printToolStripButton, this->toolStripSeparator, this->cutToolStripButton,
					this->copyToolStripButton, this->pasteToolStripButton, this->toolStripSeparator1, this->helpToolStripButton
			});
			this->toolStrip1->Location = System::Drawing::Point(3, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Padding = System::Windows::Forms::Padding(0);
			this->toolStrip1->Size = System::Drawing::Size(211, 27);
			this->toolStrip1->TabIndex = 0;
			// 
			// newToolStripButton
			// 
			this->newToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->newToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"newToolStripButton.Image")));
			this->newToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->newToolStripButton->Name = L"newToolStripButton";
			this->newToolStripButton->Size = System::Drawing::Size(24, 24);
			this->newToolStripButton->Text = L"&New";
			// 
			// openToolStripButton
			// 
			this->openToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->openToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripButton.Image")));
			this->openToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->openToolStripButton->Name = L"openToolStripButton";
			this->openToolStripButton->Size = System::Drawing::Size(24, 24);
			this->openToolStripButton->Text = L"&Open";
			// 
			// saveToolStripButton
			// 
			this->saveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->saveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveToolStripButton.Image")));
			this->saveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->saveToolStripButton->Name = L"saveToolStripButton";
			this->saveToolStripButton->Size = System::Drawing::Size(24, 24);
			this->saveToolStripButton->Text = L"&Save";
			// 
			// printToolStripButton
			// 
			this->printToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->printToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"printToolStripButton.Image")));
			this->printToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->printToolStripButton->Name = L"printToolStripButton";
			this->printToolStripButton->Size = System::Drawing::Size(24, 24);
			this->printToolStripButton->Text = L"&Print";
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(6, 27);
			// 
			// cutToolStripButton
			// 
			this->cutToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->cutToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cutToolStripButton.Image")));
			this->cutToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->cutToolStripButton->Name = L"cutToolStripButton";
			this->cutToolStripButton->Size = System::Drawing::Size(24, 24);
			this->cutToolStripButton->Text = L"C&ut";
			// 
			// copyToolStripButton
			// 
			this->copyToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->copyToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"copyToolStripButton.Image")));
			this->copyToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->copyToolStripButton->Name = L"copyToolStripButton";
			this->copyToolStripButton->Size = System::Drawing::Size(24, 24);
			this->copyToolStripButton->Text = L"&Copy";
			// 
			// pasteToolStripButton
			// 
			this->pasteToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->pasteToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pasteToolStripButton.Image")));
			this->pasteToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->pasteToolStripButton->Name = L"pasteToolStripButton";
			this->pasteToolStripButton->Size = System::Drawing::Size(24, 24);
			this->pasteToolStripButton->Text = L"&Paste";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 27);
			// 
			// helpToolStripButton
			// 
			this->helpToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->helpToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"helpToolStripButton.Image")));
			this->helpToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->helpToolStripButton->Name = L"helpToolStripButton";
			this->helpToolStripButton->Size = System::Drawing::Size(24, 24);
			this->helpToolStripButton->Text = L"He&lp";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1425, 629);
			this->Controls->Add(this->toolStripContainer1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tbCtrModelVisualAccessTree->ResumeLayout(false);
			this->tbPgModelTree->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->tbCtrlDynamicInput->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->tbCtrlGraphics->ResumeLayout(false);
			this->tbPg3DGraphics->ResumeLayout(false);
			this->tbCtrlSystemConsole->ResumeLayout(false);
			this->tbPgSolver->ResumeLayout(false);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void treeViewModelTree_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
			if (!geomTreeChildIndexing)
			{
				this->tbPgModelDynamic->Text = this->treVwModelTree->SelectedNode->Text;
				// MODEL CONTROL
				if (this->tbPgModelDynamic->Text->Equals("Model"))
				{
					this->mMdlCtrl->Enabled = true;
					this->mMdlCtrl->Show();
				}
				else
				{
					this->mMdlCtrl->Enabled = false;
					this->mMdlCtrl->Hide();
				}

				// PIPELINE CONTROL
				if (this->tbPgModelDynamic->Text->Equals("Pipeline"))
				{
					this->mPipeCtrl->Enabled = true;
					this->mPipeCtrl->Show();
				}
				else
				{
					this->mPipeCtrl->Enabled = false;
					this->mPipeCtrl->Hide();
				}

				// MATERIAL CONTROL
				if (this->tbPgModelDynamic->Text->Equals("Materials"))
				{
					this->mPipeMatCtrl->Enabled = true;
					this->mPipeMatCtrl->Show();
					this->mPipeMatCtrl->UpdateControl(nullptr);
				}
				else if (this->treVwModelTree->SelectedNode->Parent != nullptr && this->treVwModelTree->SelectedNode->Parent->Text->Equals("Materials"))
				{
					if (!this->mPipeMatCtrl->Enabled)
					{
						this->mPipeMatCtrl->Enabled = true;
						this->mPipeMatCtrl->Show();
					}
					this->mPipeMatCtrl->UpdateControl(this->mModPipMatDb[this->treVwModelTree->SelectedNode->Text]);
				}
				else
				{
					this->mPipeMatCtrl->Enabled = false;
					this->mPipeMatCtrl->Hide();
				}

				// GEOMETRY CONTROL
				if (this->tbPgModelDynamic->Text->Equals("Geometry"))
				{
					this->mPipeGeomCtrl->Enabled = true;
					this->mPipeGeomCtrl->Show();
					this->mPipeGeomCtrl->UpdateControl(nullptr);
					this->mPipeGeomCtrl->UpdateIDtxtBx(ELEM_COUNT + 1);
				}
				else if (this->treVwModelTree->SelectedNode->Parent != nullptr && this->treVwModelTree->SelectedNode->Parent->Text->Equals("Geometry"))
				{
					if (!this->mPipeGeomCtrl->Enabled)
					{
						this->mPipeGeomCtrl->Enabled = true;
						this->mPipeGeomCtrl->Show();
					}
					array<String^>^ w;
					String^ delimStr = " ";
					array<Char>^ delimiter = delimStr->ToCharArray();
					w = this->treVwModelTree->SelectedNode->Text->Split(delimiter);
					this->mPipeGeomCtrl->UpdateControl(this->mModPipElemDb[int::Parse(w[0])]);
				}
				else
				{
					this->mPipeGeomCtrl->Enabled = false;
					this->mPipeGeomCtrl->Hide();
				}
			}
		}

		private: System::Void mPipeMatCtrl_AddUpdateBtnClk(System::Object^  sender, System::EventArgs^  e){
				if (this->treVwModelTree->SelectedNode->Text->Equals("Materials"))
				{
					PipelineMaterial^ mat = gcnew PipelineMaterial(this->mPipeMatCtrl->GetMaterial());
					this->treVwModelTree->SelectedNode->Nodes->Add(gcnew TreeNode(mat->MaterialName));
					this->mModPipMatDb->Add(mat->MaterialName, mat);
					this->mPipeMatCtrl->UpdateControl(nullptr);
				}
				else if (this->treVwModelTree->SelectedNode->Parent != nullptr && this->treVwModelTree->SelectedNode->Parent->Text->Equals("Materials"))
				{
					if (this->mPipeMatCtrl->GetMaterial()->MaterialName->Equals(this->treVwModelTree->SelectedNode->Text))
					{
						this->mModPipMatDb[this->mPipeMatCtrl->GetMaterial()->MaterialName] = this->mPipeMatCtrl->GetMaterial();
					}
					else
					{
						PipelineMaterial^ mat = gcnew PipelineMaterial(this->mPipeMatCtrl->GetMaterial());

						this->mModPipMatDb->Remove(this->treVwModelTree->SelectedNode->Text);
						int index = this->treVwModelTree->SelectedNode->Index;
						this->treVwModelTree->SelectedNode->Parent->Nodes->RemoveAt(index);
						TreeNode^ nod;
						if (this->treVwModelTree->SelectedNode->Parent->Text->Equals("Materials"))
							nod = this->treVwModelTree->SelectedNode->Parent->Nodes->Insert(index, mat->MaterialName);
						else nod = this->treVwModelTree->SelectedNode->Nodes->Add(mat->MaterialName);
					
						this->mModPipMatDb->Add(mat->MaterialName, mat);
						this->treVwModelTree->SelectedNode = nod; 					
					}
				}
			}

		private: System::Void mPipeMatCtrl_RemoveCancelBtnClk(System::Object^  sender, System::EventArgs^  e){
				if (this->treVwModelTree->SelectedNode->Text->Equals("Materials"))
				{
					this->mPipeMatCtrl->UpdateControl(nullptr);
				}
				else if (this->treVwModelTree->SelectedNode->Parent != nullptr && this->treVwModelTree->SelectedNode->Parent->Text->Equals("Materials"))
				{
					this->mModPipMatDb->Remove(this->treVwModelTree->SelectedNode->Text);
					int index = this->treVwModelTree->SelectedNode->Index;
					this->treVwModelTree->SelectedNode->Parent->Nodes->RemoveAt(index);
				}
			}

		private: System::Void mPipeMatCtrl_CancelResetBtnClk(System::Object^  sender, System::EventArgs^  e){
			if (this->treVwModelTree->SelectedNode->Text->Equals("Materials"))
			{
				this->mPipeMatCtrl->UpdateControl(nullptr);
			}
			else if (this->treVwModelTree->SelectedNode->Parent != nullptr && this->treVwModelTree->SelectedNode->Parent->Text->Equals("Materials"))
			{
				this->mPipeMatCtrl->UpdateControl(this->mModPipMatDb[this->treVwModelTree->SelectedNode->Text]);
			}
		}

		private: System::Void mPipeGeomCtrl_OnMatDrpDnnCmbBx(System::Object^  sender, System::EventArgs^  e){
			array<String^>^ keys = gcnew array<String^>(this->mModPipMatDb->Count);
			int count = 0;
			for each (KeyValuePair<String^, PipelineMaterial^>^ kvp in this->mModPipMatDb)
			{
				keys[count] = kvp->Key;
				count++;
			}
			this->mPipeGeomCtrl->UpdateMatCmbBx(keys);
		}

		private: System::Void mPipeGeomCtrl_AddUpdateBtnClk(System::Object^  sender, System::EventArgs^  e){
			if (this->treVwModelTree->SelectedNode->Text->Equals("Geometry")) // ADD NEW
			{				
				Element^ elm = this->mPipeGeomCtrl->GetElement();
				if (elm->ElementType == ElementTypes::PIPE)
					this->treVwModelTree->SelectedNode->Nodes->Add(gcnew TreeNode(elm->ID.ToString() + " - PIPE"));
				else if (elm->ElementType == ElementTypes::BEND)
					this->treVwModelTree->SelectedNode->Nodes->Add(gcnew TreeNode(elm->ID.ToString() + " - BEND"));
				else if (elm->ElementType == ElementTypes::REDUCER)
					this->treVwModelTree->SelectedNode->Nodes->Add(gcnew TreeNode(elm->ID.ToString() + " - REDUCER"));
				this->mModPipElemDb->Add(elm->ID, elm);
				this->mPipeGeomCtrl->UpdateControl(nullptr);
				ELEM_COUNT++;
				this->mPipeGeomCtrl->UpdateIDtxtBx(ELEM_COUNT + 1);
			}
			else if (this->treVwModelTree->SelectedNode->Parent != nullptr && this->treVwModelTree->SelectedNode->Parent->Text->Equals("Geometry"))
			{ // UPDATE EXISTING
				array<String^>^ w;
				String^ delimStr = " -";
				array<Char>^ delimiter = delimStr->ToCharArray();
				w = this->treVwModelTree->SelectedNode->Text->Split(delimiter);
				Element^ elm = this->mPipeGeomCtrl->GetElement();
				if (elm->ID.ToString()->Equals(w[0])) // NO CHANGE IN ID WT TO TREENODE TEXT
				{
					if (elm->ElementType == this->mModPipElemDb[elm->ID]->ElementType) // NO CHANGE IN ELEMENT TYPE
					{
						this->mModPipElemDb[elm->ID] = elm;
					}
					else // CHANGE IN ELEMENT TYPE
					{
						this->mModPipElemDb->Remove(elm->ID);
						int index = this->treVwModelTree->SelectedNode->Index;
						this->treVwModelTree->SelectedNode->Parent->Nodes->RemoveAt(index);
						String^ tntxt;
						if (elm->ElementType == ElementTypes::PIPE)
							tntxt = elm->ID.ToString() + " - PIPE";
						else if (elm->ElementType == ElementTypes::BEND)
							tntxt = elm->ID.ToString() + " - BEND";
						else if (elm->ElementType == ElementTypes::REDUCER)
							tntxt = elm->ID.ToString() + " - REDUCER";
						else tntxt = "NULL";
						
						TreeNode^ nod;
						if (this->treVwModelTree->SelectedNode->Parent->Text->Equals("Geometry"))
							nod = this->treVwModelTree->SelectedNode->Parent->Nodes->Insert(index, tntxt); 
						else nod = this->treVwModelTree->SelectedNode->Nodes->Add(tntxt);

						this->mModPipElemDb->Add(elm->ID, elm);
						this->treVwModelTree->SelectedNode = nod;
					}
				}
				else // CHANGE IN ID (NOT ALLOWED) NEED TO UPDATE CODE FOR NOT ALLOWED
				{

				}
			}
		}

		private: System::Void mPipeGeomCtrl_CancelRemoveBtnClk(System::Object^  sender, System::EventArgs^  e){
			geomTreeChildIndexing = true;
			if (this->treVwModelTree->SelectedNode->Text->Equals("Geometry"))
			{
				this->mPipeGeomCtrl->UpdateControl(nullptr);
			}
			else if (this->treVwModelTree->SelectedNode->Parent != nullptr && this->treVwModelTree->SelectedNode->Parent->Text->Equals("Geometry"))
			{
				array<String^>^ w;
				String^ delimStr = " -";
				array<Char>^ delimiter = delimStr->ToCharArray();
				w = this->treVwModelTree->SelectedNode->Text->Split(delimiter);

				this->mModPipElemDb->Remove(int::Parse(w[0]));			

				ELEM_COUNT--;
				this->mPipeGeomCtrl->UpdateIDtxtBx(ELEM_COUNT + 1);

				this->ReArrangeModPipElemDb(int::Parse(w[0]));
				//this->label1->Text = this->mModPipElemDb->Count.ToString();

				int index = this->treVwModelTree->SelectedNode->Index;
				int parentIndex = this->treVwModelTree->SelectedNode->Parent->Index;
			
				while (this->treVwModelTree->SelectedNode->Parent->Index == parentIndex)
									this->treVwModelTree->SelectedNode->Remove();
				//for each (KeyValuePair<unsigned int, Element^>^ kvp in this->mModPipElemDb)
				for (int i = 1; i <= ELEM_COUNT; i++)
				{
					if (this->mModPipElemDb[i]->ElementType == ElementTypes::PIPE)
						this->treVwModelTree->SelectedNode->Nodes->Add(gcnew TreeNode(this->mModPipElemDb[i]->ID.ToString() + " - PIPE"));
					else if (this->mModPipElemDb[i]->ElementType == ElementTypes::BEND)
						this->treVwModelTree->SelectedNode->Nodes->Add(gcnew TreeNode(this->mModPipElemDb[i]->ID.ToString() + " - BEND"));
					else if (this->mModPipElemDb[i]->ElementType == ElementTypes::REDUCER)
						this->treVwModelTree->SelectedNode->Nodes->Add(gcnew TreeNode(this->mModPipElemDb[i]->ID.ToString() + " - REDUCER"));
				}
			}
			geomTreeChildIndexing = false;
		}
		private: System::Void mPipeGeomCtrl_CancelResetBtnClk(System::Object^  sender, System::EventArgs^  e){
			if (this->treVwModelTree->SelectedNode->Text->Equals("Geometry"))
			{
				this->mPipeGeomCtrl->UpdateControl(nullptr);
				this->mPipeGeomCtrl->UpdateIDtxtBx(ELEM_COUNT + 1);
			}
			else if (this->treVwModelTree->SelectedNode->Parent != nullptr && this->treVwModelTree->SelectedNode->Parent->Text->Equals("Geometry"))
			{
				array<String^>^ w;
				String^ delimStr = " -";
				array<Char>^ delimiter = delimStr->ToCharArray();
				w = this->treVwModelTree->SelectedNode->Text->Split(delimiter);
				this->mPipeGeomCtrl->UpdateControl(this->mModPipElemDb[int::Parse(w[0])]);
			}
		}

		private: void ReArrangeModPipElemDb(const unsigned int ind)
		{
			const int arrSize = this->mModPipElemDb->Count - ind + 1;
			array<Element^>^ elmArr = gcnew array<Element^>(arrSize);
			unsigned int i = ind + 1;
			unsigned int c = 0;

			for (i = ind + 1, c = 0; i <= ELEM_COUNT + 1; i++, c++)
			{
				elmArr[c] = this->mModPipElemDb[i];
				this->mModPipElemDb->Remove(i);
			}
			for (i = ind, c = 0; i <= ELEM_COUNT; i++, c++)
			{
				this->mModPipElemDb->Add(i, elmArr[c]);
				this->mModPipElemDb[i]->ID = i;
			}

		}		 

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		m_OA->LaunchOgre();
		this->m_OA_init = true;
	}
	private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if(m_OA->OgreStarted)
			this->m_OA->OnMouseMove(sender, e);
	}
	private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (m_OA->OgreStarted)
			this->m_OA->OnMouseDown(sender, e);
	}
	private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (m_OA->OgreStarted)
			this->m_OA->OnMouseUp(sender, e);
	}
	private: System::Void panel1_Resize(System::Object^  sender, System::EventArgs^  e) {
		if (m_OA->OgreStarted)
			this->m_OA->OnPanelResize(sender, e, this->panel1);
	}
	private: System::Void panel1_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (m_OA->OgreStarted)
			this->m_OA->OnMouseWheel(sender, e);
	}
};
}
