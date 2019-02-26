#include <iostream>
int porDiez(int x) {
	return (x << 1) + (x << 3);
}
int main(){
	int x;
	std::cout << "Introduce un numero del cual quieres multiplicar por 10: ";
	while (std::cin >> x)
	{
		std::cout << porDiez(x) << std::endl;
		std::cout << "Para salir precione alguna letra\nIntroduce un numero del cual quieres multiplicar por 10: ";
	}
	return 0;
}