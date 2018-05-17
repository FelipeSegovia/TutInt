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
	/// Resumen de Act1UnoDI
	/// </summary>
	public ref class Act1UnoDI : public System::Windows::Forms::Form
	{
	public:
		Act1UnoDI(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act1UnoDI(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act1UnoDI()
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
	private: int xbtn1CHA, ybtn1CHA, xbtn1CON, ybtn1CON, xbtn2RON, ybtn2RON, xbtn2CA, ybtn2CA, xbtn2MA, ybtn2MA, xbtn3ME, ybtn3ME, xbtn3JA, ybtn3JA, xbtn3AL, ybtn3AL, xbtn4RON, ybtn4RON, xbtn4TI, ybtn4TI, xbtn4BU, ybtn4BU;		// Guardar la posicion original del boton
	private: bool listoBtn1CHA, listoBtn1CON, listoBtn2RON, listoBtn2CA, listoBtn2MA, listoBtn3ME, listoBtn3JA, listoBtn3AL, listoBtn4RON, listoBtn4TI, listoBtn4BU;
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
	private: System::Windows::Forms::Button^  btn1CHA;
	private: System::Windows::Forms::Button^  btn1CON;
	private: System::Windows::Forms::Button^  btn2RON;
	private: System::Windows::Forms::Button^  btn2CA;
	private: System::Windows::Forms::Button^  btn4RON;
	private: System::Windows::Forms::Button^  btn3ME;
	private: System::Windows::Forms::Button^  btn4TI;
	private: System::Windows::Forms::Button^  btn3JA;
	private: System::Windows::Forms::Panel^  panel1Dos;
	private: System::Windows::Forms::Panel^  panel1Uno;
	private: System::Windows::Forms::Panel^  panel2Dos;
	private: System::Windows::Forms::Panel^  panel2Uno;
	private: System::Windows::Forms::Panel^  panel4Dos;
	private: System::Windows::Forms::Panel^  panel4Uno;
	private: System::Windows::Forms::Panel^  panel3Dos;
	private: System::Windows::Forms::Panel^  panel3Uno;
	private: System::Windows::Forms::Button^  btn2MA;
	private: System::Windows::Forms::Button^  btn4BU;
	private: System::Windows::Forms::Button^  btn3AL;
	private: System::Windows::Forms::Panel^  panel2Tres;
	private: System::Windows::Forms::Panel^  panel4Tres;
	private: System::Windows::Forms::Panel^  panel3Tres;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1UnoDI::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn1CHA = (gcnew System::Windows::Forms::Button());
			this->btn2MA = (gcnew System::Windows::Forms::Button());
			this->btn4BU = (gcnew System::Windows::Forms::Button());
			this->btn3AL = (gcnew System::Windows::Forms::Button());
			this->btn1CON = (gcnew System::Windows::Forms::Button());
			this->btn2RON = (gcnew System::Windows::Forms::Button());
			this->btn2CA = (gcnew System::Windows::Forms::Button());
			this->btn4RON = (gcnew System::Windows::Forms::Button());
			this->btn3ME = (gcnew System::Windows::Forms::Button());
			this->btn4TI = (gcnew System::Windows::Forms::Button());
			this->btn3JA = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2Tres = (gcnew System::Windows::Forms::Panel());
			this->panel4Tres = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3Tres = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
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
			this->instruccion1 = (gcnew System::Windows::Forms::Label());
			this->instruccion2 = (gcnew System::Windows::Forms::Label());
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->panelPrincipal->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1UnoDI::timer1_Tick);
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
			this->panel6->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(1034, 31);
			this->panel6->TabIndex = 5;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(5, 2);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(31, 28);
			this->pictureBox7->TabIndex = 33;
			this->pictureBox7->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(35, 3);
			this->label1->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 26);
			this->label1->TabIndex = 32;
			this->label1->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(969, 2);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(27, 26);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1UnoDI::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(1001, 2);
			this->picCerrar->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(27, 26);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1UnoDI::picCerrar_Click);
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
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(1034, 625);
			this->panelPrincipal->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->btn1CHA);
			this->panel2->Controls->Add(this->btn2MA);
			this->panel2->Controls->Add(this->btn4BU);
			this->panel2->Controls->Add(this->btn3AL);
			this->panel2->Controls->Add(this->btn1CON);
			this->panel2->Controls->Add(this->btn2RON);
			this->panel2->Controls->Add(this->btn2CA);
			this->panel2->Controls->Add(this->btn4RON);
			this->panel2->Controls->Add(this->btn3ME);
			this->panel2->Controls->Add(this->btn4TI);
			this->panel2->Controls->Add(this->btn3JA);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->panel2Tres);
			this->panel2->Controls->Add(this->panel4Tres);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->panel3Tres);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->panel1Dos);
			this->panel2->Controls->Add(this->panel1Uno);
			this->panel2->Controls->Add(this->panel2Dos);
			this->panel2->Controls->Add(this->panel2Uno);
			this->panel2->Controls->Add(this->panel4Dos);
			this->panel2->Controls->Add(this->panel4Uno);
			this->panel2->Controls->Add(this->panel3Dos);
			this->panel2->Controls->Add(this->panel3Uno);
			this->panel2->Location = System::Drawing::Point(254, 89);
			this->panel2->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(777, 483);
			this->panel2->TabIndex = 3;
			// 
			// btn1CHA
			// 
			this->btn1CHA->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1CHA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1CHA->ForeColor = System::Drawing::Color::Transparent;
			this->btn1CHA->Location = System::Drawing::Point(208, 85);
			this->btn1CHA->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn1CHA->Name = L"btn1CHA";
			this->btn1CHA->Size = System::Drawing::Size(75, 40);
			this->btn1CHA->TabIndex = 3;
			this->btn1CHA->Text = L"CHA";
			this->btn1CHA->UseVisualStyleBackColor = false;
			this->btn1CHA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn1CHA_MouseDown);
			this->btn1CHA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn1CHA_MouseMove);
			this->btn1CHA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn1CHA_MouseUp);
			// 
			// btn2MA
			// 
			this->btn2MA->BackColor = System::Drawing::Color::Teal;
			this->btn2MA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2MA->ForeColor = System::Drawing::Color::Transparent;
			this->btn2MA->Location = System::Drawing::Point(363, 186);
			this->btn2MA->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn2MA->Name = L"btn2MA";
			this->btn2MA->Size = System::Drawing::Size(75, 40);
			this->btn2MA->TabIndex = 17;
			this->btn2MA->Text = L"MA";
			this->btn2MA->UseVisualStyleBackColor = false;
			this->btn2MA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2MA_MouseDown);
			this->btn2MA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2MA_MouseMove);
			this->btn2MA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2MA_MouseUp);
			// 
			// btn4BU
			// 
			this->btn4BU->BackColor = System::Drawing::Color::Olive;
			this->btn4BU->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4BU->ForeColor = System::Drawing::Color::Transparent;
			this->btn4BU->Location = System::Drawing::Point(363, 394);
			this->btn4BU->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn4BU->Name = L"btn4BU";
			this->btn4BU->Size = System::Drawing::Size(75, 40);
			this->btn4BU->TabIndex = 18;
			this->btn4BU->Text = L"BU";
			this->btn4BU->UseVisualStyleBackColor = false;
			this->btn4BU->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4BU_MouseDown);
			this->btn4BU->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4BU_MouseMove);
			this->btn4BU->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4BU_MouseUp);
			// 
			// btn3AL
			// 
			this->btn3AL->BackColor = System::Drawing::Color::Chocolate;
			this->btn3AL->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3AL->ForeColor = System::Drawing::Color::Transparent;
			this->btn3AL->Location = System::Drawing::Point(363, 289);
			this->btn3AL->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn3AL->Name = L"btn3AL";
			this->btn3AL->Size = System::Drawing::Size(75, 40);
			this->btn3AL->TabIndex = 19;
			this->btn3AL->Text = L"AL";
			this->btn3AL->UseVisualStyleBackColor = false;
			this->btn3AL->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3AL_MouseDown);
			this->btn3AL->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3AL_MouseMove);
			this->btn3AL->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3AL_MouseUp);
			// 
			// btn1CON
			// 
			this->btn1CON->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1CON->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1CON->ForeColor = System::Drawing::Color::Transparent;
			this->btn1CON->Location = System::Drawing::Point(286, 85);
			this->btn1CON->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn1CON->Name = L"btn1CON";
			this->btn1CON->Size = System::Drawing::Size(75, 40);
			this->btn1CON->TabIndex = 3;
			this->btn1CON->Text = L"CON";
			this->btn1CON->UseVisualStyleBackColor = false;
			this->btn1CON->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn1CON_MouseDown);
			this->btn1CON->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn1CON_MouseMove);
			this->btn1CON->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn1CON_MouseUp);
			// 
			// btn2RON
			// 
			this->btn2RON->BackColor = System::Drawing::Color::Teal;
			this->btn2RON->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2RON->ForeColor = System::Drawing::Color::Transparent;
			this->btn2RON->Location = System::Drawing::Point(208, 186);
			this->btn2RON->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn2RON->Name = L"btn2RON";
			this->btn2RON->Size = System::Drawing::Size(75, 40);
			this->btn2RON->TabIndex = 4;
			this->btn2RON->Text = L"RÓN";
			this->btn2RON->UseVisualStyleBackColor = false;
			this->btn2RON->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2RON_MouseDown);
			this->btn2RON->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2RON_MouseMove);
			this->btn2RON->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2RON_MouseUp);
			// 
			// btn2CA
			// 
			this->btn2CA->BackColor = System::Drawing::Color::Teal;
			this->btn2CA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2CA->ForeColor = System::Drawing::Color::Transparent;
			this->btn2CA->Location = System::Drawing::Point(286, 186);
			this->btn2CA->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn2CA->Name = L"btn2CA";
			this->btn2CA->Size = System::Drawing::Size(75, 40);
			this->btn2CA->TabIndex = 4;
			this->btn2CA->Text = L"CA";
			this->btn2CA->UseVisualStyleBackColor = false;
			this->btn2CA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2CA_MouseDown);
			this->btn2CA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2CA_MouseMove);
			this->btn2CA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn2CA_MouseUp);
			// 
			// btn4RON
			// 
			this->btn4RON->BackColor = System::Drawing::Color::Olive;
			this->btn4RON->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4RON->ForeColor = System::Drawing::Color::Transparent;
			this->btn4RON->Location = System::Drawing::Point(208, 394);
			this->btn4RON->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn4RON->Name = L"btn4RON";
			this->btn4RON->Size = System::Drawing::Size(75, 40);
			this->btn4RON->TabIndex = 4;
			this->btn4RON->Text = L"RÓN";
			this->btn4RON->UseVisualStyleBackColor = false;
			this->btn4RON->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4RON_MouseDown);
			this->btn4RON->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4RON_MouseMove);
			this->btn4RON->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4RON_MouseUp);
			// 
			// btn3ME
			// 
			this->btn3ME->BackColor = System::Drawing::Color::Chocolate;
			this->btn3ME->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3ME->ForeColor = System::Drawing::Color::Transparent;
			this->btn3ME->Location = System::Drawing::Point(208, 289);
			this->btn3ME->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn3ME->Name = L"btn3ME";
			this->btn3ME->Size = System::Drawing::Size(75, 40);
			this->btn3ME->TabIndex = 4;
			this->btn3ME->Text = L"ME";
			this->btn3ME->UseVisualStyleBackColor = false;
			this->btn3ME->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3ME_MouseDown);
			this->btn3ME->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3ME_MouseMove);
			this->btn3ME->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3ME_MouseUp);
			// 
			// btn4TI
			// 
			this->btn4TI->BackColor = System::Drawing::Color::Olive;
			this->btn4TI->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4TI->ForeColor = System::Drawing::Color::Transparent;
			this->btn4TI->Location = System::Drawing::Point(286, 394);
			this->btn4TI->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn4TI->Name = L"btn4TI";
			this->btn4TI->Size = System::Drawing::Size(75, 40);
			this->btn4TI->TabIndex = 4;
			this->btn4TI->Text = L"TI";
			this->btn4TI->UseVisualStyleBackColor = false;
			this->btn4TI->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4TI_MouseDown);
			this->btn4TI->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4TI_MouseMove);
			this->btn4TI->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn4TI_MouseUp);
			// 
			// btn3JA
			// 
			this->btn3JA->BackColor = System::Drawing::Color::Chocolate;
			this->btn3JA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3JA->ForeColor = System::Drawing::Color::Transparent;
			this->btn3JA->Location = System::Drawing::Point(286, 289);
			this->btn3JA->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn3JA->Name = L"btn3JA";
			this->btn3JA->Size = System::Drawing::Size(75, 40);
			this->btn3JA->TabIndex = 4;
			this->btn3JA->Text = L"JA";
			this->btn3JA->UseVisualStyleBackColor = false;
			this->btn3JA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3JA_MouseDown);
			this->btn3JA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3JA_MouseMove);
			this->btn3JA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDI::btn3JA_MouseUp);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(75, 372);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(123, 82);
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			// 
			// panel2Tres
			// 
			this->panel2Tres->BackColor = System::Drawing::Color::Teal;
			this->panel2Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Tres->Location = System::Drawing::Point(623, 186);
			this->panel2Tres->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel2Tres->Name = L"panel2Tres";
			this->panel2Tres->Size = System::Drawing::Size(77, 42);
			this->panel2Tres->TabIndex = 13;
			// 
			// panel4Tres
			// 
			this->panel4Tres->BackColor = System::Drawing::Color::Olive;
			this->panel4Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Tres->Location = System::Drawing::Point(623, 395);
			this->panel4Tres->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel4Tres->Name = L"panel4Tres";
			this->panel4Tres->Size = System::Drawing::Size(77, 42);
			this->panel4Tres->TabIndex = 14;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(71, 269);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(127, 82);
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			// 
			// panel3Tres
			// 
			this->panel3Tres->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Tres->Location = System::Drawing::Point(623, 289);
			this->panel3Tres->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel3Tres->Name = L"panel3Tres";
			this->panel3Tres->Size = System::Drawing::Size(77, 42);
			this->panel3Tres->TabIndex = 15;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(75, 164);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(114, 82);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(75, 61);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(115, 82);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// panel1Dos
			// 
			this->panel1Dos->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Dos->Location = System::Drawing::Point(546, 85);
			this->panel1Dos->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel1Dos->Name = L"panel1Dos";
			this->panel1Dos->Size = System::Drawing::Size(77, 42);
			this->panel1Dos->TabIndex = 8;
			// 
			// panel1Uno
			// 
			this->panel1Uno->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Uno->Location = System::Drawing::Point(470, 85);
			this->panel1Uno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel1Uno->Name = L"panel1Uno";
			this->panel1Uno->Size = System::Drawing::Size(77, 42);
			this->panel1Uno->TabIndex = 7;
			// 
			// panel2Dos
			// 
			this->panel2Dos->BackColor = System::Drawing::Color::Teal;
			this->panel2Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Dos->Location = System::Drawing::Point(546, 186);
			this->panel2Dos->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel2Dos->Name = L"panel2Dos";
			this->panel2Dos->Size = System::Drawing::Size(77, 42);
			this->panel2Dos->TabIndex = 11;
			// 
			// panel2Uno
			// 
			this->panel2Uno->BackColor = System::Drawing::Color::Teal;
			this->panel2Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Uno->Location = System::Drawing::Point(470, 186);
			this->panel2Uno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel2Uno->Name = L"panel2Uno";
			this->panel2Uno->Size = System::Drawing::Size(77, 42);
			this->panel2Uno->TabIndex = 10;
			// 
			// panel4Dos
			// 
			this->panel4Dos->BackColor = System::Drawing::Color::Olive;
			this->panel4Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Dos->Location = System::Drawing::Point(547, 395);
			this->panel4Dos->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel4Dos->Name = L"panel4Dos";
			this->panel4Dos->Size = System::Drawing::Size(77, 42);
			this->panel4Dos->TabIndex = 11;
			// 
			// panel4Uno
			// 
			this->panel4Uno->BackColor = System::Drawing::Color::Olive;
			this->panel4Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Uno->Location = System::Drawing::Point(470, 395);
			this->panel4Uno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel4Uno->Name = L"panel4Uno";
			this->panel4Uno->Size = System::Drawing::Size(77, 42);
			this->panel4Uno->TabIndex = 10;
			// 
			// panel3Dos
			// 
			this->panel3Dos->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Dos->Location = System::Drawing::Point(546, 289);
			this->panel3Dos->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel3Dos->Name = L"panel3Dos";
			this->panel3Dos->Size = System::Drawing::Size(77, 42);
			this->panel3Dos->TabIndex = 11;
			// 
			// panel3Uno
			// 
			this->panel3Uno->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Uno->Location = System::Drawing::Point(470, 289);
			this->panel3Uno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel3Uno->Name = L"panel3Uno";
			this->panel3Uno->Size = System::Drawing::Size(77, 42);
			this->panel3Uno->TabIndex = 10;
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(0, 39);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(183, 112);
			this->btnAyuda->TabIndex = 11;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1UnoDI::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDI::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1UnoDI::btnAyuda_MouseHover);
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->btnListo);
			this->panel5->Controls->Add(this->btnVolver);
			this->panel5->Location = System::Drawing::Point(17, 324);
			this->panel5->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(207, 230);
			this->panel5->TabIndex = 10;
			// 
			// btnListo
			// 
			this->btnListo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnListo.BackgroundImage")));
			this->btnListo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnListo->Enabled = false;
			this->btnListo->Location = System::Drawing::Point(25, 90);
			this->btnListo->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btnListo->Name = L"btnListo";
			this->btnListo->Size = System::Drawing::Size(171, 66);
			this->btnListo->TabIndex = 1;
			this->btnListo->TabStop = false;
			this->btnListo->Visible = false;
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1UnoDI::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDI::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1UnoDI::btnListo_MouseHover);
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(10, 23);
			this->btnVolver->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(181, 69);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1UnoDI::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDI::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1UnoDI::btnVolver_MouseHover);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->instruccion1);
			this->panel4->Controls->Add(this->instruccion2);
			this->panel4->Location = System::Drawing::Point(185, 33);
			this->panel4->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(788, 41);
			this->panel4->TabIndex = 7;
			// 
			// instruccion1
			// 
			this->instruccion1->AutoSize = true;
			this->instruccion1->BackColor = System::Drawing::Color::Transparent;
			this->instruccion1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion1->ForeColor = System::Drawing::Color::White;
			this->instruccion1->Location = System::Drawing::Point(42, 5);
			this->instruccion1->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(637, 31);
			this->instruccion1->TabIndex = 5;
			this->instruccion1->Text = L"Ordenemos las sílabas para descubrir los objetos del mar";
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::Color::White;
			this->instruccion2->Location = System::Drawing::Point(37, 4);
			this->instruccion2->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(747, 31);
			this->instruccion2->TabIndex = 4;
			this->instruccion2->Text = L"Desliza cada sílaba hacia los recuadros vacios para crear la palabra";
			this->instruccion2->Visible = false;
			// 
			// Act1UnoDI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1034, 625);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panelPrincipal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->Name = L"Act1UnoDI";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1UnoDI";
			this->Activated += gcnew System::EventHandler(this, &Act1UnoDI::Act1UnoDI_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1UnoDI::Act1UnoDI_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1UnoDI::Act1UnoDI_Load);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->panelPrincipal->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoDI_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoDI_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoDI_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos, bool listoTres);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void moverBoton(System::Windows::Forms::Button^ boton);
	private: System::Void btn1CHA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CON_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2RON_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2MA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3ME_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3JA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3AL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4RON_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4TI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4BU_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CHA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CON_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2RON_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2MA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3ME_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3JA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3AL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4RON_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4TI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4BU_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CHA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CON_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2RON_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2MA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3ME_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3JA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3AL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4RON_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4TI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4BU_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	};
}
