#pragma once
#include "BaseDeDatos.h"
#include "AgenteControlador.h"
#include "Recuperacion.h"
#include <msclr\marshal.h>

namespace TutIntV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Resumen de PrincipalUno
	/// </summary>
	public ref class PrincipalUno : public System::Windows::Forms::Form
	{
	public:
		PrincipalUno(void)
		{
			InitializeComponent();
			inicializarTamBotones();
		}

		PrincipalUno(Form^ f, BaseDeDatos^ manejador)
		{
			form = f;
			manejadorBD = manejador;
			recuperacion = new Recuperacion();
			InitializeComponent();
			inicializarTamBotones();
			inicializarComponentesBD();
			this->Size = System::Drawing::Size(1050, 598);
			this->Show();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PrincipalUno()
		{
			if (components)
			{
				delete components;
			}
		}

	private: marshal_context ^ context;
	private: int numAct;
	private: int salir;
	private: BaseDeDatos ^ manejadorBD;
	private: AgenteControlador * controlador;
	private: Recuperacion * recuperacion;
	private: int hMarlin, wMarlin, hDory, wDory, wTiburones, hTiburones, hTortugas, wTortugas, wNemo, hNemo, wVolver, hVolver, wTortuH, hTortuH, wPulpo, hPulpo, wPezAma, hPezAma, hPezGlobo, wPezGlobo;
	private: System::Windows::Forms::Form^ form;
	private: System::Windows::Forms::PictureBox^  btnMarlin;
	private: System::Windows::Forms::PictureBox^  btnDory;
	private: System::Windows::Forms::PictureBox^  btnTiburones;
	private: System::Windows::Forms::PictureBox^  btnTortugas;
	private: System::Windows::Forms::PictureBox^  btnNemo;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Label^  lblEstrellas;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  btnMarlinD;
	private: System::Windows::Forms::PictureBox^  btnNemoD;
	private: System::Windows::Forms::PictureBox^  btnTortugasD;
	private: System::Windows::Forms::PictureBox^  btnTiburonesD;
	private: System::Windows::Forms::PictureBox^  btnDoryD;
	private: System::Windows::Forms::PictureBox^  btnPlay;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  btnTortu;
	private: System::Windows::Forms::PictureBox^  btnTortuD;
	private: System::Windows::Forms::PictureBox^  btnPulpoD;
	private: System::Windows::Forms::PictureBox^  btnPulpo;
	private: System::Windows::Forms::PictureBox^  btnPezAmaD;
	private: System::Windows::Forms::PictureBox^  btnPezAma;
	private: System::Windows::Forms::PictureBox^  btnPezGloD;
	private: System::Windows::Forms::PictureBox^  btnPezGlo;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PrincipalUno::typeid));
			this->btnMarlin = (gcnew System::Windows::Forms::PictureBox());
			this->btnDory = (gcnew System::Windows::Forms::PictureBox());
			this->btnTiburones = (gcnew System::Windows::Forms::PictureBox());
			this->btnTortugas = (gcnew System::Windows::Forms::PictureBox());
			this->btnNemo = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->btnPezGloD = (gcnew System::Windows::Forms::PictureBox());
			this->btnPezGlo = (gcnew System::Windows::Forms::PictureBox());
			this->btnPezAmaD = (gcnew System::Windows::Forms::PictureBox());
			this->btnPezAma = (gcnew System::Windows::Forms::PictureBox());
			this->btnPulpoD = (gcnew System::Windows::Forms::PictureBox());
			this->btnPulpo = (gcnew System::Windows::Forms::PictureBox());
			this->btnTortuD = (gcnew System::Windows::Forms::PictureBox());
			this->btnTortu = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlay = (gcnew System::Windows::Forms::PictureBox());
			this->btnNemoD = (gcnew System::Windows::Forms::PictureBox());
			this->btnTortugasD = (gcnew System::Windows::Forms::PictureBox());
			this->btnTiburonesD = (gcnew System::Windows::Forms::PictureBox());
			this->btnDoryD = (gcnew System::Windows::Forms::PictureBox());
			this->btnMarlinD = (gcnew System::Windows::Forms::PictureBox());
			this->lblEstrellas = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMarlin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDory))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTiburones))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTortugas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnNemo))->BeginInit();
			this->panelPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPezGloD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPezGlo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPezAmaD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPezAma))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPulpoD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPulpo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTortuD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTortu))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnNemoD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTortugasD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTiburonesD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDoryD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMarlinD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// btnMarlin
			// 
			this->btnMarlin->BackColor = System::Drawing::Color::Transparent;
			this->btnMarlin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMarlin.BackgroundImage")));
			this->btnMarlin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnMarlin->Location = System::Drawing::Point(331, 19);
			this->btnMarlin->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMarlin->Name = L"btnMarlin";
			this->btnMarlin->Size = System::Drawing::Size(222, 168);
			this->btnMarlin->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnMarlin->TabIndex = 0;
			this->btnMarlin->TabStop = false;
			this->btnMarlin->WaitOnLoad = true;
			// 
			// btnDory
			// 
			this->btnDory->BackColor = System::Drawing::Color::Transparent;
			this->btnDory->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDory.BackgroundImage")));
			this->btnDory->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDory->Location = System::Drawing::Point(100, 399);
			this->btnDory->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDory->Name = L"btnDory";
			this->btnDory->Size = System::Drawing::Size(186, 150);
			this->btnDory->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnDory->TabIndex = 1;
			this->btnDory->TabStop = false;
			this->btnDory->WaitOnLoad = true;
			// 
			// btnTiburones
			// 
			this->btnTiburones->BackColor = System::Drawing::Color::Transparent;
			this->btnTiburones->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTiburones.BackgroundImage")));
			this->btnTiburones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTiburones->Location = System::Drawing::Point(751, 22);
			this->btnTiburones->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnTiburones->Name = L"btnTiburones";
			this->btnTiburones->Size = System::Drawing::Size(375, 224);
			this->btnTiburones->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnTiburones->TabIndex = 2;
			this->btnTiburones->TabStop = false;
			this->btnTiburones->WaitOnLoad = true;
			// 
			// btnTortugas
			// 
			this->btnTortugas->BackColor = System::Drawing::Color::Transparent;
			this->btnTortugas->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTortugas.BackgroundImage")));
			this->btnTortugas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTortugas->Location = System::Drawing::Point(59, 139);
			this->btnTortugas->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnTortugas->Name = L"btnTortugas";
			this->btnTortugas->Size = System::Drawing::Size(259, 212);
			this->btnTortugas->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnTortugas->TabIndex = 3;
			this->btnTortugas->TabStop = false;
			this->btnTortugas->WaitOnLoad = true;
			// 
			// btnNemo
			// 
			this->btnNemo->BackColor = System::Drawing::Color::Transparent;
			this->btnNemo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNemo.BackgroundImage")));
			this->btnNemo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNemo->Location = System::Drawing::Point(673, 298);
			this->btnNemo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnNemo->Name = L"btnNemo";
			this->btnNemo->Size = System::Drawing::Size(254, 152);
			this->btnNemo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnNemo->TabIndex = 4;
			this->btnNemo->TabStop = false;
			this->btnNemo->WaitOnLoad = true;
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->btnPezGloD);
			this->panelPrincipal->Controls->Add(this->btnPezGlo);
			this->panelPrincipal->Controls->Add(this->btnPezAmaD);
			this->panelPrincipal->Controls->Add(this->btnPezAma);
			this->panelPrincipal->Controls->Add(this->btnPulpoD);
			this->panelPrincipal->Controls->Add(this->btnPulpo);
			this->panelPrincipal->Controls->Add(this->btnTortuD);
			this->panelPrincipal->Controls->Add(this->btnTortu);
			this->panelPrincipal->Controls->Add(this->btnPlay);
			this->panelPrincipal->Controls->Add(this->btnNemoD);
			this->panelPrincipal->Controls->Add(this->btnTortugasD);
			this->panelPrincipal->Controls->Add(this->btnTiburonesD);
			this->panelPrincipal->Controls->Add(this->btnDoryD);
			this->panelPrincipal->Controls->Add(this->btnMarlinD);
			this->panelPrincipal->Controls->Add(this->lblEstrellas);
			this->panelPrincipal->Controls->Add(this->pictureBox1);
			this->panelPrincipal->Controls->Add(this->btnVolver);
			this->panelPrincipal->Controls->Add(this->btnNemo);
			this->panelPrincipal->Controls->Add(this->btnTortugas);
			this->panelPrincipal->Controls->Add(this->btnTiburones);
			this->panelPrincipal->Controls->Add(this->btnDory);
			this->panelPrincipal->Controls->Add(this->btnMarlin);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 39);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(1395, 680);
			this->panelPrincipal->TabIndex = 0;
			// 
			// btnPezGloD
			// 
			this->btnPezGloD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPezGloD.BackgroundImage")));
			this->btnPezGloD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPezGloD->Enabled = false;
			this->btnPezGloD->Location = System::Drawing::Point(947, 447);
			this->btnPezGloD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPezGloD->Name = L"btnPezGloD";
			this->btnPezGloD->Size = System::Drawing::Size(284, 204);
			this->btnPezGloD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPezGloD->TabIndex = 26;
			this->btnPezGloD->TabStop = false;
			this->btnPezGloD->Visible = false;
			this->btnPezGloD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnPezGloD_Click);
			this->btnPezGloD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnPezGloD_MouseLeave);
			this->btnPezGloD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnPezGloD_MouseHover);
			// 
			// btnPezGlo
			// 
			this->btnPezGlo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPezGlo.BackgroundImage")));
			this->btnPezGlo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPezGlo->Location = System::Drawing::Point(947, 450);
			this->btnPezGlo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPezGlo->Name = L"btnPezGlo";
			this->btnPezGlo->Size = System::Drawing::Size(284, 204);
			this->btnPezGlo->TabIndex = 25;
			this->btnPezGlo->TabStop = false;
			// 
			// btnPezAmaD
			// 
			this->btnPezAmaD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPezAmaD.BackgroundImage")));
			this->btnPezAmaD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPezAmaD->Enabled = false;
			this->btnPezAmaD->Location = System::Drawing::Point(467, 468);
			this->btnPezAmaD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPezAmaD->Name = L"btnPezAmaD";
			this->btnPezAmaD->Size = System::Drawing::Size(266, 178);
			this->btnPezAmaD->TabIndex = 24;
			this->btnPezAmaD->TabStop = false;
			this->btnPezAmaD->Visible = false;
			this->btnPezAmaD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnPezAmaD_Click);
			this->btnPezAmaD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnPezAmaD_MouseLeave);
			this->btnPezAmaD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnPezAmaD_MouseHover);
			// 
			// btnPezAma
			// 
			this->btnPezAma->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPezAma.BackgroundImage")));
			this->btnPezAma->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPezAma->Location = System::Drawing::Point(467, 471);
			this->btnPezAma->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPezAma->Name = L"btnPezAma";
			this->btnPezAma->Size = System::Drawing::Size(266, 178);
			this->btnPezAma->TabIndex = 23;
			this->btnPezAma->TabStop = false;
			// 
			// btnPulpoD
			// 
			this->btnPulpoD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPulpoD.BackgroundImage")));
			this->btnPulpoD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPulpoD->Enabled = false;
			this->btnPulpoD->Location = System::Drawing::Point(1155, 248);
			this->btnPulpoD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPulpoD->Name = L"btnPulpoD";
			this->btnPulpoD->Size = System::Drawing::Size(196, 220);
			this->btnPulpoD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPulpoD->TabIndex = 22;
			this->btnPulpoD->TabStop = false;
			this->btnPulpoD->Visible = false;
			this->btnPulpoD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnPulpoD_Click);
			this->btnPulpoD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnPulpoD_MouseLeave);
			this->btnPulpoD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnPulpoD_MouseHover);
			// 
			// btnPulpo
			// 
			this->btnPulpo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPulpo.BackgroundImage")));
			this->btnPulpo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPulpo->Location = System::Drawing::Point(1155, 250);
			this->btnPulpo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPulpo->Name = L"btnPulpo";
			this->btnPulpo->Size = System::Drawing::Size(196, 220);
			this->btnPulpo->TabIndex = 21;
			this->btnPulpo->TabStop = false;
			// 
			// btnTortuD
			// 
			this->btnTortuD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTortuD.BackgroundImage")));
			this->btnTortuD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTortuD->Enabled = false;
			this->btnTortuD->Location = System::Drawing::Point(375, 280);
			this->btnTortuD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnTortuD->Name = L"btnTortuD";
			this->btnTortuD->Size = System::Drawing::Size(252, 196);
			this->btnTortuD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnTortuD->TabIndex = 20;
			this->btnTortuD->TabStop = false;
			this->btnTortuD->Visible = false;
			this->btnTortuD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnTortuD_Click);
			this->btnTortuD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnTortuD_MouseLeave);
			this->btnTortuD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnTortuD_MouseHover);
			// 
			// btnTortu
			// 
			this->btnTortu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTortu.BackgroundImage")));
			this->btnTortu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTortu->Location = System::Drawing::Point(397, 282);
			this->btnTortu->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnTortu->Name = L"btnTortu";
			this->btnTortu->Size = System::Drawing::Size(231, 168);
			this->btnTortu->TabIndex = 19;
			this->btnTortu->TabStop = false;
			// 
			// btnPlay
			// 
			this->btnPlay->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPlay.BackgroundImage")));
			this->btnPlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPlay->Location = System::Drawing::Point(1271, 122);
			this->btnPlay->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(101, 82);
			this->btnPlay->TabIndex = 18;
			this->btnPlay->TabStop = false;
			this->btnPlay->WaitOnLoad = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &PrincipalUno::btnPlay_Click);
			// 
			// btnNemoD
			// 
			this->btnNemoD->BackColor = System::Drawing::Color::Transparent;
			this->btnNemoD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNemoD.BackgroundImage")));
			this->btnNemoD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNemoD->Enabled = false;
			this->btnNemoD->Location = System::Drawing::Point(673, 296);
			this->btnNemoD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnNemoD->Name = L"btnNemoD";
			this->btnNemoD->Size = System::Drawing::Size(259, 233);
			this->btnNemoD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnNemoD->TabIndex = 17;
			this->btnNemoD->TabStop = false;
			this->btnNemoD->Visible = false;
			this->btnNemoD->WaitOnLoad = true;
			this->btnNemoD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnNemoD_Click);
			this->btnNemoD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnNemoD_MouseLeave);
			this->btnNemoD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnNemoD_MouseHover);
			// 
			// btnTortugasD
			// 
			this->btnTortugasD->BackColor = System::Drawing::Color::Transparent;
			this->btnTortugasD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTortugasD.BackgroundImage")));
			this->btnTortugasD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTortugasD->Enabled = false;
			this->btnTortugasD->Location = System::Drawing::Point(59, 137);
			this->btnTortugasD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnTortugasD->Name = L"btnTortugasD";
			this->btnTortugasD->Size = System::Drawing::Size(259, 212);
			this->btnTortugasD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnTortugasD->TabIndex = 16;
			this->btnTortugasD->TabStop = false;
			this->btnTortugasD->Visible = false;
			this->btnTortugasD->WaitOnLoad = true;
			this->btnTortugasD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnTortugasD_Click);
			this->btnTortugasD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnTortugasD_MouseLeave);
			this->btnTortugasD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnTortugasD_MouseHover);
			// 
			// btnTiburonesD
			// 
			this->btnTiburonesD->BackColor = System::Drawing::Color::Transparent;
			this->btnTiburonesD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTiburonesD.BackgroundImage")));
			this->btnTiburonesD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTiburonesD->Enabled = false;
			this->btnTiburonesD->Location = System::Drawing::Point(751, 19);
			this->btnTiburonesD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnTiburonesD->Name = L"btnTiburonesD";
			this->btnTiburonesD->Size = System::Drawing::Size(375, 226);
			this->btnTiburonesD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnTiburonesD->TabIndex = 15;
			this->btnTiburonesD->TabStop = false;
			this->btnTiburonesD->Visible = false;
			this->btnTiburonesD->WaitOnLoad = true;
			this->btnTiburonesD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnTiburonesD_Click);
			this->btnTiburonesD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnTiburonesD_MouseLeave);
			this->btnTiburonesD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnTiburonesD_MouseHover);
			// 
			// btnDoryD
			// 
			this->btnDoryD->BackColor = System::Drawing::Color::Transparent;
			this->btnDoryD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDoryD.BackgroundImage")));
			this->btnDoryD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDoryD->Enabled = false;
			this->btnDoryD->Location = System::Drawing::Point(7, 397);
			this->btnDoryD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDoryD->Name = L"btnDoryD";
			this->btnDoryD->Size = System::Drawing::Size(279, 259);
			this->btnDoryD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnDoryD->TabIndex = 14;
			this->btnDoryD->TabStop = false;
			this->btnDoryD->Visible = false;
			this->btnDoryD->WaitOnLoad = true;
			this->btnDoryD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnDoryD_Click);
			this->btnDoryD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnDoryD_MouseLeave);
			this->btnDoryD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnDoryD_MouseHover);
			// 
			// btnMarlinD
			// 
			this->btnMarlinD->BackColor = System::Drawing::Color::Transparent;
			this->btnMarlinD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMarlinD.BackgroundImage")));
			this->btnMarlinD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnMarlinD->Enabled = false;
			this->btnMarlinD->Location = System::Drawing::Point(331, 17);
			this->btnMarlinD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMarlinD->Name = L"btnMarlinD";
			this->btnMarlinD->Size = System::Drawing::Size(297, 252);
			this->btnMarlinD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnMarlinD->TabIndex = 13;
			this->btnMarlinD->TabStop = false;
			this->btnMarlinD->Visible = false;
			this->btnMarlinD->WaitOnLoad = true;
			this->btnMarlinD->Click += gcnew System::EventHandler(this, &PrincipalUno::btnMarlinD_Click);
			this->btnMarlinD->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnMarlinD_MouseLeave);
			this->btnMarlinD->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnMarlinD_MouseHover);
			// 
			// lblEstrellas
			// 
			this->lblEstrellas->AutoSize = true;
			this->lblEstrellas->BackColor = System::Drawing::Color::Transparent;
			this->lblEstrellas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstrellas->ForeColor = System::Drawing::Color::White;
			this->lblEstrellas->Location = System::Drawing::Point(1217, 36);
			this->lblEstrellas->Name = L"lblEstrellas";
			this->lblEstrellas->Size = System::Drawing::Size(50, 54);
			this->lblEstrellas->TabIndex = 12;
			this->lblEstrellas->Text = L"0";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(1271, 14);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(105, 94);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(5, 7);
			this->btnVolver->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(93, 70);
			this->btnVolver->TabIndex = 9;
			this->btnVolver->TabStop = false;
			this->btnVolver->WaitOnLoad = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &PrincipalUno::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &PrincipalUno::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &PrincipalUno::btnVolver_MouseHover);
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
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1395, 39);
			this->panel1->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(7, 2);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(41, 34);
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
			this->label6->Location = System::Drawing::Point(45, 4);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(124, 31);
			this->label6->TabIndex = 32;
			this->label6->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(1310, 2);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(37, 33);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &PrincipalUno::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(1352, 2);
			this->picCerrar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(37, 33);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &PrincipalUno::picCerrar_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &PrincipalUno::timer1_Tick);
			// 
			// PrincipalUno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1395, 719);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"PrincipalUno";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PrincipalUno";
			this->Activated += gcnew System::EventHandler(this, &PrincipalUno::PrincipalUno_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &PrincipalUno::PrincipalUno_Deactivate);
			this->Load += gcnew System::EventHandler(this, &PrincipalUno::PrincipalUno_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMarlin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDory))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTiburones))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTortugas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnNemo))->EndInit();
			this->panelPrincipal->ResumeLayout(false);
			this->panelPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPezGloD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPezGlo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPezAmaD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPezAma))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPulpoD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPulpo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTortuD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTortu))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnNemoD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTortugasD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTiburonesD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDoryD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMarlinD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void SonidoInicio();
	private: void SonidoDory();
	private: void SonidoTiburones();
	private: void SonidoTortugas();
	private: void SonidoNemo();
	private: void SonidoNemoPapa();
	private: void SonidoPulpo();
	private: void SonidoPezAma();
	private: void SonidoPezGlobo();
	private: void SonidoTortu();
	private: void SonidoInicial();

	private: void inicializarTamBotones();
	private: void inicializarComponentesBD();
	private: void cargarActBB();		// Dificultad Basica, Complejidad Basica
	private: void cargarActBI();
	private: void cargarActBD();
	private: void cargarActIB();
	private: void cargarActII();
	private: void cargarActID();
	private: void cargarActDB();
	private: void cargarActDI();
	private: void cargarActDD();

	private: System::Void btnPulpoD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPulpoD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTortuD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTortuD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPezGloD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPezGloD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPezAmaD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPezAmaD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnMarlinD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnMarlinD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDoryD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDoryD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTiburonesD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTiburonesD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTortugasD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTortugasD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnNemoD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnNemoD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);

	private: System::Void btnPulpoD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTortuD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPezGloD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPezAmaD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnMarlinD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDoryD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTiburonesD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTortugasD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnNemoD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalUno_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalUno_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalUno_Deactivate(System::Object^  sender, System::EventArgs^  e);
	};
}
