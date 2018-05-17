#include "Evaluador.h"
#include "Hecho.h"
#include "Argumento.h"

using namespace std;

Evaluador::Evaluador(std::string hab, int act, std::vector<std::string> resp, string dificultad, string complejidad) {
	habilidad = hab;
	actividad = act;
	respuestas = resp;
	dif = dificultad;
	compl= complejidad;
	contBuenas = 0;
	contMalas = 0;
	lecturaArchivo = new LeerArchivoEvaluador();
	lecturaArchivo->lecturaEvaluador();
	conectorEvaluador = ConectorEvaluador::obtenerConectorEvaluador();
}

Evaluador::Evaluador(){
	lecturaArchivo = new LeerArchivoEvaluador();
	lecturaArchivo->lecturaEvaluador();
	conectorEvaluador = ConectorEvaluador::obtenerConectorEvaluador();
}

Evaluador::~Evaluador() {}

string Evaluador::revisarActividad() {
	for (unsigned int i = 0; i < respuestas.size(); i++) {
		conectorEvaluador->agregarHecho(new Hecho("habilidad", Argumento(habilidad), VERDADERO));
		conectorEvaluador->agregarHecho(new Hecho("dificultad", Argumento(dif), VERDADERO));
		conectorEvaluador->agregarHecho(new Hecho("complejidad", Argumento(compl), VERDADERO));
		conectorEvaluador->agregarHecho(new Hecho("actividad", Argumento(to_string(actividad)), VERDADERO));
		conectorEvaluador->agregarHecho(new Hecho("itemAct", Argumento(to_string(i + 1)), VERDADERO));
		conectorEvaluador->agregarHecho(new Hecho("respuesta", Argumento(respuestas[i]), VERDADERO));
		obtenerEstadoRespuesta();
		conectorEvaluador->borrarHechos();
	}
	conectorEvaluador->borrarHechos();
	return nivelLogroAct;
}

void Evaluador::obtenerEstadoRespuesta() {
	motorInferencia = new MotorDeInferencia(conectorEvaluador->obtenerBaseDeHechos(), conectorEvaluador->obtenerBaseDeConocimiento());
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("calificacion", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		if (motorInferencia->getTerminoInferencia()) {
			if (resultado->getEstado() == VERDADERO) {
				if (motorInferencia != nullptr)
				{
					motorInferencia->setDetenerInferencia(true);
				}
				contBuenas++;
			}
			else {
				if (motorInferencia != nullptr)
				{
					motorInferencia->setDetenerInferencia(true);
				}
				contMalas++;
			}
		}
	}
}

string Evaluador::determinarNivelLogroActividad(int porcentaje) {
	conectorEvaluador->agregarHecho(new Hecho("porcentaje", Argumento(to_string(porcentaje)), VERDADERO));

	motorInferencia = new MotorDeInferencia(conectorEvaluador->obtenerBaseDeHechos(), conectorEvaluador->obtenerBaseDeConocimiento());
	Hecho *resultado = nullptr;
	resultado = motorInferencia->ejecutar("nivelLogroAct", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		string res = resultado->getArgumento()[0].ToString();
		return res;
	}
	return nullptr;
}

int Evaluador::getContBuenas() {
	return contBuenas;
}

int Evaluador::getContMalas() {
	return contMalas;
}

string Evaluador::getNivelLogroAct() {
	return nivelLogroAct;
}