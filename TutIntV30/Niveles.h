#pragma once
#include "BaseDeDatos.h"

namespace TutIntV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Niveles
	/// </summary>
	public ref class Niveles : public System::Windows::Forms::Form
	{
	public:
		Niveles(void)
		{
			InitializeComponent();
			inicializarTam();
		}
		Niveles(Form^ f, BaseDeDatos^ manejador)
		{
			form = f;
			manejadorBD = manejador;
			InitializeComponent();
			inicializarTam();
			inicializarComponentesBD();
			this->Size = System::Drawing::Size(1050, 598);
			this->Show();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Niveles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: BaseDeDatos ^ manejadorBD;
	private: System::Windows::Forms::Form^ form;
	private: int hUno, wUno, hDos, wDos, hTres, wTres, hVolver, wVolver;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  picNivelUno;
	private: System::Windows::Forms::PictureBox^  picNivel2;
	private: System::Windows::Forms::PictureBox^  picNivel3;
	private: System::Windows::Forms::PictureBox^  picNivel3E;
	private: System::Windows::Forms::PictureBox^  picNivel2E;
	private: System::Windows::Forms::Label^  lblEstrellas;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Niveles::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->picNivelUno = (gcnew System::Windows::Forms::PictureBox());
			this->picNivel2 = (gcnew System::Windows::Forms::PictureBox());
			this->picNivel3 = (gcnew System::Windows::Forms::PictureBox());
			this->picNivel3E = (gcnew System::Windows::Forms::PictureBox());
			this->picNivel2E = (gcnew System::Windows::Forms::PictureBox());
			this->lblEstrellas = (gcnew System::Windows::Forms::Label());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivelUno))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivel2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivel3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivel3E))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivel2E))->BeginInit();
			this->panelPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(457, 19);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(78, 77);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			// 
			// picNivelUno
			// 
			this->picNivelUno->BackColor = System::Drawing::Color::Transparent;
			this->picNivelUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picNivelUno.BackgroundImage")));
			this->picNivelUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picNivelUno->Location = System::Drawing::Point(85, 152);
			this->picNivelUno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picNivelUno->Name = L"picNivelUno";
			this->picNivelUno->Size = System::Drawing::Size(258, 251);
			this->picNivelUno->TabIndex = 2;
			this->picNivelUno->TabStop = false;
			this->picNivelUno->WaitOnLoad = true;
			this->picNivelUno->Click += gcnew System::EventHandler(this, &Niveles::picNivelUno_Click);
			this->picNivelUno->MouseLeave += gcnew System::EventHandler(this, &Niveles::picNivelUno_MouseLeave);
			this->picNivelUno->MouseHover += gcnew System::EventHandler(this, &Niveles::picNivelUno_MouseHover);
			// 
			// picNivel2
			// 
			this->picNivel2->BackColor = System::Drawing::Color::Transparent;
			this->picNivel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picNivel2.BackgroundImage")));
			this->picNivel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picNivel2->Location = System::Drawing::Point(390, 152);
			this->picNivel2->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picNivel2->Name = L"picNivel2";
			this->picNivel2->Size = System::Drawing::Size(258, 251);
			this->picNivel2->TabIndex = 3;
			this->picNivel2->TabStop = false;
			this->picNivel2->Visible = false;
			this->picNivel2->WaitOnLoad = true;
			this->picNivel2->Click += gcnew System::EventHandler(this, &Niveles::picNivel2_Click);
			this->picNivel2->MouseLeave += gcnew System::EventHandler(this, &Niveles::picNivel2_MouseLeave);
			this->picNivel2->MouseHover += gcnew System::EventHandler(this, &Niveles::picNivel2_MouseHover);
			// 
			// picNivel3
			// 
			this->picNivel3->BackColor = System::Drawing::Color::Transparent;
			this->picNivel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picNivel3.BackgroundImage")));
			this->picNivel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picNivel3->Location = System::Drawing::Point(691, 152);
			this->picNivel3->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picNivel3->Name = L"picNivel3";
			this->picNivel3->Size = System::Drawing::Size(258, 251);
			this->picNivel3->TabIndex = 4;
			this->picNivel3->TabStop = false;
			this->picNivel3->Visible = false;
			this->picNivel3->WaitOnLoad = true;
			this->picNivel3->Click += gcnew System::EventHandler(this, &Niveles::picNivel3_Click);
			this->picNivel3->MouseLeave += gcnew System::EventHandler(this, &Niveles::picNivel3_MouseLeave);
			this->picNivel3->MouseHover += gcnew System::EventHandler(this, &Niveles::picNivel3_MouseHover);
			// 
			// picNivel3E
			// 
			this->picNivel3E->BackColor = System::Drawing::Color::Transparent;
			this->picNivel3E->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picNivel3E.BackgroundImage")));
			this->picNivel3E->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picNivel3E->Enabled = false;
			this->picNivel3E->Location = System::Drawing::Point(691, 152);
			this->picNivel3E->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picNivel3E->Name = L"picNivel3E";
			this->picNivel3E->Size = System::Drawing::Size(258, 251);
			this->picNivel3E->TabIndex = 6;
			this->picNivel3E->TabStop = false;
			this->picNivel3E->WaitOnLoad = true;
			// 
			// picNivel2E
			// 
			this->picNivel2E->BackColor = System::Drawing::Color::Transparent;
			this->picNivel2E->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picNivel2E.BackgroundImage")));
			this->picNivel2E->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picNivel2E->Enabled = false;
			this->picNivel2E->Location = System::Drawing::Point(390, 152);
			this->picNivel2E->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picNivel2E->Name = L"picNivel2E";
			this->picNivel2E->Size = System::Drawing::Size(258, 251);
			this->picNivel2E->TabIndex = 5;
			this->picNivel2E->TabStop = false;
			this->picNivel2E->WaitOnLoad = true;
			// 
			// lblEstrellas
			// 
			this->lblEstrellas->AutoSize = true;
			this->lblEstrellas->BackColor = System::Drawing::Color::Transparent;
			this->lblEstrellas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstrellas->ForeColor = System::Drawing::Color::Black;
			this->lblEstrellas->Location = System::Drawing::Point(538, 35);
			this->lblEstrellas->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->lblEstrellas->Name = L"lblEstrellas";
			this->lblEstrellas->Size = System::Drawing::Size(42, 44);
			this->lblEstrellas->TabIndex = 7;
			this->lblEstrellas->Text = L"0";
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->button3);
			this->panelPrincipal->Controls->Add(this->button1);
			this->panelPrincipal->Controls->Add(this->button2);
			this->panelPrincipal->Controls->Add(this->btnVolver);
			this->panelPrincipal->Controls->Add(this->lblEstrellas);
			this->panelPrincipal->Controls->Add(this->picNivel3E);
			this->panelPrincipal->Controls->Add(this->picNivel2E);
			this->panelPrincipal->Controls->Add(this->picNivel3);
			this->panelPrincipal->Controls->Add(this->picNivel2);
			this->panelPrincipal->Controls->Add(this->picNivelUno);
			this->panelPrincipal->Controls->Add(this->pictureBox1);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 31);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(694, 381);
			this->panelPrincipal->TabIndex = 0;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkGoldenrod;
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(705, 406);
			this->button3->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(235, 51);
			this->button3->TabIndex = 22;
			this->button3->Text = L"Generar Reporte";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkGoldenrod;
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(403, 406);
			this->button1->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(235, 51);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Generar Reporte";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkGoldenrod;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(97, 406);
			this->button2->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(235, 51);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Generar Reporte";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Visible = false;
			// 
			// btnVolver
			// 
			this->btnVolver->BackColor = System::Drawing::Color::Transparent;
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(21, 19);
			this->btnVolver->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(81, 66);
			this->btnVolver->TabIndex = 19;
			this->btnVolver->TabStop = false;
			this->btnVolver->WaitOnLoad = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Niveles::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Niveles::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Niveles::btnVolver_MouseHover);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->picMinimizar);
			this->panel1->Controls->Add(this->picCerrar);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(694, 31);
			this->panel1->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(6, 1);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(31, 28);
			this->pictureBox2->TabIndex = 29;
			this->pictureBox2->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(36, 2);
			this->label6->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(100, 25);
			this->label6->TabIndex = 28;
			this->label6->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(631, 1);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(27, 26);
			this->picMinimizar->TabIndex = 27;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Niveles::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(663, 1);
			this->picCerrar->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(27, 26);
			this->picCerrar->TabIndex = 26;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Niveles::picCerrar_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Niveles::timer1_Tick);
			// 
			// Niveles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(694, 412);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->Name = L"Niveles";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Niveles";
			this->Activated += gcnew System::EventHandler(this, &Niveles::Niveles_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Niveles::Niveles_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Niveles::Niveles_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivelUno))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivel2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivel3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivel3E))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picNivel2E))->EndInit();
			this->panelPrincipal->ResumeLayout(false);
			this->panelPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void inicializarTam();
	private: void inicializarComponentesBD();
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Niveles_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivelUno_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivelUno_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivel2_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivel2_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivel3_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivel3_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivelUno_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivel2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picNivel3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Niveles_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Niveles_Deactivate(System::Object^  sender, System::EventArgs^  e);
	};
}
