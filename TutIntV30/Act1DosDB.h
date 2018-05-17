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
	/// Resumen de Act1DosDB
	/// </summary>
	public ref class Act1DosDB : public System::Windows::Forms::Form
	{
	public:
		Act1DosDB(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act1DosDB(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act1DosDB()
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
	private: int xbtn1GA, ybtn1GA, xbtn1AL, ybtn1AL, xbtn2CA, ybtn2CA, xbtn2OR, ybtn2OR, xbtn3CA, ybtn3CA, xbtn3FO, ybtn3FO, xbtn4FRE, ybtn4FRE, xbtn4CO, ybtn4CO;		// Guardar la posicion original del boton
	private: bool listoBtn1GA, listoBtn1AL, listoBtn2CA, listoBtn2OR, listoBtn3CA, listoBtn3FO, listoBtn4FRE, listoBtn4CO;
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
	private: System::Windows::Forms::Button^  btn1GA;
	private: System::Windows::Forms::Button^  btn1AL;
	private: System::Windows::Forms::Button^  btn2CA;
	private: System::Windows::Forms::Button^  btn2OR;
	private: System::Windows::Forms::Button^  btn4FRE;
	private: System::Windows::Forms::Button^  btn3CA;
	private: System::Windows::Forms::Button^  btn4CO;
	private: System::Windows::Forms::Button^  btn3FO;
	private: System::Windows::Forms::Panel^  panel1Dos;
	private: System::Windows::Forms::Panel^  panel1Uno;
	private: System::Windows::Forms::Panel^  panel2Dos;
	private: System::Windows::Forms::Panel^  panel2Uno;
	private: System::Windows::Forms::Panel^  panel4Dos;
	private: System::Windows::Forms::Panel^  panel4Uno;
	private: System::Windows::Forms::Panel^  panel3Dos;
	private: System::Windows::Forms::Panel^  panel3Uno;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1DosDB::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn1GA = (gcnew System::Windows::Forms::Button());
			this->btn1AL = (gcnew System::Windows::Forms::Button());
			this->btn2CA = (gcnew System::Windows::Forms::Button());
			this->btn2OR = (gcnew System::Windows::Forms::Button());
			this->btn4FRE = (gcnew System::Windows::Forms::Button());
			this->btn3CA = (gcnew System::Windows::Forms::Button());
			this->btn4CO = (gcnew System::Windows::Forms::Button());
			this->btn3FO = (gcnew System::Windows::Forms::Button());
			this->panel1Dos = (gcnew System::Windows::Forms::Panel());
			this->panel1Uno = (gcnew System::Windows::Forms::Panel());
			this->panel2Dos = (gcnew System::Windows::Forms::Panel());
			this->panel2Uno = (gcnew System::Windows::Forms::Panel());
			this->panel4Dos = (gcnew System::Windows::Forms::Panel());
			this->panel4Uno = (gcnew System::Windows::Forms::Panel());
			this->panel3Dos = (gcnew System::Windows::Forms::Panel());
			this->panel3Uno = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
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
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1DosDB::timer1_Tick);
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
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1DosDB::picMinimizar_Click);
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
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1DosDB::picCerrar_Click);
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
			this->panel2->Controls->Add(this->btn1GA);
			this->panel2->Controls->Add(this->btn1AL);
			this->panel2->Controls->Add(this->btn2CA);
			this->panel2->Controls->Add(this->btn2OR);
			this->panel2->Controls->Add(this->btn4FRE);
			this->panel2->Controls->Add(this->btn3CA);
			this->panel2->Controls->Add(this->btn4CO);
			this->panel2->Controls->Add(this->btn3FO);
			this->panel2->Controls->Add(this->panel1Dos);
			this->panel2->Controls->Add(this->panel1Uno);
			this->panel2->Controls->Add(this->panel2Dos);
			this->panel2->Controls->Add(this->panel2Uno);
			this->panel2->Controls->Add(this->panel4Dos);
			this->panel2->Controls->Add(this->panel4Uno);
			this->panel2->Controls->Add(this->panel3Dos);
			this->panel2->Controls->Add(this->panel3Uno);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Location = System::Drawing::Point(592, 187);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1791, 1116);
			this->panel2->TabIndex = 3;
			// 
			// btn1GA
			// 
			this->btn1GA->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1GA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1GA->ForeColor = System::Drawing::Color::Transparent;
			this->btn1GA->Location = System::Drawing::Point(655, 181);
			this->btn1GA->Name = L"btn1GA";
			this->btn1GA->Size = System::Drawing::Size(175, 89);
			this->btn1GA->TabIndex = 3;
			this->btn1GA->Text = L"GA";
			this->btn1GA->UseVisualStyleBackColor = false;
			this->btn1GA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn1GA_MouseDown);
			this->btn1GA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn1GA_MouseMove);
			this->btn1GA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn1GA_MouseUp);
			// 
			// btn1AL
			// 
			this->btn1AL->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1AL->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1AL->ForeColor = System::Drawing::Color::Transparent;
			this->btn1AL->Location = System::Drawing::Point(878, 181);
			this->btn1AL->Name = L"btn1AL";
			this->btn1AL->Size = System::Drawing::Size(175, 89);
			this->btn1AL->TabIndex = 3;
			this->btn1AL->Text = L"AL";
			this->btn1AL->UseVisualStyleBackColor = false;
			this->btn1AL->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn1AL_MouseDown);
			this->btn1AL->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn1AL_MouseMove);
			this->btn1AL->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn1AL_MouseUp);
			// 
			// btn2CA
			// 
			this->btn2CA->BackColor = System::Drawing::Color::Teal;
			this->btn2CA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2CA->ForeColor = System::Drawing::Color::Transparent;
			this->btn2CA->Location = System::Drawing::Point(655, 427);
			this->btn2CA->Name = L"btn2CA";
			this->btn2CA->Size = System::Drawing::Size(175, 89);
			this->btn2CA->TabIndex = 4;
			this->btn2CA->Text = L"CA";
			this->btn2CA->UseVisualStyleBackColor = false;
			this->btn2CA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn2CA_MouseDown);
			this->btn2CA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn2CA_MouseMove);
			this->btn2CA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn2CA_MouseUp);
			// 
			// btn2OR
			// 
			this->btn2OR->BackColor = System::Drawing::Color::Teal;
			this->btn2OR->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2OR->ForeColor = System::Drawing::Color::Transparent;
			this->btn2OR->Location = System::Drawing::Point(866, 427);
			this->btn2OR->Name = L"btn2OR";
			this->btn2OR->Size = System::Drawing::Size(175, 89);
			this->btn2OR->TabIndex = 4;
			this->btn2OR->Text = L"OR";
			this->btn2OR->UseVisualStyleBackColor = false;
			this->btn2OR->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn2OR_MouseDown);
			this->btn2OR->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn2OR_MouseMove);
			this->btn2OR->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn2OR_MouseUp);
			// 
			// btn4FRE
			// 
			this->btn4FRE->BackColor = System::Drawing::Color::Olive;
			this->btn4FRE->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4FRE->ForeColor = System::Drawing::Color::Transparent;
			this->btn4FRE->Location = System::Drawing::Point(655, 911);
			this->btn4FRE->Name = L"btn4FRE";
			this->btn4FRE->Size = System::Drawing::Size(175, 89);
			this->btn4FRE->TabIndex = 4;
			this->btn4FRE->Text = L"FRE";
			this->btn4FRE->UseVisualStyleBackColor = false;
			this->btn4FRE->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn4FRE_MouseDown);
			this->btn4FRE->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn4FRE_MouseMove);
			this->btn4FRE->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn4FRE_MouseUp);
			// 
			// btn3CA
			// 
			this->btn3CA->BackColor = System::Drawing::Color::Chocolate;
			this->btn3CA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3CA->ForeColor = System::Drawing::Color::Transparent;
			this->btn3CA->Location = System::Drawing::Point(655, 666);
			this->btn3CA->Name = L"btn3CA";
			this->btn3CA->Size = System::Drawing::Size(175, 89);
			this->btn3CA->TabIndex = 4;
			this->btn3CA->Text = L"CA";
			this->btn3CA->UseVisualStyleBackColor = false;
			this->btn3CA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn3CA_MouseDown);
			this->btn3CA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn3CA_MouseMove);
			this->btn3CA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn3CA_MouseUp);
			// 
			// btn4CO
			// 
			this->btn4CO->BackColor = System::Drawing::Color::Olive;
			this->btn4CO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4CO->ForeColor = System::Drawing::Color::Transparent;
			this->btn4CO->Location = System::Drawing::Point(866, 911);
			this->btn4CO->Name = L"btn4CO";
			this->btn4CO->Size = System::Drawing::Size(187, 89);
			this->btn4CO->TabIndex = 4;
			this->btn4CO->Text = L"CO";
			this->btn4CO->UseVisualStyleBackColor = false;
			this->btn4CO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn4CO_MouseDown);
			this->btn4CO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn4CO_MouseMove);
			this->btn4CO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn4CO_MouseUp);
			// 
			// btn3FO
			// 
			this->btn3FO->BackColor = System::Drawing::Color::Chocolate;
			this->btn3FO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3FO->ForeColor = System::Drawing::Color::Transparent;
			this->btn3FO->Location = System::Drawing::Point(866, 666);
			this->btn3FO->Name = L"btn3FO";
			this->btn3FO->Size = System::Drawing::Size(175, 89);
			this->btn3FO->TabIndex = 4;
			this->btn3FO->Text = L"FO";
			this->btn3FO->UseVisualStyleBackColor = false;
			this->btn3FO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn3FO_MouseDown);
			this->btn3FO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn3FO_MouseMove);
			this->btn3FO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1DosDB::btn3FO_MouseUp);
			// 
			// panel1Dos
			// 
			this->panel1Dos->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Dos->Location = System::Drawing::Point(1331, 181);
			this->panel1Dos->Name = L"panel1Dos";
			this->panel1Dos->Size = System::Drawing::Size(174, 89);
			this->panel1Dos->TabIndex = 8;
			// 
			// panel1Uno
			// 
			this->panel1Uno->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Uno->Location = System::Drawing::Point(1152, 181);
			this->panel1Uno->Name = L"panel1Uno";
			this->panel1Uno->Size = System::Drawing::Size(174, 89);
			this->panel1Uno->TabIndex = 7;
			// 
			// panel2Dos
			// 
			this->panel2Dos->BackColor = System::Drawing::Color::Teal;
			this->panel2Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Dos->Location = System::Drawing::Point(1331, 428);
			this->panel2Dos->Name = L"panel2Dos";
			this->panel2Dos->Size = System::Drawing::Size(174, 89);
			this->panel2Dos->TabIndex = 11;
			// 
			// panel2Uno
			// 
			this->panel2Uno->BackColor = System::Drawing::Color::Teal;
			this->panel2Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Uno->Location = System::Drawing::Point(1152, 428);
			this->panel2Uno->Name = L"panel2Uno";
			this->panel2Uno->Size = System::Drawing::Size(174, 89);
			this->panel2Uno->TabIndex = 10;
			// 
			// panel4Dos
			// 
			this->panel4Dos->BackColor = System::Drawing::Color::Olive;
			this->panel4Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Dos->Location = System::Drawing::Point(1331, 913);
			this->panel4Dos->Name = L"panel4Dos";
			this->panel4Dos->Size = System::Drawing::Size(174, 89);
			this->panel4Dos->TabIndex = 11;
			// 
			// panel4Uno
			// 
			this->panel4Uno->BackColor = System::Drawing::Color::Olive;
			this->panel4Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Uno->Location = System::Drawing::Point(1152, 913);
			this->panel4Uno->Name = L"panel4Uno";
			this->panel4Uno->Size = System::Drawing::Size(174, 89);
			this->panel4Uno->TabIndex = 10;
			// 
			// panel3Dos
			// 
			this->panel3Dos->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Dos->Location = System::Drawing::Point(1331, 666);
			this->panel3Dos->Name = L"panel3Dos";
			this->panel3Dos->Size = System::Drawing::Size(174, 89);
			this->panel3Dos->TabIndex = 11;
			// 
			// panel3Uno
			// 
			this->panel3Uno->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Uno->Location = System::Drawing::Point(1152, 666);
			this->panel3Uno->Name = L"panel3Uno";
			this->panel3Uno->Size = System::Drawing::Size(174, 89);
			this->panel3Uno->TabIndex = 10;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(275, 860);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(268, 184);
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(246, 619);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(315, 184);
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(274, 377);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(265, 184);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(312, 117);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(195, 208);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
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
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1DosDB::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1DosDB::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1DosDB::btnAyuda_MouseHover);
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
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1DosDB::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1DosDB::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1DosDB::btnListo_MouseHover);
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
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1DosDB::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1DosDB::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1DosDB::btnVolver_MouseHover);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->instruccion1);
			this->panel4->Controls->Add(this->instruccion2);
			this->panel4->Location = System::Drawing::Point(436, 73);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1902, 91);
			this->panel4->TabIndex = 7;
			// 
			// instruccion1
			// 
			this->instruccion1->AutoSize = true;
			this->instruccion1->BackColor = System::Drawing::Color::Transparent;
			this->instruccion1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion1->ForeColor = System::Drawing::Color::White;
			this->instruccion1->Location = System::Drawing::Point(101, 11);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(1400, 68);
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
			this->instruccion2->Location = System::Drawing::Point(92, 9);
			this->instruccion2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(1646, 68);
			this->instruccion2->TabIndex = 4;
			this->instruccion2->Text = L"Desliza cada sílaba hacia los recuadros vacios para crear la palabra";
			this->instruccion2->Visible = false;
			// 
			// Act1DosDB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2450, 1334);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panelPrincipal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Act1DosDB";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1DosDB";
			this->Activated += gcnew System::EventHandler(this, &Act1DosDB::Act1DosDB_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1DosDB::Act1DosDB_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1DosDB::Act1DosDB_Load);
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
	private: System::Void Act1DosDB_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosDB_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosDB_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void moverBoton(System::Windows::Forms::Button^ boton);
	private: System::Void btn1GA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1AL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2OR_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3FO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4FRE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4CO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1GA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1AL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2OR_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3FO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4FRE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4CO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1GA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1AL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2OR_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3FO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4FRE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4CO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	};
}
