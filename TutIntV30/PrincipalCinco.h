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
	/// Resumen de PrincipalCinco
	/// </summary>
	public ref class PrincipalCinco : public System::Windows::Forms::Form
	{
	public:
		PrincipalCinco(void)
		{
			InitializeComponent();
		}
		PrincipalCinco(Form^ f, BaseDeDatos^ manejador)
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
		~PrincipalCinco()
		{
			if (components)
			{
				delete components;
			}
		}
	private: BaseDeDatos ^ manejadorBD;
	private: System::Windows::Forms::Form^ form;
	private: int wVolver, hVolver, wUno, hUno, wDos, hDos, wTres, hTres, wCuatro, hCuatro, wCinco, hCinco, wSeis, hSeis, wSiete, hSiete;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::Label^  lblEstrellas;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  btnDos;
	private: System::Windows::Forms::PictureBox^  btnUno;
	private: System::Windows::Forms::PictureBox^  btnDosE;
	private: System::Windows::Forms::PictureBox^  btnDosD;
	private: System::Windows::Forms::PictureBox^  btnUnoD;
	private: System::Windows::Forms::PictureBox^  btnTres;
	private: System::Windows::Forms::PictureBox^  btnTresD;
	private: System::Windows::Forms::PictureBox^  btnTresE;
	private: System::Windows::Forms::PictureBox^  btnSeisD;
	private: System::Windows::Forms::PictureBox^  btnSeis;
	private: System::Windows::Forms::PictureBox^  btnSeisE;
	private: System::Windows::Forms::PictureBox^  btnSieteE;
	private: System::Windows::Forms::PictureBox^  btnSieteD;
	private: System::Windows::Forms::PictureBox^  btnSiete;
	private: System::Windows::Forms::PictureBox^  btnCuatroE;
	private: System::Windows::Forms::PictureBox^  btnCincoE;
	private: System::Windows::Forms::PictureBox^  btnCincoD;
	private: System::Windows::Forms::PictureBox^  btnCuatroD;
	private: System::Windows::Forms::PictureBox^  btnCinco;
	private: System::Windows::Forms::PictureBox^  btnCuatro;
	private: System::Windows::Forms::PictureBox^  btnPlay;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PrincipalCinco::typeid));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->btnPlay = (gcnew System::Windows::Forms::PictureBox());
			this->btnCuatroE = (gcnew System::Windows::Forms::PictureBox());
			this->btnCincoE = (gcnew System::Windows::Forms::PictureBox());
			this->btnCincoD = (gcnew System::Windows::Forms::PictureBox());
			this->btnCuatroD = (gcnew System::Windows::Forms::PictureBox());
			this->btnCinco = (gcnew System::Windows::Forms::PictureBox());
			this->btnCuatro = (gcnew System::Windows::Forms::PictureBox());
			this->btnSieteE = (gcnew System::Windows::Forms::PictureBox());
			this->btnSieteD = (gcnew System::Windows::Forms::PictureBox());
			this->btnSiete = (gcnew System::Windows::Forms::PictureBox());
			this->btnSeisE = (gcnew System::Windows::Forms::PictureBox());
			this->btnSeisD = (gcnew System::Windows::Forms::PictureBox());
			this->btnSeis = (gcnew System::Windows::Forms::PictureBox());
			this->btnTresE = (gcnew System::Windows::Forms::PictureBox());
			this->btnTresD = (gcnew System::Windows::Forms::PictureBox());
			this->btnTres = (gcnew System::Windows::Forms::PictureBox());
			this->btnDosE = (gcnew System::Windows::Forms::PictureBox());
			this->btnDosD = (gcnew System::Windows::Forms::PictureBox());
			this->btnUnoD = (gcnew System::Windows::Forms::PictureBox());
			this->btnDos = (gcnew System::Windows::Forms::PictureBox());
			this->btnUno = (gcnew System::Windows::Forms::PictureBox());
			this->lblEstrellas = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatroE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCincoE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCincoD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatroD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCinco))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSieteE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSieteD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSiete))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeisE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeisD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTresE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTresD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTres))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDosE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDosD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnUnoD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnUno))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
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
			this->panelPrincipal->Controls->Add(this->btnPlay);
			this->panelPrincipal->Controls->Add(this->btnCuatroE);
			this->panelPrincipal->Controls->Add(this->btnCincoE);
			this->panelPrincipal->Controls->Add(this->btnCincoD);
			this->panelPrincipal->Controls->Add(this->btnCuatroD);
			this->panelPrincipal->Controls->Add(this->btnCinco);
			this->panelPrincipal->Controls->Add(this->btnCuatro);
			this->panelPrincipal->Controls->Add(this->btnSieteE);
			this->panelPrincipal->Controls->Add(this->btnSieteD);
			this->panelPrincipal->Controls->Add(this->btnSiete);
			this->panelPrincipal->Controls->Add(this->btnSeisE);
			this->panelPrincipal->Controls->Add(this->btnSeisD);
			this->panelPrincipal->Controls->Add(this->btnSeis);
			this->panelPrincipal->Controls->Add(this->btnTresE);
			this->panelPrincipal->Controls->Add(this->btnTresD);
			this->panelPrincipal->Controls->Add(this->btnTres);
			this->panelPrincipal->Controls->Add(this->btnDosE);
			this->panelPrincipal->Controls->Add(this->btnDosD);
			this->panelPrincipal->Controls->Add(this->btnUnoD);
			this->panelPrincipal->Controls->Add(this->btnDos);
			this->panelPrincipal->Controls->Add(this->btnUno);
			this->panelPrincipal->Controls->Add(this->lblEstrellas);
			this->panelPrincipal->Controls->Add(this->btnVolver);
			this->panelPrincipal->Controls->Add(this->pictureBox7);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 70);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(2414, 1237);
			this->panelPrincipal->TabIndex = 0;
			// 
			// btnPlay
			// 
			this->btnPlay->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPlay.BackgroundImage")));
			this->btnPlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPlay->Location = System::Drawing::Point(203, 10);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(134, 114);
			this->btnPlay->TabIndex = 21;
			this->btnPlay->TabStop = false;
			this->btnPlay->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnPlay_Click);
			// 
			// btnCuatroE
			// 
			this->btnCuatroE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCuatroE.BackgroundImage")));
			this->btnCuatroE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCuatroE->Location = System::Drawing::Point(737, 666);
			this->btnCuatroE->Name = L"btnCuatroE";
			this->btnCuatroE->Size = System::Drawing::Size(467, 428);
			this->btnCuatroE->TabIndex = 45;
			this->btnCuatroE->TabStop = false;
			// 
			// btnCincoE
			// 
			this->btnCincoE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCincoE.BackgroundImage")));
			this->btnCincoE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCincoE->Location = System::Drawing::Point(1431, 619);
			this->btnCincoE->Name = L"btnCincoE";
			this->btnCincoE->Size = System::Drawing::Size(467, 450);
			this->btnCincoE->TabIndex = 44;
			this->btnCincoE->TabStop = false;
			// 
			// btnCincoD
			// 
			this->btnCincoD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCincoD.BackgroundImage")));
			this->btnCincoD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCincoD->Location = System::Drawing::Point(1431, 619);
			this->btnCincoD->Name = L"btnCincoD";
			this->btnCincoD->Size = System::Drawing::Size(467, 450);
			this->btnCincoD->TabIndex = 43;
			this->btnCincoD->TabStop = false;
			this->btnCincoD->Visible = false;
			this->btnCincoD->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnCincoD_Click);
			this->btnCincoD->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnCincoD_MouseLeave);
			this->btnCincoD->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnCincoD_MouseHover);
			// 
			// btnCuatroD
			// 
			this->btnCuatroD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCuatroD.BackgroundImage")));
			this->btnCuatroD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCuatroD->Location = System::Drawing::Point(737, 666);
			this->btnCuatroD->Name = L"btnCuatroD";
			this->btnCuatroD->Size = System::Drawing::Size(467, 428);
			this->btnCuatroD->TabIndex = 42;
			this->btnCuatroD->TabStop = false;
			this->btnCuatroD->Visible = false;
			this->btnCuatroD->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnCuatroD_Click);
			this->btnCuatroD->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnCuatroD_MouseLeave);
			this->btnCuatroD->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnCuatroD_MouseHover);
			// 
			// btnCinco
			// 
			this->btnCinco->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCinco.BackgroundImage")));
			this->btnCinco->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCinco->Location = System::Drawing::Point(1431, 619);
			this->btnCinco->Name = L"btnCinco";
			this->btnCinco->Size = System::Drawing::Size(467, 450);
			this->btnCinco->TabIndex = 41;
			this->btnCinco->TabStop = false;
			this->btnCinco->Visible = false;
			this->btnCinco->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnCinco_Click);
			this->btnCinco->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnCinco_MouseLeave);
			this->btnCinco->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnCinco_MouseHover);
			// 
			// btnCuatro
			// 
			this->btnCuatro->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCuatro.BackgroundImage")));
			this->btnCuatro->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCuatro->Location = System::Drawing::Point(737, 666);
			this->btnCuatro->Name = L"btnCuatro";
			this->btnCuatro->Size = System::Drawing::Size(467, 428);
			this->btnCuatro->TabIndex = 40;
			this->btnCuatro->TabStop = false;
			this->btnCuatro->Visible = false;
			this->btnCuatro->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnCuatro_Click);
			this->btnCuatro->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnCuatro_MouseLeave);
			this->btnCuatro->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnCuatro_MouseHover);
			// 
			// btnSieteE
			// 
			this->btnSieteE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSieteE.BackgroundImage")));
			this->btnSieteE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSieteE->Location = System::Drawing::Point(1608, 75);
			this->btnSieteE->Name = L"btnSieteE";
			this->btnSieteE->Size = System::Drawing::Size(358, 357);
			this->btnSieteE->TabIndex = 39;
			this->btnSieteE->TabStop = false;
			// 
			// btnSieteD
			// 
			this->btnSieteD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSieteD.BackgroundImage")));
			this->btnSieteD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSieteD->Location = System::Drawing::Point(1608, 75);
			this->btnSieteD->Name = L"btnSieteD";
			this->btnSieteD->Size = System::Drawing::Size(358, 357);
			this->btnSieteD->TabIndex = 38;
			this->btnSieteD->TabStop = false;
			this->btnSieteD->Visible = false;
			this->btnSieteD->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnSieteD_Click);
			this->btnSieteD->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnSieteD_MouseLeave);
			this->btnSieteD->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnSieteD_MouseHover);
			// 
			// btnSiete
			// 
			this->btnSiete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSiete.BackgroundImage")));
			this->btnSiete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSiete->Location = System::Drawing::Point(1610, 75);
			this->btnSiete->Name = L"btnSiete";
			this->btnSiete->Size = System::Drawing::Size(358, 357);
			this->btnSiete->TabIndex = 37;
			this->btnSiete->TabStop = false;
			this->btnSiete->Visible = false;
			this->btnSiete->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnSiete_Click);
			this->btnSiete->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnSiete_MouseLeave);
			this->btnSiete->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnSiete_MouseHover);
			// 
			// btnSeisE
			// 
			this->btnSeisE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSeisE.BackgroundImage")));
			this->btnSeisE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSeisE->Location = System::Drawing::Point(2011, 559);
			this->btnSeisE->Name = L"btnSeisE";
			this->btnSeisE->Size = System::Drawing::Size(272, 510);
			this->btnSeisE->TabIndex = 36;
			this->btnSeisE->TabStop = false;
			// 
			// btnSeisD
			// 
			this->btnSeisD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSeisD.BackgroundImage")));
			this->btnSeisD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSeisD->Location = System::Drawing::Point(2011, 559);
			this->btnSeisD->Name = L"btnSeisD";
			this->btnSeisD->Size = System::Drawing::Size(272, 510);
			this->btnSeisD->TabIndex = 35;
			this->btnSeisD->TabStop = false;
			this->btnSeisD->Visible = false;
			this->btnSeisD->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnSeisD_Click);
			this->btnSeisD->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnSeisD_MouseLeave);
			this->btnSeisD->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnSeisD_MouseHover);
			// 
			// btnSeis
			// 
			this->btnSeis->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSeis.BackgroundImage")));
			this->btnSeis->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSeis->Location = System::Drawing::Point(2011, 559);
			this->btnSeis->Name = L"btnSeis";
			this->btnSeis->Size = System::Drawing::Size(272, 510);
			this->btnSeis->TabIndex = 34;
			this->btnSeis->TabStop = false;
			this->btnSeis->Visible = false;
			this->btnSeis->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnSeis_Click);
			this->btnSeis->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnSeis_MouseLeave);
			this->btnSeis->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnSeis_MouseHover);
			// 
			// btnTresE
			// 
			this->btnTresE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTresE.BackgroundImage")));
			this->btnTresE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTresE->Location = System::Drawing::Point(830, 50);
			this->btnTresE->Name = L"btnTresE";
			this->btnTresE->Size = System::Drawing::Size(467, 452);
			this->btnTresE->TabIndex = 33;
			this->btnTresE->TabStop = false;
			// 
			// btnTresD
			// 
			this->btnTresD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTresD.BackgroundImage")));
			this->btnTresD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTresD->Location = System::Drawing::Point(830, 51);
			this->btnTresD->Name = L"btnTresD";
			this->btnTresD->Size = System::Drawing::Size(467, 452);
			this->btnTresD->TabIndex = 32;
			this->btnTresD->TabStop = false;
			this->btnTresD->Visible = false;
			this->btnTresD->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnTresD_Click);
			this->btnTresD->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnTresD_MouseLeave);
			this->btnTresD->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnTresD_MouseHover);
			// 
			// btnTres
			// 
			this->btnTres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTres.BackgroundImage")));
			this->btnTres->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTres->Location = System::Drawing::Point(830, 51);
			this->btnTres->Name = L"btnTres";
			this->btnTres->Size = System::Drawing::Size(467, 452);
			this->btnTres->TabIndex = 31;
			this->btnTres->TabStop = false;
			this->btnTres->Visible = false;
			this->btnTres->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnTres_Click);
			this->btnTres->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnTres_MouseLeave);
			this->btnTres->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnTres_MouseHover);
			// 
			// btnDosE
			// 
			this->btnDosE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDosE.BackgroundImage")));
			this->btnDosE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDosE->Location = System::Drawing::Point(366, 64);
			this->btnDosE->Name = L"btnDosE";
			this->btnDosE->Size = System::Drawing::Size(289, 341);
			this->btnDosE->TabIndex = 30;
			this->btnDosE->TabStop = false;
			// 
			// btnDosD
			// 
			this->btnDosD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDosD.BackgroundImage")));
			this->btnDosD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDosD->Location = System::Drawing::Point(366, 64);
			this->btnDosD->Name = L"btnDosD";
			this->btnDosD->Size = System::Drawing::Size(289, 341);
			this->btnDosD->TabIndex = 29;
			this->btnDosD->TabStop = false;
			this->btnDosD->Visible = false;
			this->btnDosD->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnDosD_Click);
			this->btnDosD->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnDosD_MouseLeave);
			this->btnDosD->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnDosD_MouseHover);
			// 
			// btnUnoD
			// 
			this->btnUnoD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUnoD.BackgroundImage")));
			this->btnUnoD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnUnoD->Location = System::Drawing::Point(77, 624);
			this->btnUnoD->Name = L"btnUnoD";
			this->btnUnoD->Size = System::Drawing::Size(350, 510);
			this->btnUnoD->TabIndex = 28;
			this->btnUnoD->TabStop = false;
			this->btnUnoD->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnUnoD_Click);
			this->btnUnoD->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnUnoD_MouseLeave);
			this->btnUnoD->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnUnoD_MouseHover);
			// 
			// btnDos
			// 
			this->btnDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDos.BackgroundImage")));
			this->btnDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDos->Location = System::Drawing::Point(366, 64);
			this->btnDos->Name = L"btnDos";
			this->btnDos->Size = System::Drawing::Size(289, 341);
			this->btnDos->TabIndex = 27;
			this->btnDos->TabStop = false;
			this->btnDos->Visible = false;
			this->btnDos->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnDos_Click);
			this->btnDos->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnDos_MouseLeave);
			this->btnDos->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnDos_MouseHover);
			// 
			// btnUno
			// 
			this->btnUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUno.BackgroundImage")));
			this->btnUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnUno->Location = System::Drawing::Point(77, 624);
			this->btnUno->Name = L"btnUno";
			this->btnUno->Size = System::Drawing::Size(350, 510);
			this->btnUno->TabIndex = 26;
			this->btnUno->TabStop = false;
			this->btnUno->Visible = false;
			this->btnUno->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnUno_Click);
			this->btnUno->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnUno_MouseLeave);
			this->btnUno->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnUno_MouseHover);
			// 
			// lblEstrellas
			// 
			this->lblEstrellas->AutoSize = true;
			this->lblEstrellas->BackColor = System::Drawing::Color::Transparent;
			this->lblEstrellas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstrellas->ForeColor = System::Drawing::Color::White;
			this->lblEstrellas->Location = System::Drawing::Point(2106, 50);
			this->lblEstrellas->Name = L"lblEstrellas";
			this->lblEstrellas->Size = System::Drawing::Size(88, 96);
			this->lblEstrellas->TabIndex = 24;
			this->lblEstrellas->Text = L"0";
			// 
			// btnVolver
			// 
			this->btnVolver->BackColor = System::Drawing::Color::Transparent;
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(34, 14);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(147, 110);
			this->btnVolver->TabIndex = 25;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &PrincipalCinco::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &PrincipalCinco::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &PrincipalCinco::btnVolver_MouseHover);
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(2207, 14);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(183, 171);
			this->pictureBox7->TabIndex = 23;
			this->pictureBox7->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &PrincipalCinco::timer1_Tick);
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
			this->picMinimizar->Click += gcnew System::EventHandler(this, &PrincipalCinco::picMinimizar_Click);
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
			this->picCerrar->Click += gcnew System::EventHandler(this, &PrincipalCinco::picCerrar_Click);
			// 
			// PrincipalCinco
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(2414, 1307);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PrincipalCinco";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PrincipalCinco";
			this->Activated += gcnew System::EventHandler(this, &PrincipalCinco::PrincipalCinco_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &PrincipalCinco::PrincipalCinco_Deactivate);
			this->Load += gcnew System::EventHandler(this, &PrincipalCinco::PrincipalCinco_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->panelPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatroE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCincoE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCincoD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatroD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCinco))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSieteE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSieteD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSiete))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeisE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeisD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTresE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTresD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTres))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDosE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDosD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnUnoD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnUno))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
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
	private: void cargarActUno(bool destacado);
	private: void cargarActDos(bool destacado);
	private: void cargarActTres(bool destacado);
	private: void cargarActCuatro(bool destacado);
	private: void cargarActCinco(bool destacado);
	private: void cargarActSeis(bool destacado);
	private: void cargarActSiete(bool destacado);
	private: System::Void btnVolver_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnUno_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDos_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTres_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCuatro_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCinco_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSeis_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSiete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnUnoD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDosD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTresD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCuatroD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCincoD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSeisD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSieteD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnUno_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnUno_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDos_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDos_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTres_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTres_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCuatro_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCuatro_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCinco_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCinco_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSeis_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSeis_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSiete_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSiete_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnUnoD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnUnoD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDosD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDosD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTresD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTresD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCuatroD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCuatroD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCincoD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCincoD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSeisD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSeisD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSieteD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSieteD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e);
	private: void SonidoUno();
	private: void SonidoDos();
	private: void SonidoTres();
	private: void SonidoCuatro();
	private: void SonidoCinco();
	private: void SonidoSeis();
	private: void SonidoSiete();
	private: void SonidoGruFinal();
	private: void SonidoInicial();
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalCinco_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalCinco_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalCinco_Deactivate(System::Object^  sender, System::EventArgs^  e);
	};
}
