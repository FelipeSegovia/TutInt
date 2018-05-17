#include "PrincipalUno.h"
#include "NivelUno.h"
#include "Act1UnoBB.h"
#include "Act1DosBB.h"
#include "Act1UnoBI.h"
#include "Act1DosBI.h"
#include "Act1UnoBD.h"
#include "Act1DosBD.h"
#include "Act1DosIB.h"
#include "Act1UnoIB.h"
#include "Act1DosII.h"
#include "Act1UnoII.h"
#include "Act1DosID.h"
#include "Act1UnoID.h"
#include "Act1UnoDB.h"
#include "Act1DosDB.h"
#include "Act1UnoDI.h"
#include "Act1DosDI.h"
#include "Act1UnoDD.h"
#include "Act1DosDD.h"
#include "Mensaje.h"
#include <windows.h>
#include <MMSystem.h>
#include <msclr/marshal.h>

System::Void TutIntV30::PrincipalUno::SonidoInicio() {
	//PlaySound(TEXT("Audios/Oceano/Marlin.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoDory() {
	//PlaySound(TEXT("Audios/Oceano/Dory.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoTiburones() {
	//PlaySound(TEXT("Audios/Oceano/Tiburones.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoTortugas() {
	//PlaySound(TEXT("Audios/Oceano/Tortugas.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoNemo() {
	//PlaySound(TEXT("Audios/Oceano/Nemo.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoNemoPapa() {
	//PlaySound(TEXT("Audios/Oceano/Nemo-Papa.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoPulpo() {
	//PlaySound(TEXT("Audios/Oceano/perla nemo.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoPezAma() {
	//PlaySound(TEXT("Audios/Oceano/tad.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoPezGlobo() {
	//PlaySound(TEXT("Audios/Oceano/globo.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoTortu() {
	//PlaySound(TEXT("Audios/Oceano/chiqui.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::SonidoInicial() {
	//PlaySound(TEXT("Audios/Oceano/Inicio_mundo_del_oceano.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalUno::inicializarTamBotones() {
	wMarlin = btnMarlinD->Size.Width;
	hMarlin = btnMarlinD->Size.Height;
	wDory = btnDoryD->Size.Width;
	hDory = btnDoryD->Size.Height;
	wTiburones = btnTiburonesD->Size.Width;
	hTiburones = btnTiburonesD->Size.Height;
	wTortugas = btnTortugasD->Size.Width;
	hTortugas = btnTortugasD->Size.Height;
	wNemo = btnNemoD->Size.Width;
	hNemo = btnNemoD->Size.Height;
	hTortuH = btnTortuD->Size.Height;
	wTortuH = btnTortuD->Size.Width;
	hPulpo = btnPulpoD->Size.Height;
	wPulpo = btnPulpoD->Size.Width;
	hPezGlobo = btnPezGloD->Size.Height;
	wPezGlobo = btnPezGloD->Size.Width;
	hPezAma = btnPezAmaD->Size.Height;
	wPezAma = btnPezAmaD->Size.Width;
	wVolver = btnVolver->Size.Width;
	hVolver = btnVolver->Size.Height;
}
// Se llama al Agente Controlador para ver que actividad (personaje) desbloquear
System::Void TutIntV30::PrincipalUno::inicializarComponentesBD() {
	msclr::interop::marshal_context context;

	manejadorBD->setNombreHabilidad("Conciencia_fonologica");
	recuperacion->setNumSesion(manejadorBD->seleccionarNumeroSesion());
	recuperacion->setNombreJugador(manejadorBD->getNombreJugador());
	recuperacion->setNumUltimaActividad(manejadorBD->seleccionarActividadActual());
	recuperacion->setHabilidadActividad("Conciencia_fonologica");
	string dificultadActAnterior = manejadorBD->seleccionarDificultadActividadActual();
	recuperacion->setDificultadActividad(dificultadActAnterior);
	manejadorBD->setDificultad(context.marshal_as<String^>(dificultadActAnterior));
	string complejidadActAnterior = manejadorBD->seleccionarComplejidadActividadActual();
	recuperacion->setComplejidadActividad(complejidadActAnterior);
	manejadorBD->setComplejidad(context.marshal_as<String^>(complejidadActAnterior));

	recuperacion->setContadorAlto(manejadorBD->seleccionarContadorAlto());
	recuperacion->setContadorMedio(manejadorBD->seleccionarContadorMedio());
	recuperacion->setContadorBajo(manejadorBD->seleccionarContadorBajo());
	recuperacion->setProblemaGenerado(manejadorBD->seleccionarUltimoProblemaGenerado());
	recuperacion->setNivelActuacionRegla(manejadorBD->seleccionarUltimoNivelActuacion());
	recuperacion->setHistorialNivelActuacion(manejadorBD->seleccionarTotalActuacion());

	MessageBox::Show("Actividad Anterior: \nDificultad: " + context.marshal_as<String^>(recuperacion->getDificultadActividad()) + "\nComplejidad: " + context.marshal_as<String^>(recuperacion->getComplejidadActividad()) + "\nNivel Actuacion: " + context.marshal_as<String^>(recuperacion->getNivelActuacionRegla()) + "\nProblema: " + context.marshal_as<String^>(recuperacion->getProblemaGenerado()));
	controlador = new AgenteControlador("Conciencia_fonologica", recuperacion, manejadorBD->getNumSesion());
	vector<string> actividad = controlador->determinarActividad();

	vector<Regla*> reglasModificadas = controlador->getReglasMayorPeso();
	string reglas = "";
	if (reglasModificadas.size() > 0)
	{
		for (unsigned int x = 0; x < reglasModificadas.size(); x++)
		{
			reglas = reglas + reglasModificadas[x]->getCabeza()->getRelacion() + "(" + reglasModificadas[x]->getCabeza()->getArgumento()[0].getValor() + "):-";
			for (int y = 0; y < reglasModificadas[x]->getNumeroCondiciones(); y++)
			{
				reglas = reglas + reglasModificadas[x]->getCuerpo()[y]->getRelacion() + "(" + reglasModificadas[x]->getCuerpo()[y]->getArgumento()[0].getValor() + "), ";
			}
			reglas = reglas + "peso(" + to_string(reglasModificadas[x]->getPeso()) + ")\n";
		}
		MessageBox::Show(context.marshal_as<String^>(reglas));
	}
	lblEstrellas->Text = System::Convert::ToString(manejadorBD->seleccionarCantEstrellasHabilidad());
	salir = 0;
	if (actividad[0] == "FIN") {
		salir = 1;
		manejadorBD->ingresarDesbloqueoSiguienteHabilidad("Conciencia_alfabetica");
	}
	if (salir != 1) {
		recuperacion->setObjetivoActividad(manejadorBD->seleccionarObjetivoActividadActual());
		recuperacion->setPorcentajesActuacionMedio(manejadorBD->seleccionarPorcentajeActuacionMedio());

		MessageBox::Show("Actividad Actual: \nDificultad: " + context.marshal_as<String^>(actividad[0]) + "\nComplejidad: " + context.marshal_as<String^>(actividad[1]) + "\nNumero: " + context.marshal_as<String^>(actividad[2]));

		if (actividad[0] == "Basica") {					// Dificultad
			if (actividad[1] == "Basica") {				// Complejidad
				numAct = atoi(actividad[2].c_str());
				cargarActBB();
			}
			else if (actividad[1] == "Intermedia") {
				numAct = atoi(actividad[2].c_str());
				cargarActBI();
				SonidoInicial();
			}
			else if (actividad[1] == "Dificil") {
				numAct = atoi(actividad[2].c_str());
				cargarActBD();
			}
		}
		else if (actividad[0] == "Intermedia") {
			if (actividad[1] == "Basica") {
				numAct = atoi(actividad[2].c_str());
				cargarActIB();
			}
			else if (actividad[1] == "Intermedia") {
				numAct = atoi(actividad[2].c_str());
				cargarActII();
			}
			else if (actividad[1] == "Dificil") {
				numAct = atoi(actividad[2].c_str());
				cargarActID();
			}
		}
		else {
			if (actividad[1] == "Basica") {
				numAct = atoi(actividad[2].c_str());
				cargarActDB();
			}
			else if (actividad[1] == "Intermedia") {
				numAct = atoi(actividad[2].c_str());
				cargarActDI();
			}
			else if (actividad[1] == "Dificil") {
				numAct = atoi(actividad[2].c_str());
				cargarActDD();
			}
		}
	}
	else
	{
		//Si salir == 1
		gcnew Mensaje();

	}
}
System::Void TutIntV30::PrincipalUno::cargarActBB() {
	this->btnMarlinD->Visible = true;
	this->btnMarlinD->Enabled = true;
	this->btnMarlin->Visible = false;
}
System::Void TutIntV30::PrincipalUno::cargarActBI() {
	this->btnDoryD->Visible = true;
	this->btnDoryD->Enabled = true;
	this->btnDory->Visible = false;
}
System::Void TutIntV30::PrincipalUno::cargarActBD() {
	this->btnPulpoD->Visible = true;
	this->btnPulpoD->Enabled = true;
	this->btnPulpo->Visible = false;
}
System::Void TutIntV30::PrincipalUno::cargarActIB() {
	this->btnTortuD->Visible = true;
	this->btnTortuD->Enabled = true;
	this->btnTortu->Visible = false;
}
System::Void TutIntV30::PrincipalUno::cargarActII() {
	this->btnTiburonesD->Visible = true;
	this->btnTiburonesD->Enabled = true;
	this->btnTiburones->Visible = false;
}
System::Void TutIntV30::PrincipalUno::cargarActID() {
	this->btnPezAmaD->Visible = true;
	this->btnPezAmaD->Enabled = true;
	this->btnPezAma->Visible = false;
}
System::Void TutIntV30::PrincipalUno::cargarActDB() {
	this->btnTortugasD->Visible = true;
	this->btnTortugasD->Enabled = true;
	this->btnTortugas->Visible = false;
}
System::Void TutIntV30::PrincipalUno::cargarActDI() {
	this->btnPezGloD->Visible = true;
	this->btnPezGloD->Enabled = true;
	this->btnPezGlo->Visible = false;
}
System::Void TutIntV30::PrincipalUno::cargarActDD() {
	this->btnNemoD->Visible = true;
	this->btnNemoD->Enabled = true;
	this->btnNemo->Visible = false;
}
System::Void TutIntV30::PrincipalUno::btnTortuD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTortuD->Size = System::Drawing::Size(wTortuH, hTortuH);
}
System::Void TutIntV30::PrincipalUno::btnTortuD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTortuD->Size = System::Drawing::Size(wTortuH + 20, hTortuH + 20);
	SonidoTortu();
}
System::Void TutIntV30::PrincipalUno::btnPezAmaD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPezAmaD->Size = System::Drawing::Size(wPezAma + 20, hPezAma + 20);
	SonidoPezAma();
}
System::Void TutIntV30::PrincipalUno::btnPezAmaD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPezAmaD->Size = System::Drawing::Size(wPezAma, hPezAma);
}
System::Void TutIntV30::PrincipalUno::btnPezGloD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPezGloD->Size = System::Drawing::Size(wPezGlobo, hPezGlobo);
}
System::Void TutIntV30::PrincipalUno::btnPezGloD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPezGloD->Size = System::Drawing::Size(wPezGlobo + 20, hPezGlobo + 20);
	SonidoPezGlobo();
}
System::Void TutIntV30::PrincipalUno::btnPulpoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPulpoD->Size = System::Drawing::Size(wPulpo + 20, hPulpo + 20);
	SonidoPulpo();
}
System::Void TutIntV30::PrincipalUno::btnPulpoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnPulpoD->Size = System::Drawing::Size(wPulpo, hPulpo);
}
System::Void TutIntV30::PrincipalUno::btnMarlinD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnMarlinD->Size = System::Drawing::Size(wMarlin + 20, hMarlin + 20);
	SonidoNemoPapa();
}
System::Void TutIntV30::PrincipalUno::btnMarlinD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnMarlinD->Size = System::Drawing::Size(wMarlin, hMarlin);
}
System::Void TutIntV30::PrincipalUno::btnDoryD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnDoryD->Size = System::Drawing::Size(wDory, hDory);
}
System::Void TutIntV30::PrincipalUno::btnDoryD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnDoryD->Size = System::Drawing::Size(wDory + 20, hDory + 20);
	SonidoDory();
}
System::Void TutIntV30::PrincipalUno::btnTiburonesD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTiburonesD->Size = System::Drawing::Size(wTiburones + 20, hTiburones + 20);
	SonidoTiburones();
}
System::Void TutIntV30::PrincipalUno::btnTiburonesD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTiburonesD->Size = System::Drawing::Size(wTiburones, hTiburones);
}
System::Void TutIntV30::PrincipalUno::btnTortugasD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTortugasD->Size = System::Drawing::Size(wTortugas, hTortugas);
}
System::Void TutIntV30::PrincipalUno::btnTortugasD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnTortugasD->Size = System::Drawing::Size(wTortugas + 20, hTortugas + 20);
	SonidoTortugas();
}
System::Void TutIntV30::PrincipalUno::btnNemoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnNemoD->Size = System::Drawing::Size(wNemo + 20, hNemo + 20);
	SonidoNemo();
}
System::Void TutIntV30::PrincipalUno::btnNemoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalUno::btnNemoD->Size = System::Drawing::Size(wNemo, hNemo);
}
System::Void TutIntV30::PrincipalUno::btnTortuD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoIB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosIB(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnPezAmaD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoID(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosID(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnPezGloD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoDI(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosDI(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnPulpoD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoBD(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosBD(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnMarlinD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoBB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosBB(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnDoryD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoBI(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosBI(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnTiburonesD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoII(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosII(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnTortugasD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoDB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosDB(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnNemoD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		gcnew Act1UnoDD(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		gcnew Act1DosDD(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalUno::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew NivelUno(this, manejadorBD);
}
System::Void TutIntV30::PrincipalUno::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void TutIntV30::PrincipalUno::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::PrincipalUno::btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
	SonidoInicial();
}
System::Void TutIntV30::PrincipalUno::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		this->form->Close();
		if (manejadorBD->getNumSesion() == 0)
		{
			//PlaySound(TEXT("Audios/Inicio/principalUno.wav"), NULL, SND_ASYNC);
		}
	}
}
System::Void TutIntV30::PrincipalUno::PrincipalUno_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::PrincipalUno::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void TutIntV30::PrincipalUno::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::PrincipalUno::PrincipalUno_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::PrincipalUno::PrincipalUno_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}

