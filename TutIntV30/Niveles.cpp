#include "Niveles.h"
#include "NivelUno.h"
#include "NivelDos.h"
#include "PrincipalCinco.h"
#include "Advertencia.h"
#include <list>
#include <string>

System::Void TutIntV30::Niveles::inicializarTam() {
	wUno = this->picNivelUno->Size.Width;
	hUno = this->picNivelUno->Size.Height;
	wDos = this->picNivel2->Size.Width;
	hDos = this->picNivel2->Size.Height;
	wTres = this->picNivel3->Size.Width;
	hTres = this->picNivel3->Size.Height;
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
}
//Muestra los niveles en los que se encuentra desbloqueados para el usuario
System::Void TutIntV30::Niveles::inicializarComponentesBD() {
	std::list<std::string> lista = manejadorBD->seleccionarNivelesDisponibles();
	int totalEstr = manejadorBD->seleccionarTotalEstrellas();
	// Actualizar los botones segun la lista
	std::list<std::string>::iterator i;
	for (i = lista.begin(); i != lista.end(); i++) {
		if (*i == "Playa") {
			this->picNivelUno->Visible = true;
		}
		else if (*i == "Parque") {
			this->picNivel2->Visible = true;
			this->picNivel2E->Visible = false;
		}
		else if (*i == "Espacio") {
			this->picNivel3->Visible = true;
			this->picNivel3E->Visible = false;
		}
	}
	this->lblEstrellas->Text = System::Convert::ToString(totalEstr);
}
System::Void TutIntV30::Niveles::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		if (form != nullptr) {
			this->form->Close();
		}
	}
}
System::Void TutIntV30::Niveles::Niveles_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Niveles::picNivelUno_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picNivelUno->Size = System::Drawing::Size(wUno + 10, hUno + 10);
}
System::Void TutIntV30::Niveles::picNivelUno_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picNivelUno->Size = System::Drawing::Size(wUno, hUno);
}
System::Void TutIntV30::Niveles::picNivel2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picNivel2->Size = System::Drawing::Size(wDos + 10, hDos + 10);
}
System::Void TutIntV30::Niveles::picNivel2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picNivel2->Size = System::Drawing::Size(wDos, hDos);
}
System::Void TutIntV30::Niveles::picNivel3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->picNivel3->Size = System::Drawing::Size(wTres + 10, hTres + 10);
}
System::Void TutIntV30::Niveles::picNivel3_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->picNivel3->Size = System::Drawing::Size(wTres, hTres);
}
System::Void TutIntV30::Niveles::picNivelUno_Click(System::Object^  sender, System::EventArgs^  e) {
	NivelUno^ ventana = gcnew NivelUno(this, manejadorBD);
}
System::Void TutIntV30::Niveles::picNivel2_Click(System::Object^  sender, System::EventArgs^  e) {
	NivelDos^ ventana = gcnew NivelDos(this, manejadorBD);
}
System::Void TutIntV30::Niveles::picNivel3_Click(System::Object^  sender, System::EventArgs^  e) {
	PrincipalCinco^ ventana = gcnew PrincipalCinco(this, manejadorBD);
}
System::Void TutIntV30::Niveles::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	// Mostrar mensaje: Si esta seguro que desea salir de su partida
	bool salirNivel = true;
	Advertencia^ ventana = gcnew Advertencia(this, salirNivel, manejadorBD);
	ventana->ShowDialog();
}
System::Void TutIntV30::Niveles::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void TutIntV30::Niveles::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Niveles::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void TutIntV30::Niveles::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Niveles::Niveles_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Niveles::Niveles_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}