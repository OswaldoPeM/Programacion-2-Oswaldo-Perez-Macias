#pragma once
#include"Arista.h"
class Grafo
{
protected:
	Nodos* _nodos=nullptr;
	Arista* _arista=nullptr;
	int _nodoSize = 0;
	int _aristaSize = 0;

	void matCordCSV(std::string matriz);
	void matCordS(std::string &matriz);
	void matAdy(std::string &matriz);
	void imprimirCamino(NodoViajero *camino);
	void sortVec(std::vector<NodoViajero*>* lista, int der, int izq);


public:
	Nodos* getNodos();
	Arista* getArista();
	int getNodoSize();
	int getAristaSize();
	bool interprete(std::string &matriz);
	void matCordCons(std::string &matriz);
	void profund(std::string &inicio);
	void amplitud(std::string &inicio);
	virtual void primeroMejor(std::string &inicio,std::string &objetivo,int &facP,int &facD);//primero el mejor sin cordenadas
	virtual void dijkstra(std::string &inicio, int &facP, int &facD);
	virtual void AStar(std::string &inicio,std::string &objetivo, int &facP, int &facD);
	
	Grafo();
	~Grafo();
};

class GrafoCord :public Grafo {
public:
	//void primeroMejor();
	//void dijkstra();
	void AStar(std::string &inicio, std::string &objetivo, int &facP, int &facD);
	GrafoCord(std::string &nombre);
	//GrafoCord(Grafo& grafo);
};

