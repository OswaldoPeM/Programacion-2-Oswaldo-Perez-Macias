#include<iostream>
#include <string>
bool isPair(char z) {
	switch (z)
	{
	case'2':case'4':case'6':case'8':case'0':
		return true;
	default:
		return false;
		break;
	}
}
int main() {
	std::string valor;
	while (valor!="x")
	{
	std::cout << "Introdusca numero para saber si es par\nPara cerrar precione x\n";
	std::cin >> valor;
	(isPair(valor[valor.size()-1])) ? std::cout << "\nEs par\n" : std::cout << "\nNo es par\n";
	}
	return 0;
}