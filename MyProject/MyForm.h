#pragma once
#include "OpenGL.h"

namespace MyProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		byte scalebyte = 0;

	private: System::Windows::Forms::CheckBox^ funcBox;
	private: System::Windows::Forms::CheckBox^ derBox;
	private: System::Windows::Forms::CheckBox^ maxBox;
	private: System::Windows::Forms::CheckBox^ osBox;
	private: System::Windows::Forms::CheckBox^ colorBox;






	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ bBox;

	private: System::Windows::Forms::TextBox^ eBox;




	private: System::Windows::Forms::CheckBox^ localmaxBox;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;



















		private:
			OpenGL^ opengl;

		public:
			MyForm(void)
			{
				InitializeComponent();
				opengl = gcnew OpenGL(this, 700, 600);
			}


		protected:
			/// <summary>
			/// Освободить все используемые ресурсы.
			/// </summary>
			~MyForm()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ plusbutton;
	private: System::Windows::Forms::Button^ minusbutton;













		private: System::ComponentModel::IContainer^ components;
		protected:

		private:
			/// <summary>
			/// Обязательная переменная конструктора.
			/// </summary>

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Требуемый метод для поддержки конструктора — не изменяйте 
			/// содержимое этого метода с помощью редактора кода.
			/// </summary>
			void InitializeComponent(void)
			{
				this->components = (gcnew System::ComponentModel::Container());
				this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				this->plusbutton = (gcnew System::Windows::Forms::Button());
				this->minusbutton = (gcnew System::Windows::Forms::Button());
				this->funcBox = (gcnew System::Windows::Forms::CheckBox());
				this->derBox = (gcnew System::Windows::Forms::CheckBox());
				this->maxBox = (gcnew System::Windows::Forms::CheckBox());
				this->osBox = (gcnew System::Windows::Forms::CheckBox());
				this->colorBox = (gcnew System::Windows::Forms::CheckBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->bBox = (gcnew System::Windows::Forms::TextBox());
				this->eBox = (gcnew System::Windows::Forms::TextBox());
				this->localmaxBox = (gcnew System::Windows::Forms::CheckBox());
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
				this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
				this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
				this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
				this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
				this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
				this->panel2 = (gcnew System::Windows::Forms::Panel());
				this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
				this->panel1->SuspendLayout();
				this->panel2->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				this->SuspendLayout();
				// 
				// timer1
				// 
				this->timer1->Enabled = true;
				this->timer1->Interval = 10;
				this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				// 
				// plusbutton
				// 
				this->plusbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				this->plusbutton->Location = System::Drawing::Point(963, 298);
				this->plusbutton->Name = L"plusbutton";
				this->plusbutton->Size = System::Drawing::Size(129, 44);
				this->plusbutton->TabIndex = 0;
				this->plusbutton->Text = L"Приблизить";
				this->toolTip1->SetToolTip(this->plusbutton, L"С помощью клавиш w или +");
				this->plusbutton->UseVisualStyleBackColor = true;
				this->plusbutton->Click += gcnew System::EventHandler(this, &MyForm::plusbutton_Click);
				// 
				// minusbutton
				// 
				this->minusbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				this->minusbutton->Location = System::Drawing::Point(1109, 298);
				this->minusbutton->Name = L"minusbutton";
				this->minusbutton->Size = System::Drawing::Size(129, 44);
				this->minusbutton->TabIndex = 0;
				this->minusbutton->Text = L"Отдалить";
				this->toolTip1->SetToolTip(this->minusbutton, L"С помощью клавиш s или -");
				this->minusbutton->UseVisualStyleBackColor = true;
				this->minusbutton->Click += gcnew System::EventHandler(this, &MyForm::minusbutton_Click);
				// 
				// funcBox
				// 
				this->funcBox->AutoSize = true;
				this->funcBox->Checked = true;
				this->funcBox->CheckState = System::Windows::Forms::CheckState::Checked;
				this->funcBox->Location = System::Drawing::Point(12, 15);
				this->funcBox->Name = L"funcBox";
				this->funcBox->Size = System::Drawing::Size(90, 22);
				this->funcBox->TabIndex = 1;
				this->funcBox->Text = L"Функция";
				this->funcBox->UseVisualStyleBackColor = true;
				this->funcBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::funcBox_CheckedChanged);
				// 
				// derBox
				// 
				this->derBox->AutoSize = true;
				this->derBox->Location = System::Drawing::Point(142, 15);
				this->derBox->Name = L"derBox";
				this->derBox->Size = System::Drawing::Size(124, 22);
				this->derBox->TabIndex = 2;
				this->derBox->Text = L"Производная";
				this->derBox->UseVisualStyleBackColor = true;
				this->derBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::derBox_CheckedChanged);
				// 
				// maxBox
				// 
				this->maxBox->AutoSize = true;
				this->maxBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				this->maxBox->Location = System::Drawing::Point(12, 169);
				this->maxBox->Name = L"maxBox";
				this->maxBox->Size = System::Drawing::Size(233, 22);
				this->maxBox->TabIndex = 2;
				this->maxBox->Text = L"Максимум (и минимум тоже)";
				this->maxBox->UseVisualStyleBackColor = true;
				this->maxBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::maxBox_CheckedChanged);
				// 
				// osBox
				// 
				this->osBox->AutoSize = true;
				this->osBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				this->osBox->Checked = true;
				this->osBox->CheckState = System::Windows::Forms::CheckState::Checked;
				this->osBox->Location = System::Drawing::Point(12, 54);
				this->osBox->Name = L"osBox";
				this->osBox->Size = System::Drawing::Size(58, 22);
				this->osBox->TabIndex = 2;
				this->osBox->Text = L"Оси";
				this->osBox->UseVisualStyleBackColor = true;
				this->osBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::osBox_CheckedChanged);
				// 
				// colorBox
				// 
				this->colorBox->AutoSize = true;
				this->colorBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				this->colorBox->Location = System::Drawing::Point(142, 54);
				this->colorBox->Name = L"colorBox";
				this->colorBox->Size = System::Drawing::Size(64, 22);
				this->colorBox->TabIndex = 2;
				this->colorBox->Text = L"Цвет";
				this->colorBox->UseVisualStyleBackColor = true;
				this->colorBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::colorBox_CheckedChanged);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(9, 212);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(197, 18);
				this->label1->TabIndex = 4;
				this->label1->Text = L"На отрезке от                  до";
				this->label1->Visible = false;
				// 
				// bBox
				// 
				this->bBox->Location = System::Drawing::Point(125, 212);
				this->bBox->MaxLength = 3;
				this->bBox->Name = L"bBox";
				this->bBox->Size = System::Drawing::Size(39, 24);
				this->bBox->TabIndex = 5;
				this->bBox->Visible = false;
				this->bBox->Leave += gcnew System::EventHandler(this, &MyForm::bBox_Leave);
				// 
				// eBox
				// 
				this->eBox->Location = System::Drawing::Point(215, 212);
				this->eBox->MaxLength = 3;
				this->eBox->Name = L"eBox";
				this->eBox->Size = System::Drawing::Size(39, 24);
				this->eBox->TabIndex = 5;
				this->eBox->Visible = false;
				this->eBox->Leave += gcnew System::EventHandler(this, &MyForm::eBox_Leave);
				// 
				// localmaxBox
				// 
				this->localmaxBox->AutoSize = true;
				this->localmaxBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				this->localmaxBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
				this->localmaxBox->Location = System::Drawing::Point(12, 253);
				this->localmaxBox->Name = L"localmaxBox";
				this->localmaxBox->Size = System::Drawing::Size(242, 21);
				this->localmaxBox->TabIndex = 2;
				this->localmaxBox->Text = L"Локальный максимум / минимум";
				this->localmaxBox->UseVisualStyleBackColor = true;
				this->localmaxBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::localmaxBox_CheckedChanged);
				// 
				// panel1
				// 
				this->panel1->BackColor = System::Drawing::SystemColors::Control;
				this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->panel1->Controls->Add(this->radioButton6);
				this->panel1->Controls->Add(this->radioButton4);
				this->panel1->Controls->Add(this->radioButton2);
				this->panel1->Controls->Add(this->radioButton5);
				this->panel1->Controls->Add(this->radioButton3);
				this->panel1->Controls->Add(this->radioButton1);
				this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				this->panel1->Location = System::Drawing::Point(963, 26);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(275, 233);
				this->panel1->TabIndex = 6;
				// 
				// radioButton6
				// 
				this->radioButton6->AutoSize = true;
				this->radioButton6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.8F));
				this->radioButton6->Location = System::Drawing::Point(14, 197);
				this->radioButton6->Name = L"radioButton6";
				this->radioButton6->Size = System::Drawing::Size(194, 22);
				this->radioButton6->TabIndex = 3;
				this->radioButton6->Text = L"y = sqrt(x)*tan(x)*sin(2*x)";
				this->radioButton6->UseVisualStyleBackColor = true;
				this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton6_CheckedChanged);
				// 
				// radioButton4
				// 
				this->radioButton4->AutoSize = true;
				this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.8F));
				this->radioButton4->Location = System::Drawing::Point(14, 120);
				this->radioButton4->Name = L"radioButton4";
				this->radioButton4->Size = System::Drawing::Size(135, 22);
				this->radioButton4->TabIndex = 3;
				this->radioButton4->Text = L"y = log(x)+sin(x)";
				this->radioButton4->UseVisualStyleBackColor = true;
				this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
				// 
				// radioButton2
				// 
				this->radioButton2->AutoSize = true;
				this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.8F));
				this->radioButton2->Location = System::Drawing::Point(14, 49);
				this->radioButton2->Name = L"radioButton2";
				this->radioButton2->Size = System::Drawing::Size(151, 22);
				this->radioButton2->TabIndex = 3;
				this->radioButton2->Text = L"y = cos(x)*sin(2*x)";
				this->radioButton2->UseVisualStyleBackColor = true;
				this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
				// 
				// radioButton5
				// 
				this->radioButton5->AutoSize = true;
				this->radioButton5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.8F));
				this->radioButton5->Location = System::Drawing::Point(14, 157);
				this->radioButton5->Name = L"radioButton5";
				this->radioButton5->Size = System::Drawing::Size(138, 22);
				this->radioButton5->TabIndex = 3;
				this->radioButton5->Text = L"y = exp(x)+sin(x)";
				this->radioButton5->UseVisualStyleBackColor = true;
				this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton5_CheckedChanged);
				// 
				// radioButton3
				// 
				this->radioButton3->AutoSize = true;
				this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.8F));
				this->radioButton3->Location = System::Drawing::Point(14, 84);
				this->radioButton3->Name = L"radioButton3";
				this->radioButton3->Size = System::Drawing::Size(121, 22);
				this->radioButton3->TabIndex = 3;
				this->radioButton3->Text = L"y = cos(x)*x*x";
				this->radioButton3->UseVisualStyleBackColor = true;
				this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
				// 
				// radioButton1
				// 
				this->radioButton1->AutoSize = true;
				this->radioButton1->Checked = true;
				this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.8F));
				this->radioButton1->Location = System::Drawing::Point(14, 17);
				this->radioButton1->Name = L"radioButton1";
				this->radioButton1->Size = System::Drawing::Size(89, 22);
				this->radioButton1->TabIndex = 3;
				this->radioButton1->TabStop = true;
				this->radioButton1->Text = L"y = sin(x)";
				this->radioButton1->UseVisualStyleBackColor = true;
				this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
				// 
				// panel2
				// 
				this->panel2->BackColor = System::Drawing::SystemColors::Control;
				this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->panel2->Controls->Add(this->pictureBox1);
				this->panel2->Controls->Add(this->funcBox);
				this->panel2->Controls->Add(this->derBox);
				this->panel2->Controls->Add(this->localmaxBox);
				this->panel2->Controls->Add(this->eBox);
				this->panel2->Controls->Add(this->bBox);
				this->panel2->Controls->Add(this->osBox);
				this->panel2->Controls->Add(this->colorBox);
				this->panel2->Controls->Add(this->label4);
				this->panel2->Controls->Add(this->label1);
				this->panel2->Controls->Add(this->maxBox);
				this->panel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
				this->panel2->Location = System::Drawing::Point(963, 378);
				this->panel2->Name = L"panel2";
				this->panel2->Size = System::Drawing::Size(271, 295);
				this->panel2->TabIndex = 7;
				// 
				// pictureBox1
				// 
				this->pictureBox1->ImageLocation = L"C:\\Users\\deskt\\Downloads\\#ffff00#ffff00#ff0000#ff00ff#ff00ff_1920_192.png";
				this->pictureBox1->Location = System::Drawing::Point(12, 118);
				this->pictureBox1->Name = L"pictureBox1";
				this->pictureBox1->Size = System::Drawing::Size(242, 32);
				this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->pictureBox1->TabIndex = 8;
				this->pictureBox1->TabStop = false;
				this->pictureBox1->Visible = false;
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(11, 88);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(242, 18);
				this->label4->TabIndex = 4;
				this->label4->Text = L"  -                         0                          +";
				this->label4->Visible = false;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->BackColor = System::Drawing::SystemColors::Control;
				this->label2->Location = System::Drawing::Point(1060, 370);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(78, 16);
				this->label2->TabIndex = 4;
				this->label2->Text = L"Видимость";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->BackColor = System::Drawing::SystemColors::Control;
				this->label3->Location = System::Drawing::Point(1052, 18);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(110, 16);
				this->label3->TabIndex = 4;
				this->label3->Text = L"Выбор функции";
				// 
				// toolTip1
				// 
				this->toolTip1->AutoPopDelay = 5000;
				this->toolTip1->InitialDelay = 500;
				this->toolTip1->ReshowDelay = 100;
				this->toolTip1->Tag = L"plusbutton_MouseEnter()";
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				this->ClientSize = System::Drawing::Size(1250, 734);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->panel2);
				this->Controls->Add(this->panel1);
				this->Controls->Add(this->minusbutton);
				this->Controls->Add(this->plusbutton);
				this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				this->Name = L"MyForm";
				this->Text = L"Приблизить";
				this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				this->panel1->ResumeLayout(false);
				this->panel1->PerformLayout();
				this->panel2->ResumeLayout(false);
				this->panel2->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion
			private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
			{
				opengl->Render();
			}
		private: System::Void minusbutton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (opengl->scalsebyte < 126)
				opengl->scalsebyte += 1;
		}
		private: System::Void plusbutton_Click(System::Object^ sender, System::EventArgs^ e) {
			if (opengl->scalsebyte > 1)
				opengl->scalsebyte -= 1;

		}
		private: System::Void funcBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->funcvis = funcBox->Checked;
		}
		private: System::Void derBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->dervis = derBox->Checked;
		}
		private: System::Void maxBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->maxvis = maxBox->Checked;
			label1->Visible = maxBox->Checked;
			bBox->Visible = maxBox->Checked;
			eBox->Visible = maxBox->Checked;
		}
		private: System::Void osBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->osvis = osBox->Checked;
		}
		private: System::Void colorBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->colvis = colorBox->Checked;
			label4->Visible = colorBox->Checked;
			pictureBox1->Visible = colorBox->Checked;
		}

		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void bBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			INT16::TryParse(bBox->Text, opengl->begin);
		}
		private: System::Void eBox_Leave(System::Object^ sender, System::EventArgs^ e) {
			INT16::TryParse(bBox->Text, opengl->end);
		}

		private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->refresh = true;
			opengl->findex = 1;
		}
		private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->refresh = true; 
			opengl->findex = 2;
		}
		private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->refresh = true; 
			opengl->findex = 3;
		}
		private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->refresh = true; 
			opengl->findex = 4;
		}
		private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->refresh = true; 
			opengl->findex = 5;
		}
		private: System::Void radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->refresh = true; 
			opengl->findex = 6;
		}
		private: System::Void localmaxBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			opengl->locmaxvis = localmaxBox->Checked;
		}
};
}
