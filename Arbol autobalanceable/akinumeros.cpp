#include "akinumeros.h"
//regresa la raiz
Nodo * Akinumero::getRaiz()
{
	return _raiz;
}
//Crea un nodo
Nodo * Akinumero::crearNodo(int x)
{
	Nodo* nodo = new Nodo(x);
	return nodo;
}
//aniade un numero, a la izquierda si es menor, a la derecha si es mayor, y si es igual no se agregara al arbol
void Akinumero::addNodo(Nodo * nodo,int valor)
{
	if (this != NULL) {
		if (_raiz != NULL) {
			if (nodo->getDato() == valor) {
				std::cout << "Valor ya existente\n"; 
				system("pause");
				return;
			}
			if (nodo->getDato() > valor) {
				if (nodo->getIzq() != NULL)addNodo(nodo->getIzq(), valor);
				else { nodo->setIzq(crearNodo(valor)); }
			}
			if (nodo->getDato() < valor) {
				if (nodo->getDer() != NULL)addNodo(nodo->getDer(), valor);
				else { nodo->setDer(crearNodo(valor)); }
			}
			return;
		}
		_raiz = crearNodo(valor);
	}
}
//sirve para saber el peso total del arbol y al mismo tiempo modifica el factor balance de los nodos
int Akinumero::peso(Nodo * nodo)
{
	int pesoDer = 0, pesoIzq = 0;
	if (nodo->getDer() == NULL && nodo->getIzq() == NULL) return 1;
	if (nodo->getIzq() != NULL) {
		pesoIzq = peso(nodo->getIzq());
	}
	if (nodo->getDer() != NULL) {
		pesoDer = peso(nodo->getDer());
	}
	nodo->modBalance(pesoDer - pesoIzq);
	if (nodo->getBalance() < -1) {// si el arbol esta mas cargado para la izquierda 
		if (nodo->getIzq()->getBalance() > 0) {// y el nodo hijo izquierdo tambien tiene mas peso a la derecha
			RDD(nodo);
		}
		else {// si el nodo hijo izquierdo tiene mas peso a la izquierda
			RSD(nodo);
		}
	}
	if (nodo->getBalance() > 1) {//si el arbol esta mas cargado a la derecha
		if (nodo->getDer()->getBalance() < 0) {// y el nodo derecho tambien tiene mas peso a la izquierda
			RDI(nodo);
		}
		else {// si el hijo teiem mas peso a la derecha
			RSI(nodo);
		}
	}
	int pesoT = (pesoDer < pesoIzq) ? pesoIzq : pesoDer;
	return pesoT + 1;

}
//rotacion simple a la derecha
void Akinumero::RSD(Nodo * nodo)
{
	Nodo G = *nodo;
	Nodo* R = G.getIzq();
	Nodo* F = R->getDer();
	Nodo* H = G.getDer();
	nodo->setIzq(nodo->getIzq()->getIzq());
	R->setIzq(F);
	R->setDer(H);
	nodo->setDer(R);
	nodo->setDato(R->getDato());
	R->setDato(G.getDato());
	G.setDer(NULL);
	G.setIzq(NULL);

}
//rotacion simple a la izquierda
void Akinumero::RSI(Nodo * nodo)
{
	Nodo G = *nodo;
	Nodo* R = G.getDer();
	Nodo* F = R->getIzq();
	Nodo* H = G.getIzq();
	nodo->setDer(nodo->getDer()->getDer());
	R->setDer(F);
	R->setIzq(H);
	nodo->setIzq(R);
	nodo->setDato(R->getDato());
	R->setDato(G.getDato());
	G.setDer(NULL);
	G.setIzq(NULL);
}
//rotacion doble a la derecha
void Akinumero::RDD(Nodo * nodo)
{
	Nodo G = *nodo;// esta variable es para no afectar la direccion y solo sacar los hijos necesarios.
	Nodo* R = G.getIzq();
	Nodo* H = G.getDer();
	Nodo* F = R->getDer();
	R->setDer(F->getIzq());
	F->setIzq(F->getDer());
	F->setDer(H);
	nodo->setDer(F);
	nodo->setDato(F->getDato());
	F->setDato(G.getDato());
	G.setDer(NULL);
	G.setIzq(NULL);
}

//rotacion doble a la izquierda
void Akinumero::RDI(Nodo * nodo)
{
	Nodo G = *nodo;
	Nodo* R = G.getDer();
	Nodo* H = G.getIzq();
	Nodo* F = R->getIzq();
	R->setIzq(F->getDer());
	F->setDer(F->getIzq());
	F->setIzq(H);
	nodo->setIzq(F);
	nodo->setDato(F->getDato());
	F->setDato(G.getDato());
	G.setDer(NULL);
	G.setIzq(NULL);
}
//imprime el arbol de manera horizontal arriba representa la izquierda y abajo la parte derecha
void Akinumero::print(Nodo * nodo,std::string x)
{
	if (nodo != NULL) {
		print(nodo->getIzq(), x + "   ");
		std::cout << x << nodo->getDato() << "\n";
		print(nodo->getDer(), x + "   ");
	}
}

Akinumero::Akinumero()
{
}

//antes de desaparecer crea una reaccion en cadena que destruye todo los nodos.
Akinumero::~Akinumero()
{
	delete _raiz;
}
