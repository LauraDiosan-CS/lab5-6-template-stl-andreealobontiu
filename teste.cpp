#include "teste.h"
#include "Masina.h"
#include "Repository.h"
#include "Service.h"
#include <assert.h>
#include <string.h>
#include <iostream>

using namespace std;

void testMasina()
{
	Masina m1 = Masina("andreea", "ab56afs", "liber");
	assert(strcmp(m1.getNumePosesor(),"andreea")==0);
	m1.setNrInmatriculare("ab-06-kxv");
	Masina m2 = Masina(m1);
	assert(strcmp(m1.getNrInmatriculare(), m2.getNrInmatriculare()) == 0);
	m2.setStatus("ocupat");
	assert(strcmp(m2.getStatus(), "ocupat") == 0);

	Masina m3 = Masina();
	assert(m3.getNumePosesor() == NULL);
	assert(m3.getNumePosesor() == NULL);
	m3.setNumePosesr("Aurel");
	assert(m3.getNumePosesor() != NULL);
	
	assert(m2.compare(m1) == false);
	
	cout << "Testele pentru clasa Masina functioneaza" << endl;
}

void testRepository()
{
	Repository repo;
	assert(repo.getLen() == 0);
	assert(repo.getAll().empty() == true);
	
	Masina m1 = Masina("Andreea", "AB-06-KXV", "ocupat");
	Masina m2 = Masina("Alex", "CJ-56-ASD", "liber");
	Masina m3 = Masina("Laura", "CJ-76-GHF", "liber");
	Masina m4 = Masina("Constantin", "TL-03-LDF", "ocupat");
	Masina m5 = Masina("Dan", "SM-50-THU", "ocupat");
	Masina m6 = Masina(m1);
	repo.addMasina(m1);
	repo.addMasina(m2);
	repo.addMasina(m3);
	repo.addMasina(m4);
	repo.addMasina(m5);
	repo.addMasina(m6);
	
	assert(repo.getLen() == 6);
	repo.deleteMasina(m1);
	assert(repo.getLen() == 4);

	repo.updateMasina(1, m1);
	assert(repo.findElem(m1)==true);
	assert(repo.getAll().empty() == false);
	
	cout << "Testele pentru clasa Repository functioneaza" << endl;
}

void testService()
{
	Service serv;
	assert(serv.getRepo().getAll().empty() == true);

	Masina m1 = Masina("Andreea", "AB-06-KXV", "ocupat");
	Masina m2 = Masina("Alex", "CJ-56-ASD", "liber");
	Masina m3 = Masina("Laura", "CJ-76-GHF", "liber");
	Masina m4 = Masina("Constantin", "TL-03-LDF", "ocupat");
	Masina m5 = Masina("Dan", "SM-50-THU", "ocupat");
	serv.addMasina(m1);
	serv.addMasina(m2);
	serv.addMasina(m3);
	serv.addMasina(m4);
	serv.addMasina(m5);
	assert(serv.getRepo().getLen() == 5);
	
	serv.updateMasina(0, m5);
	assert(serv.getRepo().findElem(m1) == false);

	serv.deleteMasina(m5);
	assert(serv.getLen() == 3);

	serv.getRepo().getAll().clear();
	assert(serv.getLen() != 0);
	assert(serv.getRepo().getAll().empty() == false);

	assert(serv.getOcupat() == 1);
	

	cout << "Testele pentru clasa Service functioneaza" << endl;
}
