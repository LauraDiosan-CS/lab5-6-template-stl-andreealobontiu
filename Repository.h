#pragma once
#include "Masina.h"
#include<list>
#include <iterator>

class Repository {
private:
	list<Masina> masini;
	list<Masina>::iterator it;
public:
	Repository();
	~Repository();
	void addMasina(Masina m);
	void deleteMasina(Masina m);
	void deleteMasina(int index);
	void updateMasina(int index, Masina newM);
	int getLen();
	bool findElem(Masina m);
	list<Masina> getAll();
	
};
