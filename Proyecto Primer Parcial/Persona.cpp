#include "Persona.h"



string Persona::GetFName()
{
	return _nombre;
}

void Persona::setName(string nombre)
{
	_nombre = nombre;
}

string Persona::GetLName()
{
	return _apellido;
}

void Persona::setLName(string apellido)
{
	_apellido = apellido;
}

string Persona::GetEMail()
{
	return _eMail;
}

void Persona::setEMail(string eMail)
{
	_eMail = eMail;
}

void Persona::setBD(int fecha[3])
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
