#pragma once
#include"Nodo.h"
class Akinumero
{
	Nodo* _raiz = NULL;
	int altura = 0;
public:
	Nodo* getRaiz();
	Nodo* crearNodo(int x);
	void addNodo(Nodo* nodo,int valor);
	int peso(Nodo* nodo);
	void RSD(Nodo* nodo);
	void RSI(Nodo* nodo);
	void RDD(Nodo* nodo);
	void RDI(Nodo* nodo);
	void print(Nodo* nodo,std::string x);
	Akinumero();
	~Akinumero();
};

