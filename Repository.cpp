#include "Repository.h"


//constructor default pentru Repository
Repository::Repository()
{
	this->masini = {};
}

//destructor pentru Repository
Repository::~Repository()
{
	if (!this->masini.empty())
	{
		this->masini.clear();
	}
}

//descriere: functie care adauga in Repository o masina
//in: o instanta de Masina
//out: -
void Repository::addMasina(Masina m)
{
	masini.push_back(m);
}

//functie care sterge o Masina din Repository
//in: o instanta de Masina
//out: -
void Repository::deleteMasina(Masina m)
{
	this->masini.remove(m);
}

//functie care sterge o instanta de Masina dupa index
//in: indexul masinii care urmeaza sa fie stearsa
//out: -
void Repository::deleteMasina(int index)
{
	this->it = masini.begin();
	advance(it, index);
	masini.erase(it);
}

//functie care actualizeaza informatiile despre o masina
//in: indexul masinii care urmeaza sa fie actualizata si noile informatii
//out: o instanta de Masina cu informatiile actualizate
void Repository::updateMasina(int index, Masina newM)
{
	try
	{
		this->it = masini.begin();
		advance(it, index);
		it->setNumePosesr(newM.getNumePosesor());
		it->setNrInmatriculare(newM.getNrInmatriculare());
		it->setStatus(newM.getStatus());
	}
	catch (exception exp)
	{
		cout << "Masina nu a fost gasita!" << endl;
	}
}

//functie care returneaza lungimea Repository
//in: -
//out: lungimea Repository
int Repository::getLen()
{
	return masini.size();
}

//functie care verifica daca o masina se afla in Repository
//in: masina care se doreste a fi cautata
//out: true daca e gasita, false altfel
bool Repository::findElem(Masina m)
{
	for (auto elem:this->masini)
	{
		if (elem.compare(m)==true)
		{
			return true;
		}
	}
	return false;
}

//getter pentru lista de masini
list<Masina> Repository::getAll()
{
	return masini;
}
