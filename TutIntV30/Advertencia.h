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
	/// Resumen de Advertencia
	/// </summary>
	public ref class Advertencia : public System::Windows::Forms::Form
	{
	public:
		Advertencia(void)
		{
			InitializeComponent();
		}
		Advertencia(String^ form, Form^ f, bool salirNivel, BaseDeDatos^ manejador)
		{
			nombreForm = form;
			formAbierto = f;
			salir = salirNivel;
			manejadorBD = manejador;
			InitializeComponent();
			inicializarLabel();
			inicializarTam();
		}
		Advertencia(Form^ f, bool salirNivel, BaseDeDatos^ manejador)
		{
			formAbierto = f;
			salir = salirNivel;
			manejadorBD = manejador;
			InitializeComponent();
			inicializarLabel();
			inicializarTam();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Advertencia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: BaseDeDatos ^ manejadorBD;
	private: int wSi, hSi, wNo, hNo;
	private: bool salir;
	private: String ^ nombreForm;
	private: System::Windows::Forms::Form^ formAbierto;
	private: System::Windows::Forms::PictureBox^  picSalirPartida;
	private: System::Windows::Forms::PictureBox^  btnSi;
	private: System::Windows::Forms::PictureBox^  btnNo;
	private: System::Windows::Forms::PictureBox^  picSalirAct;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  picCerrar;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Advertencia::typeid));
			this->picSalirPartida = (gcnew System::Windows::Forms::PictureBox());
			this->btnSi = (gcnew System::Windows::Forms::PictureBox());
			this->btnNo = (gcnew System::Windows::Forms::PictureBox());
			this->picSalirAct = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSalirPartida))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSi))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnNo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSalirAct))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// picSalirPartida
			// 
			this->picSalirPartida->BackColor = System::Drawing::Color::Transparent;
			this->picSalirPartida->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picSalirPartida.BackgroundImage")));
			this->picSalirPartida->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picSalirPartida->Location = System::Drawing::Point(89, 7);
			this->picSalirPartida->Name = L"picSalirPartida";
			this->picSalirPartida->Size = System::Drawing::Size(1013, 276);
			this->picSalirPartida->TabIndex = 0;
			this->picSalirPartida->TabStop = false;
			this->picSalirPartida->WaitOnLoad = true;
			// 
			// btnSi
			// 
			this->btnSi->BackColor = System::Drawing::Color::Transparent;
			this->btnSi->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSi.BackgroundImage")));
			this->btnSi->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSi->Location = System::Drawing::Point(215, 290);
			this->btnSi->Name = L"btnSi";
			this->btnSi->Size = System::Drawing::Size(349, 140);
			this->btnSi->TabIndex = 1;
			this->btnSi->TabStop = false;
			this->btnSi->WaitOnLoad = true;
			this->btnSi->Click += gcnew System::EventHandler(this, &Advertencia::btnSi_Click);
			this->btnSi->MouseLeave += gcnew System::EventHandler(this, &Advertencia::btnSi_MouseLeave);
			this->btnSi->MouseHover += gcnew System::EventHandler(this, &Advertencia::btnSi_MouseHover);
			// 
			// btnNo
			// 
			this->btnNo->BackColor = System::Drawing::Color::Transparent;
			this->btnNo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNo.BackgroundImage")));
			this->btnNo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNo->Location = System::Drawing::Point(642, 290);
			this->btnNo->Name = L"btnNo";
			this->btnNo->Size = System::Drawing::Size(349, 140);
			this->btnNo->TabIndex = 2;
			this->btnNo->TabStop = false;
			this->btnNo->WaitOnLoad = true;
			this->btnNo->Click += gcnew System::EventHandler(this, &Advertencia::btnNo_Click);
			this->btnNo->MouseLeave += gcnew System::EventHandler(this, &Advertencia::btnNo_MouseLeave);
			this->btnNo->MouseHover += gcnew System::EventHandler(this, &Advertencia::btnNo_MouseHover);
			// 
			// picSalirAct
			// 
			this->picSalirAct->BackColor = System::Drawing::Color::Transparent;
			this->picSalirAct->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picSalirAct.BackgroundImage")));
			this->picSalirAct->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picSalirAct->Location = System::Drawing::Point(28, 26);
			this->picSalirAct->Name = L"picSalirAct";
			this->picSalirAct->Size = System::Drawing::Size(1156, 245);
			this->picSalirAct->TabIndex = 3;
			this->picSalirAct->TabStop = false;
			this->picSalirAct->Visible = false;
			this->picSalirAct->WaitOnLoad = true;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Advertencia::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->picSalirAct);
			this->panel1->Controls->Add(this->btnNo);
			this->panel1->Controls->Add(this->btnSi);
			this->panel1->Controls->Add(this->picSalirPartida);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 65);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1216, 434);
			this->panel1->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->Controls->Add(this->picCerrar);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1216, 65);
			this->panel2->TabIndex = 5;
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(1146, 3);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(64, 59);
			this->picCerrar->TabIndex = 27;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Advertencia::picCerrar_Click);
			// 
			// Advertencia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1216, 499);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Advertencia";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Advertencia";
			this->Load += gcnew System::EventHandler(this, &Advertencia::Advertencia_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSalirPartida))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSi))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnNo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSalirAct))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void inicializarTam();
	private: void inicializarLabel();
	private: System::Void btnSi_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnNo_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSi_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSi_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnNo_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnNo_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Advertencia_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	};
}
