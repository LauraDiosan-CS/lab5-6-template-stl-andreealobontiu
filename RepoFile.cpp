#include "RepoFile.h"

RepoFile::RepoFile()
{
	this->masini = {};
	this->fisier = NULL;
}

RepoFile::RepoFile(char * fisier)
{
	this->fisier = fisier;
	citireFisier(fisier);
}

void RepoFile::citireFisier(char * fisier)
{
	ifstream fin;
	fin.open(fisier);
	if (!fin)
	{
		cout << "Eroare la deschiderea fisierului" << endl;
	}
	else
		Masina masina;
		char* posesor = new char[50];
		char* nrInmatriculare = new char[50];
		char* status = new char[50];
		//string posesor, nrInmatriculare, status;
		while (!fin.eof())
		{
			fin >> posesor >> nrInmatriculare >> status;
			Masina m = Masina(posesor, nrInmatriculare, status);
			this->masini.push_back(m);
		}
}

void RepoFile::scriereFisier()
{
}

void RepoFile::addMasina(Masina m)
{
}

list<Masina> RepoFile::getAll()
{
	return list<Masina>();
}
