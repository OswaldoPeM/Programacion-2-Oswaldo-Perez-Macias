#include"Akinator.h"
using namespace std;

int main() {
	Akinator* akinator = new Akinator();
	bool jugar = true;
	akinator->loadData();
	while (jugar) {
		akinator->adivinar(akinator->getRaiz());
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