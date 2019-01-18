#pragma once
#include<iostream>
#include<string>
using namespace std;
class Persona
{
public:
	void giveName(string nombre);
	void giveLName(string apellido);
	void giveEMail(string eMail);
	void giveBD(int fecha[]);
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

