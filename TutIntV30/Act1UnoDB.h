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
	/// Resumen de Act1UnoDB
	/// </summary>
	public ref class Act1UnoDB : public System::Windows::Forms::Form
	{
	public:
		Act1UnoDB(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act1UnoDB(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act1UnoDB()
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
	private: int xbtn1FIN, ybtn1FIN, xbtn1DEL, ybtn1DEL, xbtn2RAL, ybtn2RAL, xbtn2CO, ybtn2CO, xbtn3CA, ybtn3CA, xbtn3RO, ybtn3RO, xbtn4PUL, ybtn4PUL, xbtn4PO, ybtn4PO;		// Guardar la posicion original del boton
	private: bool listoBtn1FIN, listoBtn1DEL, listoBtn2RAL, listoBtn2CO, listoBtn3CA, listoBtn3RO, listoBtn4PUL, listoBtn4PO;
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
	private: System::Windows::Forms::Button^  btn1FIN;
	private: System::Windows::Forms::Button^  btn1DEL;
	private: System::Windows::Forms::Button^  btn2RAL;
	private: System::Windows::Forms::Button^  btn2CO;
	private: System::Windows::Forms::Button^  btn4PUL;
	private: System::Windows::Forms::Button^  btn3CA;
	private: System::Windows::Forms::Button^  btn4PO;
	private: System::Windows::Forms::Button^  btn3RO;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1UnoDB::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn1FIN = (gcnew System::Windows::Forms::Button());
			this->btn1DEL = (gcnew System::Windows::Forms::Button());
			this->btn2RAL = (gcnew System::Windows::Forms::Button());
			this->btn2CO = (gcnew System::Windows::Forms::Button());
			this->btn4PUL = (gcnew System::Windows::Forms::Button());
			this->btn3CA = (gcnew System::Windows::Forms::Button());
			this->btn4PO = (gcnew System::Windows::Forms::Button());
			this->btn3RO = (gcnew System::Windows::Forms::Button());
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
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1UnoDB::timer1_Tick);
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
			this->panel6->Size = System::Drawing::Size(1137, 31);
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
			this->picMinimizar->Location = System::Drawing::Point(1072, 2);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(27, 26);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1UnoDB::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(1104, 2);
			this->picCerrar->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(27, 26);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1UnoDB::picCerrar_Click);
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
			this->panelPrincipal->Size = System::Drawing::Size(1137, 633);
			this->panelPrincipal->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->btn1FIN);
			this->panel2->Controls->Add(this->btn1DEL);
			this->panel2->Controls->Add(this->btn2RAL);
			this->panel2->Controls->Add(this->btn2CO);
			this->panel2->Controls->Add(this->btn4PUL);
			this->panel2->Controls->Add(this->btn3CA);
			this->panel2->Controls->Add(this->btn4PO);
			this->panel2->Controls->Add(this->btn3RO);
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
			this->panel2->Location = System::Drawing::Point(280, 83);
			this->panel2->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(738, 502);
			this->panel2->TabIndex = 3;
			// 
			// btn1FIN
			// 
			this->btn1FIN->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1FIN->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1FIN->ForeColor = System::Drawing::Color::Transparent;
			this->btn1FIN->Location = System::Drawing::Point(281, 87);
			this->btn1FIN->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn1FIN->Name = L"btn1FIN";
			this->btn1FIN->Size = System::Drawing::Size(75, 40);
			this->btn1FIN->TabIndex = 3;
			this->btn1FIN->Text = L"FÍN";
			this->btn1FIN->UseVisualStyleBackColor = false;
			this->btn1FIN->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn1FIN_MouseDown);
			this->btn1FIN->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn1FIN_MouseMove);
			this->btn1FIN->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn1FIN_MouseUp);
			// 
			// btn1DEL
			// 
			this->btn1DEL->BackColor = System::Drawing::Color::Goldenrod;
			this->btn1DEL->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1DEL->ForeColor = System::Drawing::Color::Transparent;
			this->btn1DEL->Location = System::Drawing::Point(371, 87);
			this->btn1DEL->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn1DEL->Name = L"btn1DEL";
			this->btn1DEL->Size = System::Drawing::Size(75, 40);
			this->btn1DEL->TabIndex = 3;
			this->btn1DEL->Text = L"DEL";
			this->btn1DEL->UseVisualStyleBackColor = false;
			this->btn1DEL->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn1DEL_MouseDown);
			this->btn1DEL->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn1DEL_MouseMove);
			this->btn1DEL->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn1DEL_MouseUp);
			// 
			// btn2RAL
			// 
			this->btn2RAL->BackColor = System::Drawing::Color::Teal;
			this->btn2RAL->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2RAL->ForeColor = System::Drawing::Color::Transparent;
			this->btn2RAL->Location = System::Drawing::Point(281, 195);
			this->btn2RAL->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn2RAL->Name = L"btn2RAL";
			this->btn2RAL->Size = System::Drawing::Size(75, 40);
			this->btn2RAL->TabIndex = 4;
			this->btn2RAL->Text = L"RAL";
			this->btn2RAL->UseVisualStyleBackColor = false;
			this->btn2RAL->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn2RAL_MouseDown);
			this->btn2RAL->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn2RAL_MouseMove);
			this->btn2RAL->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn2RAL_MouseUp);
			// 
			// btn2CO
			// 
			this->btn2CO->BackColor = System::Drawing::Color::Teal;
			this->btn2CO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2CO->ForeColor = System::Drawing::Color::Transparent;
			this->btn2CO->Location = System::Drawing::Point(371, 195);
			this->btn2CO->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn2CO->Name = L"btn2CO";
			this->btn2CO->Size = System::Drawing::Size(75, 40);
			this->btn2CO->TabIndex = 4;
			this->btn2CO->Text = L"CO";
			this->btn2CO->UseVisualStyleBackColor = false;
			this->btn2CO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn2CO_MouseDown);
			this->btn2CO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn2CO_MouseMove);
			this->btn2CO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn2CO_MouseUp);
			// 
			// btn4PUL
			// 
			this->btn4PUL->BackColor = System::Drawing::Color::Olive;
			this->btn4PUL->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4PUL->ForeColor = System::Drawing::Color::Transparent;
			this->btn4PUL->Location = System::Drawing::Point(281, 420);
			this->btn4PUL->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn4PUL->Name = L"btn4PUL";
			this->btn4PUL->Size = System::Drawing::Size(75, 40);
			this->btn4PUL->TabIndex = 4;
			this->btn4PUL->Text = L"PUL";
			this->btn4PUL->UseVisualStyleBackColor = false;
			this->btn4PUL->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn4PUL_MouseDown);
			this->btn4PUL->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn4PUL_MouseMove);
			this->btn4PUL->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn4PUL_MouseUp);
			// 
			// btn3CA
			// 
			this->btn3CA->BackColor = System::Drawing::Color::Chocolate;
			this->btn3CA->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3CA->ForeColor = System::Drawing::Color::Transparent;
			this->btn3CA->Location = System::Drawing::Point(281, 303);
			this->btn3CA->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn3CA->Name = L"btn3CA";
			this->btn3CA->Size = System::Drawing::Size(75, 40);
			this->btn3CA->TabIndex = 4;
			this->btn3CA->Text = L"CA";
			this->btn3CA->UseVisualStyleBackColor = false;
			this->btn3CA->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn3CA_MouseDown);
			this->btn3CA->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn3CA_MouseMove);
			this->btn3CA->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn3CA_MouseUp);
			// 
			// btn4PO
			// 
			this->btn4PO->BackColor = System::Drawing::Color::Olive;
			this->btn4PO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4PO->ForeColor = System::Drawing::Color::Transparent;
			this->btn4PO->Location = System::Drawing::Point(371, 420);
			this->btn4PO->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn4PO->Name = L"btn4PO";
			this->btn4PO->Size = System::Drawing::Size(80, 40);
			this->btn4PO->TabIndex = 4;
			this->btn4PO->Text = L"PO";
			this->btn4PO->UseVisualStyleBackColor = false;
			this->btn4PO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn4PO_MouseDown);
			this->btn4PO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn4PO_MouseMove);
			this->btn4PO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn4PO_MouseUp);
			// 
			// btn3RO
			// 
			this->btn3RO->BackColor = System::Drawing::Color::Chocolate;
			this->btn3RO->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3RO->ForeColor = System::Drawing::Color::Transparent;
			this->btn3RO->Location = System::Drawing::Point(371, 303);
			this->btn3RO->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btn3RO->Name = L"btn3RO";
			this->btn3RO->Size = System::Drawing::Size(75, 40);
			this->btn3RO->TabIndex = 4;
			this->btn3RO->Text = L"RO";
			this->btn3RO->UseVisualStyleBackColor = false;
			this->btn3RO->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn3RO_MouseDown);
			this->btn3RO->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn3RO_MouseMove);
			this->btn3RO->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Act1UnoDB::btn3RO_MouseUp);
			// 
			// panel1Dos
			// 
			this->panel1Dos->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Dos->Location = System::Drawing::Point(570, 88);
			this->panel1Dos->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel1Dos->Name = L"panel1Dos";
			this->panel1Dos->Size = System::Drawing::Size(77, 42);
			this->panel1Dos->TabIndex = 8;
			// 
			// panel1Uno
			// 
			this->panel1Uno->BackColor = System::Drawing::Color::Goldenrod;
			this->panel1Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1Uno->Location = System::Drawing::Point(494, 88);
			this->panel1Uno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel1Uno->Name = L"panel1Uno";
			this->panel1Uno->Size = System::Drawing::Size(77, 42);
			this->panel1Uno->TabIndex = 7;
			// 
			// panel2Dos
			// 
			this->panel2Dos->BackColor = System::Drawing::Color::Teal;
			this->panel2Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Dos->Location = System::Drawing::Point(570, 196);
			this->panel2Dos->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel2Dos->Name = L"panel2Dos";
			this->panel2Dos->Size = System::Drawing::Size(77, 42);
			this->panel2Dos->TabIndex = 11;
			// 
			// panel2Uno
			// 
			this->panel2Uno->BackColor = System::Drawing::Color::Teal;
			this->panel2Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2Uno->Location = System::Drawing::Point(494, 196);
			this->panel2Uno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel2Uno->Name = L"panel2Uno";
			this->panel2Uno->Size = System::Drawing::Size(77, 42);
			this->panel2Uno->TabIndex = 10;
			// 
			// panel4Dos
			// 
			this->panel4Dos->BackColor = System::Drawing::Color::Olive;
			this->panel4Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Dos->Location = System::Drawing::Point(570, 421);
			this->panel4Dos->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel4Dos->Name = L"panel4Dos";
			this->panel4Dos->Size = System::Drawing::Size(77, 42);
			this->panel4Dos->TabIndex = 11;
			// 
			// panel4Uno
			// 
			this->panel4Uno->BackColor = System::Drawing::Color::Olive;
			this->panel4Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4Uno->Location = System::Drawing::Point(494, 421);
			this->panel4Uno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel4Uno->Name = L"panel4Uno";
			this->panel4Uno->Size = System::Drawing::Size(77, 42);
			this->panel4Uno->TabIndex = 10;
			// 
			// panel3Dos
			// 
			this->panel3Dos->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Dos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Dos->Location = System::Drawing::Point(570, 303);
			this->panel3Dos->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel3Dos->Name = L"panel3Dos";
			this->panel3Dos->Size = System::Drawing::Size(77, 42);
			this->panel3Dos->TabIndex = 11;
			// 
			// panel3Uno
			// 
			this->panel3Uno->BackColor = System::Drawing::Color::Chocolate;
			this->panel3Uno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3Uno->Location = System::Drawing::Point(494, 303);
			this->panel3Uno->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel3Uno->Name = L"panel3Uno";
			this->panel3Uno->Size = System::Drawing::Size(77, 42);
			this->panel3Uno->TabIndex = 10;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(105, 398);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(135, 82);
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(105, 282);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(135, 82);
			this->pictureBox4->TabIndex = 14;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(121, 173);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(105, 82);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(110, 63);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(128, 82);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(1, 39);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(183, 112);
			this->btnAyuda->TabIndex = 11;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1UnoDB::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDB::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1UnoDB::btnAyuda_MouseHover);
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
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1UnoDB::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDB::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1UnoDB::btnListo_MouseHover);
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
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1UnoDB::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1UnoDB::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1UnoDB::btnVolver_MouseHover);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->instruccion1);
			this->panel4->Controls->Add(this->instruccion2);
			this->panel4->Location = System::Drawing::Point(186, 33);
			this->panel4->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(779, 41);
			this->panel4->TabIndex = 7;
			// 
			// instruccion1
			// 
			this->instruccion1->AutoSize = true;
			this->instruccion1->BackColor = System::Drawing::Color::Transparent;
			this->instruccion1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion1->ForeColor = System::Drawing::Color::White;
			this->instruccion1->Location = System::Drawing::Point(40, 4);
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
			this->instruccion2->Location = System::Drawing::Point(35, 4);
			this->instruccion2->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(747, 31);
			this->instruccion2->TabIndex = 4;
			this->instruccion2->Text = L"Desliza cada sílaba hacia los recuadros vacios para crear la palabra";
			this->instruccion2->Visible = false;
			// 
			// Act1UnoDB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1137, 633);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panelPrincipal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->Name = L"Act1UnoDB";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1UnoDB";
			this->Activated += gcnew System::EventHandler(this, &Act1UnoDB::Act1UnoDB_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1UnoDB::Act1UnoDB_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1UnoDB::Act1UnoDB_Load);
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
	private: System::Void Act1UnoDB_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoDB_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoDB_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void moverBoton(System::Windows::Forms::Button^ boton);
	private: System::Void btn1FIN_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1DEL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2RAL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3RO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PUL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1FIN_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1DEL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2RAL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3RO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PUL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1FIN_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn1DEL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2RAL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn2CO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn3RO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PUL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn4PO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	};
}
