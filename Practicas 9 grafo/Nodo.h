#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
class Nodo
{
	float cord[2];
	int valor=0;
	char visitado = 'n';
	std::string etiqueta="";
public:
	char getVisit();// retorna el valor de visita
	void setCord(std::string x);
	void visit();// visita el nodo
	void rVisit();//resetea el valor de visita
	void setEti(std::string x);//asigna etiqueta
	void setVal(int x);//asigna valor
	std::string getEti();//regresa etiqueta
	int getVal();//regresa valor

	Nodo();
	~Nodo();
};

