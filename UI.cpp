#include "UI.h"
#include <iostream>

using namespace std;

//functie care printeaza meniul pe consola
void UI::printMeniu()
{
	cout << "0. Exit" << endl;
	cout << "1. Adauga o masina" << endl;
	cout << "2. Arata lista de masini" << endl;
	cout << "3. Actualizeaza o masina" << endl;
	cout << "4. Sterge o masina" << endl << endl;
	cout << "------SENZOR------" << endl;
	cout << "5. Intra cu o masina" << endl;
	cout << "6. Iesi cu o masina" << endl<<endl;
}

//functie care ruleaza aplicatia
void UI::interFace()
{
	int optiune;
	bool stop = true;
	RepoFile repo;
	/*Masina m1 = Masina("Andreea", "AB-06-KXV", "ocupat");
	Masina m2 = Masina("Alex", "CJ-56-ASD", "liber");
	Masina m3 = Masina("Laura", "CJ-76-GHF", "liber");
	Masina m4 = Masina("Constantin", "TL-03-LDF", "ocupat");
	Masina m5 = Masina("Dan", "SM-50-THU", "ocupat");
	Masina m6 = Masina("Maria", "SM-45-BDJ","liber");

	this->serv.addMasina(m1);
	this->serv.addMasina(m2);
	this->serv.addMasina(m3);
	this->serv.addMasina(m4);
	this->serv.addMasina(m5);
	this->serv.addMasina(m6);*/

	const char* fisier = new char[50];
	fisier = "fisier.txt";
	this->serv.citireFisier(fisier);

	int capacitateMax = 3;
	int capacitateCurenta = this->serv.getOcupat();
	
	while (stop)
	{
		printMeniu();
		cout << "Alegeti o optiune: ";
		cin >> optiune;
		cout << endl;

		if (optiune == 0)  //exit
		{
			stop = false;
			system("pause");
			cout << "Program incheiat" << endl;
		}
		else if (optiune == 1) //optiunea 1
		{
			char* posesor = new char[50];
			char* nrInmatriculare = new char[50];
			char* status = new char[50];

			cout << "Introduceti numele posesorului: ";
			cin >> posesor;

			cout << "Introduceti numarul de inmatriculare: ";
			cin >> nrInmatriculare;

			cout << "Introduceti statusul: ";
			cin >> status;

			if (strcmp(status,"ocupat")==0)
			{
				if (capacitateCurenta < capacitateMax)
				{
					Masina masinaAdd = Masina(posesor, nrInmatriculare, status);
					this->serv.addMasina(masinaAdd);
					//cout << "Masina a fost adaugata" << endl << endl;
					capacitateCurenta++;
				}
				else
					cout << "Parcarea este plina" << endl << endl;
			
			}
			else
			{
				Masina masinaAdd = Masina(posesor, nrInmatriculare, status);
				this->serv.addMasina(masinaAdd);
				//cout << "Masina a fost adaugata" << endl << endl;
			}
			
		}
		else if (optiune == 2)  //optiunea 2
		{
			this->serv.readMasini();
			cout << endl;
		}
		else if (optiune == 3)  //optiunea 3
		{
			int index;
			char* newPosesor = new char[50];
			char* newNrInmatriculare = new char[50];
			char* newStatus = new char[50];

			cout << endl << endl;
			this->serv.readMasini();
			cout << endl;

			cout << "Introduceti indexul masinii pe care doriti sa o actualizati: ";
			cin >> index;

			cout << "introduceti noul nume al posesorului: ";
			cin >> newPosesor;

			cout << "Introduceti noul numar de inmatriculare: ";
			cin >> newNrInmatriculare;

			cout << "Introduceti noul status: ";
			cin >> newStatus;
			Masina masinaUpdate = Masina(newPosesor, newNrInmatriculare, newStatus);
			this->serv.updateMasina(index, masinaUpdate);
			if (strcmp(newStatus,"ocupat")==0)
			{
				capacitateCurenta++;
			}
			cout << "Masina a fost actualizata" << endl << endl;
		}
		else if (optiune==4)  //optiunea 4
		{
			char* delPosesor = new char[50];
			char* delNrInmatriculare = new char[50];
			char* delStatus = new char[50];

			this->serv.readMasini();
			cout << endl;
			
			cout << "Introduceti datele masinii care urmeaza sa fie stearsa: " << endl;

			cout << "Numele posesorului: ";
			cin >> delPosesor;

			cout << "Numarul de inmatriculare: ";
			cin >> delNrInmatriculare;

			cout << "Statusul: ";
			cin >> delStatus;
			if (strcmp(delStatus,"ocupat")==0)
			{
				cout << "Masina nu poate fi stearsa" << endl;
			}
			else
			{
				Masina masinaDelete = Masina(delPosesor, delNrInmatriculare, delStatus);
				this->serv.deleteMasina(masinaDelete);
				cout << "Masina a fost stearsa" << endl << endl;
			}
			
			
		}
		else if (optiune==5) //optiunea 5
		{
			int index1 = 0;
			this->serv.readMasini();
			cout << endl;
			if (capacitateCurenta<capacitateMax)
			{
				cout << "Introduceti indexul masinii cu care doriti sa intrati: ";
				cin >> index1;
				if (strcmp(this->serv.getStatus(index1), "liber") == 0)
				{
					this->serv.updateStatus("ocupat", index1);
					capacitateCurenta++;
				}
				else
				{
					cout << "Nu se poate intra cu aceasta masina" << endl;
				}
			}
			else
			{
				cout << "Parcarea este plina" << endl << endl;
			}
			
		
		}
		else if (optiune==6)  //optiunea 6
		{
			int index2 = 0;
			this->serv.readMasini();
			cout << endl;
			cout << "Introduceti indexul masinii cu care doriti sa iesiti: ";
			cin >> index2;
			if (strcmp(this->serv.getStatus(index2), "ocupat") == 0)
			{
				this->serv.updateStatus("liber", index2);
				capacitateCurenta--;
			}
			else
			{
				cout << "Nu se poate iesi cu aceasta masina" << endl;
			}
		}
	}
}
