#include "Lista.h"

Nodo * Lista::GetRaiz()
{
	return _Raiz;
}

Nodo * Lista::GetFin()
{
	return _Fin;
}

void Lista::clear()
{
	if (_Raiz != NULL) {
		_Fin->setNext(NULL);
		delete _Raiz;
	}
}

void Lista::print()
{
	Nodo* temp = _Raiz;
	int x = 0;
	if (_Raiz != NULL) {
		std::cout << "Apellido,Nombre,EMail,Fecha" << std::endl;
		while (temp != _Fin)
		{
			std::cout << temp->GetPersona().GetLName() << ',' << temp->GetPersona().GetFName() << ',' << temp->GetPersona().GetEMail() << ',' << temp->GetPersona().GetBD(0) << ',' << temp->GetPersona().GetBD(1) << ',' << temp->GetPersona().GetBD(2) << endl;
			temp = temp->GetNext();
		}
	}
}

void Simple::push_back(Nodo * nodo)
{
	Nodo* temp1 = _Raiz;
	if (_Raiz != NULL)
	{
		while (temp1!= _Fin)
		{
			temp1 = temp1->GetNext();
		}
		temp1->setNext(nodo);
		_Fin = nodo;
		return;
	}
	_Raiz = nodo;
	_Fin = nodo;
}

void Simple::push_front(Nodo * nodo)
{
	if (_Raiz != NULL)
	{
		nodo->setNext(_Raiz);
		_Raiz = nodo;
	return;
	}
	_Raiz = nodo;
	_Fin = nodo;
}

void Simple::insert_at(Nodo * nodo, int lugar)
{
	Nodo* temp = _Raiz;
	int pos = 0;
	while (pos != lugar)
	{
		if (temp == _Fin) { std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
		temp = temp->GetNext();
		pos++;
	}
	if (temp == _Fin) {
		temp->setNext(nodo);
		_Fin = nodo;
		return;
	}
	nodo->setNext(temp->GetNext());
	temp->setNext(nodo);
}

void Simple::delete_at(int lugar)
{
	Nodo* temp1 = _Raiz, *temp2 = 0;
	int pos = 0;
	while (pos != lugar) {
		temp2 = temp1;
		if (temp1 == _Fin) {
			std::cout << "Lo siento la direccion donde quiere borrar a la persona es inexistente(Se ha sobrepasado)" << std::endl;
			return;
		}
		temp1 = temp1->GetNext();
		pos++;
	}
	if (temp1 != _Fin) {
		temp2->setNext(temp1->GetNext());
		temp1->setNext(NULL);
		delete temp1;
		return;
	}
	_Fin = temp2;
	temp2->setNext(NULL);
	temp1->setNext(NULL);
	delete temp1;
}

bool Lista::FindByName(string nombre, string apellido)
{
	Nodo* temp = _Raiz;
	int x = -1;
	if (_Raiz != NULL) {
		while (temp != _Fin)
		{
			x++;
			if (temp->GetPersona().GetLName() != apellido)
			{
				temp = temp->GetNext();
				continue;
			}
			if (temp->GetPersona().GetFName() != nombre) continue;
			if (isThis(temp))
			{
				std::cout << "La persona esta persona se encuentra en el lugar: " << x << std::endl;
				return true;
			}
			temp = temp->GetNext();
		}
		std::cout << "La persona que busca, no coincide con la lista de personas." << std::endl;
		return false;
	}
	std::cout << "La lista esta vacia" << std::endl;
	return false;
}

int Lista::size()
{
	Nodo* temp = _Raiz;
	int x = 0;
	if (_Raiz != NULL) {
		while (temp != _Fin)
		{
			temp = temp->GetNext();
			x++;
		}
		return x;
	}
	std::cout << "La lista esta vacia" << std::endl;
}

Nodo * Simple::pop_back()
{
	Nodo* temp1 = _Raiz, *temp2=0;
	while (temp1 != _Fin)
	{
		temp2 = temp1;
		temp1 = temp1->GetNext();
	}
	_Fin = temp2;
	temp2->setNext(NULL);
	temp1->setNext(NULL);
	return temp1;
}

Nodo * Simple::pop_front()
{
	Nodo* temp = _Raiz;
	_Raiz = _Raiz->GetNext();
	temp->setNext(NULL);
	return temp;
}

void Simple::delete_last()
{
	delete pop_back();
}

void Simple::delete_first()
{
	delete pop_front();
}

void Simple::sortByName()
{
	Nodo* actual = _Raiz->GetNext(), *anterior = _Raiz;
	Persona temp;
	int tam = size(), tam2 = size();
	bool orden = true;
	for (int i = 0; i < tam - 1; i++)
	{
		actual = _Raiz->GetNext();
		anterior = _Raiz;
		for (int j = 0; j < tam2; j++)//
		{
			if (actual->GetPersona().GetLName() + actual->GetPersona().GetFName() < anterior->GetPersona().GetLName() + anterior->GetPersona().GetFName()) {// intercambia de lugar la mayor por la menor.
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona());
				anterior->setPersona(temp);
				orden = false;
			}
			actual = actual->GetNext();
			anterior = anterior->GetNext();
		}
		if (orden) break;
		tam2--;
	}

}

void Simple::sortByBrithDay()
{
	Nodo* actual = _Raiz->GetNext(), *anterior = _Raiz;
	Persona temp;
	int tam = size(), tam2 = size();
	bool orden = true;
	for (int i = 0; i < tam - 1; i++)
	{
		actual = _Raiz->GetNext();
		anterior = _Raiz;
		for (int j = 0; j < tam2; j++)
		{
			if (actual->GetPersona().GetBD(2) < anterior->GetPersona().GetBD(2)) {// intercambia de lugar la mayor por la menor.
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona());
				anterior->setPersona(temp);
				orden = false;
			}
			if ((actual->GetPersona().GetBD(2) == anterior->GetPersona().GetBD(1)) && (actual->GetPersona().GetBD(1) < anterior->GetPersona().GetBD(1))) {// intercambia de lugar la mayor por la menor.
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona());
				anterior->setPersona(temp);
			}
			if ((actual->GetPersona().GetBD(2) == anterior->GetPersona().GetBD(1)) && (actual->GetPersona().GetBD(1) == anterior->GetPersona().GetBD(1)) && (actual->GetPersona().GetBD(0) < anterior->GetPersona().GetBD(0))) {// intercambia de lugar la mayor por la menor.
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona());
				anterior->setPersona(temp);
			}
			
			actual = actual->GetNext();
			anterior = anterior->GetNext();
		}
		if (orden) break;
		tam2--;
	}
}

void Simple::sortByEMail()
{
}


bool Lista::isThis(Nodo * nodo)
{
	std::cout << "/nNombre: " << nodo->GetPersona().GetLName() << " " << nodo->GetPersona().GetFName() <<"\nFecha de nacimiento: " << nodo->GetPersona().GetBD(0) << '/' << nodo->GetPersona().GetBD(1) <<'/' << nodo->GetPersona().GetBD(2) << "\nEmail: " << nodo->GetPersona().GetEMail() << std::endl;
	std::cout << "Esta seguro de que esta es la persona?\n Presiones 's' si es asi\n" << std::endl;
	char opc = '\0';
	std::cin >> opc;
	if (opc != 's')return false;
	return true;
}



Lista::Lista()
{
}

Lista::~Lista()
{
	clear();
}

void Doble::push_back(Nodo * nodo)
{
	Nodo* temp1 = _Raiz;
	if (_Raiz != NULL)
	{
		while (temp1 != _Fin)
		{
			temp1 = temp1->GetNext();
		}
		temp1->setNext(nodo);
		nodo->setPrev(temp1);
		_Fin = nodo;
		_Fin->setNext(NULL);
		return;
	}
	_Raiz = nodo;
	_Fin = nodo;
}

void Doble::push_front(Nodo * nodo)
{
	Nodo* temp1 = _Raiz;
	if (_Raiz != NULL)
	{
		_Raiz = nodo;
		nodo->setNext(temp1);
		temp1->setPrev(_Raiz);
		_Fin->setNext(NULL);
		return;
	}
	_Raiz = nodo;
	_Fin = nodo;
	nodo->setNext(nodo);
	nodo->setPrev(nodo);
}

void Doble::insert_at(Nodo * nodo, int lugar)
{
	Nodo* temp1 = _Raiz;
	int pos = 0;
	while (pos != lugar)
	{
		temp1 = temp1->GetNext();
		if (temp1 == NULL) { std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
		pos++;
	}
	if (temp1==_Fin) _Fin = nodo;
	nodo->setNext(temp1->GetNext());
	nodo->setPrev(temp1);
	if(temp1 != _Fin)temp1->GetNext()->setPrev(nodo);
	temp1->setNext(nodo);
}

void Doble::delete_at(int lugar)
{
	Nodo* temp1 = _Raiz, *temp2 = 0;
	if (_Raiz != NULL) {
		for (int i = 0; i < lugar; i++)
		{
			temp2 = temp1;
			temp1 = temp1->GetNext();
			if (temp1 == NULL) {
				std::cout << "Lo siento la direccion donde quiere borrar a la persona es inexistente(Se ha sobrepasado)" << std::endl;
				return;
			}
		} 
		temp2->setNext(temp1->GetNext());
		if (temp1->GetNext() != NULL)temp1->GetNext()->setPrev(temp2);
		temp1->setNext(NULL);
		delete temp1;
		return;
	}
	
	std::cout << "La lista esta vacia" << std::endl;
}

Nodo * Doble::pop_back()
{
	Nodo* temp1 = _Raiz, *temp2 = 0;
	while (temp1 != _Fin)
	{
		temp2 = temp1;
		temp1 = temp1->GetNext();
	}
	_Fin = temp2;
	temp2->setNext(NULL);
	temp1->setNext(NULL);
	return temp1;
}

Nodo * Doble::pop_front()
{
	Nodo* temp = _Raiz;
	_Raiz = _Raiz->GetNext();
	_Raiz->setPrev(NULL);
	temp->setNext(NULL);
	return temp;
}

void Doble::delete_last()
{
	delete pop_back();
}

void Doble::delete_first()
{
	delete pop_front();
}

void Doble::sortByName()
{
	quickSort_byName(_Raiz,_Fin);
}

void Doble::quickSort_byName(Nodo* izquierda, Nodo* derecha)
{
	if ((derecha != NULL) && (izquierda != derecha) && (izquierda != NULL))
	{
		if ((derecha->GetPrev() != NULL) | (izquierda->GetNext() != NULL)) {
			Nodo *p = _quickSort_byName(izquierda, derecha);
			if (p != NULL) quickSort_byName(izquierda, p->GetPrev());
			if (p != NULL) quickSort_byName(p->GetNext(), derecha);
		}
	}
}

Nodo * Doble::_quickSort_byName(Nodo * izquierda, Nodo * derecha)
{
	Persona x = derecha->GetPersona(),temp;
	Nodo  *j = izquierda ,*i = izquierda->GetPrev();
		while (j != derecha)
		{
			if (j == NULL)return NULL;
			if ((j->GetPersona().GetLName()+ j->GetPersona().GetFName()) < (x.GetLName()+ x.GetFName()))
			{
				i = (i == NULL) ? izquierda : i->GetNext();
				temp = i->GetPersona();
				i->setPersona(j->GetPersona());
				j->setPersona(temp);
			}
			j = j->GetNext();
		}
		i = (i == NULL) ? izquierda : i->GetNext();
		temp = i->GetPersona();
		i->setPersona(derecha->GetPersona());
		derecha->setPersona(temp);
		return i;
}

void Doble::sortByBrithDay()
{
	quickSort_byBrithDay(_Raiz, _Fin);
}

void Doble::quickSort_byBrithDay(Nodo* derecha, Nodo* izquierda)
{
	if ((derecha != NULL) && (izquierda != derecha) && (izquierda != NULL))
	{
		if ((derecha->GetPrev() != NULL) | (izquierda->GetNext() != NULL)) {
			Nodo *p = _quickSort_byBrithDay(izquierda, derecha);
			if (p != NULL) quickSort_byBrithDay(izquierda, p->GetPrev());
			if (p != NULL) quickSort_byBrithDay(p->GetNext(), derecha);
		}
	}
}

Nodo * Doble::_quickSort_byBrithDay(Nodo * derecha, Nodo * izquierda)
{
	Persona x = derecha->GetPersona(), temp;
	Nodo  *j = izquierda, *i = izquierda->GetPrev();
	while (j != derecha)
	{
		if (j == NULL)return NULL;
		if (j->GetPersona().GetBD(2) < x.GetBD(2))
		{
			i = (i == NULL) ? izquierda : i->GetNext();
			temp = i->GetPersona();
			i->setPersona(j->GetPersona());
			j->setPersona(temp);
		}
		if ((j->GetPersona().GetBD(2) == x.GetBD(2)) && (j->GetPersona().GetBD(1) < x.GetBD(1))) {// intercambia de lugar la mayor por la menor.
			i = (i == NULL) ? izquierda : i->GetNext();
			temp = i->GetPersona();
			i->setPersona(j->GetPersona());
			j->setPersona(temp);
		}
		if ((j->GetPersona().GetBD(2) == x.GetBD(1)) && (j->GetPersona().GetBD(1) == x.GetBD(1)) && (j->GetPersona().GetBD(0) < x.GetBD(0))) {// intercambia de lugar la mayor por la menor.
			
			temp = i->GetPersona();
			i->setPersona(j->GetPersona());
			j->setPersona(temp);
		}
		j = j->GetNext();
	}
	i = (i == NULL) ? izquierda : i->GetNext();
	temp = i->GetPersona();
	i->setPersona(derecha->GetPersona());
	derecha->setPersona(temp);
	return i;
}

void RSimple::push_back(Nodo * nodo)
{
	if (_Raiz != NULL)
	{
		_Fin->setNext(nodo);
		nodo->setNext(_Raiz);
		_Fin = nodo;
		return;
	}
	_Raiz = nodo;
	_Fin = nodo;
	nodo->setNext(_Raiz);
}

void RSimple::push_front(Nodo * nodo)
{
	if (_Raiz != NULL)
	{
		_Fin->setNext(nodo);
		nodo->setNext(_Raiz);
		_Raiz = nodo;
		return;
	}
	_Raiz = nodo;
	_Fin = nodo;
	nodo->setNext(nodo);
}

void RSimple::insert_at(Nodo * nodo, int lugar)
{
	Nodo* temp1 = _Raiz;
	int pos = 0;
	while (pos != lugar)
	{
		if (temp1 == _Fin) { std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
		temp1 = temp1->GetNext();
		pos++;
	}
	if (temp1 = _Fin) _Fin = nodo;
	if (temp1 = _Raiz) _Raiz = nodo;
	nodo->setNext(temp1->GetNext());
	temp1->setNext(nodo);

}

void RSimple::delete_at(int lugar)
{
	if (_Raiz != NULL) {
		Nodo* temp1 = _Raiz, *temp2 = 0;
		int pos = 0;
		while (pos != lugar)
		{
			temp2 = temp1;
			if (temp2 == _Fin) { std::cout << "Lo siento la direccion donde quiere borrar a la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
			temp1 = temp1->GetNext();
			pos++;
		}
		if (temp1 = _Raiz) {
			_Raiz = temp1->GetNext();
			_Fin->setNext(_Raiz);
		}
		if (temp1 != _Fin) temp2->setNext(temp1->GetNext());
		if (temp1 == _Fin) _Fin = temp2;
		temp1->setNext(NULL);
		delete temp1;
	}
	std::cout << "La lista esta vacia" << std::endl;
}


Nodo * RSimple::pop_back()
{
	if (_Raiz != NULL)
	{
		Nodo* temp1 = _Raiz, *temp2 = 0;
		while (temp1 != _Fin)
		{
			temp2 = temp1;
			temp1 = temp1->GetNext();
		}
		temp2->setNext(NULL);
		_Fin = temp2;
		return temp1;
	}
	std::cout << "La lista esta vacia" << std::endl;
	return NULL;
}

Nodo * RSimple::pop_front()
{
	Nodo* temp = _Raiz;
	if (_Raiz == NULL)
	{
		_Raiz = _Raiz->GetNext();
		temp->setNext(NULL);
		return temp;
	}
	std::cout << "La lista esta vacia" << std::endl;
	return NULL;
}

void RSimple::delete_last()
{
	delete pop_back();
}

void RSimple::delete_first()
{
	delete pop_front();
}

void RSimple::sortByName()
{
	Nodo* actual = _Raiz->GetNext(), *anterior = _Raiz;
	Persona temp;
	int tam = size(), tam2 = size();
	bool orden = true;
	for (int i = 0; i < tam - 1; i++)
	{
		actual = _Raiz->GetNext();
		anterior = _Raiz;
		for (int j = 0; j < tam2; j++)
		{
			if ((actual->GetPersona().GetLName() < anterior->GetPersona().GetLName()) && (anterior != _Fin)) {// intercambia de lugar la mayor por la menor.
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona()); // cuando ya esta ordenado hace iteraciones de mas.
				anterior->setPersona(temp);
				orden = false;
			}
			if ((actual->GetPersona().GetLName() == anterior->GetPersona().GetLName()) && (actual->GetPersona().GetFName() < anterior->GetPersona().GetFName())) {
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona()); // cuando ya esta ordenado hace iteraciones de mas.
				anterior->setPersona(temp);
			}
			actual = actual->GetNext();
			anterior = anterior->GetNext();
		}
		if (orden) break;
		tam2--;
	}

}

void RSimple::sortByBrithDay()
{
	Nodo* actual = _Raiz->GetNext(), *anterior = _Raiz;
	Persona temp;
	int tam = size(), tam2 = size();
	bool orden = true;
	for (int i = 0; i < tam - 1; i++)
	{
		actual = _Raiz->GetNext();
		anterior = _Raiz;
		for (int j = 0; j < tam2; j++)//
		{
			if (actual->GetPersona().GetBD(2) < anterior->GetPersona().GetBD(2)) {// intercambia de lugar la mayor por la menor.
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona());
				anterior->setPersona(temp);
				orden = false;
			}
			if ((actual->GetPersona().GetBD(2) == anterior->GetPersona().GetBD(2)) && (actual->GetPersona().GetBD(1) < anterior->GetPersona().GetBD(1))) {// intercambia de lugar la mayor por la menor.
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona());
				anterior->setPersona(temp);
			}
			if ((actual->GetPersona().GetBD(2) == anterior->GetPersona().GetBD(2)) && (actual->GetPersona().GetBD(1) == anterior->GetPersona().GetBD(1)) && (actual->GetPersona().GetBD(0) < anterior->GetPersona().GetBD(0))) {// intercambia de lugar la mayor por la menor.
				temp = actual->GetPersona();
				actual->setPersona(anterior->GetPersona());
				anterior->setPersona(temp);
			}

			actual = actual->GetNext();
			anterior = anterior->GetNext();
		}
		if (orden == true) break;
		tam2--;
	}
}

void RDoble::push_back(Nodo * nodo)
{
	if (_Raiz != NULL)
	{
		nodo->setNext(_Raiz);
		nodo->setPrev(_Fin);
		_Raiz->setPrev(nodo);
		_Fin->setNext(nodo);
		_Fin = nodo;
		return;
	}
	nodo->setPrev(nodo);
	nodo->setNext(nodo);
	_Raiz = nodo;
	_Fin = nodo;
}

void RDoble::push_front(Nodo * nodo)
{
	Nodo* temp1 = _Raiz;
	if (_Raiz != NULL)
	{
		_Raiz = nodo;
		nodo->setNext(temp1);
		temp1->setPrev(_Raiz);
		_Fin->setNext(_Raiz);
		_Raiz->setPrev(_Fin);
		return;
	}
	_Raiz = nodo;
	_Fin = nodo;
	nodo->setNext(nodo);
	nodo->setPrev(nodo);

	
}

void RDoble::insert_at(Nodo * nodo, int lugar)
{
	Nodo* temp1 = _Raiz, *temp2 = 0;
	int pos = 0;
	if (lugar == 0) push_front(nodo);
	while (pos != lugar)
	{
		temp2 = temp1;
		if (temp1 == _Fin) { std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
		temp1 = temp1->GetNext();
		pos++;
	}
	if (temp1 == _Raiz) _Fin = nodo;
	nodo->setNext(temp1);
	nodo->setPrev(temp2);
	temp2->setNext(nodo);
	temp1->setPrev(nodo);
}

void RDoble::delete_at(int lugar)
{
	Nodo* temp1 = _Raiz, *temp2 = 0;
	for (int i = 0; i < lugar; i++)
	{
		temp2 = temp1;
		if ((temp2 == NULL) | (temp2 == _Raiz) && (i != 0)) { std::cout << "Lo siento la direccion donde quiere borrar a la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
		temp1 = temp1->GetNext();
	}
	if (temp1 == _Raiz) {
		_Fin->setNext(_Raiz->GetNext());
		_Raiz->GetNext()->setPrev(_Fin);
		_Raiz = _Raiz->GetNext();
		delete temp1;
		return;
	}
	if (temp1 == _Fin) _Fin = temp2;
	temp2->setNext(temp1->GetNext());
	temp1->GetNext()->setPrev(temp2);
	temp1->setNext(NULL);
	delete temp1;
}



Nodo * RDoble::pop_back()
{
	Nodo* temp=_Fin;
	_Fin = _Fin->GetPrev();
	_Fin->setNext(_Raiz);
	_Raiz->setPrev(_Fin);
	temp->setNext(NULL);
	return temp;
}

Nodo * RDoble::pop_front()
{
	Nodo* temp = _Raiz;
	_Raiz = _Raiz->GetNext();
	_Fin->setNext(_Raiz);
	_Raiz->setPrev(_Fin);
	temp->setNext(NULL);
	return temp;
}

void RDoble::delete_last()
{
	delete pop_back();
}

void RDoble::delete_first()
{
	delete pop_front();
}

void RDoble::sortByName()
{
	_Raiz->setPrev(NULL);
	_Fin->setNext(NULL);
	quickSort_byName(_Raiz, _Fin);
	_Fin->setNext(_Raiz);
	_Raiz->setPrev(_Fin);
}

void RDoble::quickSort_byName(Nodo * izquierda, Nodo * derecha)
{
	if ((derecha != NULL) && (izquierda != derecha) && (izquierda != NULL))
	{
		if ((derecha->GetPrev() != NULL) | (izquierda->GetNext() != NULL)) {
			Nodo *p = _quickSort_byName(izquierda, derecha);
			if (p != NULL) quickSort_byName(izquierda, p->GetPrev());
			if (p != NULL) quickSort_byName(p->GetNext(), derecha);
		}
	}
}

Nodo * RDoble::_quickSort_byName(Nodo * izquierda, Nodo *derecha)
{
	Persona x = derecha->GetPersona(), temp;
	Nodo  *j = izquierda, *i = izquierda->GetPrev();
	while (j != derecha)
	{
		if (j == NULL)return NULL;
		if ((j->GetPersona().GetLName() + j->GetPersona().GetFName()) < (x.GetLName() + x.GetFName()))
		{
			i = (i == NULL) ? izquierda : i->GetNext();
			temp = i->GetPersona();
			i->setPersona(j->GetPersona());
			j->setPersona(temp);
		}
		j = j->GetNext();
	}
	i = (i == NULL) ? izquierda : i->GetNext();
	temp = i->GetPersona();
	i->setPersona(derecha->GetPersona());
	derecha->setPersona(temp);
	return i;
}

void RDoble::sortByBrithDay()
{
	quickSort_byBrithDay(_Raiz, _Fin);
}

void RDoble::quickSort_byBrithDay(Nodo* derecha, Nodo* izquierda)
{
	if ((derecha != NULL) && (izquierda != derecha) && (izquierda != NULL))
	{
		if ((derecha->GetPrev() != NULL) | (izquierda->GetNext() != NULL)) {
			Nodo *p = _quickSort_byBrithDay(izquierda, derecha);
			if (p != NULL) quickSort_byBrithDay(izquierda, p->GetPrev());
			if (p != NULL) quickSort_byBrithDay(p->GetNext(), derecha);
		}
	}
}

Nodo * RDoble::_quickSort_byBrithDay(Nodo * derecha, Nodo * izquierda)
{
	Persona x = derecha->GetPersona(), temp;
	Nodo  *j = izquierda, *i = izquierda->GetPrev();
	while (j != derecha)
	{
		if (j == NULL)return NULL;
		if (j->GetPersona().GetBD(2) < x.GetBD(2))
		{
			i = (i == NULL) ? izquierda : i->GetNext();
			temp = i->GetPersona();
			i->setPersona(j->GetPersona());
			j->setPersona(temp);
		}
		if ((j->GetPersona().GetBD(2) == x.GetBD(2)) && (j->GetPersona().GetBD(2) < x.GetBD(2))) {// intercambia de lugar la mayor por la menor.
			i = (i == NULL) ? izquierda : i->GetNext();
			temp = i->GetPersona();
			i->setPersona(j->GetPersona());
			j->setPersona(temp);
		}
		if ((j->GetPersona().GetBD(2) == x.GetBD(2)) && (j->GetPersona().GetBD(1) == x.GetBD(2)) && (j->GetPersona().GetBD(0) < x.GetBD(0))) {// intercambia de lugar la mayor por la menor.

			temp = i->GetPersona();
			i->setPersona(j->GetPersona());
			j->setPersona(temp);
		}
		j = j->GetNext();
	}
	i = (i == NULL) ? izquierda : i->GetNext();
	temp = i->GetPersona();
	i->setPersona(derecha->GetPersona());
	derecha->setPersona(temp);
	return i;
}
