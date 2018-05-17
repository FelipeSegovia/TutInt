#include "Act1DosDB.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>

System::Void TutIntV30::Act1DosDB::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void TutIntV30::Act1DosDB::inicializarPosiciones() {
	xbtn1GA = btn1GA->Location.X;		ybtn1GA = btn1GA->Location.Y;
	xbtn1AL = btn1AL->Location.X;		ybtn1AL = btn1AL->Location.Y;
	xbtn2CA = btn2CA->Location.X;		ybtn2CA = btn2CA->Location.Y;
	xbtn2OR = btn2OR->Location.X;		ybtn2OR = btn2OR->Location.Y;
	xbtn3CA = btn3CA->Location.X;		ybtn3CA = btn3CA->Location.Y;
	xbtn3FO = btn3FO->Location.X;		ybtn3FO = btn3FO->Location.Y;
	xbtn4FRE = btn4FRE->Location.X;		ybtn4FRE = btn4FRE->Location.Y;
	xbtn4CO = btn4CO->Location.X;		ybtn4CO = btn4CO->Location.Y;
}
System::Void TutIntV30::Act1DosDB::comprobarRespuestas() {
	if (listoBtn1GA == true && listoBtn1AL == true && listoBtn2CA == true && listoBtn2OR == true &&
		listoBtn3CA == true && listoBtn3FO == true && listoBtn4FRE == true && listoBtn4CO == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act1DosDB::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act1DosDB::obtenerTiempoItems() {
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
System::Void TutIntV30::Act1DosDB::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;

	if (btn1GA->Location == panel1Uno->Location) {
		respuestas.push_back("GAAL");
	}
	else {
		respuestas.push_back("ALGA");
	}

	if (btn2CA->Location == panel2Uno->Location) {
		respuestas.push_back("CAOR");
	}
	else {
		respuestas.push_back("ORCA");
	}

	if (btn3CA->Location == panel3Uno->Location) {
		respuestas.push_back("CAFO");
	}
	else {
		respuestas.push_back("FOCA");
	}

	if (btn4FRE->Location == panel4Uno->Location) {
		respuestas.push_back("FRECO");
	}
	else {
		respuestas.push_back("COFRE");
	}
	msclr::interop::marshal_context context;
	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Dificil", "Basica", 2);
	controlador->obtenerNivelLogro();
	controlador->evaluarActividad();
	manejadorBD->setNumeroActividad(2);
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
	manejadorBD->setDificultad("Dificil");
	manejadorBD->setComplejidad("Basica");
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
System::Void TutIntV30::Act1DosDB::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act1DosDB::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act1DosDB::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act1DosDB::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act1DosDB::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act1DosDB::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act1DosDB::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act1DosDB::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
	//sonidoInicial();
	this->contAyuda++;
	if (this->instruccion1->Visible == true) {
		this->instruccion1->Visible = false;
		this->instruccion2->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad basica/NI_CB_voz2.wav"), NULL, SND_ASYNC);
	}
	else if (this->instruccion2->Visible == true) {
		this->instruccion2->Visible = false;
		this->instruccion1->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad basica/NI_CB_voz1.wav"), NULL, SND_ASYNC);
	}
}
System::Void TutIntV30::Act1DosDB::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act1DosDB::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act1DosDB::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act1DosDB::Act1DosDB_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad basica/NI_CB_voz1.wav"), NULL, SND_ASYNC);
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
System::Void TutIntV30::Act1DosDB::Act1DosDB_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act1DosDB::Act1DosDB_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act1DosDB::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos)
{
	if (listoUno == true && listoDos == true) {
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
System::Void TutIntV30::Act1DosDB::moverBoton(System::Windows::Forms::Button^ boton) {
	boton->Location = System::Drawing::Point(posMouseFormX - posMouseBtnX, posMouseFormY - posMouseBtnY);
	posActBtnX = boton->Location.X;
	posActBtnY = boton->Location.Y;
}
System::Void TutIntV30::Act1DosDB::btn1GA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1GA->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1DosDB::btn1AL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1AL->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1DosDB::btn2CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2CA->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1DosDB::btn2OR_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2OR->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1DosDB::btn3CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3CA->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDB::btn3FO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3FO->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDB::btn4FRE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4FRE->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1DosDB::btn4CO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4CO->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1DosDB::btn1GA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1GA->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1GA->Location.X;
	int y = btn1GA->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1AL->Location != panel1Uno->Location) {
			btn1GA->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1GA = true;
			tiempo_respuesta(1, t_item1, listoBtn1GA, listoBtn1AL);
		}
		else {
			btn1GA->Location = System::Drawing::Point(xbtn1GA, ybtn1GA);
			listoBtn1GA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1AL->Location != panel1Dos->Location) {
			btn1GA->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1GA = true;
			tiempo_respuesta(1, t_item1, listoBtn1GA, listoBtn1AL);
		}
		else {
			btn1GA->Location = System::Drawing::Point(xbtn1GA, ybtn1GA);
			listoBtn1GA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1GA->Location = System::Drawing::Point(xbtn1GA, ybtn1GA);
		listoBtn1GA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDB::btn1AL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1AL->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1AL->Location.X;
	int y = btn1AL->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1GA->Location != panel1Uno->Location) {
			btn1AL->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1AL = true;
			tiempo_respuesta(1, t_item1, listoBtn1GA, listoBtn1AL);
		}
		else {
			btn1AL->Location = System::Drawing::Point(xbtn1AL, ybtn1AL);
			listoBtn1AL = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1GA->Location != panel1Dos->Location) {
			btn1AL->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1AL = true;
			tiempo_respuesta(1, t_item1, listoBtn1GA, listoBtn1AL);
		}
		else {
			btn1AL->Location = System::Drawing::Point(xbtn1AL, ybtn1AL);
			listoBtn1AL = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1AL->Location = System::Drawing::Point(xbtn1AL, ybtn1AL);
		listoBtn1AL = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDB::btn2CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2CA->BackColor = System::Drawing::Color::Teal;
	int x = btn2CA->Location.X;
	int y = btn2CA->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2OR->Location != panel2Uno->Location) {
			btn2CA->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2CA = true;
			tiempo_respuesta(2, t_item2, listoBtn2CA, listoBtn2OR);
		}
		else {
			btn2CA->Location = System::Drawing::Point(xbtn2CA, ybtn2CA);
			listoBtn2CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2OR->Location != panel2Dos->Location) {
			btn2CA->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2CA = true;
			tiempo_respuesta(2, t_item2, listoBtn2CA, listoBtn2OR);
		}
		else {
			btn2CA->Location = System::Drawing::Point(xbtn2CA, ybtn2CA);
			listoBtn2CA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2CA->Location = System::Drawing::Point(xbtn2CA, ybtn2CA);
		listoBtn2CA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDB::btn2OR_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2OR->BackColor = System::Drawing::Color::Teal;
	int x = btn2OR->Location.X;
	int y = btn2OR->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2CA->Location != panel2Uno->Location) {
			btn2OR->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2OR = true;
			tiempo_respuesta(2, t_item2, listoBtn2CA, listoBtn2OR);
		}
		else {
			btn2OR->Location = System::Drawing::Point(xbtn2OR, ybtn2OR);
			listoBtn2OR = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2CA->Location != panel2Dos->Location) {
			btn2OR->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2OR = true;
			tiempo_respuesta(2, t_item2, listoBtn2CA, listoBtn2OR);
		}
		else {
			btn2OR->Location = System::Drawing::Point(xbtn2OR, ybtn2OR);
			listoBtn2OR = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2OR->Location = System::Drawing::Point(xbtn2OR, ybtn2OR);
		listoBtn2OR = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDB::btn3CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3CA->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3CA->Location.X;
	int y = btn3CA->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3FO->Location != panel3Uno->Location) {
			btn3CA->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3CA = true;
			tiempo_respuesta(3, t_item3, listoBtn3FO, listoBtn3CA);
		}
		else {
			btn3CA->Location = System::Drawing::Point(xbtn3CA, ybtn3CA);
			listoBtn3CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3FO->Location != panel3Dos->Location) {
			btn3CA->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3CA = true;
			tiempo_respuesta(3, t_item3, listoBtn3FO, listoBtn3CA);
		}
		else {
			btn3CA->Location = System::Drawing::Point(xbtn3CA, ybtn3CA);
			listoBtn3CA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3CA->Location = System::Drawing::Point(xbtn3CA, ybtn3CA);
		listoBtn3CA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDB::btn3FO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3FO->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3FO->Location.X;
	int y = btn3FO->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3CA->Location != panel3Uno->Location) {
			btn3FO->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3FO = true;
			tiempo_respuesta(3, t_item3, listoBtn3FO, listoBtn3CA);
		}
		else {
			btn3FO->Location = System::Drawing::Point(xbtn3FO, ybtn3FO);
			listoBtn3FO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3CA->Location != panel3Dos->Location) {
			btn3FO->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3FO = true;
			tiempo_respuesta(3, t_item3, listoBtn3FO, listoBtn3CA);
		}
		else {
			btn3FO->Location = System::Drawing::Point(xbtn3FO, ybtn3FO);
			listoBtn3FO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3FO->Location = System::Drawing::Point(xbtn3FO, ybtn3FO);
		listoBtn3FO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDB::btn4FRE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4FRE->BackColor = System::Drawing::Color::Olive;
	int x = btn4FRE->Location.X;
	int y = btn4FRE->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4CO->Location != panel4Uno->Location) {
			btn4FRE->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4FRE = true;
			tiempo_respuesta(4, t_item4, listoBtn4CO, listoBtn4FRE);
		}
		else {
			btn4FRE->Location = System::Drawing::Point(xbtn4FRE, ybtn4FRE);
			listoBtn4FRE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4CO->Location != panel4Dos->Location) {
			btn4FRE->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4FRE = true;
			tiempo_respuesta(4, t_item4, listoBtn4CO, listoBtn4FRE);
		}
		else {
			btn4FRE->Location = System::Drawing::Point(xbtn4FRE, ybtn4FRE);
			listoBtn4FRE = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4FRE->Location = System::Drawing::Point(xbtn4FRE, ybtn4FRE);
		listoBtn4FRE = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDB::btn4CO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4CO->BackColor = System::Drawing::Color::Olive;
	int x = btn4CO->Location.X;
	int y = btn4CO->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4FRE->Location != panel4Uno->Location) {
			btn4CO->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4CO = true;
			tiempo_respuesta(4, t_item4, listoBtn4CO, listoBtn4FRE);
		}
		else {
			btn4CO->Location = System::Drawing::Point(xbtn4CO, ybtn4CO);
			listoBtn4CO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4FRE->Location != panel4Dos->Location) {
			btn4CO->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4CO = true;
			tiempo_respuesta(4, t_item4, listoBtn4CO, listoBtn4FRE);
		}
		else {
			btn4CO->Location = System::Drawing::Point(xbtn4CO, ybtn4CO);
			listoBtn4CO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4CO->Location = System::Drawing::Point(xbtn4CO, ybtn4CO);
		listoBtn4CO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDB::btn1GA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1GA);
	}
}
System::Void TutIntV30::Act1DosDB::btn1AL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1AL);
	}
}
System::Void TutIntV30::Act1DosDB::btn2CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2CA);
	}
}
System::Void TutIntV30::Act1DosDB::btn2OR_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2OR);
	}
}
System::Void TutIntV30::Act1DosDB::btn3CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3CA);
	}
}
System::Void TutIntV30::Act1DosDB::btn3FO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3FO);
	}
}
System::Void TutIntV30::Act1DosDB::btn4FRE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4FRE);
	}
}
System::Void TutIntV30::Act1DosDB::btn4CO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4CO);
	}
}