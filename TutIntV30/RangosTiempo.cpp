#include "RangosTiempo.h"
#include "Argumento.h"

RangosTiempo::RangosTiempo(int act, TiempoMI* tiempo, std::string hab, std::string dif, std::string compl) {
	actividad = act;
	tiempoAct = tiempo;
	habilidad = hab;
	dificultad = dif;
	complejidad = compl;
}

RangosTiempo::RangosTiempo(int act, std::string hab, std::string dif, std::string compl) {
	actividad = act;
	habilidad = hab;
	dificultad = dif;
	complejidad = compl;
}

RangosTiempo::~RangosTiempo() { }

Hecho* RangosTiempo::determinarTiempoItem() {
	Hecho *hecho;
	if (habilidad == "Conciencia_fonologica") {
		if (dificultad == "Basica") {
			if (complejidad == "Básica") {
				hecho = rangosItemHabilidadUnoBB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadUnoBI();
			}
			else {
				hecho = rangosItemHabilidadUnoBD();
			}
		}
		else if (dificultad == "Intermedia") {
			if (complejidad == "Básica") {
				hecho = rangosItemHabilidadUnoIB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadUnoII();
			}
			else {
				hecho = rangosItemHabilidadUnoID();
			}
		}
		else {
			if (complejidad == "Básica") {
				hecho = rangosItemHabilidadUnoDB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadUnoDI();
			}
			else {
				hecho = rangosItemHabilidadUnoDD();
			}
		}
	}
	else if (habilidad == "Conciencia_alfabetica") {
		if (dificultad == "Basica") {
			if (complejidad == "Básica") {
				hecho = rangosItemHabilidadDosBB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadDosBI();
			}
			else {
				hecho = rangosItemHabilidadDosBD();
			}
		}
		else if (dificultad == "Intermedia") {
			if (complejidad == "Básica") {
				hecho = rangosItemHabilidadDosIB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadDosII();
			}
			else {
				hecho = rangosItemHabilidadDosID();
			}
		}
		else {
			if (complejidad == "Básica") {
				hecho = rangosItemHabilidadDosDB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosItemHabilidadDosDI();
			}
			else {
				hecho = rangosItemHabilidadDosDD();
			}
		}
	}
	return hecho;
}

Hecho* RangosTiempo::determinarTiempoAct() {
	Hecho *hecho;
	if (habilidad == "Conciencia_fonologica") {
		if (dificultad == "Basica") {
			if (complejidad == "Básica") {
				hecho = rangosActHabilidadUnoBB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadUnoBI();
			}
			else {
				hecho = rangosActHabilidadUnoBD();
			}
		}
		else if (dificultad == "Intermedia") {
			if (complejidad == "Básica") {
				hecho = rangosActHabilidadUnoIB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadUnoII();
			}
			else {
				hecho = rangosActHabilidadUnoID();
			}
		}
		else {
			if (complejidad == "Básica") {
				hecho = rangosActHabilidadUnoDB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadUnoDI();
			}
			else {
				hecho = rangosActHabilidadUnoDD();
			}
		}
	}
	else if (habilidad == "Conciencia_alfabetica") {
		if (dificultad == "Basica") {
			if (complejidad == "Básica") {
				hecho = rangosActHabilidadDosBB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadDosBI();
			}
			else {
				hecho = rangosActHabilidadDosBD();
			}
		}
		else if (dificultad == "Intermedia") {
			if (complejidad == "Básica") {
				hecho = rangosActHabilidadDosIB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadDosII();
			}
			else {
				hecho = rangosActHabilidadDosID();
			}
		}
		else {
			if (complejidad == "Básica") {
				hecho = rangosActHabilidadDosDB();
			}
			else if (complejidad == "Intermedia") {
				hecho = rangosActHabilidadDosDI();
			}
			else {
				hecho = rangosActHabilidadDosDD();
			}
		}
	}
	//Es por mientras
	return hecho;
}

// Item Actividad
Hecho* RangosTiempo::rangosItemHabilidadUnoBB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 33) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 33 && tiempoTotal <= 136) {	// 2:16
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 137) {	// 2:17
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 45) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 45 && tiempoTotal <= 74) {	// 1:14
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 75) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoBI() {
	Hecho* rangoAct = new Hecho();
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 40) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 40 && tiempoTotal <= 99) {	// 1:39
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 100) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 29) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 29 && tiempoTotal <= 80) {	// 1:20
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 81) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoBD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 25) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 25 && tiempoTotal <= 89) {	// 1:09
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 90) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 30) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 30 && tiempoTotal <= 84) {	// 1:04
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 85) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoIB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 35) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 35 && tiempoTotal <= 84) {	// 1:04
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 85) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 31) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 30 && tiempoTotal <= 89) {	// 1:09
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 89) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoII() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 36) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 36 && tiempoTotal <= 101) {	// 1:41
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 102) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 67) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 67 && tiempoTotal <= 139) {	// 2:19
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 140) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoID() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 30) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 30 && tiempoTotal <= 79) {	// 1:19
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 80) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoDB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 87) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 87 && tiempoTotal <= 242) {	// 4:02
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 243) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 20) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 20 && tiempoTotal <= 55) {	// 0:55
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 56) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoDI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 40) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 40 && tiempoTotal <= 114) {	// 1:54
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 115) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 80) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 80 && tiempoTotal <= 149) {	// 2:29
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 150) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadUnoDD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 80) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 80 && tiempoTotal <= 149) {	// 2:29
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 150) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 76) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 76 && tiempoTotal <= 179) {	// 2:59
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 180) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosBB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 15) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 15 && tiempoTotal <= 26) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 26) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosBI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 20) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 20 && tiempoTotal <= 55) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 56) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 17) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 17 && tiempoTotal <= 43) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 44) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosBD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 27) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 27 && tiempoTotal <= 50) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 51) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 30) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 30 && tiempoTotal <= 60) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 61) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosIB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 16) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 16 && tiempoTotal <= 40) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 41) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 25) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 25 && tiempoTotal <= 50) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 51) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosII() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 25) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 25 && tiempoTotal <= 50) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 51) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 20) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 20 && tiempoTotal <= 45) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 46) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosID() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 40) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 40 && tiempoTotal <= 80) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 81) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 35) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 35 && tiempoTotal <= 70) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 71) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosDB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 45) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 45 && tiempoTotal <= 80) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 81) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 55) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 55 && tiempoTotal <= 100) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 101) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosDI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 60) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 60 && tiempoTotal <= 120) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 121) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosItemHabilidadDosDD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 90) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 90 && tiempoTotal <= 140) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 141) {
			rangoAct = new Hecho("rangoTiempoItem", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

// Actividades
Hecho* RangosTiempo::rangosActHabilidadUnoBB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 130) {	// 2:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 130 && tiempoTotal <= 316) {	// 5:16
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 317) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 225) {	// 3:45
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 225 && tiempoTotal <= 310) {	// 5:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 311) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoBI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 130) {	// 2:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 130 && tiempoTotal <= 300) {	// 5:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 301) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 120) {	// 2:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 240) {	// 4:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 241) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoBD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 90) {	// 1:30
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 90 && tiempoTotal <= 190) {	// 3:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 191) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 120) {	// 2:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 240) {	// 4:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 241) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoIB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 119) {	// 1:59
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 119 && tiempoTotal <= 239) {	// 3:59
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 240) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 147) {	// 2:27
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 259) {	// 4:19
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 260) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoII() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 120) {	// 2:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 269) {	// 4:29
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 270) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 270) {	// 4:30
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 270 && tiempoTotal <= 389) {	// 6:29
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 390) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoID() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 120) {	// 2:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 249) {	// 4:09
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 250) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoDB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 310) {	// 5:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 310 && tiempoTotal <= 240) {	// 7:30
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 241) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 60) {	// 1:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 60 && tiempoTotal <= 140) {	// 2:20
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 140) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoDI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 140) {	// 2:20
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 140 && tiempoTotal <= 245) {	// 4:05
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 246) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 250) {		// 4:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 250 && tiempoTotal <= 400) {	// 6:40
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 401) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadUnoDD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 250) {	// 4:10
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 250 && tiempoTotal <= 380) {	// 6:20
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 381) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 240) {		// 4:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 240 && tiempoTotal <= 360) {	// 6:00
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 361) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosBB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 50) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal >50 && tiempoTotal <= 110) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 111) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosBI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 80) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 80 && tiempoTotal <= 180) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 181) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 78) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 78 && tiempoTotal <= 175) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 176) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosBD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 100) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 100 && tiempoTotal <= 210) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 211) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 120) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 230) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 231) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosIB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 60) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 60 && tiempoTotal <= 150) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 151) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 70) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 70 && tiempoTotal <= 170) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 171) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosII() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 60) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 60 && tiempoTotal <= 140) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 141) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 60) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 60 && tiempoTotal <= 130) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 131) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosID() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 110) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 110 && tiempoTotal <= 230) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 231) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 100) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 100 && tiempoTotal <= 220) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 221) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosDB() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1) {
		if (tiempoTotal <= 120) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 120 && tiempoTotal <= 240) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 241) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	else if (actividad == 2) {
		if (tiempoTotal <= 130) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 130 && tiempoTotal <= 270) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 271) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosDI() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 210) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 210 && tiempoTotal <= 340) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 341) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

Hecho* RangosTiempo::rangosActHabilidadDosDD() {
	Hecho* rangoAct;
	int tiempoTotal = tiempoAct->segundosTotales();
	if (actividad == 1 || actividad == 2) {
		if (tiempoTotal <= 230) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Bueno"), VERDADERO);
		}
		else if (tiempoTotal > 230 && tiempoTotal <= 350) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Regular"), VERDADERO);
		}
		else if (tiempoTotal >= 351) {
			rangoAct = new Hecho("rangoTiempoAct", Argumento("Malo"), VERDADERO);
		}
	}
	return rangoAct;
}

int RangosTiempo::getActividad() {
	return actividad;
}

void RangosTiempo::setActividad(int act) {
	actividad = act;
}

void RangosTiempo::setTiempo(TiempoMI* time) {
	tiempoAct = time;
}