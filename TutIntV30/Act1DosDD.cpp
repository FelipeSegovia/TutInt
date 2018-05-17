#include "Act1DosDD.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act1DosDD::inicializarTam() {
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
System::Void TutIntV30::Act1DosDD::inicializarPosiciones() {
	xbtn1TU = btn1TU->Location.X;		ybtn1TU = btn1TU->Location.Y;
	xbtn1GA = btn1GA->Location.X;		ybtn1GA = btn1GA->Location.Y;
	xbtn1TOR = btn1TOR->Location.X;		ybtn1TOR = btn1TOR->Location.Y;
	xbtn2VIO = btn2VIO->Location.X;		ybtn2VIO = btn2VIO->Location.Y;
	xbtn2TA = btn2TA->Location.X;		ybtn2TA = btn2TA->Location.Y;
	xbtn2GA = btn2GA->Location.X;		ybtn2GA = btn2GA->Location.Y;
	xbtn3LI = btn3LI->Location.X;		ybtn3LI = btn3LI->Location.Y;
	xbtn3CA = btn3CA->Location.X;		ybtn3CA = btn3CA->Location.Y;
	xbtn3NO = btn3NO->Location.X;		ybtn3NO = btn3NO->Location.Y;
	xbtn3PE = btn3PE->Location.X;		ybtn3PE = btn3PE->Location.Y;
	xbtn4JO = btn4JO->Location.X;		ybtn4JO = btn4JO->Location.Y;
	xbtn4CAN = btn4CAN->Location.X;		ybtn4CAN = btn4CAN->Location.Y;
	xbtn4GRE = btn4GRE->Location.X;		ybtn4GRE = btn4GRE->Location.Y;
}
System::Void TutIntV30::Act1DosDD::comprobarRespuestas() {
	if (listoBtn1TU == true && listoBtn1GA == true && listoBtn1TOR == true && listoBtn2VIO == true && listoBtn2TA == true && listoBtn2GA == true &&
		listoBtn3LI == true && listoBtn3CA == true && listoBtn3NO == true && listoBtn3PE == true && listoBtn4JO == true && listoBtn4CAN == true && listoBtn4GRE == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act1DosDD::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	//Temporal Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	//Temporal ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act1DosDD::obtenerTiempoItems() {
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
System::Void TutIntV30::Act1DosDD::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
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
		if (btn1TU->Location.X == locationPanelUno[y] && btn1TU->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1TU->Text;
		}
		else if (btn1GA->Location.X == locationPanelUno[y] && btn1GA->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1GA->Text;
		}
		else if (btn1TOR->Location.X == locationPanelUno[y] && btn1TOR->Location.Y == locationPanelUno[cont]) {
			palabraUno = palabraUno + btn1TOR->Text;
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
		if (btn2TA->Location.X == locationPanelDos[i] && btn2TA->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2TA->Text;
		}
		else if (btn2GA->Location.X == locationPanelDos[i] && btn2GA->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2GA->Text;
		}
		else if (btn2VIO->Location.X == locationPanelDos[i] && btn2VIO->Location.Y == locationPanelDos[cont]) {
			palabraDos = palabraDos + btn2VIO->Text;
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
	locationPanelTres.push_back(panel3Cuatro->Location.X);
	locationPanelTres.push_back(panel3Cuatro->Location.Y);

	String^ palabraTres = nullptr;
	cont = 0;
	while (cont < 6) {
		int x = cont++;
		if (btn3NO->Location.X == locationPanelTres[x] && btn3NO->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3NO->Text;
		}
		else if (btn3CA->Location.X == locationPanelTres[x] && btn3CA->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3CA->Text;
		}
		else if (btn3LI->Location.X == locationPanelTres[x] && btn3LI->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3LI->Text;
		}
		else if (btn3PE->Location.X == locationPanelTres[x] && btn3PE->Location.Y == locationPanelTres[cont]) {
			palabraTres = palabraTres + btn3PE->Text;
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
		if (btn4GRE->Location.X == locationPanelCuatro[j] && btn4GRE->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4GRE->Text;
		}
		else if (btn4CAN->Location.X == locationPanelCuatro[j] && btn4CAN->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4CAN->Text;
		}
		else if (btn4JO->Location.X == locationPanelCuatro[j] && btn4JO->Location.Y == locationPanelCuatro[cont]) {
			palabraCuatro = palabraCuatro + btn4JO->Text;
		}
		cont++;
	}
	string string4 = context.marshal_as<std::string>(palabraCuatro);
	respuestas.push_back(string4);
	string4.clear();

	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Dificil", "Dificil", 2);
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
System::Void TutIntV30::Act1DosDD::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act1DosDD::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act1DosDD::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act1DosDD::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act1DosDD::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act1DosDD::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act1DosDD::ayudaUno_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaUno->Size = System::Drawing::Size(wAyudaUno + 5, hAyudaUno + 5);
}
System::Void TutIntV30::Act1DosDD::ayudaUno_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaUno->Size = System::Drawing::Size(wAyudaUno, hAyudaUno);
}
System::Void TutIntV30::Act1DosDD::ayudaDos_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaDos->Size = System::Drawing::Size(wAyudaDos + 5, hAyudaDos + 5);
}
System::Void TutIntV30::Act1DosDD::ayudaDos_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaDos->Size = System::Drawing::Size(wAyudaDos, hAyudaDos);
}
System::Void TutIntV30::Act1DosDD::ayudaTres_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaTres->Size = System::Drawing::Size(wAyudaTres + 5, hAyudaTres + 5);
}
System::Void TutIntV30::Act1DosDD::ayudaTres_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaTres->Size = System::Drawing::Size(wAyudaTres, hAyudaTres);
}
System::Void TutIntV30::Act1DosDD::ayudaCuatro_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaCuatro->Size = System::Drawing::Size(wAyudaCuatro + 5, hAyudaCuatro + 5);
}
System::Void TutIntV30::Act1DosDD::ayudaCuatro_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaCuatro->Size = System::Drawing::Size(wAyudaCuatro, hAyudaCuatro);
}
System::Void TutIntV30::Act1DosDD::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act1DosDD::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
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
System::Void TutIntV30::Act1DosDD::ayudaUno_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaUno->Visible = false;
	this->pictureBox1->Visible = true;
	this->contAyuda++;
}
System::Void TutIntV30::Act1DosDD::ayudaDos_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaDos->Visible = false;
	this->pictureBox2->Visible = true;
	this->contAyuda++;
}
System::Void TutIntV30::Act1DosDD::ayudaTres_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaTres->Visible = false;
	this->pictureBox4->Visible = true;
	this->contAyuda++;
}
System::Void TutIntV30::Act1DosDD::ayudaCuatro_Click(System::Object^  sender, System::EventArgs^  e) {
	this->ayudaCuatro->Visible = false;
	this->pictureBox3->Visible = true;
	this->contAyuda++;
}
System::Void TutIntV30::Act1DosDD::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act1DosDD::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act1DosDD::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act1DosDD::Act1DosDD_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad dificil/NI_CD_voz2.wav"), NULL, SND_ASYNC);
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
System::Void TutIntV30::Act1DosDD::Act1DosDD_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act1DosDD::Act1DosDD_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act1DosDD::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoUno, bool listoDos, bool listoTres, bool listoCuatro)
{
	if (listoUno == true && listoDos == true && listoTres == true && listoCuatro == true) {
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
System::Void TutIntV30::Act1DosDD::moverBoton(System::Windows::Forms::Button^ boton) {
	boton->Location = System::Drawing::Point(posMouseFormX - posMouseBtnX, posMouseFormY - posMouseBtnY);
	posActBtnX = boton->Location.X;
	posActBtnY = boton->Location.Y;
}
System::Void TutIntV30::Act1DosDD::btn1TU_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1TU->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1DosDD::btn1GA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1GA->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1DosDD::btn1TOR_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn1TOR->BackColor = System::Drawing::Color::DarkGoldenrod;
}
System::Void TutIntV30::Act1DosDD::btn2VIO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2VIO->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1DosDD::btn2TA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2TA->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1DosDD::btn2GA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn2GA->BackColor = System::Drawing::Color::DarkTurquoise;
}
System::Void TutIntV30::Act1DosDD::btn3LI_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3LI->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDD::btn3CA_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3CA->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDD::btn3NO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3NO->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDD::btn3PE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn3PE->BackColor = System::Drawing::Color::Sienna;
}
System::Void TutIntV30::Act1DosDD::btn4JO_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4JO->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1DosDD::btn4CAN_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4CAN->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1DosDD::btn4GRE_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseBtnX = e->Location.X;
	posMouseBtnY = e->Location.Y;
	btnPresionado = true;
	btn4GRE->BackColor = System::Drawing::Color::DarkKhaki;
}
System::Void TutIntV30::Act1DosDD::btn1TU_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1TU->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1TU->Location.X;
	int y = btn1TU->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1GA->Location != panel1Uno->Location && btn1TOR->Location != panel1Uno->Location) {
			btn1TU->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1TU = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
		}
		else {
			btn1TU->Location = System::Drawing::Point(xbtn1TU, ybtn1TU);
			listoBtn1TU = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1GA->Location != panel1Dos->Location && btn1TOR->Location != panel1Dos->Location) {
			btn1TU->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1TU = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
		}
		else {
			btn1TU->Location = System::Drawing::Point(xbtn1TU, ybtn1TU);
			listoBtn1TU = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1GA->Location != panel1Tres->Location && btn1TOR->Location != panel1Tres->Location) {
			btn1TU->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1TU = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
		}
		else {
			btn1TU->Location = System::Drawing::Point(xbtn1TU, ybtn1TU);
			listoBtn1TU = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1TU->Location = System::Drawing::Point(xbtn1TU, ybtn1TU);
		listoBtn1TU = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn1GA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1GA->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1GA->Location.X;
	int y = btn1GA->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1TU->Location != panel1Uno->Location && btn1TOR->Location != panel1Uno->Location) {
			btn1GA->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1GA = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
		}
		else {
			btn1GA->Location = System::Drawing::Point(xbtn1GA, ybtn1GA);
			listoBtn1GA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1TU->Location != panel1Dos->Location && btn1TOR->Location != panel1Dos->Location) {
			btn1GA->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1GA = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
		}
		else {
			btn1GA->Location = System::Drawing::Point(xbtn1GA, ybtn1GA);
			listoBtn1GA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1TU->Location != panel1Tres->Location && btn1TOR->Location != panel1Tres->Location) {
			btn1GA->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1GA = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
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
System::Void TutIntV30::Act1DosDD::btn1TOR_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn1TOR->BackColor = System::Drawing::Color::Goldenrod;
	int x = btn1TOR->Location.X;
	int y = btn1TOR->Location.Y;
	if (x > panel1Uno->Location.X && x < panel1Uno->Location.X + panel1Uno->Size.Width && y > panel1Uno->Location.Y && y < panel1Uno->Location.Y + panel1Uno->Size.Height) {
		if (btn1TU->Location != panel1Uno->Location && btn1GA->Location != panel1Uno->Location) {
			btn1TOR->Location = System::Drawing::Point(panel1Uno->Location.X, panel1Uno->Location.Y);
			listoBtn1TOR = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
		}
		else {
			btn1TOR->Location = System::Drawing::Point(xbtn1TOR, ybtn1TOR);
			listoBtn1TOR = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Dos->Location.X && x < panel1Dos->Location.X + panel1Dos->Size.Width && y > panel1Dos->Location.Y && y < panel1Dos->Location.Y + panel1Dos->Size.Height) {
		if (btn1TU->Location != panel1Dos->Location && btn1GA->Location != panel1Dos->Location) {
			btn1TOR->Location = System::Drawing::Point(panel1Dos->Location.X, panel1Dos->Location.Y);
			listoBtn1TOR = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
		}
		else {
			btn1TOR->Location = System::Drawing::Point(xbtn1TOR, ybtn1TOR);
			listoBtn1TOR = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel1Tres->Location.X && x < panel1Tres->Location.X + panel1Tres->Size.Width && y > panel1Tres->Location.Y && y < panel1Tres->Location.Y + panel1Tres->Size.Height) {
		if (btn1TU->Location != panel1Tres->Location && btn1GA->Location != panel1Tres->Location) {
			btn1TOR->Location = System::Drawing::Point(panel1Tres->Location.X, panel1Tres->Location.Y);
			listoBtn1TOR = true;
			tiempo_respuesta(1, t_item1, listoBtn1TU, listoBtn1GA, listoBtn1TOR, true);
		}
		else {
			btn1TOR->Location = System::Drawing::Point(xbtn1TOR, ybtn1TOR);
			listoBtn1TOR = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn1TOR->Location = System::Drawing::Point(xbtn1TOR, ybtn1TOR);
		listoBtn1TOR = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn2VIO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2VIO->BackColor = System::Drawing::Color::Teal;
	int x = btn2VIO->Location.X;
	int y = btn2VIO->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2TA->Location != panel2Uno->Location && btn2GA->Location != panel2Uno->Location) {
			btn2VIO->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2VIO = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2VIO->Location = System::Drawing::Point(xbtn2VIO, ybtn2VIO);
			listoBtn2VIO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2TA->Location != panel2Dos->Location && btn2GA->Location != panel2Dos->Location) {
			btn2VIO->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2VIO = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2VIO->Location = System::Drawing::Point(xbtn2VIO, ybtn2VIO);
			listoBtn2VIO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2TA->Location != panel2Tres->Location && btn2GA->Location != panel2Tres->Location) {
			btn2VIO->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2VIO = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2VIO->Location = System::Drawing::Point(xbtn2VIO, ybtn2VIO);
			listoBtn2VIO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2VIO->Location = System::Drawing::Point(xbtn2VIO, ybtn2VIO);
		listoBtn2VIO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn2TA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2TA->BackColor = System::Drawing::Color::Teal;
	int x = btn2TA->Location.X;
	int y = btn2TA->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2VIO->Location != panel2Uno->Location && btn2GA->Location != panel2Uno->Location) {
			btn2TA->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2TA = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2TA->Location = System::Drawing::Point(xbtn2TA, ybtn2TA);
			listoBtn2TA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2VIO->Location != panel2Dos->Location && btn2GA->Location != panel2Dos->Location) {
			btn2TA->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2TA = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2TA->Location = System::Drawing::Point(xbtn2TA, ybtn2TA);
			listoBtn2TA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2VIO->Location != panel2Tres->Location && btn2GA->Location != panel2Tres->Location) {
			btn2TA->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2TA = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2TA->Location = System::Drawing::Point(xbtn2TA, ybtn2TA);
			listoBtn2TA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2TA->Location = System::Drawing::Point(xbtn2TA, ybtn2TA);
		listoBtn2TA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn2GA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn2GA->BackColor = System::Drawing::Color::Teal;
	int x = btn2GA->Location.X;
	int y = btn2GA->Location.Y;
	if (x > panel2Uno->Location.X && x < panel2Uno->Location.X + panel2Uno->Size.Width && y > panel2Uno->Location.Y && y < panel2Uno->Location.Y + panel2Uno->Size.Height) {
		if (btn2VIO->Location != panel2Uno->Location && btn2TA->Location != panel2Uno->Location) {
			btn2GA->Location = System::Drawing::Point(panel2Uno->Location.X, panel2Uno->Location.Y);
			listoBtn2GA = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2GA->Location = System::Drawing::Point(xbtn2GA, ybtn2GA);
			listoBtn2GA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Dos->Location.X && x < panel2Dos->Location.X + panel2Dos->Size.Width && y > panel2Dos->Location.Y && y < panel2Dos->Location.Y + panel2Dos->Size.Height) {
		if (btn2VIO->Location != panel2Dos->Location && btn2TA->Location != panel2Dos->Location) {
			btn2GA->Location = System::Drawing::Point(panel2Dos->Location.X, panel2Dos->Location.Y);
			listoBtn2GA = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2GA->Location = System::Drawing::Point(xbtn2GA, ybtn2GA);
			listoBtn2GA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel2Tres->Location.X && x < panel2Tres->Location.X + panel2Tres->Size.Width && y > panel2Tres->Location.Y && y < panel2Tres->Location.Y + panel2Tres->Size.Height) {
		if (btn2VIO->Location != panel2Tres->Location && btn2TA->Location != panel2Tres->Location) {
			btn2GA->Location = System::Drawing::Point(panel2Tres->Location.X, panel2Tres->Location.Y);
			listoBtn2GA = true;
			tiempo_respuesta(2, t_item2, listoBtn2VIO, listoBtn2TA, listoBtn2GA, true);
		}
		else {
			btn2GA->Location = System::Drawing::Point(xbtn2GA, ybtn2GA);
			listoBtn2GA = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn2GA->Location = System::Drawing::Point(xbtn2GA, ybtn2GA);
		listoBtn2GA = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn3LI_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3LI->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3LI->Location.X;
	int y = btn3LI->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3CA->Location != panel3Uno->Location && btn3NO->Location != panel3Uno->Location && btn3PE->Location != panel3Uno->Location) {
			btn3LI->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3LI = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3LI->Location = System::Drawing::Point(xbtn3LI, ybtn3LI);
			listoBtn3LI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3CA->Location != panel3Dos->Location && btn3NO->Location != panel3Dos->Location && btn3PE->Location != panel3Dos->Location) {
			btn3LI->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3LI = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3LI->Location = System::Drawing::Point(xbtn3LI, ybtn3LI);
			listoBtn3LI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3CA->Location != panel3Tres->Location && btn3NO->Location != panel3Tres->Location && btn3PE->Location != panel3Tres->Location) {
			btn3LI->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3LI = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3LI->Location = System::Drawing::Point(xbtn3LI, ybtn3LI);
			listoBtn3LI = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Cuatro->Location.X && x < panel3Cuatro->Location.X + panel3Cuatro->Size.Width && y > panel3Cuatro->Location.Y && y < panel3Cuatro->Location.Y + panel3Cuatro->Size.Height) {
		if (btn3CA->Location != panel3Cuatro->Location && btn3NO->Location != panel3Cuatro->Location && btn3PE->Location != panel3Cuatro->Location) {
			btn3LI->Location = System::Drawing::Point(panel3Cuatro->Location.X, panel3Cuatro->Location.Y);
			listoBtn3LI = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3LI->Location = System::Drawing::Point(xbtn3LI, ybtn3LI);
			listoBtn3LI = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3LI->Location = System::Drawing::Point(xbtn3LI, ybtn3LI);
		listoBtn3LI = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn3CA_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3CA->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3CA->Location.X;
	int y = btn3CA->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3LI->Location != panel3Uno->Location && btn3NO->Location != panel3Uno->Location && btn3PE->Location != panel3Uno->Location) {
			btn3CA->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3CA = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3CA->Location = System::Drawing::Point(xbtn3CA, ybtn3CA);
			listoBtn3CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3LI->Location != panel3Dos->Location && btn3NO->Location != panel3Dos->Location && btn3PE->Location != panel3Dos->Location) {
			btn3CA->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3CA = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3CA->Location = System::Drawing::Point(xbtn3CA, ybtn3CA);
			listoBtn3CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3LI->Location != panel3Tres->Location && btn3NO->Location != panel3Tres->Location && btn3PE->Location != panel3Tres->Location) {
			btn3CA->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3CA = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3CA->Location = System::Drawing::Point(xbtn3CA, ybtn3CA);
			listoBtn3CA = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Cuatro->Location.X && x < panel3Cuatro->Location.X + panel3Cuatro->Size.Width && y > panel3Cuatro->Location.Y && y < panel3Cuatro->Location.Y + panel3Cuatro->Size.Height) {
		if (btn3LI->Location != panel3Cuatro->Location && btn3NO->Location != panel3Cuatro->Location && btn3PE->Location != panel3Cuatro->Location) {
			btn3CA->Location = System::Drawing::Point(panel3Cuatro->Location.X, panel3Cuatro->Location.Y);
			listoBtn3CA = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
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
System::Void TutIntV30::Act1DosDD::btn3NO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3NO->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3NO->Location.X;
	int y = btn3NO->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3LI->Location != panel3Uno->Location && btn3CA->Location != panel3Uno->Location && btn3PE->Location != panel3Uno->Location) {
			btn3NO->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3NO = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3NO->Location = System::Drawing::Point(xbtn3NO, ybtn3NO);
			listoBtn3NO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3LI->Location != panel3Dos->Location && btn3CA->Location != panel3Dos->Location && btn3PE->Location != panel3Dos->Location) {
			btn3NO->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3NO = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3NO->Location = System::Drawing::Point(xbtn3NO, ybtn3NO);
			listoBtn3NO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3LI->Location != panel3Tres->Location && btn3CA->Location != panel3Tres->Location && btn3PE->Location != panel3Tres->Location) {
			btn3NO->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3NO = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3NO->Location = System::Drawing::Point(xbtn3NO, ybtn3NO);
			listoBtn3NO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Cuatro->Location.X && x < panel3Cuatro->Location.X + panel3Cuatro->Size.Width && y > panel3Cuatro->Location.Y && y < panel3Cuatro->Location.Y + panel3Cuatro->Size.Height) {
		if (btn3LI->Location != panel3Cuatro->Location && btn3CA->Location != panel3Cuatro->Location && btn3PE->Location != panel3Cuatro->Location) {
			btn3NO->Location = System::Drawing::Point(panel3Cuatro->Location.X, panel3Cuatro->Location.Y);
			listoBtn3NO = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3NO->Location = System::Drawing::Point(xbtn3NO, ybtn3NO);
			listoBtn3NO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3NO->Location = System::Drawing::Point(xbtn3NO, ybtn3NO);
		listoBtn3NO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn3PE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn3PE->BackColor = System::Drawing::Color::Chocolate;
	int x = btn3PE->Location.X;
	int y = btn3PE->Location.Y;
	if (x > panel3Uno->Location.X && x < panel3Uno->Location.X + panel3Uno->Size.Width && y > panel3Uno->Location.Y && y < panel3Uno->Location.Y + panel3Uno->Size.Height) {
		if (btn3LI->Location != panel3Uno->Location && btn3CA->Location != panel3Uno->Location && btn3NO->Location != panel3Uno->Location) {
			btn3PE->Location = System::Drawing::Point(panel3Uno->Location.X, panel3Uno->Location.Y);
			listoBtn3PE = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3PE->Location = System::Drawing::Point(xbtn3PE, ybtn3PE);
			listoBtn3PE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Dos->Location.X && x < panel3Dos->Location.X + panel3Dos->Size.Width && y > panel3Dos->Location.Y && y < panel3Dos->Location.Y + panel3Dos->Size.Height) {
		if (btn3LI->Location != panel3Dos->Location && btn3CA->Location != panel3Dos->Location && btn3NO->Location != panel3Dos->Location) {
			btn3PE->Location = System::Drawing::Point(panel3Dos->Location.X, panel3Dos->Location.Y);
			listoBtn3PE = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3PE->Location = System::Drawing::Point(xbtn3PE, ybtn3PE);
			listoBtn3PE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Tres->Location.X && x < panel3Tres->Location.X + panel3Tres->Size.Width && y > panel3Tres->Location.Y && y < panel3Tres->Location.Y + panel3Tres->Size.Height) {
		if (btn3LI->Location != panel3Tres->Location && btn3CA->Location != panel3Tres->Location && btn3NO->Location != panel3Tres->Location) {
			btn3PE->Location = System::Drawing::Point(panel3Tres->Location.X, panel3Tres->Location.Y);
			listoBtn3PE = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3PE->Location = System::Drawing::Point(xbtn3PE, ybtn3PE);
			listoBtn3PE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel3Cuatro->Location.X && x < panel3Cuatro->Location.X + panel3Cuatro->Size.Width && y > panel3Cuatro->Location.Y && y < panel3Cuatro->Location.Y + panel3Cuatro->Size.Height) {
		if (btn3LI->Location != panel3Cuatro->Location && btn3CA->Location != panel3Cuatro->Location && btn3NO->Location != panel3Cuatro->Location) {
			btn3PE->Location = System::Drawing::Point(panel3Cuatro->Location.X, panel3Cuatro->Location.Y);
			listoBtn3PE = true;
			tiempo_respuesta(3, t_item3, listoBtn3CA, listoBtn3LI, listoBtn3NO, listoBtn3PE);
		}
		else {
			btn3PE->Location = System::Drawing::Point(xbtn3PE, ybtn3PE);
			listoBtn3PE = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn3PE->Location = System::Drawing::Point(xbtn3PE, ybtn3PE);
		listoBtn3PE = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn4JO_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4JO->BackColor = System::Drawing::Color::Olive;
	int x = btn4JO->Location.X;
	int y = btn4JO->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4CAN->Location != panel4Uno->Location && btn4GRE->Location != panel4Uno->Location) {
			btn4JO->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4JO = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4JO->Location = System::Drawing::Point(xbtn4JO, ybtn4JO);
			listoBtn4JO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4CAN->Location != panel4Dos->Location && btn4GRE->Location != panel4Dos->Location) {
			btn4JO->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4JO = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4JO->Location = System::Drawing::Point(xbtn4JO, ybtn4JO);
			listoBtn4JO = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4CAN->Location != panel4Tres->Location && btn4GRE->Location != panel4Tres->Location) {
			btn4JO->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4JO = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4JO->Location = System::Drawing::Point(xbtn4JO, ybtn4JO);
			listoBtn4JO = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4JO->Location = System::Drawing::Point(xbtn4JO, ybtn4JO);
		listoBtn4JO = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn4CAN_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4CAN->BackColor = System::Drawing::Color::Olive;
	int x = btn4CAN->Location.X;
	int y = btn4CAN->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4JO->Location != panel4Uno->Location && btn4GRE->Location != panel4Uno->Location) {
			btn4CAN->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4CAN = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4CAN->Location = System::Drawing::Point(xbtn4CAN, ybtn4CAN);
			listoBtn4CAN = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4JO->Location != panel4Dos->Location && btn4GRE->Location != panel4Dos->Location) {
			btn4CAN->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4CAN = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4CAN->Location = System::Drawing::Point(xbtn4CAN, ybtn4CAN);
			listoBtn4CAN = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4JO->Location != panel4Tres->Location && btn4GRE->Location != panel4Tres->Location) {
			btn4CAN->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4CAN = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4CAN->Location = System::Drawing::Point(xbtn4CAN, ybtn4CAN);
			listoBtn4CAN = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4CAN->Location = System::Drawing::Point(xbtn4CAN, ybtn4CAN);
		listoBtn4CAN = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn4GRE_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btnPresionado = false;
	btn4GRE->BackColor = System::Drawing::Color::Olive;
	int x = btn4GRE->Location.X;
	int y = btn4GRE->Location.Y;
	if (x > panel4Uno->Location.X && x < panel4Uno->Location.X + panel4Uno->Size.Width && y > panel4Uno->Location.Y && y < panel4Uno->Location.Y + panel4Uno->Size.Height) {
		if (btn4JO->Location != panel4Uno->Location && btn4CAN->Location != panel4Uno->Location) {
			btn4GRE->Location = System::Drawing::Point(panel4Uno->Location.X, panel4Uno->Location.Y);
			listoBtn4GRE = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4GRE->Location = System::Drawing::Point(xbtn4GRE, ybtn4GRE);
			listoBtn4GRE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Dos->Location.X && x < panel4Dos->Location.X + panel4Dos->Size.Width && y > panel4Dos->Location.Y && y < panel4Dos->Location.Y + panel4Dos->Size.Height) {
		if (btn4JO->Location != panel4Dos->Location && btn4CAN->Location != panel4Dos->Location) {
			btn4GRE->Location = System::Drawing::Point(panel4Dos->Location.X, panel4Dos->Location.Y);
			listoBtn4GRE = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4GRE->Location = System::Drawing::Point(xbtn4GRE, ybtn4GRE);
			listoBtn4GRE = false;
			this->btnListo->Visible = false;
		}
	}
	else if (x > panel4Tres->Location.X && x < panel4Tres->Location.X + panel4Tres->Size.Width && y > panel4Tres->Location.Y && y < panel4Tres->Location.Y + panel4Tres->Size.Height) {
		if (btn4JO->Location != panel4Tres->Location && btn4CAN->Location != panel4Tres->Location) {
			btn4GRE->Location = System::Drawing::Point(panel4Tres->Location.X, panel4Tres->Location.Y);
			listoBtn4GRE = true;
			tiempo_respuesta(4, t_item4, listoBtn4CAN, listoBtn4JO, listoBtn4GRE, true);
		}
		else {
			btn4GRE->Location = System::Drawing::Point(xbtn4GRE, ybtn4GRE);
			listoBtn4GRE = false;
			this->btnListo->Visible = false;
		}
	}
	else {
		btn4GRE->Location = System::Drawing::Point(xbtn4GRE, ybtn4GRE);
		listoBtn4GRE = false;
		this->btnListo->Visible = false;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosDD::btn1TU_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1TU);
	}
}
System::Void TutIntV30::Act1DosDD::btn1GA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1GA);
	}
}
System::Void TutIntV30::Act1DosDD::btn1TOR_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn1TOR);
	}
}
System::Void TutIntV30::Act1DosDD::btn2VIO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2VIO);
	}
}
System::Void TutIntV30::Act1DosDD::btn2TA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2TA);
	}
}
System::Void TutIntV30::Act1DosDD::btn2GA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn2GA);
	}
}
System::Void TutIntV30::Act1DosDD::btn3LI_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3LI);
	}
}
System::Void TutIntV30::Act1DosDD::btn3CA_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3CA);
	}
}
System::Void TutIntV30::Act1DosDD::btn3NO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3NO);
	}
}
System::Void TutIntV30::Act1DosDD::btn3PE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn3PE);
	}
}
System::Void TutIntV30::Act1DosDD::btn4JO_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4JO);
	}
}
System::Void TutIntV30::Act1DosDD::btn4CAN_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4CAN);
	}
}
System::Void TutIntV30::Act1DosDD::btn4GRE_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	posMouseFormX = posActBtnX + e->Location.X;
	posMouseFormY = posActBtnY + e->Location.Y;
	if (btnPresionado == true)
	{
		moverBoton(btn4GRE);
	}
}