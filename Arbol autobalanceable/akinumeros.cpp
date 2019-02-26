#include "akinumeros.h"

Nodo * Akinumero::getRaiz()
{
	return _raiz;
}

Nodo * Akinumero::crearNodo(int x)
{
	Nodo* nodo = new Nodo(x);
	return nodo;
}

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


int Akinumero::peso(Nodo * nodo)
{
	int pesoDer = 0, pesoIzq = 0;
	if (nodo->getDer() == NULL && nodo->getIzq() == NULL) return 1;
	if (nodo->getIzq() != NULL) {
		pesoIzq = peso(nodo->getIzq());
	}
	if(nodo->getDer()!=NULL){
		pesoDer = peso(nodo->getDer());

	}
	nodo->modBalance(pesoDer-pesoIzq);
	if (nodo->getBalance() < -1) {
		if (nodo->getIzq()->getBalance() > 0) {
			RDD(nodo);
		}
		else {
			RSD(nodo);
		}
	}
	if (nodo->getBalance() > 1) {
		if (nodo->getDer()->getBalance() < 0) {
			RDI(nodo);
		}
		else {
			RSI(nodo);
		}
		
	}
	int pesoT = (pesoDer < pesoIzq) ? pesoIzq : pesoDer;
	return pesoT + 1;
}

void Akinumero::RSD(Nodo * nodo)
{
	Nodo* p = nodo->getIzq();
	Nodo* q = p->getIzq();
	Nodo* b = q->getDer();
	p->setIzq(b);
	q->setDer(p);
	if (_raiz == nodo) _raiz=q;
	p->modBalance(0);
	if (q->getIzq() != NULL)q->getIzq()->modBalance(0);
}

void Akinumero::RSI(Nodo * nodo)
{
	Nodo* temp = nodo->getDer();
	nodo->setDer(temp->getIzq());
	if (_raiz == nodo) _raiz = temp;
	nodo = temp;
}

void Akinumero::RDD(Nodo * nodo)
{
	Nodo* P = nodo;
	Nodo* Q = P->getIzq();
	Nodo* R = Q->getDer();
	Nodo* B = R->getIzq();
	Nodo* C = R->getDer();

	 Q->setDer(B);
   P->setIzq(C);
   R->setIzq(Q);
   R->setDer(P);
   switch (R->getBalance()) {
   case -1: Q->modBalance(0); P->modBalance(1); break;
   case 0:  Q->modBalance(0); P->modBalance(0); break;
   case 1:  Q->modBalance(1); P->modBalance(0); break;
   }
   R->modBalance(0);
	/*Nodo* temp = nodo->getDer();
	Nodo* temp2 = nodo->getDer()->getIzq();
	temp->setIzq(temp2->getDer());
	temp2->setDer(temp);
	nodo->setDer(temp2->getIzq());
	temp2->setIzq(nodo);
	if (_raiz == nodo) _raiz = temp;
	nodo = temp2;
*/
}

void Akinumero::RDI(Nodo * nodo)
{
	Nodo* temp = nodo->getIzq();
	Nodo* temp2 = nodo->getIzq()->getDer();
	temp->setDer(temp2->getIzq());
	temp2->setIzq(temp);
	nodo->setIzq(temp2->getDer());
	temp2->setDer(nodo);
	if (_raiz == nodo) _raiz = temp;
	nodo = temp2;
}

void Akinumero::print(Nodo * nodo,std::string x)
{
	if (nodo != NULL) {
		print(nodo->getIzq(), x + "   ");
		std::cout << x << nodo->getDato() << " " << nodo->getBalance() << "\n";
		print(nodo->getDer(), x + "   ");
	}
}

Akinumero::Akinumero()
{
}


Akinumero::~Akinumero()
{
	delete _raiz;
}
