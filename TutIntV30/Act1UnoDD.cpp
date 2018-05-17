#include "Act1UnoDD.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act1UnoDD::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
	wAyudaUno = this->ayudaUno->Size.Width;
	hAyudaUno = this->ayudaUno->Size.Height;
	wAyudaDos = this->ayudaDos->Size.Width;
	hAyudaDos = this->ayudaDos->Size.Height;
	wAyudaTres = this->ayudaTres->Size.Width;
	hAyudaTres = this->ayudaTres->Size.Height;
	wAyudaCuatro = this->ayudaCuatro->Size.Width;
	hAyudaCuatro = this->ayudaCuatro->Size.Height;
}
System::Void TutIntV30::Act1UnoDD::inicializarPosiciones() {
	xbtn1RA = btn1RA->Location.X;		ybtn1RA = btn1RA->Location.Y;
	xbtn1CA = btn1CA->Location.X;		ybtn1CA = btn1CA->Location.Y;
	xbtn1COL = btn1COL->Location.X;		ybtn1COL = btn1COL->Location.Y;
	xbtn2GUI = btn2GUI->Location.X;		ybtn2GUI = btn2GUI->Location.Y;
	xbtn2NO = btn2NO->Location.X;		ybtn2NO = btn2NO->Location.Y;
	xbtn2PIN = btn2PIN->Location.X;		ybtn2PIN = btn2PIN->Location.Y;
	xbtn3TRE = btn3TRE->Location.X;		ybtn3TRE = btn3TRE->Location.Y;
	xbtn3ES = btn3ES->Location.X;		ybtn3ES = btn3ES->Location.Y;
	xbtn3LLA = btn3LLA->Location.X;		ybtn3LLA = btn3LLA->Location.Y;
	xbtn4BA = btn4BA->Location.X;		ybtn4BA = btn4BA->Location.Y;
	xbtn4NA = btn4NA->Location.X;		ybtn4NA = btn4NA->Location.Y;
	xbtn4LLE = btn4LLE->Location.X;		ybtn4LLE = btn4LLE->Location.Y;
}
System::Void TutIntV30::Act1UnoDD::comprobarRespuestas() {
	if (listoBtn1RA == true && listoBtn1CA == true && listoBtn1COL == true && listoBtn2GUI == true && listoBtn2NO == true && listoBtn2PIN == true &&
		listoBtn3TRE == true && listoBtn3ES == true && listoBtn3LLA == true && listoBtn4BA == true && listoBtn4NA == true && listoBtn4LLE == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act1UnoDD::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act1UnoDD::obtenerTiempoItems() {
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
System::Void TutIntV30::Act1UnoDD::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
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
		if (btn1RA->Location.X == locationPanelUno[y] && btn1RA->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1RA->Text;
		}
		else if (btn1CA->Location.X == locationPanelUno[y] && btn1CA->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1CA->Text;
		}
		else if (btn1COL->Location.X == locationPanelUno[y] && btn1COL->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1COL->Text;
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
		if (btn2NO->Location.X == locationPanelDos[i] && btn2NO->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2NO->Text;
		}
		else if (btn2PIN->Location.X == locationPanelDos[i] && btn2PIN->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2PIN->Text;
		}
		else if (btn2GUI->Location.X == locationPanelDos[i] && btn2GUI->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + "GUI";
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
		if (btn3LLA->Location.X == locationPanelTres[x] && btn3LLA->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3LLA->Text;
		}
		else if (btn3ES->Location.X == locationPanelTres[x] && btn3ES->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3ES->Text;
		}
		else if (btn3TRE->Location.X == locationPanelTres[x] && btn3TRE->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3TRE->Text;
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
		if (btn4LLE->Location.X == locationPanelCuatro[j] && btn4LLE->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4LLE->Text;
		}
		else if (btn4NA->Location.X == locationPanelCuatro[j] && btn4NA->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4NA->Text;
		}
		else if (btn4BA->Location.X == locationPanelCuatro[j] && btn4BA->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4BA->Text;
		}
		cont++;
	}
	string string4 = context.marshal_as<std::string>(palabraCuatro);
	respuestas.push_back(string4);
	string4.clear();

	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Dificil", "Dificil", 1);
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
System::Void TutIntV30::Act1UnoDD::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act1UnoDD::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act1UnoDD::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act1UnoDD::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act1UnoDD::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act1UnoDD::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act1UnoDD::ayudaUno_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaUno->Size = System::Drawing::Size(wAyudaUno + 5, hAyudaUno + 5);
}
System::Void TutIntV30::Act1UnoDD::ayudaUno_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaUno->Size = System::Drawing::Size(wAyudaUno, hAyudaUno);
}
System::Void TutIntV30::Act1UnoDD::ayudaDos_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaDos->Size = System::Drawing::Size(wAyudaDos + 5, hAyudaDos + 5);
}
System::Void TutIntV30::Act1UnoDD::ayudaDos_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaDos->Size = System::Drawing::Size(wAyudaDos, hAyudaDos);
}
System::Void TutIntV30::Act1UnoDD::ayudaTres_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaTres->Size = System::Drawing::Size(wAyudaTres + 5, hAyudaTres + 5);
}
System::Void TutIntV30::Act1UnoDD::ayudaTres_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaTres->Size = System::Drawing::Size(wAyudaTres, hAyudaTres);
}
System::Void TutIntV30::Act1UnoDD::ayudaCuatro_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaCuatro->Size = System::Drawing::Size(wAyudaCuatro + 5, hAyudaCuatro + 5);
}
System::Void TutIntV30::Act1UnoDD::ayudaCuatro_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaCuatro->Size = System::Drawing::Size(wAyudaCuatro, hAyudaCuatro);
}
System::Void TutIntV30::Act1UnoDD::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act1UnoDD::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
	//sonidoInicial();
	this->contAyuda++;
	if (this->instruccion1->Visible == true) {
		this->instruccion1->Visible = false;
		this->instruccion2->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad dificil/NI_CD_voz2.wav"), NULL, SND_ASYNC);

	}
	else if (this->instruccion2->Visible == true) {
		this->instruccion2->Visible = false;
		this->instruccion1->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad dificil/NI_CD_voz1.wav"), NULL, SND_ASYNC);
	}
}
System::Void TutIntV30::Act1UnoDD::ayudaUno_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaUno->Visible = false;
	this->pictureBox1->Visible = true;
	this->contAyuda++;
}
System::Void TutIntV30::Act1UnoDD::ayudaDos_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaDos->Visible = false;
	this->pictureBox2->Visible = true;
	this->contAyuda++;
}
System::Void TutIntV30::Act1UnoDD::ayudaTres_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaTres->Visible = false;
	this->pictureBox4->Visible = true;
	this->contAyuda++;
}
System::Void TutIntV30::Act1UnoDD::ayudaCuatro_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaCuatro->Visible = false;
	this->pictureBox3->Visible = true;
	this->contAyuda++;
}
System::Void TutIntV30::Act1UnoDD::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act1UnoDD::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act1UnoDD::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act1UnoDD::Act1UnoDD_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad dificil/NI_CD_voz1.wav"), NULL, SND_ASYNC);
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
System::Void TutIntV30::Act1UnoDD::Act1UnoDD_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act1UnoDD::Act1UnoDD_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act1UnoDD::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos, bool listoTres)
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
System::Void TutIntV30::Act1UnoDD::moverBoton(System::Windows::Forms::Button^ boton) {
	boton->Location = System::Drawing::Point(posMouseFormX - posMouseBtnX, posMouseFormY - posMouseBtnY);
	posActBtnX = boton->Location.X;
	posActBtnY = boton->Location.Y;
}
System::Void TutIntV30::Act1UnoDD::btn1RA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1RA->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1UnoDD::btn1CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1CA->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1UnoDD::btn1COL_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1COL->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1UnoDD::btn2GUI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2GUI->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1UnoDD::btn2NO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2NO->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1UnoDD::btn2PIN_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2PIN->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1UnoDD::btn3TRE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3TRE->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1UnoDD::btn3ES_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3ES->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1UnoDD::btn3LLA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3LLA->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1UnoDD::btn4BA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4BA->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1UnoDD::btn4NA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4NA->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1UnoDD::btn4LLE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4LLE->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1UnoDD::btn1RA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1RA->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1RA->Location.X;
	int y = btn1RA->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1CA->Location != panel1Uno->Location && btn1COL->Location != panel1Uno->Location) {
			btn1RA->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1RA = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
		}
		else {
			btn1RA->Location = System::Drawing::Point(xbtn1RA, ybtn1RA);
			listoBtn1RA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1CA->Location != panel1Dos->Location && btn1COL->Location != panel1Dos->Location) {
			btn1RA->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1RA = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
		}
		else {
			btn1RA->Location = System::Drawing::Point(xbtn1RA, ybtn1RA);
			listoBtn1RA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1CA->Location != panel1Tres->Location && btn1COL->Location != panel1Tres->Location) {
			btn1RA->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1RA = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
		}
		else {
			btn1RA->Location = System::Drawing::Point(xbtn1RA, ybtn1RA);
			listoBtn1RA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1RA->Location = System::Drawing::Point(xbtn1RA, ybtn1RA);
		listoBtn1RA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn1CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1CA->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1CA->Location.X;
	int y = btn1CA->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1RA->Location != panel1Uno->Location && btn1COL->Location != panel1Uno->Location) {
			btn1CA->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1CA = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
		}
		else {
			btn1CA->Location = System::Drawing::Point(xbtn1CA, ybtn1CA);
			listoBtn1CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1RA->Location != panel1Dos->Location && btn1COL->Location != panel1Dos->Location) {
			btn1CA->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1CA = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
		}
		else {
			btn1CA->Location = System::Drawing::Point(xbtn1CA, ybtn1CA);
			listoBtn1CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1RA->Location != panel1Tres->Location && btn1COL->Location != panel1Tres->Location) {
			btn1CA->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1CA = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
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
System::Void TutIntV30::Act1UnoDD::btn1COL_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1COL->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1COL->Location.X;
	int y = btn1COL->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1RA->Location != panel1Uno->Location && btn1CA->Location != panel1Uno->Location) {
			btn1COL->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1COL = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
		}
		else {
			btn1COL->Location = System::Drawing::Point(xbtn1COL, ybtn1COL);
			listoBtn1COL = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1RA->Location != panel1Dos->Location && btn1CA->Location != panel1Dos->Location) {
			btn1COL->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1COL = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
		}
		else {
			btn1COL->Location = System::Drawing::Point(xbtn1COL, ybtn1COL);
			listoBtn1COL = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1RA->Location != panel1Tres->Location && btn1CA->Location != panel1Tres->Location) {
			btn1COL->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1COL = true;
			tiempo_respuesta(1, t_item1, listoBtn1RA, listoBtn1CA, listoBtn1COL);
		}
		else {
			btn1COL->Location = System::Drawing::Point(xbtn1COL, ybtn1COL);
			listoBtn1COL = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1COL->Location = System::Drawing::Point(xbtn1COL, ybtn1COL);
		listoBtn1COL = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn2GUI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2GUI->BackColor = System::Drawing::Color::Teal;
	int x = btn2GUI->Location.X;
	int y = btn2GUI->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2NO->Location != panel2Uno->Location && btn2PIN->Location != panel2Uno->Location) {
			btn2GUI->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2GUI = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2GUI->Location = System::Drawing::Point(xbtn2GUI, ybtn2GUI);
			listoBtn2GUI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2NO->Location != panel2Dos->Location && btn2PIN->Location != panel2Dos->Location) {
			btn2GUI->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2GUI = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2GUI->Location = System::Drawing::Point(xbtn2GUI, ybtn2GUI);
			listoBtn2GUI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2NO->Location != panel2Tres->Location && btn2PIN->Location != panel2Tres->Location) {
			btn2GUI->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2GUI = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2GUI->Location = System::Drawing::Point(xbtn2GUI, ybtn2GUI);
			listoBtn2GUI = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2GUI->Location = System::Drawing::Point(xbtn2GUI, ybtn2GUI);
		listoBtn2GUI = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn2NO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2NO->BackColor = System::Drawing::Color::Teal;
	int x = btn2NO->Location.X;
	int y = btn2NO->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2GUI->Location != panel2Uno->Location && btn2PIN->Location != panel2Uno->Location) {
			btn2NO->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2NO = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2NO->Location = System::Drawing::Point(xbtn2NO, ybtn2NO);
			listoBtn2NO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2GUI->Location != panel2Dos->Location && btn2PIN->Location != panel2Dos->Location) {
			btn2NO->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2NO = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2NO->Location = System::Drawing::Point(xbtn2NO, ybtn2NO);
			listoBtn2NO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2GUI->Location != panel2Tres->Location && btn2PIN->Location != panel2Tres->Location) {
			btn2NO->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2NO = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2NO->Location = System::Drawing::Point(xbtn2NO, ybtn2NO);
			listoBtn2NO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2NO->Location = System::Drawing::Point(xbtn2NO, ybtn2NO);
		listoBtn2NO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn2PIN_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2PIN->BackColor = System::Drawing::Color::Teal;
	int x = btn2PIN->Location.X;
	int y = btn2PIN->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2GUI->Location != panel2Uno->Location && btn2NO->Location != panel2Uno->Location) {
			btn2PIN->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2PIN = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2PIN->Location = System::Drawing::Point(xbtn2PIN, ybtn2PIN);
			listoBtn2PIN = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2GUI->Location != panel2Dos->Location && btn2NO->Location != panel2Dos->Location) {
			btn2PIN->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2PIN = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2PIN->Location = System::Drawing::Point(xbtn2PIN, ybtn2PIN);
			listoBtn2PIN = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2GUI->Location != panel2Tres->Location && btn2NO->Location != panel2Tres->Location) {
			btn2PIN->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2PIN = true;
			tiempo_respuesta(2, t_item2, listoBtn2GUI, listoBtn2NO, listoBtn2PIN);
		}
		else {
			btn2PIN->Location = System::Drawing::Point(xbtn2PIN, ybtn2PIN);
			listoBtn2PIN = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2PIN->Location = System::Drawing::Point(xbtn2PIN, ybtn2PIN);
		listoBtn2PIN = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn3TRE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3TRE->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3TRE->Location.X;
	int y = btn3TRE->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3ES->Location != panel3Uno->Location && btn3LLA->Location != panel3Uno->Location) {
			btn3TRE->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3TRE = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3TRE->Location = System::Drawing::Point(xbtn3TRE, ybtn3TRE);
			listoBtn3TRE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3ES->Location != panel3Dos->Location && btn3LLA->Location != panel3Dos->Location) {
			btn3TRE->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3TRE = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3TRE->Location = System::Drawing::Point(xbtn3TRE, ybtn3TRE);
			listoBtn3TRE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3ES->Location != panel3Tres->Location && btn3LLA->Location != panel3Tres->Location) {
			btn3TRE->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3TRE = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3TRE->Location = System::Drawing::Point(xbtn3TRE, ybtn3TRE);
			listoBtn3TRE = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3TRE->Location = System::Drawing::Point(xbtn3TRE, ybtn3TRE);
		listoBtn3TRE = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn3ES_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3ES->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3ES->Location.X;
	int y = btn3ES->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3TRE->Location != panel3Uno->Location && btn3LLA->Location != panel3Uno->Location) {
			btn3ES->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3ES = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3ES->Location = System::Drawing::Point(xbtn3ES, ybtn3ES);
			listoBtn3ES = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3TRE->Location != panel3Dos->Location && btn3LLA->Location != panel3Dos->Location) {
			btn3ES->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3ES = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3ES->Location = System::Drawing::Point(xbtn3ES, ybtn3ES);
			listoBtn3ES = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3TRE->Location != panel3Tres->Location && btn3LLA->Location != panel3Tres->Location) {
			btn3ES->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3ES = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3ES->Location = System::Drawing::Point(xbtn3ES, ybtn3ES);
			listoBtn3ES = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3ES->Location = System::Drawing::Point(xbtn3ES, ybtn3ES);
		listoBtn3ES = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn3LLA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3LLA->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3LLA->Location.X;
	int y = btn3LLA->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3TRE->Location != panel3Uno->Location && btn3ES->Location != panel3Uno->Location) {
			btn3LLA->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3LLA = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3LLA->Location = System::Drawing::Point(xbtn3LLA, ybtn3LLA);
			listoBtn3LLA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3TRE->Location != panel3Dos->Location && btn3ES->Location != panel3Dos->Location) {
			btn3LLA->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3LLA = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3LLA->Location = System::Drawing::Point(xbtn3LLA, ybtn3LLA);
			listoBtn3LLA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3TRE->Location != panel3Tres->Location && btn3ES->Location != panel3Tres->Location) {
			btn3LLA->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3LLA = true;
			tiempo_respuesta(3, t_item3, listoBtn3ES, listoBtn3TRE, listoBtn3LLA);
		}
		else {
			btn3LLA->Location = System::Drawing::Point(xbtn3LLA, ybtn3LLA);
			listoBtn3LLA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3LLA->Location = System::Drawing::Point(xbtn3LLA, ybtn3LLA);
		listoBtn3LLA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn4BA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4BA->BackColor = System::Drawing::Color::Olive;
	int x = btn4BA->Location.X;
	int y = btn4BA->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4NA->Location != panel4Uno->Location && btn4LLE->Location != panel4Uno->Location) {
			btn4BA->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4BA = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4BA->Location = System::Drawing::Point(xbtn4BA, ybtn4BA);
			listoBtn4BA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4NA->Location != panel4Dos->Location && btn4LLE->Location != panel4Dos->Location) {
			btn4BA->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4BA = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4BA->Location = System::Drawing::Point(xbtn4BA, ybtn4BA);
			listoBtn4BA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4NA->Location != panel4Tres->Location && btn4LLE->Location != panel4Tres->Location) {
			btn4BA->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4BA = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4BA->Location = System::Drawing::Point(xbtn4BA, ybtn4BA);
			listoBtn4BA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4BA->Location = System::Drawing::Point(xbtn4BA, ybtn4BA);
		listoBtn4BA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn4NA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4NA->BackColor = System::Drawing::Color::Olive;
	int x = btn4NA->Location.X;
	int y = btn4NA->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4BA->Location != panel4Uno->Location && btn4LLE->Location != panel4Uno->Location) {
			btn4NA->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4NA = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4NA->Location = System::Drawing::Point(xbtn4NA, ybtn4NA);
			listoBtn4NA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4BA->Location != panel4Dos->Location && btn4LLE->Location != panel4Dos->Location) {
			btn4NA->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4NA = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4NA->Location = System::Drawing::Point(xbtn4NA, ybtn4NA);
			listoBtn4NA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4BA->Location != panel4Tres->Location && btn4LLE->Location != panel4Tres->Location) {
			btn4NA->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4NA = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4NA->Location = System::Drawing::Point(xbtn4NA, ybtn4NA);
			listoBtn4NA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4NA->Location = System::Drawing::Point(xbtn4NA, ybtn4NA);
		listoBtn4NA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn4LLE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4LLE->BackColor = System::Drawing::Color::Olive;
	int x = btn4LLE->Location.X;
	int y = btn4LLE->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4BA->Location != panel4Uno->Location && btn4NA->Location != panel4Uno->Location) {
			btn4LLE->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4LLE = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4LLE->Location = System::Drawing::Point(xbtn4LLE, ybtn4LLE);
			listoBtn4LLE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4BA->Location != panel4Dos->Location && btn4NA->Location != panel4Dos->Location) {
			btn4LLE->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4LLE = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4LLE->Location = System::Drawing::Point(xbtn4LLE, ybtn4LLE);
			listoBtn4LLE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4BA->Location != panel4Tres->Location && btn4NA->Location != panel4Tres->Location) {
			btn4LLE->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4LLE = true;
			tiempo_respuesta(4, t_item4, listoBtn4NA, listoBtn4BA, listoBtn4LLE);
		}
		else {
			btn4LLE->Location = System::Drawing::Point(xbtn4LLE, ybtn4LLE);
			listoBtn4LLE = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4LLE->Location = System::Drawing::Point(xbtn4LLE, ybtn4LLE);
		listoBtn4LLE = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1UnoDD::btn1RA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1RA);
	}
}
System::Void TutIntV30::Act1UnoDD::btn1CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1CA);
	}
}
System::Void TutIntV30::Act1UnoDD::btn1COL_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1COL);
	}
}
System::Void TutIntV30::Act1UnoDD::btn2GUI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2GUI);
	}
}
System::Void TutIntV30::Act1UnoDD::btn2NO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2NO);
	}
}
System::Void TutIntV30::Act1UnoDD::btn2PIN_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2PIN);
	}
}
System::Void TutIntV30::Act1UnoDD::btn3TRE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3TRE);
	}
}
System::Void TutIntV30::Act1UnoDD::btn3ES_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3ES);
	}
}
System::Void TutIntV30::Act1UnoDD::btn3LLA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3LLA);
	}
}
System::Void TutIntV30::Act1UnoDD::btn4BA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4BA);
	}
}
System::Void TutIntV30::Act1UnoDD::btn4NA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4NA);
	}
}
System::Void TutIntV30::Act1UnoDD::btn4LLE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4LLE);
	}
}