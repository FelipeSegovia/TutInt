#include "PrincipalDos.h"
#include "NivelUno.h"
#include <windows.h>
#include <MMSystem.h>

System::Void TutIntV30::PrincipalDos::inicializarTamBotones() {
	wBob = btnBobEsponjaD->Size.Width;
	hBob = btnBobEsponjaD->Size.Height;
	wCalamardo = btnCalamardoD->Size.Width;
	hCalamardo = btnCalamardoD->Size.Height;
	wPatricio = btnPatricioD->Size.Width;
	hPatricio = btnPatricioD->Size.Height;
	wGary = btnGaryD->Size.Width;
	hGary = btnGaryD->Size.Height;
	wArenita = btnArenitaD->Size.Width;
	hArenita = btnArenitaD->Size.Height;
	wPuff = btnPuffD->Size.Width;
	hPuff = btnPuffD->Size.Height;
	wCangrejo = btnCangrejoD->Size.Width;
	hCangrejo = btnCangrejoD->Size.Height;
	wPlankton = btnPlanktonD->Size.Width;
	hPlankton = btnPlanktonD->Size.Height;
	wPerla = btnPerlaD->Size.Width;
	hPerla = btnPerlaD->Size.Height;
	wVolver = btnVolver->Size.Width;
	hVolver = btnVolver->Size.Height;
}
System::Void TutIntV30::PrincipalDos::inicializarComponentesBD() {
	msclr::interop::marshal_context context;

	manejadorBD->setNombreHabilidad("Conciencia_alfabetica");
	recuperacion->setNumSesion(manejadorBD->seleccionarNumeroSesion());
	recuperacion->setNombreJugador(manejadorBD->getNombreJugador());
	recuperacion->setNumUltimaActividad(manejadorBD->seleccionarActividadActual());
	recuperacion->setHabilidadActividad("Conciencia_alfabetica");
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

	controlador = new AgenteControlador("Conciencia_alfabetica", recuperacion, manejadorBD->getNumSesion());
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
		manejadorBD->ingresarDesbloqueoSiguienteHabilidad("Vocabulario");
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
}
System::Void TutIntV30::PrincipalDos::cargarActBB() {
	this->btnPatricioD->Visible = true;
	this->btnPatricioD->Enabled = true;
	this->btnPatricio->Visible = false;
}
System::Void TutIntV30::PrincipalDos::cargarActBI() {
	this->btnBobEsponjaD->Visible = true;
	this->btnBobEsponjaD->Enabled = true;
	this->btnBobEsponja->Visible = false;
}
System::Void TutIntV30::PrincipalDos::cargarActBD() {
	this->btnPlanktonD->Visible = true;
	this->btnPlanktonD->Enabled = true;
	this->btnPlankton->Visible = false;
}
System::Void TutIntV30::PrincipalDos::cargarActIB() {
	this->btnCangrejoD->Visible = true;
	this->btnCangrejoD->Enabled = true;
	this->btnCangrejo->Visible = false;
}
System::Void TutIntV30::PrincipalDos::cargarActII() {
	this->btnArenitaD->Visible = true;
	this->btnArenitaD->Enabled = true;
	this->btnArenita->Visible = false;
}
System::Void TutIntV30::PrincipalDos::cargarActID() {
	this->btnCalamardoD->Visible = true;
	this->btnCalamardoD->Enabled = true;
	this->btnCalamardo->Visible = false;
}
System::Void TutIntV30::PrincipalDos::cargarActDB() {
	this->btnPerlaD->Visible = true;
	this->btnPerlaD->Enabled = true;
	this->btnPerla->Visible = false;
}
System::Void TutIntV30::PrincipalDos::cargarActDI() {
	this->btnPuffD->Visible = true;
	this->btnPuffD->Enabled = true;
	this->btnPuff->Visible = false;
}
System::Void TutIntV30::PrincipalDos::cargarActDD() {
	this->btnGaryD->Visible = true;
	this->btnGaryD->Enabled = true;
	this->btnGary->Visible = false;
}
System::Void TutIntV30::PrincipalDos::btnPlanktonD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPlanktonD->Size = System::Drawing::Size(wPlankton + 20, hPlankton + 20);
	SonidoPlankton();
}
System::Void TutIntV30::PrincipalDos::btnPlanktonD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPlanktonD->Size = System::Drawing::Size(wPlankton, hPlankton);
}
System::Void TutIntV30::PrincipalDos::btnPuffD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPuffD->Size = System::Drawing::Size(wPuff + 20, hPuff + 20);
	SonidoPuff();
}
System::Void TutIntV30::PrincipalDos::btnPuffD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPuffD->Size = System::Drawing::Size(wPuff, hPuff);
}
System::Void TutIntV30::PrincipalDos::btnPerlaD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPerlaD->Size = System::Drawing::Size(wPerla + 20, hPerla + 20);
	SonidoPerla();
}
System::Void TutIntV30::PrincipalDos::btnPerlaD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPerlaD->Size = System::Drawing::Size(wPerla, hPerla);
}
System::Void TutIntV30::PrincipalDos::btnCangrejoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnCangrejoD->Size = System::Drawing::Size(wCangrejo + 20, hCangrejo + 20);
	SonidoCangrejo();
}
System::Void TutIntV30::PrincipalDos::btnCangrejoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnCangrejoD->Size = System::Drawing::Size(wCangrejo, hCangrejo);
}
System::Void TutIntV30::PrincipalDos::btnBobEsponjaD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnBobEsponjaD->Size = System::Drawing::Size(wBob + 20, hBob + 20);
	SonidoBob();
}
System::Void TutIntV30::PrincipalDos::btnBobEsponjaD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnBobEsponjaD->Size = System::Drawing::Size(wBob, hBob);
}
System::Void TutIntV30::PrincipalDos::btnCalamardoD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnCalamardoD->Size = System::Drawing::Size(wCalamardo + 20, hCalamardo + 20);
	SonidoCalamardo();
}
System::Void TutIntV30::PrincipalDos::btnCalamardoD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnCalamardoD->Size = System::Drawing::Size(wCalamardo, hCalamardo);
}
System::Void TutIntV30::PrincipalDos::btnPatricioD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPatricioD->Size = System::Drawing::Size(wPatricio + 20, hPatricio + 20);
	SonidoPatricio();
}
System::Void TutIntV30::PrincipalDos::btnPatricioD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnPatricioD->Size = System::Drawing::Size(wPatricio, hPatricio);
}
System::Void TutIntV30::PrincipalDos::btnGaryD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnGaryD->Size = System::Drawing::Size(wGary + 20, hGary + 20);
	SonidoGary();
}
System::Void TutIntV30::PrincipalDos::btnGaryD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnGaryD->Size = System::Drawing::Size(wGary, hGary);
}
System::Void TutIntV30::PrincipalDos::btnArenitaD_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnArenitaD->Size = System::Drawing::Size(wArenita + 20, hArenita + 20);
	SonidoArenita();
}
System::Void TutIntV30::PrincipalDos::btnArenitaD_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	PrincipalDos::btnArenitaD->Size = System::Drawing::Size(wArenita, hArenita);
}
System::Void TutIntV30::PrincipalDos::btnPuffD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoDI(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosDI(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnPerlaD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoDB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosDB(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnCangrejoD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoIB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosIB(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnPlanktonD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoBD(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosBD(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnBobEsponjaD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoBI(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosBI(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnPatricioD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoBB(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosBB(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnGaryD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoDD(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosDD(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnArenitaD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoII(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosII(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnCalamardoD_Click(System::Object^  sender, System::EventArgs^  e) {
	if (numAct == 1) {
		//gcnew Actividad2UnoID(this, manejadorBD, controlador);
	}
	else if (numAct == 2) {
		//gcnew Actividad2DosID(this, manejadorBD, controlador);
	}
}
System::Void TutIntV30::PrincipalDos::btnVolver_Click(System::Object^  sender, System::EventArgs^  e) {
	gcnew NivelUno(this, manejadorBD);
}
System::Void TutIntV30::PrincipalDos::btnVolver_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver + 10, hVolver + 10);
}
System::Void TutIntV30::PrincipalDos::btnVolver_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	this->btnVolver->Size = System::Drawing::Size(wVolver, hVolver);
}
System::Void TutIntV30::PrincipalDos::SonidoBob() {
	//PlaySound(TEXT("Audios/Playa/Bob-Esponja.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoCalamardo() {
	//PlaySound(TEXT("Audios/Playa/Calamardo.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoPatricio() {
	//PlaySound(TEXT("Audios/Playa/Patricio.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoArenita() {
	//PlaySound(TEXT("Audios/Playa/Arenita.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoGary() {
	//PlaySound(TEXT("Audios/Playa/Gary.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoPuff() {
	//PlaySound(TEXT("Audios/Playa/señoraPuff.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoPerla() {
	//PlaySound(TEXT("Audios/Playa/perlita.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoPlankton() {
	//PlaySound(TEXT("Audios/Playa/plankton.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoCangrejo() {
	//PlaySound(TEXT("Audios/Playa/DonCangrejo.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::SonidoBobGary() {
	//PlaySound(TEXT("Audios/Playa/Bob-Esponja-Final.wav"), NULL, SND_ASYNC);
}
System::Void TutIntV30::PrincipalDos::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
		//this->form->Hide();
	}
}
System::Void TutIntV30::PrincipalDos::PrincipalDos_Load(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::PrincipalDos::picCerrar_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
System::Void TutIntV30::PrincipalDos::picMinimizar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}
System::Void TutIntV30::PrincipalDos::PrincipalDos_Activated(System::Object^  sender, System::EventArgs^  e) {
	this->timer1->Start();
}
System::Void TutIntV30::PrincipalDos::PrincipalDos_Deactivate(System::Object^  sender, System::EventArgs^  e) {
	if (this->WindowState == FormWindowState::Minimized) {
		this->Opacity = 0;
	}
}