#include "Home.h"
#include "dictionarydll.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Dictionary;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Dictionary::Home form;
	Application::Run(% form);
}


private: System::Void insertButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// Call your C++/CLI insert function here
	Dictionary::Home::insertCppFunction(search->Text);
}