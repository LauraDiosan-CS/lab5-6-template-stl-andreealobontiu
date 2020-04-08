#pragma once
#include <iostream>

using namespace std;


class Masina
{
private:
	char* posesor;
	char* nrInmatriculare;
	char* status;
public:
	Masina();
	Masina(const char* p, const char* nr, const char* s);
	Masina(const Masina &m);
	~Masina();
	char* getNumePosesor();
	void setNumePosesr(const char* n);
	char* getNrInmatriculare();
	void setNrInmatriculare(const char* n);
	char* getStatus();
	void setStatus(const char* s);

	Masina& operator=(const Masina& m);
	bool operator==(const Masina& m);
	friend ostream& operator<<(ostream& os, const Masina& m);
	
	char* toString();
	bool compare(Masina &m);
};

