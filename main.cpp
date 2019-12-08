#include <iostream>
#include "FileSystem.h"
using namespace std;

int main () {
	FileSystem nuevo;
	//nuevo.AnadirTipo(new Directory("/",4));
	cout << "TIPO 1=DIRECTORIO \nTIPO 0= ARCHIVO\n\n";
	nuevo.AgregarArchivo (new Directory("//",""));
	nuevo.AgregarArchivo (new File ("Hacks",".zip",543,"//"));
	nuevo.AgregarArchivo (new File ("Aimbot",".exe",123,"Hacks"));
	nuevo.AgregarArchivo (new Directory ("Programacion","//"));
	nuevo.AgregarArchivo (new Directory ("Estructura","Programacion"));
	nuevo.AgregarArchivo (new Directory ("BASE DE DATOS","Estructura"));
	nuevo.AgregarArchivo (new File ("Fortnite",".exe",123,"Estructura"));
	nuevo.imprimir ();

	return 0;
}