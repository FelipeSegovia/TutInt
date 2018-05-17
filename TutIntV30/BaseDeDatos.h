#pragma once
#ifndef BASE_DE_DATOS
#define BASE_DE_DATOS

#include <string>
#include <msclr\marshal_cppstd.h>
#include <list>
#include "TiempoMI.h"

using namespace System::Data::SqlClient;

public ref class BaseDeDatos
{
public: 
	BaseDeDatos();
	~BaseDeDatos();
	//--------------SELECCIONAR---------
	System::Data::DataSet^ seleccionarListaUsuariosRegistrados();
	int seleccionarNumeroSesion();
	std::list<std::string>seleccionarNivelesDisponibles();
	int seleccionarTotalEstrellas();
	int seleccionarCantEstrellasNivel();
	std::vector<std::string> seleccionarHabilidadesDisponibles();
	int seleccionarActividadActual();
	std::string seleccionarDificultadActividadActual();
	std::string seleccionarComplejidadActividadActual();
	int seleccionarContadorAlto();
	int seleccionarContadorMedio();
	int seleccionarContadorBajo();
	std::string seleccionarUltimoProblemaGenerado();
	std::string seleccionarUltimoNivelActuacion();
	std::vector<std::string> seleccionarTotalActuacion();
	int seleccionarCantEstrellasHabilidad();
	std::string seleccionarObjetivoActividadActual();
	std::vector<double> seleccionarPorcentajeActuacionMedio();
	std::vector<int> seleccionarCodigoPercepcionesMedio();
	int seleccionarUltimoCodigoActividad();
	int seleccionarIntentosActividad();

	//--------------INGRESAR------------
	bool ingresarDatosRegistro(System::String^ nombre);
	void ingresarDesbloqueoSiguienteHabilidad(System::String^ hab_sgte);
	void ingresarPercepcionesUsuario(TiempoMI* timepoAct, int cantAyuda, System::String^ porcentActuacion, System::String^ nivActuacion, System::String^ totalActuacion);
	void ingresarDatosActividadActual(int buenas, int malas, System::String ^ niv_logro, int estrellas, int intento, System::String^ problema, System::String^ reglaNivActuacion);
	void ingresarTiemposItem(TiempoMI* tiempo, int item);
	void ingresarActualizarDatosEstrellasNivel(int estrellas);
	void ingresarActualizarDatosEstrellasHabilidad(int estrellas);
	void ingresarActualizarDatosEstrellasTotales(int estrellas);
	void ingresarActualizacionDatosHabilidad(System::String ^ nivLogro_hab, int cantEstrellas, System::String ^ permiso);
	//--------------ACTUALIZAR----------
	void actualizarContadoresHabilidad(int contadorBueno, int contadorMedio, int contadorMalo);
	//-----------------SET--------------
	void setNombreJugador(System::String^ nombre);
	void setNumSesion(int numSesion);
	void setNombreNivel(System::String^ nomNivel);
	void setNombreHabilidad(System::String^ nomHab);
	void setDificultad(System::String^ _dificultad);
	void setComplejidad(System::String^ _complejidad);
	void setNumeroActividad(int numAct);
	void setCodigoActividad(int codigo);
	//----------------GET---------------
	std::string getNombreJugador();
	int getNumSesion();
	//----------SOLO USO EN LA CLASE----
	void estadoBD(int estado);

private:
	const int CONECTAR = 1;
	const int DESCONECTAR = 0;
	SqlConnection^ conn;
	SqlCommand^ connCmd;
	SqlDataReader^ dataReader;
	System::String^ nombreJugador;
	System::String^ nivel;
	System::String^ habilidad;
	System::String^ dificultad;
	System::String^ complejidad;
	msclr::interop::marshal_context context;
	int num_sesion;
	int numActividad;
	int codigo_act;
};

#endif // !BASE_DE_DATOS