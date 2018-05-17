#pragma once
#include "BaseDeDatos.h"
#include "AgenteControlador.h"
#include "TiempoMI.h"
#include "TiempoGUI.h"

namespace TutIntV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Act2UnoBB
	/// </summary>
	public ref class Act2UnoBB : public System::Windows::Forms::Form
	{
	public:
		Act2UnoBB(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}
		Act2UnoBB(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
		{
			form = f;
			manejadorBD = manejador;
			controlador = control;
			InitializeComponent();
			inicializarTam();
			inicializarPosiciones();
			this->Size = System::Drawing::Size(1050, 598);
			this->Show();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Act2UnoBB()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int contAyuda = 0;
	private: BaseDeDatos ^ manejadorBD;
	private: AgenteControlador * controlador;
	private: int segundos, minutos, horas;			// Para el form
	private: TiempoGUI ^ t_actividad, ^t_item1, ^t_item2, ^t_item3, ^t_item4;
	private: Thread ^ hiloAct;
	private: System::Windows::Forms::Form^ form;
	private: int wVolver, hVolver, wListo, hListo, wAyuda, hAyuda;
	private: int posMouseFormX, posMouseFormY;
	private: int posMouseBtnX, posMouseBtnY;
	private: int posActBtnX, posActBtnY;
	private: bool btnPresionado = false;
	private: int xbtn1, ybtn1, xbtn2, ybtn2, xbtn3, ybtn3, xbtn4, ybtn4;		// Guardar la posicion original del boton
	private: bool listoBtn1, listoBtn2, listoBtn3, listoBtn4;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::PictureBox^  btnListo;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Panel^  panel2;


	private: System::Windows::Forms::PictureBox^  btnAyuda;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  btnCuatro;
	private: System::Windows::Forms::Button^  btnTres;
	private: System::Windows::Forms::Button^  btnDos;
	private: System::Windows::Forms::Button^  btnUno;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panelTres3;
	private: System::Windows::Forms::Panel^  panelDos3;
	private: System::Windows::Forms::Panel^  panelTres2;
	private: System::Windows::Forms::Panel^  panelUno3;
	private: System::Windows::Forms::Panel^  panelTres1;
	private: System::Windows::Forms::Panel^  panelDos2;
	private: System::Windows::Forms::Panel^  panelDos1;
	private: System::Windows::Forms::Panel^  panelUno2;
	private: System::Windows::Forms::Panel^  panelUno1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  instruccion1;
	private: System::Windows::Forms::Label^  instruccion2;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act2UnoBB::typeid));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->instruccion1 = (gcnew System::Windows::Forms::Label());
			this->instruccion2 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->btnListo = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnCuatro = (gcnew System::Windows::Forms::Button());
			this->btnTres = (gcnew System::Windows::Forms::Button());
			this->btnDos = (gcnew System::Windows::Forms::Button());
			this->btnUno = (gcnew System::Windows::Forms::Button());
			this->panelTres3 = (gcnew System::Windows::Forms::Panel());
			this->panelDos3 = (gcnew System::Windows::Forms::Panel());
			this->panelTres2 = (gcnew System::Windows::Forms::Panel());
			this->panelUno3 = (gcnew System::Windows::Forms::Panel());
			this->panelTres1 = (gcnew System::Windows::Forms::Panel());
			this->panelDos2 = (gcnew System::Windows::Forms::Panel());
			this->panelDos1 = (gcnew System::Windows::Forms::Panel());
			this->panelUno2 = (gcnew System::Windows::Forms::Panel());
			this->panelUno1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnAyuda = (gcnew System::Windows::Forms::PictureBox());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPrincipal->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->panel1);
			this->panelPrincipal->Controls->Add(this->panel13);
			this->panelPrincipal->Controls->Add(this->panel2);
			this->panelPrincipal->Controls->Add(this->btnAyuda);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 39);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(1401, 724);
			this->panelPrincipal->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->instruccion1);
			this->panel1->Controls->Add(this->instruccion2);
			this->panel1->Location = System::Drawing::Point(174, 3);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1209, 54);
			this->panel1->TabIndex = 14;
			// 
			// instruccion1
			// 
			this->instruccion1->AutoSize = true;
			this->instruccion1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->instruccion1->Location = System::Drawing::Point(57, 7);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(1055, 38);
			this->instruccion1->TabIndex = 14;
			this->instruccion1->Text = L"�Con qu� letra inicia la im�gen\? Mu�vela al cuadro de la letra que corresponde";
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->instruccion2->Location = System::Drawing::Point(56, 5);
			this->instruccion2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(862, 38);
			this->instruccion2->TabIndex = 13;
			this->instruccion2->Text = L"Arrastra la imagen a la letra con que inicia, seg�n corresponda.";
			this->instruccion2->Visible = false;
			// 
			// panel13
			// 
			this->panel13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel13.BackgroundImage")));
			this->panel13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel13->Controls->Add(this->btnListo);
			this->panel13->Controls->Add(this->btnVolver);
			this->panel13->Location = System::Drawing::Point(10, 375);
			this->panel13->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(277, 282);
			this->panel13->TabIndex = 13;
			// 
			// btnListo
			// 
			this->btnListo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnListo.BackgroundImage")));
			this->btnListo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnListo->Enabled = false;
			this->btnListo->Location = System::Drawing::Point(34, 110);
			this->btnListo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnListo->Name = L"btnListo";
			this->btnListo->Size = System::Drawing::Size(227, 81);
			this->btnListo->TabIndex = 1;
			this->btnListo->TabStop = false;
			this->btnListo->Visible = false;
			this->btnListo->Click += gcnew System::EventHandler(this, &Act2UnoBB::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act2UnoBB::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act2UnoBB::btnListo_MouseHover);
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(13, 28);
			this->btnVolver->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(241, 86);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act2UnoBB::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act2UnoBB::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act2UnoBB::btnVolver_MouseHover);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->btnCuatro);
			this->panel2->Controls->Add(this->btnTres);
			this->panel2->Controls->Add(this->btnDos);
			this->panel2->Controls->Add(this->btnUno);
			this->panel2->Controls->Add(this->panelTres3);
			this->panel2->Controls->Add(this->panelDos3);
			this->panel2->Controls->Add(this->panelTres2);
			this->panel2->Controls->Add(this->panelUno3);
			this->panel2->Controls->Add(this->panelTres1);
			this->panel2->Controls->Add(this->panelDos2);
			this->panel2->Controls->Add(this->panelDos1);
			this->panel2->Controls->Add(this->panelUno2);
			this->panel2->Controls->Add(this->panelUno1);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(289, 61);
			this->panel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1095, 630);
			this->panel2->TabIndex = 12;
			// 
			// btnCuatro
			// 
			this->btnCuatro->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCuatro.BackgroundImage")));
			this->btnCuatro->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCuatro->FlatAppearance->BorderSize = 0;
			this->btnCuatro->Location = System::Drawing::Point(268, 383);
			this->btnCuatro->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCuatro->Name = L"btnCuatro";
			this->btnCuatro->Size = System::Drawing::Size(167, 122);
			this->btnCuatro->TabIndex = 3;
			this->btnCuatro->UseVisualStyleBackColor = true;
			this->btnCuatro->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnCuatro_MouseDown);
			this->btnCuatro->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnCuatro_MouseMove);
			this->btnCuatro->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnCuatro_MouseUp);
			// 
			// btnTres
			// 
			this->btnTres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTres.BackgroundImage")));
			this->btnTres->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTres->FlatAppearance->BorderSize = 0;
			this->btnTres->Location = System::Drawing::Point(87, 280);
			this->btnTres->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnTres->Name = L"btnTres";
			this->btnTres->Size = System::Drawing::Size(167, 122);
			this->btnTres->TabIndex = 2;
			this->btnTres->UseVisualStyleBackColor = true;
			this->btnTres->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnTres_MouseDown);
			this->btnTres->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnTres_MouseMove);
			this->btnTres->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnTres_MouseUp);
			// 
			// btnDos
			// 
			this->btnDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDos.BackgroundImage")));
			this->btnDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDos->FlatAppearance->BorderSize = 0;
			this->btnDos->Location = System::Drawing::Point(268, 169);
			this->btnDos->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnDos->Name = L"btnDos";
			this->btnDos->Size = System::Drawing::Size(167, 122);
			this->btnDos->TabIndex = 1;
			this->btnDos->UseVisualStyleBackColor = true;
			this->btnDos->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnDos_MouseDown);
			this->btnDos->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnDos_MouseMove);
			this->btnDos->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnDos_MouseUp);
			// 
			// btnUno
			// 
			this->btnUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUno.BackgroundImage")));
			this->btnUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnUno->FlatAppearance->BorderSize = 0;
			this->btnUno->Location = System::Drawing::Point(87, 77);
			this->btnUno->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnUno->Name = L"btnUno";
			this->btnUno->Size = System::Drawing::Size(167, 122);
			this->btnUno->TabIndex = 0;
			this->btnUno->UseVisualStyleBackColor = true;
			this->btnUno->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnUno_MouseDown);
			this->btnUno->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnUno_MouseMove);
			this->btnUno->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act2UnoBB::btnUno_MouseUp);
			// 
			// panelTres3
			// 
			this->panelTres3->BackColor = System::Drawing::Color::Chocolate;
			this->panelTres3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelTres3->Location = System::Drawing::Point(831, 401);
			this->panelTres3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelTres3->Name = L"panelTres3";
			this->panelTres3->Size = System::Drawing::Size(169, 124);
			this->panelTres3->TabIndex = 11;
			// 
			// panelDos3
			// 
			this->panelDos3->BackColor = System::Drawing::Color::Chocolate;
			this->panelDos3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelDos3->Location = System::Drawing::Point(831, 270);
			this->panelDos3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelDos3->Name = L"panelDos3";
			this->panelDos3->Size = System::Drawing::Size(169, 124);
			this->panelDos3->TabIndex = 11;
			// 
			// panelTres2
			// 
			this->panelTres2->BackColor = System::Drawing::Color::OliveDrab;
			this->panelTres2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelTres2->Location = System::Drawing::Point(656, 401);
			this->panelTres2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelTres2->Name = L"panelTres2";
			this->panelTres2->Size = System::Drawing::Size(169, 124);
			this->panelTres2->TabIndex = 10;
			// 
			// panelUno3
			// 
			this->panelUno3->BackColor = System::Drawing::Color::Chocolate;
			this->panelUno3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelUno3->Location = System::Drawing::Point(831, 138);
			this->panelUno3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelUno3->Name = L"panelUno3";
			this->panelUno3->Size = System::Drawing::Size(169, 124);
			this->panelUno3->TabIndex = 8;
			// 
			// panelTres1
			// 
			this->panelTres1->BackColor = System::Drawing::Color::DarkOrange;
			this->panelTres1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelTres1->Location = System::Drawing::Point(481, 401);
			this->panelTres1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelTres1->Name = L"panelTres1";
			this->panelTres1->Size = System::Drawing::Size(169, 124);
			this->panelTres1->TabIndex = 9;
			// 
			// panelDos2
			// 
			this->panelDos2->BackColor = System::Drawing::Color::OliveDrab;
			this->panelDos2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelDos2->Location = System::Drawing::Point(656, 270);
			this->panelDos2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelDos2->Name = L"panelDos2";
			this->panelDos2->Size = System::Drawing::Size(169, 124);
			this->panelDos2->TabIndex = 10;
			// 
			// panelDos1
			// 
			this->panelDos1->BackColor = System::Drawing::Color::DarkOrange;
			this->panelDos1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelDos1->Location = System::Drawing::Point(481, 270);
			this->panelDos1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelDos1->Name = L"panelDos1";
			this->panelDos1->Size = System::Drawing::Size(169, 124);
			this->panelDos1->TabIndex = 9;
			// 
			// panelUno2
			// 
			this->panelUno2->BackColor = System::Drawing::Color::OliveDrab;
			this->panelUno2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelUno2->Location = System::Drawing::Point(656, 138);
			this->panelUno2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelUno2->Name = L"panelUno2";
			this->panelUno2->Size = System::Drawing::Size(169, 124);
			this->panelUno2->TabIndex = 8;
			// 
			// panelUno1
			// 
			this->panelUno1->BackColor = System::Drawing::Color::DarkOrange;
			this->panelUno1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelUno1->Location = System::Drawing::Point(481, 138);
			this->panelUno1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelUno1->Name = L"panelUno1";
			this->panelUno1->Size = System::Drawing::Size(169, 124);
			this->panelUno1->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Chocolate;
			this->label4->Location = System::Drawing::Point(883, 67);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 70);
			this->label4->TabIndex = 6;
			this->label4->Text = L"S";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::OliveDrab;
			this->label3->Location = System::Drawing::Point(713, 67);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 70);
			this->label3->TabIndex = 5;
			this->label3->Text = L"O";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DarkOrange;
			this->label2->Location = System::Drawing::Point(539, 67);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 70);
			this->label2->TabIndex = 4;
			this->label2->Text = L"A";
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(0, 10);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(171, 149);
			this->btnAyuda->TabIndex = 8;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act2UnoBB::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act2UnoBB::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act2UnoBB::btnAyuda_MouseHover);
			// 
			// panel9
			// 
			this->panel9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel9.BackgroundImage")));
			this->panel9->Controls->Add(this->pictureBox7);
			this->panel9->Controls->Add(this->label6);
			this->panel9->Controls->Add(this->picMinimizar);
			this->panel9->Controls->Add(this->picCerrar);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel9->Location = System::Drawing::Point(0, 0);
			this->panel9->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1401, 39);
			this->panel9->TabIndex = 3;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(7, 2);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(41, 35);
			this->pictureBox7->TabIndex = 33;
			this->pictureBox7->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(46, 4);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
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
			this->picMinimizar->Location = System::Drawing::Point(1315, 3);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(37, 33);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act2UnoBB::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(1358, 3);
			this->picCerrar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(37, 33);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act2UnoBB::picCerrar_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act2UnoBB::timer1_Tick);
			// 
			// Act2UnoBB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1401, 763);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel9);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Act2UnoBB";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act2UnoBB";
			this->Activated += gcnew System::EventHandler(this, &Act2UnoBB::Act2UnoBB_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act2UnoBB::Act2UnoBB_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act2UnoBB::Act2UnoBB_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel13->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->EndInit();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void inicializarTam();
	private: void inicializarPosiciones();
	private: void comprobarRespuestas();
	private: void sonidoInicial();
	private: System::Void btnAyuda_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnListo_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act2UnoBB_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act2UnoBB_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act2UnoBB_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoBtn);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void moverBoton(System::Windows::Forms::Button^ boton);
	private: System::Void btnUno_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnDos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnTres_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnCuatro_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnUno_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnDos_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnTres_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnCuatro_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnUno_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnDos_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnTres_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnCuatro_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	};
}