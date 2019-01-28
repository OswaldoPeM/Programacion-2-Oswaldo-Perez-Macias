#include "Nodo.h"



Persona * Nodo::GetPersona()
{
	return _Person;
}

void Nodo::setNext(Nodo *ptrS)
{
	_Siguiente = ptrS;
}

void Nodo::setPrev(Nodo * ptrA)
{
	_Anterior = ptrA;
}

void Nodo::setPerson(Persona persona)
{
	*_Person = persona;
}

Nodo * Nodo::GetSiguiente()
{
	return _Siguiente;
}

Nodo * Nodo::GetAnterior()
{
	return _Anterior;
}

Nodo::Nodo()
{
}


Nodo::~Nodo()
{
	if (GetSiguiente() != NULL)
	{
		delete GetSiguiente();
	}
}
