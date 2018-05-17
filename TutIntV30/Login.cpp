#include "Login.h"
#include "Niveles.h"
#include "Registro.h"

System::Void TutIntV30::Login::inicializarTam() {
	wPic2 = this->pictureBox1->Size.Width;
	hPic2 = this->pictureBox1->Size.Height;
}
System::Void TutIntV30::Login::pictureBox1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox1->Size = System::Drawing::Size(wPic2 + 10, hPic2 + 10);
}
System::Void TutIntV30::Login::pictureBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox1->Size = System::Drawing::Size(wPic2, hPic2);
}
System::Void TutIntV30::Login::pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	Registro^ registro = gcnew Registro(this->dgv1, manejadorBD);
	registro->ShowDialog();
}
System::Void TutIntV30::Login::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Hide();
	}
}
System::Void TutIntV30::Login::Login_Load(System::Object^  sender, System::EventArgs^  e) {
	this->dgv1->DataSource = manejadorBD->seleccionarListaUsuariosRegistrados()->Tables[0];
	timer1->Start();
	if (dgv1->RowCount == 0)
	{
		//PlaySound(TEXT("Audios/Inicio/inicio.wav"), NULL, SND_ASYNC);
	}
}
System::Void TutIntV30::Login::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void TutIntV30::Login::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Login::Login_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Login::Login_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Login::dgv1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	String^ nombre = this->dgv1->CurrentRow->Cells[0]->Value->ToString();
	if (nombre == nullptr) {
		System::Windows::Forms::MessageBox::Show("No existe una cuenta en esta seccion");
	}
	else {
		manejadorBD->setNombreJugador(nombre);
		int num_sesion = manejadorBD->seleccionarNumeroSesion();
		//System::Windows::Forms::MessageBox::Show(Convert::ToString(num_sesion));
		num_sesion = num_sesion + 1;
		manejadorBD->setNumSesion(num_sesion);
		gcnew Niveles(this, manejadorBD);
	}
}

System::Void TutIntV30::Login::pictureBox4_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	//PlaySound(TEXT("Audios/Inicio/inicio.wav"), NULL, SND_ASYNC);
}
