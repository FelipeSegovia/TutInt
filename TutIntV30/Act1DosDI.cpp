#include "Act1DosDI.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act1DosDI::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void TutIntV30::Act1DosDI::inicializarPosiciones() {
	xbtn1MAR = btn1MAR->Location.X;		ybtn1MAR = btn1MAR->Location.Y;
	xbtn1CA = btn1CA->Location.X;		ybtn1CA = btn1CA->Location.Y;
	xbtn1LA = btn1LA->Location.X;		ybtn1LA = btn1LA->Location.Y;
	xbtn2DU = btn2DU->Location.X;		ybtn2DU = btn2DU->Location.Y;
	xbtn2SA = btn2SA->Location.X;		ybtn2SA = btn2SA->Location.Y;
	xbtn2ME = btn2ME->Location.X;		ybtn2ME = btn2ME->Location.Y;
	xbtn3NA = btn3NA->Location.X;		ybtn3NA = btn3NA->Location.Y;
	xbtn3RE = btn3RE->Location.X;		ybtn3RE = btn3RE->Location.Y;
	xbtn3SI = btn3SI->Location.X;		ybtn3SI = btn3SI->Location.Y;
	xbtn4JAS = btn4JAS->Location.X;		ybtn4JAS = btn4JAS->Location.Y;
	xbtn4ES = btn4ES->Location.X;		ybtn4ES = btn4ES->Location.Y;
	xbtn4PON = btn4PON->Location.X;		ybtn4PON = btn4PON->Location.Y;
}
System::Void TutIntV30::Act1DosDI::comprobarRespuestas() {
	if (listoBtn1MAR == true && listoBtn1CA == true && listoBtn1LA == true && listoBtn2DU == true && listoBtn2SA == true && listoBtn2ME == true &&
		listoBtn3NA == true && listoBtn3RE == true && listoBtn3SI == true && listoBtn4JAS == true && listoBtn4ES == true && listoBtn4PON == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act1DosDI::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act1DosDI::obtenerTiempoItems() {
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
System::Void TutIntV30::Act1DosDI::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;
	msclr::interop::marshal_context context;

	vector<int> locationPanelUno;
	locationPanelUno.push_back(panel1Uno->Location.X);
	locationPanelUno.push_back(panel1Uno->Location.Y);
	locationPanelUno.push_back(panel1Dos->Location.X);
	locationPanelUno.push_back(panel1Dos->Location.Y);
	locationPanelUno.push_back(panel1Tres->Location.X);
	locationPanelUno.push_back(panel1Tres->Location.Y);

	String^ palabraUno = nullptr;
	int cont = 0;
	while (cont < 6) {
		int y = cont++;
		if (btn1MAR->Location.X == locationPanelUno[y] && btn1MAR->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1MAR->Text;
		}
		else if (btn1CA->Location.X == locationPanelUno[y] && btn1CA->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1CA->Text;
		}
		else if (btn1LA->Location.X == locationPanelUno[y] && btn1LA->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1LA->Text;
		}
		cont++;
	}
	string string1 = context.marshal_as<std::string>(palabraUno);
	respuestas.push_back(string1);
	string1.clear();

	vector<int> locationPanelDos;
	locationPanelDos.push_back(panel2Uno->Location.X);
	locationPanelDos.push_back(panel2Uno->Location.Y);
	locationPanelDos.push_back(panel2Dos->Location.X);
	locationPanelDos.push_back(panel2Dos->Location.Y);
	locationPanelDos.push_back(panel2Tres->Location.X);
	locationPanelDos.push_back(panel2Tres->Location.Y);

	String^ palabraDos = nullptr;
	cont = 0;
	while (cont < 6) {
		int i = cont++;
		if (btn2SA->Location.X == locationPanelDos[i] && btn2SA->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2SA->Text;
		}
		else if (btn2ME->Location.X == locationPanelDos[i] && btn2ME->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2ME->Text;
		}
		else if (btn2DU->Location.X == locationPanelDos[i] && btn2DU->Location.Y == locationPanelDos[cont]) {
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
		if (btn3SI->Location.X == locationPanelTres[x] && btn3SI->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3SI->Text;
		}
		else if (btn3RE->Location.X == locationPanelTres[x] && btn3RE->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3RE->Text;
		}
		else if (btn3NA->Location.X == locationPanelTres[x] && btn3NA->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3NA->Text;
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
		if (btn4PON->Location.X == locationPanelCuatro[j] && btn4PON->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4PON->Text;
		}
		else if (btn4ES->Location.X == locationPanelCuatro[j] && btn4ES->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4ES->Text;
		}
		else if (btn4JAS->Location.X == locationPanelCuatro[j] && btn4JAS->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + "RON";
		}
		cont++;
	}
	string string4 = context.marshal_as<std::string>(palabraCuatro);
	respuestas.push_back(string4);
	string4.clear();

	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Dificil", "Intermedia", 2);
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
System::Void TutIntV30::Act1DosDI::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act1DosDI::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act1DosDI::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act1DosDI::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act1DosDI::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act1DosDI::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act1DosDI::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act1DosDI::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
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
System::Void TutIntV30::Act1DosDI::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act1DosDI::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act1DosDI::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act1DosDI::Act1DosDI_Load(System::Object^  sender, System::EventArgs^  e) {
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
System::Void TutIntV30::Act1DosDI::Act1DosDI_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act1DosDI::Act1DosDI_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act1DosDI::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos, bool listoTres)
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
System::Void TutIntV30::Act1DosDI::moverBoton(System::Windows::Forms::Button^ boton) {
	boton->Location = System::Drawing::Point(posMouseFormX - posMouseBtnX, posMouseFormY - posMouseBtnY);
	posActBtnX = boton->Location.X;
	posActBtnY = boton->Location.Y;
}
System::Void TutIntV30::Act1DosDI::btn1MAR_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1MAR->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1DosDI::btn1CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1CA->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1DosDI::btn1LA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1LA->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1DosDI::btn2DU_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2DU->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1DosDI::btn2SA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2SA->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1DosDI::btn2ME_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2ME->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1DosDI::btn3NA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3NA->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDI::btn3RE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3RE->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDI::btn3SI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3SI->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDI::btn4JAS_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4JAS->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1DosDI::btn4ES_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4ES->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1DosDI::btn4PON_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4PON->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1DosDI::btn1MAR_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1MAR->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1MAR->Location.X;
	int y = btn1MAR->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1CA->Location != panel1Uno->Location && btn1LA->Location != panel1Uno->Location) {
			btn1MAR->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1MAR = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1MAR->Location = System::Drawing::Point(xbtn1MAR, ybtn1MAR);
			listoBtn1MAR = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1CA->Location != panel1Dos->Location && btn1LA->Location != panel1Dos->Location) {
			btn1MAR->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1MAR = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1MAR->Location = System::Drawing::Point(xbtn1MAR, ybtn1MAR);
			listoBtn1MAR = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1CA->Location != panel1Tres->Location && btn1LA->Location != panel1Tres->Location) {
			btn1MAR->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1MAR = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1MAR->Location = System::Drawing::Point(xbtn1MAR, ybtn1MAR);
			listoBtn1MAR = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1MAR->Location = System::Drawing::Point(xbtn1MAR, ybtn1MAR);
		listoBtn1MAR = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn1CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1CA->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1CA->Location.X;
	int y = btn1CA->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1MAR->Location != panel1Uno->Location && btn1LA->Location != panel1Uno->Location) {
			btn1CA->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1CA = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1CA->Location = System::Drawing::Point(xbtn1CA, ybtn1CA);
			listoBtn1CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1MAR->Location != panel1Dos->Location && btn1LA->Location != panel1Dos->Location) {
			btn1CA->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1CA = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1CA->Location = System::Drawing::Point(xbtn1CA, ybtn1CA);
			listoBtn1CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1MAR->Location != panel1Tres->Location && btn1LA->Location != panel1Tres->Location) {
			btn1CA->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1CA = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1CA->Location = System::Drawing::Point(xbtn1CA, ybtn1CA);
			listoBtn1CA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1CA->Location = System::Drawing::Point(xbtn1CA, ybtn1CA);
		listoBtn1CA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn1LA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1LA->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1LA->Location.X;
	int y = btn1LA->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1MAR->Location != panel1Uno->Location && btn1CA->Location != panel1Uno->Location) {
			btn1LA->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1LA = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1LA->Location = System::Drawing::Point(xbtn1LA, ybtn1LA);
			listoBtn1LA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1MAR->Location != panel1Dos->Location && btn1CA->Location != panel1Dos->Location) {
			btn1LA->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1LA = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1LA->Location = System::Drawing::Point(xbtn1LA, ybtn1LA);
			listoBtn1LA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1MAR->Location != panel1Tres->Location && btn1CA->Location != panel1Tres->Location) {
			btn1LA->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1LA = true;
			tiempo_respuesta(1, t_item1, listoBtn1MAR, listoBtn1CA, listoBtn1LA);
		}
		else {
			btn1LA->Location = System::Drawing::Point(xbtn1LA, ybtn1LA);
			listoBtn1LA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1LA->Location = System::Drawing::Point(xbtn1LA, ybtn1LA);
		listoBtn1LA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn2DU_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2DU->BackColor = System::Drawing::Color::Teal;
	int x = btn2DU->Location.X;
	int y = btn2DU->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2SA->Location != panel2Uno->Location && btn2ME->Location != panel2Uno->Location) {
			btn2DU->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2DU = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2DU->Location = System::Drawing::Point(xbtn2DU, ybtn2DU);
			listoBtn2DU = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2SA->Location != panel2Dos->Location && btn2ME->Location != panel2Dos->Location) {
			btn2DU->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2DU = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2DU->Location = System::Drawing::Point(xbtn2DU, ybtn2DU);
			listoBtn2DU = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2SA->Location != panel2Tres->Location && btn2ME->Location != panel2Tres->Location) {
			btn2DU->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2DU = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2DU->Location = System::Drawing::Point(xbtn2DU, ybtn2DU);
			listoBtn2DU = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2DU->Location = System::Drawing::Point(xbtn2DU, ybtn2DU);
		listoBtn2DU = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn2SA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2SA->BackColor = System::Drawing::Color::Teal;
	int x = btn2SA->Location.X;
	int y = btn2SA->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2DU->Location != panel2Uno->Location && btn2ME->Location != panel2Uno->Location) {
			btn2SA->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2SA = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2SA->Location = System::Drawing::Point(xbtn2SA, ybtn2SA);
			listoBtn2SA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2DU->Location != panel2Dos->Location && btn2ME->Location != panel2Dos->Location) {
			btn2SA->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2SA = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2SA->Location = System::Drawing::Point(xbtn2SA, ybtn2SA);
			listoBtn2SA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2DU->Location != panel2Tres->Location && btn2ME->Location != panel2Tres->Location) {
			btn2SA->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2SA = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2SA->Location = System::Drawing::Point(xbtn2SA, ybtn2SA);
			listoBtn2SA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2SA->Location = System::Drawing::Point(xbtn2SA, ybtn2SA);
		listoBtn2SA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn2ME_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2ME->BackColor = System::Drawing::Color::Teal;
	int x = btn2ME->Location.X;
	int y = btn2ME->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2DU->Location != panel2Uno->Location && btn2SA->Location != panel2Uno->Location) {
			btn2ME->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2ME = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2ME->Location = System::Drawing::Point(xbtn2ME, ybtn2ME);
			listoBtn2ME = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2DU->Location != panel2Dos->Location && btn2SA->Location != panel2Dos->Location) {
			btn2ME->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2ME = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2ME->Location = System::Drawing::Point(xbtn2ME, ybtn2ME);
			listoBtn2ME = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2DU->Location != panel2Tres->Location && btn2SA->Location != panel2Tres->Location) {
			btn2ME->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2ME = true;
			tiempo_respuesta(2, t_item2, listoBtn2DU, listoBtn2SA, listoBtn2ME);
		}
		else {
			btn2ME->Location = System::Drawing::Point(xbtn2ME, ybtn2ME);
			listoBtn2ME = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2ME->Location = System::Drawing::Point(xbtn2ME, ybtn2ME);
		listoBtn2ME = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn3NA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3NA->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3NA->Location.X;
	int y = btn3NA->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3RE->Location != panel3Uno->Location && btn3SI->Location != panel3Uno->Location) {
			btn3NA->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3NA = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3NA->Location = System::Drawing::Point(xbtn3NA, ybtn3NA);
			listoBtn3NA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3RE->Location != panel3Dos->Location && btn3SI->Location != panel3Dos->Location) {
			btn3NA->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3NA = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3NA->Location = System::Drawing::Point(xbtn3NA, ybtn3NA);
			listoBtn3NA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3RE->Location != panel3Tres->Location && btn3SI->Location != panel3Tres->Location) {
			btn3NA->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3NA = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3NA->Location = System::Drawing::Point(xbtn3NA, ybtn3NA);
			listoBtn3NA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3NA->Location = System::Drawing::Point(xbtn3NA, ybtn3NA);
		listoBtn3NA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn3RE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3RE->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3RE->Location.X;
	int y = btn3RE->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3NA->Location != panel3Uno->Location && btn3SI->Location != panel3Uno->Location) {
			btn3RE->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3RE = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3RE->Location = System::Drawing::Point(xbtn3RE, ybtn3RE);
			listoBtn3RE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3NA->Location != panel3Dos->Location && btn3SI->Location != panel3Dos->Location) {
			btn3RE->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3RE = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3RE->Location = System::Drawing::Point(xbtn3RE, ybtn3RE);
			listoBtn3RE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3NA->Location != panel3Tres->Location && btn3SI->Location != panel3Tres->Location) {
			btn3RE->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3RE = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3RE->Location = System::Drawing::Point(xbtn3RE, ybtn3RE);
			listoBtn3RE = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3RE->Location = System::Drawing::Point(xbtn3RE, ybtn3RE);
		listoBtn3RE = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn3SI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3SI->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3SI->Location.X;
	int y = btn3SI->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3NA->Location != panel3Uno->Location && btn3RE->Location != panel3Uno->Location) {
			btn3SI->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3SI = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3SI->Location = System::Drawing::Point(xbtn3SI, ybtn3SI);
			listoBtn3SI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3NA->Location != panel3Dos->Location && btn3RE->Location != panel3Dos->Location) {
			btn3SI->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3SI = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3SI->Location = System::Drawing::Point(xbtn3SI, ybtn3SI);
			listoBtn3SI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3NA->Location != panel3Tres->Location && btn3RE->Location != panel3Tres->Location) {
			btn3SI->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3SI = true;
			tiempo_respuesta(3, t_item3, listoBtn3RE, listoBtn3NA, listoBtn3SI);
		}
		else {
			btn3SI->Location = System::Drawing::Point(xbtn3SI, ybtn3SI);
			listoBtn3SI = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3SI->Location = System::Drawing::Point(xbtn3SI, ybtn3SI);
		listoBtn3SI = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn4JAS_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4JAS->BackColor = System::Drawing::Color::Olive;
	int x = btn4JAS->Location.X;
	int y = btn4JAS->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4ES->Location != panel4Uno->Location && btn4PON->Location != panel4Uno->Location) {
			btn4JAS->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4JAS = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4JAS->Location = System::Drawing::Point(xbtn4JAS, ybtn4JAS);
			listoBtn4JAS = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4ES->Location != panel4Dos->Location && btn4PON->Location != panel4Dos->Location) {
			btn4JAS->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4JAS = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4JAS->Location = System::Drawing::Point(xbtn4JAS, ybtn4JAS);
			listoBtn4JAS = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4ES->Location != panel4Tres->Location && btn4PON->Location != panel4Tres->Location) {
			btn4JAS->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4JAS = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4JAS->Location = System::Drawing::Point(xbtn4JAS, ybtn4JAS);
			listoBtn4JAS = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4JAS->Location = System::Drawing::Point(xbtn4JAS, ybtn4JAS);
		listoBtn4JAS = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn4ES_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4ES->BackColor = System::Drawing::Color::Olive;
	int x = btn4ES->Location.X;
	int y = btn4ES->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4JAS->Location != panel4Uno->Location && btn4PON->Location != panel4Uno->Location) {
			btn4ES->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4ES = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4ES->Location = System::Drawing::Point(xbtn4ES, ybtn4ES);
			listoBtn4ES = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4JAS->Location != panel4Dos->Location && btn4PON->Location != panel4Dos->Location) {
			btn4ES->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4ES = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4ES->Location = System::Drawing::Point(xbtn4ES, ybtn4ES);
			listoBtn4ES = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4JAS->Location != panel4Tres->Location && btn4PON->Location != panel4Tres->Location) {
			btn4ES->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4ES = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4ES->Location = System::Drawing::Point(xbtn4ES, ybtn4ES);
			listoBtn4ES = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4ES->Location = System::Drawing::Point(xbtn4ES, ybtn4ES);
		listoBtn4ES = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn4PON_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4PON->BackColor = System::Drawing::Color::Olive;
	int x = btn4PON->Location.X;
	int y = btn4PON->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4JAS->Location != panel4Uno->Location && btn4ES->Location != panel4Uno->Location) {
			btn4PON->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4PON = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4PON->Location = System::Drawing::Point(xbtn4PON, ybtn4PON);
			listoBtn4PON = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4JAS->Location != panel4Dos->Location && btn4ES->Location != panel4Dos->Location) {
			btn4PON->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4PON = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4PON->Location = System::Drawing::Point(xbtn4PON, ybtn4PON);
			listoBtn4PON = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4JAS->Location != panel4Tres->Location && btn4ES->Location != panel4Tres->Location) {
			btn4PON->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4PON = true;
			tiempo_respuesta(4, t_item4, listoBtn4ES, listoBtn4JAS, listoBtn4PON);
		}
		else {
			btn4PON->Location = System::Drawing::Point(xbtn4PON, ybtn4PON);
			listoBtn4PON = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4PON->Location = System::Drawing::Point(xbtn4PON, ybtn4PON);
		listoBtn4PON = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDI::btn1MAR_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1MAR);
	}
}
System::Void TutIntV30::Act1DosDI::btn1CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1CA);
	}
}
System::Void TutIntV30::Act1DosDI::btn1LA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1LA);
	}
}
System::Void TutIntV30::Act1DosDI::btn2DU_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2DU);
	}
}
System::Void TutIntV30::Act1DosDI::btn2SA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2SA);
	}
}
System::Void TutIntV30::Act1DosDI::btn2ME_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2ME);
	}
}
System::Void TutIntV30::Act1DosDI::btn3NA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3NA);
	}
}
System::Void TutIntV30::Act1DosDI::btn3RE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3RE);
	}
}
System::Void TutIntV30::Act1DosDI::btn3SI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3SI);
	}
}
System::Void TutIntV30::Act1DosDI::btn4JAS_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4JAS);
	}
}
System::Void TutIntV30::Act1DosDI::btn4ES_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4ES);
	}
}
System::Void TutIntV30::Act1DosDI::btn4PON_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4PON);
	}
}