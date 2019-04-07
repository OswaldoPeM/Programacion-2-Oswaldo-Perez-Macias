#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
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
	std::string _eti = "";
	std::string _codigo = "";
	float _costo = 1;
	//latitud x, longitud y
	float _cord[2];
};

class NodoViajero:public Nodos
{
	Nodos *_actual;
	NodoViajero* _anterior = nullptr;
	float _peligroT = 0;
	float _distanciaT = 0;
	void setDisTCord(Nodos* objetivo);
public:
	void setActual(Nodos *actual);
	void setAnterior(NodoViajero* anterior);
	void setPeligroT(float &peligro);
	void setDistanciaT(float &distancia);
	void setCosto(int &facP,int &facD);
	void setCosto(float costo);
	Nodos *getActual();
	NodoViajero* getAnterior();
	float getPeliT();
	float getDistanciaT();
	NodoViajero(Nodos *actual);
	NodoViajero(Nodos *actual, float costo);
	NodoViajero(Nodos* actual,Nodos* destino, NodoViajero* anterior, float peligro, int &facP, int &facD);
	NodoViajero(Nodos *actual ,NodoViajero* anterior,float peligro,float distancia, int &facP,int &facD);
};

