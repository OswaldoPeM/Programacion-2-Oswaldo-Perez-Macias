#include "Persona.h"



string Persona::GetFName()
{
	return _nombre;
}

void Persona::giveName(string nombre)
{
	_nombre = nombre;
}

string Persona::GetLName()
{
	return _apellido;
}

void Persona::giveLName(string apellido)
{
	_apellido = apellido;
}

string Persona::GetEMail()
{
	return _eMail;
}

void Persona::giveEMail(string eMail)
{
	_eMail = eMail;
}

void Persona::giveBD(int fecha[])
{
	_fecha[0] = fecha[0];
	_fecha[1] = fecha[1];
	_fecha[2] = fecha[2];
}

int* Persona::GetBD()
{
	return _fecha;
}

Persona::Persona()
{
}


Persona::~Persona()
{
}
