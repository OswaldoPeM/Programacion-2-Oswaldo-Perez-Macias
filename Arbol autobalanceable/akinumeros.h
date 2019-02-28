#pragma once
#include"Nodo.h"
class Akinumero
{
	Nodo* _raiz = NULL;
public:
	Nodo* getRaiz();
	Nodo* crearNodo(int x);
	void addNodo(Nodo* nodo, int valor); //agrega un entero
	int peso(Nodo* nodo);// la profundidad del arbol
	void RSD(Nodo* nodo);//rotacion simple a la derecha
	void RSI(Nodo* nodo);//rotacion simple a la izquierda
	void RDD(Nodo* nodo);//rotacion doble a la derecha
	void RDI(Nodo* nodo);//rotacion doble a la izquierda
	void print(Nodo* nodo,std::string x);//imprime la lista 
	Akinumero();
	~Akinumero();
};

