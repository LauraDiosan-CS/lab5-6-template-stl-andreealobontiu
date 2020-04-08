#pragma once
#include "Repository.h"
#include "Masina.h"
#include <iostream>

using namespace std;

class Service
{
private:
	Repository repo;
public:
	Service();
	~Service();
	Repository getRepo();
	void addMasina(Masina m);
	void updateMasina(int index, Masina m);
	void readMasini();
	void deleteMasina(Masina m);
	int getLen();

	int getOcupat();
};

