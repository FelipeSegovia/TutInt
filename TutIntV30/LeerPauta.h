#pragma once
#ifndef LEER_PAUTA
#define LEER_PAUTA

#include <string>
#include <map>
#include <fstream>
#include "Pauta.h"
#include <iostream>

using namespace std;

class LeerPauta
{
public:
	LeerPauta(string ruta);
	~LeerPauta();
	void leer();
	vector<Pauta> getPauta();
private:
	string link;
	Pauta evaluador;
	vector<Pauta> pauta; //Aqui se contiene todas las respuestas

};

#endif // !LEER_PAUTA
