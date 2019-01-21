#pragma once
#include"Persona.h"
class Nodo
{
private:
	Persona _Persona;
	Nodo* _Siguiente = NULL;
	Nodo* _Anterior = NULL;
public:
	Persona GetPersona();
	void GiveSiguiente(Nodo *ptrS);
	void GiveAnteriro(Nodo *ptrA);
	Nodo* GetSiguiente();
	Nodo* GetAnterior();
	Nodo();
	~Nodo();
};

