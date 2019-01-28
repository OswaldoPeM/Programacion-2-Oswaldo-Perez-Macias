#pragma once
#include"Persona.h"
class Nodo
{
private:
	Nodo* _Siguiente = NULL;
	Nodo* _Anterior = NULL;
	Persona *_Person;
public:
	void setNext(Nodo *ptrS);
	void setPrev(Nodo *ptrA);
	void setPerson(Persona persona);
	Persona* GetPersona();
	Nodo* GetSiguiente();
	Nodo* GetAnterior();
	Nodo();
	~Nodo();
};

