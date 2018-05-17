#pragma once
#include <Windows.h>

using namespace System::Threading;

public ref class TiempoGUI {

private:
	bool iniciar = true;
	int horas;
	int minutos;
	int segundos;

public:
	TiempoGUI();
	~TiempoGUI();
	void setIniciar(bool inc);
	void setHoras(int h);
	void setMinutos(int m);
	void setSegundos(int s);
	int getHoras();
	int getMinutos();
	int getSegundos();
	void cronometro();
	int segundostotales();
};
