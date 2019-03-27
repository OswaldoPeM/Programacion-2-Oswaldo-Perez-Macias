#include "NodoPM.h"


void NodoPM::setActual(Nodo * actual)
{
	_actual = actual;
}

void NodoPM::setCosto(float x)
{
	_costo += x;
}

void NodoPM::setAnterior(NodoPM * anterior)
{
	_anterior = anterior;
}

Nodo * NodoPM::getAct()
{
	return _actual;
}

float NodoPM::getCost()
{
	return _costo;
}

NodoPM * NodoPM::getAnt()
{
	return _anterior;
}

NodoPM::NodoPM()
{
}

NodoPM::NodoPM(Nodo * actual, float costo)
{
	_actual = actual;
	_costo += costo;
}

NodoPM::NodoPM(Nodo * actual, NodoPM * anterior,float costo)
{
	_actual = actual;
	_anterior = anterior;
	if(anterior!= NULL) _costo = anterior->getCost() + costo;
}


NodoPM::~NodoPM()
{
}
