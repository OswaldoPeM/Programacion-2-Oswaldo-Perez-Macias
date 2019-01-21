#include "Nodo.h"



Persona Nodo::GetPersona()
{
	return _Persona;
}

void Nodo::GiveSiguiente(Nodo *ptrS)
{
	_Siguiente = ptrS;
}

void Nodo::GiveAnteriro(Nodo * ptrA)
{
	_Anterior = ptrA;
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
}
