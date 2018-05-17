#include "LeerArchivo.h"
#include "Hecho.h"
#include "Regla.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <list>
#include <direct.h>

using namespace std;

LeerArchivo::LeerArchivo() {
	conector = Conector::obtenerConector();
}

LeerArchivo::~LeerArchivo() { }

void LeerArchivo::copiarArchivo(string nombreArchivo) {
	string cadena;
	string archivoActual = "BaseDeConocimiento/baseDeConocimiento.txt";		// Archivo original
	ifstream archivo(archivoActual.c_str());
	if (!archivo.fail()) {
		vector<string> newNombre = separarNombre(nombreArchivo);
		string carpeta = newNombre[0];
		mkdir(carpeta.c_str());
		string direccion = carpeta + "\\" + nombreArchivo;
		cadena = "copy " + archivoActual + " " + direccion;
		system(cadena.c_str());
	}
	archivo.close();
}

vector<string> LeerArchivo::separarNombre(string nombreArchivo)
{
	std::vector<std::string> resultado;
	std::string::const_iterator itBegin = nombreArchivo.begin();
	std::string::const_iterator itEnd = nombreArchivo.end();

	int numItems = 1;
	for (std::string::const_iterator it = itBegin; it != itEnd; ++it)
		numItems += *it == ' ';

	resultado.reserve(numItems);

	for (std::string::const_iterator it = itBegin; it != itEnd; ++it)
	{
		if (*it == '.')
		{
			resultado.push_back(std::string(itBegin, it));
			itBegin = it + 1;
		}
	}
	if (itBegin != itEnd)
		resultado.push_back(std::string(itBegin, itEnd));

	return resultado;
}

void LeerArchivo::lectura(string nombreArchivo) {					// Con peso en las reglas
	vector<string> newNombre = separarNombre(nombreArchivo);
	string carpeta = newNombre[0];
	string direccion = carpeta + "//" + nombreArchivo;
	ifstream archivo(direccion.c_str());
	if (archivo.fail()) {
		exit(1);
	}

	const int size = 9999;
	char texto[size];
	string text;
	list<Regla> listaRegla;

	while (!archivo.eof()) { // Se lee cada regla (una por linea)
		archivo >> texto;
		// Separacion de la cabeza y el cuerpo de la regla.
		// Cabeza de la Regla
		char *palabra, *nextToken;
		palabra = strtok_s(texto, ":", &nextToken); //Divide la cabeza del cuerpo
		char *cabeza = palabra;
		//if (palabra) cout << "Cabeza: " << cabeza << endl;

		// Cuerpo de la Regla, se almacena en una lista
		list<char*> hechos;
		bool entrar = true;
		while (palabra) {
			palabra = strtok_s(NULL, ",", &nextToken);
			if (entrar) {
				text = palabra;
				text = text.substr(1, text.size());
				palabra = (char *)alloca(text.size() + 1);
				memcpy(palabra, text.c_str(), text.size() + 1);
				entrar = false;
			}
			//if (palabra) cout << "Cuerpo: " << palabra << endl;
			hechos.push_back(palabra);
		}

		// Se separa la constante del argumento del Hecho Cabeza  constante(argumento)
		char *constante = strtok_s(cabeza, "(", &nextToken);
		//if (constante) cout << "Cabeza\n   Constante: " << constante << endl;

		char *charCabezaConstante = constante;
		string tmpCabezaConst = charCabezaConstante;

		char *argumento;
		Hecho *hechoCabeza;
		entrar = true;
		while (constante && entrar) {
			constante = strtok_s(NULL, ")", &nextToken);
			argumento = constante;
			//if (constante) cout << "   Argumento: " << argumento << endl;
			string argu = argumento;
			Argumento argumento(argu);
			hechoCabeza = new Hecho(tmpCabezaConst, argumento);	// SE DEBE ALMACENAR EL HECHO (CABEZA)
			hechoCabeza->setPermanente(true);
			//conector->agregarHecho(hechoCabeza);
			entrar = false;
		}

		// Se separa la constante del argumento de cada hecho del cuerpo de la regla
		//cout << "Cuerpo" << endl;
		list<char*>::iterator it;
		int i = 0, tam = hechos.size();
		bool acceder = true;
		vector<Hecho*> vectHecho;
		int pesoRegla;
		for (it = hechos.begin(); it != hechos.end() && acceder; it++) {
			if (acceder == false) break;
			char *constante = strtok_s(*it, "(", &nextToken);
			//if (constante) cout << "  Hecho\n   Constante: " << constante << endl;

			string hechoC = constante;		// Predicado
			if (hechoC == "peso") {
				entrar = true;
				while (constante && entrar) {
					constante = strtok_s(NULL, ")", &nextToken);
					char *argumento = constante;
					//if (constante) cout << "   Argumento: " << argumento << endl;
					string hechoA = argumento;
					pesoRegla = atoi(hechoA.c_str());
					break;
				}
			}
			else {
				entrar = true;
				while (constante && entrar) {
					constante = strtok_s(NULL, ")", &nextToken);
					char *argumento = constante;
					//if (constante) cout << "   Argumento: " << argumento << endl;
					string hechoA = argumento;
					Argumento arg(hechoA);
					entrar = false;
					Hecho *newHecho = new Hecho(hechoC, arg);	// SE DEBE ALMACENAR CADA HECHO DE LA REGLA
					newHecho->setPermanente(true);
					//conector->agregarHecho(newHecho);
					vectHecho.push_back(newHecho);
				}
			}
			i++;
			if (i == tam - 1) {
				acceder = false;
			}
		}
		// SE DEBE ALMACENAR LA REGLA A LA BASE DE CONOCIMIENTO
		conector->agregarRegla(new Regla(hechoCabeza, vectHecho, pesoRegla));

		//cout << endl << endl;
	}
	archivo.close();
}

void LeerArchivo::escribirArchivo(string nombreArchivo)
{
	vector<string> newNombre = separarNombre(nombreArchivo);
	string carpeta = newNombre[0];
	string dir = carpeta + "//" + nombreArchivo;
	fstream fichero(dir.c_str(), fstream::in | fstream::out | fstream::trunc);
	BaseDeConocimiento *baseConocimiento = conector->obtenerBaseDeConocimiento();
	int cant = conector->obtenerBaseDeConocimiento()->getNumeroReglas();
	for (int i = 0; i < baseConocimiento->getNumeroReglas(); i++) {
		Regla *regla = baseConocimiento->obtenerRegla(i);
		string cabeza = regla->getCabeza()->getRelacion() + "(" + regla->getCabeza()->getArgumento()[0].ToString() + "):-";
		fichero << cabeza;
		for (int j = 0; j < regla->getNumeroCondiciones(); j++) {
			Hecho *condicion = regla->getCuerpo()[j];
			string hechoCuerpo = condicion->getRelacion() + "(" + condicion->getArgumento()[0].ToString() + "),";
			fichero << hechoCuerpo;
		}
		int cont = i;
		cont = cont + 1;
		if (cont == baseConocimiento->getNumeroReglas()) {
			fichero << "peso(" << regla->getPeso() << ")";
		}
		else {
			fichero << "peso(" << regla->getPeso() << ")" << endl;
		}
	}
	fichero.close();
}
