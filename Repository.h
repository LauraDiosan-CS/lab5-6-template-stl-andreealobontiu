#pragma once
#include "Masina.h"
#include<list>
#include <iterator>

class Repository {
private:
	list<Masina> masini;
	list<Masina>::iterator it;
	int capacitateMax = 7;
public:
	Repository();
	~Repository();
	void addMasina(Masina m);
	void deleteMasina(Masina m);
	void deleteMasina(int index);
	void updateMasina(int index, Masina newM);
	int getLen();
	bool findElem(Masina m);
	bool findNrInmatriculare(char* n);
	char* getStatus(int index);
	void updateStatus(const char* newS, int index);
	list<Masina> getAll();
	
	
};