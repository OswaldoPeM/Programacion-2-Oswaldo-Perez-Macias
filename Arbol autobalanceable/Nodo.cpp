#include "Nodo.h"

Nodo * Nodo::getDer()
{
	return _Der;
}

Nodo * Nodo::getIzq()
{
	return _Izq;
}

int Nodo::getBalance()
{
	return _balance;
}

void Nodo::modBalance(int x)
{
	_balance = x;
}

int Nodo::getDato()
{
	return _dato;
}

void Nodo::setDato(int x)
{
	_dato = x;
}



void Nodo::setDer(Nodo * der)
{
	_Der = der;
}

void Nodo::setIzq(Nodo * izq)
{
	if (izq != NULL) {
	_Izq = izq;
	}
}

Nodo::Nodo()
{
}

Nodo::Nodo(int x)
{
	_dato = x;
}


Nodo::~Nodo()
{
	if (_Izq != NULL) { delete _Izq; }
	if (_Der != NULL) { delete _Der; }
}
