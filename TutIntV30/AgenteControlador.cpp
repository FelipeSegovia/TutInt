#include "AgenteControlador.h"

AgenteControlador::AgenteControlador(string habilidad, Recuperacion *_recuperacion, int sesion)
{
	archivo = new LeerArchivo();
	percepciones = new Percepciones();
	percepciones->setHabilidad(habilidad);
	recuperacion = _recuperacion;
	numSesion = sesion;
	setPercepcionesHabilidad(habilidad, recuperacion->getNumUltimaActividad());
	string nombreArchivo = "baseDeConocimiento" + recuperacion->getNombreJugador() + ".txt";
	if (recuperacion->getNumUltimaActividad() == 0) {
		// Si es primera vez que entra, se crea la base de conocimiento para ese usuario
		archivo->copiarArchivo(nombreArchivo.c_str());
	}
	if (recuperacion->getNumSesion() != this->numSesion) {
		archivo->lectura(nombreArchivo.c_str());
	}
	conector = Conector::obtenerConector();
}

AgenteControlador::~AgenteControlador() {}

vector<string> AgenteControlador::determinarActividad()
{
	vector<string> actividad;
	//Caso para un usuario nuevo
	if ((recuperacion->getNumUltimaActividad() == 0) && (recuperacion->getHabilidadActividad() == "Conciencia_fonologica"))
	{

		actividad.push_back("Basica"); //dificultad
		actividad.push_back("Intermedia"); //complejidad
		actividad.push_back("1"); //numero de la actividad
		percepciones->setActividad(1);
		percepciones->setDificultad("Basica");
		percepciones->setComplejidad("Intermedia");
		recuperacion->setNumUltimaActividad(percepciones->getActividad());
		return actividad;
	}
	//Si ingresa en otra sesion
	else if (recuperacion->getNumSesion() != this->numSesion)
	{
		string complejidad = recuperacion->getComplejidadActividad();
		string dificultad = recuperacion->getDificultadActividad();
		string habilidad = recuperacion->getHabilidadActividad();

		Hecho *resultado = nullptr;
		conector->agregarHecho(new Hecho("dif", dificultad, VERDADERO));
		conector->agregarHecho(new Hecho("compl", complejidad, VERDADERO));
		conector->agregarHecho(new Hecho("hab", habilidad, VERDADERO));
		motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
		resultado = motorInferencia->ejecutar("nuevaSesion", ENCADENAMIENTO_ADELANTE);
		if (motorInferencia->getTerminoInferencia())
		{
			if (resultado->getArgumento()[0].getValor() == "siguienteHabilidad")
			{
				if (percepciones->getHabilidad() == "Cociencia_alfabetica") {
					actividad.push_back("Basica");
					actividad.push_back("Intermedia");
					actividad.push_back("1");
					percepciones->setHabilidad("Conciencia_alfabetica");
					percepciones->setDificultad("Basica");
					percepciones->setComplejidad("Intermedia");
					percepciones->setActividad(1);
				}
				else {
					actividad.push_back("FIN");
				}
				delete motorInferencia;
				return actividad;
			}
			else
			{
				char regla[9999];
				strcpy_s(regla, resultado->getArgumento()[0].getValor().c_str());
				char *palabra, *nextToken;
				palabra = strtok_s(regla, "_", &nextToken);    //Divide la cabeza del cuerpo
				actividad.push_back(palabra);
				actividad.push_back(nextToken);
				actividad.push_back("1");
				percepciones->setActividad(1);
				percepciones->setDificultad(palabra);
				percepciones->setComplejidad(nextToken);
				delete motorInferencia;
				return actividad;
			}
		}
	}
	//Si esta en la misma sesion
	else if (recuperacion->getNumSesion() == this->numSesion)
	{
		Hecho *resultado = nullptr;
		string tmpRegla = recuperacion->getNivelActuacionRegla();
		Regla* reglaNivActuacion = conector->transformarStringRegla(tmpRegla);
		conector->agregarHecho(new Hecho(reglaNivActuacion->getCabeza()->getRelacion(), Argumento(reglaNivActuacion->getCabeza()->getArgumento()[0].getValor()), VERDADERO));
		conector->agregarHecho(new Hecho("dificultad", Argumento(recuperacion->getDificultadActividad()), VERDADERO));
		conector->agregarHecho(new Hecho("complejidad", Argumento(recuperacion->getComplejidadActividad()), VERDADERO));
		motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
		resultado = motorInferencia->ejecutar("estado", ENCADENAMIENTO_ADELANTE);
		if (motorInferencia->getTerminoInferencia())
		{
			if (recuperacion->getProblemaGenerado() == "") //solo nivel de actuacion por lo que no existe critica
			{
				string habilidad;

				if (resultado->getArgumento()[0].getValor() == "Siguiente_Habilidad")
				{
					if (recuperacion->getHabilidadActividad() == "Conciencia_fonologica") {
						habilidad = "Conciencia_alfabetica";
					}
					else if (recuperacion->getHabilidadActividad() == "Conciencia_alfabetica")
					{
						habilidad = "Vocabulario";
					}
					else if (recuperacion->getHabilidadActividad() == "Vocabulario")
					{
						habilidad = "Comprension_literal";
					}
					else if (recuperacion->getHabilidadActividad() == "Comprension_literal")
					{
						habilidad = "Comprension_inferencial";
					}
					else if (recuperacion->getHabilidadActividad() == "Comprension_inferencial")
					{
						habilidad = "Termino"; //Si en la GUI se retorna esto mandar un mensaje que termino
					}

					if (habilidad != "Termino")
					{

						char regla[9999];
						strcpy_s(regla, resultado->getArgumento()[0].getValor().c_str());
						char *palabra, *nextToken;
						palabra = strtok_s(regla, "_", &nextToken);    //Divide la cabeza del cuerpo
						actividad.push_back(habilidad);
						actividad.push_back(palabra);
						actividad.push_back(nextToken);
						percepciones->setDificultad(palabra);
						percepciones->setComplejidad(nextToken);
						percepciones->setHabilidad(habilidad);
						if (recuperacion->getNumUltimaActividad() == 1)
						{
							actividad.push_back("2");
							percepciones->setActividad(2);
						}
						else
						{
							actividad.push_back("1");
							percepciones->setActividad(1);
						}

						return actividad;
					}
					else
					{
						actividad.push_back(habilidad);
						percepciones->setHabilidad(habilidad);
						conector->borrarHechos();
						delete motorInferencia;
						return actividad;
					}

				}
				else {
					char regla[9999];
					strcpy_s(regla, resultado->getArgumento()[0].getValor().c_str());
					char *palabra, *nextToken;
					palabra = strtok_s(regla, "_", &nextToken);    //Divide la cabeza del cuerpo
					actividad.push_back(palabra);
					actividad.push_back(nextToken);
					percepciones->setDificultad(palabra);
					percepciones->setComplejidad(nextToken);
					if (recuperacion->getNumUltimaActividad() == 1)
					{
						actividad.push_back("2");
						percepciones->setActividad(2);
					}
					else
					{
						actividad.push_back("1");
						percepciones->setActividad(1);
					}
					conector->borrarHechos();
					delete motorInferencia;
					return actividad;
				}
			}
			else {	// SI HAY UN PROBLEMA
				string tmpRegla = recuperacion->getProblemaGenerado();
				Regla* reglaProblema = conector->transformarStringRegla(tmpRegla);
				if (reglaProblema->getCabeza()->getArgumento()[0].getValor() == "Siguinte_Habilidad_Racha") {
					if (percepciones->getHabilidad() == "Cociencia_alfabetica") {
						actividad.push_back("Basica");
						actividad.push_back("Intermedia");
						actividad.push_back("1");
						percepciones->setHabilidad("Conciencia_alfabetica");
						percepciones->setDificultad("Basica");
						percepciones->setComplejidad("Intermedia");
						percepciones->setActividad(1);
					}
					else {
						actividad.push_back("FIN");
					}
					conector->borrarHechos();
					delete motorInferencia;
					return actividad;
				}
				else if (reglaProblema->getCabeza()->getArgumento()[0].getValor() == "Siguinte_Habilidad") {
					if (percepciones->getHabilidad() == "Cociencia_alfabetica") {
						actividad.push_back("Basica");
						actividad.push_back("Basica");
						actividad.push_back("1");
						percepciones->setHabilidad("Conciencia_alfabetica");
						percepciones->setDificultad("Basica");
						percepciones->setComplejidad("Basica");
						percepciones->setActividad(1);
					}
					else {
						actividad.push_back("FIN");
					}
					conector->borrarHechos();
					delete motorInferencia;
					return actividad;
				}
				else {

					char regla[9999];
					strcpy_s(regla, reglaProblema->getCabeza()->getArgumento()[0].getValor().c_str());
					char *palabra, *nextToken;
					palabra = strtok_s(regla, "_", &nextToken);
					actividad.push_back(palabra);
					actividad.push_back(nextToken);
					if (recuperacion->getNumUltimaActividad() == 1)
					{
						actividad.push_back("2");
						percepciones->setActividad(2);
					}
					else
					{
						actividad.push_back("1");
						percepciones->setActividad(1);
					}
					percepciones->setDificultad(palabra);
					percepciones->setComplejidad(nextToken);
					conector->borrarHechos();
					delete motorInferencia;
					return actividad;
				}
			}
		}
	}
	return actividad;
}

void AgenteControlador::setNumSesion(int _numSesion) {
	this->numSesion = _numSesion;
}

Percepciones* AgenteControlador::getPercepciones()
{
	return this->percepciones;
}

int AgenteControlador::getRespuestasBuenas()
{
	return this->contBuenas;
}

int AgenteControlador::getRespuestasMalas()
{
	return this->contMalas;
}

void AgenteControlador::obtenerNivelLogro() {
	//Aqui hay que sobrecargar el constructor y el metodo revisarActividad() para no dañar el proyecto
	LeerPauta *archivo = new LeerPauta("Pauta.txt");
	archivo->leer();
	vector<Pauta> pauta = archivo->getPauta();
	//Obtengo las respuestas buenas y malas de la actividad
	unsigned int tam_pauta = 0;
	while (tam_pauta < pauta.size())
	{
		if (pauta[tam_pauta].getHabilidad() == percepciones->getHabilidad() &&
			pauta[tam_pauta].getDificultad() == percepciones->getDificultad() &&
			pauta[tam_pauta].getComplejidad() == percepciones->getComplejidad() &&
			pauta[tam_pauta].getActividad() == to_string(percepciones->getActividad()))
		{
			vector<string> respuestas = pauta[tam_pauta].getRespuestas();
			vector<string> respuestas_percepciones = percepciones->getRespuestas();
			for (unsigned int i = 0; i < respuestas.size(); i++)
			{
				if (respuestas[i] == respuestas_percepciones[i])
				{
					contBuenas++;
				}
				else
				{
					contMalas++;
				}
			}
		}
		tam_pauta++;
	}

	//Saco el nivel de logro de la actividad
	int porcentaje = ((contBuenas * 100) / (contBuenas + contMalas));
	Evaluador *evaluador = new Evaluador();
	percepciones->setNivelLogro(evaluador->determinarNivelLogroActividad(porcentaje));
	delete evaluador;
}

void AgenteControlador::evaluarActividad() {
	AgenteAprendizaje *aprendizaje = new AgenteAprendizaje(percepciones, recuperacion);
	vector<Regla*> actuacionObtenida = aprendizaje->determinarElementoActuacion();
	if (actuacionObtenida.size() == 1) {
		actuacion = conector->pasarReglaString(actuacionObtenida[0]);
	}
	else if (actuacionObtenida.size() == 2) {
		actuacion = conector->pasarReglaString(actuacionObtenida[0]);
		problema = conector->pasarReglaString(actuacionObtenida[1]);
	}
	percepciones->setNivelActuacion(aprendizaje->getPorcentActuacion()); //porcentaje de acutacion
}

Recuperacion* AgenteControlador::getRecuperacion() {
	return recuperacion;
}

string AgenteControlador::getProblema()
{
	return problema;
}

string AgenteControlador::getActuacion() {
	return actuacion;
}

void AgenteControlador::actualizarBaseConocimientoUsuario() {
	string nombreArchivo = "baseDeConocimiento" + recuperacion->getNombreJugador() + ".txt";
	archivo->escribirArchivo(nombreArchivo);
}

void AgenteControlador::setPercepcionesHabilidad(string habilidad, int actividad)
{
	percepciones->setActividad(actividad);
	percepciones->setHabilidad(habilidad);
}

void AgenteControlador::setPercepcionesActividad(vector<string> resp, int ayuda, vector<TiempoMI*> timeItems, TiempoMI * timeAct)
{
	percepciones->setRespuestas(resp);
	percepciones->setCantAyuda(ayuda);
	percepciones->setTiempoItems(timeItems);
	percepciones->setTiempoAct(timeAct);
}

void AgenteControlador::setPercepcionesActividad(vector<string> resp, int ayuda, vector<TiempoMI*> timeItems, TiempoMI * timeAct, string nivLogro)
{
	percepciones->setRespuestas(resp);
	percepciones->setCantAyuda(ayuda);
	percepciones->setTiempoItems(timeItems);
	percepciones->setTiempoAct(timeAct);
	percepciones->setNivelLogro(nivLogro);
}

void AgenteControlador::setPercepcionesNivelActividad(string habilidad, string dificultad, string complejidad, int numAct) {
	percepciones->setHabilidad(habilidad);
	percepciones->setDificultad(dificultad);
	percepciones->setComplejidad(complejidad);
	percepciones->setActividad(numAct);
}

vector<Regla*> AgenteControlador::getReglasMayorPeso() {
	vector<Regla*> reglas = conector->obtenerBaseDeConocimiento()->obtenerReglasDeMayorPeso();
	return reglas;
}

vector<Regla*> AgenteControlador::getBC() {
	BaseDeConocimiento* bc = conector->obtenerBaseDeConocimiento();
	vector<Regla*> reglas;
	int x = 1;
	Regla* regla = bc->obtenerRegla(x);
	reglas.push_back(regla);
	x = 100;
	Regla* regla2 = bc->obtenerRegla(x);
	reglas.push_back(regla2);
	x = 200;
	Regla* regla3 = bc->obtenerRegla(x);
	reglas.push_back(regla3);
	return reglas;
}
