#include "Grafo.h"
int main() {
	Grafo *grafo = new Grafo;
	grafo->setNod();
	grafo->print();
	grafo->scope(grafo->getNod(),grafo->getNod());
	std::cout << std::endl;
	grafo->profun();
	std::cout << std::endl;
	grafo->ampli();
	grafo->firstB("F","C", 1);
	delete grafo;
	system("pause");
	return 0;
}