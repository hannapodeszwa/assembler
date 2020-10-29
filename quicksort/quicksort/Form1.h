#pragma once
#include <vector>
//#include <msclr>
#include "Quicksort.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TrackBar^ suwak;
	private: System::Windows::Forms::Label^ watki;





	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ liczby;





	private: System::Windows::Forms::Label^ nazwa_pliku;


	protected:


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->suwak = (gcnew System::Windows::Forms::TrackBar());
			this->watki = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->nazwa_pliku = (gcnew System::Windows::Forms::Label());
			this->liczby = (gcnew System::Windows::Forms::TextBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->suwak))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(273, 277);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Sortuj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// suwak
			// 
			this->suwak->Location = System::Drawing::Point(10, 151);
			this->suwak->Maximum = 64;
			this->suwak->Minimum = 1;
			this->suwak->Name = L"suwak";
			this->suwak->Size = System::Drawing::Size(235, 56);
			this->suwak->TabIndex = 3;
			this->suwak->Text = L"Liczba w¹tków";
			this->suwak->Value = 1;
			this->suwak->Scroll += gcnew System::EventHandler(this, &Form1::suwak_Scroll_1);
			// 
			// watki
			// 
			this->watki->AutoSize = true;
			this->watki->Location = System::Drawing::Point(7, 116);
			this->watki->Name = L"watki";
			this->watki->Size = System::Drawing::Size(114, 17);
			this->watki->TabIndex = 4;
			this->watki->Text = L"Liczba w¹tków: 1";
			this->watki->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->groupBox1->CausesValidation = false;
			this->groupBox1->Controls->Add(this->nazwa_pliku);
			this->groupBox1->Controls->Add(this->liczby);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->suwak);
			this->groupBox1->Controls->Add(this->watki);
			this->groupBox1->Location = System::Drawing::Point(12, 56);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(255, 207);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// nazwa_pliku
			// 
			this->nazwa_pliku->AutoSize = true;
			this->nazwa_pliku->Location = System::Drawing::Point(7, 24);
			this->nazwa_pliku->Name = L"nazwa_pliku";
			this->nazwa_pliku->Size = System::Drawing::Size(87, 17);
			this->nazwa_pliku->TabIndex = 9;
			this->nazwa_pliku->Text = L"Nazwa pliku:";
			this->nazwa_pliku->Click += gcnew System::EventHandler(this, &Form1::label1_Click_1);
			// 
			// liczby
			// 
			this->liczby->Location = System::Drawing::Point(95, 24);
			this->liczby->Name = L"liczby";
			this->liczby->Size = System::Drawing::Size(154, 22);
			this->liczby->TabIndex = 8;
			this->liczby->TextChanged += gcnew System::EventHandler(this, &Form1::liczby_TextChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(10, 83);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(55, 21);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->Text = L"asm";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(10, 56);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(54, 21);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"C++";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(273, 221);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"czas: ";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(397, 341);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Quicksort";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->suwak))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}


	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Quicksort quicksort1;

		/*if (liczba1->Text == "")
		{
			MessageBox::Show("Podaj liczby do sortowania.");
		}
		else
		{*/
		//pobranie liczb do sortowania
	//	quicksort.set_tab(Convert::ToInt16(liczba1->Text), Convert::ToInt16(liczba2->Text), Convert::ToInt16(liczba3->Text));
		if (nazwa_pliku->Text == "")
		{
			MessageBox::Show("Podaj plik.");
		}
		else
		{
			String^ str = (liczby->Text);
			string s;
			MarshalString(str, s);
			//= gcnew(str.c_str);
			quicksort1.set_plik(s);
			quicksort1.set_liczba_watkow(suwak->Value);
			if(radioButton2->Checked)
			quicksort1.set_czy_asm(1);

			quicksort1.quicksort();

			label2->Text = "czas: " + Convert::ToString(quicksort1.get_czas());
			
		}
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void suwak_Scroll_1(System::Object^ sender, System::EventArgs^ e) {
		watki->Text = "Liczba watkow: " + Convert::ToString(suwak->Value);
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void liczby_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};

}
