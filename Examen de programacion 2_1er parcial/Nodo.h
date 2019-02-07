#pragma once
#include"Persona.h"
class Nodo
{
private:
	Nodo* _Next = NULL;//apunta al siguiente nodo
	Nodo* _Prev = NULL;// apunta al nodo anterior
	Persona _Persona;// La persona
public:
	void setNext(Nodo *ptrS);
	void setPrev(Nodo *ptrA);
	void setPersona(Persona persona);
	Persona GetPersona();//Almacena a la persona
	Nodo* GetNext();//regresa el puntero siguiente
	Nodo* GetPrev();//regresa el puntero anterior
	Nodo();
	~Nodo();
};

