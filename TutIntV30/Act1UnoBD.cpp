#include "Act1UnoBD.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act1UnoBD::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void TutIntV30::Act1UnoBD::comprobarRespuestas() {
	if (listoPinguino == true && listoEstrella == true && listoEsponjas == true && listoBallena == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act1UnoBD::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act1UnoBD::obtenerTiempoItems() {
	vector<TiempoMI*> tiempoItems;
	TiempoMI* tmp = new TiempoMI();
	tmp->setMinutos(t_item1->getMinutos());
	tmp->setSegundos(t_item1->getSegundos());
	tiempoItems.push_back(tmp);
	TiempoMI* tmp2 = new TiempoMI();
	tmp2->setMinutos(t_item2->getMinutos());
	tmp2->setSegundos(t_item2->getSegundos());
	tiempoItems.push_back(tmp2);
	TiempoMI* tmp3 = new TiempoMI();
	tmp3->setMinutos(t_item3->getMinutos());
	tmp3->setSegundos(t_item3->getSegundos());
	tiempoItems.push_back(tmp3);
	TiempoMI* tmp4 = new TiempoMI();
	tmp4->setMinutos(t_item4->getMinutos());
	tmp4->setSegundos(t_item4->getSegundos());
	tiempoItems.push_back(tmp4);

	return tiempoItems;
}
System::Void TutIntV30::Act1UnoBD::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;
	msclr::interop::marshal_context context;

	string stringBtn1 = context.marshal_as<std::string>(this->textEsponjas->Text->ToString());
	respuestas.push_back(stringBtn1);
	stringBtn1.clear();

	string stringBtn2 = context.marshal_as<std::string>(this->textPinguino->Text->ToString());
	respuestas.push_back(stringBtn2);
	stringBtn2.clear();

	string stringBtn3 = context.marshal_as<std::string>(this->textEstrella->Text->ToString());
	respuestas.push_back(stringBtn3);
	stringBtn3.clear();

	string stringBtn4 = context.marshal_as<std::string>(this->textBallena->Text->ToString());
	respuestas.push_back(stringBtn4);
	stringBtn4.clear();

	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Basica", "Dificil", 1);
	controlador->obtenerNivelLogro();
	controlador->evaluarActividad();
	manejadorBD->setNumeroActividad(1);
	int codigoAct = manejadorBD->seleccionarUltimoCodigoActividad();
	codigoAct = codigoAct + 1;
	manejadorBD->setCodigoActividad(codigoAct);
	int cantidad;
	if (controlador->getRecuperacion()->getNivelActuacion() == "Alto") {
		cantidad = 3;
	}
	else if (controlador->getRecuperacion()->getNivelActuacion() == "Medio")
	{
		cantidad = 2;
	}
	else if (controlador->getRecuperacion()->getNivelActuacion() == "Bajo")
	{
		cantidad = 1;
	}
	String^ problemaGenerado = "";
	if (controlador->getProblema() != "") {
		problemaGenerado = context.marshal_as<String^>(controlador->getProblema());
	}
	else {
		vector<Regla*> reglasPeso = controlador->getReglasMayorPeso();
		String^ stringReglas;
		for (unsigned int i = 0; i < reglasPeso.size(); i++) {
			stringReglas = stringReglas + i + ")" + context.marshal_as<String^>(reglasPeso[i]->ToString()) + "\n";
		}
		//MessageBox::Show(stringReglas);
	}
	int intentos = manejadorBD->seleccionarIntentosActividad() + 1;
	MessageBox::Show("Nivel Actuacion = " + controlador->getRecuperacion()->getPorcentajeActuacion() + "\nNivel Actuacion: " + context.marshal_as<String^>(controlador->getRecuperacion()->getNivelActuacion()) + "\nTotal actuacion: " + context.marshal_as<String^>(controlador->getRecuperacion()->getTotalActuacion()));
	string porcentaje = to_string(controlador->getRecuperacion()->getPorcentajeActuacion());
	for (unsigned int x = 0; x < strlen(porcentaje.c_str()) - 1; x++)
	{
		if (porcentaje[x] == ',')
		{
			porcentaje[x] = '.';
		}
	}
	manejadorBD->setNombreHabilidad("Conciencia_fonologica");
	manejadorBD->setDificultad("Basica");
	manejadorBD->setComplejidad("Dificil");
	manejadorBD->ingresarPercepcionesUsuario(tiempoAct, contAyuda, context.marshal_as<String^>(porcentaje), context.marshal_as<String^>(controlador->getRecuperacion()->getNivelActuacion()), context.marshal_as<String^>(controlador->getRecuperacion()->getTotalActuacion()));
	MessageBox::Show("Buenas = " + controlador->getRespuestasBuenas() + "\nMalas = " + controlador->getRespuestasMalas() + "\nNivel Logro = " + context.marshal_as<String^>(controlador->getPercepciones()->getNivelLogro()) + "\nTiempo Acr = " + tiempoAct->getMinutos() + ":" + tiempoAct->getSegundos() + "\n Problema=" + problemaGenerado);
	//MessageBox::Show(context.marshal_as<String^>(controlador->getActuacion()));
	manejadorBD->ingresarDatosActividadActual(controlador->getRespuestasBuenas(), controlador->getRespuestasMalas(), context.marshal_as<String^>(controlador->getPercepciones()->getNivelLogro()), cantidad, intentos, problemaGenerado, context.marshal_as<String^>(controlador->getActuacion()));
	for (int i = 0; i < 4; i++) {
		int cont = i;
		manejadorBD->ingresarTiemposItem(tiempoItems[i], cont++);
	}
	manejadorBD->actualizarContadoresHabilidad(controlador->getRecuperacion()->getContadorAlto(), controlador->getRecuperacion()->getContadorMedio(), controlador->getRecuperacion()->getContadorBajo());
	FormEstrella^ ventana = gcnew FormEstrella(controlador, manejadorBD, "Conciencia_fonologica", this, cantidad);
	ventana->ShowDialog();
}
System::Void TutIntV30::Act1UnoBD::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act1UnoBD::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act1UnoBD::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act1UnoBD::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act1UnoBD::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act1UnoBD::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act1UnoBD::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act1UnoBD::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
	//sonidoInicial();
	this->contAyuda++;
	if (this->instruccion1->Visible == true) {
		this->instruccion1->Visible = false;
		this->instruccion2->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Dificil/Complejidad dificil/ND_CD_voz2.wav"), NULL, SND_ASYNC);
	}
	else if (this->instruccion2->Visible == true) {
		this->instruccion2->Visible = false;
		this->instruccion1->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Dificil/Complejidad dificil/ND_CD_voz1.wav"), NULL, SND_ASYNC);
	}
}
System::Void TutIntV30::Act1UnoBD::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act1UnoBD::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act1UnoBD::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act1UnoBD::Act1UnoBD_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Dificil/Complejidad dificil/NB_CD_voz1.wav"), NULL, SND_ASYNC);
	//sumar tiempo que demora en dar la instrucción a t_actividad
	t_actividad = gcnew TiempoGUI();
	//t_actividad->setSegundos(tiempo de reproduccion de actividad);
	t_item1 = gcnew TiempoGUI();
	t_item2 = gcnew TiempoGUI();
	t_item3 = gcnew TiempoGUI();
	t_item4 = gcnew TiempoGUI();
	hiloAct = gcnew Thread(gcnew ThreadStart(t_actividad, &TiempoGUI::cronometro));
	hiloAct->Start();
}
System::Void TutIntV30::Act1UnoBD::Act1UnoBD_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act1UnoBD::Act1UnoBD_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act1UnoBD::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::TextBox^ textBox)
{
	if (textBox->Text != "") {
		int tiempo_total_seg;
		if (numItem == 1)
		{
			tiempo_total_seg = t_item1->segundostotales();
			if (tiempo_total_seg < t_item2->segundostotales()) {
				tiempo_total_seg = t_item2->segundostotales();
			}
			if (tiempo_total_seg < t_item3->segundostotales()) {
				tiempo_total_seg = t_item3->segundostotales();
			}
			if (tiempo_total_seg < t_item4->segundostotales()) {
				tiempo_total_seg = t_item4->segundostotales();
			}
		}
		else if (numItem == 2)
		{
			tiempo_total_seg = t_item2->segundostotales();
			if (tiempo_total_seg < t_item1->segundostotales()) {
				tiempo_total_seg = t_item1->segundostotales();
			}
			else if (tiempo_total_seg < t_item3->segundostotales()) {
				tiempo_total_seg = t_item3->segundostotales();
			}
			else if (tiempo_total_seg < t_item4->segundostotales()) {
				tiempo_total_seg = t_item4->segundostotales();
			}

		}
		else if (numItem == 3)
		{
			tiempo_total_seg = t_item3->segundostotales();
			if (tiempo_total_seg < t_item1->segundostotales()) {
				tiempo_total_seg = t_item1->segundostotales();
			}
			if (tiempo_total_seg < t_item2->segundostotales()) {
				tiempo_total_seg = t_item2->segundostotales();
			}
			if (tiempo_total_seg < t_item4->segundostotales()) {
				tiempo_total_seg = t_item4->segundostotales();
			}
		}
		else if (numItem == 4)
		{
			tiempo_total_seg = t_item4->segundostotales();
			if (tiempo_total_seg < t_item1->segundostotales()) {
				tiempo_total_seg = t_item1->segundostotales();
			}
			if (tiempo_total_seg < t_item2->segundostotales()) {
				tiempo_total_seg = t_item2->segundostotales();
			}
			if (tiempo_total_seg < t_item3->segundostotales()) {
				tiempo_total_seg = t_item3->segundostotales();
			}
		}
		//comparo la diferencia de tiempo entre el tr mayor y el de la actividad para sacar un tiempo de respuesta vertical.
		int diferencia = t_actividad->segundostotales() - tiempo_total_seg;
		tr_item->setMinutos(diferencia / 60);
		tr_item->setSegundos(diferencia % 60);
		//System::Windows::Forms::MessageBox::Show("Tiempo:\nMinutos: " + Convert::ToString(tr_item->getMinutos())+ "\nSegundos: "+ Convert::ToString(tr_item->getSegundos()));
	}
	else {
		//System::Windows::Forms::MessageBox::Show("Ya se clickeo");
	}
}
void TutIntV30::Act1UnoBD::cambiarColor() {
	this->textEsponjas->BackColor = System::Drawing::Color::White;
	this->textEsponjas->ForeColor = System::Drawing::Color::Black;
	this->lblEsponjas->ForeColor = System::Drawing::Color::Black;
	this->textBallena->BackColor = System::Drawing::Color::White;
	this->textBallena->ForeColor = System::Drawing::Color::Black;
	this->lblBallena->ForeColor = System::Drawing::Color::Black;
	this->textPinguino->BackColor = System::Drawing::Color::White;
	this->textPinguino->ForeColor = System::Drawing::Color::Black;
	this->lblPinguino->ForeColor = System::Drawing::Color::Black;
	this->textEstrella->BackColor = System::Drawing::Color::White;
	this->textEstrella->ForeColor = System::Drawing::Color::Black;
	this->lblEstrella->ForeColor = System::Drawing::Color::Black;
}
System::Void TutIntV30::Act1UnoBD::textEsponjas_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (!(Char::IsNumber(e->KeyChar)) && (e->KeyChar != (char)Keys::Back))
	{
		textEsponjas->Text = "";
		e->Handled = true;
		return;
	}
}
System::Void TutIntV30::Act1UnoBD::textEstrella_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (!(Char::IsNumber(e->KeyChar)) && (e->KeyChar != (char)Keys::Back))
	{
		textEstrella->Text = "";
		e->Handled = true;
		return;
	}
}
System::Void TutIntV30::Act1UnoBD::textPinguino_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (!(Char::IsNumber(e->KeyChar)) && (e->KeyChar != (char)Keys::Back))
	{
		textPinguino->Text = "";
		e->Handled = true;
		return;
	}
}
System::Void TutIntV30::Act1UnoBD::textBallena_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (!(Char::IsNumber(e->KeyChar)) && (e->KeyChar != (char)Keys::Back))
	{
		textBallena->Text = "";
		e->Handled = true;
		return;
	}
}
System::Void TutIntV30::Act1UnoBD::textEsponjas_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarColor();
	this->textEsponjas->BackColor = System::Drawing::Color::Olive;
	this->textEsponjas->ForeColor = System::Drawing::Color::White;
	this->lblEsponjas->ForeColor = System::Drawing::Color::Olive;
}
System::Void TutIntV30::Act1UnoBD::textEstrella_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarColor();
	this->textEstrella->BackColor = System::Drawing::Color::Olive;
	this->textEstrella->ForeColor = System::Drawing::Color::White;
	this->lblEstrella->ForeColor = System::Drawing::Color::Olive;
}
System::Void TutIntV30::Act1UnoBD::textPinguino_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarColor();
	this->textPinguino->BackColor = System::Drawing::Color::Olive;
	this->textPinguino->ForeColor = System::Drawing::Color::White;
	this->lblPinguino->ForeColor = System::Drawing::Color::Olive;
}
System::Void TutIntV30::Act1UnoBD::textBallena_Click(System::Object^  sender, System::EventArgs^  e) {
	cambiarColor();
	this->textBallena->BackColor = System::Drawing::Color::Olive;
	this->textBallena->ForeColor = System::Drawing::Color::White;
	this->lblBallena->ForeColor = System::Drawing::Color::Olive;
}
System::Void TutIntV30::Act1UnoBD::textEsponjas_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(1, t_item1, this->textEsponjas);
	if (this->textEsponjas->Text == "") {
		listoEsponjas = false;
		this->btnListo->Visible = false;
	}
	else {
		listoEsponjas = true;
		comprobarRespuestas();
	}
}
System::Void TutIntV30::Act1UnoBD::textBallena_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(4, t_item4, this->textBallena);
	if (this->textBallena->Text == "") {
		listoBallena = false;
		this->btnListo->Visible = false;
	}
	else {
		listoBallena = true;
		comprobarRespuestas();
	}
}
System::Void TutIntV30::Act1UnoBD::textPinguino_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(2, t_item2, this->textPinguino);
	if (this->textPinguino->Text == "") {
		listoPinguino = false;
		this->btnListo->Visible = false;
	}
	else {
		listoPinguino = true;
		comprobarRespuestas();
	}
}
System::Void TutIntV30::Act1UnoBD::textEstrella_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(3, t_item3, this->textEstrella);
	if (this->textEstrella->Text == "") {
		listoEstrella = false;
		this->btnListo->Visible = false;
	}
	else {
		listoEstrella = true;
		comprobarRespuestas();
	}
}
