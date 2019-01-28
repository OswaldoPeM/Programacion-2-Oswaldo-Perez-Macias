#pragma once
#include<iostream>
#include<string>
using namespace std;
class Persona
{
public:
	void setName(string nombre);
	void setLName(string apellido);
	void setEMail(string eMail);
	void setBD(int fecha[3]);

	int* GetBD();
	string GetFName();
	string GetLName();
	string GetEMail();
	Persona();
	~Persona();
private:
	int _fecha[3];
	string _nombre = "", _apellido = "", _eMail = "";

};

