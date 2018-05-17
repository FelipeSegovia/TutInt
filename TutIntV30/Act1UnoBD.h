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
	/// Resumen de Act1UnoBD
	/// </summary>
	public ref class Act1UnoBD : public System::Windows::Forms::Form
	{
	public:
		Act1UnoBD(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act1UnoBD(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act1UnoBD()
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
	private: bool listoEsponjas = false, listoBallena = false, listoPinguino = false, listoEstrella = false;
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

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  lblEsponjas;
	private: System::Windows::Forms::Label^  lblPinguino;
	private: System::Windows::Forms::Label^  lblEstrella;
	private: System::Windows::Forms::Label^  lblBallena;
	private: System::Windows::Forms::TextBox^  textEsponjas;
	private: System::Windows::Forms::TextBox^  textPinguino;
	private: System::Windows::Forms::TextBox^  textEstrella;
	private: System::Windows::Forms::TextBox^  textBallena;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1UnoBD::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->lblEsponjas = (gcnew System::Windows::Forms::Label());
			this->lblPinguino = (gcnew System::Windows::Forms::Label());
			this->lblEstrella = (gcnew System::Windows::Forms::Label());
			this->lblBallena = (gcnew System::Windows::Forms::Label());
			this->textEsponjas = (gcnew System::Windows::Forms::TextBox());
			this->textPinguino = (gcnew System::Windows::Forms::TextBox());
			this->textEstrella = (gcnew System::Windows::Forms::TextBox());
			this->textBallena = (gcnew System::Windows::Forms::TextBox());
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->panelPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel4->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1UnoBD::timer1_Tick);
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
			this->panel6->Margin = System::Windows::Forms::Padding(1);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(832, 31);
			this->panel6->TabIndex = 5;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(5, 2);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(1);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(31, 28);
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
			this->label1->Location = System::Drawing::Point(35, 3);
			this->label1->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 25);
			this->label1->TabIndex = 32;
			this->label1->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(767, 2);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(1);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(27, 26);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1UnoBD::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(800, 2);
			this->picCerrar->Margin = System::Windows::Forms::Padding(1);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(27, 26);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1UnoBD::picCerrar_Click);
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
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 0);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(1);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(832, 494);
			this->panelPrincipal->TabIndex = 4;
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(0, 38);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(1);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(183, 112);
			this->btnAyuda->TabIndex = 11;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1UnoBD::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1UnoBD::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1UnoBD::btnAyuda_MouseHover);
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->btnListo);
			this->panel5->Controls->Add(this->btnVolver);
			this->panel5->Location = System::Drawing::Point(17, 324);
			this->panel5->Margin = System::Windows::Forms::Padding(1);
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
			this->btnListo->Margin = System::Windows::Forms::Padding(1);
			this->btnListo->Name = L"btnListo";
			this->btnListo->Size = System::Drawing::Size(171, 66);
			this->btnListo->TabIndex = 1;
			this->btnListo->TabStop = false;
			this->btnListo->Visible = false;
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1UnoBD::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1UnoBD::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1UnoBD::btnListo_MouseHover);
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(10, 23);
			this->btnVolver->Margin = System::Windows::Forms::Padding(1);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(181, 69);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1UnoBD::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1UnoBD::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1UnoBD::btnVolver_MouseHover);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->instruccion1);
			this->panel4->Controls->Add(this->instruccion2);
			this->panel4->Location = System::Drawing::Point(182, 32);
			this->panel4->Margin = System::Windows::Forms::Padding(1);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(860, 41);
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
			this->instruccion1->Size = System::Drawing::Size(571, 31);
			this->instruccion1->TabIndex = 5;
			this->instruccion1->Text = L"Cuenta la cantidad de letras que tiene cada palabra";
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::Color::White;
			this->instruccion2->Location = System::Drawing::Point(40, 4);
			this->instruccion2->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(811, 31);
			this->instruccion2->TabIndex = 4;
			this->instruccion2->Text = L"Debes contar cuántas letras tiene cada palabra y anotarlo en el cuadrado";
			this->instruccion2->Visible = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(266, 75);
			this->panel1->Margin = System::Windows::Forms::Padding(1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(732, 512);
			this->panel1->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				29.30743F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				41.38512F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				29.30745F)));
			this->tableLayoutPanel1->Controls->Add(this->panel2, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox3, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox4, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->lblEsponjas, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->lblPinguino, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->lblEstrella, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->lblBallena, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->textEsponjas, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->textPinguino, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->textEstrella, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBallena, 2, 4);
			this->tableLayoutPanel1->Location = System::Drawing::Point(74, 63);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.22222F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.22222F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.22222F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.22222F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(588, 417);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(417, 2);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(169, 42);
			this->panel2->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Padding = System::Windows::Forms::Padding(15, 9, 15, 9);
			this->label2->Size = System::Drawing::Size(188, 41);
			this->label2->TabIndex = 1;
			this->label2->Text = L"TOTAL DE LETRAS";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(21, 48);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(130, 88);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(41, 140);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(90, 88);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(34, 232);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(104, 88);
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(18, 324);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(135, 91);
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			// 
			// lblEsponjas
			// 
			this->lblEsponjas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblEsponjas->AutoSize = true;
			this->lblEsponjas->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEsponjas->ForeColor = System::Drawing::Color::Olive;
			this->lblEsponjas->Location = System::Drawing::Point(174, 46);
			this->lblEsponjas->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEsponjas->Name = L"lblEsponjas";
			this->lblEsponjas->Size = System::Drawing::Size(239, 92);
			this->lblEsponjas->TabIndex = 5;
			this->lblEsponjas->Text = L"ESPONJAS";
			this->lblEsponjas->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblPinguino
			// 
			this->lblPinguino->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblPinguino->AutoSize = true;
			this->lblPinguino->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPinguino->Location = System::Drawing::Point(174, 138);
			this->lblPinguino->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPinguino->Name = L"lblPinguino";
			this->lblPinguino->Size = System::Drawing::Size(239, 92);
			this->lblPinguino->TabIndex = 6;
			this->lblPinguino->Text = L"PINGÜINO";
			this->lblPinguino->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblEstrella
			// 
			this->lblEstrella->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblEstrella->AutoSize = true;
			this->lblEstrella->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstrella->Location = System::Drawing::Point(174, 230);
			this->lblEstrella->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEstrella->Name = L"lblEstrella";
			this->lblEstrella->Size = System::Drawing::Size(239, 92);
			this->lblEstrella->TabIndex = 7;
			this->lblEstrella->Text = L"ESTRELLA";
			this->lblEstrella->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblBallena
			// 
			this->lblBallena->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblBallena->AutoSize = true;
			this->lblBallena->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBallena->Location = System::Drawing::Point(174, 322);
			this->lblBallena->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblBallena->Name = L"lblBallena";
			this->lblBallena->Size = System::Drawing::Size(239, 95);
			this->lblBallena->TabIndex = 8;
			this->lblBallena->Text = L"BALLENA";
			this->lblBallena->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textEsponjas
			// 
			this->textEsponjas->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textEsponjas->BackColor = System::Drawing::Color::Olive;
			this->textEsponjas->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textEsponjas->ForeColor = System::Drawing::Color::White;
			this->textEsponjas->Location = System::Drawing::Point(468, 60);
			this->textEsponjas->Margin = System::Windows::Forms::Padding(2);
			this->textEsponjas->Name = L"textEsponjas";
			this->textEsponjas->Size = System::Drawing::Size(66, 64);
			this->textEsponjas->TabIndex = 9;
			this->textEsponjas->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textEsponjas->Click += gcnew System::EventHandler(this, &Act1UnoBD::textEsponjas_Click);
			this->textEsponjas->TextChanged += gcnew System::EventHandler(this, &Act1UnoBD::textEsponjas_TextChanged);
			this->textEsponjas->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Act1UnoBD::textEsponjas_KeyPress);
			// 
			// textPinguino
			// 
			this->textPinguino->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textPinguino->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textPinguino->Location = System::Drawing::Point(468, 152);
			this->textPinguino->Margin = System::Windows::Forms::Padding(2);
			this->textPinguino->Name = L"textPinguino";
			this->textPinguino->Size = System::Drawing::Size(66, 64);
			this->textPinguino->TabIndex = 10;
			this->textPinguino->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textPinguino->Click += gcnew System::EventHandler(this, &Act1UnoBD::textPinguino_Click);
			this->textPinguino->TextChanged += gcnew System::EventHandler(this, &Act1UnoBD::textPinguino_TextChanged);
			this->textPinguino->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Act1UnoBD::textPinguino_KeyPress);
			// 
			// textEstrella
			// 
			this->textEstrella->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textEstrella->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textEstrella->Location = System::Drawing::Point(468, 244);
			this->textEstrella->Margin = System::Windows::Forms::Padding(2);
			this->textEstrella->Name = L"textEstrella";
			this->textEstrella->Size = System::Drawing::Size(66, 64);
			this->textEstrella->TabIndex = 11;
			this->textEstrella->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textEstrella->Click += gcnew System::EventHandler(this, &Act1UnoBD::textEstrella_Click);
			this->textEstrella->TextChanged += gcnew System::EventHandler(this, &Act1UnoBD::textEstrella_TextChanged);
			this->textEstrella->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Act1UnoBD::textEstrella_KeyPress);
			// 
			// textBallena
			// 
			this->textBallena->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBallena->Font = (gcnew System::Drawing::Font(L"Consolas", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBallena->Location = System::Drawing::Point(468, 337);
			this->textBallena->Margin = System::Windows::Forms::Padding(2);
			this->textBallena->Name = L"textBallena";
			this->textBallena->Size = System::Drawing::Size(66, 64);
			this->textBallena->TabIndex = 12;
			this->textBallena->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBallena->Click += gcnew System::EventHandler(this, &Act1UnoBD::textBallena_Click);
			this->textBallena->TextChanged += gcnew System::EventHandler(this, &Act1UnoBD::textBallena_TextChanged);
			this->textBallena->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Act1UnoBD::textBallena_KeyPress);
			// 
			// Act1UnoBD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 494);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panelPrincipal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Act1UnoBD";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1UnoBD";
			this->Activated += gcnew System::EventHandler(this, &Act1UnoBD::Act1UnoBD_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1UnoBD::Act1UnoBD_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1UnoBD::Act1UnoBD_Load);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->panelPrincipal->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->EndInit();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void inicializarTam();
	private: void comprobarRespuestas();
	private: void sonidoInicial();
	private: void cambiarColor();
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
	private: System::Void Act1UnoBD_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoBD_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1UnoBD_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::TextBox^ textBox);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void textEsponjas_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	private: System::Void textEstrella_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	private: System::Void textBallena_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	private: System::Void textPinguino_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	private: System::Void textEsponjas_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textEstrella_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textBallena_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textPinguino_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textEsponjas_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textEstrella_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textBallena_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void textPinguino_TextChanged(System::Object^  sender, System::EventArgs^  e);
	};
}
