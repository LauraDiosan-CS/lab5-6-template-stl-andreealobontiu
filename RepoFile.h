#pragma once
#include "Repository.h"
#include <fstream>
#include <iostream>

using namespace std;

class RepoFile : public Repository
{
private:
	list<Masina> masini;
	list<Masina>::iterator it;
	char* fisier;
public:
	RepoFile();
	RepoFile(char* fisier);
	void citireFisier(char* fisier);
	void scriereFisier();
	void addMasina(Masina m);
	list<Masina> getAll();
	
};

