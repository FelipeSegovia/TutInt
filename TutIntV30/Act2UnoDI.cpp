#include "Act2UnoDI.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act2UnoDI::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void TutIntV30::Act2UnoDI::inicializarPosiciones() {
	xbtn1 = btnUno->Location.X;			ybtn1 = btnUno->Location.Y;
	xbtn2 = btnDos->Location.X;			ybtn2 = btnDos->Location.Y;
	xbtn3 = btnTres->Location.X;			ybtn3 = btnTres->Location.Y;
	xbtn4 = btnCuatro->Location.X;		ybtn4 = btnCuatro->Location.Y;
}
System::Void TutIntV30::Act2UnoDI::comprobarRespuestas() {
	if (listoBtn1 == true && listoBtn2 == true && listoBtn3 == true && listoBtn4 == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act2UnoDI::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaDos", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act2UnoDI::obtenerTiempoItems() {
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
System::Void TutIntV30::Act2UnoDI::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;

	if (btnUno->Location.X == panelUno->Location.X && btnUno->Location.Y == panelUno->Location.Y) {
		respuestas.push_back("1");	// Posicion 1
	}
	else if (btnUno->Location.X == panelDos->Location.X && btnUno->Location.Y == panelDos->Location.Y) {
		respuestas.push_back("2");
	}
	else if (btnUno->Location.X == panelTres->Location.X && btnUno->Location.Y == panelTres->Location.Y) {
		respuestas.push_back("3");
	}
	else if (btnUno->Location.X == panelCuatro->Location.X && btnUno->Location.Y == panelCuatro->Location.Y) {
		respuestas.push_back("4");
	}

	if (btnDos->Location.X == panelUno->Location.X && btnDos->Location.Y == panelUno->Location.Y) {
		respuestas.push_back("1");	// Posicion 1
	}
	else if (btnDos->Location.X == panelDos->Location.X && btnDos->Location.Y == panelDos->Location.Y) {
		respuestas.push_back("2");
	}
	else if (btnDos->Location.X == panelTres->Location.X && btnDos->Location.Y == panelTres->Location.Y) {
		respuestas.push_back("3");
	}
	else if (btnDos->Location.X == panelCuatro->Location.X && btnDos->Location.Y == panelCuatro->Location.Y) {
		respuestas.push_back("4");
	}

	if (btnTres->Location.X == panelUno->Location.X && btnTres->Location.Y == panelUno->Location.Y) {
		respuestas.push_back("1");	// Posicion 1
	}
	else if (btnTres->Location.X == panelDos->Location.X && btnTres->Location.Y == panelDos->Location.Y) {
		respuestas.push_back("2");
	}
	else if (btnTres->Location.X == panelTres->Location.X && btnTres->Location.Y == panelTres->Location.Y) {
		respuestas.push_back("3");
	}
	else if (btnTres->Location.X == panelCuatro->Location.X && btnTres->Location.Y == panelCuatro->Location.Y) {
		respuestas.push_back("4");
	}

	if (btnCuatro->Location.X == panelUno->Location.X && btnCuatro->Location.Y == panelUno->Location.Y) {
		respuestas.push_back("1");	// Posicion 1
	}
	else if (btnCuatro->Location.X == panelDos->Location.X && btnCuatro->Location.Y == panelDos->Location.Y) {
		respuestas.push_back("2");
	}
	else if (btnCuatro->Location.X == panelTres->Location.X && btnCuatro->Location.Y == panelTres->Location.Y) {
		respuestas.push_back("3");
	}
	else if (btnCuatro->Location.X == panelCuatro->Location.X && btnCuatro->Location.Y == panelCuatro->Location.Y) {
		respuestas.push_back("4");
	}

	msclr::interop::marshal_context context;
	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Dificil", "Intermedia", 1);
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
	manejadorBD->setNombreHabilidad("Conciencia_alfabetica");
	manejadorBD->setDificultad("Dificil");
	manejadorBD->setComplejidad("Intermedia");
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
System::Void TutIntV30::Act2UnoDI::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act2UnoDI::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act2UnoDI::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act2UnoDI::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act2UnoDI::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act2UnoDI::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act2UnoDI::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act2UnoDI::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
	//sonidoInicial();
	this->contAyuda++;
	if (this->instruccion1->Visible == true) {
		this->instruccion1->Visible = false;
		this->instruccion2->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad2/Nivel Dificil/Complejidad intermedia/ND_CI_voz2.wav"), NULL, SND_ASYNC);
	}
	else if (this->instruccion2->Visible == true) {
		this->instruccion2->Visible = false;
		this->instruccion1->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad2/Nivel Dificil/Complejidad intermedia/ND_CI_voz1.wav"), NULL, SND_ASYNC);
	}

}
System::Void TutIntV30::Act2UnoDI::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act2UnoDI::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act2UnoDI::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act2UnoDI::Act2UnoDI_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Oceano/Habilidad2/Nivel Dificil/Complejidad intermedia/ND_CI_voz1.wav"), NULL, SND_ASYNC);
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
System::Void TutIntV30::Act2UnoDI::Act2UnoDI_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act2UnoDI::Act2UnoDI_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act2UnoDI::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoBtn)
{
	if (listoBtn == true) {
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
System::Void TutIntV30::Act2UnoDI::moverBoton(System::Windows::Forms::Button^ boton) {
	boton->Location = System::Drawing::Point(posMouseFormX - posMouseBtnX, posMouseFormY - posMouseBtnY);
	posActBtnX = boton->Location.X;
	posActBtnY = boton->Location.Y;
}
System::Void TutIntV30::Act2UnoDI::btnUno_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
}
System::Void TutIntV30::Act2UnoDI::btnDos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
}
System::Void TutIntV30::Act2UnoDI::btnTres_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
}
System::Void TutIntV30::Act2UnoDI::btnCuatro_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
}
System::Void TutIntV30::Act2UnoDI::btnUno_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	int x = btnUno->Location.X;
	int y = btnUno->Location.Y;
	if (x > panelUno->Location.X && x < panelUno->Location.X + panelUno->Size.Width && y > panelUno->Location.Y && y < panelUno->Location.Y + panelUno->Size.Height) {
		if (btnDos->Location != panelUno->Location && btnTres->Location != panelUno->Location && btnCuatro->Location != panelUno->Location) {
			btnUno->Location = System::Drawing::Point(panelUno->Location.X, panelUno->Location.Y);
			listoBtn1 = true;
			tiempo_respuesta(1, t_item1, listoBtn1);
		}
		else {
			btnUno->Location = System::Drawing::Point(xbtn1, ybtn1);
			listoBtn1 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelDos->Location.X && x < panelDos->Location.X + panelDos->Size.Width && y > panelDos->Location.Y && y < panelDos->Location.Y + panelDos->Size.Height) {
		if (btnDos->Location != panelDos->Location && btnTres->Location != panelDos->Location && btnCuatro->Location != panelDos->Location) {
			btnUno->Location = System::Drawing::Point(panelDos->Location.X, panelDos->Location.Y);
			listoBtn1 = true;
			tiempo_respuesta(1, t_item1, listoBtn1);
		}
		else {
			btnUno->Location = System::Drawing::Point(xbtn1, ybtn1);
			listoBtn1 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelTres->Location.X && x < panelTres->Location.X + panelTres->Size.Width && y > panelTres->Location.Y && y < panelTres->Location.Y + panelTres->Size.Height) {
		if (btnDos->Location != panelTres->Location && btnTres->Location != panelTres->Location && btnCuatro->Location != panelTres->Location) {
			btnUno->Location = System::Drawing::Point(panelTres->Location.X, panelTres->Location.Y);
			listoBtn1 = true;
			tiempo_respuesta(1, t_item1, listoBtn1);
		}
		else {
			btnUno->Location = System::Drawing::Point(xbtn1, ybtn1);
			listoBtn1 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelCuatro->Location.X && x < panelCuatro->Location.X + panelCuatro->Size.Width && y > panelCuatro->Location.Y && y < panelCuatro->Location.Y + panelCuatro->Size.Height) {
		if (btnDos->Location != panelCuatro->Location && btnTres->Location != panelCuatro->Location && btnCuatro->Location != panelCuatro->Location) {
			btnUno->Location = System::Drawing::Point(panelCuatro->Location.X, panelCuatro->Location.Y);
			listoBtn1 = true;
			tiempo_respuesta(1, t_item1, listoBtn1);
		}
		else {
			btnUno->Location = System::Drawing::Point(xbtn1, ybtn1);
			listoBtn1 = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btnUno->Location = System::Drawing::Point(xbtn1, ybtn1);
		listoBtn1 = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoDI::btnDos_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	int x = btnDos->Location.X;
	int y = btnDos->Location.Y;
	if (x > panelUno->Location.X && x < panelUno->Location.X + panelUno->Size.Width && y > panelUno->Location.Y && y < panelUno->Location.Y + panelUno->Size.Height) {
		if (btnUno->Location != panelUno->Location && btnTres->Location != panelUno->Location && btnCuatro->Location != panelUno->Location) {
			btnDos->Location = System::Drawing::Point(panelUno->Location.X, panelUno->Location.Y);
			listoBtn2 = true;
			tiempo_respuesta(2, t_item2, listoBtn2);
		}
		else {
			btnDos->Location = System::Drawing::Point(xbtn2, ybtn2);
			listoBtn2 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelDos->Location.X && x < panelDos->Location.X + panelDos->Size.Width && y > panelDos->Location.Y && y < panelDos->Location.Y + panelDos->Size.Height) {
		if (btnUno->Location != panelDos->Location && btnTres->Location != panelDos->Location && btnCuatro->Location != panelDos->Location) {
			btnDos->Location = System::Drawing::Point(panelDos->Location.X, panelDos->Location.Y);
			listoBtn2 = true;
			tiempo_respuesta(2, t_item2, listoBtn2);
		}
		else {
			btnDos->Location = System::Drawing::Point(xbtn2, ybtn2);
			listoBtn2 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelTres->Location.X && x < panelTres->Location.X + panelTres->Size.Width && y > panelTres->Location.Y && y < panelTres->Location.Y + panelTres->Size.Height) {
		if (btnUno->Location != panelTres->Location && btnTres->Location != panelTres->Location && btnCuatro->Location != panelTres->Location) {
			btnDos->Location = System::Drawing::Point(panelTres->Location.X, panelTres->Location.Y);
			listoBtn2 = true;
			tiempo_respuesta(2, t_item2, listoBtn2);
		}
		else {
			btnDos->Location = System::Drawing::Point(xbtn2, ybtn2);
			listoBtn2 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelCuatro->Location.X && x < panelCuatro->Location.X + panelCuatro->Size.Width && y > panelCuatro->Location.Y && y < panelCuatro->Location.Y + panelCuatro->Size.Height) {
		if (btnUno->Location != panelCuatro->Location && btnTres->Location != panelCuatro->Location && btnCuatro->Location != panelCuatro->Location) {
			btnDos->Location = System::Drawing::Point(panelCuatro->Location.X, panelCuatro->Location.Y);
			listoBtn2 = true;
			tiempo_respuesta(2, t_item2, listoBtn2);
		}
		else {
			btnDos->Location = System::Drawing::Point(xbtn2, ybtn2);
			listoBtn2 = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btnDos->Location = System::Drawing::Point(xbtn2, ybtn2);
		listoBtn2 = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoDI::btnTres_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	int x = btnTres->Location.X;
	int y = btnTres->Location.Y;
	if (x > panelUno->Location.X && x < panelUno->Location.X + panelUno->Size.Width && y > panelUno->Location.Y && y < panelUno->Location.Y + panelUno->Size.Height) {
		if (btnUno->Location != panelUno->Location && btnDos->Location != panelUno->Location && btnCuatro->Location != panelUno->Location) {
			btnTres->Location = System::Drawing::Point(panelUno->Location.X, panelUno->Location.Y);
			listoBtn3 = true;
			tiempo_respuesta(3, t_item3, listoBtn3);
		}
		else {
			btnTres->Location = System::Drawing::Point(xbtn3, ybtn3);
			listoBtn3 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelDos->Location.X && x < panelDos->Location.X + panelDos->Size.Width && y > panelDos->Location.Y && y < panelDos->Location.Y + panelDos->Size.Height) {
		if (btnUno->Location != panelDos->Location && btnDos->Location != panelDos->Location && btnCuatro->Location != panelDos->Location) {
			btnTres->Location = System::Drawing::Point(panelDos->Location.X, panelDos->Location.Y);
			listoBtn3 = true;
			tiempo_respuesta(3, t_item3, listoBtn3);
		}
		else {
			btnTres->Location = System::Drawing::Point(xbtn3, ybtn3);
			listoBtn3 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelTres->Location.X && x < panelTres->Location.X + panelTres->Size.Width && y > panelTres->Location.Y && y < panelTres->Location.Y + panelTres->Size.Height) {
		if (btnUno->Location != panelTres->Location && btnDos->Location != panelTres->Location && btnCuatro->Location != panelTres->Location) {
			btnTres->Location = System::Drawing::Point(panelTres->Location.X, panelTres->Location.Y);
			listoBtn3 = true;
			tiempo_respuesta(3, t_item3, listoBtn3);
		}
		else {
			btnTres->Location = System::Drawing::Point(xbtn3, ybtn3);
			listoBtn3 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelCuatro->Location.X && x < panelCuatro->Location.X + panelCuatro->Size.Width && y > panelCuatro->Location.Y && y < panelCuatro->Location.Y + panelCuatro->Size.Height) {
		if (btnUno->Location != panelCuatro->Location && btnDos->Location != panelCuatro->Location && btnCuatro->Location != panelCuatro->Location) {
			btnTres->Location = System::Drawing::Point(panelCuatro->Location.X, panelCuatro->Location.Y);
			listoBtn3 = true;
			tiempo_respuesta(3, t_item3, listoBtn3);
		}
		else {
			btnTres->Location = System::Drawing::Point(xbtn3, ybtn3);
			listoBtn3 = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btnTres->Location = System::Drawing::Point(xbtn3, ybtn3);
		listoBtn3 = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoDI::btnCuatro_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	int x = btnCuatro->Location.X;
	int y = btnCuatro->Location.Y;
	if (x > panelUno->Location.X && x < panelUno->Location.X + panelUno->Size.Width && y > panelUno->Location.Y && y < panelUno->Location.Y + panelUno->Size.Height) {
		if (btnUno->Location != panelUno->Location && btnDos->Location != panelUno->Location && btnTres->Location != panelUno->Location) {
			btnCuatro->Location = System::Drawing::Point(panelUno->Location.X, panelUno->Location.Y);
			listoBtn4 = true;
			tiempo_respuesta(4, t_item4, listoBtn4);
		}
		else {
			btnCuatro->Location = System::Drawing::Point(xbtn4, ybtn4);
			listoBtn4 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelDos->Location.X && x < panelDos->Location.X + panelDos->Size.Width && y > panelDos->Location.Y && y < panelDos->Location.Y + panelDos->Size.Height) {
		if (btnUno->Location != panelDos->Location && btnDos->Location != panelDos->Location && btnTres->Location != panelDos->Location) {
			btnCuatro->Location = System::Drawing::Point(panelDos->Location.X, panelDos->Location.Y);
			listoBtn4 = true;
			tiempo_respuesta(4, t_item4, listoBtn4);
		}
		else {
			btnCuatro->Location = System::Drawing::Point(xbtn4, ybtn4);
			listoBtn4 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelTres->Location.X && x < panelTres->Location.X + panelTres->Size.Width && y > panelTres->Location.Y && y < panelTres->Location.Y + panelTres->Size.Height) {
		if (btnUno->Location != panelTres->Location && btnDos->Location != panelTres->Location && btnTres->Location != panelTres->Location) {
			btnCuatro->Location = System::Drawing::Point(panelTres->Location.X, panelTres->Location.Y);
			listoBtn4 = true;
			tiempo_respuesta(4, t_item4, listoBtn4);
		}
		else {
			btnCuatro->Location = System::Drawing::Point(xbtn4, ybtn4);
			listoBtn4 = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panelCuatro->Location.X && x < panelCuatro->Location.X + panelCuatro->Size.Width && y > panelCuatro->Location.Y && y < panelCuatro->Location.Y + panelCuatro->Size.Height) {
		if (btnUno->Location != panelCuatro->Location && btnDos->Location != panelCuatro->Location && btnTres->Location != panelCuatro->Location) {
			btnCuatro->Location = System::Drawing::Point(panelCuatro->Location.X, panelCuatro->Location.Y);
			listoBtn4 = true;
			tiempo_respuesta(4, t_item4, listoBtn4);
		}
		else {
			btnCuatro->Location = System::Drawing::Point(xbtn4, ybtn4);
			listoBtn4 = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btnCuatro->Location = System::Drawing::Point(xbtn4, ybtn4);
		listoBtn4 = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoDI::btnUno_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btnUno);
	}
}
System::Void TutIntV30::Act2UnoDI::btnDos_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btnDos);
	}
}
System::Void TutIntV30::Act2UnoDI::btnTres_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btnTres);
	}
}
System::Void TutIntV30::Act2UnoDI::btnCuatro_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btnCuatro);
	}
}
