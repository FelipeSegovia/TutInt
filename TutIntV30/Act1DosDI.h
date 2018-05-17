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
	/// Resumen de Act1DosDI
	/// </summary>
	public ref class Act1DosDI : public System::Windows::Forms::Form
	{
	public:
		Act1DosDI(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act1DosDI(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act1DosDI()
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
	private: int xbtn1MAR, ybtn1MAR, xbtn1CA, ybtn1CA, xbtn1LA, ybtn1LA, xbtn2DU, ybtn2DU, xbtn2SA, ybtn2SA, xbtn2ME, ybtn2ME, xbtn3NA, ybtn3NA, xbtn3RE, ybtn3RE, xbtn3SI, ybtn3SI, xbtn4JAS, ybtn4JAS, xbtn4ES, ybtn4ES, xbtn4PON, ybtn4PON;		// Guardar la posicion original del boton
	private: bool listoBtn1MAR, listoBtn1CA, listoBtn1LA, listoBtn2DU, listoBtn2SA, listoBtn2ME, listoBtn3NA, listoBtn3RE, listoBtn3SI, listoBtn4JAS, listoBtn4ES, listoBtn4PON;
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
	private: System::Windows::Forms::Button^  btn1MAR;
	private: System::Windows::Forms::Button^  btn1CA;
	private: System::Windows::Forms::Button^  btn2DU;
	private: System::Windows::Forms::Button^  btn2SA;
	private: System::Windows::Forms::Button^  btn4JAS;
	private: System::Windows::Forms::Button^  btn3NA;
	private: System::Windows::Forms::Button^  btn4ES;
	private: System::Windows::Forms::Button^  btn3RE;
	private: System::Windows::Forms::Panel^  panel1Dos;
	private: System::Windows::Forms::Panel^  panel1Uno;
	private: System::Windows::Forms::Panel^  panel2Dos;
	private: System::Windows::Forms::Panel^  panel2Uno;
	private: System::Windows::Forms::Panel^  panel4Dos;
	private: System::Windows::Forms::Panel^  panel4Uno;
	private: System::Windows::Forms::Panel^  panel3Dos;
	private: System::Windows::Forms::Panel^  panel3Uno;
	private: System::Windows::Forms::Button^  btn2ME;
	private: System::Windows::Forms::Button^  btn4PON;
	private: System::Windows::Forms::Button^  btn3SI;
	private: System::Windows::Forms::Panel^  panel2Tres;
	private: System::Windows::Forms::Panel^  panel4Tres;
	private: System::Windows::Forms::Panel^  panel3Tres;
	private: System::Windows::Forms::Button^  btn1LA;
	private: System::Windows::Forms::Panel^  panel1Tres;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1DosDI::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn1LA = (gcnew System::Windows::Forms::Button());
			this->btn1MAR = (gcnew System::Windows::Forms::Button());
			this->btn2ME = (gcnew System::Windows::Forms::Button());
			this->btn4PON = (gcnew System::Windows::Forms::Button());
			this->btn3SI = (gcnew System::Windows::Forms::Button());
			this->btn1CA = (gcnew System::Windows::Forms::Button());
			this->btn2DU = (gcnew System::Windows::Forms::Button());
			this->btn2SA = (gcnew System::Windows::Forms::Button());
			this->btn4JAS = (gcnew System::Windows::Forms::Button());
			this->btn3NA = (gcnew System::Windows::Forms::Button());
			this->btn4ES = (gcnew System::Windows::Forms::Button());
			this->btn3RE = (gcnew System::Windows::Forms::Button());
			this->panel1Tres = (gcnew System::Windows::Forms::Panel());
			this->panel2Tres = (gcnew System::Windows::Forms::Panel());
			this->panel4Tres = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
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
			this->instruccion2 = (gcnew System::Windows::Forms::Label());
			this->instruccion1 = (gcnew System::Windows::Forms::Label());
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->panelPrincipal->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
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
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1DosDI::timer1_Tick);
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
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1DosDI::picMinimizar_Click);
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
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1DosDI::picCerrar_Click);
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
			this->panel2->Controls->Add(this->btn1LA);
			this->panel2->Controls->Add(this->btn1MAR);
			this->panel2->Controls->Add(this->btn2ME);
			this->panel2->Controls->Add(this->btn4PON);
			this->panel2->Controls->Add(this->btn3SI);
			this->panel2->Controls->Add(this->btn1CA);
			this->panel2->Controls->Add(this->btn2DU);
			this->panel2->Controls->Add(this->btn2SA);
			this->panel2->Controls->Add(this->btn4JAS);
			this->panel2->Controls->Add(this->btn3NA);
			this->panel2->Controls->Add(this->btn4ES);
			this->panel2->Controls->Add(this->btn3RE);
			this->panel2->Controls->Add(this->panel1Tres);
			this->panel2->Controls->Add(this->panel2Tres);
			this->panel2->Controls->Add(this->panel4Tres);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->pictureBox3);
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
			this->panel2->Location = System::Drawing::Point(592, 185);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1813, 1065);
			this->panel2->TabIndex = 3;
			// 
			// btn1LA
			// 
			this->btn1LA->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1LA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1LA->ForeColor = System::Drawing::Color::Transparent;
			this->btn1LA->Location = System::Drawing::Point(848, 189);
			this->btn1LA->Name = L"btn1LA";
			this->btn1LA->Size = System::Drawing::Size(175, 89);
			this->btn1LA->TabIndex = 20;
			this->btn1LA->Text = L"LA";
			this->btn1LA->UseVisualStyleBackColor = false;
			this->btn1LA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1LA_MouseDown);
			this->btn1LA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1LA_MouseMove);
			this->btn1LA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1LA_MouseUp);
			// 
			// btn1MAR
			// 
			this->btn1MAR->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1MAR->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1MAR->ForeColor = System::Drawing::Color::Transparent;
			this->btn1MAR->Location = System::Drawing::Point(486, 189);
			this->btn1MAR->Name = L"btn1MAR";
			this->btn1MAR->Size = System::Drawing::Size(175, 89);
			this->btn1MAR->TabIndex = 3;
			this->btn1MAR->Text = L"MAR";
			this->btn1MAR->UseVisualStyleBackColor = false;
			this->btn1MAR->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1MAR_MouseDown);
			this->btn1MAR->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1MAR_MouseMove);
			this->btn1MAR->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1MAR_MouseUp);
			// 
			// btn2ME
			// 
			this->btn2ME->BackColor = System::Drawing::Color::Teal;
			this->btn2ME->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2ME->ForeColor = System::Drawing::Color::Transparent;
			this->btn2ME->Location = System::Drawing::Point(848, 414);
			this->btn2ME->Name = L"btn2ME";
			this->btn2ME->Size = System::Drawing::Size(175, 89);
			this->btn2ME->TabIndex = 17;
			this->btn2ME->Text = L"ME";
			this->btn2ME->UseVisualStyleBackColor = false;
			this->btn2ME->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2ME_MouseDown);
			this->btn2ME->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2ME_MouseMove);
			this->btn2ME->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2ME_MouseUp);
			// 
			// btn4PON
			// 
			this->btn4PON->BackColor = System::Drawing::Color::Olive;
			this->btn4PON->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4PON->ForeColor = System::Drawing::Color::Transparent;
			this->btn4PON->Location = System::Drawing::Point(848, 879);
			this->btn4PON->Name = L"btn4PON";
			this->btn4PON->Size = System::Drawing::Size(175, 89);
			this->btn4PON->TabIndex = 18;
			this->btn4PON->Text = L"PON";
			this->btn4PON->UseVisualStyleBackColor = false;
			this->btn4PON->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4PON_MouseDown);
			this->btn4PON->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4PON_MouseMove);
			this->btn4PON->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4PON_MouseUp);
			// 
			// btn3SI
			// 
			this->btn3SI->BackColor = System::Drawing::Color::Chocolate;
			this->btn3SI->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3SI->ForeColor = System::Drawing::Color::Transparent;
			this->btn3SI->Location = System::Drawing::Point(848, 644);
			this->btn3SI->Name = L"btn3SI";
			this->btn3SI->Size = System::Drawing::Size(175, 89);
			this->btn3SI->TabIndex = 19;
			this->btn3SI->Text = L"SI";
			this->btn3SI->UseVisualStyleBackColor = false;
			this->btn3SI->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3SI_MouseDown);
			this->btn3SI->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3SI_MouseMove);
			this->btn3SI->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3SI_MouseUp);
			// 
			// btn1CA
			// 
			this->btn1CA->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1CA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1CA->ForeColor = System::Drawing::Color::Transparent;
			this->btn1CA->Location = System::Drawing::Point(668, 189);
			this->btn1CA->Name = L"btn1CA";
			this->btn1CA->Size = System::Drawing::Size(175, 89);
			this->btn1CA->TabIndex = 3;
			this->btn1CA->Text = L"CA";
			this->btn1CA->UseVisualStyleBackColor = false;
			this->btn1CA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1CA_MouseDown);
			this->btn1CA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1CA_MouseMove);
			this->btn1CA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn1CA_MouseUp);
			// 
			// btn2DU
			// 
			this->btn2DU->BackColor = System::Drawing::Color::Teal;
			this->btn2DU->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2DU->ForeColor = System::Drawing::Color::Transparent;
			this->btn2DU->Location = System::Drawing::Point(486, 414);
			this->btn2DU->Name = L"btn2DU";
			this->btn2DU->Size = System::Drawing::Size(175, 89);
			this->btn2DU->TabIndex = 4;
			this->btn2DU->Text = L"DU";
			this->btn2DU->UseVisualStyleBackColor = false;
			this->btn2DU->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2DU_MouseDown);
			this->btn2DU->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2DU_MouseMove);
			this->btn2DU->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2DU_MouseUp);
			// 
			// btn2SA
			// 
			this->btn2SA->BackColor = System::Drawing::Color::Teal;
			this->btn2SA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2SA->ForeColor = System::Drawing::Color::Transparent;
			this->btn2SA->Location = System::Drawing::Point(668, 414);
			this->btn2SA->Name = L"btn2SA";
			this->btn2SA->Size = System::Drawing::Size(175, 89);
			this->btn2SA->TabIndex = 4;
			this->btn2SA->Text = L"SA";
			this->btn2SA->UseVisualStyleBackColor = false;
			this->btn2SA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2SA_MouseDown);
			this->btn2SA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2SA_MouseMove);
			this->btn2SA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn2SA_MouseUp);
			// 
			// btn4JAS
			// 
			this->btn4JAS->BackColor = System::Drawing::Color::Olive;
			this->btn4JAS->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4JAS->ForeColor = System::Drawing::Color::Transparent;
			this->btn4JAS->Location = System::Drawing::Point(486, 879);
			this->btn4JAS->Name = L"btn4JAS";
			this->btn4JAS->Size = System::Drawing::Size(175, 89);
			this->btn4JAS->TabIndex = 4;
			this->btn4JAS->Text = L"JAS";
			this->btn4JAS->UseVisualStyleBackColor = false;
			this->btn4JAS->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4JAS_MouseDown);
			this->btn4JAS->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4JAS_MouseMove);
			this->btn4JAS->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4JAS_MouseUp);
			// 
			// btn3NA
			// 
			this->btn3NA->BackColor = System::Drawing::Color::Chocolate;
			this->btn3NA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3NA->ForeColor = System::Drawing::Color::Transparent;
			this->btn3NA->Location = System::Drawing::Point(486, 644);
			this->btn3NA->Name = L"btn3NA";
			this->btn3NA->Size = System::Drawing::Size(175, 89);
			this->btn3NA->TabIndex = 4;
			this->btn3NA->Text = L"NA";
			this->btn3NA->UseVisualStyleBackColor = false;
			this->btn3NA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3NA_MouseDown);
			this->btn3NA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3NA_MouseMove);
			this->btn3NA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3NA_MouseUp);
			// 
			// btn4ES
			// 
			this->btn4ES->BackColor = System::Drawing::Color::Olive;
			this->btn4ES->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4ES->ForeColor = System::Drawing::Color::Transparent;
			this->btn4ES->Location = System::Drawing::Point(668, 879);
			this->btn4ES->Name = L"btn4ES";
			this->btn4ES->Size = System::Drawing::Size(175, 89);
			this->btn4ES->TabIndex = 4;
			this->btn4ES->Text = L"ES";
			this->btn4ES->UseVisualStyleBackColor = false;
			this->btn4ES->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4ES_MouseDown);
			this->btn4ES->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4ES_MouseMove);
			this->btn4ES->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn4ES_MouseUp);
			// 
			// btn3RE
			// 
			this->btn3RE->BackColor = System::Drawing::Color::Chocolate;
			this->btn3RE->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3RE->ForeColor = System::Drawing::Color::Transparent;
			this->btn3RE->Location = System::Drawing::Point(668, 644);
			this->btn3RE->Name = L"btn3RE";
			this->btn3RE->Size = System::Drawing::Size(175, 89);
			this->btn3RE->TabIndex = 4;
			this->btn3RE->Text = L"RE";
			this->btn3RE->UseVisualStyleBackColor = false;
			this->btn3RE->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3RE_MouseDown);
			this->btn3RE->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3RE_MouseMove);
			this->btn3RE->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDI::btn3RE_MouseUp);
			// 
			// panel1Tres
			// 
			this->panel1Tres->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Tres->Location = System::Drawing::Point(1453, 189);
			this->panel1Tres->Name = L"panel1Tres";
			this->panel1Tres->Size = System::Drawing::Size(174, 89);
			this->panel1Tres->TabIndex = 21;
			// 
			// panel2Tres
			// 
			this->panel2Tres->BackColor = System::Drawing::Color::Teal;
			this->panel2Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Tres->Location = System::Drawing::Point(1453, 415);
			this->panel2Tres->Name = L"panel2Tres";
			this->panel2Tres->Size = System::Drawing::Size(174, 89);
			this->panel2Tres->TabIndex = 13;
			// 
			// panel4Tres
			// 
			this->panel4Tres->BackColor = System::Drawing::Color::Olive;
			this->panel4Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Tres->Location = System::Drawing::Point(1453, 881);
			this->panel4Tres->Name = L"panel4Tres";
			this->panel4Tres->Size = System::Drawing::Size(174, 89);
			this->panel4Tres->TabIndex = 14;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(187, 599);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(263, 184);
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(163, 830);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(317, 184);
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			// 
			// panel3Tres
			// 
			this->panel3Tres->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Tres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Tres->Location = System::Drawing::Point(1453, 644);
			this->panel3Tres->Name = L"panel3Tres";
			this->panel3Tres->Size = System::Drawing::Size(174, 89);
			this->panel3Tres->TabIndex = 15;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(219, 358);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(200, 203);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(220, 95);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(199, 224);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// panel1Dos
			// 
			this->panel1Dos->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Dos->Location = System::Drawing::Point(1275, 189);
			this->panel1Dos->Name = L"panel1Dos";
			this->panel1Dos->Size = System::Drawing::Size(174, 89);
			this->panel1Dos->TabIndex = 8;
			// 
			// panel1Uno
			// 
			this->panel1Uno->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Uno->Location = System::Drawing::Point(1096, 189);
			this->panel1Uno->Name = L"panel1Uno";
			this->panel1Uno->Size = System::Drawing::Size(174, 89);
			this->panel1Uno->TabIndex = 7;
			// 
			// panel2Dos
			// 
			this->panel2Dos->BackColor = System::Drawing::Color::Teal;
			this->panel2Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Dos->Location = System::Drawing::Point(1275, 415);
			this->panel2Dos->Name = L"panel2Dos";
			this->panel2Dos->Size = System::Drawing::Size(174, 89);
			this->panel2Dos->TabIndex = 11;
			// 
			// panel2Uno
			// 
			this->panel2Uno->BackColor = System::Drawing::Color::Teal;
			this->panel2Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Uno->Location = System::Drawing::Point(1096, 415);
			this->panel2Uno->Name = L"panel2Uno";
			this->panel2Uno->Size = System::Drawing::Size(174, 89);
			this->panel2Uno->TabIndex = 10;
			// 
			// panel4Dos
			// 
			this->panel4Dos->BackColor = System::Drawing::Color::Olive;
			this->panel4Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Dos->Location = System::Drawing::Point(1276, 881);
			this->panel4Dos->Name = L"panel4Dos";
			this->panel4Dos->Size = System::Drawing::Size(174, 89);
			this->panel4Dos->TabIndex = 11;
			// 
			// panel4Uno
			// 
			this->panel4Uno->BackColor = System::Drawing::Color::Olive;
			this->panel4Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Uno->Location = System::Drawing::Point(1096, 881);
			this->panel4Uno->Name = L"panel4Uno";
			this->panel4Uno->Size = System::Drawing::Size(174, 89);
			this->panel4Uno->TabIndex = 10;
			// 
			// panel3Dos
			// 
			this->panel3Dos->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Dos->Location = System::Drawing::Point(1275, 644);
			this->panel3Dos->Name = L"panel3Dos";
			this->panel3Dos->Size = System::Drawing::Size(174, 89);
			this->panel3Dos->TabIndex = 11;
			// 
			// panel3Uno
			// 
			this->panel3Uno->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Uno->Location = System::Drawing::Point(1096, 644);
			this->panel3Uno->Name = L"panel3Uno";
			this->panel3Uno->Size = System::Drawing::Size(174, 89);
			this->panel3Uno->TabIndex = 10;
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(5, 86);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(2);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(427, 250);
			this->btnAyuda->TabIndex = 11;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1DosDI::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1DosDI::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1DosDI::btnAyuda_MouseHover);
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
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1DosDI::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1DosDI::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1DosDI::btnListo_MouseHover);
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
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1DosDI::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1DosDI::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1DosDI::btnVolver_MouseHover);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->instruccion1);
			this->panel4->Controls->Add(this->instruccion2);
			this->panel4->Location = System::Drawing::Point(430, 73);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1846, 91);
			this->panel4->TabIndex = 7;
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::Color::White;
			this->instruccion2->Location = System::Drawing::Point(88, 9);
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
			this->instruccion1->Location = System::Drawing::Point(103, 11);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(1400, 68);
			this->instruccion1->TabIndex = 5;
			this->instruccion1->Text = L"Ordenemos las sílabas para descubrir los objetos del mar";
			// 
			// Act1DosDI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2450, 1334);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panelPrincipal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Act1DosDI";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1DosDI";
			this->Activated += gcnew System::EventHandler(this, &Act1DosDI::Act1DosDI_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1DosDI::Act1DosDI_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1DosDI::Act1DosDI_Load);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->panelPrincipal->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
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
	private: System::Void Act1DosDI_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosDI_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosDI_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos, bool listoTres);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void moverBoton(System::Windows::Forms::Button^ boton);
	private: System::Void btn1MAR_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1LA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2DU_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2SA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2ME_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3NA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3RE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3SI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4JAS_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4ES_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PON_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1MAR_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1LA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2DU_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2SA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2ME_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3NA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3RE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3SI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4JAS_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4ES_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PON_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1MAR_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1LA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2DU_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2SA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2ME_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3NA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3RE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3SI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4JAS_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4ES_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PON_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	};
}
