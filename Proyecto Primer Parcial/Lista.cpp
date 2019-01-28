#include "Lista.h"

Nodo * Lista::GetRaiz()
{
	return _Raiz;
}

void Lista::clear()
{
	delete _Raiz;
}

void Lista::push_back(Nodo * nodo)
{
	Nodo* temp1=_Raiz, *temp2;
	switch (tipo)
	{
	case 's':
	case 'd':
		if (_Raiz != NULL)
		{

			while (temp1->GetSiguiente() != NULL)
			{
				temp2 = temp1;
				temp1 = temp1->GetSiguiente();
			}
			nodo->setNext(NULL);
			temp2->setNext(nodo);
			if (tipo == 'd') nodo->setPrev(temp2);
			break;
		}
		_Raiz = nodo;
		break;
	case'S':// siendo un anillo, regresa un paso al "ultimo" y agrega un siguiente nodo y a ese nodo se le vincula con la raiz de la lista 
		if (_Raiz != NULL)
		{
			while (temp1->GetSiguiente() != _Raiz)
			{
				temp2 = temp1;
				temp1 = temp1->GetSiguiente();
			}
			nodo->setNext(_Raiz);
			temp2->setNext(nodo);
			break;
		}
		_Raiz = nodo;
		nodo->setNext(_Raiz);
		break;
	case 'D':// da un paso atras en el anillo y coloca ahi el nodo, que se ligara al anterior y a la razi para cerrar el ciruclo
		if (_Raiz != NULL)
		{
		temp2 = temp1->GetAnterior();
		nodo->setPrev(temp2);
		nodo->setNext(_Raiz);
		temp2->setNext(nodo);
		break;
		}
		nodo->setPrev(nodo);
		nodo->setNext(nodo);
		_Raiz = nodo;
		break;

	default:
		break;
	}
	_Fin = nodo;
}

void Lista::push_front(Nodo * nodo)
{
	Nodo* temp1 = _Raiz;
	_Raiz=nodo;
	nodo->setNext(temp1);
	if ((tipo != 'd') | (tipo != 'D'))  return; 
	temp1->setPrev(_Raiz);
}

void Lista::insert_at(Nodo * nodo, int lugar)
{
	Nodo* temp1 = _Raiz, *temp2;
	int pos = 0;
	while (pos != lugar)
	{
		temp2 = temp1;
		if (temp2 == NULL) { std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
		temp1 = temp1->GetSiguiente();
		pos++;
	}
	if ((temp1 == NULL) | (temp1==_Raiz)) {
		nodo->setNext(temp1);
		temp2->setNext(nodo);
	}
	if ((tipo != 's') && (tipo != 'S')) { nodo->setPrev(temp2); temp1->setPrev(nodo); }
}

void Lista::delete_at(int lugar)
{
	Nodo* temp1 = _Raiz, *temp2;
	for (int i = 0; i < lugar; i++)
	{
		temp2 = temp1;
		if ((temp2 == NULL) | (temp2==_Raiz) && (i !=0 )) { std::cout << "Lo siento la direccion donde quiere borrar a la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
		temp1 = temp1->GetSiguiente();
	}
	temp2->setNext(temp1->GetSiguiente());
	if ((tipo != 's') && (tipo != 'S')) temp1->GetSiguiente()->setPrev(temp2);
	delete temp1;
}

void Lista::_deleteByName(string nombre, string apellido)
{
	Nodo* temp1 = _Raiz,*temp2=_Raiz;
	while (temp2 != NULL)
	{
		if (temp1->GetPersona()->GetLName() != apellido)
		{
			temp2 = temp1;
			temp1 = temp1->GetSiguiente;
			continue; 
		}
		if (temp1->GetPersona()->GetFName() != nombre) continue;
		if (isThis(temp1))
		{
			temp2->setNext(temp1->GetSiguiente);
			if ((tipo == 'd')|(tipo == 'D')) temp1->GetSiguiente.GiveAnterior(temp2);
			temp1->setNext(NULL);
			delete temp1;
		}
		temp2 = temp1;
		temp1 = temp1->GetSiguiente;
	}
	std::cout << "La persona que busca, no coincide con la lista de personas." << std::endl;
}


bool Lista::isThis(Nodo * nodo)
{
	std::cout << "/nNombre: " << nodo->GetPersona()->GetFName() << " " << nodo->GetPersona()->GetLName() << "\nFecha de nacimiento: " << nodo->GetPersona()->GetBD()[0] << '/' << nodo->GetPersona()->GetBD()[1] << '/' << nodo->GetPersona()->GetBD()[2] << "\nEmail: " << nodo->GetPersona()->GetEMail() << std::endl;
	std::cout << "Si es esta la persona que quieres eliminar de la lista, Presiones 's'" << std::endl;
	char opc = '\0';
	std::cin >> opc;
	if ((opc != 's') | (opc != 'S'))return false;
	return true;
}

Lista::Lista()
{
}

Lista::~Lista()
{
	
}
