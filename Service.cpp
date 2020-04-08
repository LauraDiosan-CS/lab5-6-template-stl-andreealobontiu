#include "Service.h"

//constructor default pentru Service
Service::Service()
{
	this->repo = {};
}

//destructor pentru Service
Service::~Service()
{
	if (!this->repo.getAll().empty())
	{
		this->repo.getAll().clear();
	}
}

//getter pentru Repository
Repository Service::getRepo()
{
	return this->repo;
}

//descriere: functie care adauga in Service o masina
//in: o instanta de Masina
//out: -
void Service::addMasina(Masina m)
{
	if(this->repo.findElem(m)==true)
	{
		cout << "Masina exista deja in gestiune" << endl << endl;
	}
	else
		this->repo.addMasina(m);
}

//functie care actualizeaza informatiile despre o masina
//in: indexul masinii care urmeaza sa fie actualizata si noile informatii
//out: o instanta de Masina cu informatiile actualizate
void Service::updateMasina(int index, Masina m)
{
	this->repo.updateMasina(index, m);
}

//functie care printeaza lista de masini
void Service::readMasini()
{
	int i = 0;
	for (auto elem:this->repo.getAll())
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
	this->repo.deleteMasina(m);
}

//getter pentru lungimea Repository
int Service::getLen()
{
	return this->repo.getAll().size();
}

int Service::getOcupat()
{
	int ocupat = 0;
	for (auto elem:this->repo.getAll())
	{
		if (strcmp(elem.getStatus(),"ocupat")==0)
		{
			ocupat++;
		}
	}
	return ocupat;
}
