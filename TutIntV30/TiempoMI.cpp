#include "TiempoMI.h"

TiempoMI::TiempoMI() {}

TiempoMI::~TiempoMI() {}

void TiempoMI::setHoras(int h)
{
	horas = h;
}

void TiempoMI::setMinutos(int m)
{
	minutos = m;
}

void TiempoMI::setSegundos(int s)
{
	segundos = s;
}

int TiempoMI::getHoras()
{
	return horas;
}

int TiempoMI::getMinutos()
{
	return minutos;
}

int TiempoMI::getSegundos()
{
	return segundos;
}

int TiempoMI::segundosTotales() {
	int total = segundos + (minutos * 60);
	return total;
}
