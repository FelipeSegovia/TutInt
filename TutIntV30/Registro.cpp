#include "Registro.h"

System::Void TutIntV30::Registro::pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ id = this->textBox1->Text;
	bool aceptado = manejadorBD->ingresarDatosRegistro(id);
	if (aceptado) {
		this->Close();
		// Se carga la tabla
		this->tabla->DataSource = manejadorBD->seleccionarListaUsuariosRegistrados()->Tables[0];
	}
}
System::Void TutIntV30::Registro::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
System::Void TutIntV30::Registro::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
	}
}
System::Void TutIntV30::Registro::Registro_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Inicio/instruccion_registro.wav"), NULL, SND_ASYNC);
}
