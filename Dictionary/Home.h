#pragma once

namespace Dictionary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
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
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ search;
	private: System::Windows::Forms::Button^ insertButton;
	private: System::Windows::Forms::Button^ deleteButton;
	private: System::Windows::Forms::Button^ searchButton;
	private: System::Windows::Forms::Button^ suggestButton;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->search = (gcnew System::Windows::Forms::TextBox());
			this->insertButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->suggestButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 16.1194F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(238, 205);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 35);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Dictionary";
			this->label1->Click += gcnew System::EventHandler(this, &Home::label1_Click);
			// 
			// search
			// 
			this->search->Location = System::Drawing::Point(159, 297);
			this->search->Margin = System::Windows::Forms::Padding(5);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(361, 22);
			this->search->TabIndex = 3;
			this->search->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->search->TextChanged += gcnew System::EventHandler(this, &Home::textBox1_TextChanged);
			// 
			// insertButton
			// 
			this->insertButton->Location = System::Drawing::Point(111, 358);
			this->insertButton->Name = L"insertButton";
			this->insertButton->Size = System::Drawing::Size(106, 56);
			this->insertButton->TabIndex = 4;
			this->insertButton->Text = L"Insert";
			this->insertButton->UseVisualStyleBackColor = true;
			this->insertButton->Click += gcnew System::EventHandler(this, &Home::insertButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(244, 358);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Padding = System::Windows::Forms::Padding(5);
			this->deleteButton->Size = System::Drawing::Size(87, 56);
			this->deleteButton->TabIndex = 5;
			this->deleteButton->Text = L"Delete";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Home::deleteButton_Click);
			// 
			// searchButton
			// 
			this->searchButton->Location = System::Drawing::Point(364, 358);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(82, 56);
			this->searchButton->TabIndex = 6;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = true;
			// 
			// suggestButton
			// 
			this->suggestButton->Location = System::Drawing::Point(473, 358);
			this->suggestButton->Name = L"suggestButton";
			this->suggestButton->Size = System::Drawing::Size(98, 56);
			this->suggestButton->TabIndex = 7;
			this->suggestButton->Text = L"Suggest";
			this->suggestButton->UseVisualStyleBackColor = true;
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(723, 669);
			this->Controls->Add(this->suggestButton);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->insertButton);
			this->Controls->Add(this->search);
			this->Controls->Add(this->label1);
			this->Name = L"Home";
			this->Padding = System::Windows::Forms::Padding(5);
			this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			this->Text = L"Home";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Home_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void insertButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
