#include "Advertencia.h"
#include "Login.h"
//#include "PrincipalUno.h"
//#include "PrincipalDos.h"
//#include "PrincipalTres.h"
//#include "PrincipalCuatro.h"
//#include "PrincipalCinco.h"

System::Void TutIntV30::Advertencia::inicializarTam() {
	wSi = this->btnSi->Size.Width;
	hSi = this->btnSi->Size.Height;
	wNo = this->btnNo->Size.Width;
	hNo = this->btnNo->Size.Height;
}
System::Void TutIntV30::Advertencia::inicializarLabel() {
	if (!salir) {
		this->picSalirAct->Visible = true;
		this->picSalirPartida->Visible = false;
	}
	else {
		this->picSalirAct->Visible = false;
		this->picSalirPartida->Visible = true;
	}
}
System::Void TutIntV30::Advertencia::btnSi_Click(System::Object^  sender, System::EventArgs^  e) {
	if (salir) {
		this->Close();
		gcnew Login(formAbierto);
	}
	else {
		if (nombreForm == "etapaUno") {
			this->Close();
			//gcnew PrincipalUno(formAbierto, manejadorBD);
		}
		else if (nombreForm == "etapaDos") {
			this->Close();
			//gcnew PrincipalDos(formAbierto, manejadorBD);
		}
		else if (nombreForm == "etapaTres") {
			this->Close();
			//gcnew PrincipalTres(formAbierto, manejadorBD);
		}
		else if (nombreForm == "etapaCuatro") {
			this->Close();
			//gcnew PrincipalCuatro(formAbierto, manejadorBD);
		}
		else if (nombreForm == "etapaCinco") {
			this->Close();
			//gcnew PrincipalCinco(formAbierto, manejadorBD);
		}
	}
}
System::Void TutIntV30::Advertencia::btnNo_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
System::Void TutIntV30::Advertencia::btnSi_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnSi->Size = System::Drawing::Size(wSi + 7, hSi + 7);
}
System::Void TutIntV30::Advertencia::btnSi_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnSi->Size = System::Drawing::Size(wSi, hSi);
}
System::Void TutIntV30::Advertencia::btnNo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnNo->Size = System::Drawing::Size(wNo + 7, hNo + 7);
}
System::Void TutIntV30::Advertencia::btnNo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnNo->Size = System::Drawing::Size(wNo, hNo);
}
System::Void TutIntV30::Advertencia::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
System::Void TutIntV30::Advertencia::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
	}
}
System::Void TutIntV30::Advertencia::Advertencia_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
