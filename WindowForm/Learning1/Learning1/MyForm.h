#pragma once

namespace Learning1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(395, 45);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(355, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to windows Form Calculator ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(400, 129);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(99, 38);
			this->textBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(468, 356);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 25);
			this->label2->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(641, 129);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(109, 38);
			this->textBox2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(400, 173);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(62, 43);
			this->button2->TabIndex = 5;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(594, 173);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(62, 43);
			this->button3->TabIndex = 6;
			this->button3->Text = L"*";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(494, 173);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(62, 43);
			this->button4->TabIndex = 7;
			this->button4->Text = L"-";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(688, 173);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(62, 43);
			this->button5->TabIndex = 8;
			this->button5->Text = L"/";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(395, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 34);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Operand 1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(635, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 34);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Operand 2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(1064, 681);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"MV Boli", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(5);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	double result = System::Convert::ToDouble(this->textBox1->Text) + System::Convert::ToDouble(this->textBox2->Text);
	this->label2->Text ="RESULT : " + this->textBox1->Text + " + " + this->textBox2->Text + " : " +System::Convert::ToString(result);

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	double result = System::Convert::ToDouble(this->textBox1->Text) - System::Convert::ToDouble(this->textBox2->Text);
	this->label2->Text = "RESULT : " + this->textBox1->Text + " - " + this->textBox2->Text + " : " + System::Convert::ToString(result);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	double result = System::Convert::ToDouble(this->textBox1->Text) * System::Convert::ToDouble(this->textBox2->Text);
	this->label2->Text = "RESULT : " + this->textBox1->Text + " * " + this->textBox2->Text + " : " +System::Convert::ToString(result);
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	double result = System::Convert::ToDouble(this->textBox1->Text) / System::Convert::ToDouble(this->textBox2->Text);
	this->label2->Text = "RESULT : "+ this->textBox1->Text +" / " + this->textBox2->Text +" : "+ System::Convert::ToString(result) ;
	
}
};
}
