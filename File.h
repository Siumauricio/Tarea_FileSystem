#pragma once
#include "FileEntry.h"
#ifndef FILE_H
#define FILE_H


class File: public FileEntry {
private:
public:
	string extension = "";
	int bytes = 0;
	File (string,string,int,string);
};
#endif