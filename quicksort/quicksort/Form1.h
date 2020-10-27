#pragma once
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
	private: System::Windows::Forms::TextBox^ liczba3;

	private: System::Windows::Forms::TextBox^ liczba2;

	private: System::Windows::Forms::TextBox^ liczba1;

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
			this->liczba3 = (gcnew System::Windows::Forms::TextBox());
			this->liczba2 = (gcnew System::Windows::Forms::TextBox());
			this->liczba1 = (gcnew System::Windows::Forms::TextBox());
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
			// 
			// watki
			// 
			this->watki->AutoSize = true;
			this->watki->Location = System::Drawing::Point(7, 116);
			this->watki->Name = L"watki";
			this->watki->Size = System::Drawing::Size(98, 17);
			this->watki->TabIndex = 4;
			this->watki->Text = L"Liczba w¹tków";
			this->watki->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->groupBox1->CausesValidation = false;
			this->groupBox1->Controls->Add(this->liczba3);
			this->groupBox1->Controls->Add(this->liczba2);
			this->groupBox1->Controls->Add(this->liczba1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->suwak);
			this->groupBox1->Controls->Add(this->watki);
			this->groupBox1->Location = System::Drawing::Point(12, 64);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(255, 207);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// liczba3
			// 
			this->liczba3->Location = System::Drawing::Point(78, 21);
			this->liczba3->Name = L"liczba3";
			this->liczba3->Size = System::Drawing::Size(29, 22);
			this->liczba3->TabIndex = 10;
			// 
			// liczba2
			// 
			this->liczba2->Location = System::Drawing::Point(41, 21);
			this->liczba2->Name = L"liczba2";
			this->liczba2->Size = System::Drawing::Size(31, 22);
			this->liczba2->TabIndex = 9;
			// 
			// liczba1
			// 
			this->liczba1->Location = System::Drawing::Point(6, 21);
			this->liczba1->Name = L"liczba1";
			this->liczba1->Size = System::Drawing::Size(29, 22);
			this->liczba1->TabIndex = 8;
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

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Quicksort quicksort;

		/*if (liczba1->Text == "")
		{
			MessageBox::Show("Podaj liczby do sortowania.");
		}
		else
		{*/
		//pobranie liczb do sortowania
	//	quicksort.set_tab(Convert::ToInt16(liczba1->Text), Convert::ToInt16(liczba2->Text), Convert::ToInt16(liczba3->Text));

		quicksort.set_liczba_watkow(suwak->Value);
		quicksort.quicksort();

		label2->Text = "czas: " + Convert::ToString(quicksort.get_czas());
		//}
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void suwak_Scroll(System::Object^ sender, System::EventArgs^ e) {
		watki->Text="Liczba watkow: " + Convert::ToString(suwak->Value);
		//toolTip1.SetToolTip(suwak, suwak.Value.ToString());
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};

}
