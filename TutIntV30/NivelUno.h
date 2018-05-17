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
	/// Resumen de NivelUno
	/// </summary>
	public ref class NivelUno : public System::Windows::Forms::Form
	{
	public:
		NivelUno(void)
		{
			InitializeComponent();
			inicializarTam();
		}
		NivelUno(Form^ f, BaseDeDatos^ manejador)
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
		~NivelUno()
		{
			if (components)
			{
				delete components;
			}
		}
	private: BaseDeDatos ^ manejadorBD;
	private: System::Windows::Forms::Form^ form;
	private: int wUno, hUno, wDos, hDos, wVolver, hVolver;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::PictureBox^  picHab2E;
	private: System::Windows::Forms::PictureBox^  picHab2;
	private: System::Windows::Forms::Label^  lblEstrellas;
	private: System::Windows::Forms::PictureBox^  picHab1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NivelUno::typeid));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->picHab2E = (gcnew System::Windows::Forms::PictureBox());
			this->picHab2 = (gcnew System::Windows::Forms::PictureBox());
			this->lblEstrellas = (gcnew System::Windows::Forms::Label());
			this->picHab1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHab2E))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHab2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHab1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->button2);
			this->panelPrincipal->Controls->Add(this->button1);
			this->panelPrincipal->Controls->Add(this->btnVolver);
			this->panelPrincipal->Controls->Add(this->picHab2E);
			this->panelPrincipal->Controls->Add(this->picHab2);
			this->panelPrincipal->Controls->Add(this->lblEstrellas);
			this->panelPrincipal->Controls->Add(this->picHab1);
			this->panelPrincipal->Controls->Add(this->pictureBox1);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 70);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(2414, 1237);
			this->panelPrincipal->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkGoldenrod;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(1248, 887);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(549, 114);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Generar Reporte";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkGoldenrod;
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(513, 894);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(549, 114);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Generar Reporte";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(43, 44);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(189, 147);
			this->btnVolver->TabIndex = 13;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &NivelUno::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &NivelUno::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &NivelUno::btnVolver_MouseHover);
			// 
			// picHab2E
			// 
			this->picHab2E->BackColor = System::Drawing::Color::Transparent;
			this->picHab2E->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picHab2E.BackgroundImage")));
			this->picHab2E->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picHab2E->Enabled = false;
			this->picHab2E->Location = System::Drawing::Point(1224, 320);
			this->picHab2E->Name = L"picHab2E";
			this->picHab2E->Size = System::Drawing::Size(601, 560);
			this->picHab2E->TabIndex = 12;
			this->picHab2E->TabStop = false;
			this->picHab2E->Visible = true;
			// 
			// picHab2
			// 
			this->picHab2->BackColor = System::Drawing::Color::Transparent;
			this->picHab2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picHab2.BackgroundImage")));
			this->picHab2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picHab2->Location = System::Drawing::Point(1224, 320);
			this->picHab2->Name = L"picHab2";
			this->picHab2->Size = System::Drawing::Size(601, 560);
			this->picHab2->TabIndex = 11;
			this->picHab2->TabStop = false;
			this->picHab2->Visible = false;
			this->picHab2->Click += gcnew System::EventHandler(this, &NivelUno::picHab2_Click);
			this->picHab2->MouseLeave += gcnew System::EventHandler(this, &NivelUno::picHab2_MouseLeave);
			this->picHab2->MouseHover += gcnew System::EventHandler(this, &NivelUno::picHab2_MouseHover);
			// 
			// lblEstrellas
			// 
			this->lblEstrellas->AutoSize = true;
			this->lblEstrellas->BackColor = System::Drawing::Color::Transparent;
			this->lblEstrellas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstrellas->ForeColor = System::Drawing::Color::Black;
			this->lblEstrellas->Location = System::Drawing::Point(1186, 78);
			this->lblEstrellas->Name = L"lblEstrellas";
			this->lblEstrellas->Size = System::Drawing::Size(88, 96);
			this->lblEstrellas->TabIndex = 10;
			this->lblEstrellas->Text = L"0";
			// 
			// picHab1
			// 
			this->picHab1->BackColor = System::Drawing::Color::Transparent;
			this->picHab1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picHab1.BackgroundImage")));
			this->picHab1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picHab1->Location = System::Drawing::Point(492, 320);
			this->picHab1->Name = L"picHab1";
			this->picHab1->Size = System::Drawing::Size(601, 560);
			this->picHab1->TabIndex = 9;
			this->picHab1->TabStop = false;
			this->picHab1->Click += gcnew System::EventHandler(this, &NivelUno::picHab1_Click);
			this->picHab1->MouseLeave += gcnew System::EventHandler(this, &NivelUno::picHab1_MouseLeave);
			this->picHab1->MouseHover += gcnew System::EventHandler(this, &NivelUno::picHab1_MouseHover);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(997, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(183, 171);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
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
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(2414, 70);
			this->panel1->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(12, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(72, 63);
			this->pictureBox2->TabIndex = 33;
			this->pictureBox2->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(81, 7);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(212, 55);
			this->label6->TabIndex = 32;
			this->label6->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(2264, 5);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(64, 59);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &NivelUno::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(2339, 5);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(64, 59);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &NivelUno::picCerrar_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &NivelUno::timer1_Tick);
			// 
			// NivelUno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(2414, 1307);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"NivelUno";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NivelUno";
			this->Activated += gcnew System::EventHandler(this, &NivelUno::NivelUno_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &NivelUno::NivelUno_Deactivate);
			this->Load += gcnew System::EventHandler(this, &NivelUno::NivelUno_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->panelPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHab2E))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHab2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHab1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
	private: System::Void picHab1_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picHab1_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picHab2_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picHab2_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picHab1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picHab2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NivelUno_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NivelUno_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NivelUno_Deactivate(System::Object^  sender, System::EventArgs^  e);
	};
}
