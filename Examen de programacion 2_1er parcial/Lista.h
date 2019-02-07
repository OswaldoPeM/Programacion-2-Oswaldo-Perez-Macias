#pragma once
#include"Nodo.h"
class Lista
{
public:
	Nodo* GetRaiz();
	Nodo* GetFin();
	int size();//imprime el tamanio de la lista
	void clear();//borra la lista
	void print();// imprime la lista
	bool isThis(Nodo* nodo);// pregunta al usuario si es esta la persona que buscas
	virtual bool FindByName(std::string nombre, std::string apellido);//imprime el lugar de la lista buscando por nombre y apellido
	virtual void sortByName() = 0;//Organiza por Nombre 
	virtual void sortByBrithDay() = 0;//Organiza la lista por Fecha de nacimiento
	//virtual void sortByEMail() = 0;//Organiza por  EMail
	virtual void push_back(Nodo* nodo) = 0;// manda a el ultimo lugar de la lista un nodo
	virtual void push_front(Nodo* nodo) = 0;//manda hasta el frente a un nodo
	virtual void insert_at(Nodo* nodo, int lugar) = 0;//inserta en un lugar el nodo
	virtual void delete_at(int lugar)=0;//borra de un lugar un nodo
	virtual void delete_last() = 0;// borra el ultimo nodo de la lista
	virtual void delete_first() = 0;//borra el primer nodo de la lista
	virtual Nodo* pop_back() = 0; // te regresa el ultimo nodo
	virtual Nodo* pop_front() = 0;// te regresa el nodo primero
	Lista();
	~Lista();
protected:
	Nodo* _Raiz = NULL;
	Nodo* _Fin = NULL;
};

class Simple : public Lista {\
public:
	void push_back(Nodo* nodo);
	void push_front(Nodo* nodo);
	void insert_at(Nodo* nodo, int lugar);
	void delete_at(int lugar);
	void delete_last();
	void delete_first();
	void sortByName();
	void sortByBrithDay();
	//void sortByEMail();
	Nodo* pop_back();
	Nodo* pop_front();
};
class Doble : public Lista {
public:
	 void push_back(Nodo* nodo);
	 void push_front(Nodo* nodo);
	 void insert_at(Nodo* nodo, int lugar);
	 void delete_at(int lugar);
	 void delete_last();
	 void delete_first();
	 void sortByName();
	 void quickSort_byName(Nodo* derecha,Nodo* izquierda);
	 Nodo* _quickSort_byName(Nodo* derecha, Nodo* izquierda);
	 void sortByBrithDay();
	 void quickSort_byBrithDay(Nodo* derecha, Nodo* izquierda);
	 Nodo* _quickSort_byBrithDay(Nodo* derecha, Nodo* izquierda);
	 Nodo* pop_back();
	 Nodo* pop_front();
};
class RSimple : public Lista {
public:
	void push_back(Nodo* nodo);
	void push_front(Nodo* nodo);
	void insert_at(Nodo* nodo, int lugar);
	void delete_at(int lugar);
	void delete_last();
	void delete_first();
	void sortByName();
	void sortByBrithDay();
	Nodo* pop_back();
	Nodo* pop_front();
};
class RDoble : public Lista {
public:
	void push_back(Nodo* nodo);
	void push_front(Nodo* nodo);
	void insert_at(Nodo* nodo, int lugar);
	void delete_at(int lugar);
	void delete_last();
	void delete_first();
	void sortByName();
	void quickSort_byName(Nodo* derecha, Nodo* izquierda);
	Nodo* _quickSort_byName(Nodo* derecha, Nodo* izquierda);
	void sortByBrithDay();
	void quickSort_byBrithDay(Nodo* derecha, Nodo* izquierda);
	Nodo* _quickSort_byBrithDay(Nodo* derecha, Nodo* izquierda);
	Nodo* pop_back();
	Nodo* pop_front();
};