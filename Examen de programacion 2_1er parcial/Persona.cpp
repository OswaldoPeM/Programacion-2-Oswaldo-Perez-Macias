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

int Persona::strToInt(string str)
{
	int i;
	istringstream(str) >> i;
	return i;
}

int Persona::GetBD(int x)
{
	switch (x)
	{
	case 0:
		return _fecha[x];
		break;
	case 1:
		return _fecha[x];
		break;
	case 2:
		return _fecha[x];
		break;
	default:
		break;
	}
	
}

Persona::Persona()
{
}

void Persona::constPersona(string LName, string FName, string EMail, string BD)
{
	string buffer;
	int x = 0, i = 0;
	_nombre = FName;
	_apellido = LName;
	_eMail = EMail;
	stringstream stream(BD);
	while (getline(stream, buffer, '/'))
	{
		_fecha[i] = strToInt(buffer);
		i++;
	}
	x = _fecha[1];
	_fecha[1] = _fecha[0];
	_fecha[0] = x;
	return;
}


Persona::~Persona()
{
}
