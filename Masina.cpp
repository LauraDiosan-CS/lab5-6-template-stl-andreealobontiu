#include "Masina.h"
#include <string.h>
#include <stdlib.h>

//default constructor; all atributes are intialized with 0/null
Masina::Masina()
{
	this->posesor = NULL;
	this->nrInmatriculare = NULL;
	this->status = NULL;
}

//parameter constructor
//in: a path, number of branches, number of commits
//out: an instance of Masina class which has those attributes
Masina::Masina(const char * p, const char* nr, const char* s)
{
	this->posesor = new char[strlen(p) + 1];
	strcpy_s(this->posesor, strlen(p) + 1, p);

	this->nrInmatriculare = new char[strlen(nr) + 1];
	strcpy_s(this->nrInmatriculare, strlen(nr) + 1, nr);

	this->status = new char[strlen(s) + 1];
	strcpy_s(this->status, strlen(s) + 1, s);
}

//copy constructor
//in: an instance of masina
//out: a new instance of masina, with the same attribute values as the first one
Masina::Masina(const Masina & m)
{
	this->posesor = new char[strlen(m.posesor) + 1];
	strcpy_s(this->posesor, strlen(m.posesor) + 1, m.posesor);

	this->nrInmatriculare = new char[strlen(m.nrInmatriculare) + 1];
	strcpy_s(this->nrInmatriculare, strlen(m.nrInmatriculare) + 1, m.nrInmatriculare);
	
	this->status = new char[strlen(m.status) + 1];
	strcpy_s(this->status, strlen(m.status) + 1, m.status);
}

Masina::~Masina()
{
	if(this->nrInmatriculare)
	{
		delete[] this->nrInmatriculare;
		this->nrInmatriculare = NULL;
	}

	if (this->posesor)
	{
		delete[] this->posesor;
		this->posesor = NULL;
	}

	if (this->status)
	{
		delete[] this->status;
		this->status = NULL;
	}
}

char * Masina::getNumePosesor()
{
	return this->posesor;
}

void Masina::setNumePosesr(const char * n)
{
	if (this->posesor) {
		delete[] this->posesor;
	}
	this->posesor = new char[strlen(n) + 1];

	strcpy_s(this->posesor, strlen(n) + 1, n);
}

char * Masina::getNrInmatriculare()
{
	return this->nrInmatriculare;
}

void Masina::setNrInmatriculare(const char * n)
{
	if (this->nrInmatriculare) {
		delete[] this->nrInmatriculare;
	}
	this->nrInmatriculare = new char[strlen(n) + 1];

	strcpy_s(this->nrInmatriculare, strlen(n) + 1, n);
}

char * Masina::getStatus()
{
	return this->status;
}

void Masina::setStatus(const char * s)
{
	if (this->status) {
		delete[] this->status;
	}
	this->status = new char[strlen(s) + 1];

	strcpy_s(this->status, strlen(s) + 1, s);
}

Masina & Masina::operator=(const Masina & m)
{
	if (this != &m)
	{
		this->setNumePosesr(m.posesor);
		this->setNrInmatriculare(m.nrInmatriculare);
		this->setStatus(m.status);
	}
	return *this;
}

char * Masina::toString()
{
	if (this->posesor != NULL) {
		int noChars = strlen(this->posesor)+strlen(this->nrInmatriculare)+strlen(this->status) + 1 + 5 + 5 + 2;
		char* s = new char[noChars];
		
		strcpy_s(s, noChars, this->posesor);
		strcat_s(s, noChars, " ; ");

		strcpy_s(s, noChars, this->nrInmatriculare);
		strcat_s(s, noChars, " ; ");

		strcpy_s(s, noChars, this->status);
		strcat_s(s, noChars, " ; ");


		return s;
	}
	else
		return NULL;
}

bool Masina::compare(Masina & m)
{
	return (strcmp(this->posesor, m.posesor) == 0) && (strcmp(this->nrInmatriculare,m.nrInmatriculare)==0) && (strcmp(this->status, m.status) == 0);
}



