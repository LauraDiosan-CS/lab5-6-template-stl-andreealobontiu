#include "Repository.h"

void Repository::addMasina(Masina m)
{
	masini.push_back(m);
}

int Repository::getLen()
{
	return masini.size();
}

vector<Masina> Repository::getAll()
{
	return masini;
}
