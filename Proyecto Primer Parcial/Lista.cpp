#include "Lista.h"



void Lista::push_back(Nodo * nodo)
{
	Nodo* temp1=_Raiz, *temp2;
	switch (tipo)
	{
	case 's':
		while (temp1->GetSiguiente() != NULL)
		{
			temp2=temp1->GetSiguiente;
			temp1->GiveSiguiente(temp1->GetSiguiente);
		}
		temp2->GiveSiguiente(nodo);
		nodo->GiveSiguiente(temp1);
		break;
	case'S':// siendo un anillo, regresa un paso al "ultimo"
		temp2 = temp1->GetAnterior();
		temp2->GiveSiguiente(nodo);
		nodo->GiveSiguiente(_Raiz);
	default:
		break;
	}
}

void Lista::push_front(Nodo * nodo)
{
	Nodo* temp1 = _Raiz;
	_Raiz=nodo;
	nodo->GiveSiguiente(temp1);

}

Lista::Lista()
{
}


Lista::~Lista()
{
}
