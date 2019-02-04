#include"Lista.h"

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
	return lista;
}
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
void menu(Lista* lista) {
	lista->print();
	lista->sortByName();
	lista->print();
}
int main() {
	Lista *lista=NULL;
	lista=defLista(lista);
	crearLista(lista);
	menu(lista);

	delete lista;

	return 0;
}