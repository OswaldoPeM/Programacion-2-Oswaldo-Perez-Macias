#include<iostream>
#include<string>
struct Nodo
{
	int dato;
	Nodo* der;
	Nodo* izq;
};
void destructor(Nodo *arbol) {
	
	if (arbol->izq != NULL) { destructor(arbol->izq); }
	if (arbol->der != NULL) { destructor(arbol->der); }
	if(arbol->der == NULL && arbol->izq == NULL) {
		delete arbol;
		arbol = NULL;
		return;
	}
}
Nodo* crearNod(int valor) {
	Nodo* nodo = new Nodo;
	nodo->dato = valor;
	nodo->der = NULL;
	nodo->izq = NULL;
	return nodo;
}
void addData(Nodo* Arbol, int valor) {

	if (Arbol->dato >= valor) {
		if (Arbol->izq != NULL)addData(Arbol->izq, valor);
		else { Arbol->izq = crearNod(valor); }
	}
	if (Arbol->dato < valor) {
		if (Arbol->der != NULL)addData(Arbol->der, valor);
		else { Arbol->der = crearNod(valor); }
	}

}
void setData(Nodo* arbol,int valor=0) {
	std::cout << "Introdusca un entero\n";
	std::cin >> valor;
	addData(arbol, valor);
}
void printArbol(Nodo* arbol, std::string x) {
	if (arbol != NULL) {
		printArbol(arbol->izq, x + "   ");
		std::cout << x << arbol->dato << "\n";
		printArbol(arbol->der, x + "   ");
	}
}
int main(){
	Nodo* arbol = NULL;
	char opc = '\0';
	std::cout << "Vamos a crear un arbol binario\n\nIntroduce el dato entero de la raiz\n";
	int x;
	std::cin >> x;
	arbol = crearNod(x);
	while (opc!='x')
	{
		std::cout << "Presiona 1 para agregar un nuevo entero al arbol\nPresiona x para salir y destruir el arbol\n";
		std::cin >> opc;
		if (opc == '1')setData(arbol);
	}
	printArbol(arbol,"");
	destructor(arbol);
	system("pause");
	return 0;
}
