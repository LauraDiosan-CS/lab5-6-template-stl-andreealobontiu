#include "RepoFile.h"

//constructor implicit pentru Repofile
RepoFile::RepoFile()
{
	this->fisier = NULL;
}

//constructor cu parametri pentru Repofile
//in: numele fisierului din care se vor citi date
//out: RepoFile populat cu datele din fisier
RepoFile::RepoFile(char * fisier)
{
	this->fisier = fisier;
	citireFisier(fisier);
}

//functie care citeste din fisier date
//in: numele fisierului
//out: RepoFile populat cu datele din fisier
void RepoFile::citireFisier(const char * fisier)
{
	ifstream fin;
	fin.open(fisier);
	if (!fin)
	{
		cout << "Eroare la deschiderea fisierului" << endl;
	}
	else
	{
		Masina masina;
		char* posesor = new char[50];
		char* nrInmatriculare = new char[50];
		char* status = new char[50];
		while (!fin.eof())
		{
			fin >> posesor >> nrInmatriculare >> status;
			masina = Masina(posesor, nrInmatriculare, status);
			this->addMasina(masina);
			
		}
	}
	fin.close();
}

