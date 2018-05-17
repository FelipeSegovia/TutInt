#ifndef MANEJADORMI_H
#define MANEJADORMI_H

#include "MotorDeInferencia.h"
#include "BaseDeConocimiento.h"
#include "BaseDeHechos.h"
#include "Hecho.h"
#include "Conector.h"
#include "LeerArchivo.h"
#include <Windows.h>
//Encadenamiento adelante para ver si las respuestas del usuario estan buenas
//Encadenamiento atras para saber si pasa a la otra o tiene que repetirla

using namespace System;

public ref class ManejadorMI {

public:
	ManejadorMI(string nombreArchivo);
	~ManejadorMI();
	void insertar(string habilidad, string level, int numActividad, string resp);
	void insertar2(string habilidad, string level, vector<string> respuestas);
	void borrarHechos();
	void iniciarHechos();
	void ejecutarMotorInferencia();
	void calcularNivLogroActividad();
	void calcularNivLogroHabilidad(int cantAct, int cantLogrado);
	void ejecutarMIHabilidad();
	String^ getNumeroDeEstrellas();
	String^ getNivLogroActividad();
	int getContadorBuenas();
	int getContadorMalas();
	bool getSgteHab();

private:
	BaseDeHechos* baseHechos;
	BaseDeConocimiento* baseConocimiento;
	MotorDeInferencia* motorInferencia;
	Conector* conector1;
	Conector* conector2;
	LeerArchivo *archivo;
	int contadorBuenas = 0;
	int contadorMalas = 0;
	String^ nivelLogroAct;
	String^ nivelLogroHab;
	String^ sgteHab;
};
#endif // !MANEJADORMI_H



