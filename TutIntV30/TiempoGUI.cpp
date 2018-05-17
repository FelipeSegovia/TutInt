#include "TiempoGUI.h"

TiempoGUI::TiempoGUI() {}

TiempoGUI::~TiempoGUI() {}

void TiempoGUI::setIniciar(bool inc)
{
	iniciar = inc;
}

void TiempoGUI::setHoras(int h)
{
	horas = h;
}

void TiempoGUI::setMinutos(int m)
{
	minutos = m;
}

void TiempoGUI::setSegundos(int s)
{
	segundos = s;
}

int TiempoGUI::getHoras()
{
	return horas;
}

int TiempoGUI::getMinutos()
{
	return minutos;
}

int TiempoGUI::getSegundos()
{
	return this->segundos;
}

void TiempoGUI::cronometro()
{
	do {
		if (segundos == 60) {
			segundos = 0;
			minutos++;
		}
		if (minutos == 60)
		{
			minutos = 0;
		}
		Sleep(1000);
		segundos++;
	} while (iniciar);
}

int TiempoGUI::segundostotales()
{
	int segTotal = segundos + minutos * 60;
	return segTotal;
}