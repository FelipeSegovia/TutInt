#pragma once
#include "BaseDeDatos.h"

namespace TutIntV30 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Mensaje
	/// </summary>
	public ref class Mensaje : public System::Windows::Forms::Form
	{
	public:
		Mensaje(void)
		{
			InitializeComponent();
		}
		Mensaje(int hab, System::Windows::Forms::Form^ _form, BaseDeDatos^ bd)
		{
			habilidad = hab;
			form = _form;
			manejadorBD = bd;
			InitializeComponent();
			inicializar();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Mensaje()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int habilidad;
	private: BaseDeDatos ^ manejadorBD;
	private: System::Windows::Forms::Form^ form;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panelDos;
	private: System::Windows::Forms::PictureBox^  pictureDos;
	private: System::Windows::Forms::PictureBox^  pictureUno;
	private: System::Windows::Forms::Button^  button1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Mensaje::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelDos = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureDos = (gcnew System::Windows::Forms::PictureBox());
			this->pictureUno = (gcnew System::Windows::Forms::PictureBox());
			this->panelDos->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureDos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureUno))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Mensaje::timer1_Tick);
			// 
			// panelDos
			// 
			this->panelDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panelDos->Controls->Add(this->button1);
			this->panelDos->Controls->Add(this->pictureDos);
			this->panelDos->Controls->Add(this->pictureUno);
			this->panelDos->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelDos->Location = System::Drawing::Point(0, 0);
			this->panelDos->Name = L"panelDos";
			this->panelDos->Size = System::Drawing::Size(1361, 909);
			this->panelDos->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Peru;
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(529, 648);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(342, 77);
			this->button1->TabIndex = 2;
			this->button1->Text = L"CONTINUAR";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Mensaje::btnUno_Click);
			// 
			// pictureDos
			// 
			this->pictureDos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureDos.BackgroundImage")));
			this->pictureDos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureDos->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureDos->Location = System::Drawing::Point(0, 0);
			this->pictureDos->Name = L"pictureDos";
			this->pictureDos->Size = System::Drawing::Size(1361, 909);
			this->pictureDos->TabIndex = 1;
			this->pictureDos->TabStop = false;
			// 
			// pictureUno
			// 
			this->pictureUno->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureUno.BackgroundImage")));
			this->pictureUno->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureUno->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureUno->Location = System::Drawing::Point(0, 0);
			this->pictureUno->Name = L"pictureUno";
			this->pictureUno->Size = System::Drawing::Size(1361, 909);
			this->pictureUno->TabIndex = 0;
			this->pictureUno->TabStop = false;
			// 
			// Mensaje
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1361, 909);
			this->Controls->Add(this->panelDos);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Mensaje";
			this->Opacity = 0;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mensaje";
			this->Load += gcnew System::EventHandler(this, &Mensaje::Mensaje_Load);
			this->panelDos->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureDos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureUno))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void SonidoUno();
	private: void SonidoDos();
	private: void SonidoTres();
	private: void SonidoCuatro();
	private: void SonidoCinco();
	private: void iniciarPic();
	private: void inicializar();
	private: System::Void btnUno_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void Mensaje_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	};
}
