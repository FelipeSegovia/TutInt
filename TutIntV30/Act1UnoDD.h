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
	/// Resumen de Act1UnoDD
	/// </summary>
	public ref class Act1UnoDD : public System::Windows::Forms::Form
	{
	public:
		Act1UnoDD(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act1UnoDD(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Act1UnoDD()
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
	private: int wVolver, hVolver, wListo, hListo, wAyuda, hAyuda, wAyudaUno, hAyudaUno, wAyudaDos, hAyudaDos, wAyudaTres, hAyudaTres, wAyudaCuatro, hAyudaCuatro;
	private: int posMouseFormX, posMouseFormY;
	private: int posMouseBtnX, posMouseBtnY;
	private: int posActBtnX, posActBtnY;
	private: bool btnPresionado = false;
	private: int xbtn1RA, ybtn1RA, xbtn1CA, ybtn1CA, xbtn1COL, ybtn1COL, xbtn2GUI, ybtn2GUI, xbtn2NO, ybtn2NO, xbtn2PIN, ybtn2PIN, xbtn3TRE, ybtn3TRE, xbtn3ES, ybtn3ES, xbtn3LLA, ybtn3LLA, xbtn4BA, ybtn4BA, xbtn4NA, ybtn4NA, xbtn4LLE, ybtn4LLE;		// Guardar la posicion original del boton
	private: bool listoBtn1RA, listoBtn1CA, listoBtn1COL, listoBtn2GUI, listoBtn2NO, listoBtn2PIN, listoBtn3TRE, listoBtn3ES, listoBtn3LLA, listoBtn4BA, listoBtn4NA, listoBtn4LLE;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::PictureBox^  btnAyuda;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  btnListo;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  instruccion2;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btn1RA;
	private: System::Windows::Forms::Button^  btn1CA;
	private: System::Windows::Forms::Button^  btn2GUI;
	private: System::Windows::Forms::Button^  btn2NO;
	private: System::Windows::Forms::Button^  btn4BA;
	private: System::Windows::Forms::Button^  btn3TRE;
	private: System::Windows::Forms::Button^  btn4NA;
	private: System::Windows::Forms::Button^  btn3ES;
	private: System::Windows::Forms::Panel^  panel1Dos;
	private: System::Windows::Forms::Panel^  panel1Uno;
	private: System::Windows::Forms::Panel^  panel2Dos;
	private: System::Windows::Forms::Panel^  panel2Uno;
	private: System::Windows::Forms::Panel^  panel4Dos;
	private: System::Windows::Forms::Panel^  panel4Uno;
	private: System::Windows::Forms::Panel^  panel3Dos;
	private: System::Windows::Forms::Panel^  panel3Uno;
	private: System::Windows::Forms::Button^  btn2PIN;
	private: System::Windows::Forms::Button^  btn4LLE;
	private: System::Windows::Forms::Button^  btn3LLA;
	private: System::Windows::Forms::Panel^  panel2Tres;
	private: System::Windows::Forms::Panel^  panel4Tres;
	private: System::Windows::Forms::Panel^  panel3Tres;
	private: System::Windows::Forms::Button^  btn1COL;
	private: System::Windows::Forms::Panel^  panel1Tres;
	private: System::Windows::Forms::PictureBox^  ayudaUno;
	private: System::Windows::Forms::PictureBox^  ayudaCuatro;
	private: System::Windows::Forms::PictureBox^  ayudaTres;
	private: System::Windows::Forms::PictureBox^  ayudaDos;
	private: System::Windows::Forms::Label^  instruccion1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1UnoDD::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn1COL = (gcnew System::Windows::Forms::Button());
			this->btn1RA = (gcnew System::Windows::Forms::Button());
			this->btn2PIN = (gcnew System::Windows::Forms::Button());
			this->btn4LLE = (gcnew System::Windows::Forms::Button());
			this->btn3LLA = (gcnew System::Windows::Forms::Button());
			this->btn1CA = (gcnew System::Windows::Forms::Button());
			this->btn2GUI = (gcnew System::Windows::Forms::Button());
			this->btn2NO = (gcnew System::Windows::Forms::Button());
			this->btn4BA = (gcnew System::Windows::Forms::Button());
			this->btn3TRE = (gcnew System::Windows::Forms::Button());
			this->btn4NA = (gcnew System::Windows::Forms::Button());
			this->btn3ES = (gcnew System::Windows::Forms::Button());
			this->ayudaCuatro = (gcnew System::Windows::Forms::PictureBox());
			this->ayudaTres = (gcnew System::Windows::Forms::PictureBox());
			this->ayudaDos = (gcnew System::Windows::Forms::PictureBox());
			this->ayudaUno = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1Tres = (gcnew System::Windows::Forms::Panel());
			this->panel2Tres = (gcnew System::Windows::Forms::Panel());
			this->panel4Tres = (gcnew System::Windows::Forms::Panel());
			this->panel3Tres = (gcnew System::Windows::Forms::Panel());
			this->panel1Dos = (gcnew System::Windows::Forms::Panel());
			this->panel1Uno = (gcnew System::Windows::Forms::Panel());
			this->panel2Dos = (gcnew System::Windows::Forms::Panel());
			this->panel2Uno = (gcnew System::Windows::Forms::Panel());
			this->panel4Dos = (gcnew System::Windows::Forms::Panel());
			this->panel4Uno = (gcnew System::Windows::Forms::Panel());
			this->panel3Dos = (gcnew System::Windows::Forms::Panel());
			this->panel3Uno = (gcnew System::Windows::Forms::Panel());
			this->btnAyuda = (gcnew System::Windows::Forms::PictureBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->btnListo = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->instruccion2 = (gcnew System::Windows::Forms::Label());
			this->instruccion1 = (gcnew System::Windows::Forms::Label());
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->panelPrincipal->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaCuatro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaTres))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaDos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaUno))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1UnoDD::timer1_Tick);
			// 
			// panel6
			// 
			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel6.BackgroundImage")));
			this->panel6->Controls->Add(this->pictureBox7);
			this->panel6->Controls->Add(this->label1);
			this->panel6->Controls->Add(this->picMinimizar);
			this->panel6->Controls->Add(this->picCerrar);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Margin = System::Windows::Forms::Padding(2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(2450, 69);
			this->panel6->TabIndex = 5;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(12, 4);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(72, 62);
			this->pictureBox7->TabIndex = 33;
			this->pictureBox7->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(82, 7);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 55);
			this->label1->TabIndex = 32;
			this->label1->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(2298, 4);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(2);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(63, 58);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1UnoDD::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(2373, 4);
			this->picCerrar->Margin = System::Windows::Forms::Padding(2);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(63, 58);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1UnoDD::picCerrar_Click);
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->panel2);
			this->panelPrincipal->Controls->Add(this->btnAyuda);
			this->panelPrincipal->Controls->Add(this->panel5);
			this->panelPrincipal->Controls->Add(this->panel4);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 0);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(2);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(2450, 1334);
			this->panelPrincipal->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->btn1COL);
			this->panel2->Controls->Add(this->btn1RA);
			this->panel2->Controls->Add(this->btn2PIN);
			this->panel2->Controls->Add(this->btn4LLE);
			this->panel2->Controls->Add(this->btn3LLA);
			this->panel2->Controls->Add(this->btn1CA);
			this->panel2->Controls->Add(this->btn2GUI);
			this->panel2->Controls->Add(this->btn2NO);
			this->panel2->Controls->Add(this->btn4BA);
			this->panel2->Controls->Add(this->btn3TRE);
			this->panel2->Controls->Add(this->btn4NA);
			this->panel2->Controls->Add(this->btn3ES);
			this->panel2->Controls->Add(this->ayudaCuatro);
			this->panel2->Controls->Add(this->ayudaTres);
			this->panel2->Controls->Add(this->ayudaDos);
			this->panel2->Controls->Add(this->ayudaUno);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->panel1Tres);
			this->panel2->Controls->Add(this->panel2Tres);
			this->panel2->Controls->Add(this->panel4Tres);
			this->panel2->Controls->Add(this->panel3Tres);
			this->panel2->Controls->Add(this->panel1Dos);
			this->panel2->Controls->Add(this->panel1Uno);
			this->panel2->Controls->Add(this->panel2Dos);
			this->panel2->Controls->Add(this->panel2Uno);
			this->panel2->Controls->Add(this->panel4Dos);
			this->panel2->Controls->Add(this->panel4Uno);
			this->panel2->Controls->Add(this->panel3Dos);
			this->panel2->Controls->Add(this->panel3Uno);
			this->panel2->Location = System::Drawing::Point(592, 187);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1791, 1091);
			this->panel2->TabIndex = 3;
			// 
			// btn1COL
			// 
			this->btn1COL->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1COL->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1COL->ForeColor = System::Drawing::Color::Transparent;
			this->btn1COL->Location = System::Drawing::Point(549, 188);
			this->btn1COL->Name = L"btn1COL";
			this->btn1COL->Size = System::Drawing::Size(175, 89);
			this->btn1COL->TabIndex = 20;
			this->btn1COL->Text = L"COL";
			this->btn1COL->UseVisualStyleBackColor = false;
			this->btn1COL->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1COL_MouseDown);
			this->btn1COL->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1COL_MouseMove);
			this->btn1COL->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1COL_MouseUp);
			// 
			// btn1RA
			// 
			this->btn1RA->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1RA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1RA->ForeColor = System::Drawing::Color::Transparent;
			this->btn1RA->Location = System::Drawing::Point(187, 188);
			this->btn1RA->Name = L"btn1RA";
			this->btn1RA->Size = System::Drawing::Size(175, 89);
			this->btn1RA->TabIndex = 3;
			this->btn1RA->Text = L"RA";
			this->btn1RA->UseVisualStyleBackColor = false;
			this->btn1RA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1RA_MouseDown);
			this->btn1RA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1RA_MouseMove);
			this->btn1RA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1RA_MouseUp);
			// 
			// btn2PIN
			// 
			this->btn2PIN->BackColor = System::Drawing::Color::Teal;
			this->btn2PIN->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2PIN->ForeColor = System::Drawing::Color::Transparent;
			this->btn2PIN->Location = System::Drawing::Point(549, 413);
			this->btn2PIN->Name = L"btn2PIN";
			this->btn2PIN->Size = System::Drawing::Size(175, 89);
			this->btn2PIN->TabIndex = 17;
			this->btn2PIN->Text = L"PIN";
			this->btn2PIN->UseVisualStyleBackColor = false;
			this->btn2PIN->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2PIN_MouseDown);
			this->btn2PIN->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2PIN_MouseMove);
			this->btn2PIN->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2PIN_MouseUp);
			// 
			// btn4LLE
			// 
			this->btn4LLE->BackColor = System::Drawing::Color::Olive;
			this->btn4LLE->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4LLE->ForeColor = System::Drawing::Color::Transparent;
			this->btn4LLE->Location = System::Drawing::Point(549, 878);
			this->btn4LLE->Name = L"btn4LLE";
			this->btn4LLE->Size = System::Drawing::Size(175, 89);
			this->btn4LLE->TabIndex = 18;
			this->btn4LLE->Text = L"LLE";
			this->btn4LLE->UseVisualStyleBackColor = false;
			this->btn4LLE->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4LLE_MouseDown);
			this->btn4LLE->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4LLE_MouseMove);
			this->btn4LLE->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4LLE_MouseUp);
			// 
			// btn3LLA
			// 
			this->btn3LLA->BackColor = System::Drawing::Color::Chocolate;
			this->btn3LLA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3LLA->ForeColor = System::Drawing::Color::Transparent;
			this->btn3LLA->Location = System::Drawing::Point(549, 643);
			this->btn3LLA->Name = L"btn3LLA";
			this->btn3LLA->Size = System::Drawing::Size(175, 89);
			this->btn3LLA->TabIndex = 19;
			this->btn3LLA->Text = L"LLA";
			this->btn3LLA->UseVisualStyleBackColor = false;
			this->btn3LLA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3LLA_MouseDown);
			this->btn3LLA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3LLA_MouseMove);
			this->btn3LLA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3LLA_MouseUp);
			// 
			// btn1CA
			// 
			this->btn1CA->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1CA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1CA->ForeColor = System::Drawing::Color::Transparent;
			this->btn1CA->Location = System::Drawing::Point(369, 188);
			this->btn1CA->Name = L"btn1CA";
			this->btn1CA->Size = System::Drawing::Size(175, 89);
			this->btn1CA->TabIndex = 3;
			this->btn1CA->Text = L"CA";
			this->btn1CA->UseVisualStyleBackColor = false;
			this->btn1CA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1CA_MouseDown);
			this->btn1CA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1CA_MouseMove);
			this->btn1CA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn1CA_MouseUp);
			// 
			// btn2GUI
			// 
			this->btn2GUI->BackColor = System::Drawing::Color::Teal;
			this->btn2GUI->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2GUI->ForeColor = System::Drawing::Color::Transparent;
			this->btn2GUI->Location = System::Drawing::Point(187, 413);
			this->btn2GUI->Name = L"btn2GUI";
			this->btn2GUI->Size = System::Drawing::Size(175, 89);
			this->btn2GUI->TabIndex = 4;
			this->btn2GUI->Text = L"GÜI";
			this->btn2GUI->UseVisualStyleBackColor = false;
			this->btn2GUI->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2GUI_MouseDown);
			this->btn2GUI->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2GUI_MouseMove);
			this->btn2GUI->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2GUI_MouseUp);
			// 
			// btn2NO
			// 
			this->btn2NO->BackColor = System::Drawing::Color::Teal;
			this->btn2NO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2NO->ForeColor = System::Drawing::Color::Transparent;
			this->btn2NO->Location = System::Drawing::Point(369, 413);
			this->btn2NO->Name = L"btn2NO";
			this->btn2NO->Size = System::Drawing::Size(175, 89);
			this->btn2NO->TabIndex = 4;
			this->btn2NO->Text = L"NO";
			this->btn2NO->UseVisualStyleBackColor = false;
			this->btn2NO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2NO_MouseDown);
			this->btn2NO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2NO_MouseMove);
			this->btn2NO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn2NO_MouseUp);
			// 
			// btn4BA
			// 
			this->btn4BA->BackColor = System::Drawing::Color::Olive;
			this->btn4BA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4BA->ForeColor = System::Drawing::Color::Transparent;
			this->btn4BA->Location = System::Drawing::Point(187, 878);
			this->btn4BA->Name = L"btn4BA";
			this->btn4BA->Size = System::Drawing::Size(175, 89);
			this->btn4BA->TabIndex = 4;
			this->btn4BA->Text = L"BA";
			this->btn4BA->UseVisualStyleBackColor = false;
			this->btn4BA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4BA_MouseDown);
			this->btn4BA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4BA_MouseMove);
			this->btn4BA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4BA_MouseUp);
			// 
			// btn3TRE
			// 
			this->btn3TRE->BackColor = System::Drawing::Color::Chocolate;
			this->btn3TRE->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3TRE->ForeColor = System::Drawing::Color::Transparent;
			this->btn3TRE->Location = System::Drawing::Point(187, 643);
			this->btn3TRE->Name = L"btn3TRE";
			this->btn3TRE->Size = System::Drawing::Size(175, 89);
			this->btn3TRE->TabIndex = 4;
			this->btn3TRE->Text = L"TRE";
			this->btn3TRE->UseVisualStyleBackColor = false;
			this->btn3TRE->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3TRE_MouseDown);
			this->btn3TRE->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3TRE_MouseMove);
			this->btn3TRE->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3TRE_MouseUp);
			// 
			// btn4NA
			// 
			this->btn4NA->BackColor = System::Drawing::Color::Olive;
			this->btn4NA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4NA->ForeColor = System::Drawing::Color::Transparent;
			this->btn4NA->Location = System::Drawing::Point(369, 878);
			this->btn4NA->Name = L"btn4NA";
			this->btn4NA->Size = System::Drawing::Size(175, 89);
			this->btn4NA->TabIndex = 4;
			this->btn4NA->Text = L"NA";
			this->btn4NA->UseVisualStyleBackColor = false;
			this->btn4NA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4NA_MouseDown);
			this->btn4NA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4NA_MouseMove);
			this->btn4NA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn4NA_MouseUp);
			// 
			// btn3ES
			// 
			this->btn3ES->BackColor = System::Drawing::Color::Chocolate;
			this->btn3ES->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3ES->ForeColor = System::Drawing::Color::Transparent;
			this->btn3ES->Location = System::Drawing::Point(369, 643);
			this->btn3ES->Name = L"btn3ES";
			this->btn3ES->Size = System::Drawing::Size(175, 89);
			this->btn3ES->TabIndex = 4;
			this->btn3ES->Text = L"ES";
			this->btn3ES->UseVisualStyleBackColor = false;
			this->btn3ES->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3ES_MouseDown);
			this->btn3ES->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3ES_MouseMove);
			this->btn3ES->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDD::btn3ES_MouseUp);
			// 
			// ayudaCuatro
			// 
			this->ayudaCuatro->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ayudaCuatro.BackgroundImage")));
			this->ayudaCuatro->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ayudaCuatro->Location = System::Drawing::Point(1400, 844);
			this->ayudaCuatro->Name = L"ayudaCuatro";
			this->ayudaCuatro->Size = System::Drawing::Size(160, 145);
			this->ayudaCuatro->TabIndex = 25;
			this->ayudaCuatro->TabStop = false;
			this->ayudaCuatro->Click += gcnew System::EventHandler(this, &Act1UnoDD::ayudaCuatro_Click);
			this->ayudaCuatro->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDD::ayudaCuatro_MouseLeave);
			this->ayudaCuatro->MouseHover += gcnew System::EventHandler(this, &Act1UnoDD::ayudaCuatro_MouseHover);
			// 
			// ayudaTres
			// 
			this->ayudaTres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ayudaTres.BackgroundImage")));
			this->ayudaTres->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ayudaTres->Location = System::Drawing::Point(1400, 615);
			this->ayudaTres->Name = L"ayudaTres";
			this->ayudaTres->Size = System::Drawing::Size(160, 145);
			this->ayudaTres->TabIndex = 24;
			this->ayudaTres->TabStop = false;
			this->ayudaTres->Click += gcnew System::EventHandler(this, &Act1UnoDD::ayudaTres_Click);
			this->ayudaTres->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDD::ayudaTres_MouseLeave);
			this->ayudaTres->MouseHover += gcnew System::EventHandler(this, &Act1UnoDD::ayudaTres_MouseHover);
			// 
			// ayudaDos
			// 
			this->ayudaDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ayudaDos.BackgroundImage")));
			this->ayudaDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ayudaDos->Location = System::Drawing::Point(1400, 381);
			this->ayudaDos->Name = L"ayudaDos";
			this->ayudaDos->Size = System::Drawing::Size(160, 145);
			this->ayudaDos->TabIndex = 23;
			this->ayudaDos->TabStop = false;
			this->ayudaDos->Click += gcnew System::EventHandler(this, &Act1UnoDD::ayudaDos_Click);
			this->ayudaDos->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDD::ayudaDos_MouseLeave);
			this->ayudaDos->MouseHover += gcnew System::EventHandler(this, &Act1UnoDD::ayudaDos_MouseHover);
			// 
			// ayudaUno
			// 
			this->ayudaUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ayudaUno.BackgroundImage")));
			this->ayudaUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ayudaUno->Location = System::Drawing::Point(1400, 153);
			this->ayudaUno->Name = L"ayudaUno";
			this->ayudaUno->Size = System::Drawing::Size(160, 145);
			this->ayudaUno->TabIndex = 22;
			this->ayudaUno->TabStop = false;
			this->ayudaUno->Click += gcnew System::EventHandler(this, &Act1UnoDD::ayudaUno_Click);
			this->ayudaUno->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDD::ayudaUno_MouseLeave);
			this->ayudaUno->MouseHover += gcnew System::EventHandler(this, &Act1UnoDD::ayudaUno_MouseHover);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(1341, 116);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(264, 202);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(1385, 357);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(200, 203);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(1337, 829);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(294, 184);
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(1371, 598);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(231, 184);
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// panel1Tres
			// 
			this->panel1Tres->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Tres->Location = System::Drawing::Point(1151, 188);
			this->panel1Tres->Name = L"panel1Tres";
			this->panel1Tres->Size = System::Drawing::Size(174, 89);
			this->panel1Tres->TabIndex = 21;
			// 
			// panel2Tres
			// 
			this->panel2Tres->BackColor = System::Drawing::Color::Teal;
			this->panel2Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Tres->Location = System::Drawing::Point(1151, 414);
			this->panel2Tres->Name = L"panel2Tres";
			this->panel2Tres->Size = System::Drawing::Size(174, 89);
			this->panel2Tres->TabIndex = 13;
			// 
			// panel4Tres
			// 
			this->panel4Tres->BackColor = System::Drawing::Color::Olive;
			this->panel4Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Tres->Location = System::Drawing::Point(1151, 880);
			this->panel4Tres->Name = L"panel4Tres";
			this->panel4Tres->Size = System::Drawing::Size(174, 89);
			this->panel4Tres->TabIndex = 14;
			// 
			// panel3Tres
			// 
			this->panel3Tres->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Tres->Location = System::Drawing::Point(1151, 643);
			this->panel3Tres->Name = L"panel3Tres";
			this->panel3Tres->Size = System::Drawing::Size(174, 89);
			this->panel3Tres->TabIndex = 15;
			// 
			// panel1Dos
			// 
			this->panel1Dos->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Dos->Location = System::Drawing::Point(973, 188);
			this->panel1Dos->Name = L"panel1Dos";
			this->panel1Dos->Size = System::Drawing::Size(174, 89);
			this->panel1Dos->TabIndex = 8;
			// 
			// panel1Uno
			// 
			this->panel1Uno->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Uno->Location = System::Drawing::Point(794, 188);
			this->panel1Uno->Name = L"panel1Uno";
			this->panel1Uno->Size = System::Drawing::Size(174, 89);
			this->panel1Uno->TabIndex = 7;
			// 
			// panel2Dos
			// 
			this->panel2Dos->BackColor = System::Drawing::Color::Teal;
			this->panel2Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Dos->Location = System::Drawing::Point(973, 414);
			this->panel2Dos->Name = L"panel2Dos";
			this->panel2Dos->Size = System::Drawing::Size(174, 89);
			this->panel2Dos->TabIndex = 11;
			// 
			// panel2Uno
			// 
			this->panel2Uno->BackColor = System::Drawing::Color::Teal;
			this->panel2Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Uno->Location = System::Drawing::Point(794, 414);
			this->panel2Uno->Name = L"panel2Uno";
			this->panel2Uno->Size = System::Drawing::Size(174, 89);
			this->panel2Uno->TabIndex = 10;
			// 
			// panel4Dos
			// 
			this->panel4Dos->BackColor = System::Drawing::Color::Olive;
			this->panel4Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Dos->Location = System::Drawing::Point(974, 880);
			this->panel4Dos->Name = L"panel4Dos";
			this->panel4Dos->Size = System::Drawing::Size(174, 89);
			this->panel4Dos->TabIndex = 11;
			// 
			// panel4Uno
			// 
			this->panel4Uno->BackColor = System::Drawing::Color::Olive;
			this->panel4Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Uno->Location = System::Drawing::Point(794, 880);
			this->panel4Uno->Name = L"panel4Uno";
			this->panel4Uno->Size = System::Drawing::Size(174, 89);
			this->panel4Uno->TabIndex = 10;
			// 
			// panel3Dos
			// 
			this->panel3Dos->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Dos->Location = System::Drawing::Point(973, 643);
			this->panel3Dos->Name = L"panel3Dos";
			this->panel3Dos->Size = System::Drawing::Size(174, 89);
			this->panel3Dos->TabIndex = 11;
			// 
			// panel3Uno
			// 
			this->panel3Uno->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Uno->Location = System::Drawing::Point(794, 643);
			this->panel3Uno->Name = L"panel3Uno";
			this->panel3Uno->Size = System::Drawing::Size(174, 89);
			this->panel3Uno->TabIndex = 10;
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(3, 86);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(2);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(427, 250);
			this->btnAyuda->TabIndex = 11;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1UnoDD::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDD::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1UnoDD::btnAyuda_MouseHover);
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->btnListo);
			this->panel5->Controls->Add(this->btnVolver);
			this->panel5->Location = System::Drawing::Point(40, 723);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(483, 513);
			this->panel5->TabIndex = 10;
			// 
			// btnListo
			// 
			this->btnListo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnListo.BackgroundImage")));
			this->btnListo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnListo->Enabled = false;
			this->btnListo->Location = System::Drawing::Point(58, 201);
			this->btnListo->Margin = System::Windows::Forms::Padding(2);
			this->btnListo->Name = L"btnListo";
			this->btnListo->Size = System::Drawing::Size(399, 147);
			this->btnListo->TabIndex = 1;
			this->btnListo->TabStop = false;
			this->btnListo->Visible = false;
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1UnoDD::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDD::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1UnoDD::btnListo_MouseHover);
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(23, 51);
			this->btnVolver->Margin = System::Windows::Forms::Padding(2);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(422, 154);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1UnoDD::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDD::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1UnoDD::btnVolver_MouseHover);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->instruccion1);
			this->panel4->Controls->Add(this->instruccion2);
			this->panel4->Location = System::Drawing::Point(434, 73);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1857, 91);
			this->panel4->TabIndex = 7;
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::Color::White;
			this->instruccion2->Location = System::Drawing::Point(85, 9);
			this->instruccion2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(1646, 68);
			this->instruccion2->TabIndex = 4;
			this->instruccion2->Text = L"Desliza cada sílaba hacia los recuadros vacios para crear la palabra";
			this->instruccion2->Visible = false;
			// 
			// instruccion1
			// 
			this->instruccion1->AutoSize = true;
			this->instruccion1->BackColor = System::Drawing::Color::Transparent;
			this->instruccion1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion1->ForeColor = System::Drawing::Color::White;
			this->instruccion1->Location = System::Drawing::Point(99, 11);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(1400, 68);
			this->instruccion1->TabIndex = 5;
			this->instruccion1->Text = L"Ordenemos las sílabas para descubrir los objetos del mar";
			// 
			// Act1UnoDD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2450, 1334);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panelPrincipal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Act1UnoDD";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1UnoDD";
			this->Activated += gcnew System::EventHandler(this, &Act1UnoDD::Act1UnoDD_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1UnoDD::Act1UnoDD_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1UnoDD::Act1UnoDD_Load);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->panelPrincipal->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaCuatro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaTres))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaDos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaUno))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->EndInit();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
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
	private: System::Void ayudaUno_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaDos_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaTres_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaCuatro_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaUno_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaUno_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaDos_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaDos_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaTres_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaTres_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaCuatro_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ayudaCuatro_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoDD_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoDD_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoDD_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos, bool listoTres);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void moverBoton(System::Windows::Forms::Button^ boton);
	private: System::Void btn1RA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1COL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2GUI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2NO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2PIN_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3TRE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3ES_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3LLA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4BA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4NA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4LLE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1RA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1COL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2GUI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2NO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2PIN_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3TRE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3ES_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3LLA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4BA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4NA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4LLE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1RA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1COL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2GUI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2NO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2PIN_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3TRE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3ES_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3LLA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4BA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4NA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4LLE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	};
}
