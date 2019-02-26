#include"akinumeros.h"

int main() {
	Akinumero* arbol = new Akinumero();
	int x = 0, y = 0;
	std::cout << "introduce un numero para agregar al arbol presiona enter para introducir: ";
	while (std::cin >> x)
	{
		system("cls");
	arbol->print(arbol->getRaiz(), "");
		std::cout << "Introduce otro numero\nPara cerrar programa introdusca un caracter\n ";
		arbol->addNodo(arbol->getRaiz(), x);
		y = arbol->peso(arbol->getRaiz());
	}
	std::cout << "El peso del arbol es de " << y << std::endl;
	delete arbol;
	system("pause");
	return 0;
}