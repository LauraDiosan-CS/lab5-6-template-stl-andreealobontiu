#pragma once
#include "Masina.h"
#include<vector>

class Repository {
private:
	vector<Masina> masini;
public:
	Repository(){}
	~Repository(){}
	void addMasina(Masina m);
	int getLen();
	vector<Masina> getAll();
};