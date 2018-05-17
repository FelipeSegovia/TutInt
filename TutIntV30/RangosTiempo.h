#ifndef RANGOSTIEMPO_H
#define RANGOSTIEMPO_H

#include "Hecho.h"
#include "TiempoMI.h"
#include <string>

public class RangosTiempo {

private:
	int actividad;
	TiempoMI* tiempoAct;
	std::string habilidad;
	std::string dificultad;
	std::string complejidad;

public:
	RangosTiempo(int act, TiempoMI* tiempo, std::string hab, std::string dif, std::string compl);
	RangosTiempo(int act, std::string hab, std::string dif, std::string compl);
	~RangosTiempo();
	Hecho* determinarTiempoItem();
	Hecho* determinarTiempoAct();
	Hecho* rangosItemHabilidadUnoBB();
	Hecho* rangosItemHabilidadUnoBI();
	Hecho* rangosItemHabilidadUnoBD();
	Hecho* rangosItemHabilidadUnoIB();
	Hecho* rangosItemHabilidadUnoII();
	Hecho* rangosItemHabilidadUnoID();
	Hecho* rangosItemHabilidadUnoDB();
	Hecho* rangosItemHabilidadUnoDI();
	Hecho* rangosItemHabilidadUnoDD();
	Hecho* rangosItemHabilidadDosBB();
	Hecho* rangosItemHabilidadDosBI();
	Hecho* rangosItemHabilidadDosBD();
	Hecho* rangosItemHabilidadDosIB();
	Hecho* rangosItemHabilidadDosII();
	Hecho* rangosItemHabilidadDosID();
	Hecho* rangosItemHabilidadDosDB();
	Hecho* rangosItemHabilidadDosDI();
	Hecho* rangosItemHabilidadDosDD();
	Hecho* rangosActHabilidadUnoBB();
	Hecho* rangosActHabilidadUnoBI();
	Hecho* rangosActHabilidadUnoBD();
	Hecho* rangosActHabilidadUnoIB();
	Hecho* rangosActHabilidadUnoII();
	Hecho* rangosActHabilidadUnoID();
	Hecho* rangosActHabilidadUnoDB();
	Hecho* rangosActHabilidadUnoDI();
	Hecho* rangosActHabilidadUnoDD();
	Hecho* rangosActHabilidadDosBB();
	Hecho* rangosActHabilidadDosBI();
	Hecho* rangosActHabilidadDosBD();
	Hecho* rangosActHabilidadDosIB();
	Hecho* rangosActHabilidadDosII();
	Hecho* rangosActHabilidadDosID();
	Hecho* rangosActHabilidadDosDB();
	Hecho* rangosActHabilidadDosDI();
	Hecho* rangosActHabilidadDosDD();
	int getActividad();
	void setActividad(int act);
	void setTiempo(TiempoMI* time);
};
#endif // RANGOSTIEMPO_H

/*
BB = Dificultad básica, complejidad básica
BI = Dificultad básica, complejidad intermedia
BD = Dificultad básica, complejidad difícil
IB = Dificultad intermedia, complejidad básica
II = Dificultad intermedia, complejidad intermedia
ID = Dificultad intermedia, complejidad difícil
DB = Dificultad difícil, complejidad básica
DI = Dificultad difícil, complejidad intermedia
DD = Dificultad difícil, complejidad difícil
*/