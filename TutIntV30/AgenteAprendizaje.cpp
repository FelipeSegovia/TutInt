#include "AgenteAprendizaje.h"

AgenteAprendizaje::AgenteAprendizaje(Percepciones *p, Recuperacion *_recuperacion) {
	percepciones = p;
	conector = Conector::obtenerConector();
	recuperacion = _recuperacion;
	contadorAlto = recuperacion->getContadorAlto();
	contadorMedio = recuperacion->getContadorMedio();
	contadorBajo = recuperacion->getContadorBajo();
}

AgenteAprendizaje::~AgenteAprendizaje() { }

int AgenteAprendizaje::obtenerCritica() {		// 1: hay critica, 2: no hay critica, 0: no hay critica por ser la primera act.
	nivelAutonomia = getNivelAutonomia();
	nivelEficacia = getNivelEficacia();
	nivelMotivacion = getNivelMotivacion();
	nivelLogro = getNivelLogro();

	double porcentajeActuacion;
	// Determinar porcentaje de cada nivel

	// Autonomia
	string valorAutonomia = "";
	if (nivelAutonomia == "Bueno") {
		valorAutonomia = "99.9";
	}
	else if (nivelAutonomia == "Regular") {
		valorAutonomia = "66.6";
	}
	else if (nivelAutonomia == "Malo") {
		valorAutonomia = "33.3";
	}

	// Eficacia
	string valorEficacia = "";
	if (nivelEficacia == "Bueno") {
		valorEficacia = "99.9";
	}
	else if (nivelEficacia == "Regular") {
		valorEficacia = "66.6";
	}
	else if (nivelEficacia == "Malo") {
		valorEficacia = "33.3";
	}

	//Motivacion
	string valorMotivacion = "";
	if (nivelMotivacion == "Bueno") {
		valorMotivacion = "99.9";
	}
	else if (nivelEficacia == "Regular") {
		valorMotivacion = "66.6";
	}
	else if (nivelEficacia == "Malo") {
		valorMotivacion = "33.3";
	}

	//Nivel de Logro
	string valorLogro = "";
	if (nivelLogro == "Logrado") {
		valorLogro = "99.9";
	}
	else if (nivelLogro == "Medianamente_Logrado") {
		valorLogro = "66.6";
	}
	else {
		valorLogro = "33.3";
	}

	double porcentAutonomia = atof(valorAutonomia.c_str());		// Convertir a double
	double porcentEficacia = atof(valorEficacia.c_str());
	double porcentMotivacion = atof(valorMotivacion.c_str());
	double porcentLogro = atof(valorLogro.c_str());

	porcentajeActuacion = (porcentAutonomia * 0.15) + (porcentEficacia * 0.15) + (porcentMotivacion * 0.15) + (porcentLogro * 0.55);
	percepciones->setPorcentAutonomia(porcentAutonomia);
	percepciones->setPorcentEficacia(porcentEficacia);
	percepciones->setPorcentMotivacion(porcentMotivacion);
	percepciones->setPorcentLogro(porcentLogro);
	setPorcentActuacion(porcentajeActuacion);
	percepciones->setNivelActuacion(porcentajeActuacion);

	// Obtener nivel de actuacion de la actividad
	vector<Hecho*> cuerpo;
	string rangoActuacion = "";
	if (porcentajeActuacion < 50) {
		cuerpo.push_back(new Hecho("rangoActuacion", Argumento("0-49"), VERDADERO));
		nivelActuacion = new Regla(new Hecho("nivelActuacion", Argumento("Bajo"), VERDADERO), cuerpo);
		rangoActuacion = "Bajo";
	}
	else if (porcentajeActuacion >= 50 && porcentajeActuacion < 80) {
		cuerpo.push_back(new Hecho("rangoActuacion", Argumento("50-79"), VERDADERO));
		nivelActuacion = new Regla(new Hecho("nivelActuacion", Argumento("Medio"), VERDADERO), cuerpo);
		rangoActuacion = "Medio";
	}
	else if (porcentajeActuacion >= 80) {
		cuerpo.push_back(new Hecho("rangoActuacion", Argumento("80-100"), VERDADERO));
		nivelActuacion = new Regla(new Hecho("nivelActuacion", Argumento("Alto"), VERDADERO), cuerpo);
		rangoActuacion = "Alto";
	}

	// Establecer si hay critica
	vector<string> historialNiveles = recuperacion->getHistorialNivelActuacion();
	if (historialNiveles.size() == 0) {			// No ha hecho ninguna actividad, aparte de la que se esta evaluando
												// Se guarda este nivel de actuacion como total_actuacion en la BD
		totalActuacion = rangoActuacion;
		percepciones->setTotalActuacion(totalActuacion);
		recuperacion->setDatosActuacion(rangoActuacion, totalActuacion, porcentajeActuacion);
		percepciones->setNivelActuacionEscrito(rangoActuacion);
		return 0;
	}
	else if (historialNiveles.size() >= 1) {		// Ha hecho una actividad o más actividades
		int total = historialNiveles.size() - 1;
		// Establece si hay progreso
		conector->agregarHecho(new Hecho("nivelActual", Argumento(rangoActuacion), VERDADERO));
		conector->agregarHecho(new Hecho("nivelAnterior", Argumento(historialNiveles[total]), VERDADERO));
		motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
		Hecho *resultadoProgreso = nullptr;
		string progreso = "";
		resultadoProgreso = motorInferencia->ejecutar("progreso", ENCADENAMIENTO_ATRAS);
		if (motorInferencia->getTerminoInferencia()) {
			progreso = resultadoProgreso->getArgumento()[0].ToString();
			progresoActual = motorInferencia->getReglaInferida();
			conector->borrarHechos();
		}
		delete motorInferencia;

		// Segun resultado de progreso, establece si hay critica
		conector->agregarHecho(new Hecho("progreso", Argumento(progreso), VERDADERO));
		motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
		Hecho *resultadoCritica = nullptr;
		string argCritica = "";
		resultadoCritica = motorInferencia->ejecutar("generarCritica", ENCADENAMIENTO_ATRAS);
		if (motorInferencia->getTerminoInferencia()) {
			argCritica = resultadoCritica->getArgumento()[0].ToString();
			conector->borrarHechos();
		}
		delete motorInferencia;

		if (progreso == "Mantiene") {
			totalActuacion = rangoActuacion;
			if (totalActuacion == "Alto") {
				contadorAlto++;
				contadorMedio = 0;
				contadorBajo = 0;
			}
			else if (totalActuacion == "Medio") {
				contadorMedio++;
				contadorBajo = 0;
				contadorAlto = 0;
			}
			else if (totalActuacion == "Bajo") {
				contadorBajo++;
				contadorAlto = 0;
				contadorMedio = 0;
			}
		}
		else if (progreso == "True") {
			totalActuacion = "Alto";
			contadorAlto = 0;
			contadorBajo = 0;
			contadorMedio = 0;
		}
		else if (progreso == "False") {
			totalActuacion = "Bajo";
			contadorAlto = 0;
			contadorMedio = 0;
			contadorBajo = 0;
		}

		if (argCritica == "True") {		// True = Progreso o retroceso, hay critica
			critica = progreso;
			recuperacion->setDatosActuacion(rangoActuacion, totalActuacion, porcentajeActuacion);
			return 1;
		}
		else {
			recuperacion->setDatosActuacion(rangoActuacion, totalActuacion, porcentajeActuacion);
			return 2;
		}
		return 2;
	}
	return 2;
}

Regla* AgenteAprendizaje::generarProblema() {
	string nivActuacion = totalActuacion;
	if (contadorAlto == 3) {
		contadorAlto = 2;
	}
	else if (contadorBajo == 3) {
		contadorMedio = 2;
	}
	if (contadorMedio >= 2) {
		contadorMedio = 2;
		vector<double> porcentajes = recuperacion->getPorcentajesActuacionMedio();
		int contMedioAlto = 0, contMedioBajo = 0;
		if (percepciones->getNivelActuacion() < 64) {
			contMedioBajo++;
		}
		else {
			contMedioAlto++;
		}
		for (unsigned int i = 0; i < porcentajes.size(); i++) {
			if (porcentajes[i] < 64) {
				contMedioBajo++;
			}
			else {
				contMedioAlto++;
			}
		}
		if (contMedioAlto > contMedioBajo) {
			nivActuacion = "Medio_Alto";
		}
		else {
			nivActuacion = "Medio_Bajo";
		}
	}
	conector->agregarHecho(new Hecho("dificultad", Argumento(percepciones->getDificultad()), VERDADERO));
	conector->agregarHecho(new Hecho("complejidad", Argumento(percepciones->getComplejidad()), VERDADERO));
	conector->agregarHecho(new Hecho("totalActuacion", Argumento(nivActuacion), VERDADERO));
	conector->agregarHecho(new Hecho("contadorAlto", Argumento(to_string(contadorAlto)), VERDADERO));
	conector->agregarHecho(new Hecho("contadorMedio", Argumento(to_string(contadorMedio)), VERDADERO));
	conector->agregarHecho(new Hecho("contadorBajo", Argumento(to_string(contadorBajo)), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	Hecho *resultadoProblema = nullptr;
	Regla *problema = nullptr;
	resultadoProblema = motorInferencia->ejecutar("generarProblema", ENCADENAMIENTO_ATRAS);
	if (motorInferencia->getTerminoInferencia()) {
		problema = motorInferencia->getReglaInferida();
		conector->borrarHechos();
	}
	delete motorInferencia;

	recuperacion->setContadorAlto(contadorAlto);
	recuperacion->setContadorMedio(contadorMedio);
	recuperacion->setContadorBajo(contadorBajo);

	return problema;
}

void AgenteAprendizaje::realimentarElementoAprendizaje() {
	string tmpRegla = recuperacion->getProblemaGenerado();
	if (tmpRegla != "") {
		Regla* problemaGenerado = conector->transformarStringRegla(tmpRegla);

		// Cuanto aprendizaje (valor) hubo según el proceso o retroceso
		conector->agregarHecho(new Hecho(progresoActual->getCabeza()->getRelacion(), Argumento(progresoActual->getCabeza()->getArgumento()[0]), VERDADERO));
		conector->agregarHecho(new Hecho(progresoActual->getCuerpo()[0]->getRelacion(), Argumento(progresoActual->getCuerpo()[0]->getArgumento()[0]), VERDADERO));
		conector->agregarHecho(new Hecho(progresoActual->getCuerpo()[1]->getRelacion(), Argumento(progresoActual->getCuerpo()[1]->getArgumento()[0]), VERDADERO));

		motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
		Hecho *resultadoAprendizaje = nullptr;
		string aprendizaje = "";
		resultadoAprendizaje = motorInferencia->ejecutar("aprendizaje", ENCADENAMIENTO_ATRAS);
		if (motorInferencia->getTerminoInferencia()) {
			aprendizaje = resultadoAprendizaje->getArgumento()[0].ToString();
			conector->borrarHechos();
		}
		delete motorInferencia;

		// Cambiar el peso que tiene la regla que se disparo para el problema y las que se dispararon para llegar a esa
		int valorAprendizaje = atoi(aprendizaje.c_str());
		int pesoActual = conector->obtenerBaseDeConocimiento()->obtenerRegla(problemaGenerado)->getPeso();
		int total = pesoActual + valorAprendizaje;
		conector->obtenerBaseDeConocimiento()->obtenerRegla(problemaGenerado)->setPeso(total);

		// Cambiar peso de las reglas que conllevan al problema generado
		int pesoNivelActuacion = conector->obtenerBaseDeConocimiento()->obtenerRegla(nivelActuacion)->getPeso();
		int totalNivelActuacion = pesoNivelActuacion + valorAprendizaje;
		conector->obtenerBaseDeConocimiento()->obtenerRegla(nivelActuacion)->setPeso(totalNivelActuacion);
	}
}

// Funcion llamada desde el Agente Controlador
vector<Regla*> AgenteAprendizaje::determinarElementoActuacion() {
	vector<Regla*> elemento;
	int presentaCritica = obtenerCritica();
	if (presentaCritica == 1) {					// Hay critica
		realimentarElementoAprendizaje();
		elemento.push_back(nivelActuacion);
		return elemento;
	}
	else if (presentaCritica == 2) {				// No hay critica
		elemento.push_back(nivelActuacion);
		Regla *problema = generarProblema();
		elemento.push_back(problema);
		return elemento;
	}
	else if (presentaCritica == 0) {				// No hay critica por ser la primera actividad
		elemento.push_back(nivelActuacion);
		return elemento;
	}
	return elemento;
}

string AgenteAprendizaje::getNivelAutonomia() {
	string rangoCantAyuda;
	if (percepciones->getCantAyuda() >= 10) {
		if (percepciones->getComplejidad() == "Basico") {
			rangoCantAyuda = "7-10";
		}
		else if (percepciones->getComplejidad() == "Intermedia") {
			rangoCantAyuda = "8-10";
		}
		else if (percepciones->getComplejidad() == "Dificil") {
			rangoCantAyuda = "9-10";
		}
	}
	else {
		conector->agregarHecho(new Hecho("total", Argumento(to_string(percepciones->getCantAyuda())), VERDADERO));
		conector->agregarHecho(new Hecho("complejidad", Argumento(percepciones->getComplejidad()), VERDADERO));
		motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
		Hecho *resultadoAyuda = nullptr;
		resultadoAyuda = motorInferencia->ejecutar("cantAyuda", ENCADENAMIENTO_ADELANTE);
		if (motorInferencia->getTerminoInferencia()) {
			rangoCantAyuda = resultadoAyuda->getArgumento()[0].ToString();
			conector->borrarHechos();
		}
		delete motorInferencia;
	}
	Hecho *resultado = nullptr;
	string nivel;
	conector->agregarHecho(new Hecho("cantAyuda", Argumento(rangoCantAyuda), VERDADERO));
	motorInferencia = new MotorDeInferencia(conector->obtenerBaseDeHechos(), conector->obtenerBaseDeConocimiento());
	resultado = motorInferencia->ejecutar("rangoAyuda", ENCADENAMIENTO_ADELANTE);
	if (motorInferencia->getTerminoInferencia()) {
		nivel = resultado->getArgumento()[0].ToString();
		conector->borrarHechos();
	}
	delete motorInferencia;
	return nivel;
}

string AgenteAprendizaje::getNivelEficacia() {
	RangosTiempo *rango = new RangosTiempo(percepciones->getActividad(), percepciones->getHabilidad(), percepciones->getDificultad(), percepciones->getComplejidad());
	vector<string> niveles;
	for (unsigned int i = 0; i < percepciones->getTiempoItems().size(); i++) {
		rango->setTiempo(percepciones->getTiempoItems()[i]);
		Hecho *rangoItem = rango->determinarTiempoItem();
		string argumento = rangoItem->getArgumento()[0].getValor();
		niveles.push_back(argumento);
	}
	int contBueno = 0, contRegular = 0, contMalo = 0;
	for (unsigned int i = 0; i < niveles.size(); i++) {
		if (niveles[i] == "Bueno") {
			contBueno++;
		}
		else if (niveles[i] == "Regular") {
			contRegular++;
		}
		else {
			contMalo++;
		}
	}
	string nivelEficacia;
	if (contBueno > contMalo && contBueno > contRegular) {
		nivelEficacia = "Bueno";
	}
	else if (contRegular > contBueno && contRegular > contBueno) {
		nivelEficacia = "Regular";
	}
	else if (contMalo > contRegular && contMalo > contBueno) {
		nivelEficacia = "Malo";
	}
	else if (contBueno == contRegular) {
		nivelEficacia = "Regular";
	}
	else if (contBueno == contMalo) {
		nivelEficacia = "Regular";
	}
	else if (contRegular == contMalo) {
		nivelEficacia = "Malo";
	}
	return nivelEficacia;
}


string AgenteAprendizaje::getNivelMotivacion() {
	RangosTiempo *rango = new RangosTiempo(percepciones->getActividad(), percepciones->getTiempoAct(), percepciones->getHabilidad(), percepciones->getDificultad(), percepciones->getComplejidad());
	Hecho *rangoAct = rango->determinarTiempoAct();
	string nivel = rangoAct->getArgumento()[0].ToString();
	return nivel;
}

string AgenteAprendizaje::getNivelLogro() {
	return percepciones->getNivelLogro();
}

void AgenteAprendizaje::setPorcentActuacion(double porcent)
{
	porcentActuacion = porcent;
}

double AgenteAprendizaje::getPorcentActuacion()
{
	return porcentActuacion;
}
