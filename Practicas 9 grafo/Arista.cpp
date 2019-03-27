#include "Arista.h"



Nodo * Arista::getLink(int x)
{
	return link[x];
}

void Arista::setLink(Nodo* x, Nodo* y)
{
	link[0] = x;
	link[1] = y;
}

int Arista::getPeso()
{
	return peso;
}

Arista::Arista()
{
}

Arista::Arista(Nodo *x, Nodo * y)
{
	link[0] = x;
	link[1] = y;
}

Arista::Arista(Nodo * x, Nodo * y, std::string val)
{
	link[0] = x;
	link[1] = y;
	int costo = 0;
	for (int i = 0; i < val.size(); i++)
	{
		costo = ((costo << 1) + (costo << 3));
		costo = costo + (val[i] - '0');
	}
	peso = costo;
}


Arista::~Arista()
{
}
