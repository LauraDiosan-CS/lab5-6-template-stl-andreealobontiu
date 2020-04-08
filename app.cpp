#include "Repository.h"
#include "Masina.h"
#include "teste.h"
#include "Service.h"
#include "UI.h"
#include <iostream>
 
using namespace std;

int main()
{
	testMasina();
	testRepository();
	testService();
	cout << endl;

	UI u;
	u.interFace();
	system("pause");

	
	
	return 0;
}