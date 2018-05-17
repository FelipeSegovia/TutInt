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
	/// Resumen de Act1UnoII
	/// </summary>
	public ref class Act1UnoII : public System::Windows::Forms::Form
	{
	public:
		Act1UnoII(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
		{
			form = f;
			manejadorBD = manejador;
			controlador = control;
			InitializeComponent();
			inicializarTam();
			this->Size = System::Drawing::Size(1050, 598);
			this->Show();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Act1UnoII()
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
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: int wVolver, hVolver, wListo, hListo, wAyuda, hAyuda;
	private: bool listoEstrella = false, listoTortuga = false, listoTiburon = false, listoMedusa = false;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  btnListo;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  instruccion2;
	private: System::Windows::Forms::PictureBox^  btnAyuda;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Button^  btn3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Button^  btn2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  btn2T;
	private: System::Windows::Forms::Button^  btn2M;
	private: System::Windows::Forms::Button^  btn2L;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  btn3P;
	private: System::Windows::Forms::Button^  btn3B;
	private: System::Windows::Forms::Button^  btn3D;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Button^  btn4O;
	private: System::Windows::Forms::Button^  btn4A;
	private: System::Windows::Forms::Button^  btn4E;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  btn1A;
	private: System::Windows::Forms::Button^  btn1E;
	private: System::Windows::Forms::Button^  btn1T;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  btn1;
	private: System::Windows::Forms::Label^  lbl;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Panel^  panel17;
	private: System::Windows::Forms::Panel^  panel15;
	private: System::Windows::Forms::Panel^  panel16;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel18;
	private: System::Windows::Forms::Panel^  panel19;
	private: System::Windows::Forms::Panel^  panel20;
	private: System::Windows::Forms::Panel^  panel21;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel22;
	private: System::Windows::Forms::Panel^  panel23;
	private: System::Windows::Forms::Panel^  panel24;
	private: System::Windows::Forms::Panel^  panel25;
	private: System::Windows::Forms::Label^  label9;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1UnoII::typeid));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->btnListo = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->instruccion2 = (gcnew System::Windows::Forms::Label());
			this->btnAyuda = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn2T = (gcnew System::Windows::Forms::Button());
			this->btn2M = (gcnew System::Windows::Forms::Button());
			this->btn2L = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn3P = (gcnew System::Windows::Forms::Button());
			this->btn3B = (gcnew System::Windows::Forms::Button());
			this->btn3D = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn4O = (gcnew System::Windows::Forms::Button());
			this->btn4A = (gcnew System::Windows::Forms::Button());
			this->btn4E = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn1A = (gcnew System::Windows::Forms::Button());
			this->btn1E = (gcnew System::Windows::Forms::Button());
			this->btn1T = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->lbl = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->instruccion1 = (gcnew System::Windows::Forms::Label());
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->panelPrincipal->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel22->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel24->SuspendLayout();
			this->panel25->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel18->SuspendLayout();
			this->panel19->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel21->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel15->SuspendLayout();
			this->panel16->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->flowLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->flowLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel13->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel6
			// 
			this->panel6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel6.BackgroundImage")));
			this->panel6->Controls->Add(this->pictureBox7);
			this->panel6->Controls->Add(this->label1);
			this->panel6->Controls->Add(this->picMinimizar);
			this->panel6->Controls->Add(this->picCerrar);
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Margin = System::Windows::Forms::Padding(2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(2448, 1334);
			this->panel6->TabIndex = 3;
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
			this->picMinimizar->Location = System::Drawing::Point(2294, 4);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(2);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(63, 58);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1UnoII::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(2371, 4);
			this->picCerrar->Margin = System::Windows::Forms::Padding(2);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(63, 58);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1UnoII::picCerrar_Click);
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->panel5);
			this->panelPrincipal->Controls->Add(this->panel4);
			this->panelPrincipal->Controls->Add(this->btnAyuda);
			this->panelPrincipal->Controls->Add(this->panel1);
			this->panelPrincipal->Location = System::Drawing::Point(0, 69);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(2);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(2445, 1265);
			this->panelPrincipal->TabIndex = 4;
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
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1UnoII::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1UnoII::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1UnoII::btnListo_MouseHover);
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
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1UnoII::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1UnoII::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1UnoII::btnVolver_MouseHover);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->instruccion1);
			this->panel4->Controls->Add(this->instruccion2);
			this->panel4->Location = System::Drawing::Point(457, 16);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1800, 91);
			this->panel4->TabIndex = 7;
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::Color::White;
			this->instruccion2->Location = System::Drawing::Point(98, 9);
			this->instruccion2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(1588, 68);
			this->instruccion2->TabIndex = 4;
			this->instruccion2->Text = L"¿Qué letra falta para completar la palabra\? Guíate por la imagen";
			this->instruccion2->Visible = false;
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(23, 27);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(2);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(427, 250);
			this->btnAyuda->TabIndex = 1;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1UnoII::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1UnoII::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1UnoII::btnAyuda_MouseHover);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(618, 129);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1708, 1086);
			this->panel1->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				51.6039F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.3961F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				534)));
			this->tableLayoutPanel1->Controls->Add(this->panel9, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel8, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel7, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel3, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel4, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(222, 98);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1339, 899);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->panel22);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(806, 674);
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(531, 223);
			this->panel9->TabIndex = 19;
			// 
			// panel22
			// 
			this->panel22->Controls->Add(this->panel23);
			this->panel22->Controls->Add(this->panel24);
			this->panel22->Controls->Add(this->panel25);
			this->panel22->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel22->Location = System::Drawing::Point(0, 0);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(531, 223);
			this->panel22->TabIndex = 15;
			// 
			// panel23
			// 
			this->panel23->Controls->Add(this->label4);
			this->panel23->Location = System::Drawing::Point(275, 1);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(253, 232);
			this->panel23->TabIndex = 18;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(-19, 62);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(226, 98);
			this->label4->TabIndex = 12;
			this->label4->Text = L"DUSA";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel24
			// 
			this->panel24->Controls->Add(this->btn4);
			this->panel24->Location = System::Drawing::Point(178, 0);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(102, 232);
			this->panel24->TabIndex = 17;
			// 
			// btn4
			// 
			this->btn4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4->BackColor = System::Drawing::Color::White;
			this->btn4->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4->ForeColor = System::Drawing::Color::Black;
			this->btn4->Location = System::Drawing::Point(5, 53);
			this->btn4->Margin = System::Windows::Forms::Padding(2);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(91, 103);
			this->btn4->TabIndex = 13;
			this->btn4->UseVisualStyleBackColor = false;
			// 
			// panel25
			// 
			this->panel25->Controls->Add(this->label9);
			this->panel25->Location = System::Drawing::Point(23, 0);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(162, 232);
			this->panel25->TabIndex = 16;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(89, 60);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(88, 98);
			this->label9->TabIndex = 13;
			this->label9->Text = L"M";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->panel18);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(806, 450);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(531, 220);
			this->panel8->TabIndex = 18;
			// 
			// panel18
			// 
			this->panel18->Controls->Add(this->panel19);
			this->panel18->Controls->Add(this->panel20);
			this->panel18->Controls->Add(this->panel21);
			this->panel18->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel18->Location = System::Drawing::Point(0, 0);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(531, 220);
			this->panel18->TabIndex = 14;
			// 
			// panel19
			// 
			this->panel19->Controls->Add(this->label3);
			this->panel19->Location = System::Drawing::Point(275, 1);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(253, 232);
			this->panel19->TabIndex = 18;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(-16, 62);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(226, 98);
			this->label3->TabIndex = 12;
			this->label3->Text = L"URÓN";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel20
			// 
			this->panel20->Controls->Add(this->btn3);
			this->panel20->Location = System::Drawing::Point(178, 0);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(102, 232);
			this->panel20->TabIndex = 17;
			// 
			// btn3
			// 
			this->btn3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3->BackColor = System::Drawing::Color::White;
			this->btn3->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3->ForeColor = System::Drawing::Color::Black;
			this->btn3->Location = System::Drawing::Point(6, 53);
			this->btn3->Margin = System::Windows::Forms::Padding(2);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(86, 103);
			this->btn3->TabIndex = 13;
			this->btn3->UseVisualStyleBackColor = false;
			// 
			// panel21
			// 
			this->panel21->Controls->Add(this->label8);
			this->panel21->Location = System::Drawing::Point(23, 0);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(162, 232);
			this->panel21->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(43, 63);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(134, 98);
			this->label8->TabIndex = 13;
			this->label8->Text = L"TI";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->panel12);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(806, 226);
			this->panel7->Margin = System::Windows::Forms::Padding(2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(531, 220);
			this->panel7->TabIndex = 17;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->panel17);
			this->panel12->Controls->Add(this->panel15);
			this->panel12->Controls->Add(this->panel16);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel12->Location = System::Drawing::Point(0, 0);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(531, 220);
			this->panel12->TabIndex = 13;
			// 
			// panel17
			// 
			this->panel17->Controls->Add(this->label2);
			this->panel17->Location = System::Drawing::Point(319, 1);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(162, 232);
			this->panel17->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(-14, 67);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 98);
			this->label2->TabIndex = 12;
			this->label2->Text = L"UGA";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel15
			// 
			this->panel15->Controls->Add(this->btn2);
			this->panel15->Location = System::Drawing::Point(222, 0);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(102, 232);
			this->panel15->TabIndex = 17;
			// 
			// btn2
			// 
			this->btn2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2->BackColor = System::Drawing::Color::White;
			this->btn2->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2->ForeColor = System::Drawing::Color::Black;
			this->btn2->Location = System::Drawing::Point(2, 59);
			this->btn2->Margin = System::Windows::Forms::Padding(2);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(96, 103);
			this->btn2->TabIndex = 13;
			this->btn2->UseVisualStyleBackColor = false;
			// 
			// panel16
			// 
			this->panel16->Controls->Add(this->label5);
			this->panel16->Location = System::Drawing::Point(56, 0);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(162, 232);
			this->panel16->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(2, 68);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(180, 98);
			this->label5->TabIndex = 13;
			this->label5->Text = L"TOR";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(65, 2);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(285, 220);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(50, 229);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(315, 214);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(42, 450);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(331, 219);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->tableLayoutPanel3);
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel2->Location = System::Drawing::Point(417, 226);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(385, 220);
			this->flowLayoutPanel2->TabIndex = 6;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel3->Controls->Add(this->btn2T, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2M, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2L, 2, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(2, 2);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 183)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(380, 183);
			this->tableLayoutPanel3->TabIndex = 3;
			// 
			// btn2T
			// 
			this->btn2T->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2T->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2T->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2T->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2T->ForeColor = System::Drawing::Color::White;
			this->btn2T->Location = System::Drawing::Point(8, 37);
			this->btn2T->Margin = System::Windows::Forms::Padding(2);
			this->btn2T->Name = L"btn2T";
			this->btn2T->Size = System::Drawing::Size(110, 109);
			this->btn2T->TabIndex = 0;
			this->btn2T->Text = L"T";
			this->btn2T->UseVisualStyleBackColor = false;
			this->btn2T->Click += gcnew System::EventHandler(this, &Act1UnoII::btn2T_Click);
			// 
			// btn2M
			// 
			this->btn2M->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2M->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2M->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2M->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2M->ForeColor = System::Drawing::Color::White;
			this->btn2M->Location = System::Drawing::Point(134, 37);
			this->btn2M->Margin = System::Windows::Forms::Padding(2);
			this->btn2M->Name = L"btn2M";
			this->btn2M->Size = System::Drawing::Size(110, 109);
			this->btn2M->TabIndex = 1;
			this->btn2M->Text = L"M";
			this->btn2M->UseVisualStyleBackColor = false;
			this->btn2M->Click += gcnew System::EventHandler(this, &Act1UnoII::btn2M_Click);
			// 
			// btn2L
			// 
			this->btn2L->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2L->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2L->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2L->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2L->ForeColor = System::Drawing::Color::White;
			this->btn2L->Location = System::Drawing::Point(261, 37);
			this->btn2L->Margin = System::Windows::Forms::Padding(2);
			this->btn2L->Name = L"btn2L";
			this->btn2L->Size = System::Drawing::Size(110, 109);
			this->btn2L->TabIndex = 2;
			this->btn2L->Text = L"L";
			this->btn2L->UseVisualStyleBackColor = false;
			this->btn2L->Click += gcnew System::EventHandler(this, &Act1UnoII::btn2L_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(92, 677);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(231, 216);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Controls->Add(this->tableLayoutPanel4);
			this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel3->Location = System::Drawing::Point(417, 450);
			this->flowLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(385, 220);
			this->flowLayoutPanel3->TabIndex = 7;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 3;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel4->Controls->Add(this->btn3P, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3B, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3D, 2, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(2, 2);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 187)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(380, 187);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// btn3P
			// 
			this->btn3P->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3P->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3P->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3P->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3P->ForeColor = System::Drawing::Color::White;
			this->btn3P->Location = System::Drawing::Point(8, 39);
			this->btn3P->Margin = System::Windows::Forms::Padding(2);
			this->btn3P->Name = L"btn3P";
			this->btn3P->Size = System::Drawing::Size(110, 109);
			this->btn3P->TabIndex = 0;
			this->btn3P->Text = L"P";
			this->btn3P->UseVisualStyleBackColor = false;
			this->btn3P->Click += gcnew System::EventHandler(this, &Act1UnoII::btn3P_Click);
			// 
			// btn3B
			// 
			this->btn3B->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3B->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3B->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3B->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3B->ForeColor = System::Drawing::Color::White;
			this->btn3B->Location = System::Drawing::Point(134, 39);
			this->btn3B->Margin = System::Windows::Forms::Padding(2);
			this->btn3B->Name = L"btn3B";
			this->btn3B->Size = System::Drawing::Size(110, 109);
			this->btn3B->TabIndex = 1;
			this->btn3B->Text = L"B";
			this->btn3B->UseVisualStyleBackColor = false;
			this->btn3B->Click += gcnew System::EventHandler(this, &Act1UnoII::btn3B_Click);
			// 
			// btn3D
			// 
			this->btn3D->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3D->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3D->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3D->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3D->ForeColor = System::Drawing::Color::White;
			this->btn3D->Location = System::Drawing::Point(261, 39);
			this->btn3D->Margin = System::Windows::Forms::Padding(2);
			this->btn3D->Name = L"btn3D";
			this->btn3D->Size = System::Drawing::Size(110, 109);
			this->btn3D->TabIndex = 2;
			this->btn3D->Text = L"D";
			this->btn3D->UseVisualStyleBackColor = false;
			this->btn3D->Click += gcnew System::EventHandler(this, &Act1UnoII::btn3D_Click);
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->Controls->Add(this->tableLayoutPanel5);
			this->flowLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel4->Location = System::Drawing::Point(417, 674);
			this->flowLayoutPanel4->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(385, 223);
			this->flowLayoutPanel4->TabIndex = 8;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel5->Controls->Add(this->btn4O, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4A, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4E, 0, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(2, 2);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(380, 183);
			this->tableLayoutPanel5->TabIndex = 4;
			// 
			// btn4O
			// 
			this->btn4O->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4O->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4O->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4O->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4O->ForeColor = System::Drawing::Color::White;
			this->btn4O->Location = System::Drawing::Point(261, 37);
			this->btn4O->Margin = System::Windows::Forms::Padding(2);
			this->btn4O->Name = L"btn4O";
			this->btn4O->Size = System::Drawing::Size(110, 109);
			this->btn4O->TabIndex = 3;
			this->btn4O->Text = L"O";
			this->btn4O->UseVisualStyleBackColor = false;
			this->btn4O->Click += gcnew System::EventHandler(this, &Act1UnoII::btn4O_Click);
			// 
			// btn4A
			// 
			this->btn4A->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4A->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4A->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4A->ForeColor = System::Drawing::Color::White;
			this->btn4A->Location = System::Drawing::Point(134, 37);
			this->btn4A->Margin = System::Windows::Forms::Padding(2);
			this->btn4A->Name = L"btn4A";
			this->btn4A->Size = System::Drawing::Size(110, 109);
			this->btn4A->TabIndex = 4;
			this->btn4A->Text = L"A";
			this->btn4A->UseVisualStyleBackColor = false;
			this->btn4A->Click += gcnew System::EventHandler(this, &Act1UnoII::btn4A_Click);
			// 
			// btn4E
			// 
			this->btn4E->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4E->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4E->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4E->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4E->ForeColor = System::Drawing::Color::White;
			this->btn4E->Location = System::Drawing::Point(8, 37);
			this->btn4E->Margin = System::Windows::Forms::Padding(2);
			this->btn4E->Name = L"btn4E";
			this->btn4E->Size = System::Drawing::Size(110, 109);
			this->btn4E->TabIndex = 5;
			this->btn4E->Text = L"E";
			this->btn4E->UseVisualStyleBackColor = false;
			this->btn4E->Click += gcnew System::EventHandler(this, &Act1UnoII::btn4E_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->tableLayoutPanel2);
			this->panel2->Location = System::Drawing::Point(417, 2);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(383, 220);
			this->panel2->TabIndex = 15;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel2->Controls->Add(this->btn1A, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1E, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1T, 2, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(-2, 18);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(399, 194);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// btn1A
			// 
			this->btn1A->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1A->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1A->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1A->ForeColor = System::Drawing::Color::White;
			this->btn1A->Location = System::Drawing::Point(11, 42);
			this->btn1A->Margin = System::Windows::Forms::Padding(2);
			this->btn1A->Name = L"btn1A";
			this->btn1A->Size = System::Drawing::Size(110, 109);
			this->btn1A->TabIndex = 0;
			this->btn1A->Text = L"A";
			this->btn1A->UseVisualStyleBackColor = false;
			this->btn1A->Click += gcnew System::EventHandler(this, &Act1UnoII::btn1A_Click);
			// 
			// btn1E
			// 
			this->btn1E->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1E->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1E->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1E->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1E->ForeColor = System::Drawing::Color::White;
			this->btn1E->Location = System::Drawing::Point(144, 42);
			this->btn1E->Margin = System::Windows::Forms::Padding(2);
			this->btn1E->Name = L"btn1E";
			this->btn1E->Size = System::Drawing::Size(110, 109);
			this->btn1E->TabIndex = 1;
			this->btn1E->Text = L"E";
			this->btn1E->UseVisualStyleBackColor = false;
			this->btn1E->Click += gcnew System::EventHandler(this, &Act1UnoII::btn1E_Click);
			// 
			// btn1T
			// 
			this->btn1T->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->btn1T->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1T->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1T->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1T->ForeColor = System::Drawing::Color::White;
			this->btn1T->Location = System::Drawing::Point(268, 42);
			this->btn1T->Margin = System::Windows::Forms::Padding(2);
			this->btn1T->Name = L"btn1T";
			this->btn1T->Size = System::Drawing::Size(110, 109);
			this->btn1T->TabIndex = 2;
			this->btn1T->Text = L"T";
			this->btn1T->UseVisualStyleBackColor = false;
			this->btn1T->Click += gcnew System::EventHandler(this, &Act1UnoII::btn1T_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel10);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(806, 2);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(531, 220);
			this->panel3->TabIndex = 16;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->panel11);
			this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel10->Location = System::Drawing::Point(0, 0);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(531, 220);
			this->panel10->TabIndex = 17;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->panel14);
			this->panel11->Controls->Add(this->panel13);
			this->panel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel11->Location = System::Drawing::Point(0, 0);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(531, 220);
			this->panel11->TabIndex = 12;
			// 
			// panel14
			// 
			this->panel14->Controls->Add(this->btn1);
			this->panel14->Location = System::Drawing::Point(384, 0);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(113, 232);
			this->panel14->TabIndex = 17;
			// 
			// btn1
			// 
			this->btn1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1->BackColor = System::Drawing::Color::White;
			this->btn1->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1->ForeColor = System::Drawing::Color::Black;
			this->btn1->Location = System::Drawing::Point(5, 57);
			this->btn1->Margin = System::Windows::Forms::Padding(2);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(96, 109);
			this->btn1->TabIndex = 13;
			this->btn1->UseVisualStyleBackColor = false;
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->lbl);
			this->panel13->Location = System::Drawing::Point(35, 0);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(352, 232);
			this->panel13->TabIndex = 16;
			// 
			// lbl
			// 
			this->lbl->AutoSize = true;
			this->lbl->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbl->Location = System::Drawing::Point(-6, 71);
			this->lbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl->Name = L"lbl";
			this->lbl->Size = System::Drawing::Size(364, 98);
			this->lbl->TabIndex = 12;
			this->lbl->Text = L"ESTRELL";
			this->lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1UnoII::timer1_Tick);
			// 
			// instruccion1
			// 
			this->instruccion1->AutoSize = true;
			this->instruccion1->BackColor = System::Drawing::Color::Transparent;
			this->instruccion1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion1->ForeColor = System::Drawing::Color::White;
			this->instruccion1->Location = System::Drawing::Point(103, 9);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(1241, 68);
			this->instruccion1->TabIndex = 5;
			this->instruccion1->Text = L"Completa la palabra, presionando la letra que falta";
			// 
			// Act1UnoII
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2450, 1334);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel6);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(7);
			this->Name = L"Act1UnoII";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1UnoII";
			this->Activated += gcnew System::EventHandler(this, &Act1UnoII::Act1UnoII_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1UnoII::Act1UnoII_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1UnoII::Act1UnoII_Load);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->panelPrincipal->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->EndInit();
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel22->ResumeLayout(false);
			this->panel23->ResumeLayout(false);
			this->panel23->PerformLayout();
			this->panel24->ResumeLayout(false);
			this->panel25->ResumeLayout(false);
			this->panel25->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel18->ResumeLayout(false);
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			this->panel20->ResumeLayout(false);
			this->panel21->ResumeLayout(false);
			this->panel21->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel12->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			this->panel17->PerformLayout();
			this->panel15->ResumeLayout(false);
			this->panel16->ResumeLayout(false);
			this->panel16->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel14->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: void inicializarTam();
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
	private: System::Void Act1UnoII_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoII_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoII_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TutIntV30::Act1UnoII::inicializarColor1();
	private: System::Void TutIntV30::Act1UnoII::inicializarColor2();
	private: System::Void TutIntV30::Act1UnoII::inicializarColor3();
	private: System::Void TutIntV30::Act1UnoII::inicializarColor4();
	private: System::Void btn1A_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1E_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1T_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2T_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2M_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2L_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3P_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3B_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3D_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4E_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4A_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4O_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::Button^ btn);
	private: vector<TiempoMI*> obtenerTiempoItems();
	};
}
