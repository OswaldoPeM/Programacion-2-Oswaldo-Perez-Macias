#pragma once
#include <iostream>
#include<string>
#include<fstream>




class Nodo
{
	Nodo* _Izq=NULL;
	Nodo* _Der=NULL;
	std::string A1 = "";
	std::string A2 = "fin";
public:
	Nodo* getDer();//retorna nodo der
	Nodo* getIzq();//retorna nodo izq
	std::string getA1();//retorna string A1
	std::string getA2();//retorna strin A2
	void setA1(std::string a1);//asigna string a A1
	void setA2(std::string a2);//asigna string a A2
	void setDer(Nodo* der);//asigna nodo derecho
	void setIzq(Nodo* izq);//asigna nodo derecho
	Nodo();
	~Nodo();
};

