#pragma once
#include "BaseDeDatos.h"
#include "AgenteControlador.h"
#include <msclr\marshal_cppstd.h>

namespace TutIntV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormEstrella
	/// </summary>
	public ref class FormEstrella : public System::Windows::Forms::Form
	{
	public:
		FormEstrella(void)
		{
			InitializeComponent();
		}

		FormEstrella(AgenteControlador *control, BaseDeDatos^ manejador, String^ hab, Form^ formAct, int cantEstrellas) {
			controlador = control;
			numEstrellas = cantEstrellas;
			manejadorBD = manejador;
			habilidad = hab;
			formActividad = formAct;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormEstrella()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int numEstrellas;
	private: AgenteControlador * controlador;
	private: BaseDeDatos ^ manejadorBD;
	private: System::String^ habilidad;
	private: System::Windows::Forms::Form^ formActividad;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  estrellaUnoE;
	private: System::Windows::Forms::PictureBox^  estrellaDosE;
	private: System::Windows::Forms::PictureBox^  estrellaTresE;
	private: System::Windows::Forms::PictureBox^  estrellaTres;
	private: System::Windows::Forms::PictureBox^  estrellaDos;
	private: System::Windows::Forms::PictureBox^  estrellaUno;
	private: System::Windows::Forms::PictureBox^  mensaje1;
	private: System::Windows::Forms::PictureBox^  mensaje2;
	private: System::Windows::Forms::PictureBox^  mensaje3;
	private: System::Windows::Forms::Timer^  timer1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormEstrella::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->estrellaUnoE = (gcnew System::Windows::Forms::PictureBox());
			this->estrellaDosE = (gcnew System::Windows::Forms::PictureBox());
			this->estrellaTresE = (gcnew System::Windows::Forms::PictureBox());
			this->estrellaTres = (gcnew System::Windows::Forms::PictureBox());
			this->estrellaDos = (gcnew System::Windows::Forms::PictureBox());
			this->estrellaUno = (gcnew System::Windows::Forms::PictureBox());
			this->mensaje1 = (gcnew System::Windows::Forms::PictureBox());
			this->mensaje2 = (gcnew System::Windows::Forms::PictureBox());
			this->mensaje3 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaUnoE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaDosE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaTresE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaTres))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaDos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaUno))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mensaje1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mensaje2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mensaje3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::OliveDrab;
			this->button1->Font = (gcnew System::Drawing::Font(L"Candara", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(221, 295);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 45);
			this->button1->TabIndex = 0;
			this->button1->Text = L"CONTINUAR";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormEstrella::button1_Click);
			// 
			// estrellaUnoE
			// 
			this->estrellaUnoE->BackColor = System::Drawing::Color::Transparent;
			this->estrellaUnoE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"estrellaUnoE.BackgroundImage")));
			this->estrellaUnoE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->estrellaUnoE->Location = System::Drawing::Point(59, 32);
			this->estrellaUnoE->Margin = System::Windows::Forms::Padding(2);
			this->estrellaUnoE->Name = L"estrellaUnoE";
			this->estrellaUnoE->Size = System::Drawing::Size(131, 136);
			this->estrellaUnoE->TabIndex = 3;
			this->estrellaUnoE->TabStop = false;
			this->estrellaUnoE->Visible = false;
			// 
			// estrellaDosE
			// 
			this->estrellaDosE->BackColor = System::Drawing::Color::Transparent;
			this->estrellaDosE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"estrellaDosE.BackgroundImage")));
			this->estrellaDosE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->estrellaDosE->Location = System::Drawing::Point(224, 4);
			this->estrellaDosE->Margin = System::Windows::Forms::Padding(2);
			this->estrellaDosE->Name = L"estrellaDosE";
			this->estrellaDosE->Size = System::Drawing::Size(131, 136);
			this->estrellaDosE->TabIndex = 4;
			this->estrellaDosE->TabStop = false;
			this->estrellaDosE->Visible = false;
			// 
			// estrellaTresE
			// 
			this->estrellaTresE->BackColor = System::Drawing::Color::Transparent;
			this->estrellaTresE->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"estrellaTresE.BackgroundImage")));
			this->estrellaTresE->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->estrellaTresE->Location = System::Drawing::Point(385, 32);
			this->estrellaTresE->Margin = System::Windows::Forms::Padding(2);
			this->estrellaTresE->Name = L"estrellaTresE";
			this->estrellaTresE->Size = System::Drawing::Size(131, 136);
			this->estrellaTresE->TabIndex = 5;
			this->estrellaTresE->TabStop = false;
			this->estrellaTresE->Visible = false;
			// 
			// estrellaTres
			// 
			this->estrellaTres->BackColor = System::Drawing::Color::Transparent;
			this->estrellaTres->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"estrellaTres.BackgroundImage")));
			this->estrellaTres->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->estrellaTres->Location = System::Drawing::Point(385, 32);
			this->estrellaTres->Margin = System::Windows::Forms::Padding(2);
			this->estrellaTres->Name = L"estrellaTres";
			this->estrellaTres->Size = System::Drawing::Size(131, 136);
			this->estrellaTres->TabIndex = 8;
			this->estrellaTres->TabStop = false;
			// 
			// estrellaDos
			// 
			this->estrellaDos->BackColor = System::Drawing::Color::Transparent;
			this->estrellaDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"estrellaDos.BackgroundImage")));
			this->estrellaDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->estrellaDos->Location = System::Drawing::Point(224, 4);
			this->estrellaDos->Margin = System::Windows::Forms::Padding(2);
			this->estrellaDos->Name = L"estrellaDos";
			this->estrellaDos->Size = System::Drawing::Size(131, 136);
			this->estrellaDos->TabIndex = 7;
			this->estrellaDos->TabStop = false;
			// 
			// estrellaUno
			// 
			this->estrellaUno->BackColor = System::Drawing::Color::Transparent;
			this->estrellaUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"estrellaUno.BackgroundImage")));
			this->estrellaUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->estrellaUno->Location = System::Drawing::Point(59, 31);
			this->estrellaUno->Margin = System::Windows::Forms::Padding(2);
			this->estrellaUno->Name = L"estrellaUno";
			this->estrellaUno->Size = System::Drawing::Size(131, 136);
			this->estrellaUno->TabIndex = 6;
			this->estrellaUno->TabStop = false;
			// 
			// mensaje1
			// 
			this->mensaje1->BackColor = System::Drawing::Color::Transparent;
			this->mensaje1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mensaje1.BackgroundImage")));
			this->mensaje1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->mensaje1->Location = System::Drawing::Point(142, 171);
			this->mensaje1->Margin = System::Windows::Forms::Padding(2);
			this->mensaje1->Name = L"mensaje1";
			this->mensaje1->Size = System::Drawing::Size(295, 110);
			this->mensaje1->TabIndex = 9;
			this->mensaje1->TabStop = false;
			// 
			// mensaje2
			// 
			this->mensaje2->BackColor = System::Drawing::Color::Transparent;
			this->mensaje2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mensaje2.BackgroundImage")));
			this->mensaje2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->mensaje2->Location = System::Drawing::Point(95, 172);
			this->mensaje2->Margin = System::Windows::Forms::Padding(2);
			this->mensaje2->Name = L"mensaje2";
			this->mensaje2->Size = System::Drawing::Size(402, 110);
			this->mensaje2->TabIndex = 10;
			this->mensaje2->TabStop = false;
			this->mensaje2->Visible = false;
			// 
			// mensaje3
			// 
			this->mensaje3->BackColor = System::Drawing::Color::Transparent;
			this->mensaje3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mensaje3.BackgroundImage")));
			this->mensaje3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->mensaje3->Location = System::Drawing::Point(120, 198);
			this->mensaje3->Margin = System::Windows::Forms::Padding(2);
			this->mensaje3->Name = L"mensaje3";
			this->mensaje3->Size = System::Drawing::Size(350, 58);
			this->mensaje3->TabIndex = 11;
			this->mensaje3->TabStop = false;
			this->mensaje3->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormEstrella::timer1_Tick);
			// 
			// FormEstrella
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCyan;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(577, 352);
			this->Controls->Add(this->mensaje3);
			this->Controls->Add(this->mensaje2);
			this->Controls->Add(this->mensaje1);
			this->Controls->Add(this->estrellaTres);
			this->Controls->Add(this->estrellaDos);
			this->Controls->Add(this->estrellaUno);
			this->Controls->Add(this->estrellaTresE);
			this->Controls->Add(this->estrellaDosE);
			this->Controls->Add(this->estrellaUnoE);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"FormEstrella";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormEstrella";
			this->Load += gcnew System::EventHandler(this, &FormEstrella::FormEstrella_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaUnoE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaDosE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaTresE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaTres))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaDos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->estrellaUno))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mensaje1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mensaje2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mensaje3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void determinarFormHabilidad();
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FormEstrella_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	};
}

