#pragma once
#include"Nodo.h"
class Lista
{
public:
	Nodo* GetRaiz();
	void clear();
	void push_back(Nodo* nodo);
	void push_front(Nodo* nodo);
	void insert_at(Nodo* nodo,int lugar);
	void delete_at(int lugar);
	void _deleteByName(string nombre,string apellido);
	


	Lista();
	~Lista();
private:
	bool isThis(Nodo* nodo);
	Nodo* _Raiz = NULL;
	Nodo* _Fin = NULL;
	char tipo = 'j';// 's' para lista simple, 'd' para doble, 'S' simple anillada, 'D' para doble anillada
};

