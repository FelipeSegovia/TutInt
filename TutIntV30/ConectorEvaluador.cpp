#include "ConectorEvaluador.h"

ConectorEvaluador *ConectorEvaluador::conectorEvaluador = ConectorEvaluador::obtenerConectorEvaluador();

ConectorEvaluador::ConectorEvaluador() {
	reglas = new BaseDeConocimiento();
	hechos = new BaseDeHechos();
}

ConectorEvaluador::~ConectorEvaluador() { }

void ConectorEvaluador::agregarRegla(Regla *regla)
{
	reglas->agregarRegla(regla);
}

void ConectorEvaluador::agregarHecho(Hecho *hecho)
{
	hechos->agregarHecho(hecho);
}

void ConectorEvaluador::borrarHechos()
{
	hechos->borrarHechos();
}

void ConectorEvaluador::cerrarArchivo()
{
	reglas = new BaseDeConocimiento();
	hechos = new BaseDeHechos();
}

ConectorEvaluador* ConectorEvaluador::obtenerConectorEvaluador()
{
	if (ConectorEvaluador::conectorEvaluador == nullptr) {
		ConectorEvaluador *conectorEvaluador = new ConectorEvaluador();
		return conectorEvaluador;
	}
	return ConectorEvaluador::conectorEvaluador;
}

bool ConectorEvaluador::getLeyendoRegla()
{
	return leyendoRegla;
}

void ConectorEvaluador::inicioRegla()
{
	leyendoRegla = true;
}

void ConectorEvaluador::finRegla()
{
	leyendoRegla = false;
}

Regla* ConectorEvaluador::transformarStringRegla(string _regla) {
	char regla[9999];
	strcpy_s(regla, _regla.c_str());
	char *palabra, *nextToken;
	string text;
	palabra = strtok_s(regla, ":", &nextToken);    //Divide la cabeza del cuerpo
	char *cabeza = palabra;

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
		hechos.push_back(palabra);
	}
	// Se separa la constante del argumento del Hecho Cabeza  constante(argumento)
	char *constante = strtok_s(cabeza, "(", &nextToken);
	char *charCabezaConstante = constante;
	string tmpCabezaConst = charCabezaConstante;

	char *argumento;
	Hecho *hechoCabeza;
	entrar = true;
	while (constante && entrar) {
		constante = strtok_s(NULL, ")", &nextToken);
		argumento = constante;
		string argu = argumento;
		Argumento argumento(argu);
		hechoCabeza = new Hecho(tmpCabezaConst, argumento);	// SE DEBE ALMACENAR EL HECHO (CABEZA)
		hechoCabeza->setPermanente(true);
		entrar = false;
	}

	// Se separa la constante del argumento de cada hecho del cuerpo de la regla
	list<char*>::iterator it;
	int i = 0, tam = hechos.size();
	bool acceder = true;
	vector<Hecho*> vectHecho;
	int pesoRegla;
	for (it = hechos.begin(); it != hechos.end() && acceder; it++) {
		if (acceder == false) break;
		char *constante = strtok_s(*it, "(", &nextToken);
		string hechoC = constante;		// Predicado
		if (hechoC == "peso") {
			entrar = true;
			while (constante && entrar) {
				constante = strtok_s(NULL, ")", &nextToken);
				char *argumento = constante;
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
				string hechoA = argumento;
				Argumento arg(hechoA);
				entrar = false;
				Hecho *newHecho = new Hecho(hechoC, arg);
				newHecho->setPermanente(true);
				vectHecho.push_back(newHecho);
			}
		}
		i++;
		if (i == tam - 1) {
			acceder = false;
		}
	}
	return new Regla(hechoCabeza, vectHecho, pesoRegla);
}

BaseDeHechos* ConectorEvaluador::obtenerBaseDeHechos()
{
	return hechos;
}

BaseDeConocimiento* ConectorEvaluador::obtenerBaseDeConocimiento()
{
	reglas->ordenarMenorAMayor();
	return reglas;
}

string ConectorEvaluador::pasarReglaString(Regla* regla) {
	string reglaString;
	string cabezaRegla = regla->getCabeza()->getRelacion() + "(" + regla->getCabeza()->getArgumento()[0].ToString() + "):-";
	string cuerpo;
	for (unsigned int i = 0; i < regla->getCuerpo().size(); i++) {
		cuerpo = cuerpo + regla->getCuerpo()[i]->getRelacion() + "(" + regla->getCuerpo()[i]->getArgumento()[0].ToString() + "),";
	}
	reglaString = cabezaRegla + cuerpo + "peso(" + to_string(regla->getPeso()) + ")";
	return reglaString;
}

string ConectorEvaluador::ToString()
{
	string texto = "Base de Conocimiento\n";
	for (int x = 0; x<reglas->getNumeroReglas(); x++)
	{
		texto = texto + reglas->obtenerRegla(x)->ToString();
	}
	texto += "Base de Hechos\n";
	return texto;
}