#include "File.h"

File::File (string nombre,string extension,int bytes,string padre) {
	this->nombre = nombre;
	this->extension = extension;
	this->bytes = bytes;
	this->padre = padre;
	this->tipo = ARCHIVO;
}
