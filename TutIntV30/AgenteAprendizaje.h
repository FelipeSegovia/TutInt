#ifndef AGENTEAPRENDIZAJE_H
#define AGENTEAPRENDIZAJE_H

#include "MotorDeInferencia.h"
#include "RangosTiempo.h"
#include "BaseDeDatos.h"
#include "Percepciones.h"
#include "Recuperacion.h"
#include "Conector.h"
#include "Regla.h"
#include <vector>
#include <string>

using namespace std;

public class AgenteAprendizaje {

private:
	MotorDeInferencia *motorInferencia;
	Percepciones *percepciones;
	Recuperacion *recuperacion;
	Conector *conector;
	string nivelAutonomia;
	string nivelEficacia;
	string nivelMotivacion;
	string nivelLogro;
	string critica;
	string totalActuacion;
	Regla *nivelActuacion;
	Regla *progresoActual;
	int contadorAlto;			// Contador progreso = Mantiene en rangoActuacion = Alto
	int contadorMedio;			// Contador progreso = Mantiene en rangoActuacion = Medio
	int contadorBajo;			// Contador progreso = Mantiene en rangoActuacion = Bajo
	double porcentActuacion;

public:
	AgenteAprendizaje(Percepciones *p, Recuperacion *_recuperacion);
	~AgenteAprendizaje();
	int obtenerCritica();
	Regla* generarProblema();
	void realimentarElementoAprendizaje(/*critica tipo string?*/);
	vector<Regla*> determinarElementoActuacion();
	string getNivelAutonomia();												// Cantidad ayuda
	string getNivelEficacia();												// Tiempo respuestas
	string getNivelMotivacion();												// Tiempo actividad
	string getNivelLogro();													// Nivel de logro actividad
	void setPorcentActuacion(double porcent);
	double getPorcentActuacion();
};
#endif // AGENTEAPRENDIZAJE_H