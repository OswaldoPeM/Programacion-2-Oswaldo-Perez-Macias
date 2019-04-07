#include"Grafo.h"

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


void amplitud(Grafo* grafo) {
	std::string nombre = "";
	std::cout << "\nIngresa el nombre del nodo del que quieres partir\n";
	std::cin >> nombre;
	std::cin.ignore( 250, '\n');
	grafo->amplitud(nombre);
}

void profundidad(Grafo* grafo) {
	std::string nombre ="";
	std::cout << "\nIngresa el nombre del nodo del que quieres partir\n";
	std::cin >> nombre;
	std::cin.ignore(250, '\n');
	grafo->profund(nombre);
}

void primeroMejor(Grafo* grafo) {
	std::string raiz = "", objetivo = "", fac = "";
	int x = 0, y = 0;
	std::cout << "\nIngresa el nombre del nodo del que quieres partir\n";
	std::cin >> raiz;
	std::cin.ignore(250, '\n');
	std::cout << "\nIngresa el nombre del nodo al que quieres llegar\n";
	std::cin >> objetivo;
	std::cin.ignore(250, '\n');
	while (fac[0]=='p'| fac[0] == 'P'| fac[0] == 'd'| fac[0] == 'D')
	{
		std::cout << "\nSi prefieres ponderar el peligro sobre la distancia ingresa 'p'\nDe manera contraria si prefieres ponderar la distancia sobre el peligro ingresa 'd'\n ";
		std::cin >> fac;
		std::cin.ignore(250, '\n');
		switch (fac[0])
		{
		case'p':
		case'P':
			x++;
			break;
		case 'd':
		case'D':
			y++;
			break;
			
		default:
			std::cout << "si quieres regresar al menu principal y probar una busqueda que tome en cuenta ambos factores te recomiendo el A Estrella\nPara salir ingrese 'salir'\n";
			std::cin >> fac;
			std::cin.ignore(250, '\n');
		case's':
		case'S':
			return;
		}

	}
	grafo->primeroMejor(raiz, objetivo, x, y);
}

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
	grafo->AStar(raiz, objetivo, x, y);
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
		while (grafo != NULL && opc!= "salir" ) {
			std::cout << std::endl;
			system("pause");
			system("cls");
			std::cout << "\nIngresa 1 para busqueda de amplitud\nIngresa 2 para busqueda de profundidad\n";
			std::cout<<"Ingresa 3 para hacer primero mejor\nIngrese 4 para ejecutar Dijkstra\n";
			std::cout << "Ingresar 5 para A Estrella\n";
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
			default:
				break;
			}
		}

	}
	delete grafo;
}
int main() {
	pathFinder();

	return 0;
}