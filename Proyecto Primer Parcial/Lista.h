#pragma once
#include"Nodo.h"
class Lista
{
public:
	void push_back(Nodo* nodo);
	void push_front(Nodo* nodo);
	Lista();
	~Lista();
private:
	Nodo* _Raiz = NULL;
	char tipo = 'j';// 's' para lista simple, 'd' para doble, 'S' simple anillada, 'D' para doble anillada

};

