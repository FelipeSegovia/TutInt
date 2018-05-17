#pragma once
#include "BaseDeDatos.h"
#include "AgenteControlador.h"
#include "Recuperacion.h"
#include "Mensaje.h"
#include <msclr\marshal.h>

namespace TutIntV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PrincipalDos
	/// </summary>
	public ref class PrincipalDos : public System::Windows::Forms::Form
	{
	public:
		PrincipalDos(void)
		{
			InitializeComponent();
			inicializarTamBotones();
		}

		PrincipalDos(Form^ f, BaseDeDatos^ manejador)
		{
			form = f;
			manejadorBD = manejador;
			recuperacion = new Recuperacion();
			InitializeComponent();
			inicializarTamBotones();
			inicializarComponentesBD();
			this->Size = System::Drawing::Size(1050, 598);
			this->Show();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PrincipalDos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int numAct;
	private: int salir;
	private: BaseDeDatos ^ manejadorBD;
	private: AgenteControlador * controlador;
	private: Recuperacion * recuperacion;
	private: System::Windows::Forms::Form^ form;
	private: int hBob, wBob, hCalamardo, wCalamardo, wPatricio, hPatricio, hGary, wGary, wArenita, hArenita, wPerla, hPerla, wPlankton, hPlankton, wPuff, hPuff, hCangrejo, wCangrejo, wVolver, hVolver;
	private: System::Windows::Forms::Panel^  panelPrincipal;
	private: System::Windows::Forms::PictureBox^  btnGaryD;
	private: System::Windows::Forms::PictureBox^  btnCalamardoD;
	private: System::Windows::Forms::PictureBox^  btnPatricioD;
	private: System::Windows::Forms::PictureBox^  btnArenitaD;
	private: System::Windows::Forms::PictureBox^  btnBobEsponjaD;
	private: System::Windows::Forms::Label^  lblEstrellas;
	private: System::Windows::Forms::PictureBox^  btnVolver;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  btnGary;
	private: System::Windows::Forms::PictureBox^  btnCalamardo;
	private: System::Windows::Forms::PictureBox^  btnPatricio;
	private: System::Windows::Forms::PictureBox^  btnArenita;
	private: System::Windows::Forms::PictureBox^  btnBobEsponja;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  picMinimizar;
	private: System::Windows::Forms::PictureBox^  picCerrar;
	private: System::Windows::Forms::PictureBox^  btnPlankton;
	private: System::Windows::Forms::PictureBox^  btnPlanktonD;
	private: System::Windows::Forms::PictureBox^  btnCangrejoD;
	private: System::Windows::Forms::PictureBox^  btnCangrejo;
	private: System::Windows::Forms::PictureBox^  btnPuffD;
	private: System::Windows::Forms::PictureBox^  btnPuff;
	private: System::Windows::Forms::PictureBox^  btnPerlaD;
	private: System::Windows::Forms::PictureBox^  btnPerla;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PrincipalDos::typeid));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->btnPerlaD = (gcnew System::Windows::Forms::PictureBox());
			this->btnPerla = (gcnew System::Windows::Forms::PictureBox());
			this->btnPuffD = (gcnew System::Windows::Forms::PictureBox());
			this->btnPuff = (gcnew System::Windows::Forms::PictureBox());
			this->btnCangrejoD = (gcnew System::Windows::Forms::PictureBox());
			this->btnCangrejo = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlanktonD = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlankton = (gcnew System::Windows::Forms::PictureBox());
			this->btnGaryD = (gcnew System::Windows::Forms::PictureBox());
			this->btnCalamardoD = (gcnew System::Windows::Forms::PictureBox());
			this->btnPatricioD = (gcnew System::Windows::Forms::PictureBox());
			this->btnArenitaD = (gcnew System::Windows::Forms::PictureBox());
			this->btnBobEsponjaD = (gcnew System::Windows::Forms::PictureBox());
			this->lblEstrellas = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnGary = (gcnew System::Windows::Forms::PictureBox());
			this->btnCalamardo = (gcnew System::Windows::Forms::PictureBox());
			this->btnPatricio = (gcnew System::Windows::Forms::PictureBox());
			this->btnArenita = (gcnew System::Windows::Forms::PictureBox());
			this->btnBobEsponja = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->picMinimizar = (gcnew System::Windows::Forms::PictureBox());
			this->picCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPerlaD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPerla))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPuffD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPuff))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCangrejoD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCangrejo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlanktonD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlankton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnGaryD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCalamardoD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPatricioD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnArenitaD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnBobEsponjaD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnGary))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCalamardo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPatricio))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnArenita))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnBobEsponja))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->BeginInit();
			this->SuspendLayout();
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::Transparent;
			this->panelPrincipal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panelPrincipal.BackgroundImage")));
			this->panelPrincipal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelPrincipal->Controls->Add(this->btnPerlaD);
			this->panelPrincipal->Controls->Add(this->btnPerla);
			this->panelPrincipal->Controls->Add(this->btnPuffD);
			this->panelPrincipal->Controls->Add(this->btnPuff);
			this->panelPrincipal->Controls->Add(this->btnCangrejoD);
			this->panelPrincipal->Controls->Add(this->btnCangrejo);
			this->panelPrincipal->Controls->Add(this->btnPlanktonD);
			this->panelPrincipal->Controls->Add(this->btnPlankton);
			this->panelPrincipal->Controls->Add(this->btnGaryD);
			this->panelPrincipal->Controls->Add(this->btnCalamardoD);
			this->panelPrincipal->Controls->Add(this->btnPatricioD);
			this->panelPrincipal->Controls->Add(this->btnArenitaD);
			this->panelPrincipal->Controls->Add(this->btnBobEsponjaD);
			this->panelPrincipal->Controls->Add(this->lblEstrellas);
			this->panelPrincipal->Controls->Add(this->btnVolver);
			this->panelPrincipal->Controls->Add(this->pictureBox1);
			this->panelPrincipal->Controls->Add(this->btnGary);
			this->panelPrincipal->Controls->Add(this->btnCalamardo);
			this->panelPrincipal->Controls->Add(this->btnPatricio);
			this->panelPrincipal->Controls->Add(this->btnArenita);
			this->panelPrincipal->Controls->Add(this->btnBobEsponja);
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 39);
			this->panelPrincipal->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(1313, 704);
			this->panelPrincipal->TabIndex = 0;
			// 
			// btnPerlaD
			// 
			this->btnPerlaD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPerlaD.BackgroundImage")));
			this->btnPerlaD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPerlaD->Enabled = false;
			this->btnPerlaD->Location = System::Drawing::Point(102, 392);
			this->btnPerlaD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPerlaD->Name = L"btnPerlaD";
			this->btnPerlaD->Size = System::Drawing::Size(235, 188);
			this->btnPerlaD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPerlaD->TabIndex = 29;
			this->btnPerlaD->TabStop = false;
			this->btnPerlaD->Visible = false;
			this->btnPerlaD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnPerlaD_Click);
			this->btnPerlaD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnPerlaD_MouseLeave);
			this->btnPerlaD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnPerlaD_MouseHover);
			// 
			// btnPerla
			// 
			this->btnPerla->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPerla.BackgroundImage")));
			this->btnPerla->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPerla->Location = System::Drawing::Point(102, 392);
			this->btnPerla->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPerla->Name = L"btnPerla";
			this->btnPerla->Size = System::Drawing::Size(235, 188);
			this->btnPerla->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPerla->TabIndex = 28;
			this->btnPerla->TabStop = false;
			// 
			// btnPuffD
			// 
			this->btnPuffD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPuffD.BackgroundImage")));
			this->btnPuffD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPuffD->Enabled = false;
			this->btnPuffD->Location = System::Drawing::Point(636, 352);
			this->btnPuffD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPuffD->Name = L"btnPuffD";
			this->btnPuffD->Size = System::Drawing::Size(219, 233);
			this->btnPuffD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPuffD->TabIndex = 27;
			this->btnPuffD->TabStop = false;
			this->btnPuffD->Visible = false;
			this->btnPuffD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnPuffD_Click);
			this->btnPuffD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnPuffD_MouseLeave);
			this->btnPuffD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnPuffD_MouseHover);
			// 
			// btnPuff
			// 
			this->btnPuff->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPuff.BackgroundImage")));
			this->btnPuff->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPuff->Location = System::Drawing::Point(636, 352);
			this->btnPuff->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPuff->Name = L"btnPuff";
			this->btnPuff->Size = System::Drawing::Size(219, 233);
			this->btnPuff->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPuff->TabIndex = 26;
			this->btnPuff->TabStop = false;
			// 
			// btnCangrejoD
			// 
			this->btnCangrejoD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCangrejoD.BackgroundImage")));
			this->btnCangrejoD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCangrejoD->Enabled = false;
			this->btnCangrejoD->Location = System::Drawing::Point(401, 375);
			this->btnCangrejoD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCangrejoD->Name = L"btnCangrejoD";
			this->btnCangrejoD->Size = System::Drawing::Size(207, 210);
			this->btnCangrejoD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnCangrejoD->TabIndex = 25;
			this->btnCangrejoD->TabStop = false;
			this->btnCangrejoD->Visible = false;
			this->btnCangrejoD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnCangrejoD_Click);
			this->btnCangrejoD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnCangrejoD_MouseLeave);
			this->btnCangrejoD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnCangrejoD_MouseHover);
			// 
			// btnCangrejo
			// 
			this->btnCangrejo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCangrejo.BackgroundImage")));
			this->btnCangrejo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCangrejo->Location = System::Drawing::Point(401, 375);
			this->btnCangrejo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCangrejo->Name = L"btnCangrejo";
			this->btnCangrejo->Size = System::Drawing::Size(207, 210);
			this->btnCangrejo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnCangrejo->TabIndex = 24;
			this->btnCangrejo->TabStop = false;
			// 
			// btnPlanktonD
			// 
			this->btnPlanktonD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPlanktonD.BackgroundImage")));
			this->btnPlanktonD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPlanktonD->Enabled = false;
			this->btnPlanktonD->Location = System::Drawing::Point(1114, 157);
			this->btnPlanktonD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPlanktonD->Name = L"btnPlanktonD";
			this->btnPlanktonD->Size = System::Drawing::Size(136, 133);
			this->btnPlanktonD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPlanktonD->TabIndex = 23;
			this->btnPlanktonD->TabStop = false;
			this->btnPlanktonD->Visible = false;
			this->btnPlanktonD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnPlanktonD_Click);
			this->btnPlanktonD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnPlanktonD_MouseLeave);
			this->btnPlanktonD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnPlanktonD_MouseHover);
			// 
			// btnPlankton
			// 
			this->btnPlankton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPlankton.BackgroundImage")));
			this->btnPlankton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPlankton->Location = System::Drawing::Point(1114, 157);
			this->btnPlankton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPlankton->Name = L"btnPlankton";
			this->btnPlankton->Size = System::Drawing::Size(136, 133);
			this->btnPlankton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPlankton->TabIndex = 22;
			this->btnPlankton->TabStop = false;
			// 
			// btnGaryD
			// 
			this->btnGaryD->BackColor = System::Drawing::Color::Transparent;
			this->btnGaryD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGaryD.BackgroundImage")));
			this->btnGaryD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnGaryD->Enabled = false;
			this->btnGaryD->Location = System::Drawing::Point(890, 497);
			this->btnGaryD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnGaryD->Name = L"btnGaryD";
			this->btnGaryD->Size = System::Drawing::Size(157, 174);
			this->btnGaryD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnGaryD->TabIndex = 21;
			this->btnGaryD->TabStop = false;
			this->btnGaryD->Visible = false;
			this->btnGaryD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnGaryD_Click);
			this->btnGaryD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnGaryD_MouseLeave);
			this->btnGaryD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnGaryD_MouseHover);
			// 
			// btnCalamardoD
			// 
			this->btnCalamardoD->BackColor = System::Drawing::Color::Transparent;
			this->btnCalamardoD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCalamardoD.BackgroundImage")));
			this->btnCalamardoD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCalamardoD->Enabled = false;
			this->btnCalamardoD->Location = System::Drawing::Point(865, 143);
			this->btnCalamardoD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCalamardoD->Name = L"btnCalamardoD";
			this->btnCalamardoD->Size = System::Drawing::Size(164, 205);
			this->btnCalamardoD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnCalamardoD->TabIndex = 20;
			this->btnCalamardoD->TabStop = false;
			this->btnCalamardoD->Visible = false;
			this->btnCalamardoD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnCalamardoD_Click);
			this->btnCalamardoD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnCalamardoD_MouseLeave);
			this->btnCalamardoD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnCalamardoD_MouseHover);
			// 
			// btnPatricioD
			// 
			this->btnPatricioD->BackColor = System::Drawing::Color::Transparent;
			this->btnPatricioD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPatricioD.BackgroundImage")));
			this->btnPatricioD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPatricioD->Enabled = false;
			this->btnPatricioD->Location = System::Drawing::Point(1097, 422);
			this->btnPatricioD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPatricioD->Name = L"btnPatricioD";
			this->btnPatricioD->Size = System::Drawing::Size(194, 243);
			this->btnPatricioD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPatricioD->TabIndex = 19;
			this->btnPatricioD->TabStop = false;
			this->btnPatricioD->Visible = false;
			this->btnPatricioD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnPatricioD_Click);
			this->btnPatricioD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnPatricioD_MouseLeave);
			this->btnPatricioD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnPatricioD_MouseHover);
			// 
			// btnArenitaD
			// 
			this->btnArenitaD->BackColor = System::Drawing::Color::Transparent;
			this->btnArenitaD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnArenitaD.BackgroundImage")));
			this->btnArenitaD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnArenitaD->Enabled = false;
			this->btnArenitaD->Location = System::Drawing::Point(367, 98);
			this->btnArenitaD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnArenitaD->Name = L"btnArenitaD";
			this->btnArenitaD->Size = System::Drawing::Size(197, 191);
			this->btnArenitaD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnArenitaD->TabIndex = 18;
			this->btnArenitaD->TabStop = false;
			this->btnArenitaD->Visible = false;
			this->btnArenitaD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnArenitaD_Click);
			this->btnArenitaD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnArenitaD_MouseLeave);
			this->btnArenitaD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnArenitaD_MouseHover);
			// 
			// btnBobEsponjaD
			// 
			this->btnBobEsponjaD->BackColor = System::Drawing::Color::Transparent;
			this->btnBobEsponjaD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnBobEsponjaD.BackgroundImage")));
			this->btnBobEsponjaD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnBobEsponjaD->Enabled = false;
			this->btnBobEsponjaD->Location = System::Drawing::Point(82, 170);
			this->btnBobEsponjaD->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnBobEsponjaD->Name = L"btnBobEsponjaD";
			this->btnBobEsponjaD->Size = System::Drawing::Size(241, 199);
			this->btnBobEsponjaD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnBobEsponjaD->TabIndex = 17;
			this->btnBobEsponjaD->TabStop = false;
			this->btnBobEsponjaD->Visible = false;
			this->btnBobEsponjaD->Click += gcnew System::EventHandler(this, &PrincipalDos::btnBobEsponjaD_Click);
			this->btnBobEsponjaD->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnBobEsponjaD_MouseLeave);
			this->btnBobEsponjaD->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnBobEsponjaD_MouseHover);
			// 
			// lblEstrellas
			// 
			this->lblEstrellas->AutoSize = true;
			this->lblEstrellas->BackColor = System::Drawing::Color::Transparent;
			this->lblEstrellas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstrellas->ForeColor = System::Drawing::Color::Black;
			this->lblEstrellas->Location = System::Drawing::Point(1200, 32);
			this->lblEstrellas->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEstrellas->Name = L"lblEstrellas";
			this->lblEstrellas->Size = System::Drawing::Size(50, 54);
			this->lblEstrellas->TabIndex = 15;
			this->lblEstrellas->Text = L"0";
			// 
			// btnVolver
			// 
			this->btnVolver->BackColor = System::Drawing::Color::Transparent;
			this->btnVolver->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnVolver.BackgroundImage")));
			this->btnVolver->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnVolver->Location = System::Drawing::Point(17, 19);
			this->btnVolver->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(108, 81);
			this->btnVolver->TabIndex = 16;
			this->btnVolver->TabStop = false;
			this->btnVolver->Click += gcnew System::EventHandler(this, &PrincipalDos::btnVolver_Click);
			this->btnVolver->MouseLeave += gcnew System::EventHandler(this, &PrincipalDos::btnVolver_MouseLeave);
			this->btnVolver->MouseHover += gcnew System::EventHandler(this, &PrincipalDos::btnVolver_MouseHover);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(1257, 12);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(105, 94);
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// btnGary
			// 
			this->btnGary->BackColor = System::Drawing::Color::Transparent;
			this->btnGary->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGary.BackgroundImage")));
			this->btnGary->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnGary->Location = System::Drawing::Point(890, 497);
			this->btnGary->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnGary->Name = L"btnGary";
			this->btnGary->Size = System::Drawing::Size(157, 174);
			this->btnGary->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnGary->TabIndex = 4;
			this->btnGary->TabStop = false;
			// 
			// btnCalamardo
			// 
			this->btnCalamardo->BackColor = System::Drawing::Color::Transparent;
			this->btnCalamardo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCalamardo.BackgroundImage")));
			this->btnCalamardo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCalamardo->Location = System::Drawing::Point(865, 143);
			this->btnCalamardo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCalamardo->Name = L"btnCalamardo";
			this->btnCalamardo->Size = System::Drawing::Size(164, 205);
			this->btnCalamardo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnCalamardo->TabIndex = 3;
			this->btnCalamardo->TabStop = false;
			// 
			// btnPatricio
			// 
			this->btnPatricio->BackColor = System::Drawing::Color::Transparent;
			this->btnPatricio->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPatricio.BackgroundImage")));
			this->btnPatricio->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPatricio->Location = System::Drawing::Point(1097, 422);
			this->btnPatricio->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnPatricio->Name = L"btnPatricio";
			this->btnPatricio->Size = System::Drawing::Size(194, 243);
			this->btnPatricio->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnPatricio->TabIndex = 2;
			this->btnPatricio->TabStop = false;
			// 
			// btnArenita
			// 
			this->btnArenita->BackColor = System::Drawing::Color::Transparent;
			this->btnArenita->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnArenita.BackgroundImage")));
			this->btnArenita->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnArenita->Location = System::Drawing::Point(367, 98);
			this->btnArenita->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnArenita->Name = L"btnArenita";
			this->btnArenita->Size = System::Drawing::Size(197, 191);
			this->btnArenita->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnArenita->TabIndex = 1;
			this->btnArenita->TabStop = false;
			// 
			// btnBobEsponja
			// 
			this->btnBobEsponja->BackColor = System::Drawing::Color::Transparent;
			this->btnBobEsponja->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnBobEsponja.BackgroundImage")));
			this->btnBobEsponja->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnBobEsponja->Location = System::Drawing::Point(82, 170);
			this->btnBobEsponja->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnBobEsponja->Name = L"btnBobEsponja";
			this->btnBobEsponja->Size = System::Drawing::Size(241, 199);
			this->btnBobEsponja->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnBobEsponja->TabIndex = 0;
			this->btnBobEsponja->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->picMinimizar);
			this->panel1->Controls->Add(this->picCerrar);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1313, 39);
			this->panel1->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(7, 2);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(41, 35);
			this->pictureBox2->TabIndex = 33;
			this->pictureBox2->TabStop = false;
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
			this->picMinimizar->Location = System::Drawing::Point(1228, 3);
			this->picMinimizar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picMinimizar->Name = L"picMinimizar";
			this->picMinimizar->Size = System::Drawing::Size(37, 33);
			this->picMinimizar->TabIndex = 31;
			this->picMinimizar->TabStop = false;
			this->picMinimizar->Click += gcnew System::EventHandler(this, &PrincipalDos::picMinimizar_Click);
			// 
			// picCerrar
			// 
			this->picCerrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->picCerrar->BackColor = System::Drawing::Color::Transparent;
			this->picCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picCerrar.BackgroundImage")));
			this->picCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picCerrar->Location = System::Drawing::Point(1271, 3);
			this->picCerrar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picCerrar->Name = L"picCerrar";
			this->picCerrar->Size = System::Drawing::Size(37, 33);
			this->picCerrar->TabIndex = 30;
			this->picCerrar->TabStop = false;
			this->picCerrar->Click += gcnew System::EventHandler(this, &PrincipalDos::picCerrar_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &PrincipalDos::timer1_Tick);
			// 
			// PrincipalDos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1313, 743);
			this->Controls->Add(this->panelPrincipal);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"PrincipalDos";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PrincipalDos";
			this->Activated += gcnew System::EventHandler(this, &PrincipalDos::PrincipalDos_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &PrincipalDos::PrincipalDos_Deactivate);
			this->Load += gcnew System::EventHandler(this, &PrincipalDos::PrincipalDos_Load);
			this->panelPrincipal->ResumeLayout(false);
			this->panelPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPerlaD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPerla))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPuffD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPuff))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCangrejoD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCangrejo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlanktonD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPlankton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnGaryD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCalamardoD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPatricioD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnArenitaD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnBobEsponjaD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnVolver))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnGary))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnCalamardo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnPatricio))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnArenita))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnBobEsponja))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picMinimizar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCerrar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void inicializarTamBotones();
	private: void inicializarComponentesBD();
	private: void cargarActBB();
	private: void cargarActBI();
	private: void cargarActBD();
	private: void cargarActIB();
	private: void cargarActII();
	private: void cargarActID();
	private: void cargarActDB();
	private: void cargarActDI();
	private: void cargarActDD();
	private: System::Void btnPerlaD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPerlaD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPlanktonD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPlanktonD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCangrejoD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCangrejoD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPuffD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPuffD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnBobEsponjaD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnBobEsponjaD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCalamardoD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCalamardoD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPatricioD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPatricioD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnGaryD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnGaryD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnArenitaD_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnArenitaD_MouseLeave(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e);

	private: System::Void btnPuffD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCangrejoD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPlanktonD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPerlaD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnBobEsponjaD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnPatricioD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnGaryD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnArenitaD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCalamardoD_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnVolver_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: void SonidoBob();
	private: void SonidoCalamardo();
	private: void SonidoPatricio();
	private: void SonidoArenita();
	private: void SonidoGary();
	private: void SonidoPuff();
	private: void SonidoCangrejo();
	private: void SonidoPlankton();
	private: void SonidoPerla();
	private: void SonidoBobGary();
	private: System::Void PrincipalDos_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picCerrar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void picMinimizar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalDos_Activated(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PrincipalDos_Deactivate(System::Object^  sender, System::EventArgs^  e);
	};
}
