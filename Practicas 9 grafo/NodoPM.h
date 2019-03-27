#pragma once
#include "Arista.h"
class NodoPM
{
	Nodo* _actual;
	float _costo=0;
	NodoPM* _anterior = NULL;
public:
	void setActual(Nodo* actual);
	void setCosto(float x);
	void setAnterior(NodoPM* anterior);;
	Nodo* getAct();
	float getCost();
	NodoPM* getAnt();
	NodoPM();
	NodoPM(Nodo*actual, float costo);
	NodoPM(Nodo*actual, NodoPM*anterior,float costo);
	~NodoPM();
};

