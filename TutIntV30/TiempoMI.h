#pragma once
public class TiempoMI {

private:
	int horas;
	int minutos;
	int segundos;

public:
	TiempoMI();
	~TiempoMI();
	void setHoras(int h);
	void setMinutos(int m);
	void setSegundos(int s);
	int getHoras();
	int getMinutos();
	int getSegundos();
	int segundosTotales();
};

