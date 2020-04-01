#include "teste.h"
#include "Masina.h"
#include "Repository.h"
#include <assert.h>
#include <iostream>
using namespace std;

void testMasina()
{
	Masina m1 = Masina("andreea", "ab56afs", "liber");
	m1.setNumePosesr("alina");
	assert(m1.getNumePosesor() == "alina");
	assert(m1.getNrInmatriculare() == m1.getNrInmatriculare());
	m1.setStatus("ocupat");
	assert(m1.getStatus() == "ocupat");
	Masina m2 = Masina(m1);
	assert(m2.getNrInmatriculare() == m1.getNrInmatriculare());
	Masina m3 = Masina();
	assert(m3.getStatus() == NULL);
}

void testRepository()
{
	Repository r;
	assert(r.getLen() == 0);

	Masina m1 = Masina("andreea", "ab56afs", "liber");
	r.addMasina(m1);
	assert(r.getLen() == 1);

	vector<Masina>masini;
	masini = r.getAll();
	assert(r.getAll()[0].compare(masini[0])==true);
	
}
