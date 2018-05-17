#pragma once
#ifndef LEERARCHIVOEVALUADOR_H
#define LEERARCHIVOEVALUADOR_H
#include "ConectorEvaluador.h"

class LeerArchivoEvaluador {

public:
	LeerArchivoEvaluador();
	~LeerArchivoEvaluador();
	void lecturaEvaluador();

private:
	ConectorEvaluador *conectorEvaluador;
};

#endif // LEERARCHIVO_H