#pragma once
#include"Nodos.h"
class Arista
{
	Nodos* _origen, *_destino;
	float _distancia=1;
public:
	void setOr(Nodos* ori);//asigna el nodo origen
	void setDe(Nodos* des);//asigna el nodo destino
	void setDi(float dis);//asigna la distancia
	//asigna distancia con cordenadas
	void setDisCord();
	Nodos* getOr();//regresa el nodo origen
	Nodos* getDe();//regresa el nodo destino
	float getDi();//regresa distancia
	Arista();
	Arista(Nodos* ori, Nodos* des);
	Arista(Nodos* ori, Nodos* des, float dis);
	Arista(Nodos* ori, Nodos* des,std::string dis);
	~Arista();
};

