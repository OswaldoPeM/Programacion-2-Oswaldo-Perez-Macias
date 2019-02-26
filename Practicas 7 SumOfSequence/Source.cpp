#include<iostream>
#include<string>
//si existe una una manera de llegar de star a end con aumentos de step, te devuelve una suma de todos esos pasos incluyendo start y end. si no es posible devuelve un 0
int sequenceSum(int start, int end, int step)
{
	if (start > end) return 0;

	int loops = (end - start) / step;
	return start * (loops + 1) + step * (loops * loops + loops) / 2;
}

int main() {
	std::string ciclo;
	int start, end, step,x;
	while (ciclo != "x"){

		std::cout << "introdusca start, end y step en ese orden\n";
	    std::cin >>start;
		std::cin >> end;
		std::cin >> step;
		std::cout << "\nEl resultado es: " << sequenceSum(start, end, step) << "\nsi quiere salir del programa presione 'x', si quiere seguir jugando introdusca cualquier caracter\n";
		std::getline(std::cin, ciclo);
		std::cin.ignore(256, '\n');// si se introduce una linea con espcacios ignorara todo y solo tomara el primer string, y los demas no.
	}
	return 0;
}