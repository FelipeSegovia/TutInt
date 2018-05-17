#include "ManejadorMI.h"
#include "MotorDeInferencia.h"
#include "BaseDeConocimiento.h"
#include "BaseDeHechos.h"
#include "Hecho.h"
#include "Conector.h"
#include "LeerArchivo.h"
#include <vector>
#include <string.h>

using namespace System::Threading;

ManejadorMI::ManejadorMI(string nombreArchivo)
{
	archivo = new LeerArchivo();
	archivo->lectura(nombreArchivo);
	conector1 = Conector::obtenerConector();

	baseConocimiento = conector1->obtenerBaseDeConocimiento();
	baseConocimiento->ordenarMenorAMayor();

	baseHechos = conector1->obtenerBaseDeHechos();

}

ManejadorMI::~ManejadorMI() {}

void ManejadorMI::insertar(string habilidad, string level, int numActividad, string respuesta) {
	baseHechos->agregarHecho(new Hecho("habilidad", Argumento(habilidad), VERDADERO));
	baseHechos->agregarHecho(new Hecho("actividad", Argumento(level), VERDADERO));
	baseHechos->agregarHecho(new Hecho("itemAct", Argumento(to_string(numActividad)), VERDADERO));
	baseHechos->agregarHecho(new Hecho("respuesta", Argumento(respuesta), VERDADERO)); //el vector parte del 0
}

void ManejadorMI::insertar2(string habilidad, string level, vector<string> respuestas)
{
	for (unsigned int i = 0; i < respuestas.size(); i++) {
		baseHechos->agregarHecho(new Hecho("habilidad", Argumento(habilidad), VERDADERO));
		baseHechos->agregarHecho(new Hecho("actividad", Argumento(level), VERDADERO));
		baseHechos->agregarHecho(new Hecho("itemAct", Argumento(to_string(i + 1)), VERDADERO));
		baseHechos->agregarHecho(new Hecho("respuesta", Argumento(respuestas[i]), VERDADERO)); //el vector parte del 0
		ejecutarMotorInferencia();
		baseHechos->borrarHechos();
	}
	baseHechos->borrarHechos();
	calcularNivLogroActividad();
}

void ManejadorMI::borrarHechos()
{
	baseHechos->borrarHechos();
}

void ManejadorMI::iniciarHechos() {
	baseHechos = conector1->obtenerBaseDeHechos();
}


void ManejadorMI::ejecutarMotorInferencia()
{
	motorInferencia = new MotorDeInferencia(baseHechos, baseConocimiento);
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("calificacion", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		if (motorInferencia->getTerminoInferencia()) {
			if (resultado->getEstado() == VERDADERO) {
				if (motorInferencia != nullptr)
				{
					motorInferencia->setDetenerInferencia(true);
				}
				contadorBuenas++;
			}
			else {
				if (motorInferencia != nullptr)
				{
					motorInferencia->setDetenerInferencia(true);
				}
				contadorMalas++;
			}
		}
	}
}

void ManejadorMI::calcularNivLogroActividad() {
	int porcentaje = ((contadorBuenas * 100) / (contadorBuenas + contadorMalas));
	baseHechos->agregarHecho(new Hecho("porcentaje", Argumento(to_string(porcentaje)), VERDADERO));
	motorInferencia = new MotorDeInferencia(baseHechos, baseConocimiento);
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("nivelLogroAct", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		string res = resultado->getArgumento()[0].ToString();
		nivelLogroAct = gcnew String(res.c_str());
	}
}

void ManejadorMI::calcularNivLogroHabilidad(int cantAct, int cantLogrado) {
	int porcentaje = ((100 * cantLogrado) / cantAct);
	baseHechos->agregarHecho(new Hecho("porcentaje", Argumento(to_string(porcentaje)), VERDADERO));
	motorInferencia = new MotorDeInferencia(baseHechos, baseConocimiento);
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("nivelLogroHab", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		string res = resultado->getArgumento()[0].ToString();
		nivelLogroHab = gcnew String(res.c_str());
	}
	ejecutarMIHabilidad();
}

void ManejadorMI::ejecutarMIHabilidad() {
	motorInferencia = new MotorDeInferencia(baseHechos, baseConocimiento);
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("sgteHabilidad", ENCADENAMIENTO_ATRAS);
	if (motorInferencia->getTerminoInferencia()) {
		if (motorInferencia->getTerminoInferencia()) {
			string res = resultado->getArgumento()[0].ToString();
			sgteHab = gcnew String(res.c_str());
		}
	}
	baseHechos->borrarHechos();
}

bool ManejadorMI::getSgteHab() {
	if (sgteHab == "Avanza") {
		return true;
	}
	else {
		return false;
	}
}

String^ ManejadorMI::getNumeroDeEstrellas()
{
	String^ cantidad = "";
	if (nivelLogroAct == "Logrado") {
		cantidad = "3";
		return cantidad;
	}
	else if (nivelLogroAct == "Medianamente_Logrado")
	{
		cantidad = "2";
		return cantidad;
	}
	else if (nivelLogroAct == "No_Logrado")
	{
		cantidad = "1";
		return cantidad;
	}
	return cantidad;
}

String^ ManejadorMI::getNivLogroActividad()
{
	return nivelLogroAct;
}

int ManejadorMI::getContadorBuenas()
{
	return contadorBuenas;
}

int ManejadorMI::getContadorMalas()
{
	return contadorMalas;
}