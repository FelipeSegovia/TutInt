#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H
#include "Conector.h"

class LeerArchivo {

public:
	LeerArchivo();
	~LeerArchivo();
	void copiarArchivo(string nombreArchivo);
	void lectura(string nombreArchivo);			// nombreArchivo = baseConocimiento[NombreUsuario].txt
	void escribirArchivo(string nombreArchivo);
	vector<string> separarNombre(string nombreArchivo);

private:
	Conector *conector;
};

#endif // LEERARCHIVO_H