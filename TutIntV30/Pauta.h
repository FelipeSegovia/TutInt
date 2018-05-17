#pragma once
#ifndef PAUTA_H
#define PAUTA_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Pauta
{

public:
	Pauta();
	~Pauta();
	void setHabilidad(string hab);
	void setDificultad(string dific);
	void setComplejidad(string compl);
	void setActividad(string act);
	void setRespuestas(vector<string> resp);
	string getHabilidad();
	string getDificultad();
	string getComplejidad();
	string getActividad();
	vector<string> getRespuestas();

private:
	vector<string> respuestas;
	string habilidad;
	string dificultad;
	string complejidad;
	string actividad;

};

#endif // !PAUTA_H
