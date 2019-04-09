#pragma once
#include"Arista.h"
class Grafo
{
protected:
	Nodos* _nodos=nullptr;
	Arista* _arista=nullptr;
	int _nodoSize = 0;
	int _aristaSize = 0;

	void matCordCSV(std::string matriz);//crea grafo a partir de un archivo .CSV
	void matCordS(std::string &matriz);//crea grafos a partir de una archivo .TXT unicamente con cordenadas
	void matAdy(std::string &matriz);//crea grafo de una matriz de adyacencia
	void imprimirCamino(NodoViajero *camino);//imprime el camino que ha hecho el nodo viajero hasta llegar hasta el final
	void sortVec(std::vector<NodoViajero*>* lista, int der, int izq);//hace un quicksort de la lista de NodosViajeros
	void imprimirNodoViajero(NodoViajero* nodoViajero);//imprime el nodo viajero

public:
	Nodos* getNodos();//retorna _nodos
	Arista* getArista();//retorna _arista
	int getNodoSize();//retorna el tamanio de la lista de nodos
	int getAristaSize();//retorna el tamanio de la lista de aristas
	bool interprete(std::string &matriz);//lee el archivo de texto y discrimina que algoritmo lo resolvera
	void matCordCons(std::string &matriz);//interpreta que timpo de matriz de cordenadas es
	void profund(std::string &inicio, std::string &fin);//hace una busqueda de profundidad
	void amplitud(std::string &inicio, std::string &fin);//hace una busqueda de amplitud
	virtual void primeroMejor(std::string &inicio,std::string &objetivo,int &facP,int &facD);//primero el mejor sin cordenadas
	virtual void dijkstra(std::string &inicio, int &facP, int &facD);//
	virtual void AStar(std::string &inicio,std::string &objetivo, int &facP, int &facD);
	
	Grafo();
	~Grafo();
};

class GrafoCord :public Grafo {
public:
	void AStar(std::string &inicio, std::string &objetivo, int &facP, int &facD);
	GrafoCord(std::string &nombre);
};

