#include "Recuperacion.h"

Recuperacion::Recuperacion() { }

Recuperacion::~Recuperacion() { }

void Recuperacion::setHistorialNivelActuacion(vector<string> historial) {
	// En la base de datos se selecciona los total de actuacion obtenidos 
	// en un nivel de dificultad especifico de una habilidad
	historialNivelActuacion = historial;
}

vector<string> Recuperacion::getHistorialNivelActuacion() {
	return historialNivelActuacion;
}

vector<double> Recuperacion::getPorcentajesActuacionMedio() {
	return porcentajesActuacionMedio;
}

void Recuperacion::setPorcentajesActuacionMedio(vector<double> _porcentajesActuacionMedio) {
	porcentajesActuacionMedio = _porcentajesActuacionMedio;
}

void Recuperacion::setDatosActuacion(string _nivelActuacion, string _totalActuacion, double _porcentajeActuacion) {
	nivelActuacion = _nivelActuacion;
	totalActuacion = _totalActuacion;
	porcentajeActuacion = _porcentajeActuacion;
}

void Recuperacion::setProblemaGenerado(string _problemaGenerado) {
	problemaGenerado = _problemaGenerado;
}

void Recuperacion::setNombreJugador(string _nombreJugador) {
	this->nombreJugador = _nombreJugador;
}

void Recuperacion::setNumUltimaActividad(int _numAct)
{
	this->numAct = _numAct;
}

void Recuperacion::setDificultadActividad(string _dificultad)
{
	this->dificultad = _dificultad;
}

void Recuperacion::setComplejidadActividad(string _complejidad)
{
	this->complejidad = _complejidad;
}

void Recuperacion::setObjetivoActividad(string _objetivo)
{
	this->objetivo = _objetivo;
}

void Recuperacion::setHabilidadActividad(string _habilidad)
{
	this->habilidad = _habilidad;
}

void Recuperacion::setNumSesion(int _numSesion)
{
	this->numSesion = _numSesion;
}

void Recuperacion::setContadorAlto(int _contadorAlto) {
	contadorAlto = _contadorAlto;
}

void Recuperacion::setContadorMedio(int _contadorMedio) {
	contadorMedio = _contadorMedio;
}

void Recuperacion::setContadorBajo(int _contadorBajo) {
	contadorBajo = _contadorBajo;
}

void Recuperacion::setNivelActuacionRegla(string _nivelActuacionRegla) {
	nivelActuacionRegla = _nivelActuacionRegla;
}

string Recuperacion::getNivelActuacionRegla() {
	return nivelActuacionRegla;
}

string Recuperacion::getProblemaGenerado() {
	return problemaGenerado;
}

string Recuperacion::getNombreJugador() {
	return nombreJugador;
}

int Recuperacion::getNumUltimaActividad()
{
	return numAct;
}

int Recuperacion::getContadorAlto() {
	return contadorAlto;
}

int Recuperacion::getContadorMedio() {
	return contadorMedio;
}

int Recuperacion::getContadorBajo() {
	return contadorBajo;
}

string Recuperacion::getDificultadActividad()
{
	return dificultad;
}

string Recuperacion::getComplejidadActividad()
{
	return complejidad;
}

string Recuperacion::getObjetivoActividad()
{
	return objetivo;
}

string Recuperacion::getHabilidadActividad()
{
	return habilidad;
}

int Recuperacion::getNumSesion()
{
	return numSesion;
}

string Recuperacion::getNivelActuacion() {
	return nivelActuacion;
}

string Recuperacion::getTotalActuacion() {
	return totalActuacion;
}

double Recuperacion::getPorcentajeActuacion() {
	return porcentajeActuacion;
}

