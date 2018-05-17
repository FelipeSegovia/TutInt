#ifndef EVALUADOR_H
#define EVALUADOR_H

#include "ConectorEvaluador.h"
#include "LeerArchivoEvaluador.h"
#include "MotorDeInferencia.h"
#include <vector>
#include <string>

public class Evaluador {

private:
	ConectorEvaluador* conectorEvaluador;
	LeerArchivoEvaluador* lecturaArchivo;
	MotorDeInferencia* motorInferencia;
	std::vector<std::string> respuestas;
	std::string habilidad;
	int actividad;
	int contBuenas;
	int contMalas;
	std::string dif;
	std::string compl;
	std::string nivelLogroAct;

public:
	Evaluador(std::string hab, int act, std::vector<std::string> resp, string dificultad, string complejidad);
	Evaluador();
	~Evaluador();
	std::string revisarActividad();					// Retorna nivel de logro act
	void obtenerEstadoRespuesta();					// Buena o Mala
	std::string determinarNivelLogroActividad(int porcentaje);
	int getContBuenas();
	int getContMalas();
	std::string getNivelLogroAct();
};
#endif // EVALUADOR_H