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
	/// Resumen de Act2DosIB
	/// </summary>
	public ref class Act2DosIB : public System::Windows::Forms::Form
	{
	public:
		Act2DosIB(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act2DosIB(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act2DosIB()
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
	private: bool listoBtn1, listoBtn2, listoBtn3, listoBtn4;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::PictureBox^  btnListo;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  instruccion1;



	private: System::Windows::Forms::PictureBox^  btnAyuda;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  btn4;
	private: System::Windows::Forms::PictureBox^  btn2;
	private: System::Windows::Forms::PictureBox^  btn3;
	private: System::Windows::Forms::PictureBox^  btn1;
	private: System::Windows::Forms::PictureBox^  btn4No;
	private: System::Windows::Forms::PictureBox^  btn4Si;
	private: System::Windows::Forms::PictureBox^  btn3No;
	private: System::Windows::Forms::PictureBox^  btn3Si;
	private: System::Windows::Forms::PictureBox^  btn2No;
	private: System::Windows::Forms::PictureBox^  btn2Si;
	private: System::Windows::Forms::PictureBox^  btn1No;
	private: System::Windows::Forms::PictureBox^  btn1Si;
	private: System::Windows::Forms::PictureBox^  btn4NoM;
	private: System::Windows::Forms::PictureBox^  btn4SiM;
	private: System::Windows::Forms::PictureBox^  btn3NoM;
	private: System::Windows::Forms::PictureBox^  btn3SiM;
	private: System::Windows::Forms::PictureBox^  btn2NoM;
	private: System::Windows::Forms::PictureBox^  btn2SiM;
	private: System::Windows::Forms::PictureBox^  btn1NoM;
	private: System::Windows::Forms::PictureBox^  btn1SiM;
	private: System::Windows::Forms::Panel^  instruccion2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblinstr1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act2DosIB::typeid));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->instruccion2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->btnListo = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn4NoM = (gcnew System::Windows::Forms::PictureBox());
			this->btn4SiM = (gcnew System::Windows::Forms::PictureBox());
			this->btn3NoM = (gcnew System::Windows::Forms::PictureBox());
			this->btn3SiM = (gcnew System::Windows::Forms::PictureBox());
			this->btn2NoM = (gcnew System::Windows::Forms::PictureBox());
			this->btn2SiM = (gcnew System::Windows::Forms::PictureBox());
			this->btn1NoM = (gcnew System::Windows::Forms::PictureBox());
			this->btn1SiM = (gcnew System::Windows::Forms::PictureBox());
			this->btn4No = (gcnew System::Windows::Forms::PictureBox());
			this->btn4Si = (gcnew System::Windows::Forms::PictureBox());
			this->btn3No = (gcnew System::Windows::Forms::PictureBox());
			this->btn3Si = (gcnew System::Windows::Forms::PictureBox());
			this->btn2No = (gcnew System::Windows::Forms::PictureBox());
			this->btn2Si = (gcnew System::Windows::Forms::PictureBox());
			this->btn1No = (gcnew System::Windows::Forms::PictureBox());
			this->btn1Si = (gcnew System::Windows::Forms::PictureBox());
			this->btn4 = (gcnew System::Windows::Forms::PictureBox());
			this->btn2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn3 = (gcnew System::Windows::Forms::PictureBox());
			this->btn1 = (gcnew System::Windows::Forms::PictureBox());
			this->instruccion1 = (gcnew System::Windows::Forms::Panel());
			this->lblinstr1 = (gcnew System::Windows::Forms::Label());
			this->btnAyuda = (gcnew System::Windows::Forms::PictureBox());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPrincipal->SuspendLayout();
			this->instruccion2->SuspendLayout();
			this->panel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4NoM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4SiM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3NoM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3SiM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2NoM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2SiM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1NoM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1SiM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4No))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4Si))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3No))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3Si))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2No))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2Si))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1No))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1Si))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1))->BeginInit();
			this->instruccion1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->instruccion2);
			this->panelPrincipal->Controls->Add(this->panel13);
			this->panelPrincipal->Controls->Add(this->panel2);
			this->panelPrincipal->Controls->Add(this->instruccion1);
			this->panelPrincipal->Controls->Add(this->btnAyuda);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 39);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(1407, 720);
			this->panelPrincipal->TabIndex = 2;
			// 
			// instruccion2
			// 
			this->instruccion2->BackColor = System::Drawing::Color::Transparent;
			this->instruccion2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"instruccion2.BackgroundImage")));
			this->instruccion2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->instruccion2->Controls->Add(this->label2);
			this->instruccion2->Location = System::Drawing::Point(183, 1);
			this->instruccion2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(886, 79);
			this->instruccion2->TabIndex = 15;
			this->instruccion2->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(105, 6);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(711, 70);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Selecciona manito arriba si el objeto contiene la letra \"I\", \r\nde lo contrario se"
				L"lecciona manito abajo";
			// 
			// panel13
			// 
			this->panel13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel13.BackgroundImage")));
			this->panel13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel13->Controls->Add(this->btnListo);
			this->panel13->Controls->Add(this->btnVolver);
			this->panel13->Location = System::Drawing::Point(10, 375);
			this->panel13->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(277, 282);
			this->panel13->TabIndex = 13;
			// 
			// btnListo
			// 
			this->btnListo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnListo.BackgroundImage")));
			this->btnListo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnListo->Enabled = false;
			this->btnListo->Location = System::Drawing::Point(34, 110);
			this->btnListo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnListo->Name = L"btnListo";
			this->btnListo->Size = System::Drawing::Size(227, 81);
			this->btnListo->TabIndex = 1;
			this->btnListo->TabStop = false;
			this->btnListo->Visible = false;
			this->btnListo->Click += gcnew System::EventHandler(this, &Act2DosIB::btnListo_Click);
			this->btnListo->MouseLeave += gcnew System::EventHandler(this, &Act2DosIB::btnListo_MouseLeave);
			this->btnListo->MouseHover += gcnew System::EventHandler(this, &Act2DosIB::btnListo_MouseHover);
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(13, 28);
			this->btnVolver->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(241, 86);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &Act2DosIB::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &Act2DosIB::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &Act2DosIB::btnVolver_MouseHover);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->btn4NoM);
			this->panel2->Controls->Add(this->btn4SiM);
			this->panel2->Controls->Add(this->btn3NoM);
			this->panel2->Controls->Add(this->btn3SiM);
			this->panel2->Controls->Add(this->btn2NoM);
			this->panel2->Controls->Add(this->btn2SiM);
			this->panel2->Controls->Add(this->btn1NoM);
			this->panel2->Controls->Add(this->btn1SiM);
			this->panel2->Controls->Add(this->btn4No);
			this->panel2->Controls->Add(this->btn4Si);
			this->panel2->Controls->Add(this->btn3No);
			this->panel2->Controls->Add(this->btn3Si);
			this->panel2->Controls->Add(this->btn2No);
			this->panel2->Controls->Add(this->btn2Si);
			this->panel2->Controls->Add(this->btn1No);
			this->panel2->Controls->Add(this->btn1Si);
			this->panel2->Controls->Add(this->btn4);
			this->panel2->Controls->Add(this->btn2);
			this->panel2->Controls->Add(this->btn3);
			this->panel2->Controls->Add(this->btn1);
			this->panel2->Location = System::Drawing::Point(289, 83);
			this->panel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1095, 612);
			this->panel2->TabIndex = 12;
			// 
			// btn4NoM
			// 
			this->btn4NoM->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn4NoM.BackgroundImage")));
			this->btn4NoM->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn4NoM->Location = System::Drawing::Point(899, 332);
			this->btn4NoM->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn4NoM->Name = L"btn4NoM";
			this->btn4NoM->Size = System::Drawing::Size(100, 88);
			this->btn4NoM->TabIndex = 23;
			this->btn4NoM->TabStop = false;
			this->btn4NoM->Visible = false;
			// 
			// btn4SiM
			// 
			this->btn4SiM->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn4SiM.BackgroundImage")));
			this->btn4SiM->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn4SiM->Location = System::Drawing::Point(786, 331);
			this->btn4SiM->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn4SiM->Name = L"btn4SiM";
			this->btn4SiM->Size = System::Drawing::Size(100, 88);
			this->btn4SiM->TabIndex = 22;
			this->btn4SiM->TabStop = false;
			this->btn4SiM->Visible = false;
			// 
			// btn3NoM
			// 
			this->btn3NoM->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn3NoM.BackgroundImage")));
			this->btn3NoM->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn3NoM->Location = System::Drawing::Point(895, 156);
			this->btn3NoM->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn3NoM->Name = L"btn3NoM";
			this->btn3NoM->Size = System::Drawing::Size(100, 88);
			this->btn3NoM->TabIndex = 21;
			this->btn3NoM->TabStop = false;
			this->btn3NoM->Visible = false;
			// 
			// btn3SiM
			// 
			this->btn3SiM->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn3SiM.BackgroundImage")));
			this->btn3SiM->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn3SiM->Location = System::Drawing::Point(783, 156);
			this->btn3SiM->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn3SiM->Name = L"btn3SiM";
			this->btn3SiM->Size = System::Drawing::Size(100, 88);
			this->btn3SiM->TabIndex = 20;
			this->btn3SiM->TabStop = false;
			this->btn3SiM->Visible = false;
			// 
			// btn2NoM
			// 
			this->btn2NoM->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn2NoM.BackgroundImage")));
			this->btn2NoM->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn2NoM->Location = System::Drawing::Point(419, 331);
			this->btn2NoM->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn2NoM->Name = L"btn2NoM";
			this->btn2NoM->Size = System::Drawing::Size(100, 88);
			this->btn2NoM->TabIndex = 19;
			this->btn2NoM->TabStop = false;
			this->btn2NoM->Visible = false;
			// 
			// btn2SiM
			// 
			this->btn2SiM->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn2SiM.BackgroundImage")));
			this->btn2SiM->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn2SiM->Location = System::Drawing::Point(306, 332);
			this->btn2SiM->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn2SiM->Name = L"btn2SiM";
			this->btn2SiM->Size = System::Drawing::Size(100, 88);
			this->btn2SiM->TabIndex = 18;
			this->btn2SiM->TabStop = false;
			this->btn2SiM->Visible = false;
			// 
			// btn1NoM
			// 
			this->btn1NoM->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn1NoM.BackgroundImage")));
			this->btn1NoM->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn1NoM->Location = System::Drawing::Point(415, 156);
			this->btn1NoM->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn1NoM->Name = L"btn1NoM";
			this->btn1NoM->Size = System::Drawing::Size(100, 88);
			this->btn1NoM->TabIndex = 17;
			this->btn1NoM->TabStop = false;
			this->btn1NoM->Visible = false;
			// 
			// btn1SiM
			// 
			this->btn1SiM->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn1SiM.BackgroundImage")));
			this->btn1SiM->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn1SiM->Location = System::Drawing::Point(303, 156);
			this->btn1SiM->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn1SiM->Name = L"btn1SiM";
			this->btn1SiM->Size = System::Drawing::Size(100, 88);
			this->btn1SiM->TabIndex = 16;
			this->btn1SiM->TabStop = false;
			this->btn1SiM->Visible = false;
			// 
			// btn4No
			// 
			this->btn4No->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn4No.BackgroundImage")));
			this->btn4No->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn4No->Location = System::Drawing::Point(899, 331);
			this->btn4No->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn4No->Name = L"btn4No";
			this->btn4No->Size = System::Drawing::Size(100, 88);
			this->btn4No->TabIndex = 15;
			this->btn4No->TabStop = false;
			this->btn4No->Click += gcnew System::EventHandler(this, &Act2DosIB::btn4No_Click);
			// 
			// btn4Si
			// 
			this->btn4Si->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn4Si.BackgroundImage")));
			this->btn4Si->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn4Si->Location = System::Drawing::Point(786, 331);
			this->btn4Si->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn4Si->Name = L"btn4Si";
			this->btn4Si->Size = System::Drawing::Size(100, 88);
			this->btn4Si->TabIndex = 14;
			this->btn4Si->TabStop = false;
			this->btn4Si->Click += gcnew System::EventHandler(this, &Act2DosIB::btn4Si_Click);
			// 
			// btn3No
			// 
			this->btn3No->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn3No.BackgroundImage")));
			this->btn3No->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn3No->Location = System::Drawing::Point(895, 156);
			this->btn3No->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn3No->Name = L"btn3No";
			this->btn3No->Size = System::Drawing::Size(100, 88);
			this->btn3No->TabIndex = 13;
			this->btn3No->TabStop = false;
			this->btn3No->Click += gcnew System::EventHandler(this, &Act2DosIB::btn3No_Click);
			// 
			// btn3Si
			// 
			this->btn3Si->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn3Si.BackgroundImage")));
			this->btn3Si->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn3Si->Location = System::Drawing::Point(783, 156);
			this->btn3Si->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn3Si->Name = L"btn3Si";
			this->btn3Si->Size = System::Drawing::Size(100, 88);
			this->btn3Si->TabIndex = 12;
			this->btn3Si->TabStop = false;
			this->btn3Si->Click += gcnew System::EventHandler(this, &Act2DosIB::btn3Si_Click);
			// 
			// btn2No
			// 
			this->btn2No->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn2No.BackgroundImage")));
			this->btn2No->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn2No->Location = System::Drawing::Point(419, 331);
			this->btn2No->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn2No->Name = L"btn2No";
			this->btn2No->Size = System::Drawing::Size(100, 88);
			this->btn2No->TabIndex = 11;
			this->btn2No->TabStop = false;
			this->btn2No->Click += gcnew System::EventHandler(this, &Act2DosIB::btn2No_Click);
			// 
			// btn2Si
			// 
			this->btn2Si->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn2Si.BackgroundImage")));
			this->btn2Si->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn2Si->Location = System::Drawing::Point(306, 331);
			this->btn2Si->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn2Si->Name = L"btn2Si";
			this->btn2Si->Size = System::Drawing::Size(100, 88);
			this->btn2Si->TabIndex = 10;
			this->btn2Si->TabStop = false;
			this->btn2Si->Click += gcnew System::EventHandler(this, &Act2DosIB::btn2Si_Click);
			// 
			// btn1No
			// 
			this->btn1No->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn1No.BackgroundImage")));
			this->btn1No->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn1No->Location = System::Drawing::Point(415, 156);
			this->btn1No->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn1No->Name = L"btn1No";
			this->btn1No->Size = System::Drawing::Size(100, 88);
			this->btn1No->TabIndex = 9;
			this->btn1No->TabStop = false;
			this->btn1No->Click += gcnew System::EventHandler(this, &Act2DosIB::btn1No_Click);
			// 
			// btn1Si
			// 
			this->btn1Si->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn1Si.BackgroundImage")));
			this->btn1Si->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn1Si->Location = System::Drawing::Point(303, 156);
			this->btn1Si->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn1Si->Name = L"btn1Si";
			this->btn1Si->Size = System::Drawing::Size(100, 88);
			this->btn1Si->TabIndex = 8;
			this->btn1Si->TabStop = false;
			this->btn1Si->Click += gcnew System::EventHandler(this, &Act2DosIB::btn1Si_Click);
			// 
			// btn4
			// 
			this->btn4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn4.BackgroundImage")));
			this->btn4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn4->Location = System::Drawing::Point(626, 309);
			this->btn4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(139, 151);
			this->btn4->TabIndex = 7;
			this->btn4->TabStop = false;
			// 
			// btn2
			// 
			this->btn2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn2.BackgroundImage")));
			this->btn2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn2->Location = System::Drawing::Point(597, 127);
			this->btn2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(168, 147);
			this->btn2->TabIndex = 6;
			this->btn2->TabStop = false;
			// 
			// btn3
			// 
			this->btn3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn3.BackgroundImage")));
			this->btn3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn3->Location = System::Drawing::Point(101, 314);
			this->btn3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(188, 130);
			this->btn3->TabIndex = 5;
			this->btn3->TabStop = false;
			// 
			// btn1
			// 
			this->btn1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn1.BackgroundImage")));
			this->btn1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn1->Location = System::Drawing::Point(101, 129);
			this->btn1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(182, 145);
			this->btn1->TabIndex = 4;
			this->btn1->TabStop = false;
			// 
			// instruccion1
			// 
			this->instruccion1->BackColor = System::Drawing::Color::Transparent;
			this->instruccion1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->instruccion1->Controls->Add(this->lblinstr1);
			this->instruccion1->Location = System::Drawing::Point(185, 4);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(754, 54);
			this->instruccion1->TabIndex = 11;
			// 
			// lblinstr1
			// 
			this->lblinstr1->AutoSize = true;
			this->lblinstr1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblinstr1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblinstr1->Location = System::Drawing::Point(62, 6);
			this->lblinstr1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblinstr1->Name = L"lblinstr1";
			this->lblinstr1->Size = System::Drawing::Size(613, 38);
			this->lblinstr1->TabIndex = 14;
			this->lblinstr1->Text = L"Veamos si las imágenes contienen la letra \"I\"";
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(8, 7);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(171, 149);
			this->btnAyuda->TabIndex = 8;
			this->btnAyuda->TabStop = false;
			this->btnAyuda->Click += gcnew System::EventHandler(this, &Act2DosIB::btnAyuda_Click);
			this->btnAyuda->MouseLeave += gcnew System::EventHandler(this, &Act2DosIB::btnAyuda_MouseLeave);
			this->btnAyuda->MouseHover += gcnew System::EventHandler(this, &Act2DosIB::btnAyuda_MouseHover);
			// 
			// panel9
			// 
			this->panel9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel9.BackgroundImage")));
			this->panel9->Controls->Add(this->pictureBox7);
			this->panel9->Controls->Add(this->label6);
			this->panel9->Controls->Add(this->picMinimizar);
			this->panel9->Controls->Add(this->picCerrar);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel9->Location = System::Drawing::Point(0, 0);
			this->panel9->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1407, 39);
			this->panel9->TabIndex = 3;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(7, 2);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(41, 35);
			this->pictureBox7->TabIndex = 33;
			this->pictureBox7->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(46, 4);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(124, 31);
			this->label6->TabIndex = 32;
			this->label6->Text = L"TUTINT";
			// 
			// picMinimizar
			// 
			this->picMinimizar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picMinimizar->BackColor = System::Drawing::Color::Transparent;
			this->picMinimizar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picMinimizar.BackgroundImage")));
			this->picMinimizar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picMinimizar->Location = System::Drawing::Point(1321, 3);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(37, 33);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &Act2DosIB::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(1364, 3);
			this->picCerrar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(37, 33);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &Act2DosIB::picCerrar_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act2DosIB::timer1_Tick);
			// 
			// Act2DosIB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1407, 759);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel9);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Act2DosIB";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act2DosIB";
			this->Activated += gcnew System::EventHandler(this, &Act2DosIB::Act2DosIB_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act2DosIB::Act2DosIB_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act2DosIB::Act2DosIB_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->instruccion2->ResumeLayout(false);
			this->instruccion2->PerformLayout();
			this->panel13->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4NoM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4SiM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3NoM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3SiM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2NoM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2SiM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1NoM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1SiM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4No))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4Si))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3No))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3Si))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2No))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2Si))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1No))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1Si))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btn1))->EndInit();
			this->instruccion1->ResumeLayout(false);
			this->instruccion1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->EndInit();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
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
	private: System::Void Act2DosIB_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act2DosIB_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act2DosIB_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoBtn);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void btn1Si_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2Si_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3Si_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4Si_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn1No_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn2No_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn3No_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn4No_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
