#pragma once
#include <msclr\marshal_cppstd.h>
#include"Arithmetic.h"

Arithmetic* ans;

namespace finalproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  start_text_box;
	private: System::Windows::Forms::Button^  go_but;
	private: System::Windows::Forms::DataGridView^  Grid;
	private: System::Windows::Forms::Button^  set_tab_but;
	private: System::Windows::Forms::Button^  calc_but;
	private: System::Windows::Forms::TextBox^  ans_box;
	private: System::Windows::Forms::TextBox^  poliz_box;
	protected:

	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->start_text_box = (gcnew System::Windows::Forms::TextBox());
			this->go_but = (gcnew System::Windows::Forms::Button());
			this->Grid = (gcnew System::Windows::Forms::DataGridView());
			this->set_tab_but = (gcnew System::Windows::Forms::Button());
			this->calc_but = (gcnew System::Windows::Forms::Button());
			this->ans_box = (gcnew System::Windows::Forms::TextBox());
			this->poliz_box = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid))->BeginInit();
			this->SuspendLayout();
			// 
			// start_text_box
			// 
			this->start_text_box->Location = System::Drawing::Point(12, 12);
			this->start_text_box->Name = L"start_text_box";
			this->start_text_box->Size = System::Drawing::Size(471, 20);
			this->start_text_box->TabIndex = 0;
			// 
			// go_but
			// 
			this->go_but->Location = System::Drawing::Point(489, 12);
			this->go_but->Name = L"go_but";
			this->go_but->Size = System::Drawing::Size(71, 21);
			this->go_but->TabIndex = 1;
			this->go_but->Text = L"go";
			this->go_but->UseVisualStyleBackColor = true;
			this->go_but->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// Grid
			// 
			this->Grid->AllowUserToAddRows = false;
			this->Grid->AllowUserToDeleteRows = false;
			this->Grid->AllowUserToResizeColumns = false;
			this->Grid->AllowUserToResizeRows = false;
			this->Grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Grid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->Grid->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Grid->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			this->Grid->ColumnHeadersHeight = 30;
			this->Grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->Grid->ColumnHeadersVisible = false;
			this->Grid->Location = System::Drawing::Point(12, 50);
			this->Grid->MultiSelect = false;
			this->Grid->Name = L"Grid";
			this->Grid->RowHeadersVisible = false;
			this->Grid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->Grid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->Grid->Size = System::Drawing::Size(200, 266);
			this->Grid->TabIndex = 2;
			// 
			// set_tab_but
			// 
			this->set_tab_but->Location = System::Drawing::Point(12, 322);
			this->set_tab_but->Name = L"set_tab_but";
			this->set_tab_but->Size = System::Drawing::Size(200, 31);
			this->set_tab_but->TabIndex = 3;
			this->set_tab_but->Text = L"Set";
			this->set_tab_but->UseVisualStyleBackColor = true;
			this->set_tab_but->Click += gcnew System::EventHandler(this, &MyForm::set_tab_but_Click);
			// 
			// calc_but
			// 
			this->calc_but->Location = System::Drawing::Point(260, 290);
			this->calc_but->Name = L"calc_but";
			this->calc_but->Size = System::Drawing::Size(300, 63);
			this->calc_but->TabIndex = 4;
			this->calc_but->Text = L"CALCULATE";
			this->calc_but->UseVisualStyleBackColor = true;
			this->calc_but->Click += gcnew System::EventHandler(this, &MyForm::calc_but_Click);
			// 
			// ans_box
			// 
			this->ans_box->Location = System::Drawing::Point(260, 264);
			this->ans_box->Name = L"ans_box";
			this->ans_box->Size = System::Drawing::Size(300, 20);
			this->ans_box->TabIndex = 5;
			// 
			// poliz_box
			// 
			this->poliz_box->Location = System::Drawing::Point(260, 71);
			this->poliz_box->Name = L"poliz_box";
			this->poliz_box->Size = System::Drawing::Size(300, 20);
			this->poliz_box->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(572, 377);
			this->Controls->Add(this->poliz_box);
			this->Controls->Add(this->ans_box);
			this->Controls->Add(this->calc_but);
			this->Controls->Add(this->set_tab_but);
			this->Controls->Add(this->Grid);
			this->Controls->Add(this->go_but);
			this->Controls->Add(this->start_text_box);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Grid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		
		void draw_grid() {
			int cnt = ans->get_poliz()->get_tab()->get_count();
			Grid->RowCount = cnt;
			Grid->ColumnCount = 2;
			for (int i = 0; i < cnt; i++) {
				Grid->Rows[i]->Cells[0]->Value = msclr::interop::marshal_as<String^>(ans->get_poliz()->get_tab()->operator[](i).get_name());
				Grid->Rows[i]->Cells[0]->ReadOnly = true;
				Grid->Rows[i]->Cells[1]->Value = System::Convert::ToString(ans->get_poliz()->get_tab()->operator[](i).get_val());
				if (ans->get_poliz()->get_tab()->operator[](i).get_val() != 0) {
					Grid->Rows[i]->Cells[1]->ReadOnly = true;
				}
				else if (ans->get_poliz()->get_tab()->operator[](i).get_val() == 0 &&
					ans->get_poliz()->get_tab()->operator[](i).get_name() == "0") {
					Grid->Rows[i]->Cells[1]->ReadOnly = true;
				}
			}
		}

		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			std::string str = msclr::interop::marshal_as<std::string>(start_text_box->Text);
			ans = new Arithmetic(str);
			str = ans->get_poliz()->print_poliz();
			//MessageBox::Show(msclr::interop::marshal_as<String^>(str));
			start_text_box->ReadOnly = true;
			poliz_box->Text = msclr::interop::marshal_as<String^>(str);
			poliz_box->ReadOnly = true;
			draw_grid();
		}
		System::Void set_tab_but_Click(System::Object^  sender, System::EventArgs^  e) {
			int cnt = ans->get_poliz()->get_tab()->get_count();
			for (int i = 0; i < cnt; i++) {
				double kek = System::Convert::ToDouble(Grid->Rows[i]->Cells[1]->Value);
				ans->get_poliz()->get_tab()->operator[](i).set_val(kek);
				//MessageBox::Show(System::Convert::ToString(kek));
				//MessageBox::Show(System::Convert::ToString(ans.get_poliz().get_tab()->operator[](i).get_val()));
			}
			draw_grid();
		}
		System::Void calc_but_Click(System::Object^  sender, System::EventArgs^  e) {
			double res = ans->calc();
			ans_box->Text = System::Convert::ToString(res);
		}
};
}
