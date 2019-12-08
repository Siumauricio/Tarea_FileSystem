#pragma once
#ifndef FILE_H
#define FILE_H
using namespace std;
#include <string>

enum FILE_TYPE { ARCHIVO,DIRECTORIO };
class FileEntry {
public:
	string nombre = "";
	string padre = "";
	FILE_TYPE tipo;
};





#endif // !FILE_H
