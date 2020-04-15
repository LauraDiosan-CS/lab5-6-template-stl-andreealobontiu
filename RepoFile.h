#pragma once
#include "Repository.h"
#include <fstream>
#include <iostream>

using namespace std;

class RepoFile : public Repository
{
private:
	char* fisier;
public:
	RepoFile();
	RepoFile(char* fisier);
	void citireFisier(const char* fisier);
	
};

