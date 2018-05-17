#pragma once
#ifndef CONECTOREVALUADOR_H
#define CONECTOREVALUADOR_H

#include <string>
#include "BaseDeHechos.h"
#include "Hecho.h"
#include "BaseDeConocimiento.h"
#include "Regla.h"


class ConectorEvaluador {

public:
	ConectorEvaluador();
	~ConectorEvaluador();
	static ConectorEvaluador* obtenerConectorEvaluador();
	void agregarRegla(Regla *regla);
	void agregarHecho(Hecho *hecho);
	void borrarHechos();
	bool getLeyendoRegla();
	void inicioRegla();
	void finRegla();
	Regla* transformarStringRegla(string _regla);
	BaseDeConocimiento* obtenerBaseDeConocimiento();
	BaseDeHechos* obtenerBaseDeHechos();
	void cerrarArchivo();
	string pasarReglaString(Regla* regla);
	string ToString();

private:
	static ConectorEvaluador *conectorEvaluador;
	BaseDeConocimiento *reglas;
	BaseDeHechos *hechos;
	bool leyendoRegla = false;
};
#endif // CONECTOREVALUADOR_H