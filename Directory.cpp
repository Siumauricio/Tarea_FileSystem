#include "Directory.h"


Directory::Directory (string nombre,string padre) {
	this->nombre = nombre;
	this->hijos = 0;
	this->tipo = DIRECTORIO;
	this->padre = padre;
}
