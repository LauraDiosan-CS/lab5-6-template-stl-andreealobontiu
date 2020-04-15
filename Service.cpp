#include "Service.h"

//constructor default pentru Service
Service::Service()
{
	this->repoFile = {};
}

//destructor pentru Service
Service::~Service()
{
	if (!this->repoFile.getAll().empty())
	{
		this->repoFile.getAll().clear();
	}
}

//getter pentru Repository
Repository Service::getRepo()
{
	return this->repoFile;
}

//descriere: functie care adauga in Service o masina
//in: o instanta de Masina
//out: -
void Service::addMasina(Masina m)
{
	if(this->repoFile.findNrInmatriculare(m.getNrInmatriculare())==true)
	{
		cout << "Nu se poate adauga aceasta masina" << endl << endl;
	}
	else
		this->repoFile.addMasina(m);
}

//functie care actualizeaza informatiile despre o masina
//in: indexul masinii care urmeaza sa fie actualizata si noile informatii
//out: o instanta de Masina cu informatiile actualizate
void Service::updateMasina(int index, Masina m)
{
	this->repoFile.updateMasina(index, m);
}

//functie care printeaza lista de masini
void Service::readMasini()
{
	int i = 0;
	for (auto elem:this->repoFile.getAll())
	{
		cout <<i<<":  "<< elem.toString()<<endl;
		i++;
	}
}

//functie care sterge o instanta de Masina dupa index
//in: indexul masinii care urmeaza sa fie stearsa
//out: -
void Service::deleteMasina(Masina m)
{
	this->repoFile.deleteMasina(m);
}

//getter pentru lungimea Repository
int Service::getLen()
{
	return this->repoFile.getAll().size();
}

//functie care apeleaza citirea datelor dintr-un fisier
//in: numele fisierului
//out: RepoFile populat cu datele din fisier
void Service::citireFisier(const char * fisier)
{
	this->repoFile.citireFisier(fisier);
}

//functie care returneaza statusul unei masini dupa index
//in: indexul masinii la care se doreste statusul
//out: statusul masinii de la indexul dat
char* Service::getStatus(int index)
{
	return this->repoFile.getStatus(index);
}

//functie care actualizeaza statusul unei masini dupa index
//in: noul status, indexul masinii care se actualizeaza
//out: instanta de Masina cu statusul actualizat
void Service::updateStatus(const char* newS, int index)
{
	this->repoFile.updateStatus(newS, index);
}

//functie care returneaza numarul de masini cu statusul "ocupat"
//in: -
//out: numarul de masini cu statusul "ocupat"
int Service::getOcupat()
{
	int ocupat = 0;
	for (auto elem:this->repoFile.getAll())
	{
		if (strcmp(elem.getStatus(),"ocupat")==0)
		{
			ocupat++;
		}
	}
	return ocupat;
}
