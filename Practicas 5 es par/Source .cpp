#include <iostream>
int main(){
	int x;
	std::cout << "Introduce un numero del cual quieres saber si es par: ";
	while (std::cin >> x)
	{
		(x & 1) ? std::cout << "No es par.\nPara dejar de preguntar, introdusca un caracter\ncaso contrario siga introduciendo numero" : std::cout << "Es par.\nPara dejar de preguntar, introdusca un caracter\ncaso contrario siga introduciendo numero";
	}
	return 0;
}
