#include "Nodo.h"

Nodo * Nodo::getDer()
{
	return _Der;
}

Nodo * Nodo::getIzq()
{
	return _Izq;
}

std::string Nodo::getA1()
{
	return A1;
}

std::string Nodo::getA2()
{
	return A2;
}

void Nodo::setA1(std::string a1)
{
	A1 = a1;
}

void Nodo::setA2(std::string a2)
{
	A2 = a2;
}

void Nodo::setDer(Nodo * der)
{
	_Der = der;
}

void Nodo::setIzq(Nodo * izq)
{
	_Izq = izq;
}

Nodo::Nodo()
{
}


Nodo::~Nodo()
{
	if (_Der != NULL && _Izq != NULL) {
		if (_Izq != NULL) { delete _Izq; }
		if (_Der != NULL) { delete _Der; }
	}
}
