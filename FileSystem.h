#pragma once
#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H
#include <iostream>
#include "FileEntry.h"
#include "Directory.h"
#include "File.h"
using namespace std;

class FileSystem {
private:
	Directory *raiz;
	bool estaVacio ();
	void ImprimirRec (Directory *raiz);
	Directory *buscarRec (Directory *,string);
public:

	FileSystem (FileEntry*);
	FileSystem ();
	void AgregarArchivo (FileEntry *);
	Directory *buscar (string);
	void imprimir ();
	void AnadirTipo (FileEntry* tipo);

};
#endif