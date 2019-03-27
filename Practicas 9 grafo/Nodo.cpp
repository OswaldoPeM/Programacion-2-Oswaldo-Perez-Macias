#include "Nodo.h"



char Nodo::getVisit()
{
	return visitado;
}

void Nodo::setCord(std::string x)
{
	float j = 0;
	int i = 0,ceros=0;
	char decimal = 'a';
	for (int z = 0; z < x.size(); z++)
	{
		if (x[z] == ':') {
			while(ceros!=0)
			{
				j = j * .1;
				ceros--;
			}
			cord[0] = i + j;
			i = 0;
			j = 0;
			decimal = 'c';
			continue;
		}
		if (x[z] == '.') {
			decimal++;
			ceros = 0;
			continue;
		}
		if (decimal == 'b' | decimal == 'd') {
			j = j * 10;
			j = j + (x[z] - '0');
			ceros++;
		}
		else {
			i = ((i << 1) + (i << 3));
			i = i + ( x[z] - '0');
		}	
	}
	while (j > 1)
	{
		j = j * .1;
	}
	cord[1] = i + j;
}

void Nodo::visit()
{
	visitado = 's';
}

void Nodo::rVisit()
{
	visitado = 'n';
}

void Nodo::setEti(std::string x)
{
	etiqueta = x;
}

void Nodo::setVal(int x)
{
	valor = x;
}

std::string Nodo::getEti()
{
	return etiqueta;
}

int Nodo::getVal()
{
	return valor;
}

Nodo::Nodo()
{
}


Nodo::~Nodo()
{
}
