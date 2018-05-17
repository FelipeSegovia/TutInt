#include "NivelUno.h"
#include "PrincipalUno.h"
#include "PrincipalDos.h"
#include "Niveles.h"
#include <list>
#include <string>

System::Void TutIntV30::NivelUno::inicializarTam() {
	wUno = this->picHab1->Size.Width;
	hUno = this->picHab1->Size.Height;
	wDos = this->picHab2->Size.Width;
	hDos = this->picHab2->Size.Height;
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
}
//Se muestran las tematicas que puede acceder el usuario
System::Void TutIntV30::NivelUno::inicializarComponentesBD() {
	manejadorBD->setNombreNivel("Playa");
	int totalEstr = manejadorBD->seleccionarCantEstrellasNivel();
	std::vector<std::string> lista = manejadorBD->seleccionarHabilidadesDisponibles();
	// Se carga los componentes del nivel uno
	for (unsigned int x = 0; x < lista.size(); x++)
	{
		if (lista[x] == "Conciencia_fonologica")
		{
			this->picHab1->Visible = true;
		}
		if (lista[x] == "Conciencia_alfabetica")
		{
			this->picHab1->Visible = true;
			this->picHab2->Visible = true;
			this->picHab2E->Visible = false;
		}
	}
	this->lblEstrellas->Text = System::Convert::ToString(totalEstr);
}
System::Void TutIntV30::NivelUno::picHab1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picHab1->Size = System::Drawing::Size(wUno + 10, hUno + 10);
}
System::Void TutIntV30::NivelUno::picHab1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picHab1->Size = System::Drawing::Size(wUno, hUno);
}
System::Void TutIntV30::NivelUno::picHab2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picHab2->Size = System::Drawing::Size(wDos + 10, hDos + 10);
}
System::Void TutIntV30::NivelUno::picHab2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picHab2->Size = System::Drawing::Size(wDos, hDos);
}
System::Void TutIntV30::NivelUno::picHab1_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew PrincipalUno(this, manejadorBD);
}
System::Void TutIntV30::NivelUno::picHab2_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew PrincipalDos(this, manejadorBD);
}
System::Void TutIntV30::NivelUno::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew Niveles(this, manejadorBD);
}
System::Void TutIntV30::NivelUno::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void TutIntV30::NivelUno::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::NivelUno::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
	}
}
System::Void TutIntV30::NivelUno::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void TutIntV30::NivelUno::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::NivelUno::NivelUno_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::NivelUno::NivelUno_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::NivelUno::NivelUno_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}