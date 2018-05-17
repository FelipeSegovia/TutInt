#include "NivelDos.h"
#include "PrincipalTres.h"
#include "PrincipalCuatro.h"
#include "Niveles.h"
#include <list>
#include <string>

System::Void TutIntV30::NivelDos::inicializarTam() {
	wTres = this->picHab3->Size.Width;
	hTres = this->picHab3->Size.Height;
	wCuatro = this->picHab4->Size.Width;
	hCuatro = this->picHab4->Size.Height;
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
}
System::Void TutIntV30::NivelDos::inicializarComponentesBD() {
	manejadorBD->setNombreNivel("Parque");
	int totalEstr = manejadorBD->seleccionarCantEstrellasNivel();
	std::vector<std::string> lista = manejadorBD->seleccionarHabilidadesDisponibles();
	// Se carga los componentes del nivel dos
	for (unsigned int x = 0; x < lista.size();x++)
	{
		if (lista[x] == "Vocabulario") {
			this->picHab3->Visible = true;
		}
		else if (lista[x] == "Comprension_literal") {
			this->picHab3->Visible = true;
			this->picHab4->Visible = true;
			this->picHab4E->Visible = false;
		}
	}
	this->lblEstrellas->Text = System::Convert::ToString(totalEstr);
}
System::Void TutIntV30::NivelDos::picHab3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picHab3->Size = System::Drawing::Size(wTres + 10, hTres + 10);
}
System::Void TutIntV30::NivelDos::picHab3_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picHab3->Size = System::Drawing::Size(wTres, hTres);
}
System::Void TutIntV30::NivelDos::picHab4_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picHab4->Size = System::Drawing::Size(wCuatro + 10, hCuatro + 10);
}
System::Void TutIntV30::NivelDos::picHab4_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picHab4->Size = System::Drawing::Size(wCuatro, hCuatro);
}
System::Void TutIntV30::NivelDos::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//gcnew Niveles(this, manejadorBD);
}
System::Void TutIntV30::NivelDos::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void TutIntV30::NivelDos::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::NivelDos::picHab3_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew PrincipalTres(this, manejadorBD);
}
System::Void TutIntV30::NivelDos::picHab4_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew PrincipalCuatro(this, manejadorBD);
}
System::Void TutIntV30::NivelDos::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
	}
}
System::Void TutIntV30::NivelDos::NivelDos_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::NivelDos::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void TutIntV30::NivelDos::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::NivelDos::NivelDos_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::NivelDos::NivelDos_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}