#ifndef MOTORDEINFERENCIA_H
#define MOTORDEINFERENCIA_H

#include "BaseDeHechos.h"
#include "BaseDeConocimiento.h"
#include "Hecho.h"
#include "Regla.h"
#include <string>

using namespace std;

const int ENCADENAMIENTO_ATRAS = 0;
const int ENCADENAMIENTO_ADELANTE = 1;

class MotorDeInferencia {

private:
	BaseDeHechos *baseHechos;
	BaseDeConocimiento *baseConocimiento;
	Regla *reglaInferida;
	bool terminoInferencia = false;
	bool detenerInferencia = false;
	//string justificacion = "";
	int nivel = 0;

public:
	MotorDeInferencia(BaseDeHechos *baseHechos, BaseDeConocimiento *baseConocimiento);
	~MotorDeInferencia();
	Hecho* encadenamientoHaciaAdelante(string hecho);
	Hecho* encadenamientoHaciaAtras(Hecho *hechoMeta);
	Hecho* ejecutar(string objetivo, int encadenamiento);
	void setDetenerInferencia(bool value);
	bool getTerminoInferencia();
	Regla* getReglaInferida();
	//string getJustificacion();
};
#endif // MOTORDEINFERENCIA_H