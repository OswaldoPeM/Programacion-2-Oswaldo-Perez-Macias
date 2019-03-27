#pragma once
#include"NodoPM.h"

class Grafo
{
	Nodo* nodos;
	Arista*  aristas;
	int nodoSize = 0;
	int aristaSize = 0;
	void sortVec(std::vector<NodoPM*>* vector, int &derecha, int &izquierda);
	void printPM(NodoPM* camino);
	bool wasVisited();
public:
	Nodo* getNod();
	Arista *getAri();
	std::fstream* getTxt();
	void setNod();//asigna arreglo de nodos
	int tamLink(std::fstream *mat);//regresa el tamanio de el arrego de aristas
	void setAri(std::fstream* mat);//asigna aristas
	void print();//imprime conexiones las aristas "Origen Destino"
	bool scope(Nodo* x,Nodo*y);//hace recorrido de profundidad.
	void resetV();// resetea valor de visitado
	void profun();//busqueda de profundidad
	void ampli();//busqueda de amplitud
	void firstB(std::string inicio, std::string objetivo,float factpeligro);//busqueda primero el mejor.
	void dijkstra(std::string raiz, int factPeligro);
	
	Grafo();
	Grafo(int x);
	~Grafo();
};

