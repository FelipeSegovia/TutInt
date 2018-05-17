#include "Act2UnoII.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act2UnoII::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void TutIntV30::Act2UnoII::comprobarRespuestas() {
	if (listoBtn1 == true && listoBtn2 == true && listoBtn3 == true && listoBtn4 == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
	else {
		this->btnListo->Visible = false;
	}
}
System::Void TutIntV30::Act2UnoII::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaDos", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act2UnoII::obtenerTiempoItems() {
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
System::Void TutIntV30::Act2UnoII::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;
	if (this->btn1SiM->Visible == true) {
		respuestas.push_back("SI");
	}
	else if (this->btn1NoM->Visible == true) {
		respuestas.push_back("NO");
	}

	if (this->btn2SiM->Visible == true) {
		respuestas.push_back("SI");
	}
	else if (this->btn2NoM->Visible == true) {
		respuestas.push_back("NO");
	}

	if (this->btn3SiM->Visible == true) {
		respuestas.push_back("SI");
	}
	else if (this->btn3NoM->Visible == true) {
		respuestas.push_back("NO");
	}

	if (this->btn4SiM->Visible == true) {
		respuestas.push_back("SI");
	}
	else if (this->btn4NoM->Visible == true) {
		respuestas.push_back("NO");
	}


	msclr::interop::marshal_context context;
	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Intermedia", "Intermedia", 1);
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
	manejadorBD->setDificultad("Intermedia");
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
System::Void TutIntV30::Act2UnoII::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act2UnoII::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act2UnoII::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act2UnoII::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act2UnoII::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act2UnoII::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act2UnoII::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act2UnoII::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
	//sonidoInicial();
	this->contAyuda++;
	if (this->instruccion1->Visible == true) {
		this->instruccion1->Visible = false;
		this->instruccion2->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad2/Nivel Intermedio/Complejidad intermedia/NI_CI_mvoz2.wav"), NULL, SND_ASYNC);
	}
	else if (this->instruccion2->Visible == true) {
		this->instruccion2->Visible = false;
		this->instruccion1->Visible = true;
		//PlaySound(TEXT("Audios/Oceano/Habilidad2/Nivel Intermedio/Complejidad intermedia/NI_CI_mvoz2.wav"), NULL, SND_ASYNC);
	}
}
System::Void TutIntV30::Act2UnoII::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act2UnoII::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act2UnoII::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act2UnoII::Act2UnoII_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Oceano/Habilidad2/Nivel Intermedio/Complejidad intermedia/NI_CI_mvoz1.wav"), NULL, SND_ASYNC);
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
System::Void TutIntV30::Act2UnoII::Act2UnoII_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act2UnoII::Act2UnoII_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act2UnoII::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, bool listoBtn)
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
		//System::Windows::Forms::MessageBox::Show("Tiempo:\nMinutos: " + Convert::ToString(tr_item->getMinutos()) + "\nSegundos: " + Convert::ToString(tr_item->getSegundos()));
	}
	else {
		//System::Windows::Forms::MessageBox::Show("Ya se clickeo");
	}
}
System::Void TutIntV30::Act2UnoII::btn1Si_Click(System::Object^  sender, System::EventArgs^  e) {
	listoBtn1 = true;
	tiempo_respuesta(1, t_item1, listoBtn1);
	this->btn1Si->Visible = false;
	this->btn1SiM->Visible = true;
	if (this->btn1NoM->Visible == true) {
		this->btn1NoM->Visible = false;
		this->btn1No->Visible = true;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoII::btn1No_Click(System::Object^  sender, System::EventArgs^  e) {
	listoBtn1 = true;
	tiempo_respuesta(1, t_item1, listoBtn1);
	this->btn1No->Visible = false;
	this->btn1NoM->Visible = true;
	if (this->btn1SiM->Visible == true) {
		this->btn1SiM->Visible = false;
		this->btn1Si->Visible = true;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoII::btn2Si_Click(System::Object^  sender, System::EventArgs^  e) {
	listoBtn2 = true;
	tiempo_respuesta(2, t_item2, listoBtn2);
	this->btn2Si->Visible = false;
	this->btn2SiM->Visible = true;
	if (this->btn2NoM->Visible == true) {
		this->btn2NoM->Visible = false;
		this->btn2No->Visible = true;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoII::btn2No_Click(System::Object^  sender, System::EventArgs^  e) {
	listoBtn2 = true;
	tiempo_respuesta(2, t_item2, listoBtn2);
	this->btn2No->Visible = false;
	this->btn2NoM->Visible = true;
	if (this->btn2SiM->Visible == true) {
		this->btn2SiM->Visible = false;
		this->btn2Si->Visible = true;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoII::btn3Si_Click(System::Object^  sender, System::EventArgs^  e) {
	listoBtn3 = true;
	tiempo_respuesta(3, t_item3, listoBtn3);
	this->btn3Si->Visible = false;
	this->btn3SiM->Visible = true;
	if (this->btn3NoM->Visible == true) {
		this->btn3NoM->Visible = false;
		this->btn3No->Visible = true;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoII::btn3No_Click(System::Object^  sender, System::EventArgs^  e) {
	listoBtn3 = true;
	tiempo_respuesta(3, t_item3, listoBtn3);
	this->btn3No->Visible = false;
	this->btn3NoM->Visible = true;
	if (this->btn3SiM->Visible == true) {
		this->btn3SiM->Visible = false;
		this->btn3Si->Visible = true;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoII::btn4Si_Click(System::Object^  sender, System::EventArgs^  e) {
	listoBtn4 = true;
	tiempo_respuesta(4, t_item4, listoBtn4);
	this->btn4Si->Visible = false;
	this->btn4SiM->Visible = true;
	if (this->btn4NoM->Visible == true) {
		this->btn4NoM->Visible = false;
		this->btn4No->Visible = true;
	}
	comprobarRespuestas();
}
System::Void TutIntV30::Act2UnoII::btn4No_Click(System::Object^  sender, System::EventArgs^  e) {
	listoBtn4 = true;
	tiempo_respuesta(4, t_item4, listoBtn4);
	this->btn4No->Visible = false;
	this->btn4NoM->Visible = true;
	if (this->btn4SiM->Visible == true) {
		this->btn4SiM->Visible = false;
		this->btn4Si->Visible = true;
	}
	comprobarRespuestas();
}