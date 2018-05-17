#include "Act1DosII.h"
#include "FormEstrella.h"
#include "Advertencia.h"
#include "PrincipalUno.h"
#include <windows.h>
#include <MMSystem.h>
#include <string>
#include <msclr\marshal_cppstd.h>

System::Void TutIntV30::Act1DosII::inicializarTam() {
	wVolver = this->btnVolver->Size.Width;
	hVolver = this->btnVolver->Size.Height;
	wListo = this->btnListo->Size.Width;
	hListo = this->btnListo->Size.Height;
	wAyuda = this->btnAyuda->Size.Width;
	hAyuda = this->btnAyuda->Size.Height;
}
System::Void TutIntV30::Act1DosII::comprobarRespuestas() {
	if (listoGaviota == true && listoCamaron == true && listoCangrejo == true && listoPirana == true) {
		this->btnListo->Visible = true;
		this->btnListo->Enabled = true;
	}
}
System::Void TutIntV30::Act1DosII::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	//hiloAct->Abort();
	Advertencia^ ventana = gcnew Advertencia("etapaUno", this, false, manejadorBD);
	ventana->ShowDialog();
}
vector<TiempoMI*> TutIntV30::Act1DosII::obtenerTiempoItems() {
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
System::Void TutIntV30::Act1DosII::btnListo_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	t_actividad->setIniciar(false);

	vector<TiempoMI*> tiempoItems = obtenerTiempoItems();
	TiempoMI* tiempoAct = new TiempoMI();
	tiempoAct->setMinutos(t_actividad->getMinutos());
	tiempoAct->setSegundos(t_actividad->getSegundos());

	vector<string> respuestas;
	msclr::interop::marshal_context context;

	string stringBtn1 = context.marshal_as<std::string>(this->btn1->Text->ToString());
	string stringCam = "CAMA" + stringBtn1 + "ON";
	respuestas.push_back(stringCam);
	stringBtn1.clear();

	string stringBtn2 = context.marshal_as<std::string>(this->btn2->Text->ToString());
	string stringPir = "PI" + stringBtn2 + "A�A";
	respuestas.push_back(stringPir);
	stringBtn2.clear();

	string stringBtn3 = context.marshal_as<std::string>(this->btn3->Text->ToString());
	string stringGav = "GAV" + stringBtn3 + "OTA";
	respuestas.push_back(stringGav);
	stringBtn3.clear();

	string stringBtn4 = context.marshal_as<std::string>(this->btn4->Text->ToString());
	string stringCan = "CANGR" + stringBtn4 + "JO";
	respuestas.push_back(stringCan);
	stringBtn4.clear();

	controlador->setPercepcionesActividad(respuestas, contAyuda, tiempoItems, tiempoAct);
	controlador->setPercepcionesNivelActividad("Conciencia_fonologica", "Intermedia", "Intermedia", 2);
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
System::Void TutIntV30::Act1DosII::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 5, hVolver + 5);
}
System::Void TutIntV30::Act1DosII::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::Act1DosII::btnListo_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo + 5, hListo + 5);
}
System::Void TutIntV30::Act1DosII::btnListo_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnListo->Size = System::Drawing::Size(wListo, hListo);
}
System::Void TutIntV30::Act1DosII::btnAyuda_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda + 5, hAyuda + 5);
}
System::Void TutIntV30::Act1DosII::btnAyuda_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnAyuda->Size = System::Drawing::Size(wAyuda, hAyuda);
}
System::Void TutIntV30::Act1DosII::sonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/actividad_1.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::Act1DosII::btnAyuda_Click(System::Object^  sender, System::EventArgs^  e) {
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
System::Void TutIntV30::Act1DosII::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	hiloAct->Abort();
	Application::Exit();
}
System::Void TutIntV30::Act1DosII::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::Act1DosII::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		sonidoInicial();
	}
}
System::Void TutIntV30::Act1DosII::Act1DosII_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
	//PlaySound(TEXT("Audios/Oceano/Habilidad1/Nivel Intermedio/Complejidad intermedia/NI_CI_voz1.wav"), NULL, SND_ASYNC);
	//sumar tiempo que demora en dar la instrucci�n a t_actividad
	t_actividad = gcnew TiempoGUI();
	//t_actividad->setSegundos(tiempo de reproduccion de actividad);
	t_item1 = gcnew TiempoGUI();
	t_item2 = gcnew TiempoGUI();
	t_item3 = gcnew TiempoGUI();
	t_item4 = gcnew TiempoGUI();
	hiloAct = gcnew Thread(gcnew ThreadStart(t_actividad, &TiempoGUI::cronometro));
	hiloAct->Start();
}
System::Void TutIntV30::Act1DosII::Act1DosII_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::Act1DosII::Act1DosII_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}
System::Void TutIntV30::Act1DosII::tiempo_respuesta(int numItem, TiempoGUI^ tr_item, System::Windows::Forms::Button^ btn)
{
	if (btn->BackColor != System::Drawing::Color::ForestGreen) {
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
System::Void TutIntV30::Act1DosII::inicializarColor1() {
	this->btn1T->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn1R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn1L->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
System::Void TutIntV30::Act1DosII::inicializarColor2() {
	this->btn2M->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn2R->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn2S->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
System::Void TutIntV30::Act1DosII::inicializarColor3() {
	this->btn3A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn3I->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn3O->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
System::Void TutIntV30::Act1DosII::inicializarColor4() {
	this->btn4A->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn4O->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
	this->btn4E->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
		static_cast<System::Int32>(static_cast<System::Byte>(0)));
}
System::Void TutIntV30::Act1DosII::btn1T_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(1, t_item1, btn1T);
	inicializarColor1();
	btn1T->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn1T->Text;
	this->btn1->Text = letra;
	listoCamaron = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn1R_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(1, t_item1, btn1R);
	inicializarColor1();
	btn1R->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn1R->Text;
	this->btn1->Text = letra;
	listoCamaron = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn1L_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(1, t_item1, btn1L);
	inicializarColor1();
	btn1L->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn1L->Text;
	this->btn1->Text = letra;
	listoCamaron = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn2M_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(2, t_item2, btn2M);
	inicializarColor2();
	btn2M->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn2M->Text;
	this->btn2->Text = letra;
	listoPirana = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn2R_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(2, t_item2, btn2R);
	inicializarColor2();
	btn2R->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn2R->Text;
	this->btn2->Text = letra;
	listoPirana = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn2S_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(2, t_item2, btn2S);
	inicializarColor2();
	btn2S->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn2S->Text;
	this->btn2->Text = letra;
	listoPirana = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn3A_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(3, t_item3, btn3A);
	inicializarColor3();
	btn3A->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn3A->Text;
	this->btn3->Text = letra;
	listoGaviota = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn3I_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(3, t_item3, btn3I);
	inicializarColor3();
	btn3I->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn3I->Text;
	this->btn3->Text = letra;
	listoGaviota = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn3O_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(3, t_item3, btn3O);
	inicializarColor3();
	btn3O->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn3O->Text;
	this->btn3->Text = letra;
	listoGaviota = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn4A_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(4, t_item4, btn4A);
	inicializarColor4();
	btn4A->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn4A->Text;
	this->btn4->Text = letra;
	listoCangrejo = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn4O_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(4, t_item4, btn4O);
	inicializarColor4();
	btn4O->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn4O->Text;
	this->btn4->Text = letra;
	listoCangrejo = true;
	comprobarRespuestas();
}
System::Void TutIntV30::Act1DosII::btn4E_Click(System::Object^  sender, System::EventArgs^  e) {
	tiempo_respuesta(4, t_item4, btn4E);
	inicializarColor4();
	btn4E->BackColor = System::Drawing::Color::ForestGreen;
	String^ letra = btn4E->Text;
	this->btn4->Text = letra;
	listoCangrejo = true;
	comprobarRespuestas();
}