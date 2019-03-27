#pragma once
#include"Nodo.h"
class Arista
{
	Nodo *link[2];
	int peso = 1;

public:
	Nodo* getLink(int x);//regresa direccion arreglo de conexiones, si se introduce 0, retorna el vertice de origen, si 1 el de destino.
	void setLink(Nodo* x,Nodo* y);// crea arreglo de conexiones.
	int getPeso();//retorna el costo de ir por esta arista
	Arista();
	Arista(Nodo* x, Nodo* y);// se crea un arreglo con los dos nodos.
	Arista(Nodo*x, Nodo*y, std::string val);
	~Arista();
};

