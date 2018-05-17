#include <vector>
#include "LeerPauta.h"
LeerPauta::LeerPauta(string ruta)
{
	link = ruta;
}

LeerPauta::~LeerPauta() {}

void LeerPauta::leer()
{
	ifstream archivo(link.c_str());
	if (archivo.fail())
	{
		exit(1);
	}

	const int size = 9999;
	char texto[size];

	while (!archivo.eof()) //Leo cada linea
	{
		archivo >> texto;
		//Habilidad
		char* palabra, *nextToken;
		palabra = strtok_s(texto, ",", &nextToken);
		string palabraAux = palabra;
		evaluador.setHabilidad(palabraAux);

		//Dificultad
		palabra = strtok_s(NULL, ",", &nextToken);
		evaluador.setDificultad(palabra);

		//Complejidad
		palabra = strtok_s(NULL, ",", &nextToken);
		evaluador.setComplejidad(palabra);

		//Actividad
		palabra = strtok_s(NULL, ",", &nextToken);
		evaluador.setActividad(palabra);

		//Respuestas
		palabra = strtok_s(NULL, "(,)", &nextToken);
		vector<string> respuestas;
		while (palabra != NULL)
		{
			respuestas.push_back(palabra);
			palabra = strtok_s(NULL, "(,)", &nextToken);

		}

		evaluador.setRespuestas(respuestas);
		pauta.push_back(evaluador);
	}
}

vector<Pauta> LeerPauta::getPauta()
{
	return pauta;
}
