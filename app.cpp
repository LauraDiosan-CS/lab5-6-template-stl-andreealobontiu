#include "Repository.h"
#include "teste.h"
#include "UI.h"
#include <iostream>
 
using namespace std;

int main()
{
	testMasina();
	testRepository();
	testRepoFile();
	testService();
	cout << endl;

	UI u;
	u.interFace();
	system("pause");

	
	
	return 0;
}