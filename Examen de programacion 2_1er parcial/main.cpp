#include"Lista.h"
Persona nuevaPersona(bool listo = false) {
	Persona persona;
	Nodo nodo;
	Simple lista;
	std::string  tempstr;
	int x, fecha[3]{0,0,0};
	while (!listo)
	{
		std::cout << "introdusca apellido: ";
		std::cin >> tempstr;
		persona.setLName(tempstr); std::cout << "introdusca nombre: ";
		std::cin >> tempstr;
		persona.setName(tempstr);
		std::cout << "introdusca correo electronico: ";
		std::cin >> tempstr;
		persona.setEMail(tempstr);
		std::cout << "introdusca anio de nacimiento: ";
		std::cin >> x;
		fecha[2] = x;
		std::cout << "introdusca mes de nacimiento: ";
		std::cin >> x;
		fecha[1] = x;
		std::cout << "introdusca dia de nacimiento: ";
		std::cin >> x;
		fecha[0] = x;
		persona.setBD(fecha);
		nodo.setPersona(persona);
		listo = lista.isThis(&nodo);
	}
	return persona;
}
bool ordenA = false;
Lista* crearLista(Lista *lista) {
	ifstream inFile("inputdata.txt", ios_base::in);//Lectura del archivo
	string linea, dato, arreglo[4]; // donde se guardara cada dato
	int i = 0;
	Persona persona;
	Nodo* nodo;
	getline(inFile, linea);
	while (getline(inFile, linea)) {
		stringstream stream(linea);
		while (getline(stream, dato,','))
		{
			arreglo[i] = dato;
			i++;
		}
		i = 0;
		persona.constPersona(arreglo[0], arreglo[1], arreglo[2], arreglo[3]);
		nodo = new Nodo;
		nodo->setPersona(persona);
		lista->push_front(nodo);
	}
	std::cout << "Se a creado una lista apartir del archivo txt \"inputdata\"" << std::endl;
	return lista;
}
bool ordenB = false;
Lista* defLista(Lista* lista, char opc = '\0') {
	std::cout << "Si desea una lista Simple presione 1\nSi desea una lista Doble presione 2\nSi desea una lista Simple Enlazada presione 3\nSi desea una lista Doble enlazada presione 4\n" << std::endl;
	std::cin >> opc;
	switch (opc)
	{
	case '1':
		lista = new Simple;
		break;
	case '2':
		lista = new Doble;
		break;
	case '3':
		lista = new RSimple;
		break;
	case '4':
		lista = new RDoble;
		break;
	default:
		system("cls");
		std::cout << "\nNo has seleccionado ningun tipo de lista!\n" << std::endl;
		lista = defLista(lista);
		break;
	}
	return lista;
}
void sort(Lista* lista, char opc = '\0', bool listo = false) {
	if (lista->GetRaiz() != NULL) {
		while (!listo)
		{
			system("cls");
			std::cout << "\nPresiona 1 para ordenar por orden alfabetico\nPresione 2 para ordenar por fecha de nacimiento" << std::endl;
			std::cin >> opc;
			switch (opc)
			{
			case'1':
				if (!ordenA)
				{
				lista->sortByName();
				ordenA = true;
				ordenB = false;
				}
				listo = true;
				break;
			case'2':
				if (!ordenB)
				{
				lista->sortByBrithDay();
				ordenB = true;
				ordenA = false;
				}
				listo = true;
				break;
			default:
				break;
			}
		}
		return;
	}
	std::cout << "\n\nLista vacia\n" << std::endl;
}

void add(Lista* lista, char opc = '\0', bool listo = false) {

	Persona persona = nuevaPersona();
	Nodo* nodo = new Nodo;
	int x = 0;
	nodo->setPersona(persona);
	while (!listo)
	{
		system("cls");
		std::cout << "\nPresiona 1 para agregar al principio de la lista \nPresione 2 para agregar al final de la lista\nPara 3 para agregar en un punto especifico de la lista\n" << std::endl;
		std::cin >> opc;
		switch (opc)
		{
		case'1':
			lista->push_front(nodo);
			listo = true;
			break;
		case'2':
			lista->push_back(nodo);
			listo = true;
			break;
		case'3':
			if (lista->GetRaiz() != NULL) {
				std::cout << "Introdusca el indice donde agregar a la persona" << std::endl;
				std::cin >> x;
				lista->insert_at(nodo, x - 1);
				return;
			}
			std::cout << "Esta lista esta vacia, por lo que esta persona sera afregada automaticamente" << std::endl;
			lista->push_front(nodo);

			listo = true;
			break;
		default:
			break;
		}
	}
}
void find(Lista* lista, char opc = '\0', bool listo = false) {
	if (lista->GetRaiz() != NULL) {
		system("cls");
		std::string nombre = "", apellido = "";
		system("cls");
		std::cout << "introdusca apellido: ";
		std::cin >> apellido;
		std::cout << "introdusca nombre: ";
		std::cin >> nombre;
		lista->FindByName(nombre, apellido);
		return;
	}
	std::cout << "\n\nLista vacia\n";

}
void subb(Lista*lista, char opc = '\0',bool listo=false) {
	int x;
	if (lista->GetRaiz() != NULL) {
		while (!listo)
		{
			system("cls");
			std::cout << "\nPresiona 1 para eliminar al principio de la lista \nPresione 2 para eliminar al final de la lista\nPara 3 para eliminar en un punto especifico de la lista\nPresione 0 para regresar al menu principal" << std::endl;
			std::cin >> opc;
			switch (opc)
			{
			case'1':
				lista->delete_first();
				listo = true;
				break;
			case'2':
				lista->delete_last();
				listo = true;
				break;
			case'3':
				std::cout << "Introdusca el indice donde eliminar a la persona" << std::endl;
				std::cin >> x;
				lista->delete_at(x-1);
				listo = true;
				break;
			case'0':
				return;
			default:
				break;
			}
		}
		return;
	}
	std::cout << "\n\nLista vacia\n" << std::endl;
}
void popedpersona(Lista* lista, Nodo* pop, char opc = '\0', bool listo = false) {
	pop->setPrev(NULL);
	int x = 0;
	while (!listo)
	{
		system("cls");
		std::cout << "Presione 1 para agregar a esta persona al principio de la lista\nPresione 2 para agregar esta persona al final de la lista\nPresione 3 para agregar a esta persona en un indice\nPresione 4 para borrar persona\nPresione 0 para volver al menu anterior" << std::endl;
		std::cin >> opc;
		switch (opc)
		{
		case'1':
			lista->push_front(pop);
			listo = true;
			break;
		case'2':
			lista->push_back(pop);
			listo = true;
			break;
		case'3':
			if (lista->GetRaiz() != NULL) {
				std::cout << "Introdusca el indice donde agregar a la persona" << std::endl;
				std::cin >> x;
				lista->insert_at(pop, x - 1);
				return;
			}
			std::cout << "Esta lista esta vacia, por lo que esta persona sera afregada automaticamente" << std::endl;
			lista->push_front(pop);
			listo = true;
			break;
		case'4':
			pop->setNext(NULL);
			delete pop;
			listo = true;
			break;
		case'0':
			return;
		default:
			break;
		}
	}
}

void pop(Lista* lista,char opc='\0',bool listo=false) {
	Nodo* pop = NULL;
	if (lista->GetRaiz() != NULL) {
		while (!listo)
		{
			system("cls");
			std::cout << "Presione 1 para extraer a la primera persona de la lista\nPresione 2 para extraer la ultima persona de la lista\nPresione 3 para regresar al menu anterior\n" << std::endl;
			std::cin >> opc;
			switch (opc)
			{
			case'1':
				pop = lista->pop_front();
				popedpersona(lista,pop);
				listo = true;
				break;
			case'2':
				pop = lista->pop_back();
				popedpersona(lista,pop);
				listo = true;
				break;
			case'3':
				listo = true;
			default:
				break;
			}
		}
		return;
	}
	std::cout << "\n\nLista vacia\n" << std::endl;

}
void menu(Lista* lista, char opc='\0') {
	while (opc!='0') {
		system("pause");
		system("cls");
		std::cout << "Que desea hacer?\nPresiona 1 si desea saber el tamaño de la lista\nPresiona 2 si quiere ordenar la lista\nPresione 3 para agregar una persona nueva a la lista\nPresiona 4 si desea saber la ubicacion de alguna persona\nPresione 5 si desea Imprimir la lista\nPresione 6 si lo que desea es eliminar a una persona de la lista\nPresiona 7 para vaciar la lista\nPresione 8 para crear una nueva lista\nPresione 9 si quiere extraer una persona de la lista\nPresiona 0 para cerrar el programa" << std::endl;
		std::cin >> opc;
		switch (opc)
		{
		case'1':
			std::cout << "El tamanio de la lista es: " << lista->size() << std::endl;
			break;
		case'2':
			sort(lista);
			break;
		case'3':
			add(lista);
			break;
		case'4':
			find(lista);
			break;
		case'5':
			lista->print();
			break;
		case'6':
			subb(lista);
			break;
		case'7':
			lista->clear();
			ordenA = false;
			ordenB = false;
			break;
		case'8':
			delete lista;
			lista = NULL;
			lista = defLista(lista);
			crearLista(lista);
			ordenA = false;
			ordenB = false;
			break;
		case'9':
			pop(lista);
			break;
		default:
			std::cout << "\nNo has seleccionado ninguna accion valida" << std::endl;
			break;
		}
	}
}
int main() {
	Lista *lista=NULL;
	lista=defLista(lista);
	crearLista(lista);
	menu(lista);

	delete lista;

	return 0;
}