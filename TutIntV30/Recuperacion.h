#ifndef RECUPERACION_H
#define RECUPERACION_H

#include <vector>
#include <string>

using namespace std;

public class Recuperacion {

private:
	vector<string> historialNivelActuacion;		// Historial de los niveles de actuacion 
	vector<double> porcentajesActuacionMedio;
	int numAct = 0;
	int numSesion = 0;
	int contadorAlto = 0;
	int contadorMedio = 0;
	int contadorBajo = 0;
	string nombreJugador = "";
	string dificultad = "";
	string habilidad = "";
	string complejidad = "";
	string objetivo = "";
	string nivelActuacion = "";
	string totalActuacion = "";
	string problemaGenerado = "";
	string nivelActuacionRegla = "";
	double porcentajeActuacion;

public:
	Recuperacion();
	~Recuperacion();
	void setHistorialNivelActuacion(vector<string> historial);
	vector<string> getHistorialNivelActuacion();
	vector<double> getPorcentajesActuacionMedio();
	void setPorcentajesActuacionMedio(vector<double> _porcentajesActuacionMedio);
	void setProblemaGenerado(string _problemaGenerado);
	void setNivelActuacionRegla(string _nivelActuacionRegla);
	void setNombreJugador(string _nombreJugador);
	void setNumUltimaActividad(int _numAct);
	void setDificultadActividad(string _dificultad);
	void setComplejidadActividad(string _complejidad);
	void setObjetivoActividad(string _objetivo);
	void setHabilidadActividad(string _habilidad);
	void setNumSesion(int _numSesion);
	void setDatosActuacion(string _nivelActuacion, string _totalActuacion, double _porcentajeActuacion);
	void setContadorAlto(int _contadorAlto);
	void setContadorMedio(int _contadorMedio);
	void setContadorBajo(int _contadorBajo);
	int	getNumUltimaActividad();
	int getNumSesion();
	int getContadorAlto();
	int getContadorMedio();
	int getContadorBajo();
	string getProblemaGenerado();
	string getNivelActuacionRegla();
	string getNombreJugador();
	string getDificultadActividad();
	string getComplejidadActividad();
	string getObjetivoActividad();
	string getHabilidadActividad();
	string getNivelActuacion();
	string getTotalActuacion();
	double getPorcentajeActuacion();
};

#endif // RECUPERACION_H