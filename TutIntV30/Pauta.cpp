#include "Pauta.h"

Pauta::Pauta() {}

Pauta::~Pauta() {}


void Pauta::setHabilidad(string hab)
{
	habilidad = hab;
}

void Pauta::setDificultad(string dific)
{
	dificultad = dific;
}

void Pauta::setComplejidad(string compl)
{
	complejidad = compl;
}

void Pauta::setActividad(string act)
{
	actividad = act;
}

void Pauta::setRespuestas(vector<string> resp)
{
	respuestas = resp;
}

string Pauta::getHabilidad()
{
	return habilidad;
}

string Pauta::getDificultad()
{
	return dificultad;
}

string Pauta::getComplejidad()
{
	return complejidad;
}

string Pauta::getActividad()
{
	return actividad;
}

vector<string> Pauta::getRespuestas()
{
	return respuestas;
}
