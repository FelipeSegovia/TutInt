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
	/// Resumen de Act2DosDI
	/// </summary>
	public ref class Act2DosDI : public System::Windows::Forms::Form
	{
	public:
		Act2DosDI(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Act2DosDI(Form^ f, BaseDeDatos^ manejador, AgenteControlador* control)
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
		~Act2DosDI()
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
	private: int xbtn1, ybtn1, xbtn2, ybtn2, xbtn3, ybtn3, xbtn4, ybtn4;		// Guardar la posicion original del boton
	private: bool listoBtn1, listoBtn2, listoBtn3, listoBtn4;













	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  instruccion1;
	private: System::Windows::Forms::Label^  instruccion2;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::PictureBox^  btnListo;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  btnTres;
	private: System::Windows::Forms::Button^  btnDos;
	private: System::Windows::Forms::Button^  btnUno;
	private: System::Windows::Forms::Button^  btnCuatro;
	private: System::Windows::Forms::Panel^  panelCuatro;
	private: System::Windows::Forms::Panel^  panelTres;
	private: System::Windows::Forms::Panel^  panelDos;
	private: System::Windows::Forms::Panel^  panelUno;
	private: System::Windows::Forms::PictureBox^  btnAyuda;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;











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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Act2DosDI::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->instruccion1 = (gcnew System::Windows::Forms::Label());
			this->instruccion2 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->btnListo = (gcnew System::Windows::Forms::PictureBox());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnTres = (gcnew System::Windows::Forms::Button());
			this->btnDos = (gcnew System::Windows::Forms::Button());
			this->btnUno = (gcnew System::Windows::Forms::Button());
			this->btnCuatro = (gcnew System::Windows::Forms::Button());
			this->panelCuatro = (gcnew System::Windows::Forms::Panel());
			this->panelTres = (gcnew System::Windows::Forms::Panel());
			this->panelDos = (gcnew System::Windows::Forms::Panel());
			this->panelUno = (gcnew System::Windows::Forms::Panel());
			this->btnAyuda = (gcnew System::Windows::Forms::PictureBox());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panelPrincipal->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAyuda))->BeginInit();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Act2DosDI::timer1_Tick);
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->panel1);
			this->panelPrincipal->Controls->Add(this->panel13);
			this->panelPrincipal->Controls->Add(this->panel2);
			this->panelPrincipal->Controls->Add(this->btnAyuda);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 39);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(2);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(1348, 693);
			this->panelPrincipal->TabIndex = 4;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->instruccion1);
			this->panel1->Controls->Add(this->instruccion2);
			this->panel1->Location = System::Drawing::Point(183, 2);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(887, 54);
			this->panel1->TabIndex = 14;
			// 
			// instruccion1
			// 
			this->instruccion1->AutoSize = true;
			this->instruccion1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->instruccion1->Location = System::Drawing::Point(59, 7);
			this->instruccion1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion1->Name = L"instruccion1";
			this->instruccion1->Size = System::Drawing::Size(742, 38);
			this->instruccion1->TabIndex = 14;
			this->instruccion1->Text = L"Ordenemos las palabras, segun el orden del abecedario";
			// 
			// instruccion2
			// 
			this->instruccion2->AutoSize = true;
			this->instruccion2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instruccion2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->instruccion2->Location = System::Drawing::Point(56, 5);
			this->instruccion2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->instruccion2->Name = L"instruccion2";
			this->instruccion2->Size = System::Drawing::Size(744, 38);
			this->instruccion2->TabIndex = 13;
			this->instruccion2->Text = L"Ordena las imágenes, guiándote con la letra que inician";
			this->instruccion2->Visible = false;
			// 
			// panel13
			// 
			this->panel13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel13.BackgroundImage")));
			this->panel13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel13->Controls->Add(this->btnListo);
			this->panel13->Controls->Add(this->btnVolver);
			this->panel13->Location = System::Drawing::Point(10, 375);
			this->panel13->Margin = System::Windows::Forms::Padding(2);
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
			this->btnListo->Margin = System::Windows::Forms::Padding(2);
			this->btnListo->Name = L"btnListo";
			this->btnListo->Size = System::Drawing::Size(227, 81);
			this->btnListo->TabIndex = 1;
			this->btnListo->TabStop = false;
			this->btnListo->Visible = false;
			// 
			// btnVolver
			// 
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(13, 28);
			this->btnVolver->Margin = System::Windows::Forms::Padding(2);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(241, 86);
			this->btnVolver->TabIndex = 0;
			this->btnVolver->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->btnTres);
			this->panel2->Controls->Add(this->btnDos);
			this->panel2->Controls->Add(this->btnUno);
			this->panel2->Controls->Add(this->btnCuatro);
			this->panel2->Controls->Add(this->panelCuatro);
			this->panel2->Controls->Add(this->panelTres);
			this->panel2->Controls->Add(this->panelDos);
			this->panel2->Controls->Add(this->panelUno);
			this->panel2->Location = System::Drawing::Point(289, 61);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1095, 630);
			this->panel2->TabIndex = 12;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(934, 448);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 91);
			this->label4->TabIndex = 15;
			this->label4->Text = L"4";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(934, 328);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 91);
			this->label3->TabIndex = 14;
			this->label3->Text = L"3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(934, 202);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 91);
			this->label2->TabIndex = 13;
			this->label2->Text = L"2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(934, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 91);
			this->label1->TabIndex = 12;
			this->label1->Text = L"1";
			// 
			// btnTres
			// 
			this->btnTres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTres.BackgroundImage")));
			this->btnTres->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnTres->FlatAppearance->BorderSize = 0;
			this->btnTres->Location = System::Drawing::Point(105, 280);
			this->btnTres->Margin = System::Windows::Forms::Padding(2);
			this->btnTres->Name = L"btnTres";
			this->btnTres->Size = System::Drawing::Size(240, 113);
			this->btnTres->TabIndex = 2;
			this->btnTres->UseVisualStyleBackColor = true;
			// 
			// btnDos
			// 
			this->btnDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDos.BackgroundImage")));
			this->btnDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDos->FlatAppearance->BorderSize = 0;
			this->btnDos->Location = System::Drawing::Point(378, 202);
			this->btnDos->Margin = System::Windows::Forms::Padding(2);
			this->btnDos->Name = L"btnDos";
			this->btnDos->Size = System::Drawing::Size(240, 113);
			this->btnDos->TabIndex = 1;
			this->btnDos->UseVisualStyleBackColor = true;
			// 
			// btnUno
			// 
			this->btnUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUno.BackgroundImage")));
			this->btnUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnUno->FlatAppearance->BorderSize = 0;
			this->btnUno->Location = System::Drawing::Point(105, 77);
			this->btnUno->Margin = System::Windows::Forms::Padding(2);
			this->btnUno->Name = L"btnUno";
			this->btnUno->Size = System::Drawing::Size(240, 113);
			this->btnUno->TabIndex = 0;
			this->btnUno->UseVisualStyleBackColor = true;
			// 
			// btnCuatro
			// 
			this->btnCuatro->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCuatro.BackgroundImage")));
			this->btnCuatro->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCuatro->FlatAppearance->BorderSize = 0;
			this->btnCuatro->Location = System::Drawing::Point(378, 407);
			this->btnCuatro->Margin = System::Windows::Forms::Padding(2);
			this->btnCuatro->Name = L"btnCuatro";
			this->btnCuatro->Size = System::Drawing::Size(240, 113);
			this->btnCuatro->TabIndex = 3;
			this->btnCuatro->UseVisualStyleBackColor = true;
			// 
			// panelCuatro
			// 
			this->panelCuatro->BackColor = System::Drawing::Color::SandyBrown;
			this->panelCuatro->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelCuatro->Location = System::Drawing::Point(687, 436);
			this->panelCuatro->Margin = System::Windows::Forms::Padding(2);
			this->panelCuatro->Name = L"panelCuatro";
			this->panelCuatro->Size = System::Drawing::Size(242, 114);
			this->panelCuatro->TabIndex = 10;
			// 
			// panelTres
			// 
			this->panelTres->BackColor = System::Drawing::Color::SandyBrown;
			this->panelTres->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelTres->Location = System::Drawing::Point(687, 314);
			this->panelTres->Margin = System::Windows::Forms::Padding(2);
			this->panelTres->Name = L"panelTres";
			this->panelTres->Size = System::Drawing::Size(242, 114);
			this->panelTres->TabIndex = 9;
			// 
			// panelDos
			// 
			this->panelDos->BackColor = System::Drawing::Color::SandyBrown;
			this->panelDos->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelDos->Location = System::Drawing::Point(687, 194);
			this->panelDos->Margin = System::Windows::Forms::Padding(2);
			this->panelDos->Name = L"panelDos";
			this->panelDos->Size = System::Drawing::Size(242, 114);
			this->panelDos->TabIndex = 9;
			// 
			// panelUno
			// 
			this->panelUno->BackColor = System::Drawing::Color::SandyBrown;
			this->panelUno->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelUno->Location = System::Drawing::Point(687, 73);
			this->panelUno->Margin = System::Windows::Forms::Padding(2);
			this->panelUno->Name = L"panelUno";
			this->panelUno->Size = System::Drawing::Size(242, 114);
			this->panelUno->TabIndex = 7;
			// 
			// btnAyuda
			// 
			this->btnAyuda->BackColor = System::Drawing::Color::Transparent;
			this->btnAyuda->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAyuda.BackgroundImage")));
			this->btnAyuda->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAyuda->Location = System::Drawing::Point(8, 7);
			this->btnAyuda->Margin = System::Windows::Forms::Padding(2);
			this->btnAyuda->Name = L"btnAyuda";
			this->btnAyuda->Size = System::Drawing::Size(171, 149);
			this->btnAyuda->TabIndex = 8;
			this->btnAyuda->TabStop = false;
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
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1348, 39);
			this->panel9->TabIndex = 5;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(7, 2);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(2);
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
			this->picMinimizar->Location = System::Drawing::Point(1262, 3);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(2);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(37, 33);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(1305, 3);
			this->picCerrar->Margin = System::Windows::Forms::Padding(2);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(37, 33);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			// 
			// Act2DosDI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1348, 732);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel9);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Act2DosDI";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Act2DosDI";
			this->Activated += gcnew System::EventHandler(this, &Act2DosDI::Act2DosDI_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &Act2DosDI::Act2DosDI_Deactivate);
			this->Load += gcnew System::EventHandler(this, &Act2DosDI::Act2DosDI_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel13->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnListo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
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
	private: System::Void Act2DosDI_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act2DosDI_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Act2DosDI_Deactivate(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoBtn);
	private: vector<TiempoMI*> obtenerTiempoItems();
	private: System::Void moverBoton(System::Windows::Forms::Button^ boton);
	private: System::Void btnUno_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnDos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnTres_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnCuatro_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnUno_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnDos_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnTres_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnCuatro_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnUno_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnDos_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnTres_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btnCuatro_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	};
}
