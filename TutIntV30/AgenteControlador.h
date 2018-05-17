#ifndef AGENTECONTROLADOR_H
#define AGENTECONTROLADOR_H

#include "AgenteAprendizaje.h"
#include "LeerArchivo.h"
#include "Percepciones.h"
#include "Evaluador.h"
#include "MotorDeInferencia.h"
#include "Recuperacion.h"
#include "LeerPauta.h"
#include "Pauta.h"
#include <string>

using namespace std;

public class AgenteControlador {


private:
	LeerArchivo *archivo;
	Conector *conector;
	Percepciones *percepciones;
	MotorDeInferencia* motorInferencia;
	Recuperacion *recuperacion;
	AgenteAprendizaje* agenteAprende;
	int numSesion;
	int contBuenas = 0;
	int contMalas = 0;
	string problema = "";			// Regla del problema generado
	string actuacion = "";			// Regla del nivel de actuacion obtenido
	double porcentActuacion;

public:
	AgenteControlador(string habilidad, Recuperacion *_recuperacion, int sesion);
	~AgenteControlador();
	vector<string> determinarActividad();
	Percepciones* getPercepciones();
	Recuperacion* getRecuperacion();
	int getRespuestasBuenas();
	int getRespuestasMalas();
	string getProblema();
	string getActuacion();
	void evaluarActividad();
	void obtenerNivelLogro();
	void actualizarBaseConocimientoUsuario();
	vector<Regla*> getReglasMayorPeso();
	void setPercepcionesActividad(vector<string> resp, int ayuda, vector<TiempoMI*> timeItems, TiempoMI* timeAct);
	void setPercepcionesActividad(vector<string> resp, int ayuda, vector<TiempoMI*> timeItems, TiempoMI* timeAct, string nivLogro);
	void setPercepcionesHabilidad(string habilidad, int actividad);
	void setPercepcionesNivelActividad(string habilidad, string dificultad, string complejidad, int numAct);
	void setNumSesion(int _numSesion);
	vector<Regla*> getBC();
};

#endif // AGENTECONTROLADOR_H