#include"akinumeros.h"

int main() {
	Akinumero* arbol = new Akinumero();
	int x = 0, y = 0;
	std::cout << "Introduce un numero entero para agregar al arbol presiona enter para introducir: ";
	while (std::cin >> x)
	{
		arbol->addNodo(arbol->getRaiz(), x);//aniade enteros al arbol
		system("cls");//limpia la bantalla
		y = arbol->peso(arbol->getRaiz());//al mismo tiempo que  balancea el arbol regresa el peso del arbol, la profundiad que tiene
		arbol->print(arbol->getRaiz(), "");//imprime el arbol
		std::cout << "\nIntroduce otro numero\nPara cerrar programa introdusca un caracter\n ";//pide en cosola un numero.
	}
	std::cout << "\nEl peso del arbol es de " << y << std::endl;
	delete arbol;
	system("pause");
	return 0;
}