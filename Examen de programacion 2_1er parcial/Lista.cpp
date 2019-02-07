#include "Lista.h"

Nodo * Lista::GetRaiz()
{
		return _Raiz;
}

Nodo * Lista::GetFin()
{
	if (_Raiz != NULL) {
		return _Fin;
	}
	return NULL;
}

void Lista::clear()
{
	if (_Raiz != NULL) {// si la lista no esta vacia
		_Fin->setNext(NULL);// al ultimo nodo de la lista lo deja sin nodo siguiente, pues el destructor de Nodo raiz, desecadenara
		delete _Raiz;		// una reaccion en cadena que eliminara todos los nodos
		_Raiz = NULL;
	}
	std::cout << "\n\nLista vacia\n" << std::endl;
}

void Lista::print()
{
	Nodo* temp = _Raiz;
	if (_Raiz != NULL) {
		std::cout << "Apellido,Nombre,EMail,Fecha(DD/MM/YYYY)" << std::endl;// formato con el que se imprimira la lista
		while (temp != _Fin)
		{
			std::cout << temp->GetPersona().GetLName() << ',' << temp->GetPersona().GetFName() << ',' << temp->GetPersona().GetEMail() << ',' << temp->GetPersona().GetBD(0) << '/' << temp->GetPersona().GetBD(1) << '/' << temp->GetPersona().GetBD(2) << endl;
			temp = temp->GetNext();// imprime los datos y da un salto de linea
		}
		std::cout << temp->GetPersona().GetLName() << ',' << temp->GetPersona().GetFName() << ',' << temp->GetPersona().GetEMail() << ',' << temp->GetPersona().GetBD(0) << '/' << temp->GetPersona().GetBD(1) << '/' << temp->GetPersona().GetBD(2) << endl;
		return;// es while que siempre termina apuntando a la ultma persona asi que se tiene que imprimir de manera individual. ///podria arreglarse haciendo un for con el tamnio de la lista
	}
	std::cout << "\n\nLista vacia\n" << std::endl;
}

void Simple::push_back(Nodo * nodo)
{
	Nodo* temp1 = _Raiz;
	if (_Raiz != NULL)
	{
		while (temp1!= _Fin)//va hasta el fin de la lista, ahi hace referencia al nuevo nodo, seteandolo como el ultimo en la lista
		{
			temp1 = temp1->GetNext();
		}
		temp1->setNext(nodo);
		_Fin = nodo;
		return;
	}
	_Raiz = nodo;//si la lista esta vacia hara del unico nodo raiz y fin
	_Fin = nodo;
}

void Simple::push_front(Nodo * nodo)
{
	if (_Raiz != NULL)
	{
		nodo->setNext(_Raiz);// se vinculara la raiz como siguiente del nuevo nodo y el nuevo nodo sera seteado como la raiz.
		_Raiz = nodo;
	return;
	}
	_Raiz = nodo; //igual que en push_Back, si esta vacia la lista, el nodo sera raiz y fin.
	_Fin = nodo;
}

void Simple::insert_at(Nodo * nodo, int lugar)
{
	if (lugar < 0) {
		push_front(nodo);// si el indice introducido por el usuario es 0, hara un pushfront al nodo y retornara.
		return;
	}
	Nodo* temp = _Raiz;
	int pos = 0;
	while (pos != lugar)// hasta que no se llega a la posicion se recorrera la lista
	{
		pos++;
		temp = temp->GetNext();
		if ((temp == _Fin) && (lugar != pos)) {
			std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)\nLa persona se a agregado al final de la lista" << std::endl;
			push_back(nodo);// si el indice llega a el ultimo lugar y aun no llegamos al objetico se re incertara el nodo al final de la lista
			return;
		}
	}
	if (temp != _Fin) {// si el nodo ultimo a donde se quiere agregar es el final, simplemente se hace un pushback
		nodo->setNext(temp->GetNext());
		temp->setNext(nodo);
		return;
	}
	push_back(nodo);
}

void Simple::delete_at(int lugar)
{
	if (lugar<0)//similar a insert, si el numero ingresado es 0, se llamara a la funcion de borrar el primero.
	{
		delete_first();
		return;
	}
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
	temp1->setNext(NULL);// Si llega a ser el indice final de la lista, hay que dejar siempre al ultimo puntero, apuntando a nulo
	delete temp1;
}

bool Lista::FindByName(string nombre, string apellido)//busqueda por nombre y apellido
{
	Nodo* temp = _Raiz;
	int x = -1;
	if (_Raiz != NULL) {
		while (temp != _Fin)
		{
			x++;
			if (temp->GetPersona().GetLName() != apellido)// si coicide con el apellido se evaluara su nombre
			{
				temp = temp->GetNext();
				continue;
			}
			if (temp->GetPersona().GetFName() != nombre) {// si coincide su nombre y apellido se preguntara si es la persona que estas buscando
				temp = temp->GetNext();
				continue;
			}
			if (isThis(temp))
			{
				std::cout << "La persona esta persona se encuentra en el lugar: " << x << std::endl;
				return true;//si es la persona que buscas te dira su ubicacion en el indice, y dara de valor de retorno positivo
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
	int x = 0;
	if (_Raiz != NULL) {
		Nodo* temp = _Raiz;
		while (temp != _Fin)
		{
			temp = temp->GetNext(); // aumenta x hasta que se llega al final, despues se le suma uno mas para dar el tamanio real de la lista
			x++;
		}
		x++;
		return x;
	}
	std::cout << "\n\nLa lista esta vacia\n" << std::endl;
	return 0;
}

Nodo * Simple::pop_back()
{
	if (_Raiz != _Fin) {
		Nodo* temp1 = _Raiz, *temp2 = 0;
		while (temp1 != _Fin)
		{
			temp2 = temp1;
			temp1 = temp1->GetNext();// recorre la lista hasta el final y saca de la lista ese nodo, y a la vez hace nulo el puntero siguiente de nuestro ahora ultimo nodo
		}
		_Fin = temp2;
		temp2->setNext(NULL);
		temp1->setNext(NULL);
		return temp1;
	}// ai llegara a ser el unico nodo en la lista se hace nula la raiz y se regresa el nodo
	_Raiz = NULL;
	return _Fin;
}

Nodo * Simple::pop_front()//misma logica que en el pasado pero ahora el primero de la lista
{
	Nodo* temp = _Raiz;
	if (_Raiz != _Fin)
	{
		_Raiz = _Raiz->GetNext();
		temp->setNext(NULL);
		return temp;
	}
	_Raiz = NULL;
	return _Fin;
}

void Simple::delete_last()//borra ultimo
{
	if (_Raiz != NULL) {
		Nodo* temp = _Raiz;
		delete pop_back();
	}
	return;
}

void Simple::delete_first()//borra primero
{
	if (_Raiz != NULL) {
		delete pop_front();
	}
	return;
}

void Simple::sortByName()//hace un acomodo alfabetico de la lista
{
	Nodo* actual = _Raiz->GetNext(), *anterior = _Raiz;
	Persona temp;
	int tam = size(), tam2 = size()-1;
	bool orden = true;
	for (int i = 0; i < tam - 1; i++)
	{
		actual = _Raiz->GetNext();
		anterior = _Raiz;
		for (int j = 0; j < tam2; j++)
		{
			if ((actual->GetPersona().GetLName() + actual->GetPersona().GetFName()) < (anterior->GetPersona().GetLName() + anterior->GetPersona().GetFName())) {// intercambia de lugar la mayor por la menor.
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

void Simple::sortByBrithDay()// hace un acomodo tipo burbuja en la lista por fecha de nacimiento
{
	Nodo* actual = _Raiz->GetNext(), *anterior = _Raiz;
	Persona temp;
	int tam = size(), tam2 = size()-1;
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
		if (orden) break;
		tam2--;
	}
}




bool Lista::isThis(Nodo * nodo)//te muestra los datos de una persona y tu confirmas si son los datos que esperabas ver
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
	if (lugar < 0) {
		push_front(nodo);
		return;
	}
	while (pos != lugar)
	{
		temp1 = temp1->GetNext();
		if (temp1 == NULL) {
			std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)\nLa persona se a agregado al final de la lista" << std::endl;
			push_back(nodo);
			return;
		}
		pos++;
	}
	if ((temp1 != _Fin) && (temp1->GetNext() != NULL)) {
		temp1->GetNext()->setPrev(nodo);
		nodo->setNext(temp1->GetNext());
	}
	push_back(nodo);
}

void Doble::delete_at(int lugar)
{
	if (lugar<0) {
		delete_first();
		return;
	}
	Nodo* temp1 = _Raiz, *temp2 = 0;
	for (int i = 0; i < lugar; i++)
	{
		temp2 = temp1;
		temp1 = temp1->GetNext();
		if (temp1 == NULL) {
			std::cout << "Lo siento la direccion donde quiere borrar a la persona es inexistente(Se ha sobrepasado)" << std::endl;
			return;
		}
	}
	if (temp1 != _Fin) {
		temp2->setNext(temp1->GetNext());
		temp1->GetNext()->setPrev(temp2);
		temp1->setNext(NULL);
		delete temp1;
		return;
	}
	delete_last();
}

Nodo * Doble::pop_back()
{
	if (_Fin != _Raiz) {
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
	_Raiz = NULL;
	return _Fin;
}

Nodo * Doble::pop_front()
{
	Nodo* temp = _Raiz;
	if (_Raiz!=_Fin)
	{
	_Raiz = _Raiz->GetNext();
	_Raiz->setPrev(NULL);
	temp->setNext(NULL);
	return temp;
	}
	temp->setNext(NULL);
	_Raiz = NULL;
	return _Fin;
	
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
	Persona x = derecha->GetPersona(), temp;
	Nodo  *j = izquierda, *i = izquierda->GetPrev();
	while (j != derecha)
	{
		if (j == NULL)return NULL;
		if ((j->GetPersona().GetLName() + j->GetPersona().GetFName()) < (x.GetLName() + x.GetFName()))
		{
			i = (i == NULL) ? izquierda : i->GetNext();// si llegara a ser nulo se convierte en la izquierda, si no avanza un nodo.
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

void Doble::quickSort_byBrithDay(Nodo* izquierda, Nodo* derecha)
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

Nodo * Doble::_quickSort_byBrithDay(Nodo * izquierda, Nodo * derecha)
{
	Persona x = derecha->GetPersona(), temp;
	Nodo  *j = izquierda, *i = izquierda->GetPrev();
	while (j != derecha)
	{
		if (j == NULL)return NULL;
		if (j->GetPersona().GetBD(2) * 365 + j->GetPersona().GetBD(1) * 30 + j->GetPersona().GetBD(0) < x.GetBD(2) * 365 + x.GetBD(1) * 30 + x.GetBD(0))
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
	if (lugar <= 0) {
		push_front(nodo);
		return;
	}
	int pos = 0;
	Nodo* temp = _Raiz;
	while (pos != lugar)
	{
		pos++;
		temp = temp->GetNext();
		if ((temp == _Fin) && (lugar != pos)) {
			std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)\nLa persona se a agregado al final de la lista" << std::endl;
			push_back(nodo);
			return;
		}
	}
	if (temp != _Fin) {
	nodo->setNext(temp->GetNext());
	temp->setNext(nodo);
		return;
	}
		push_back(nodo);
}

void RSimple::delete_at(int lugar)
{
	if (_Raiz != NULL) {
		Nodo* temp1 = _Raiz, *temp2 = 0;
		int pos = 0;
		if (lugar < 0) {
			delete_first();
			return;
		}
		while (pos != lugar)
		{
			temp2 = temp1;
			if (temp2 == _Fin) { std::cout << "Lo siento la direccion donde quiere borrar a la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
			temp1 = temp1->GetNext();
			pos++;
		}
		if (temp1 != _Fin) {
			temp2->setNext(temp1->GetNext());
			temp1->setNext(NULL);
			delete temp1;
			return;
		}
		delete_last();
		return;
	}
	std::cout << "La lista esta vacia" << std::endl;
}


Nodo * RSimple::pop_back()
{
	if (_Raiz != NULL)
	{
		if (_Raiz != _Fin)
		{
			Nodo* temp1 = _Raiz, *temp2 = _Raiz;
			while (temp1 != _Fin)
			{
				temp2 = temp1;
				temp1 = temp1->GetNext();
			}
			temp2->setNext(NULL);
			_Fin = temp2;
			temp1->setNext(NULL);
			return temp1;
		}
		_Raiz = NULL;
		return _Fin;
	}
	std::cout << "La lista esta vacia" << std::endl;
	return NULL;
}

Nodo * RSimple::pop_front()
{
	Nodo* temp = _Raiz;
	if (temp!=_Fin)
	{
	_Raiz = _Raiz->GetNext();
	temp->setNext(NULL);
	return temp;
	}
	temp->setNext(NULL);
	_Raiz = NULL;
	return temp;
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
	int tam = size(), tam2 = size()-1;
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
	int tam = size(), tam2 = size() - 1;
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
	Nodo* temp1 = _Raiz;
	int pos = 0;
	if (lugar <= 0) {
		push_front(nodo);
		return;
	}
	while (pos != lugar)
	{
		pos++;
		temp1 = temp1->GetNext();
		if ((temp1 == _Fin) && (lugar != pos)) { 
			std::cout << "Lo siento la direccion donde quiere ingresara la persona es inexistente(Se ha sobrepasado)\nLa persona se a agregado al final de la lista" << std::endl;
			push_back(nodo);
			return;
		}
	}
	if (temp1 != _Fin) {
		nodo->setPrev(temp1);
		if (temp1->GetNext() != NULL)nodo->setNext(temp1->GetNext());
		temp1->GetNext()->setPrev(nodo);
		temp1->setNext(nodo);
		return;
	}
	push_back(nodo);
}

void RDoble::delete_at(int lugar)
{
	if (lugar < 0)
	{
		delete_first();
		return;
	}
	Nodo* temp1 = _Raiz, *temp2 = 0;
	for (int i = 0; i < lugar; i++)
	{
		temp2 = temp1;
		if (temp1==_Fin) { std::cout << "Lo siento la direccion donde quiere borrar a la persona es inexistente(Se ha sobrepasado)" << std::endl; return; }
		temp1 = temp1->GetNext();
	}
	if (temp1 == _Fin) _Fin = temp2;
	temp2->setNext(temp1->GetNext());
	temp1->GetNext()->setPrev(temp2);
	temp1->setNext(NULL);
	delete temp1;
}



Nodo * RDoble::pop_back()
{
	if (_Raiz != _Fin) {
		Nodo* temp = _Fin;
		_Fin = _Fin->GetPrev();
		_Fin->setNext(_Raiz);
		_Raiz->setPrev(_Fin);
		temp->setNext(NULL);
		return temp;
	}
	_Raiz = NULL;
	return _Fin;
}

Nodo * RDoble::pop_front()
{
	Nodo* temp = _Raiz;
	if (temp != _Fin)
	{
		_Raiz = _Raiz->GetNext();
		_Fin->setNext(_Raiz);
		_Raiz->setPrev(_Fin);
		temp->setNext(NULL);
		return temp;
	}
	temp->setNext(NULL);
	_Raiz = NULL;
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
	_Raiz->setPrev(NULL);
	_Fin->setNext(NULL);
	quickSort_byBrithDay(_Raiz, _Fin);
	_Raiz->setPrev(_Fin);
	_Fin->setNext(_Raiz);
}

void RDoble::quickSort_byBrithDay(Nodo* izquierda, Nodo* derecha)
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

Nodo * RDoble::_quickSort_byBrithDay(Nodo * izquierda, Nodo * derecha)
{
	Persona x = derecha->GetPersona(), temp;
	Nodo  *j = izquierda, *i = izquierda->GetPrev();
	while (j != derecha)
	{
		if (j == NULL)return NULL;
		if (j->GetPersona().GetBD(2)*365+ j->GetPersona().GetBD(1)*30+ j->GetPersona().GetBD(0) < x.GetBD(2)*365+ x.GetBD(1)*30+ x.GetBD(0))
		{
			i = (i == NULL) ? izquierda : i->GetNext();
			temp = i->GetPersona();
			i->setPersona(j->GetPersona());
			j->setPersona(temp);
		}
		j = j->GetNext();
	}
	i = (i == NULL) ? izquierda : i->GetNext();// 
	temp = i->GetPersona();
	i->setPersona(derecha->GetPersona());
	derecha->setPersona(temp);
	return i;
}
