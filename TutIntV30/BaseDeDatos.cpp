#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos()
{
	conn = gcnew SqlConnection("Data source=DESKTOP-BP5P7DB;Initial Catalog=bd_tutin;User Id=sa;Password=felipe69");
}

BaseDeDatos::~BaseDeDatos(){}

System::Data::DataSet ^ BaseDeDatos::seleccionarListaUsuariosRegistrados()
{
	estadoBD(CONECTAR);

	SqlDataAdapter^ daJugador = gcnew SqlDataAdapter("SELECT * FROM jugador", conn);
	System::Data::DataSet^ dsJugador = gcnew System::Data::DataSet();
	daJugador->Fill(dsJugador);
	
	estadoBD(DESCONECTAR);
	return dsJugador;
}

int BaseDeDatos::seleccionarNumeroSesion()
{
	std::string actActual;

	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT num_sesion FROM actividad,jugador WHERE IdJugador_act = '" + nombreJugador + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			actActual = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
		}
		estadoBD(DESCONECTAR);
		return atoi(actActual.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return atoi(actActual.c_str());
}

std::list<std::string> BaseDeDatos::seleccionarNivelesDisponibles()
{
	std::list<std::string> listnomNivel;

	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT nom_nivel FROM nivel WHERE IdJugador_nivel = '" + nombreJugador + "' AND permiso = 'Desbloqueado';", conn);
	SqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read()) {
		listnomNivel.push_back(context.marshal_as<std::string>(query[0]->ToString()));
	}
	estadoBD(DESCONECTAR);

	return listnomNivel;
}

int BaseDeDatos::seleccionarTotalEstrellas()
{
	//Inicio la base de datos
	estadoBD(CONECTAR);
	std::string estrellas;
	connCmd = gcnew SqlCommand("SELECT total_estrellas FROM jugador WHERE nom_jugador = '" + nombreJugador + "'; ", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			estrellas = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
		}
		estadoBD(DESCONECTAR); //Cierro la base de datos
		return atoi(estrellas.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}

	return atoi(estrellas.c_str());
}

int BaseDeDatos::seleccionarCantEstrellasNivel()
{
	estadoBD(CONECTAR);
	std::string estrellas;
	connCmd = gcnew SqlCommand("SELECT cant_estrellas FROM nivel WHERE IdJugador_nivel = '" + nombreJugador + "' AND nom_nivel = '" + nivel + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			estrellas = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
		}
		estadoBD(DESCONECTAR); //Cierro la base de datos
		return atoi(estrellas.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return atoi(estrellas.c_str());
}

std::vector<std::string> BaseDeDatos::seleccionarHabilidadesDisponibles()
{
	std::vector<std::string> habilidades;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT nombre_hab,permiso FROM habilidad WHERE IdJugador_hab ='" + nombreJugador + "' AND permiso = 'DESBLOQUEADO';", conn);
	SqlDataReader^ query = connCmd->ExecuteReader();
	while (query->Read())
	{
		habilidades.push_back(context.marshal_as<std::string>(query[0]->ToString()));
	}
	estadoBD(DESCONECTAR);
	return habilidades;
}

int BaseDeDatos::seleccionarActividadActual()
{
	std::string actActual;

	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT num_actividad FROM actividad WHERE IdJugador_act = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "' ORDER BY num_actividad ASC;", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			actActual = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
		}
		estadoBD(DESCONECTAR); //Cierro la base de datos
		return atoi(actActual.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return atoi(actActual.c_str());
}

std::string BaseDeDatos::seleccionarDificultadActividadActual()
{
	std::string dificultad;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT dificultad FROM actividad WHERE IdJugador_act = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "';", conn);
	SqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read())
	{
		dificultad = context.marshal_as<std::string>(query[0]->ToString());
	}
	estadoBD(DESCONECTAR);
	return dificultad;
}

std::string BaseDeDatos::seleccionarComplejidadActividadActual()
{
	std::string complejidad;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT complejidad FROM actividad WHERE IdJugador_act = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "' AND dificultad = '" + dificultad + "';", conn);
	SqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read())
	{
		complejidad = context.marshal_as<std::string>(query[0]->ToString());
	}
	estadoBD(DESCONECTAR);
	return complejidad;
}

int BaseDeDatos::seleccionarContadorAlto()
{
	std::string contador;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT contador_alto FROM habilidad WHERE nombre_hab = '" + habilidad + "' AND IdJugador_hab = '" + nombreJugador + "';", conn);
	dataReader = connCmd->ExecuteReader();
	while (dataReader->Read()) {
		contador = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
	}
	estadoBD(DESCONECTAR); //Cierro la base de datos
	return atoi(contador.c_str());
}

int BaseDeDatos::seleccionarContadorMedio()
{
	std::string contador;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT contador_medio FROM habilidad WHERE nombre_hab = '" + habilidad + "' AND IdJugador_hab = '" + nombreJugador + "';", conn);
	dataReader = connCmd->ExecuteReader();
	while (dataReader->Read()) {
		contador = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
	}
	estadoBD(DESCONECTAR); //Cierro la base de datos
	return atoi(contador.c_str());
}

int BaseDeDatos::seleccionarContadorBajo()
{
	std::string contador;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT contador_bajo FROM habilidad WHERE nombre_hab = '" + habilidad + "' AND IdJugador_hab = '" + nombreJugador + "';", conn);
	dataReader = connCmd->ExecuteReader();
	while (dataReader->Read()) {
		contador = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
	}
	estadoBD(DESCONECTAR); //Cierro la base de datos
	return atoi(contador.c_str());
}

std::string BaseDeDatos::seleccionarUltimoProblemaGenerado()
{
	estadoBD(CONECTAR);
	std::string reglaProblema;

	connCmd = gcnew SqlCommand("SELECT problema FROM actividad WHERE IdJugador_act = '" + nombreJugador + "' ORDER BY codigo_act DESC;", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			reglaProblema = context.marshal_as<std::string>(dataReader->GetString(0));
		}
		estadoBD(DESCONECTAR); //Cierro la base de datos
		return reglaProblema;
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return reglaProblema;
}

std::string BaseDeDatos::seleccionarUltimoNivelActuacion()
{
	estadoBD(CONECTAR);
	std::string reglaActuacion;

	connCmd = gcnew SqlCommand("SELECT regla_actuacion FROM actividad WHERE IdJugador_act = '" + nombreJugador + "' ORDER BY codigo_act DESC;", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			reglaActuacion = context.marshal_as<std::string>(dataReader->GetString(0));
		}
		estadoBD(DESCONECTAR); //Cierro la base de datos
		return reglaActuacion;
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return reglaActuacion;
}

std::vector<std::string> BaseDeDatos::seleccionarTotalActuacion()
{
	std::vector<std::string> total_actuacion;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT total_actuacion FROM percepciones,actividad WHERE actividad.num_actividad = percepciones.num_actividad AND nombre_hab = '" + habilidad + "' AND dificultad = '" + dificultad + "';", conn);
	SqlDataReader^ query = connCmd->ExecuteReader();
	while (query->Read())
	{
		total_actuacion.push_back(context.marshal_as<std::string>(query[0]->ToString()));
	}
	estadoBD(DESCONECTAR);
	return total_actuacion;
}

int BaseDeDatos::seleccionarCantEstrellasHabilidad()
{
	estadoBD(CONECTAR);
	std::string estrellas;
	connCmd = gcnew SqlCommand("SELECT cant_estrellas FROM habilidad WHERE IdJugador_hab = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		while (dataReader->Read()) {
			estrellas = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
		}
		estadoBD(DESCONECTAR); //Cierro la base de datos
		return atoi(estrellas.c_str());
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
	return atoi(estrellas.c_str());
}

std::string BaseDeDatos::seleccionarObjetivoActividadActual()
{
	std::string objetivo;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT objetivo FROM objetivos WHERE habilidad = '" + habilidad + "' AND dificultad = '" + dificultad + "' AND complejidad = '" + complejidad + "' AND num_actividad = '" + numActividad + "';", conn);
	SqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read())
	{
		objetivo = context.marshal_as<std::string>(query[0]->ToString());
	}
	estadoBD(DESCONECTAR);
	return objetivo;
}

std::vector<double> BaseDeDatos::seleccionarPorcentajeActuacionMedio()
{
	// Dos ultimos porcentaje del nivel de actuacion Medio
	std::vector<int> codigoPercepciones = seleccionarCodigoPercepcionesMedio();
	std::vector<double> porcentajesActuacion;
	if (codigoPercepciones.size() != 0 && codigoPercepciones.size() != 1) {
		estadoBD(CONECTAR);
		connCmd = gcnew SqlCommand("SELECT porcentaje_actuacion FROM percepciones WHERE codigo_percepciones = " + codigoPercepciones[0] + " OR codigo_percepciones = " + codigoPercepciones[1] + ";", conn);
		SqlDataReader^ query = connCmd->ExecuteReader();
		while (query->Read())
		{
			porcentajesActuacion.push_back(System::Convert::ToDouble(query[0]->ToString()));
		}
		estadoBD(DESCONECTAR);
	}
	return porcentajesActuacion;
}

std::vector<int> BaseDeDatos::seleccionarCodigoPercepcionesMedio()
{
	std::vector<int> codigoPercepciones;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT codigo_act FROM actividad WHERE IdJugador_act = '" + nombreJugador + "' ORDER BY codigo_act DESC;", conn);
	SqlDataReader^ query = connCmd->ExecuteReader();
	while (query->Read())
	{
		codigoPercepciones.push_back(System::Convert::ToInt32(query[0]->ToString()));
	}
	estadoBD(DESCONECTAR);
	return codigoPercepciones;
}

int BaseDeDatos::seleccionarUltimoCodigoActividad()
{
	std::string codigo;
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT codigo_act FROM actividad ORDER BY codigo_act DESC;", conn);
	dataReader = connCmd->ExecuteReader();
	while (dataReader->Read()) {
		codigo = context.marshal_as<std::string>(dataReader->GetInt32(0).ToString());
	}
	estadoBD(DESCONECTAR); //Cierro la base de datos
	return atoi(codigo.c_str());
}

int BaseDeDatos::seleccionarIntentosActividad()
{
	std::string intentos;
	int actividadActual = seleccionarActividadActual();
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("SELECT intentos FROM actividad WHERE IdJugador_act = '" + this->nombreJugador + "' AND num_actividad = " + this->numActividad + " AND nombre_hab = '" + this->habilidad + "';", conn);
	SqlDataReader^ query = connCmd->ExecuteReader();

	while (query->Read()) {
		intentos = context.marshal_as<std::string>(query[0]->ToString());
	}
	estadoBD(DESCONECTAR);

	return atoi(intentos.c_str());
}

bool BaseDeDatos::ingresarDatosRegistro(System::String ^ nombre)
{
	//Inicio la base de datos
	estadoBD(CONECTAR);
	//Datos de la tabla jugador

	connCmd = gcnew SqlCommand("INSERT INTO jugador(nom_jugador,total_estrellas) VALUES ('" + nombre + "',0);", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}

	//Datos de la tabla niveles
	//Nivel 1
	estadoBD(CONECTAR);
	setNombreNivel("Playa");
	connCmd = gcnew SqlCommand("INSERT INTO nivel(nom_nivel,IdJugador_nivel,cant_estrellas,permiso) VALUES('Playa','" + nombre + "', 0,'Desbloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Nivel 2
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("INSERT INTO nivel(nom_nivel,IdJugador_nivel,cant_estrellas,permiso) VALUES('Parque','" + nombre + "',0,'Bloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Nivel 3
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("INSERT INTO nivel(nom_nivel,IdJugador_nivel,cant_estrellas,permiso) VALUES('Espacio','" + nombre + "',0,'Bloqueado');", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Datos de la tabla habilidad
	//Conciencia_fonologica
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("INSERT INTO habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso,contador_alto,contador_medio,contador_bajo) VALUES ('Conciencia_fonologica','" + nombre + "','Playa','NN',0,'Desbloqueado',0,0,0);", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Conciencia_alfabetica
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("INSERT INTO habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso,contador_alto,contador_medio,contador_bajo) VALUES ('Conciencia_alfabetica','" + nombre + "','Playa','NN',0,'Bloqueado',0,0,0);", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Vocabulario
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("INSERT INTO habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso,contador_alto,contador_medio,contador_bajo) VALUES ('Vocabulario','" + nombre + "','Parque','NN',0,'Bloqueado',0,0,0);", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Comprension_literal
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("INSERT INTO habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso,contador_alto,contador_medio,contador_bajo) VALUES ('Comprension_literal','" + nombre + "','Parque','NN',0,'Bloqueado',0,0,0);", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	//Comprension_inferencial
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("INSERT INTO habilidad(nombre_hab,IdJugador_hab,nom_niv,niv_logro_hab,cant_estrellas,permiso,contador_alto,contador_medio,contador_bajo) VALUES ('Comprension_inferencial','" + nombre + "','Espacio','NN',0,'Bloqueado',0,0,0);", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
		return false;
	}
	return true;
}

void BaseDeDatos::ingresarDesbloqueoSiguienteHabilidad(System::String ^ hab_sgte)
{
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("UPDATE habilidad SET permiso = 'Desbloqueado' WHERE nombre_hab = '" + hab_sgte + "' AND IdJugador_hab = '" + nombreJugador + "';", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarPercepcionesUsuario(TiempoMI * timepoAct, int cantAyuda, System::String ^ porcentActuacion, System::String ^ nivActuacion, System::String ^ totalActuacion)
{
	//System::Windows::Forms::MessageBox::Show("Entro Percepciones");
	int minutos = timepoAct->getMinutos();
	int segundos = timepoAct->getSegundos();
	System::String^ tiempo = "00:" + context.marshal_as<System::String^>(std::to_string(minutos)) + ":" + context.marshal_as<System::String^>(std::to_string(segundos));
	estadoBD(CONECTAR);
	//connCmd = gcnew MySqlCommand("INSERT INTO `bd_tutin1.2`.percepciones(tiempo_actividad,cant_ayuda,porcentaje_actuacion,num_actividad,codigo_percepciones,nivel_actuacion,total_actuacion) VALUES('"+tiempo+"',"+cantAyuda+",0.5,'"+numActividad+"',537,'"+nivActuacion+"','"+totalActuacion+"');", conn);
	connCmd = gcnew SqlCommand("INSERT INTO percepciones(tiempo_actividad,cant_ayuda,porcentaje_actuacion,num_actividad,codigo_percepciones,nivel_actuacion,total_actuacion) VALUES('" + tiempo + "'," + cantAyuda + "," + porcentActuacion + ",'" + context.marshal_as<System::String^>(std::to_string(numActividad)) + "'," + codigo_act + ",'" + nivActuacion + "','" + totalActuacion + "');", conn);
	try
	{
		connCmd->ExecuteNonQuery();
		//System::Windows::Forms::MessageBox::Show("Insertar Percepciones Listo");
		estadoBD(DESCONECTAR);
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarDatosActividadActual(int buenas, int malas, System::String ^ niv_logro, int estrellas, int intento, System::String ^ problema, System::String ^ reglaNivActuacion)
{
	estadoBD(CONECTAR);
	//la columna problema hay que ver para que sirve
	connCmd = gcnew SqlCommand("INSERT INTO actividad(num_actividad,IdJugador_act,nombre_hab,buenas,malas,niv_logro_acti,cant_estrellas,intentos,dificultad,complejidad,codigo_act,num_sesion,problema,regla_actuacion) VALUES(" + numActividad + ",'" + nombreJugador + "','" + habilidad + "'," + buenas + "," + malas + ",'" + niv_logro + "'," + estrellas + "," + intento + ",'" + dificultad + "','" + complejidad + "'," + codigo_act + "," + num_sesion + ",'" + problema + "','" + reglaNivActuacion + "');", conn);
	try {
		connCmd->ExecuteNonQuery();
		//System::Windows::Forms::MessageBox::Show("Insertar Actividad Listo");
		estadoBD(DESCONECTAR);
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarTiemposItem(TiempoMI * tiempo, int item)
{
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("INSERT INTO tiempo_item (codigo_tr,num_item,tiempo) VALUES(" + codigo_act + ", " + item + ", '00:" + tiempo->getMinutos() + ":" + tiempo->getSegundos() + "'); ", conn);
	try
	{
		connCmd->ExecuteNonQuery();
		estadoBD(DESCONECTAR);
	}
	catch (System::Exception^ ex)
	{
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarActualizarDatosEstrellasNivel(int estrellas)
{
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("UPDATE nivel SET cant_estrellas = " + estrellas + " WHERE IdJugador_nivel = '" + this->nombreJugador + "' AND nom_nivel = '" + this->nivel + "';", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarActualizarDatosEstrellasHabilidad(int estrellas)
{
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("UPDATE habilidad SET cant_estrellas = " + estrellas + " WHERE IdJugador_hab = '" + nombreJugador + "' AND nombre_hab = '" + habilidad + "';", conn);
	try {
		connCmd->ExecuteNonQuery();

		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarActualizarDatosEstrellasTotales(int estrellas)
{
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("UPDATE jugador SET total_estrellas = " + estrellas + " WHERE nom_jugador = '" + nombreJugador + "';", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::ingresarActualizacionDatosHabilidad(System::String ^ nivLogro_hab, int cantEstrellas, System::String ^ permiso)
{
	estadoBD(CONECTAR);
	connCmd = gcnew SqlCommand("UPDATE Habilidad SET niv_logro_hab = '" + nivLogro_hab + "', cant_estrellas = " + cantEstrellas + ", permiso = '" + permiso + "' WHERE nombre_hab = '" + habilidad + "' AND IdJugador_hab = '" + nombreJugador + "';", conn);
	try {
		dataReader = connCmd->ExecuteReader();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::actualizarContadoresHabilidad(int contadorBueno, int contadorMedio, int contadorMalo)
{
	//Inicio la base de datos
	estadoBD(CONECTAR);
	//Datos de la tabla jugador
	connCmd = gcnew SqlCommand("UPDATE habilidad SET contador_alto = " + contadorBueno + ", contador_medio = " + contadorMedio + ", contador_bajo = " + contadorMalo + " WHERE nombre_hab = '" + habilidad + "' AND IdJugador_hab = '" + nombreJugador + "';", conn);
	try {
		connCmd->ExecuteNonQuery();
		estadoBD(DESCONECTAR); //Cierro la base de datos
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}

void BaseDeDatos::setNombreJugador(System::String ^ nombre)
{
	this->nombreJugador = nombre;
}

void BaseDeDatos::setNumSesion(int numSesion)
{
	this->num_sesion = numSesion;
}

void BaseDeDatos::setNombreNivel(System::String ^ nomNivel)
{
	this->nivel = nomNivel;
}

void BaseDeDatos::setNombreHabilidad(System::String ^ nomHab)
{
	this->habilidad = nomHab;
}

void BaseDeDatos::setDificultad(System::String ^ _dificultad)
{
	this->dificultad = _dificultad;
}

void BaseDeDatos::setComplejidad(System::String ^ _complejidad)
{
	this->complejidad = _complejidad;
}

void BaseDeDatos::setNumeroActividad(int numAct)
{
	this->numActividad = numAct;
}

void BaseDeDatos::setCodigoActividad(int codigo)
{
	this->codigo_act = codigo;
}

std::string BaseDeDatos::getNombreJugador()
{
	return context.marshal_as<std::string>(nombreJugador->ToString());
}

int BaseDeDatos::getNumSesion()
{
	return num_sesion;
}

void BaseDeDatos::estadoBD(int estado)
{
	if (estado == CONECTAR)
	{
		conn->Open();
	}
	else if (estado == DESCONECTAR)
	{
		conn->Close();
	}
}
