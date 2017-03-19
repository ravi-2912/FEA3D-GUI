#include "MainWindow.h"

namespace DemoSFLpro 
{
	using namespace System;
	using namespace System::Windows::Forms;

	[System::Runtime::InteropServices::DllImport("user32.dll")]
	bool SetProcessDPIAware();

	[STAThread]
	void Main(array<System::String^>^ args)
	{
		OperatingSystem^ osv = Environment::OSVersion;
		Version^ ver = osv->Version;
		if (ver->Major >= 6)
			SetProcessDPIAware();

		System::Windows::Forms::Application::EnableVisualStyles();
		System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
		MainWindow m_MainWindow;
		System::Windows::Forms::Application::Run(% m_MainWindow);
	}

}
