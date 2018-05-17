#include "MyForm.h"
#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TutIntV30::MyForm form;
	form.Size = System::Drawing::Size(1050, 598);
	Application::Run(%form);

}
System::Void TutIntV30::MyForm::timer1_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Opacity += .05;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
	}
}
System::Void TutIntV30::MyForm::MyForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	timer1->Start();
}
System::Void TutIntV30::MyForm::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void TutIntV30::MyForm::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::MyForm::inicializarTam()
{
	wPic = this->pictureBox2->Size.Width;
	hPic = this->pictureBox2->Size.Height;
}
System::Void TutIntV30::MyForm::pictureBox2_MouseHover(System::Object^  sender, System::EventArgs^  e)
{
	this->pictureBox2->Size = System::Drawing::Size(wPic + 20, hPic + 20);
}
System::Void TutIntV30::MyForm::pictureBox2_MouseLeave(System::Object^  sender, System::EventArgs^  e)
{
	this->pictureBox2->Size = System::Drawing::Size(wPic, hPic);
}
System::Void TutIntV30::MyForm::pictureBox2_Click(System::Object^  sender, System::EventArgs^  e)
{
	Login^ login = gcnew Login(this);
}
System::Void TutIntV30::MyForm::MyForm_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::MyForm::MyForm_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}