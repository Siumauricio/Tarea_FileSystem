#pragma once
#include "FileEntry.h"
class Directory:public FileEntry {
private:

public:
	FileEntry **hijos = 0;
	int cantHijos = 0;
	Directory (string,string);
};
