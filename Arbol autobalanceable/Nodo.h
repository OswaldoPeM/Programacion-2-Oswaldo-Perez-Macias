#pragma once
#include <iostream>
#include<fstream>
#include<string>




class Nodo
{
	Nodo* _Izq=NULL;
	Nodo* _Der=NULL;
	int _dato = 0;
	int _balance = 0;
public:
	Nodo* getDer();//retorna nodo der
	Nodo* getIzq();//retorna nodo izq
	int getBalance();//retorna balance
	void modBalance(int x);// modifica el balance del nodo
	int getDato();//retorna valor de dato
	void setDato(int x);//asigna valor al dato
	void setDer(Nodo* der);//asigna nodo derecho
	void setIzq(Nodo* izq);//asigna nodo derecho
	Nodo();
	Nodo(int x);//crea nodo con un valor de dato
	~Nodo();
};

