#include "Act1UnoDB.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act1UnoDB::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void TutIntV30::Act1UnoDB::inicializarPosiciones() {
	xbtn1FIN = btn1FIN->Location.X;		ybtn1FIN = btn1FIN->Location.Y;
	xbtn1DEL = btn1DEL->Location.X;		ybtn1DEL = btn1DEL->Location.Y;
	xbtn2RAL = btn2RAL->Location.X;		ybtn2RAL = btn2RAL->Location.Y;
	xbtn2CO = btn2CO->Location.X;		ybtn2CO = btn2CO->Location.Y;
	xbtn3CA = btn3CA->Location.X;		ybtn3CA = btn3CA->Location.Y;
	xbtn3RO = btn3RO->Location.X;		ybtn3RO = btn3RO->Location.Y;
	xbtn4PUL = btn4PUL->Location.X;		ybtn4PUL = btn4PUL->Location.Y;
	xbtn4PO = btn4PO->Location.X;		ybtn4PO = btn4PO->Location.Y;
}
System::Void TutIntV30::Act1UnoDB::comprobarRespuestas() {
	if (listoBtn1FIN == true && listoBtn1DEL == true && listoBtn2RAL == true && listoBtn2CO == true &&
		listoBtn3CA == true && listoBtn3RO == true && listoBtn4PUL == true && listoBtn4PO == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act1UnoDB::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act1UnoDB::obtenerTiempoItems() {
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
System::Void TutIntV30::Act1UnoDB::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;
	msclr::interop::marshal_context context;

	if (btn1FIN->Location == panel1Uno->Location) {
		respuestas.push_back("FINDEL");
	}
	else {
		respuestas.push_back("DELFIN");
	}

	if (btn2RAL->Location == panel2Uno->Location) {
		respuestas.push_back("RALCO");
	}
	else {
		respuestas.push_back("CORAL");
	}

	if (btn3CA->Location == panel3Uno->Location) {
		respuestas.push_back("CARO");
	}
	else {
		respuestas.push_back("ROCA");
	}

	if (btn4PUL->Location == panel4Uno->Location) {
		respuestas.push_back("PULPO");
	}
	else {
		respuestas.push_back("POPUL");
	}

	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Dificil", "Basica", 1);
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
System::Void TutIntV30::Act1UnoDB::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act1UnoDB::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act1UnoDB::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act1UnoDB::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act1UnoDB::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act1UnoDB::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act1UnoDB::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act1UnoDB::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
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
System::Void TutIntV30::Act1UnoDB::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act1UnoDB::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act1UnoDB::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act1UnoDB::Act1UnoDB_Load(System::Object^  sender, System::EventArgs^  e) {
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
System::Void TutIntV30::Act1UnoDB::Act1UnoDB_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act1UnoDB::Act1UnoDB_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act1UnoDB::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos)
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
System::Void TutIntV30::Act1UnoDB::moverBoton(System::Windows::Forms::Button^ boton) {
	boton->Location = System::Drawing::Point(posMouseFormX - posMouseBtnX, posMouseFormY - posMouseBtnY);
	posActBtnX = boton->Location.X;
	posActBtnY = boton->Location.Y;
}
System::Void TutIntV30::Act1UnoDB::btn1FIN_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1FIN->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1UnoDB::btn1DEL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1DEL->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1UnoDB::btn2RAL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2RAL->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1UnoDB::btn2CO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2CO->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1UnoDB::btn3CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3CA->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1UnoDB::btn3RO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3RO->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1UnoDB::btn4PUL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4PUL->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1UnoDB::btn4PO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4PO->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1UnoDB::btn1FIN_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1FIN->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1FIN->Location.X;
	int y = btn1FIN->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1DEL->Location != panel1Uno->Location) {
			btn1FIN->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1FIN = true;
			tiempo_respuesta(1, t_item1, listoBtn1FIN, listoBtn1DEL);
		}
		else {
			btn1FIN->Location = System::Drawing::Point(xbtn1FIN, ybtn1FIN);
			listoBtn1FIN = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1DEL->Location != panel1Dos->Location) {
			btn1FIN->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1FIN = true;
			tiempo_respuesta(1, t_item1, listoBtn1FIN, listoBtn1DEL);
		}
		else {
			btn1FIN->Location = System::Drawing::Point(xbtn1FIN, ybtn1FIN);
			listoBtn1FIN = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1FIN->Location = System::Drawing::Point(xbtn1FIN, ybtn1FIN);
		listoBtn1FIN = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDB::btn1DEL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1DEL->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1DEL->Location.X;
	int y = btn1DEL->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1FIN->Location != panel1Uno->Location) {
			btn1DEL->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1DEL = true;
			tiempo_respuesta(1, t_item1, listoBtn1FIN, listoBtn1DEL);
		}
		else {
			btn1DEL->Location = System::Drawing::Point(xbtn1DEL, ybtn1DEL);
			listoBtn1DEL = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1FIN->Location != panel1Dos->Location) {
			btn1DEL->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1DEL = true;
			tiempo_respuesta(1, t_item1, listoBtn1FIN, listoBtn1DEL);
		}
		else {
			btn1DEL->Location = System::Drawing::Point(xbtn1DEL, ybtn1DEL);
			listoBtn1DEL = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1DEL->Location = System::Drawing::Point(xbtn1DEL, ybtn1DEL);
		listoBtn1DEL = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDB::btn2RAL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2RAL->BackColor = System::Drawing::Color::Teal;
	int x = btn2RAL->Location.X;
	int y = btn2RAL->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2CO->Location != panel2Uno->Location) {
			btn2RAL->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2RAL = true;
			tiempo_respuesta(2, t_item2, listoBtn2RAL, listoBtn2CO);
		}
		else {
			btn2RAL->Location = System::Drawing::Point(xbtn2RAL, ybtn2RAL);
			listoBtn2RAL = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2CO->Location != panel2Dos->Location) {
			btn2RAL->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2RAL = true;
			tiempo_respuesta(2, t_item2, listoBtn2RAL, listoBtn2CO);
		}
		else {
			btn2RAL->Location = System::Drawing::Point(xbtn2RAL, ybtn2RAL);
			listoBtn2RAL = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2RAL->Location = System::Drawing::Point(xbtn2RAL, ybtn2RAL);
		listoBtn2RAL = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDB::btn2CO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2CO->BackColor = System::Drawing::Color::Teal;
	int x = btn2CO->Location.X;
	int y = btn2CO->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2RAL->Location != panel2Uno->Location) {
			btn2CO->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2CO = true;
			tiempo_respuesta(2, t_item2, listoBtn2RAL, listoBtn2CO);
		}
		else {
			btn2CO->Location = System::Drawing::Point(xbtn2CO, ybtn2CO);
			listoBtn2CO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2RAL->Location != panel2Dos->Location) {
			btn2CO->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2CO = true;
			tiempo_respuesta(2, t_item2, listoBtn2RAL, listoBtn2CO);
		}
		else {
			btn2CO->Location = System::Drawing::Point(xbtn2CO, ybtn2CO);
			listoBtn2CO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2CO->Location = System::Drawing::Point(xbtn2CO, ybtn2CO);
		listoBtn2CO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDB::btn3CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3CA->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3CA->Location.X;
	int y = btn3CA->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3RO->Location != panel3Uno->Location) {
			btn3CA->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3CA = true;
			tiempo_respuesta(3, t_item3, listoBtn3RO, listoBtn3CA);
		}
		else {
			btn3CA->Location = System::Drawing::Point(xbtn3CA, ybtn3CA);
			listoBtn3CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3RO->Location != panel3Dos->Location) {
			btn3CA->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3CA = true;
			tiempo_respuesta(3, t_item3, listoBtn3RO, listoBtn3CA);
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
System::Void TutIntV30::Act1UnoDB::btn3RO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3RO->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3RO->Location.X;
	int y = btn3RO->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3CA->Location != panel3Uno->Location) {
			btn3RO->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3RO = true;
			tiempo_respuesta(3, t_item3, listoBtn3RO, listoBtn3CA);
		}
		else {
			btn3RO->Location = System::Drawing::Point(xbtn3RO, ybtn3RO);
			listoBtn3RO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3CA->Location != panel3Dos->Location) {
			btn3RO->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3RO = true;
			tiempo_respuesta(3, t_item3, listoBtn3RO, listoBtn3CA);
		}
		else {
			btn3RO->Location = System::Drawing::Point(xbtn3RO, ybtn3RO);
			listoBtn3RO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3RO->Location = System::Drawing::Point(xbtn3RO, ybtn3RO);
		listoBtn3RO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDB::btn4PUL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4PUL->BackColor = System::Drawing::Color::Olive;
	int x = btn4PUL->Location.X;
	int y = btn4PUL->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4PO->Location != panel4Uno->Location) {
			btn4PUL->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4PUL = true;
			tiempo_respuesta(4, t_item4, listoBtn4PO, listoBtn4PUL);
		}
		else {
			btn4PUL->Location = System::Drawing::Point(xbtn4PUL, ybtn4PUL);
			listoBtn4PUL = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4PO->Location != panel4Dos->Location) {
			btn4PUL->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4PUL = true;
			tiempo_respuesta(4, t_item4, listoBtn4PO, listoBtn4PUL);
		}
		else {
			btn4PUL->Location = System::Drawing::Point(xbtn4PUL, ybtn4PUL);
			listoBtn4PUL = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4PUL->Location = System::Drawing::Point(xbtn4PUL, ybtn4PUL);
		listoBtn4PUL = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDB::btn4PO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4PO->BackColor = System::Drawing::Color::Olive;
	int x = btn4PO->Location.X;
	int y = btn4PO->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4PUL->Location != panel4Uno->Location) {
			btn4PO->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4PO = true;
			tiempo_respuesta(4, t_item4, listoBtn4PO, listoBtn4PUL);
		}
		else {
			btn4PO->Location = System::Drawing::Point(xbtn4PO, ybtn4PO);
			listoBtn4PO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4PUL->Location != panel4Dos->Location) {
			btn4PO->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4PO = true;
			tiempo_respuesta(4, t_item4, listoBtn4PO, listoBtn4PUL);
		}
		else {
			btn4PO->Location = System::Drawing::Point(xbtn4PO, ybtn4PO);
			listoBtn4PO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4PO->Location = System::Drawing::Point(xbtn4PO, ybtn4PO);
		listoBtn4PO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDB::btn1FIN_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1FIN);
	}
}
System::Void TutIntV30::Act1UnoDB::btn1DEL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1DEL);
	}
}
System::Void TutIntV30::Act1UnoDB::btn2RAL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2RAL);
	}
}
System::Void TutIntV30::Act1UnoDB::btn2CO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2CO);
	}
}
System::Void TutIntV30::Act1UnoDB::btn3CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3CA);
	}
}
System::Void TutIntV30::Act1UnoDB::btn3RO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3RO);
	}
}
System::Void TutIntV30::Act1UnoDB::btn4PUL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4PUL);
	}
}
System::Void TutIntV30::Act1UnoDB::btn4PO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4PO);
	}
}