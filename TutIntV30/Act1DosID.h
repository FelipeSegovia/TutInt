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
	/// Resumen de Act1DosID
	/// </summary>
	public ref class Act1DosID : public System::Windows::Forms::Form
	{
	public:
		Act1DosID(void)
		{
			InitializeComponent();
		}
		Act1DosID(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act1DosID()
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
	private: bool listoCon1 = false, listoCon2 = false, listoPeli1 = false, listoPeli2 = false, listoGav1 = false, listoGav2 = false, listoCan1 = false, listoCan2 = false;
	private: bool presBtn1 = false, presBtn2 = false, presBtn3 = false, presBtn4 = false, presBtn5 = false, presBtn6 = false, presBtn7 = false, presBtn8 = false;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  btnListo;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Panel^  instruccion2;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  btnAyuda;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Button^  btn8;
	private: System::Windows::Forms::Button^  btn7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Button^  btn6;
	private: System::Windows::Forms::Button^  btn5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::Button^  btn3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Button^  btn4C;
	private: System::Windows::Forms::Button^  btn4E;
	private: System::Windows::Forms::Button^  btn4I;
	private: System::Windows::Forms::Button^  btn4A;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  btn3A;
	private: System::Windows::Forms::Button^  btn3E;
	private: System::Windows::Forms::Button^  btn3I;
	private: System::Windows::Forms::Button^  btn3O;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  btn2A;
	private: System::Windows::Forms::Button^  btn2E;
	private: System::Windows::Forms::Button^  btn2I;
	private: System::Windows::Forms::Button^  btn2O;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  btn1A;
	private: System::Windows::Forms::Button^  btn1J;
	private: System::Windows::Forms::Button^  btn1L;
	private: System::Windows::Forms::Button^  btn1U;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Button^  btn2;
	private: System::Windows::Forms::Button^  btn1;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Panel^  panel15;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Panel^  panel16;
	private: System::Windows::Forms::Panel^  panel17;
	private: System::Windows::Forms::Panel^  panel18;
	private: System::Windows::Forms::Panel^  panel19;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Panel^  panel20;
	private: System::Windows::Forms::Panel^  panel21;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Panel^  panel24;
	private: System::Windows::Forms::Panel^  panel29;
	private: System::Windows::Forms::Panel^  panel30;
	private: System::Windows::Forms::Panel^  panel31;
	private: System::Windows::Forms::Panel^  panel32;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel22;
	private: System::Windows::Forms::Panel^  panel23;
	private: System::Windows::Forms::Panel^  panel25;
	private: System::Windows::Forms::Panel^  panel26;
	private: System::Windows::Forms::Panel^  panel27;
	private: System::Windows::Forms::Panel^  panel28;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Panel^  instruccion1;
	private: System::Windows::Forms::Label^  label15;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act1DosID::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->btnListo = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->instruccion2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnAyuda = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->panel31 = (gcnew System::Windows::Forms::Panel());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->panel32 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn4C = (gcnew System::Windows::Forms::Button());
			this->btn4E = (gcnew System::Windows::Forms::Button());
			this->btn4I = (gcnew System::Windows::Forms::Button());
			this->btn4A = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn3A = (gcnew System::Windows::Forms::Button());
			this->btn3E = (gcnew System::Windows::Forms::Button());
			this->btn3I = (gcnew System::Windows::Forms::Button());
			this->btn3O = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn2A = (gcnew System::Windows::Forms::Button());
			this->btn2E = (gcnew System::Windows::Forms::Button());
			this->btn2I = (gcnew System::Windows::Forms::Button());
			this->btn2O = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btn1A = (gcnew System::Windows::Forms::Button());
			this->btn1J = (gcnew System::Windows::Forms::Button());
			this->btn1L = (gcnew System::Windows::Forms::Button());
			this->btn1U = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->instruccion1 = (gcnew System::Windows::Forms::Panel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panelPrincipal->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->instruccion2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel24->SuspendLayout();
			this->panel29->SuspendLayout();
			this->panel30->SuspendLayout();
			this->panel31->SuspendLayout();
			this->panel32->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel22->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel25->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel27->SuspendLayout();
			this->panel28->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel16->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel18->SuspendLayout();
			this->panel19->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel21->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel15->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->instruccion1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act1DosID::timer1_Tick);
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->instruccion1);
			this->panelPrincipal->Controls->Add(this->panel5);
			this->panelPrincipal->Controls->Add(this->instruccion2);
			this->panelPrincipal->Controls->Add(this->btnAyuda);
			this->panelPrincipal->Controls->Add(this->panel1);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 70);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(2450, 1264);
			this->panelPrincipal->TabIndex = 4;
			// 
			// panel5
			// 
			this->panel5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel5.BackgroundImage")));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->btnListo);
			this->panel5->Controls->Add(this->btnVolver);
			this->panel5->Location = System::Drawing::Point(40, 722);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(484, 512);
			this->panel5->TabIndex = 10;
			// 
			// btnListo
			// 
			this->btnListo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnListo.BackgroundImage")));
			this->btnListo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnListo->Enabled = false;
			this->btnListo->Location = System::Drawing::Point(59, 200);
			this->btnListo->Name = L"btnListo";
			this->btnListo->Size = System::Drawing::Size(398, 147);
			this->btnListo->TabIndex = 1;
			this->btnListo->TabStop = false;
			this->btnListo->Visible = false;
			this->btnListo->Click += gcnew System::EventHandler(this, &Act1DosID::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act1DosID::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act1DosID::btnListo_MouseHover);
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(23, 51);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(422, 155);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act1DosID::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act1DosID::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act1DosID::btnVolver_MouseHover);
			// 
			// instruccion2
			// 
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"instruccion2.BackgroundImage")));
			this->instruccion2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->instruccion2->Controls->Add(this->label14);
			this->instruccion2->Controls->Add(this->label6);
			this->instruccion2->Location = System::Drawing::Point(433, 14);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(1407, 136);
			this->instruccion2->TabIndex = 7;
			this->instruccion2->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(156, 8);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(1137, 58);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Para completar la palabra, presiona el cuadro blanco y";
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(5, 26);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(412, 239);
			this->btnAyuda->TabIndex = 1;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act1DosID::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act1DosID::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act1DosID::btnAyuda_MouseHover);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Location = System::Drawing::Point(619, 163);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1709, 1089);
			this->panel1->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.56753F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35.94588F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.48659F)));
			this->tableLayoutPanel1->Controls->Add(this->panel8, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel7, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel5, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 2, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(164, 99);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1428, 902);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->panel24);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(823, 678);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(602, 221);
			this->panel8->TabIndex = 19;
			// 
			// panel24
			// 
			this->panel24->Controls->Add(this->panel29);
			this->panel24->Controls->Add(this->panel30);
			this->panel24->Controls->Add(this->panel31);
			this->panel24->Controls->Add(this->panel32);
			this->panel24->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel24->Location = System::Drawing::Point(0, 0);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(602, 221);
			this->panel24->TabIndex = 13;
			// 
			// panel29
			// 
			this->panel29->Controls->Add(this->label4);
			this->panel29->Location = System::Drawing::Point(417, 0);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(147, 232);
			this->panel29->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(-17, 68);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(134, 98);
			this->label4->TabIndex = 10;
			this->label4->Text = L"NO";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel30
			// 
			this->panel30->Controls->Add(this->btn8);
			this->panel30->Location = System::Drawing::Point(331, 0);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(87, 232);
			this->panel30->TabIndex = 16;
			// 
			// btn8
			// 
			this->btn8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn8->BackColor = System::Drawing::Color::White;
			this->btn8->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn8->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn8->ForeColor = System::Drawing::Color::Black;
			this->btn8->Location = System::Drawing::Point(0, 60);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(84, 103);
			this->btn8->TabIndex = 12;
			this->btn8->UseVisualStyleBackColor = false;
			this->btn8->Click += gcnew System::EventHandler(this, &Act1DosID::btn8_Click);
			// 
			// panel31
			// 
			this->panel31->Controls->Add(this->btn7);
			this->panel31->Location = System::Drawing::Point(245, 0);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(89, 232);
			this->panel31->TabIndex = 15;
			// 
			// btn7
			// 
			this->btn7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn7->BackColor = System::Drawing::Color::White;
			this->btn7->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn7->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn7->ForeColor = System::Drawing::Color::Black;
			this->btn7->Location = System::Drawing::Point(3, 60);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(84, 103);
			this->btn7->TabIndex = 11;
			this->btn7->UseVisualStyleBackColor = false;
			this->btn7->Click += gcnew System::EventHandler(this, &Act1DosID::btn7_Click);
			// 
			// panel32
			// 
			this->panel32->Controls->Add(this->label5);
			this->panel32->Location = System::Drawing::Point(53, 2);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(192, 232);
			this->panel32->TabIndex = 14;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(-11, 66);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(226, 98);
			this->label5->TabIndex = 11;
			this->label5->Text = L"PELI";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->panel22);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(823, 453);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(602, 219);
			this->panel7->TabIndex = 18;
			// 
			// panel22
			// 
			this->panel22->Controls->Add(this->panel23);
			this->panel22->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel22->Location = System::Drawing::Point(0, 0);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(602, 219);
			this->panel22->TabIndex = 17;
			// 
			// panel23
			// 
			this->panel23->Controls->Add(this->panel25);
			this->panel23->Controls->Add(this->panel26);
			this->panel23->Controls->Add(this->panel27);
			this->panel23->Controls->Add(this->panel28);
			this->panel23->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel23->Location = System::Drawing::Point(0, 0);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(602, 219);
			this->panel23->TabIndex = 12;
			// 
			// panel25
			// 
			this->panel25->Controls->Add(this->btn6);
			this->panel25->Location = System::Drawing::Point(417, 0);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(90, 232);
			this->panel25->TabIndex = 17;
			// 
			// btn6
			// 
			this->btn6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn6->BackColor = System::Drawing::Color::White;
			this->btn6->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn6->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn6->ForeColor = System::Drawing::Color::Black;
			this->btn6->Location = System::Drawing::Point(3, 59);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(84, 103);
			this->btn6->TabIndex = 12;
			this->btn6->UseVisualStyleBackColor = false;
			this->btn6->Click += gcnew System::EventHandler(this, &Act1DosID::btn6_Click);
			// 
			// panel26
			// 
			this->panel26->Controls->Add(this->label3);
			this->panel26->Location = System::Drawing::Point(269, 0);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(157, 232);
			this->panel26->TabIndex = 16;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(-16, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(180, 98);
			this->label3->TabIndex = 10;
			this->label3->Text = L"NCH";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel27
			// 
			this->panel27->Controls->Add(this->btn5);
			this->panel27->Location = System::Drawing::Point(183, 0);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(89, 232);
			this->panel27->TabIndex = 15;
			// 
			// btn5
			// 
			this->btn5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn5->BackColor = System::Drawing::Color::White;
			this->btn5->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn5->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn5->ForeColor = System::Drawing::Color::Black;
			this->btn5->Location = System::Drawing::Point(2, 59);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(84, 103);
			this->btn5->TabIndex = 11;
			this->btn5->UseVisualStyleBackColor = false;
			this->btn5->Click += gcnew System::EventHandler(this, &Act1DosID::btn5_Click);
			// 
			// panel28
			// 
			this->panel28->Controls->Add(this->label13);
			this->panel28->Location = System::Drawing::Point(109, 2);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(77, 232);
			this->panel28->TabIndex = 14;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label13->Location = System::Drawing::Point(12, 66);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(88, 98);
			this->label13->TabIndex = 12;
			this->label13->Text = L"C";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->panel10);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(823, 228);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(602, 219);
			this->panel3->TabIndex = 17;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->panel16);
			this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel10->Location = System::Drawing::Point(0, 0);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(602, 219);
			this->panel10->TabIndex = 17;
			// 
			// panel16
			// 
			this->panel16->Controls->Add(this->panel17);
			this->panel16->Controls->Add(this->panel18);
			this->panel16->Controls->Add(this->panel19);
			this->panel16->Controls->Add(this->panel20);
			this->panel16->Controls->Add(this->panel21);
			this->panel16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel16->Location = System::Drawing::Point(0, 0);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(602, 219);
			this->panel16->TabIndex = 12;
			// 
			// panel17
			// 
			this->panel17->Controls->Add(this->label2);
			this->panel17->Location = System::Drawing::Point(374, 0);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(187, 232);
			this->panel17->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(-16, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 98);
			this->label2->TabIndex = 10;
			this->label2->Text = L"OTA";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel18
			// 
			this->panel18->Controls->Add(this->btn4);
			this->panel18->Location = System::Drawing::Point(287, 0);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(90, 232);
			this->panel18->TabIndex = 17;
			// 
			// btn4
			// 
			this->btn4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4->BackColor = System::Drawing::Color::White;
			this->btn4->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4->ForeColor = System::Drawing::Color::Black;
			this->btn4->Location = System::Drawing::Point(2, 59);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(84, 103);
			this->btn4->TabIndex = 12;
			this->btn4->UseVisualStyleBackColor = false;
			this->btn4->Click += gcnew System::EventHandler(this, &Act1DosID::btn4_Click);
			// 
			// panel19
			// 
			this->panel19->Controls->Add(this->label11);
			this->panel19->Location = System::Drawing::Point(231, 0);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(57, 232);
			this->panel19->TabIndex = 16;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label11->Location = System::Drawing::Point(-12, 71);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(88, 98);
			this->label11->TabIndex = 11;
			this->label11->Text = L"V";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel20
			// 
			this->panel20->Controls->Add(this->btn3);
			this->panel20->Location = System::Drawing::Point(145, 0);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(89, 232);
			this->panel20->TabIndex = 15;
			// 
			// btn3
			// 
			this->btn3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3->BackColor = System::Drawing::Color::White;
			this->btn3->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3->ForeColor = System::Drawing::Color::Black;
			this->btn3->Location = System::Drawing::Point(2, 59);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(84, 103);
			this->btn3->TabIndex = 11;
			this->btn3->UseVisualStyleBackColor = false;
			this->btn3->Click += gcnew System::EventHandler(this, &Act1DosID::btn3_Click);
			// 
			// panel21
			// 
			this->panel21->Controls->Add(this->label12);
			this->panel21->Location = System::Drawing::Point(71, 2);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(77, 232);
			this->panel21->TabIndex = 14;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label12->Location = System::Drawing::Point(10, 69);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(88, 98);
			this->label12->TabIndex = 12;
			this->label12->Text = L"G";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 4;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->Controls->Add(this->btn4C, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4E, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4I, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->btn4A, 2, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(310, 678);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(507, 221);
			this->tableLayoutPanel5->TabIndex = 15;
			// 
			// btn4C
			// 
			this->btn4C->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4C->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4C->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4C->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4C->ForeColor = System::Drawing::Color::White;
			this->btn4C->Location = System::Drawing::Point(139, 60);
			this->btn4C->Name = L"btn4C";
			this->btn4C->Size = System::Drawing::Size(100, 100);
			this->btn4C->TabIndex = 3;
			this->btn4C->Text = L"C";
			this->btn4C->UseVisualStyleBackColor = false;
			this->btn4C->Click += gcnew System::EventHandler(this, &Act1DosID::btn4C_Click);
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
			this->btn4E->Location = System::Drawing::Point(13, 60);
			this->btn4E->Name = L"btn4E";
			this->btn4E->Size = System::Drawing::Size(100, 100);
			this->btn4E->TabIndex = 0;
			this->btn4E->Text = L"E";
			this->btn4E->UseVisualStyleBackColor = false;
			this->btn4E->Click += gcnew System::EventHandler(this, &Act1DosID::btn4E_Click);
			// 
			// btn4I
			// 
			this->btn4I->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn4I->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn4I->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn4I->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4I->ForeColor = System::Drawing::Color::White;
			this->btn4I->Location = System::Drawing::Point(265, 60);
			this->btn4I->Name = L"btn4I";
			this->btn4I->Size = System::Drawing::Size(100, 100);
			this->btn4I->TabIndex = 1;
			this->btn4I->Text = L"I";
			this->btn4I->UseVisualStyleBackColor = false;
			this->btn4I->Click += gcnew System::EventHandler(this, &Act1DosID::btn4I_Click);
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
			this->btn4A->Location = System::Drawing::Point(392, 60);
			this->btn4A->Name = L"btn4A";
			this->btn4A->Size = System::Drawing::Size(100, 100);
			this->btn4A->TabIndex = 2;
			this->btn4A->Text = L"A";
			this->btn4A->UseVisualStyleBackColor = false;
			this->btn4A->Click += gcnew System::EventHandler(this, &Act1DosID::btn4A_Click);
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 4;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->Controls->Add(this->btn3A, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3E, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3I, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->btn3O, 2, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(310, 453);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(507, 219);
			this->tableLayoutPanel4->TabIndex = 14;
			// 
			// btn3A
			// 
			this->btn3A->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3A->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3A->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3A->ForeColor = System::Drawing::Color::White;
			this->btn3A->Location = System::Drawing::Point(139, 59);
			this->btn3A->Name = L"btn3A";
			this->btn3A->Size = System::Drawing::Size(100, 100);
			this->btn3A->TabIndex = 3;
			this->btn3A->Text = L"A";
			this->btn3A->UseVisualStyleBackColor = false;
			this->btn3A->Click += gcnew System::EventHandler(this, &Act1DosID::btn3A_Click);
			// 
			// btn3E
			// 
			this->btn3E->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3E->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3E->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3E->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3E->ForeColor = System::Drawing::Color::White;
			this->btn3E->Location = System::Drawing::Point(13, 59);
			this->btn3E->Name = L"btn3E";
			this->btn3E->Size = System::Drawing::Size(100, 100);
			this->btn3E->TabIndex = 0;
			this->btn3E->Text = L"E";
			this->btn3E->UseVisualStyleBackColor = false;
			this->btn3E->Click += gcnew System::EventHandler(this, &Act1DosID::btn3E_Click);
			// 
			// btn3I
			// 
			this->btn3I->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3I->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3I->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3I->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3I->ForeColor = System::Drawing::Color::White;
			this->btn3I->Location = System::Drawing::Point(265, 59);
			this->btn3I->Name = L"btn3I";
			this->btn3I->Size = System::Drawing::Size(100, 100);
			this->btn3I->TabIndex = 1;
			this->btn3I->Text = L"I";
			this->btn3I->UseVisualStyleBackColor = false;
			this->btn3I->Click += gcnew System::EventHandler(this, &Act1DosID::btn3I_Click);
			// 
			// btn3O
			// 
			this->btn3O->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn3O->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn3O->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn3O->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3O->ForeColor = System::Drawing::Color::White;
			this->btn3O->Location = System::Drawing::Point(392, 59);
			this->btn3O->Name = L"btn3O";
			this->btn3O->Size = System::Drawing::Size(100, 100);
			this->btn3O->TabIndex = 2;
			this->btn3O->Text = L"O";
			this->btn3O->UseVisualStyleBackColor = false;
			this->btn3O->Click += gcnew System::EventHandler(this, &Act1DosID::btn3O_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel3->Controls->Add(this->btn2A, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2E, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2I, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->btn2O, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(310, 228);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(507, 219);
			this->tableLayoutPanel3->TabIndex = 11;
			// 
			// btn2A
			// 
			this->btn2A->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2A->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2A->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2A->ForeColor = System::Drawing::Color::White;
			this->btn2A->Location = System::Drawing::Point(139, 59);
			this->btn2A->Name = L"btn2A";
			this->btn2A->Size = System::Drawing::Size(100, 100);
			this->btn2A->TabIndex = 3;
			this->btn2A->Text = L"A";
			this->btn2A->UseVisualStyleBackColor = false;
			this->btn2A->Click += gcnew System::EventHandler(this, &Act1DosID::btn2A_Click);
			// 
			// btn2E
			// 
			this->btn2E->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2E->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2E->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2E->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2E->ForeColor = System::Drawing::Color::White;
			this->btn2E->Location = System::Drawing::Point(13, 59);
			this->btn2E->Name = L"btn2E";
			this->btn2E->Size = System::Drawing::Size(100, 100);
			this->btn2E->TabIndex = 0;
			this->btn2E->Text = L"E";
			this->btn2E->UseVisualStyleBackColor = false;
			this->btn2E->Click += gcnew System::EventHandler(this, &Act1DosID::btn2E_Click);
			// 
			// btn2I
			// 
			this->btn2I->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2I->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2I->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2I->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2I->ForeColor = System::Drawing::Color::White;
			this->btn2I->Location = System::Drawing::Point(265, 59);
			this->btn2I->Name = L"btn2I";
			this->btn2I->Size = System::Drawing::Size(100, 100);
			this->btn2I->TabIndex = 1;
			this->btn2I->Text = L"I";
			this->btn2I->UseVisualStyleBackColor = false;
			this->btn2I->Click += gcnew System::EventHandler(this, &Act1DosID::btn2I_Click);
			// 
			// btn2O
			// 
			this->btn2O->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn2O->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn2O->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn2O->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2O->ForeColor = System::Drawing::Color::White;
			this->btn2O->Location = System::Drawing::Point(392, 59);
			this->btn2O->Name = L"btn2O";
			this->btn2O->Size = System::Drawing::Size(100, 100);
			this->btn2O->TabIndex = 2;
			this->btn2O->Text = L"O";
			this->btn2O->UseVisualStyleBackColor = false;
			this->btn2O->Click += gcnew System::EventHandler(this, &Act1DosID::btn2O_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->Controls->Add(this->btn1A, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1J, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1L, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->btn1U, 2, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(310, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(507, 219);
			this->tableLayoutPanel2->TabIndex = 11;
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
			this->btn1A->Location = System::Drawing::Point(139, 59);
			this->btn1A->Name = L"btn1A";
			this->btn1A->Size = System::Drawing::Size(100, 100);
			this->btn1A->TabIndex = 3;
			this->btn1A->Text = L"A";
			this->btn1A->UseVisualStyleBackColor = false;
			this->btn1A->Click += gcnew System::EventHandler(this, &Act1DosID::btn1A_Click);
			// 
			// btn1J
			// 
			this->btn1J->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1J->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1J->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1J->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1J->ForeColor = System::Drawing::Color::White;
			this->btn1J->Location = System::Drawing::Point(13, 59);
			this->btn1J->Name = L"btn1J";
			this->btn1J->Size = System::Drawing::Size(100, 100);
			this->btn1J->TabIndex = 0;
			this->btn1J->Text = L"J";
			this->btn1J->UseVisualStyleBackColor = false;
			this->btn1J->Click += gcnew System::EventHandler(this, &Act1DosID::btn1J_Click);
			// 
			// btn1L
			// 
			this->btn1L->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1L->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1L->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1L->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1L->ForeColor = System::Drawing::Color::White;
			this->btn1L->Location = System::Drawing::Point(265, 59);
			this->btn1L->Name = L"btn1L";
			this->btn1L->Size = System::Drawing::Size(100, 100);
			this->btn1L->TabIndex = 1;
			this->btn1L->Text = L"L";
			this->btn1L->UseVisualStyleBackColor = false;
			this->btn1L->Click += gcnew System::EventHandler(this, &Act1DosID::btn1L_Click);
			// 
			// btn1U
			// 
			this->btn1U->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1U->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn1U->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1U->Font = (gcnew System::Drawing::Font(L"Consolas", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1U->ForeColor = System::Drawing::Color::White;
			this->btn1U->Location = System::Drawing::Point(392, 59);
			this->btn1U->Name = L"btn1U";
			this->btn1U->Size = System::Drawing::Size(100, 100);
			this->btn1U->TabIndex = 2;
			this->btn1U->Text = L"U";
			this->btn1U->UseVisualStyleBackColor = false;
			this->btn1U->Click += gcnew System::EventHandler(this, &Act1DosID::btn1U_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(8, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(290, 194);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(3, 245);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(301, 185);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(17, 473);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(273, 179);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(31, 678);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(245, 221);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel9);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(823, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(602, 219);
			this->panel2->TabIndex = 16;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->panel15);
			this->panel9->Controls->Add(this->panel14);
			this->panel9->Controls->Add(this->panel13);
			this->panel9->Controls->Add(this->panel12);
			this->panel9->Controls->Add(this->panel11);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(0, 0);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(602, 219);
			this->panel9->TabIndex = 12;
			// 
			// panel15
			// 
			this->panel15->Controls->Add(this->label7);
			this->panel15->Location = System::Drawing::Point(490, 0);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(100, 232);
			this->panel15->TabIndex = 18;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(-15, 68);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(88, 98);
			this->label7->TabIndex = 11;
			this->label7->Text = L"O";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel14
			// 
			this->panel14->Controls->Add(this->btn2);
			this->panel14->Location = System::Drawing::Point(404, 0);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(90, 232);
			this->panel14->TabIndex = 17;
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
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(84, 103);
			this->btn2->TabIndex = 12;
			this->btn2->UseVisualStyleBackColor = false;
			this->btn2->Click += gcnew System::EventHandler(this, &Act1DosID::btn2_Click);
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->label8);
			this->panel13->Location = System::Drawing::Point(218, 0);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(192, 232);
			this->panel13->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(-18, 71);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(226, 98);
			this->label8->TabIndex = 11;
			this->label8->Text = L"NGRE";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->btn1);
			this->panel12->Location = System::Drawing::Point(132, 0);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(89, 232);
			this->panel12->TabIndex = 15;
			// 
			// btn1
			// 
			this->btn1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn1->BackColor = System::Drawing::Color::White;
			this->btn1->FlatAppearance->BorderColor = System::Drawing::Color::Red;
			this->btn1->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1->ForeColor = System::Drawing::Color::Black;
			this->btn1->Location = System::Drawing::Point(2, 59);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(84, 103);
			this->btn1->TabIndex = 11;
			this->btn1->UseVisualStyleBackColor = false;
			this->btn1->Click += gcnew System::EventHandler(this, &Act1DosID::btn1_Click);
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->label9);
			this->panel11->Location = System::Drawing::Point(58, 2);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(77, 232);
			this->panel11->TabIndex = 14;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Consolas", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(12, 66);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(88, 98);
			this->label9->TabIndex = 12;
			this->label9->Text = L"C";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(2450, 70);
			this->panel6->TabIndex = 5;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(12, 4);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(72, 63);
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
			this->label1->Location = System::Drawing::Point(81, 7);
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
			this->picMinimizar->Location = System::Drawing::Point(2300, 5);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(64, 59);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act1DosID::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(2375, 5);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(64, 59);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act1DosID::picCerrar_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(152, 68);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(1021, 58);
			this->label14->TabIndex = 5;
			this->label14->Text = L"luego presiona la letra que falta en ese recuadro";
			// 
			// instruccion1
			// 
			this->instruccion1->BackColor = System::Drawing::Color::Transparent;
			this->instruccion1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"instruccion1.BackgroundImage")));
			this->instruccion1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->instruccion1->Controls->Add(this->label15);
			this->instruccion1->Location = System::Drawing::Point(428, 17);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(1551, 92);
			this->instruccion1->TabIndex = 8;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::White;
			this->label15->Location = System::Drawing::Point(129, 8);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(1298, 67);
			this->label15->TabIndex = 4;
			this->label15->Text = L"Completa la palabra, presionando las letras que faltan";
			// 
			// Act1DosID
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2450, 1334);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel6);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Act1DosID";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act1DosID";
			this->Activated += gcnew System::EventHandler(this, &Act1DosID::Act1DosID_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act1DosID::Act1DosID_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act1DosID::Act1DosID_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->instruccion2->ResumeLayout(false);
			this->instruccion2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->EndInit();
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel24->ResumeLayout(false);
			this->panel29->ResumeLayout(false);
			this->panel29->PerformLayout();
			this->panel30->ResumeLayout(false);
			this->panel31->ResumeLayout(false);
			this->panel32->ResumeLayout(false);
			this->panel32->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel22->ResumeLayout(false);
			this->panel23->ResumeLayout(false);
			this->panel25->ResumeLayout(false);
			this->panel26->ResumeLayout(false);
			this->panel26->PerformLayout();
			this->panel27->ResumeLayout(false);
			this->panel28->ResumeLayout(false);
			this->panel28->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel16->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			this->panel17->PerformLayout();
			this->panel18->ResumeLayout(false);
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			this->panel20->ResumeLayout(false);
			this->panel21->ResumeLayout(false);
			this->panel21->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			this->panel14->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->instruccion1->ResumeLayout(false);
			this->instruccion1->PerformLayout();
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
	private: System::Void Act1DosID_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosID_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act1DosID_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1J_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1L_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1A_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1U_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2E_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2A_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2I_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2O_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3E_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3A_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3I_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3O_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4E_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4C_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4I_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4A_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn5_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn6_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn7_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn8_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::Button^ btn1, System::Windows::Forms::Button^ btn2);
	private: vector<TiempoMI*> obtenerTiempoItems();
	};
}
