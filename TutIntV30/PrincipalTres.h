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
	/// Resumen de PrincipalTres
	/// </summary>
	public ref class PrincipalTres : public System::Windows::Forms::Form
	{
	public:
		PrincipalTres(void)
		{
			InitializeComponent();
		}
		PrincipalTres(Form^ f, BaseDeDatos^ manejador)
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
		~PrincipalTres()
		{
			if (components)
			{
				delete components;
			}
		}
	private: BaseDeDatos ^ manejadorBD;
	private: System::Windows::Forms::Form^ form;
	private: int wVolver, hVolver, wUno, hUno, wDos, hDos, wTres, hTres, wCuatro, hCuatro, wCinco, hCinco, wSeis, hSeis;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::PictureBox^  btnUno;
	private: System::Windows::Forms::PictureBox^  btnDos;
	private: System::Windows::Forms::PictureBox^  btnTres;
	private: System::Windows::Forms::PictureBox^  btnSeis;
	private: System::Windows::Forms::PictureBox^  btnCuatro;
	private: System::Windows::Forms::PictureBox^  btnCinco;
	private: System::Windows::Forms::Label^  lblEstrellas;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  btnDosE;
	private: System::Windows::Forms::PictureBox^  btnTresE;
	private: System::Windows::Forms::PictureBox^  btnSeisE;
	private: System::Windows::Forms::PictureBox^  btnCuatroE;
	private: System::Windows::Forms::PictureBox^  btnCincoE;
	private: System::Windows::Forms::PictureBox^  btnDosD;
	private: System::Windows::Forms::PictureBox^  btnTresD;
	private: System::Windows::Forms::PictureBox^  btnSeisD;
	private: System::Windows::Forms::PictureBox^  btnCuatroD;
	private: System::Windows::Forms::PictureBox^  btnCincoD;
	private: System::Windows::Forms::PictureBox^  btnUnoD;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PrincipalTres::typeid));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->btnPlay = (gcnew System::Windows::Forms::PictureBox());
			this->btnDosD = (gcnew System::Windows::Forms::PictureBox());
			this->btnTresD = (gcnew System::Windows::Forms::PictureBox());
			this->btnSeisD = (gcnew System::Windows::Forms::PictureBox());
			this->btnCuatroD = (gcnew System::Windows::Forms::PictureBox());
			this->btnCincoD = (gcnew System::Windows::Forms::PictureBox());
			this->btnUnoD = (gcnew System::Windows::Forms::PictureBox());
			this->btnDosE = (gcnew System::Windows::Forms::PictureBox());
			this->btnTresE = (gcnew System::Windows::Forms::PictureBox());
			this->btnSeisE = (gcnew System::Windows::Forms::PictureBox());
			this->btnCuatroE = (gcnew System::Windows::Forms::PictureBox());
			this->btnCincoE = (gcnew System::Windows::Forms::PictureBox());
			this->btnUno = (gcnew System::Windows::Forms::PictureBox());
			this->btnDos = (gcnew System::Windows::Forms::PictureBox());
			this->btnTres = (gcnew System::Windows::Forms::PictureBox());
			this->btnSeis = (gcnew System::Windows::Forms::PictureBox());
			this->btnCuatro = (gcnew System::Windows::Forms::PictureBox());
			this->btnCinco = (gcnew System::Windows::Forms::PictureBox());
			this->lblEstrellas = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDosD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTresD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeisD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatroD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCincoD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnUnoD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDosE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTresE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeisE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatroE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCincoE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnUno))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTres))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCinco))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
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
			this->panelPrincipal->Controls->Add(this->btnPlay);
			this->panelPrincipal->Controls->Add(this->btnDosD);
			this->panelPrincipal->Controls->Add(this->btnTresD);
			this->panelPrincipal->Controls->Add(this->btnSeisD);
			this->panelPrincipal->Controls->Add(this->btnCuatroD);
			this->panelPrincipal->Controls->Add(this->btnCincoD);
			this->panelPrincipal->Controls->Add(this->btnUnoD);
			this->panelPrincipal->Controls->Add(this->btnDosE);
			this->panelPrincipal->Controls->Add(this->btnTresE);
			this->panelPrincipal->Controls->Add(this->btnSeisE);
			this->panelPrincipal->Controls->Add(this->btnCuatroE);
			this->panelPrincipal->Controls->Add(this->btnCincoE);
			this->panelPrincipal->Controls->Add(this->btnUno);
			this->panelPrincipal->Controls->Add(this->btnDos);
			this->panelPrincipal->Controls->Add(this->btnTres);
			this->panelPrincipal->Controls->Add(this->btnSeis);
			this->panelPrincipal->Controls->Add(this->btnCuatro);
			this->panelPrincipal->Controls->Add(this->btnCinco);
			this->panelPrincipal->Controls->Add(this->lblEstrellas);
			this->panelPrincipal->Controls->Add(this->btnVolver);
			this->panelPrincipal->Controls->Add(this->pictureBox1);
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
			this->btnPlay->Location = System::Drawing::Point(2214, 191);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(176, 151);
			this->btnPlay->TabIndex = 19;
			this->btnPlay->TabStop = false;
			this->btnPlay->Click += gcnew System::EventHandler(this, &PrincipalTres::btnPlay_Click);
			// 
			// btnDosD
			// 
			this->btnDosD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDosD.BackgroundImage")));
			this->btnDosD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDosD->Enabled = false;
			this->btnDosD->Location = System::Drawing::Point(372, 356);
			this->btnDosD->Name = L"btnDosD";
			this->btnDosD->Size = System::Drawing::Size(345, 425);
			this->btnDosD->TabIndex = 36;
			this->btnDosD->TabStop = false;
			this->btnDosD->Visible = false;
			this->btnDosD->Click += gcnew System::EventHandler(this, &PrincipalTres::btnDosD_Click);
			this->btnDosD->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnDosD_MouseLeave);
			this->btnDosD->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnDosD_MouseHover);
			// 
			// btnTresD
			// 
			this->btnTresD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTresD.BackgroundImage")));
			this->btnTresD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTresD->Enabled = false;
			this->btnTresD->Location = System::Drawing::Point(724, 737);
			this->btnTresD->Name = L"btnTresD";
			this->btnTresD->Size = System::Drawing::Size(526, 400);
			this->btnTresD->TabIndex = 35;
			this->btnTresD->TabStop = false;
			this->btnTresD->Visible = false;
			this->btnTresD->Click += gcnew System::EventHandler(this, &PrincipalTres::btnTresD_Click);
			this->btnTresD->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnTresD_MouseLeave);
			this->btnTresD->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnTresD_MouseHover);
			// 
			// btnSeisD
			// 
			this->btnSeisD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSeisD.BackgroundImage")));
			this->btnSeisD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSeisD->Enabled = false;
			this->btnSeisD->Location = System::Drawing::Point(1894, 606);
			this->btnSeisD->Name = L"btnSeisD";
			this->btnSeisD->Size = System::Drawing::Size(364, 499);
			this->btnSeisD->TabIndex = 34;
			this->btnSeisD->TabStop = false;
			this->btnSeisD->Visible = false;
			this->btnSeisD->Click += gcnew System::EventHandler(this, &PrincipalTres::btnSeisD_Click);
			this->btnSeisD->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnSeisD_MouseLeave);
			this->btnSeisD->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnSeisD_MouseHover);
			// 
			// btnCuatroD
			// 
			this->btnCuatroD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCuatroD.BackgroundImage")));
			this->btnCuatroD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCuatroD->Enabled = false;
			this->btnCuatroD->Location = System::Drawing::Point(1095, 265);
			this->btnCuatroD->Name = L"btnCuatroD";
			this->btnCuatroD->Size = System::Drawing::Size(392, 472);
			this->btnCuatroD->TabIndex = 33;
			this->btnCuatroD->TabStop = false;
			this->btnCuatroD->Visible = false;
			this->btnCuatroD->Click += gcnew System::EventHandler(this, &PrincipalTres::btnCuatroD_Click);
			this->btnCuatroD->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnCuatroD_MouseLeave);
			this->btnCuatroD->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnCuatroD_MouseHover);
			// 
			// btnCincoD
			// 
			this->btnCincoD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCincoD.BackgroundImage")));
			this->btnCincoD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCincoD->Enabled = false;
			this->btnCincoD->Location = System::Drawing::Point(1604, 493);
			this->btnCincoD->Name = L"btnCincoD";
			this->btnCincoD->Size = System::Drawing::Size(283, 319);
			this->btnCincoD->TabIndex = 32;
			this->btnCincoD->TabStop = false;
			this->btnCincoD->Visible = false;
			this->btnCincoD->Click += gcnew System::EventHandler(this, &PrincipalTres::btnCincoD_Click);
			this->btnCincoD->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnCincoD_MouseLeave);
			this->btnCincoD->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnCincoD_MouseHover);
			// 
			// btnUnoD
			// 
			this->btnUnoD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUnoD.BackgroundImage")));
			this->btnUnoD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnUnoD->Location = System::Drawing::Point(37, 535);
			this->btnUnoD->Name = L"btnUnoD";
			this->btnUnoD->Size = System::Drawing::Size(328, 545);
			this->btnUnoD->TabIndex = 31;
			this->btnUnoD->TabStop = false;
			this->btnUnoD->Click += gcnew System::EventHandler(this, &PrincipalTres::btnUnoD_Click);
			this->btnUnoD->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnUnoD_MouseLeave);
			this->btnUnoD->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnUnoD_MouseHover);
			// 
			// btnDosE
			// 
			this->btnDosE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDosE.BackgroundImage")));
			this->btnDosE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDosE->Enabled = false;
			this->btnDosE->Location = System::Drawing::Point(372, 357);
			this->btnDosE->Name = L"btnDosE";
			this->btnDosE->Size = System::Drawing::Size(345, 425);
			this->btnDosE->TabIndex = 30;
			this->btnDosE->TabStop = false;
			// 
			// btnTresE
			// 
			this->btnTresE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTresE.BackgroundImage")));
			this->btnTresE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTresE->Enabled = false;
			this->btnTresE->Location = System::Drawing::Point(724, 738);
			this->btnTresE->Name = L"btnTresE";
			this->btnTresE->Size = System::Drawing::Size(526, 400);
			this->btnTresE->TabIndex = 29;
			this->btnTresE->TabStop = false;
			// 
			// btnSeisE
			// 
			this->btnSeisE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSeisE.BackgroundImage")));
			this->btnSeisE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSeisE->Enabled = false;
			this->btnSeisE->Location = System::Drawing::Point(1894, 607);
			this->btnSeisE->Name = L"btnSeisE";
			this->btnSeisE->Size = System::Drawing::Size(364, 499);
			this->btnSeisE->TabIndex = 28;
			this->btnSeisE->TabStop = false;
			// 
			// btnCuatroE
			// 
			this->btnCuatroE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCuatroE.BackgroundImage")));
			this->btnCuatroE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCuatroE->Enabled = false;
			this->btnCuatroE->Location = System::Drawing::Point(1095, 266);
			this->btnCuatroE->Name = L"btnCuatroE";
			this->btnCuatroE->Size = System::Drawing::Size(392, 472);
			this->btnCuatroE->TabIndex = 27;
			this->btnCuatroE->TabStop = false;
			// 
			// btnCincoE
			// 
			this->btnCincoE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCincoE.BackgroundImage")));
			this->btnCincoE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCincoE->Enabled = false;
			this->btnCincoE->Location = System::Drawing::Point(1604, 494);
			this->btnCincoE->Name = L"btnCincoE";
			this->btnCincoE->Size = System::Drawing::Size(283, 319);
			this->btnCincoE->TabIndex = 26;
			this->btnCincoE->TabStop = false;
			// 
			// btnUno
			// 
			this->btnUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUno.BackgroundImage")));
			this->btnUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnUno->Enabled = false;
			this->btnUno->Location = System::Drawing::Point(37, 536);
			this->btnUno->Name = L"btnUno";
			this->btnUno->Size = System::Drawing::Size(328, 545);
			this->btnUno->TabIndex = 25;
			this->btnUno->TabStop = false;
			this->btnUno->Visible = false;
			this->btnUno->Click += gcnew System::EventHandler(this, &PrincipalTres::btnUno_Click);
			this->btnUno->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnUno_MouseLeave);
			this->btnUno->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnUno_MouseHover);
			// 
			// btnDos
			// 
			this->btnDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDos.BackgroundImage")));
			this->btnDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDos->Enabled = false;
			this->btnDos->Location = System::Drawing::Point(372, 357);
			this->btnDos->Name = L"btnDos";
			this->btnDos->Size = System::Drawing::Size(345, 425);
			this->btnDos->TabIndex = 24;
			this->btnDos->TabStop = false;
			this->btnDos->Visible = false;
			this->btnDos->Click += gcnew System::EventHandler(this, &PrincipalTres::btnDos_Click);
			this->btnDos->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnDos_MouseLeave);
			this->btnDos->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnDos_MouseHover);
			// 
			// btnTres
			// 
			this->btnTres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTres.BackgroundImage")));
			this->btnTres->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTres->Enabled = false;
			this->btnTres->Location = System::Drawing::Point(724, 738);
			this->btnTres->Name = L"btnTres";
			this->btnTres->Size = System::Drawing::Size(526, 400);
			this->btnTres->TabIndex = 23;
			this->btnTres->TabStop = false;
			this->btnTres->Visible = false;
			this->btnTres->Click += gcnew System::EventHandler(this, &PrincipalTres::btnTres_Click);
			this->btnTres->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnTres_MouseLeave);
			this->btnTres->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnTres_MouseHover);
			// 
			// btnSeis
			// 
			this->btnSeis->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSeis.BackgroundImage")));
			this->btnSeis->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSeis->Enabled = false;
			this->btnSeis->Location = System::Drawing::Point(1894, 607);
			this->btnSeis->Name = L"btnSeis";
			this->btnSeis->Size = System::Drawing::Size(364, 499);
			this->btnSeis->TabIndex = 22;
			this->btnSeis->TabStop = false;
			this->btnSeis->Visible = false;
			this->btnSeis->Click += gcnew System::EventHandler(this, &PrincipalTres::btnSeis_Click);
			this->btnSeis->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnSeis_MouseLeave);
			this->btnSeis->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnSeis_MouseHover);
			// 
			// btnCuatro
			// 
			this->btnCuatro->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCuatro.BackgroundImage")));
			this->btnCuatro->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCuatro->Enabled = false;
			this->btnCuatro->Location = System::Drawing::Point(1095, 266);
			this->btnCuatro->Name = L"btnCuatro";
			this->btnCuatro->Size = System::Drawing::Size(392, 472);
			this->btnCuatro->TabIndex = 21;
			this->btnCuatro->TabStop = false;
			this->btnCuatro->Visible = false;
			this->btnCuatro->Click += gcnew System::EventHandler(this, &PrincipalTres::btnCuatro_Click);
			this->btnCuatro->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnCuatro_MouseLeave);
			this->btnCuatro->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnCuatro_MouseHover);
			// 
			// btnCinco
			// 
			this->btnCinco->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCinco.BackgroundImage")));
			this->btnCinco->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCinco->Enabled = false;
			this->btnCinco->Location = System::Drawing::Point(1604, 494);
			this->btnCinco->Name = L"btnCinco";
			this->btnCinco->Size = System::Drawing::Size(283, 319);
			this->btnCinco->TabIndex = 20;
			this->btnCinco->TabStop = false;
			this->btnCinco->Visible = false;
			this->btnCinco->Click += gcnew System::EventHandler(this, &PrincipalTres::btnCinco_Click);
			this->btnCinco->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnCinco_MouseLeave);
			this->btnCinco->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnCinco_MouseHover);
			// 
			// lblEstrellas
			// 
			this->lblEstrellas->AutoSize = true;
			this->lblEstrellas->BackColor = System::Drawing::Color::Transparent;
			this->lblEstrellas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstrellas->ForeColor = System::Drawing::Color::Black;
			this->lblEstrellas->Location = System::Drawing::Point(2106, 36);
			this->lblEstrellas->Name = L"lblEstrellas";
			this->lblEstrellas->Size = System::Drawing::Size(88, 96);
			this->lblEstrellas->TabIndex = 18;
			this->lblEstrellas->Text = L"0";
			// 
			// btnVolver
			// 
			this->btnVolver->BackColor = System::Drawing::Color::Transparent;
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(37, 6);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(189, 147);
			this->btnVolver->TabIndex = 19;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &PrincipalTres::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &PrincipalTres::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &PrincipalTres::btnVolver_MouseHover);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(2207, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(183, 171);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &PrincipalTres::timer1_Tick);
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
			this->picMinimizar->Click += gcnew System::EventHandler(this, &PrincipalTres::picMinimizar_Click);
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
			this->picCerrar->Click += gcnew System::EventHandler(this, &PrincipalTres::picCerrar_Click);
			// 
			// PrincipalTres
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(2414, 1307);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PrincipalTres";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PrincipalTres";
			this->Activated += gcnew System::EventHandler(this, &PrincipalTres::PrincipalTres_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &PrincipalTres::PrincipalTres_Deactivate);
			this->Load += gcnew System::EventHandler(this, &PrincipalTres::PrincipalTres_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->panelPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDosD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTresD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeisD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatroD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCincoD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnUnoD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDosE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTresE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeisE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatroE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCincoE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnUno))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnDos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnTres))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnSeis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCuatro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCinco))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
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
	private: void cargarActUno(bool destacado);
	private: void cargarActDos(bool destacado);
	private: void cargarActTres(bool destacado);
	private: void cargarActCuatro(bool destacado);
	private: void cargarActCinco(bool destacado);
	private: void cargarActSeis(bool destacado);
	private: System::Void btnVolver_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnUno_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDos_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTres_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCuatro_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCinco_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSeis_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnUnoD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDosD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnTresD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCuatroD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCincoD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnSeisD_Click(System::Object^  sender, System::EventArgs^  e);
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
	private: void SonidoJudy();
	private: void SonidoNick();
	private: void SonidoFlash();
	private: void SonidoGarraza();
	private: void SonidoBig();
	private: void SonidoOveja();
	private: void SonidoJudyFinal();
	private: void SonidoInicial();
	private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalTres_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalTres_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalTres_Deactivate(System::Object^  sender, System::EventArgs^  e);
	};
}
