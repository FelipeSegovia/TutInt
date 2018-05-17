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
	/// Resumen de Act1DosDD
	/// </summary>
	public ref class Act1DosDD : public System::Windows::Forms::Form
	{
	public:
		Act1DosDD(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act1DosDD(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act1DosDD()
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
	private: int xbtn1TU, ybtn1TU, xbtn1GA, ybtn1GA, xbtn1TOR, ybtn1TOR, xbtn2VIO, ybtn2VIO, xbtn2TA, ybtn2TA, xbtn2GA, ybtn2GA, xbtn3LI, ybtn3LI, xbtn3CA, ybtn3CA, xbtn3NO, ybtn3NO, xbtn3PE, ybtn3PE, xbtn4JO, ybtn4JO, xbtn4CAN, ybtn4CAN, xbtn4GRE, ybtn4GRE;		// Guardar la posicion original del boton
	private: bool listoBtn1TU, listoBtn1GA, listoBtn1TOR, listoBtn2VIO, listoBtn2TA, listoBtn2GA, listoBtn3LI, listoBtn3CA, listoBtn3NO, listoBtn3PE, listoBtn4JO, listoBtn4CAN, listoBtn4GRE;
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
	private: System::Windows::Forms::Button^  btn1TU;
	private: System::Windows::Forms::Button^  btn1GA;
	private: System::Windows::Forms::Button^  btn2VIO;
	private: System::Windows::Forms::Button^  btn2TA;
	private: System::Windows::Forms::Button^  btn4JO;
	private: System::Windows::Forms::Button^  btn3LI;
	private: System::Windows::Forms::Button^  btn4CAN;
	private: System::Windows::Forms::Button^  btn3CA;
	private: System::Windows::Forms::Panel^  panel1Dos;
	private: System::Windows::Forms::Panel^  panel1Uno;
	private: System::Windows::Forms::Panel^  panel2Dos;
	private: System::Windows::Forms::Panel^  panel2Uno;
	private: System::Windows::Forms::Panel^  panel4Dos;
	private: System::Windows::Forms::Panel^  panel4Uno;
	private: System::Windows::Forms::Panel^  panel3Dos;
	private: System::Windows::Forms::Panel^  panel3Uno;
	private: System::Windows::Forms::Button^  btn2GA;
	private: System::Windows::Forms::Button^  btn4GRE;
	private: System::Windows::Forms::Button^  btn3NO;
	private: System::Windows::Forms::Panel^  panel2Tres;
	private: System::Windows::Forms::Panel^  panel4Tres;
	private: System::Windows::Forms::Panel^  panel3Tres;
	private: System::Windows::Forms::Button^  btn1TOR;
	private: System::Windows::Forms::Panel^  panel1Tres;
	private: System::Windows::Forms::PictureBox^  ayudaUno;
	private: System::Windows::Forms::PictureBox^  ayudaCuatro;
	private: System::Windows::Forms::PictureBox^  ayudaTres;
	private: System::Windows::Forms::PictureBox^  ayudaDos;
	private: System::Windows::Forms::Button^  btn3PE;
	private: System::Windows::Forms::Panel^  panel3Cuatro;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1DosDD::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn3PE = (gcnew System::Windows::Forms::Button());
			this->btn1TOR = (gcnew System::Windows::Forms::Button());
			this->btn1TU = (gcnew System::Windows::Forms::Button());
			this->btn2GA = (gcnew System::Windows::Forms::Button());
			this->btn4GRE = (gcnew System::Windows::Forms::Button());
			this->btn3NO = (gcnew System::Windows::Forms::Button());
			this->btn1GA = (gcnew System::Windows::Forms::Button());
			this->btn2VIO = (gcnew System::Windows::Forms::Button());
			this->btn2TA = (gcnew System::Windows::Forms::Button());
			this->btn4JO = (gcnew System::Windows::Forms::Button());
			this->btn3LI = (gcnew System::Windows::Forms::Button());
			this->btn4CAN = (gcnew System::Windows::Forms::Button());
			this->btn3CA = (gcnew System::Windows::Forms::Button());
			this->ayudaTres = (gcnew System::Windows::Forms::PictureBox());
			this->ayudaUno = (gcnew System::Windows::Forms::PictureBox());
			this->ayudaDos = (gcnew System::Windows::Forms::PictureBox());
			this->ayudaCuatro = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
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
			this->panel3Cuatro = (gcnew System::Windows::Forms::Panel());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaTres))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaUno))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaDos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaCuatro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1DosDD::timer1_Tick);
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
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1DosDD::picMinimizar_Click);
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
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1DosDD::picCerrar_Click);
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
			this->panel2->Controls->Add(this->btn3PE);
			this->panel2->Controls->Add(this->btn1TOR);
			this->panel2->Controls->Add(this->btn1TU);
			this->panel2->Controls->Add(this->btn2GA);
			this->panel2->Controls->Add(this->btn4GRE);
			this->panel2->Controls->Add(this->btn3NO);
			this->panel2->Controls->Add(this->btn1GA);
			this->panel2->Controls->Add(this->btn2VIO);
			this->panel2->Controls->Add(this->btn2TA);
			this->panel2->Controls->Add(this->btn4JO);
			this->panel2->Controls->Add(this->btn3LI);
			this->panel2->Controls->Add(this->btn4CAN);
			this->panel2->Controls->Add(this->btn3CA);
			this->panel2->Controls->Add(this->ayudaTres);
			this->panel2->Controls->Add(this->ayudaUno);
			this->panel2->Controls->Add(this->ayudaDos);
			this->panel2->Controls->Add(this->ayudaCuatro);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->pictureBox2);
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
			this->panel2->Controls->Add(this->panel3Cuatro);
			this->panel2->Location = System::Drawing::Point(491, 180);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1956, 1117);
			this->panel2->TabIndex = 3;
			// 
			// btn3PE
			// 
			this->btn3PE->BackColor = System::Drawing::Color::Chocolate;
			this->btn3PE->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3PE->ForeColor = System::Drawing::Color::Transparent;
			this->btn3PE->Location = System::Drawing::Point(681, 643);
			this->btn3PE->Name = L"btn3PE";
			this->btn3PE->Size = System::Drawing::Size(165, 89);
			this->btn3PE->TabIndex = 21;
			this->btn3PE->Text = L"PE";
			this->btn3PE->UseVisualStyleBackColor = false;
			this->btn3PE->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3PE_MouseDown);
			this->btn3PE->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3PE_MouseMove);
			this->btn3PE->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3PE_MouseUp);
			// 
			// btn1TOR
			// 
			this->btn1TOR->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1TOR->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1TOR->ForeColor = System::Drawing::Color::Transparent;
			this->btn1TOR->Location = System::Drawing::Point(519, 188);
			this->btn1TOR->Name = L"btn1TOR";
			this->btn1TOR->Size = System::Drawing::Size(165, 89);
			this->btn1TOR->TabIndex = 20;
			this->btn1TOR->Text = L"TOR";
			this->btn1TOR->UseVisualStyleBackColor = false;
			this->btn1TOR->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1TOR_MouseDown);
			this->btn1TOR->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1TOR_MouseMove);
			this->btn1TOR->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1TOR_MouseUp);
			// 
			// btn1TU
			// 
			this->btn1TU->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1TU->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1TU->ForeColor = System::Drawing::Color::Transparent;
			this->btn1TU->Location = System::Drawing::Point(188, 188);
			this->btn1TU->Name = L"btn1TU";
			this->btn1TU->Size = System::Drawing::Size(165, 89);
			this->btn1TU->TabIndex = 3;
			this->btn1TU->Text = L"TU";
			this->btn1TU->UseVisualStyleBackColor = false;
			this->btn1TU->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1TU_MouseDown);
			this->btn1TU->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1TU_MouseMove);
			this->btn1TU->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1TU_MouseUp);
			// 
			// btn2GA
			// 
			this->btn2GA->BackColor = System::Drawing::Color::Teal;
			this->btn2GA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2GA->ForeColor = System::Drawing::Color::Transparent;
			this->btn2GA->Location = System::Drawing::Point(517, 413);
			this->btn2GA->Name = L"btn2GA";
			this->btn2GA->Size = System::Drawing::Size(165, 89);
			this->btn2GA->TabIndex = 17;
			this->btn2GA->Text = L"GA";
			this->btn2GA->UseVisualStyleBackColor = false;
			this->btn2GA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2GA_MouseDown);
			this->btn2GA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2GA_MouseMove);
			this->btn2GA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2GA_MouseUp);
			// 
			// btn4GRE
			// 
			this->btn4GRE->BackColor = System::Drawing::Color::Olive;
			this->btn4GRE->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4GRE->ForeColor = System::Drawing::Color::Transparent;
			this->btn4GRE->Location = System::Drawing::Point(517, 878);
			this->btn4GRE->Name = L"btn4GRE";
			this->btn4GRE->Size = System::Drawing::Size(165, 89);
			this->btn4GRE->TabIndex = 18;
			this->btn4GRE->Text = L"GRE";
			this->btn4GRE->UseVisualStyleBackColor = false;
			this->btn4GRE->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4GRE_MouseDown);
			this->btn4GRE->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4GRE_MouseMove);
			this->btn4GRE->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4GRE_MouseUp);
			// 
			// btn3NO
			// 
			this->btn3NO->BackColor = System::Drawing::Color::Chocolate;
			this->btn3NO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3NO->ForeColor = System::Drawing::Color::Transparent;
			this->btn3NO->Location = System::Drawing::Point(517, 643);
			this->btn3NO->Name = L"btn3NO";
			this->btn3NO->Size = System::Drawing::Size(165, 89);
			this->btn3NO->TabIndex = 19;
			this->btn3NO->Text = L"NO";
			this->btn3NO->UseVisualStyleBackColor = false;
			this->btn3NO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3NO_MouseDown);
			this->btn3NO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3NO_MouseMove);
			this->btn3NO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3NO_MouseUp);
			// 
			// btn1GA
			// 
			this->btn1GA->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1GA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1GA->ForeColor = System::Drawing::Color::Transparent;
			this->btn1GA->Location = System::Drawing::Point(353, 188);
			this->btn1GA->Name = L"btn1GA";
			this->btn1GA->Size = System::Drawing::Size(165, 89);
			this->btn1GA->TabIndex = 3;
			this->btn1GA->Text = L"GA";
			this->btn1GA->UseVisualStyleBackColor = false;
			this->btn1GA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1GA_MouseDown);
			this->btn1GA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1GA_MouseMove);
			this->btn1GA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn1GA_MouseUp);
			// 
			// btn2VIO
			// 
			this->btn2VIO->BackColor = System::Drawing::Color::Teal;
			this->btn2VIO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2VIO->ForeColor = System::Drawing::Color::Transparent;
			this->btn2VIO->Location = System::Drawing::Point(188, 413);
			this->btn2VIO->Name = L"btn2VIO";
			this->btn2VIO->Size = System::Drawing::Size(165, 89);
			this->btn2VIO->TabIndex = 4;
			this->btn2VIO->Text = L"VIO";
			this->btn2VIO->UseVisualStyleBackColor = false;
			this->btn2VIO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2VIO_MouseDown);
			this->btn2VIO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2VIO_MouseMove);
			this->btn2VIO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2VIO_MouseUp);
			// 
			// btn2TA
			// 
			this->btn2TA->BackColor = System::Drawing::Color::Teal;
			this->btn2TA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2TA->ForeColor = System::Drawing::Color::Transparent;
			this->btn2TA->Location = System::Drawing::Point(352, 413);
			this->btn2TA->Name = L"btn2TA";
			this->btn2TA->Size = System::Drawing::Size(165, 89);
			this->btn2TA->TabIndex = 4;
			this->btn2TA->Text = L"TA";
			this->btn2TA->UseVisualStyleBackColor = false;
			this->btn2TA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2TA_MouseDown);
			this->btn2TA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2TA_MouseMove);
			this->btn2TA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn2TA_MouseUp);
			// 
			// btn4JO
			// 
			this->btn4JO->BackColor = System::Drawing::Color::Olive;
			this->btn4JO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4JO->ForeColor = System::Drawing::Color::Transparent;
			this->btn4JO->Location = System::Drawing::Point(188, 878);
			this->btn4JO->Name = L"btn4JO";
			this->btn4JO->Size = System::Drawing::Size(165, 89);
			this->btn4JO->TabIndex = 4;
			this->btn4JO->Text = L"JO";
			this->btn4JO->UseVisualStyleBackColor = false;
			this->btn4JO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4JO_MouseDown);
			this->btn4JO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4JO_MouseMove);
			this->btn4JO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4JO_MouseUp);
			// 
			// btn3LI
			// 
			this->btn3LI->BackColor = System::Drawing::Color::Chocolate;
			this->btn3LI->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3LI->ForeColor = System::Drawing::Color::Transparent;
			this->btn3LI->Location = System::Drawing::Point(188, 643);
			this->btn3LI->Name = L"btn3LI";
			this->btn3LI->Size = System::Drawing::Size(165, 89);
			this->btn3LI->TabIndex = 4;
			this->btn3LI->Text = L"LI";
			this->btn3LI->UseVisualStyleBackColor = false;
			this->btn3LI->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3LI_MouseDown);
			this->btn3LI->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3LI_MouseMove);
			this->btn3LI->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3LI_MouseUp);
			// 
			// btn4CAN
			// 
			this->btn4CAN->BackColor = System::Drawing::Color::Olive;
			this->btn4CAN->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4CAN->ForeColor = System::Drawing::Color::Transparent;
			this->btn4CAN->Location = System::Drawing::Point(352, 878);
			this->btn4CAN->Name = L"btn4CAN";
			this->btn4CAN->Size = System::Drawing::Size(165, 89);
			this->btn4CAN->TabIndex = 4;
			this->btn4CAN->Text = L"CAN";
			this->btn4CAN->UseVisualStyleBackColor = false;
			this->btn4CAN->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4CAN_MouseDown);
			this->btn4CAN->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4CAN_MouseMove);
			this->btn4CAN->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn4CAN_MouseUp);
			// 
			// btn3CA
			// 
			this->btn3CA->BackColor = System::Drawing::Color::Chocolate;
			this->btn3CA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3CA->ForeColor = System::Drawing::Color::Transparent;
			this->btn3CA->Location = System::Drawing::Point(352, 643);
			this->btn3CA->Name = L"btn3CA";
			this->btn3CA->Size = System::Drawing::Size(165, 89);
			this->btn3CA->TabIndex = 4;
			this->btn3CA->Text = L"CA";
			this->btn3CA->UseVisualStyleBackColor = false;
			this->btn3CA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3CA_MouseDown);
			this->btn3CA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3CA_MouseMove);
			this->btn3CA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDD::btn3CA_MouseUp);
			// 
			// ayudaTres
			// 
			this->ayudaTres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ayudaTres.BackgroundImage")));
			this->ayudaTres->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ayudaTres->Location = System::Drawing::Point(1574, 609);
			this->ayudaTres->Name = L"ayudaTres";
			this->ayudaTres->Size = System::Drawing::Size(160, 145);
			this->ayudaTres->TabIndex = 24;
			this->ayudaTres->TabStop = false;
			this->ayudaTres->Click += gcnew System::EventHandler(this, &Act1DosDD::ayudaTres_Click);
			this->ayudaTres->MouseLeave += gcnew System::EventHandler(this, &Act1DosDD::ayudaTres_MouseLeave);
			this->ayudaTres->MouseHover += gcnew System::EventHandler(this, &Act1DosDD::ayudaTres_MouseHover);
			// 
			// ayudaUno
			// 
			this->ayudaUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ayudaUno.BackgroundImage")));
			this->ayudaUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ayudaUno->Location = System::Drawing::Point(1574, 147);
			this->ayudaUno->Name = L"ayudaUno";
			this->ayudaUno->Size = System::Drawing::Size(160, 145);
			this->ayudaUno->TabIndex = 22;
			this->ayudaUno->TabStop = false;
			this->ayudaUno->Click += gcnew System::EventHandler(this, &Act1DosDD::ayudaUno_Click);
			this->ayudaUno->MouseLeave += gcnew System::EventHandler(this, &Act1DosDD::ayudaUno_MouseLeave);
			this->ayudaUno->MouseHover += gcnew System::EventHandler(this, &Act1DosDD::ayudaUno_MouseHover);
			// 
			// ayudaDos
			// 
			this->ayudaDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ayudaDos.BackgroundImage")));
			this->ayudaDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ayudaDos->Location = System::Drawing::Point(1574, 375);
			this->ayudaDos->Name = L"ayudaDos";
			this->ayudaDos->Size = System::Drawing::Size(160, 145);
			this->ayudaDos->TabIndex = 23;
			this->ayudaDos->TabStop = false;
			this->ayudaDos->Click += gcnew System::EventHandler(this, &Act1DosDD::ayudaDos_Click);
			this->ayudaDos->MouseLeave += gcnew System::EventHandler(this, &Act1DosDD::ayudaDos_MouseLeave);
			this->ayudaDos->MouseHover += gcnew System::EventHandler(this, &Act1DosDD::ayudaDos_MouseHover);
			// 
			// ayudaCuatro
			// 
			this->ayudaCuatro->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ayudaCuatro.BackgroundImage")));
			this->ayudaCuatro->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ayudaCuatro->Location = System::Drawing::Point(1574, 838);
			this->ayudaCuatro->Name = L"ayudaCuatro";
			this->ayudaCuatro->Size = System::Drawing::Size(160, 145);
			this->ayudaCuatro->TabIndex = 25;
			this->ayudaCuatro->TabStop = false;
			this->ayudaCuatro->Click += gcnew System::EventHandler(this, &Act1DosDD::ayudaCuatro_Click);
			this->ayudaCuatro->MouseLeave += gcnew System::EventHandler(this, &Act1DosDD::ayudaCuatro_MouseLeave);
			this->ayudaCuatro->MouseHover += gcnew System::EventHandler(this, &Act1DosDD::ayudaCuatro_MouseHover);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(1511, 823);
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
			this->pictureBox4->Location = System::Drawing::Point(1545, 583);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(231, 209);
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(1515, 110);
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
			this->pictureBox2->Location = System::Drawing::Point(1481, 351);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(307, 203);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// panel1Tres
			// 
			this->panel1Tres->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Tres->Location = System::Drawing::Point(1210, 188);
			this->panel1Tres->Name = L"panel1Tres";
			this->panel1Tres->Size = System::Drawing::Size(164, 89);
			this->panel1Tres->TabIndex = 21;
			// 
			// panel2Tres
			// 
			this->panel2Tres->BackColor = System::Drawing::Color::Teal;
			this->panel2Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Tres->Location = System::Drawing::Point(1210, 414);
			this->panel2Tres->Name = L"panel2Tres";
			this->panel2Tres->Size = System::Drawing::Size(164, 89);
			this->panel2Tres->TabIndex = 13;
			// 
			// panel4Tres
			// 
			this->panel4Tres->BackColor = System::Drawing::Color::Olive;
			this->panel4Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Tres->Location = System::Drawing::Point(1210, 880);
			this->panel4Tres->Name = L"panel4Tres";
			this->panel4Tres->Size = System::Drawing::Size(164, 89);
			this->panel4Tres->TabIndex = 14;
			// 
			// panel3Tres
			// 
			this->panel3Tres->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Tres->Location = System::Drawing::Point(1210, 643);
			this->panel3Tres->Name = L"panel3Tres";
			this->panel3Tres->Size = System::Drawing::Size(164, 89);
			this->panel3Tres->TabIndex = 15;
			// 
			// panel1Dos
			// 
			this->panel1Dos->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Dos->Location = System::Drawing::Point(1040, 188);
			this->panel1Dos->Name = L"panel1Dos";
			this->panel1Dos->Size = System::Drawing::Size(164, 89);
			this->panel1Dos->TabIndex = 8;
			// 
			// panel1Uno
			// 
			this->panel1Uno->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Uno->Location = System::Drawing::Point(870, 188);
			this->panel1Uno->Name = L"panel1Uno";
			this->panel1Uno->Size = System::Drawing::Size(164, 89);
			this->panel1Uno->TabIndex = 7;
			// 
			// panel2Dos
			// 
			this->panel2Dos->BackColor = System::Drawing::Color::Teal;
			this->panel2Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Dos->Location = System::Drawing::Point(1040, 414);
			this->panel2Dos->Name = L"panel2Dos";
			this->panel2Dos->Size = System::Drawing::Size(164, 89);
			this->panel2Dos->TabIndex = 11;
			// 
			// panel2Uno
			// 
			this->panel2Uno->BackColor = System::Drawing::Color::Teal;
			this->panel2Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Uno->Location = System::Drawing::Point(870, 414);
			this->panel2Uno->Name = L"panel2Uno";
			this->panel2Uno->Size = System::Drawing::Size(164, 89);
			this->panel2Uno->TabIndex = 10;
			// 
			// panel4Dos
			// 
			this->panel4Dos->BackColor = System::Drawing::Color::Olive;
			this->panel4Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Dos->Location = System::Drawing::Point(1041, 880);
			this->panel4Dos->Name = L"panel4Dos";
			this->panel4Dos->Size = System::Drawing::Size(164, 89);
			this->panel4Dos->TabIndex = 11;
			// 
			// panel4Uno
			// 
			this->panel4Uno->BackColor = System::Drawing::Color::Olive;
			this->panel4Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Uno->Location = System::Drawing::Point(870, 880);
			this->panel4Uno->Name = L"panel4Uno";
			this->panel4Uno->Size = System::Drawing::Size(164, 89);
			this->panel4Uno->TabIndex = 10;
			// 
			// panel3Dos
			// 
			this->panel3Dos->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Dos->Location = System::Drawing::Point(1040, 643);
			this->panel3Dos->Name = L"panel3Dos";
			this->panel3Dos->Size = System::Drawing::Size(164, 89);
			this->panel3Dos->TabIndex = 11;
			// 
			// panel3Uno
			// 
			this->panel3Uno->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Uno->Location = System::Drawing::Point(870, 643);
			this->panel3Uno->Name = L"panel3Uno";
			this->panel3Uno->Size = System::Drawing::Size(164, 89);
			this->panel3Uno->TabIndex = 10;
			// 
			// panel3Cuatro
			// 
			this->panel3Cuatro->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Cuatro->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Cuatro->Location = System::Drawing::Point(1380, 643);
			this->panel3Cuatro->Name = L"panel3Cuatro";
			this->panel3Cuatro->Size = System::Drawing::Size(164, 89);
			this->panel3Cuatro->TabIndex = 20;
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
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1DosDD::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1DosDD::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1DosDD::btnAyuda_MouseHover);
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->btnListo);
			this->panel5->Controls->Add(this->btnVolver);
			this->panel5->Location = System::Drawing::Point(3, 723);
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
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1DosDD::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1DosDD::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1DosDD::btnListo_MouseHover);
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
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1DosDD::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1DosDD::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1DosDD::btnVolver_MouseHover);
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
			this->panel4->Size = System::Drawing::Size(1836, 91);
			this->panel4->TabIndex = 7;
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::Color::White;
			this->instruccion2->Location = System::Drawing::Point(86, 9);
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
			this->instruccion1->Location = System::Drawing::Point(92, 11);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(1400, 68);
			this->instruccion1->TabIndex = 5;
			this->instruccion1->Text = L"Ordenemos las sílabas para descubrir los objetos del mar";
			// 
			// Act1DosDD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2450, 1334);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panelPrincipal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Act1DosDD";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1DosDD";
			this->Activated += gcnew System::EventHandler(this, &Act1DosDD::Act1DosDD_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1DosDD::Act1DosDD_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1DosDD::Act1DosDD_Load);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->panelPrincipal->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaTres))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaUno))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaDos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ayudaCuatro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
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
	private: System::Void Act1DosDD_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosDD_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosDD_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos, bool listoTres, bool listoCuatro);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void moverBoton(System::Windows::Forms::Button^ boton);
	private: System::Void btn1TU_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1GA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1TOR_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2VIO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2TA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2GA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3LI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3NO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3PE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4JO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4CAN_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4GRE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1TU_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1GA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1TOR_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2VIO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2TA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2GA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3LI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3PE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3NO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4JO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4CAN_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4GRE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1TU_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1GA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1TOR_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2VIO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2TA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2GA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3LI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3PE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3NO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4JO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4CAN_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4GRE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	};
}
