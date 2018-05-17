#ifndef PERCEPCIONES_H
#define PERCEPCIONES_H

#include "TiempoMI.h"
#include<vector>
#include<string>

using namespace System;

public class Percepciones {

private:
	// Percepciones	
	std::vector<std::string> respuestas;		// Respuesta de la actividad realizada
	std::vector<TiempoMI*> tiempoItems;		// Eficacia
	std::string nivelLogro;					// Desempeño
	TiempoMI* tiempoAct;						// Motivacion
	int cantAyuda;							// Autonomía
	int actividad;
	std::string habilidad;
	std::string complejidad;					// Nivel de Complejidad
	std::string dificultad;					// Nivel de Dificultad
	std::string objetivo;					// Objetivo a lograr
	double nivelActuacion;					// Nivel obtenido del usuario
	std::string totalActuacion;
	std::string nivelActuacionEscrito;
	double porcentAutonomia;
	double porcentEficacia;
	double porcentMotivacion;
	double porcentLogro;

public:
	Percepciones();
	Percepciones(int act, std::string hab, std::string compl, std::string dific, std::string obj);
	Percepciones(std::string nivLogro, int ayuda, std::vector<TiempoMI*> timeItems, TiempoMI* timeAct, std::string obj);
	~Percepciones();
	std::vector<std::string> getRespuestas();
	std::string getNivelLogro();
	void setRespuestas(std::vector<std::string> resp);
	void setNivelLogro(std::string nivLogro);
	void setCantAyuda(int ayuda);
	void setTiempoItems(std::vector<TiempoMI*> timeItems);
	void setTiempoAct(TiempoMI* timeAct);
	void setActividad(int act);
	void setObjetivo(std::string obj);
	void setNivelActuacion(double nivActuacion);
	void setDificultad(std::string dific);
	void setHabilidad(std::string hab);
	void setComplejidad(std::string compl);
	void setTotalActuacion(std::string total);
	void setNivelActuacionEscrito(std::string nivActuacionEscrito);
	void setPorcentAutonomia(double _porcentAutonomia);
	void setPorcentEficacia(double _porcentEficacia);
	void setPorcentMotivacion(double _porcentMotivacion);
	void setPorcentLogro(double _porcentPorcentLogro);
	int getCantAyuda();
	std::string getTotalActuacion();
	std::string getNivelActuacionEscrito();
	std::vector<TiempoMI*> getTiempoItems();
	TiempoMI* getTiempoAct();
	int getActividad();
	std::string getHabilidad();
	std::string getObjetivo();
	std::string getComplejidad();
	std::string getDificultad();
	double getNivelActuacion();
	double getPorcentAutonomia();
	double getPorcentEficacia();
	double getPorcentMotivacion();
	double getPorcentLogro();
};
#endif // PERCEPCIONES_H
