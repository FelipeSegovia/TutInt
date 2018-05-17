#pragma once
#include "BaseDeDatos.h"
#include "AgenteControlador.h"
#include "TiempoGUI.h"
#include "TiempoMI.h"

namespace TutIntV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Act1DosIB
	/// </summary>
	public ref class Act1DosIB : public System::Windows::Forms::Form
	{
	public:
		Act1DosIB(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act1DosIB()
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
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  btnListo;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  instruccion2;
	private: System::Windows::Forms::Panel^  panel1;
	private: int wVolver, hVolver, wListo, hListo, wAyuda, hAyuda;
	private: bool listoPez = false, listoSol = false, listoPelota = false, listoSirena = false;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  lblPulpo;
	private: System::Windows::Forms::Label^  lblCangrejo;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  btn2M;
	private: System::Windows::Forms::Button^  btn2R;
	private: System::Windows::Forms::Button^  btn2D;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  btn3D;
	private: System::Windows::Forms::Button^  btn3P;
	private: System::Windows::Forms::Button^  btn3M;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Button^  btn4R;
	private: System::Windows::Forms::Button^  btn4P;
	private: System::Windows::Forms::Button^  btn4B;
	private: System::Windows::Forms::Label^  lblPez;
	private: System::Windows::Forms::Label^  lblTiburon;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  btn1R;
	private: System::Windows::Forms::Button^  btn1T;
	private: System::Windows::Forms::Button^  btn1S;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btn1;
	private: System::Windows::Forms::Button^  btn2;
	private: System::Windows::Forms::Button^  btn3;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::PictureBox^  btnAyuda;
	private: System::Windows::Forms::Timer^  timerAct;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Panel^  panel17;
	private: System::Windows::Forms::Panel^  panel15;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::Panel^  panel16;
	private: System::Windows::Forms::Panel^  panel18;
	private: System::Windows::Forms::Panel^  panel19;
	private: System::Windows::Forms::Panel^  panel20;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1DosIB::typeid));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->btnAyuda = (gcnew System::Windows::Forms::PictureBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->btnListo = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->instruccion1 = (gcnew System::Windows::Forms::Label());
			this->instruccion2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->lblPulpo = (gcnew System::Windows::Forms::Label());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->lblTiburon = (gcnew System::Windows::Forms::Label());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->lblCangrejo = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn2M = (gcnew System::Windows::Forms::Button());
			this->btn2R = (gcnew System::Windows::Forms::Button());
			this->btn2D = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn3D = (gcnew System::Windows::Forms::Button());
			this->btn3P = (gcnew System::Windows::Forms::Button());
			this->btn3M = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn4R = (gcnew System::Windows::Forms::Button());
			this->btn4P = (gcnew System::Windows::Forms::Button());
			this->btn4B = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn1R = (gcnew System::Windows::Forms::Button());
			this->btn1T = (gcnew System::Windows::Forms::Button());
			this->btn1S = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->lblPez = (gcnew System::Windows::Forms::Label());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->timerAct = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panelPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel4->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel18->SuspendLayout();
			this->panel19->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel16->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->flowLayoutPanel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->flowLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel7->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel15->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->btnAyuda);
			this->panelPrincipal->Controls->Add(this->panel5);
			this->panelPrincipal->Controls->Add(this->panel4);
			this->panelPrincipal->Controls->Add(this->panel1);
			this->panelPrincipal->Location = System::Drawing::Point(0, 69);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(2);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(2448, 1330);
			this->panelPrincipal->TabIndex = 1;
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(26, 25);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(2);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(427, 250);
			this->btnAyuda->TabIndex = 11;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1DosIB::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1DosIB::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1DosIB::btnAyuda_MouseHover);
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
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1DosIB::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1DosIB::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1DosIB::btnListo_MouseHover);
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
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1DosIB::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1DosIB::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1DosIB::btnVolver_MouseHover);
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
			this->panel4->Size = System::Drawing::Size(1421, 91);
			this->panel4->TabIndex = 7;
			// 
			// instruccion1
			// 
			this->instruccion1->AutoSize = true;
			this->instruccion1->BackColor = System::Drawing::Color::Transparent;
			this->instruccion1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion1->ForeColor = System::Drawing::Color::White;
			this->instruccion1->Location = System::Drawing::Point(86, 9);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(1241, 68);
			this->instruccion1->TabIndex = 5;
			this->instruccion1->Text = L"Completa la palabra, presionando la letra que falta";
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::Color::White;
			this->instruccion2->Location = System::Drawing::Point(78, 9);
			this->instruccion2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(1102, 68);
			this->instruccion2->TabIndex = 4;
			this->instruccion2->Text = L"Presiona la letra inicial de la imagen indicada";
			this->instruccion2->Visible = false;
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
			this->panel1->Size = System::Drawing::Size(1708, 1097);
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
				560)));
			this->tableLayoutPanel1->Controls->Add(this->panel18, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel13, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel8, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel3, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel4, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel7, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(222, 113);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 44.4898F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.5102F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 252)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 223)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1339, 910);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel18
			// 
			this->panel18->Controls->Add(this->panel19);
			this->panel18->Controls->Add(this->panel20);
			this->panel18->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel18->Location = System::Drawing::Point(781, 689);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(555, 218);
			this->panel18->TabIndex = 19;
			// 
			// panel19
			// 
			this->panel19->Controls->Add(this->lblPulpo);
			this->panel19->Location = System::Drawing::Point(209, 1);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(288, 242);
			this->panel19->TabIndex = 18;
			// 
			// lblPulpo
			// 
			this->lblPulpo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblPulpo->AutoSize = true;
			this->lblPulpo->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPulpo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblPulpo->Location = System::Drawing::Point(-19, 60);
			this->lblPulpo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPulpo->Name = L"lblPulpo";
			this->lblPulpo->Size = System::Drawing::Size(226, 98);
			this->lblPulpo->TabIndex = 13;
			this->lblPulpo->Text = L"ULPO";
			this->lblPulpo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel20
			// 
			this->panel20->Controls->Add(this->btn4);
			this->panel20->Location = System::Drawing::Point(108, 0);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(106, 246);
			this->panel20->TabIndex = 17;
			// 
			// btn4
			// 
			this->btn4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4->BackColor = System::Drawing::Color::White;
			this->btn4->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4->ForeColor = System::Drawing::Color::Black;
			this->btn4->Location = System::Drawing::Point(2, 48);
			this->btn4->Margin = System::Windows::Forms::Padding(2);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(98, 109);
			this->btn4->TabIndex = 14;
			this->btn4->UseVisualStyleBackColor = false;
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->panel14);
			this->panel13->Controls->Add(this->panel16);
			this->panel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel13->Location = System::Drawing::Point(781, 437);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(555, 246);
			this->panel13->TabIndex = 18;
			// 
			// panel14
			// 
			this->panel14->Controls->Add(this->lblTiburon);
			this->panel14->Location = System::Drawing::Point(209, 1);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(288, 242);
			this->panel14->TabIndex = 18;
			// 
			// lblTiburon
			// 
			this->lblTiburon->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblTiburon->AutoSize = true;
			this->lblTiburon->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiburon->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblTiburon->Location = System::Drawing::Point(-17, 64);
			this->lblTiburon->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblTiburon->Name = L"lblTiburon";
			this->lblTiburon->Size = System::Drawing::Size(272, 98);
			this->lblTiburon->TabIndex = 12;
			this->lblTiburon->Text = L"EDUSA";
			this->lblTiburon->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel16
			// 
			this->panel16->Controls->Add(this->btn3);
			this->panel16->Location = System::Drawing::Point(108, 0);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(106, 246);
			this->panel16->TabIndex = 17;
			// 
			// btn3
			// 
			this->btn3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3->BackColor = System::Drawing::Color::White;
			this->btn3->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3->ForeColor = System::Drawing::Color::Black;
			this->btn3->Location = System::Drawing::Point(0, 50);
			this->btn3->Margin = System::Windows::Forms::Padding(2);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(98, 109);
			this->btn3->TabIndex = 13;
			this->btn3->UseVisualStyleBackColor = false;
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(781, 196);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(555, 235);
			this->panel8->TabIndex = 17;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->panel10);
			this->panel9->Controls->Add(this->panel11);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(0, 0);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(555, 235);
			this->panel9->TabIndex = 15;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->lblCangrejo);
			this->panel10->Location = System::Drawing::Point(209, 1);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(288, 259);
			this->panel10->TabIndex = 18;
			// 
			// lblCangrejo
			// 
			this->lblCangrejo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblCangrejo->AutoSize = true;
			this->lblCangrejo->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCangrejo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblCangrejo->Location = System::Drawing::Point(-17, 60);
			this->lblCangrejo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblCangrejo->Name = L"lblCangrejo";
			this->lblCangrejo->Size = System::Drawing::Size(272, 98);
			this->lblCangrejo->TabIndex = 11;
			this->lblCangrejo->Text = L"ELFÍN";
			this->lblCangrejo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->btn2);
			this->panel11->Location = System::Drawing::Point(108, 0);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(106, 257);
			this->panel11->TabIndex = 17;
			// 
			// btn2
			// 
			this->btn2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2->BackColor = System::Drawing::Color::White;
			this->btn2->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2->ForeColor = System::Drawing::Color::Black;
			this->btn2->Location = System::Drawing::Point(4, 50);
			this->btn2->Margin = System::Windows::Forms::Padding(2);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(98, 109);
			this->btn2->TabIndex = 13;
			this->btn2->UseVisualStyleBackColor = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(33, 207);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(334, 213);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(82, 442);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(236, 236);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->panel3);
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel2->Location = System::Drawing::Point(403, 195);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(373, 237);
			this->flowLayoutPanel2->TabIndex = 6;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->tableLayoutPanel3);
			this->panel3->Location = System::Drawing::Point(2, 2);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(380, 232);
			this->panel3->TabIndex = 16;
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
			this->tableLayoutPanel3->Controls->Add(this->btn2M, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2R, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2D, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 232)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(380, 232);
			this->tableLayoutPanel3->TabIndex = 3;
			// 
			// btn2M
			// 
			this->btn2M->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2M->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2M->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2M->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2M->ForeColor = System::Drawing::Color::White;
			this->btn2M->Location = System::Drawing::Point(8, 62);
			this->btn2M->Margin = System::Windows::Forms::Padding(2);
			this->btn2M->Name = L"btn2M";
			this->btn2M->Size = System::Drawing::Size(110, 107);
			this->btn2M->TabIndex = 0;
			this->btn2M->Text = L"M";
			this->btn2M->UseVisualStyleBackColor = false;
			this->btn2M->Click += gcnew System::EventHandler(this, &Act1DosIB::btn2M_Click);
			// 
			// btn2R
			// 
			this->btn2R->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2R->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2R->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2R->ForeColor = System::Drawing::Color::White;
			this->btn2R->Location = System::Drawing::Point(134, 62);
			this->btn2R->Margin = System::Windows::Forms::Padding(2);
			this->btn2R->Name = L"btn2R";
			this->btn2R->Size = System::Drawing::Size(110, 107);
			this->btn2R->TabIndex = 1;
			this->btn2R->Text = L"R";
			this->btn2R->UseVisualStyleBackColor = false;
			this->btn2R->Click += gcnew System::EventHandler(this, &Act1DosIB::btn2R_Click);
			// 
			// btn2D
			// 
			this->btn2D->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2D->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2D->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2D->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2D->ForeColor = System::Drawing::Color::White;
			this->btn2D->Location = System::Drawing::Point(261, 62);
			this->btn2D->Margin = System::Windows::Forms::Padding(2);
			this->btn2D->Name = L"btn2D";
			this->btn2D->Size = System::Drawing::Size(110, 107);
			this->btn2D->TabIndex = 2;
			this->btn2D->Text = L"D";
			this->btn2D->UseVisualStyleBackColor = false;
			this->btn2D->Click += gcnew System::EventHandler(this, &Act1DosIB::btn2D_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(24, 688);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(352, 220);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Controls->Add(this->tableLayoutPanel4);
			this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel3->Location = System::Drawing::Point(403, 436);
			this->flowLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(373, 248);
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
			this->tableLayoutPanel4->Controls->Add(this->btn3D, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3P, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3M, 2, 0);
			this->tableLayoutPanel4->Location = System::Drawing::Point(2, 2);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 240)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(380, 240);
			this->tableLayoutPanel4->TabIndex = 1;
			// 
			// btn3D
			// 
			this->btn3D->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3D->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3D->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3D->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3D->ForeColor = System::Drawing::Color::White;
			this->btn3D->Location = System::Drawing::Point(8, 66);
			this->btn3D->Margin = System::Windows::Forms::Padding(2);
			this->btn3D->Name = L"btn3D";
			this->btn3D->Size = System::Drawing::Size(110, 107);
			this->btn3D->TabIndex = 0;
			this->btn3D->Text = L"D";
			this->btn3D->UseVisualStyleBackColor = false;
			this->btn3D->Click += gcnew System::EventHandler(this, &Act1DosIB::btn3D_Click);
			// 
			// btn3P
			// 
			this->btn3P->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3P->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3P->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3P->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3P->ForeColor = System::Drawing::Color::White;
			this->btn3P->Location = System::Drawing::Point(134, 66);
			this->btn3P->Margin = System::Windows::Forms::Padding(2);
			this->btn3P->Name = L"btn3P";
			this->btn3P->Size = System::Drawing::Size(110, 107);
			this->btn3P->TabIndex = 1;
			this->btn3P->Text = L"P";
			this->btn3P->UseVisualStyleBackColor = false;
			this->btn3P->Click += gcnew System::EventHandler(this, &Act1DosIB::btn3P_Click);
			// 
			// btn3M
			// 
			this->btn3M->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3M->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3M->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3M->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3M->ForeColor = System::Drawing::Color::White;
			this->btn3M->Location = System::Drawing::Point(261, 66);
			this->btn3M->Margin = System::Windows::Forms::Padding(2);
			this->btn3M->Name = L"btn3M";
			this->btn3M->Size = System::Drawing::Size(110, 107);
			this->btn3M->TabIndex = 2;
			this->btn3M->Text = L"M";
			this->btn3M->UseVisualStyleBackColor = false;
			this->btn3M->Click += gcnew System::EventHandler(this, &Act1DosIB::btn3M_Click);
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->Controls->Add(this->tableLayoutPanel5);
			this->flowLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel4->Location = System::Drawing::Point(403, 688);
			this->flowLayoutPanel4->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(373, 220);
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
			this->tableLayoutPanel5->Controls->Add(this->btn4R, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4P, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4B, 0, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(2, 2);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(380, 215);
			this->tableLayoutPanel5->TabIndex = 4;
			// 
			// btn4R
			// 
			this->btn4R->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4R->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4R->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4R->ForeColor = System::Drawing::Color::White;
			this->btn4R->Location = System::Drawing::Point(261, 54);
			this->btn4R->Margin = System::Windows::Forms::Padding(2);
			this->btn4R->Name = L"btn4R";
			this->btn4R->Size = System::Drawing::Size(110, 107);
			this->btn4R->TabIndex = 3;
			this->btn4R->Text = L"R";
			this->btn4R->UseVisualStyleBackColor = false;
			this->btn4R->Click += gcnew System::EventHandler(this, &Act1DosIB::btn4R_Click);
			// 
			// btn4P
			// 
			this->btn4P->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4P->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4P->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4P->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4P->ForeColor = System::Drawing::Color::White;
			this->btn4P->Location = System::Drawing::Point(134, 54);
			this->btn4P->Margin = System::Windows::Forms::Padding(2);
			this->btn4P->Name = L"btn4P";
			this->btn4P->Size = System::Drawing::Size(110, 107);
			this->btn4P->TabIndex = 4;
			this->btn4P->Text = L"P";
			this->btn4P->UseVisualStyleBackColor = false;
			this->btn4P->Click += gcnew System::EventHandler(this, &Act1DosIB::btn4P_Click);
			// 
			// btn4B
			// 
			this->btn4B->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4B->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4B->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4B->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4B->ForeColor = System::Drawing::Color::White;
			this->btn4B->Location = System::Drawing::Point(8, 54);
			this->btn4B->Margin = System::Windows::Forms::Padding(2);
			this->btn4B->Name = L"btn4B";
			this->btn4B->Size = System::Drawing::Size(110, 107);
			this->btn4B->TabIndex = 5;
			this->btn4B->Text = L"B";
			this->btn4B->UseVisualStyleBackColor = false;
			this->btn4B->Click += gcnew System::EventHandler(this, &Act1DosIB::btn4B_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->tableLayoutPanel2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(403, 2);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(373, 189);
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
			this->tableLayoutPanel2->Controls->Add(this->btn1R, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1T, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1S, 2, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(373, 189);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// btn1R
			// 
			this->btn1R->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1R->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1R->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1R->ForeColor = System::Drawing::Color::White;
			this->btn1R->Location = System::Drawing::Point(7, 41);
			this->btn1R->Margin = System::Windows::Forms::Padding(2);
			this->btn1R->Name = L"btn1R";
			this->btn1R->Size = System::Drawing::Size(110, 107);
			this->btn1R->TabIndex = 0;
			this->btn1R->Text = L"R";
			this->btn1R->UseVisualStyleBackColor = false;
			this->btn1R->Click += gcnew System::EventHandler(this, &Act1DosIB::btn1R_Click);
			// 
			// btn1T
			// 
			this->btn1T->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1T->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1T->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1T->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1T->ForeColor = System::Drawing::Color::White;
			this->btn1T->Location = System::Drawing::Point(131, 41);
			this->btn1T->Margin = System::Windows::Forms::Padding(2);
			this->btn1T->Name = L"btn1T";
			this->btn1T->Size = System::Drawing::Size(110, 107);
			this->btn1T->TabIndex = 1;
			this->btn1T->Text = L"T";
			this->btn1T->UseVisualStyleBackColor = false;
			this->btn1T->Click += gcnew System::EventHandler(this, &Act1DosIB::btn1T_Click);
			// 
			// btn1S
			// 
			this->btn1S->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->btn1S->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1S->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1S->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1S->ForeColor = System::Drawing::Color::White;
			this->btn1S->Location = System::Drawing::Point(250, 41);
			this->btn1S->Margin = System::Windows::Forms::Padding(2);
			this->btn1S->Name = L"btn1S";
			this->btn1S->Size = System::Drawing::Size(110, 107);
			this->btn1S->TabIndex = 2;
			this->btn1S->Text = L"S";
			this->btn1S->UseVisualStyleBackColor = false;
			this->btn1S->Click += gcnew System::EventHandler(this, &Act1DosIB::btn1S_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(36, 2);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(328, 189);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->panel12);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(781, 3);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(555, 187);
			this->panel7->TabIndex = 16;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->panel17);
			this->panel12->Controls->Add(this->panel15);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel12->Location = System::Drawing::Point(0, 0);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(555, 187);
			this->panel12->TabIndex = 15;
			// 
			// panel17
			// 
			this->panel17->Controls->Add(this->lblPez);
			this->panel17->Location = System::Drawing::Point(209, 1);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(288, 206);
			this->panel17->TabIndex = 18;
			// 
			// lblPez
			// 
			this->lblPez->AutoSize = true;
			this->lblPez->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPez->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lblPez->Location = System::Drawing::Point(-17, 52);
			this->lblPez->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPez->Name = L"lblPez";
			this->lblPez->Size = System::Drawing::Size(180, 98);
			this->lblPez->TabIndex = 10;
			this->lblPez->Text = L"OCA";
			this->lblPez->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel15
			// 
			this->panel15->Controls->Add(this->btn1);
			this->panel15->Location = System::Drawing::Point(108, 0);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(106, 204);
			this->panel15->TabIndex = 17;
			// 
			// btn1
			// 
			this->btn1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1->BackColor = System::Drawing::Color::White;
			this->btn1->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1->ForeColor = System::Drawing::Color::Black;
			this->btn1->Location = System::Drawing::Point(2, 41);
			this->btn1->Margin = System::Windows::Forms::Padding(2);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(98, 109);
			this->btn1->TabIndex = 12;
			this->btn1->UseVisualStyleBackColor = false;
			// 
			// timerAct
			// 
			this->timerAct->Interval = 1;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1DosIB::timer1_Tick);
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
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1DosIB::picCerrar_Click);
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
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1DosIB::picMinimizar_Click);
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
			this->panel6->TabIndex = 3;
			// 
			// Act1DosIB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2450, 1334);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panelPrincipal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(7);
			this->Name = L"Act1DosIB";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1DosIB";
			this->Activated += gcnew System::EventHandler(this, &Act1DosIB::Act1DosIB_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1DosIB::Act1DosIB_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1DosIB::Act1DosIB_Load);
			this->panelPrincipal->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->EndInit();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel18->ResumeLayout(false);
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			this->panel20->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->panel14->ResumeLayout(false);
			this->panel14->PerformLayout();
			this->panel16->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel11->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel7->ResumeLayout(false);
			this->panel12->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			this->panel17->PerformLayout();
			this->panel15->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
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
	private: System::Void Act1DosIB_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosIB_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosIB_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TutIntV30::Act1DosIB::inicializarColor1();
	private: System::Void TutIntV30::Act1DosIB::inicializarColor2();
	private: System::Void TutIntV30::Act1DosIB::inicializarColor3();
	private: System::Void TutIntV30::Act1DosIB::inicializarColor4();
	private: System::Void btn1R_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1T_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1S_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2M_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2R_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2D_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3D_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3P_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3M_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4B_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4P_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4R_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::Button^ btn);
	private: vector<TiempoMI*> obtenerTiempoItems();
	};
}
