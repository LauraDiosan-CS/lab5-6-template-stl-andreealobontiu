#include "Repository.h"
#include "Masina.h"
#include "teste.h"
#include <iostream>
 
using namespace std;

int main()
{
	testMasina();
	testRepository();
	Repository repo; 

	Masina m1 = Masina("andreea", "ab06kxv", "ocupat");
	Masina m2 = Masina(m1);

	cout << m1.toString() << endl << m2.toString() << endl;
	
}