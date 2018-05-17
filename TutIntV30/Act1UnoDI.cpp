#include "Act1UnoDI.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act1UnoDI::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void TutIntV30::Act1UnoDI::inicializarPosiciones() {
	xbtn1CHA = btn1CHA->Location.X;		ybtn1CHA = btn1CHA->Location.Y;
	xbtn1CON = btn1CON->Location.X;		ybtn1CON = btn1CON->Location.Y;
	xbtn2RON = btn2RON->Location.X;		ybtn2RON = btn2RON->Location.Y;
	xbtn2CA = btn2CA->Location.X;		ybtn2CA = btn2CA->Location.Y;
	xbtn2MA = btn2MA->Location.X;		ybtn2MA = btn2MA->Location.Y;
	xbtn3ME = btn3ME->Location.X;		ybtn3ME = btn3ME->Location.Y;
	xbtn3JA = btn3JA->Location.X;		ybtn3JA = btn3JA->Location.Y;
	xbtn3AL = btn3AL->Location.X;		ybtn3AL = btn3AL->Location.Y;
	xbtn4RON = btn4RON->Location.X;		ybtn4RON = btn4RON->Location.Y;
	xbtn4TI = btn4TI->Location.X;		ybtn4TI = btn4TI->Location.Y;
	xbtn4BU = btn4BU->Location.X;		ybtn4BU = btn4BU->Location.Y;
}
System::Void TutIntV30::Act1UnoDI::comprobarRespuestas() {
	if (listoBtn1CHA == true && listoBtn1CON == true && listoBtn2RON == true && listoBtn2CA == true && listoBtn2MA == true &&
		listoBtn3ME == true && listoBtn3JA == true && listoBtn3AL == true && listoBtn4RON == true && listoBtn4TI == true && listoBtn4BU == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act1UnoDI::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act1UnoDI::obtenerTiempoItems() {
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
System::Void TutIntV30::Act1UnoDI::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;
	msclr::interop::marshal_context context;

	if (btn1CHA->Location == panel1Uno->Location) {
		respuestas.push_back("CHACON");
	}
	else {
		respuestas.push_back("CONCHA");
	}

	vector<int> locationPanelDos;
	locationPanelDos.push_back(panel2Uno->Location.X);
	locationPanelDos.push_back(panel2Uno->Location.Y);
	locationPanelDos.push_back(panel2Dos->Location.X);
	locationPanelDos.push_back(panel2Dos->Location.Y);
	locationPanelDos.push_back(panel2Tres->Location.X);
	locationPanelDos.push_back(panel2Tres->Location.Y);

	String^ palabraDos = nullptr;
	int cont = 0;
	while (cont < 6) {
		int i = cont++;
		if (btn2CA->Location.X == locationPanelDos[i] && btn2CA->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2CA->Text;
		}
		else if (btn2MA->Location.X == locationPanelDos[i] && btn2MA->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2MA->Text;
		}
		else if (btn2RON->Location.X == locationPanelDos[i] && btn2RON->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + "RON";
		}
		cont++;
	}
	string string2 = context.marshal_as<std::string>(palabraDos);
	respuestas.push_back(string2);
	string2.clear();

	vector<int> locationPanelTres;
	locationPanelTres.push_back(panel3Uno->Location.X);
	locationPanelTres.push_back(panel3Uno->Location.Y);
	locationPanelTres.push_back(panel3Dos->Location.X);
	locationPanelTres.push_back(panel3Dos->Location.Y);
	locationPanelTres.push_back(panel3Tres->Location.X);
	locationPanelTres.push_back(panel3Tres->Location.Y);

	String^ palabraTres = nullptr;
	cont = 0;
	while (cont < 6) {
		int x = cont++;
		if (btn3AL->Location.X == locationPanelTres[x] && btn3AL->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3AL->Text;
		}
		else if (btn3JA->Location.X == locationPanelTres[x] && btn3JA->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3JA->Text;
		}
		else if (btn3ME->Location.X == locationPanelTres[x] && btn3ME->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3ME->Text;
		}
		cont++;
	}
	string string3 = context.marshal_as<std::string>(palabraTres);
	respuestas.push_back(string3);
	string3.clear();

	vector<int> locationPanelCuatro;
	locationPanelCuatro.push_back(panel4Uno->Location.X);
	locationPanelCuatro.push_back(panel4Uno->Location.Y);
	locationPanelCuatro.push_back(panel4Dos->Location.X);
	locationPanelCuatro.push_back(panel4Dos->Location.Y);
	locationPanelCuatro.push_back(panel4Tres->Location.X);
	locationPanelCuatro.push_back(panel4Tres->Location.Y);

	String^ palabraCuatro = nullptr;
	cont = 0;
	while (cont < 6) {
		int j = cont++;
		if (btn4BU->Location.X == locationPanelCuatro[j] && btn4BU->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4BU->Text;
		}
		else if (btn4TI->Location.X == locationPanelCuatro[j] && btn4TI->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4TI->Text;
		}
		else if (btn4RON->Location.X == locationPanelCuatro[j] && btn4RON->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + "RON";
		}
		cont++;
	}
	string string4 = context.marshal_as<std::string>(palabraCuatro);
	respuestas.push_back(string4);
	string4.clear();

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
	manejadorBD->setNombreHabilidad("Conciencia_fonologica");
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
System::Void TutIntV30::Act1UnoDI::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act1UnoDI::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act1UnoDI::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act1UnoDI::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act1UnoDI::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act1UnoDI::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act1UnoDI::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act1UnoDI::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
	//sonidoInicial();
	this->contAyuda++;
	if (this->instruccion1->Visible == true) {
		this->instruccion1->Visible = false;
		this->instruccion2->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad intermedia/NI_CI_voz2.wav"), NULL, SND_ASYNC);
	}
	else if (this->instruccion2->Visible == true) {
		this->instruccion2->Visible = false;
		this->instruccion1->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad intermedia/NI_CI_voz1.wav"), NULL, SND_ASYNC);
	}
}
System::Void TutIntV30::Act1UnoDI::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act1UnoDI::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act1UnoDI::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act1UnoDI::Act1UnoDI_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad intermedia/NI_CI_voz1.wav"), NULL, SND_ASYNC);
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
System::Void TutIntV30::Act1UnoDI::Act1UnoDI_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act1UnoDI::Act1UnoDI_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act1UnoDI::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos)
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
System::Void TutIntV30::Act1UnoDI::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos, bool listoTres)
{
	if (listoUno == true && listoDos == true && listoTres == true) {
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
System::Void TutIntV30::Act1UnoDI::moverBoton(System::Windows::Forms::Button^ boton) {
	boton->Location = System::Drawing::Point(posMouseFormX - posMouseBtnX, posMouseFormY - posMouseBtnY);
	posActBtnX = boton->Location.X;
	posActBtnY = boton->Location.Y;
}
System::Void TutIntV30::Act1UnoDI::btn1CHA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1CHA->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1UnoDI::btn1CON_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1CON->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1UnoDI::btn2RON_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2RON->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1UnoDI::btn2CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2CA->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1UnoDI::btn2MA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2MA->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1UnoDI::btn3ME_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3ME->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1UnoDI::btn3JA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3JA->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1UnoDI::btn3AL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3AL->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1UnoDI::btn4RON_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4RON->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1UnoDI::btn4TI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4TI->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1UnoDI::btn4BU_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4BU->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1UnoDI::btn1CHA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1CHA->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1CHA->Location.X;
	int y = btn1CHA->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1CON->Location != panel1Uno->Location) {
			btn1CHA->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1CHA = true;
			tiempo_respuesta(1, t_item1, listoBtn1CHA, listoBtn1CON);
		}
		else {
			btn1CHA->Location = System::Drawing::Point(xbtn1CHA, ybtn1CHA);
			listoBtn1CHA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1CON->Location != panel1Dos->Location) {
			btn1CHA->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1CHA = true;
			tiempo_respuesta(1, t_item1, listoBtn1CHA, listoBtn1CON);
		}
		else {
			btn1CHA->Location = System::Drawing::Point(xbtn1CHA, ybtn1CHA);
			listoBtn1CHA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1CHA->Location = System::Drawing::Point(xbtn1CHA, ybtn1CHA);
		listoBtn1CHA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn1CON_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1CON->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1CON->Location.X;
	int y = btn1CON->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1CHA->Location != panel1Uno->Location) {
			btn1CON->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1CON = true;
			tiempo_respuesta(1, t_item1, listoBtn1CHA, listoBtn1CON);
		}
		else {
			btn1CON->Location = System::Drawing::Point(xbtn1CON, ybtn1CON);
			listoBtn1CON = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1CHA->Location != panel1Dos->Location) {
			btn1CON->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1CON = true;
			tiempo_respuesta(1, t_item1, listoBtn1CHA, listoBtn1CON);
		}
		else {
			btn1CON->Location = System::Drawing::Point(xbtn1CON, ybtn1CON);
			listoBtn1CON = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1CON->Location = System::Drawing::Point(xbtn1CON, ybtn1CON);
		listoBtn1CON = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn2RON_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2RON->BackColor = System::Drawing::Color::Teal;
	int x = btn2RON->Location.X;
	int y = btn2RON->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2CA->Location != panel2Uno->Location && btn2MA->Location != panel2Uno->Location) {
			btn2RON->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2RON = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
		}
		else {
			btn2RON->Location = System::Drawing::Point(xbtn2RON, ybtn2RON);
			listoBtn2RON = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2CA->Location != panel2Dos->Location && btn2MA->Location != panel2Dos->Location) {
			btn2RON->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2RON = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
		}
		else {
			btn2RON->Location = System::Drawing::Point(xbtn2RON, ybtn2RON);
			listoBtn2RON = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2CA->Location != panel2Tres->Location && btn2MA->Location != panel2Tres->Location) {
			btn2RON->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2RON = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
		}
		else {
			btn2RON->Location = System::Drawing::Point(xbtn2RON, ybtn2RON);
			listoBtn2RON = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2RON->Location = System::Drawing::Point(xbtn2RON, ybtn2RON);
		listoBtn2RON = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn2CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2CA->BackColor = System::Drawing::Color::Teal;
	int x = btn2CA->Location.X;
	int y = btn2CA->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2RON->Location != panel2Uno->Location && btn2MA->Location != panel2Uno->Location) {
			btn2CA->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2CA = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
		}
		else {
			btn2CA->Location = System::Drawing::Point(xbtn2CA, ybtn2CA);
			listoBtn2CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2RON->Location != panel2Dos->Location && btn2MA->Location != panel2Dos->Location) {
			btn2CA->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2CA = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
		}
		else {
			btn2CA->Location = System::Drawing::Point(xbtn2CA, ybtn2CA);
			listoBtn2CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2RON->Location != panel2Tres->Location && btn2MA->Location != panel2Tres->Location) {
			btn2CA->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2CA = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
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
System::Void TutIntV30::Act1UnoDI::btn2MA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2MA->BackColor = System::Drawing::Color::Teal;
	int x = btn2MA->Location.X;
	int y = btn2MA->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2RON->Location != panel2Uno->Location && btn2CA->Location != panel2Uno->Location) {
			btn2MA->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2MA = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
		}
		else {
			btn2MA->Location = System::Drawing::Point(xbtn2MA, ybtn2MA);
			listoBtn2MA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2RON->Location != panel2Dos->Location && btn2CA->Location != panel2Dos->Location) {
			btn2MA->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2MA = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
		}
		else {
			btn2MA->Location = System::Drawing::Point(xbtn2MA, ybtn2MA);
			listoBtn2MA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2RON->Location != panel2Tres->Location && btn2CA->Location != panel2Tres->Location) {
			btn2MA->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2MA = true;
			tiempo_respuesta(2, t_item2, listoBtn2RON, listoBtn2CA, listoBtn2MA);
		}
		else {
			btn2MA->Location = System::Drawing::Point(xbtn2MA, ybtn2MA);
			listoBtn2MA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2MA->Location = System::Drawing::Point(xbtn2MA, ybtn2MA);
		listoBtn2MA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn3ME_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3ME->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3ME->Location.X;
	int y = btn3ME->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3JA->Location != panel3Uno->Location && btn3AL->Location != panel3Uno->Location) {
			btn3ME->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3ME = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3ME->Location = System::Drawing::Point(xbtn3ME, ybtn3ME);
			listoBtn3ME = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3JA->Location != panel3Dos->Location && btn3AL->Location != panel3Dos->Location) {
			btn3ME->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3ME = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3ME->Location = System::Drawing::Point(xbtn3ME, ybtn3ME);
			listoBtn3ME = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3JA->Location != panel3Tres->Location && btn3AL->Location != panel3Tres->Location) {
			btn3ME->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3ME = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3ME->Location = System::Drawing::Point(xbtn3ME, ybtn3ME);
			listoBtn3ME = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3ME->Location = System::Drawing::Point(xbtn3ME, ybtn3ME);
		listoBtn3ME = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn3JA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3JA->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3JA->Location.X;
	int y = btn3JA->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3ME->Location != panel3Uno->Location && btn3AL->Location != panel3Uno->Location) {
			btn3JA->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3JA = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3JA->Location = System::Drawing::Point(xbtn3JA, ybtn3JA);
			listoBtn3JA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3ME->Location != panel3Dos->Location && btn3AL->Location != panel3Dos->Location) {
			btn3JA->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3JA = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3JA->Location = System::Drawing::Point(xbtn3JA, ybtn3JA);
			listoBtn3JA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3ME->Location != panel3Tres->Location && btn3AL->Location != panel3Tres->Location) {
			btn3JA->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3JA = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3JA->Location = System::Drawing::Point(xbtn3JA, ybtn3JA);
			listoBtn3JA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3JA->Location = System::Drawing::Point(xbtn3JA, ybtn3JA);
		listoBtn3JA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn3AL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3AL->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3AL->Location.X;
	int y = btn3AL->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3ME->Location != panel3Uno->Location && btn3JA->Location != panel3Uno->Location) {
			btn3AL->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3AL = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3AL->Location = System::Drawing::Point(xbtn3AL, ybtn3AL);
			listoBtn3AL = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3ME->Location != panel3Dos->Location && btn3JA->Location != panel3Dos->Location) {
			btn3AL->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3AL = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3AL->Location = System::Drawing::Point(xbtn3AL, ybtn3AL);
			listoBtn3AL = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3ME->Location != panel3Tres->Location && btn3JA->Location != panel3Tres->Location) {
			btn3AL->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3AL = true;
			tiempo_respuesta(3, t_item3, listoBtn3JA, listoBtn3ME, listoBtn3AL);
		}
		else {
			btn3AL->Location = System::Drawing::Point(xbtn3AL, ybtn3AL);
			listoBtn3AL = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3AL->Location = System::Drawing::Point(xbtn3AL, ybtn3AL);
		listoBtn3AL = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn4RON_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4RON->BackColor = System::Drawing::Color::Olive;
	int x = btn4RON->Location.X;
	int y = btn4RON->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4TI->Location != panel4Uno->Location && btn4BU->Location != panel4Uno->Location) {
			btn4RON->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4RON = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4RON->Location = System::Drawing::Point(xbtn4RON, ybtn4RON);
			listoBtn4RON = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4TI->Location != panel4Dos->Location && btn4BU->Location != panel4Dos->Location) {
			btn4RON->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4RON = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4RON->Location = System::Drawing::Point(xbtn4RON, ybtn4RON);
			listoBtn4RON = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4TI->Location != panel4Tres->Location && btn4BU->Location != panel4Tres->Location) {
			btn4RON->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4RON = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4RON->Location = System::Drawing::Point(xbtn4RON, ybtn4RON);
			listoBtn4RON = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4RON->Location = System::Drawing::Point(xbtn4RON, ybtn4RON);
		listoBtn4RON = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn4TI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4TI->BackColor = System::Drawing::Color::Olive;
	int x = btn4TI->Location.X;
	int y = btn4TI->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4RON->Location != panel4Uno->Location && btn4BU->Location != panel4Uno->Location) {
			btn4TI->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4TI = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4TI->Location = System::Drawing::Point(xbtn4TI, ybtn4TI);
			listoBtn4TI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4RON->Location != panel4Dos->Location && btn4BU->Location != panel4Dos->Location) {
			btn4TI->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4TI = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4TI->Location = System::Drawing::Point(xbtn4TI, ybtn4TI);
			listoBtn4TI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4RON->Location != panel4Tres->Location && btn4BU->Location != panel4Tres->Location) {
			btn4TI->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4TI = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4TI->Location = System::Drawing::Point(xbtn4TI, ybtn4TI);
			listoBtn4TI = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4TI->Location = System::Drawing::Point(xbtn4TI, ybtn4TI);
		listoBtn4TI = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn4BU_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4BU->BackColor = System::Drawing::Color::Olive;
	int x = btn4BU->Location.X;
	int y = btn4BU->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4RON->Location != panel4Uno->Location && btn4TI->Location != panel4Uno->Location) {
			btn4BU->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4BU = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4BU->Location = System::Drawing::Point(xbtn4BU, ybtn4BU);
			listoBtn4BU = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4RON->Location != panel4Dos->Location && btn4TI->Location != panel4Dos->Location) {
			btn4BU->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4BU = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4BU->Location = System::Drawing::Point(xbtn4BU, ybtn4BU);
			listoBtn4BU = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4RON->Location != panel4Tres->Location && btn4TI->Location != panel4Tres->Location) {
			btn4BU->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4BU = true;
			tiempo_respuesta(4, t_item4, listoBtn4TI, listoBtn4RON, listoBtn4BU);
		}
		else {
			btn4BU->Location = System::Drawing::Point(xbtn4BU, ybtn4BU);
			listoBtn4BU = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4BU->Location = System::Drawing::Point(xbtn4BU, ybtn4BU);
		listoBtn4BU = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDI::btn1CHA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1CHA);
	}
}
System::Void TutIntV30::Act1UnoDI::btn1CON_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1CON);
	}
}
System::Void TutIntV30::Act1UnoDI::btn2RON_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2RON);
	}
}
System::Void TutIntV30::Act1UnoDI::btn2CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2CA);
	}
}
System::Void TutIntV30::Act1UnoDI::btn2MA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2MA);
	}
}
System::Void TutIntV30::Act1UnoDI::btn3ME_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3ME);
	}
}
System::Void TutIntV30::Act1UnoDI::btn3JA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3JA);
	}
}
System::Void TutIntV30::Act1UnoDI::btn3AL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3AL);
	}
}
System::Void TutIntV30::Act1UnoDI::btn4RON_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4RON);
	}
}
System::Void TutIntV30::Act1UnoDI::btn4TI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4TI);
	}
}
System::Void TutIntV30::Act1UnoDI::btn4BU_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4BU);
	}
}