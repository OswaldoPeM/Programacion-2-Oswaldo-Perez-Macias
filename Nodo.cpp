#include "Nodo.h"



Persona  Nodo::GetPersona()
{
	return _Persona;
}

void Nodo::setNext(Nodo *ptrS)
{
	_Next = ptrS;
}

void Nodo::setPrev(Nodo * ptrA)
{
	_Prev = ptrA;
}

void Nodo::setPersona(Persona persona)
{
	_Persona = persona;
}

Nodo * Nodo::GetNext()
{
	return _Next;
}

Nodo * Nodo::GetPrev()
{
	return _Prev;
}

Nodo::Nodo()
{
}


Nodo::~Nodo()
{
	if (GetNext() != NULL)
	{
		delete GetNext();
	}
}
