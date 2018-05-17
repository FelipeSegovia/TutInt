#include "FormEstrella.h"
#include "PrincipalUno.h"
//#include "PrincipalDos.h"
//#include "PrincipalTres.h"
//#include "PrincipalCuatro.h"
//#include "PrincipalCinco.h"

System::Void TutIntV30::FormEstrella::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	int estrellas = numEstrellas;
	// para el nivel.
	int cantEstrellasNivelActual = manejadorBD->seleccionarCantEstrellasNivel() + estrellas;
	manejadorBD->ingresarActualizarDatosEstrellasNivel(cantEstrellasNivelActual);
	// para la habilidad.
	int cantEstrellasHabActual = manejadorBD->seleccionarCantEstrellasHabilidad() + estrellas;
	manejadorBD->ingresarActualizarDatosEstrellasHabilidad(cantEstrellasHabActual);
	// para las estrellas totales
	int cantEstrellasTotalActual = manejadorBD->seleccionarTotalEstrellas() + estrellas;
	manejadorBD->ingresarActualizarDatosEstrellasTotales(cantEstrellasTotalActual);

	controlador->actualizarBaseConocimientoUsuario();
	determinarFormHabilidad();
	this->Close();
}

System::Void TutIntV30::FormEstrella::determinarFormHabilidad() {

	if ((habilidad == "Conciencia_fonologica") &&
		(manejadorBD->seleccionarDificultadActividadActual() == "Dificil") &&
		(manejadorBD->seleccionarComplejidadActividadActual() == "Dificil") &&
		(manejadorBD->seleccionarActividadActual() ==  1) ||
		(manejadorBD->seleccionarActividadActual() == 2))
	{
		//PrincipalDos^ principal = gcnew PrincipalDos(formActividad, manejadorBD);
	}
	else
	{

		if (habilidad == "Conciencia_fonologica") {
			PrincipalUno^ principal = gcnew PrincipalUno(formActividad, manejadorBD);
		}
		else if (habilidad == "Conciencia_alfabetica") {
			//PrincipalDos^ principal = gcnew PrincipalDos(formActividad, manejadorBD);
		}
		else if (habilidad == "Vocabulario") {
			//PrincipalTres^ principal = gcnew PrincipalTres(formActividad, manejadorBD);
		}
		else if (habilidad == "Comprension_literal") {
			//PrincipalCuatro^ principal = gcnew PrincipalCuatro(formActividad, manejadorBD);
		}
		else if (habilidad == "Comprension_inferencial") {
			//PrincipalCinco^ principal = gcnew PrincipalCinco(formActividad, manejadorBD);
		}
	}
}

System::Void TutIntV30::FormEstrella::FormEstrella_Load(System::Object^  sender, System::EventArgs^  e) {
	if (numEstrellas == 1)
	{
		mensaje1->Visible = false;
		mensaje2->Visible = false;
		mensaje3->Visible = true;
		estrellaUno->Visible = true;
		estrellaDos->Visible = false;
		estrellaTres->Visible = false;
		estrellaDosE->Visible = true;
		estrellaTresE->Visible = true;
	}
	else if (numEstrellas == 2) {
		mensaje1->Visible = false;
		mensaje2->Visible = true;
		mensaje3->Visible = false;
		estrellaUno->Visible = true;
		estrellaDos->Visible = true;
		estrellaTres->Visible = false;
		estrellaTresE->Visible = true;
	}
	else {
		mensaje1->Visible = true;
		mensaje2->Visible = false;
		mensaje3->Visible = false;
		estrellaUno->Visible = true;
		estrellaDos->Visible = true;
		estrellaTres->Visible = true;
	}
	this->timer1->Start();
}
System::Void TutIntV30::FormEstrella::timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->Opacity += .1;
	//Detener el timer
	if (this->Opacity == 1) {
		this->timer1->Stop();
	}
}