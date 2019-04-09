#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cmath>
class Nodos
{
public:
	//asigna etiqueta
	virtual void setEti(std::string nombre);
	//asigna costo
	virtual void setCosto(std::string peso);
	//asigna latitud
	virtual void setCordX(std::string x);
	//asigna longitud
	virtual void setCordY(std::string y);
	virtual void setCords(std::string x,std::string y);//asigna las cordenadas
	virtual void setCodigo(std::string codigo);//asigna codigo
	virtual std::string getEti();//retorna la etiqueta
	virtual float getCosto();//retorna el costo
	virtual float getCord(char x);//retorna la cordenada, dependiendo si se quiere en x o en y;
	virtual std::string getCodi();//retorna el codigo
	Nodos();
	~Nodos();
protected:
	std::string _eti = "";//etiqueta
	std::string _codigo = "";//codigo
	float _costo = 1;
	//latitud x, longitud y
	float _cord[2];
};

class NodoViajero :public Nodos
{
	Nodos *_actual;//nodo actual
	NodoViajero* _anterior = nullptr;//NodoViajer anterior
	int pasos = 0;
	float _peligroT = 0;//peligro o precio
	float _distanciaT = 0;// distanciadesde la partida al actual, o desde el actual al final
	float _disRecorrida = 0;// distancia recorrida
	void setDisAFin(Nodos* objetivo);//asigna Distancia al objetivo
public:
	void setActual(Nodos *actual);//asigna el nodo actual
	void setPasos();
	void setAnterior(NodoViajero* anterior);//asigna el nodoViajero anterior
	void setPeligroT(float &peligro);//asigna el peligro o el precio de llegar a cierto nodo
	void setDistanciaT(float &distancia);//asigna la distancia entre nodo y nodo
	void setCosto(int &facP, int &facD);//aigna el costo segun las exigencias de la persona
	void setCosto(float costo);//asigna el peligro o precio para llegar a cierto nodo
	void setDisRec(float recorrida);//similar a distanciaT pero en todos los casos hara referencia a la distancia recorrida y no a la distanciarecorrida o distancia a el objetivo
	Nodos *getActual();//retorna el nodo actual
	NodoViajero* getAnterior();//retrona el nodo anterior
	float getPeliT();//regresa el peligro o precio acumulado
	int getPasos();
	float getDistanciaT();//regresa la distanciadesde la partida al actual, o desde el actual al final segun el caso
	float getDisRec();//retorna la distancia recorrida
	//Contructores
	NodoViajero(Nodos *actual);
	NodoViajero(Nodos *actual, float costo);
	NodoViajero(Nodos* actual, Nodos* destino, NodoViajero* anterior, float peligro, int &facP, int &facD);
	NodoViajero(Nodos* actual, Nodos* destino, NodoViajero* anterior, float distancia, float peligro, int &facP, int &facD);
	NodoViajero(Nodos *actual, NodoViajero* anterior, float peligro, float distancia, int &facP, int &facD);
};


