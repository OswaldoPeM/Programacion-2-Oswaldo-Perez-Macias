#include"Grafo.h"
//crea el grafo
Grafo* creadorGrafo(Grafo* grafo) {
	std::string nombre = "";
	std::cout << "\nIngresa el nombre del archivo te texto que quieres abrir\n";
	std::cin >> nombre;
	std::cin.ignore(250, '\n');
	grafo = new Grafo();
	if (grafo->interprete(nombre)) {
		delete grafo;
		grafo = new GrafoCord(nombre);
	}
	if (grafo->getNodoSize() == 0) {
		delete grafo;
		grafo = NULL;
	}
	return  grafo;
}
//hace una busqueda de amplitud
void amplitud(Grafo* grafo) {
	std::string nombre = "",fin="";
	std::cout << "\nIngresa el nombre del nodo del que quieres partir\n";
	std::cin >> nombre;
	std::cin.ignore( 250, '\n');
	std::cout << "\nIngresa el nombre del nodo al que quieres llegar\n";
	std::cin >> fin;
	std::cin.ignore(250, '\n');
	grafo->amplitud(nombre,fin);
}
//hace  una busqueda de profundidad
void profundidad(Grafo* grafo) {
	std::string nombre ="",fin="";
	std::cout << "\nIngresa el nombre del nodo del que quieres partir\n";
	std::cin >> nombre;
	std::cin.ignore(250, '\n');
	std::cout << "\nIngresa el nombre del nodo al que quieres llegar\n";
	std::cin >> fin;
	std::cin.ignore(250, '\n');
	grafo->profund(nombre,fin);
}
//hace una busqueda de primero el mejor
void primeroMejor(Grafo* grafo) {
	std::string raiz = "", objetivo = "", fac = "";
	int x = 0, y = 0;
	std::cout << "\nIngresa el nombre del nodo del que quieres partir\n";
	std::cin >> raiz;
	std::cin.ignore(250, '\n');
	std::cout << "\nIngresa el nombre del nodo al que quieres llegar\n";
	std::cin >> objetivo;
	std::cin.ignore(250, '\n');
	std::cout << "\nIngresa el 'p' o 'd' en funcion de lo que quieres que sea tomado en cuenta\n'p'para el peligro o precio,'d' para distancia\npor defecto se escojera la distancia";
	std::cin >> fac;
	std::cin.ignore(250, '\n');
	switch (fac[0])
	{
	case'd':
	case'D':
		y = 1;
		break;
	case'p':
	case'P':
	default:
		x = 1;
		break;
	}
	grafo->primeroMejor(raiz, objetivo, x, y);
}
//hace una corrida de dijkstra
void dijkstra(Grafo* grafo) {
	std::string nombre = "";
	int x = 1, y = 1;
	std::cout << "\nIngresa el nombre del nodo del que quieres partir\n";
	std::cin >> nombre;
	std::cin.ignore(250, '\n');
	grafo->dijkstra(nombre, x, y);
}

void Astar(Grafo* grafo) {
	std::string raiz = "", objetivo = "";
	int x = 1, y = 1;
	std::cout << "\nIngresa el nombre del nodo del que quieres partir\n";
	std::cin >> raiz;
	std::cin.ignore(250, '\n');
	std::cout << "\nIngresa el nombre del nodo al que quieres llegar\n";
	std::cin >> objetivo;
	std::cin.ignore(250, '\n');
	std::cout << "Ingresa el nivel de importancia de el Precio o Peligro en valores enteros: ";
	std::cin >> x;
	std::cin.ignore(250, '\n');
	std::cout << "Ingresa el nivel de importancia de la distancia en valores enteros: ";
	std::cin >> y;
	std::cin.ignore(250, '\n');
	grafo->AStar(raiz, objetivo, x, y);
}
Grafo* borrarGrafo(Grafo* grafo) {
	delete grafo;
	grafo = NULL;
	return grafo;
}
void pathFinder() {
	Grafo *grafo=nullptr;
	std::string opc="";
	
	while (opc != "salir")
	{
 		while (grafo == NULL  ) {

			grafo = creadorGrafo(grafo); 
				if (grafo==NULL) {
					system("pause");
					system("cls");
					std::cout << "\nIngrese 'salir' para salir del programa o cualquier otra tecla para continuar\n";
					std::cin >> opc;
					std::cin.ignore(250, '\n');
					if (opc == "salir")break;
				}
		}
		while (grafo != NULL) {
			std::cout << std::endl;
			system("pause");
			system("cls");
			std::cout << "\nIngresa 1 para busqueda de amplitud\nIngresa 2 para busqueda de profundidad\n";
			std::cout<<"Ingresa 3 para hacer primero mejor\nIngrese 4 para ejecutar Dijkstra\n";
			std::cout << "Ingresar 5 para A Estrella\nIngresar 6 para borrar grafo y volver a ingresar otro\n";
			std::cout << "Ingrese \"salir\" para salir del programa\n";
			std::cin >> opc;
			std::cin.ignore(250, '\n');

			switch (opc[0])
			{
			case '1':
				amplitud(grafo);
				break;
			case'2':
				profundidad(grafo);
				break;
			case'3':
				primeroMejor(grafo);
				break;
			case'4':
				dijkstra(grafo);
				break;
			case'5':
				Astar(grafo);
				break;
			case'6':
				grafo = borrarGrafo(grafo);
			default:
				break;
			}
			if (opc == "salir") {
				grafo = borrarGrafo(grafo);
			}
		}
	}
}
int main() {
	pathFinder();

	return 0;
}