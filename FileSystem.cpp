#include "FileSystem.h"

FileSystem::FileSystem (): raiz (0) {}

FileSystem::FileSystem (FileEntry* tipo) {
	this->raiz = (Directory*)tipo;
}
void FileSystem ::AnadirTipo (FileEntry* tipo) {
	FileSystem *file = new FileSystem (tipo);
	AgregarArchivo ((FileEntry*)file);
}
void FileSystem::AgregarArchivo (FileEntry*archivo) {
	if(estaVacio ()) {
		raiz = (Directory*)archivo;
		return;
	}
		Directory *padre = buscar (archivo->padre);
		if(padre == 0||padre->tipo==ARCHIVO) {
			cout << "Ingrese Un Padre Valido!" << endl;
			return;
		}
		//crear copia de hijos
		Directory **tmpHijos = new Directory * [raiz->cantHijos + 1]; //declarando un arreglo de apuntadores
		for(int i = 0; i < padre->cantHijos; i++) {
			tmpHijos[i] = (Directory *)padre->hijos[i];
		}
		tmpHijos[padre->cantHijos] = (Directory *)archivo;

		if(padre->cantHijos != 0) {
			delete padre->hijos;
		}
		padre->cantHijos++;
		padre->hijos = (FileEntry **)tmpHijos;
}
bool FileSystem::estaVacio () {

	return raiz == 0;
}

Directory *FileSystem::buscar (string codigoPadre) {
	return buscarRec (raiz,codigoPadre);
}

Directory *FileSystem::buscarRec (Directory *raiz,string codigoPadre) {
	if(raiz == 0)
		return 0;
	if(raiz->nombre == codigoPadre)
		return raiz;

	for(int i = 0; i < raiz->cantHijos; i++) {
		if(raiz->hijos[i]->tipo!=ARCHIVO) {
			Directory *tmp = buscarRec ((Directory *)raiz->hijos[i],codigoPadre);
			if(tmp != 0)
				return tmp;
		}
	}
	return 0;
}

void FileSystem::imprimir () {
	ImprimirRec (raiz);
}

void FileSystem::ImprimirRec (Directory *raiz) {
	if(raiz == 0) {
		return;
	}
	cout << "{ Nombre: " << raiz->nombre << ", Padre: " << raiz->padre << " Tipo: "<<raiz->tipo<<"}" << endl;
	for(int i = 0; i < raiz->cantHijos; i++) {
		if(raiz->hijos[i]->tipo != ARCHIVO) {
			ImprimirRec ((Directory *)raiz->hijos[i]);
		}else{
			File *a = (File*)raiz->hijos[i];
			cout << "{ Nombre: " << raiz->hijos[i]->nombre << " Extension: "<<  a->extension<<", Padre: " << raiz->hijos[i]->padre << " Tipo: " << raiz->hijos[i]->tipo<< " Tamano Bytes: "<< a->bytes <<"}" << endl;
			
		}
    }
}



