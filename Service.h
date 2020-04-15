#pragma once
#include "Repository.h"
#include "RepoFile.h"
#include "Masina.h"
#include <iostream>

using namespace std;

class Service
{
private:
	//Repository repo;
	RepoFile repoFile;
public:
	Service();
	~Service();
	Repository getRepo();
	void addMasina(Masina m);
	void updateMasina(int index, Masina m);
	void readMasini();
	void deleteMasina(Masina m);
	int getLen();
	void citireFisier(const char* fisier);
	char* getStatus(int index);
	void updateStatus(const char* newS, int index);
	int getOcupat();
};

