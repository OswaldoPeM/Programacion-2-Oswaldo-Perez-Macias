#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
class Persona
{
public:
	void setName(string nombre);
	void setLName(string apellido);
	void setEMail(string eMail);
	void setBD(int fecha[3]);
	int strToInt(string str);
	int GetBD(int x);
	string GetFName();
	string GetLName();
	string GetEMail();
	Persona();
	void constPersona(string LName, string FName, string EMail, string BD);
	~Persona();
private:
	int _fecha[3];
	string _nombre = "", _apellido = "", _eMail = "";

};

