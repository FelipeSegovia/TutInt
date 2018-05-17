#include "Percepciones.h"

using namespace std;

Percepciones::Percepciones() { }

// Para Agente Controlador
Percepciones::Percepciones(int act, string hab, string compl, string dific, std::string obj) {
	actividad = act;
	habilidad = hab;
	complejidad = compl;
	dificultad = dific;
	objetivo = obj;
}

// Para Agente DCL
Percepciones::Percepciones(string nivLogro, int ayuda, vector<TiempoMI*> timeItems, TiempoMI* timeAct, string obj) {
	nivelLogro = nivLogro;
	cantAyuda = ayuda;
	tiempoItems = timeItems;
	tiempoAct = timeAct;
	objetivo = obj;
}

Percepciones::~Percepciones() { }

vector<string> Percepciones::getRespuestas() {
	return respuestas;
}

void Percepciones::setRespuestas(vector<string> resp) {
	respuestas = resp;
}

string Percepciones::getNivelLogro() {
	return nivelLogro;
}

void Percepciones::setNivelLogro(string nivLogro) {
	nivelLogro = nivLogro;
}

int Percepciones::getCantAyuda() {
	return cantAyuda;
}

std::string Percepciones::getTotalActuacion()
{
	return totalActuacion;
}

std::string Percepciones::getNivelActuacionEscrito()
{
	return nivelActuacionEscrito;
}

void Percepciones::setCantAyuda(int ayuda) {
	cantAyuda = ayuda;
}

vector<TiempoMI*> Percepciones::getTiempoItems() {
	return tiempoItems;
}

void Percepciones::setTiempoItems(vector<TiempoMI*> timeItems) {
	tiempoItems = timeItems;
}

TiempoMI* Percepciones::getTiempoAct() {
	return tiempoAct;
}

void Percepciones::setTiempoAct(TiempoMI* timeAct) {
	tiempoAct = timeAct;
}

int Percepciones::getActividad() {
	return actividad;
}

void Percepciones::setActividad(int act) {
	actividad = act;
}

string Percepciones::getHabilidad() {
	return habilidad;
}

void Percepciones::setHabilidad(string hab) {
	habilidad = hab;
}

string Percepciones::getComplejidad() {
	return complejidad;
}

void Percepciones::setComplejidad(string compl) {
	complejidad = compl;
}

void Percepciones::setTotalActuacion(std::string total)
{
	totalActuacion = total;
}

void Percepciones::setNivelActuacionEscrito(std::string nivActuacionEscrito)
{
	nivelActuacionEscrito = nivActuacionEscrito;
}

string Percepciones::getDificultad() {
	return dificultad;
}

void Percepciones::setDificultad(string dific) {
	dificultad = dific;
}

string Percepciones::getObjetivo() {
	return objetivo;
}

void Percepciones::setObjetivo(string obj) {
	objetivo = obj;
}

double Percepciones::getNivelActuacion() {
	return nivelActuacion;
}

void Percepciones::setNivelActuacion(double nivActuacion) {
	nivelActuacion = nivActuacion;
}

void Percepciones::setPorcentAutonomia(double _porcentAutonomia) {
	porcentAutonomia = _porcentAutonomia;
}

void Percepciones::setPorcentEficacia(double _porcentEficacia) {
	porcentEficacia = _porcentEficacia;
}

void Percepciones::setPorcentMotivacion(double _porcentMotivacion) {
	porcentMotivacion = _porcentMotivacion;
}

void Percepciones::setPorcentLogro(double _porcentLogro) {
	porcentLogro = _porcentLogro;
}

double Percepciones::getPorcentAutonomia() {
	return porcentAutonomia;
}

double Percepciones::getPorcentEficacia() {
	return porcentEficacia;
}

double Percepciones::getPorcentMotivacion() {
	return porcentMotivacion;
}

double Percepciones::getPorcentLogro() {
	return porcentLogro;
}