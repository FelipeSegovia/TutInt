#include "Mensaje.h"
#include "NivelUno.h"
#include "NivelDos.h"
#include <windows.h>
#include <MMSystem.h>

System::Void TutIntV30::Mensaje::SonidoUno() {
	//PlaySound(TEXT("Audios/Oceano/Nemo-Papa.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Mensaje::SonidoDos() {
	//PlaySound(TEXT("Audios/Playa/Bob-Esponja-Final.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Mensaje::SonidoTres() {
	//PlaySound(TEXT("Audios/Parque/Judy-Final.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Mensaje::SonidoCuatro() {
	//PlaySound(TEXT("Audios/Zoologico/Marty-Final.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Mensaje::SonidoCinco() {
	//PlaySound(TEXT("Audios/Espacio/Gru-Final.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Mensaje::iniciarPic() {
	this->pictureUno->Visible = false;
	this->pictureDos->Visible = false;
}
System::Void TutIntV30::Mensaje::inicializar() {
	iniciarPic();
	if (habilidad == 1) {
		this->pictureUno->Visible = true;
		SonidoUno();
	}
	else if (habilidad == 2) {
		this->pictureDos->Visible = true;
		SonidoDos();
	}
	else if (habilidad == 3) {
		//this->pictureBox2->Visible = true;
		//this->picTres->Visible = true;
		SonidoTres();
	}
	else if (habilidad == 4) {
		//this->pictureBox2->Visible = true;
		//this->picCuatro->Visible = true;
		SonidoCuatro();
	}
	else if (habilidad == 5) {
		//this->pictureBox1->Visible = true;
		//this->picCinco->Visible = true;
		SonidoCinco();
	}
}
System::Void TutIntV30::Mensaje::btnUno_Click(System::Object^  sender, System::EventArgs^  e) {
	if (habilidad == 1 || habilidad == 2) {
		manejadorBD->ingresarActualizacionDatosHabilidad("Conciencia_alfabetica", 0, "Desbloqueado");
		NivelUno ^nivel = gcnew NivelUno(form, manejadorBD);
	}
	else if (habilidad == 3 || habilidad == 4) {
		//NivelDos ^nivel = gcnew NivelDos(form, manejadorBD);
	}
	else if (habilidad == 5) {

	}
	this->Close();
}
System::Void TutIntV30::Mensaje::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->Close();
	}
}
System::Void TutIntV30::Mensaje::Mensaje_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
