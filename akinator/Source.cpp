#include"Akinator.h"
using namespace std;

int main() {
	Akinator* akinator = new Akinator();
	bool jugar = true;
 	akinator->arbolBase();
	akinator->crearArbol(akinator->getRaiz());
	while (jugar) {
		akinator->adivinar(akinator->getRaiz());
		akinator->salvarNodo();
		akinator->saveData();
		system("cls");
		cout << "Quieres seguir jugando ?";
		if (akinator->opc(false)) {
			continue;
		}
		else {
			jugar = false;
		}
	}
	delete akinator;
	system("pause");
	return 0;
}