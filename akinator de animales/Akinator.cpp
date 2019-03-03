#include "Akinator.h"

//retorna un booleano que decide a que lado del nodo ir, si verdadero pregunta por una opcion, si falso pregunta si o no.
bool Akinator::opc(bool x)
{
		char opc;
	if (x) {
		while (true)
		{
			std::cout << "Opcion (1) u Opcion (2)" << std::endl;
			std::cin >> opc;
			std::cin.ignore('\n');
			switch (opc) {
			case '1':return false; case '2':return true;
			}
		}
	}
	else {
		std::cout << "\nY/N\n" << std::endl;
		while (true)
		{
			std::cin >> opc;
			std::cin.ignore('\n');
			switch (opc)
			{
			case'Y':case'y':return true; case'n':case'N':return false;
			}
		}
	}
}
//retorna la raiz
Nodo * Akinator::getRaiz()
{
	return raiz;
}
//crea nuevo nodo
Nodo * Akinator::crearNodo()
{
	Nodo* nuevo = new Nodo();
	return nuevo;
}
//inserta nodo a el arbol
void Akinator::addNodo(Nodo* pos,std::string animal="")
{
	std::cin.ignore();
	pos->setIzq(crearNodo());
	*pos->getIzq() = *pos;
	std::cout << "En que animal estabas pensando?\n" << std::endl;// pregunta en que animal estas pensando
	char _str[40];
	std::cin.getline(_str, 40,'\n'); //la linea de texto introducida la convierte en animal
	animal = _str;
	animal = strSinEsp(animal);
	pos->setDer(crearNodo());
	pos->getDer()->setA1(animal);//aniade al animal nuevo
	std::cout << "Una caracteristica general que sea el animal que pensaste, que no hayamos pasado seria\n(escribe una caracteristica general) Es: " << std::endl;
	std::cin.getline(_str, 40,'\n');
	animal = _str;
	animal = strSinEsp(animal);
	pos->setA2(animal);//aniade la caracteristica que te llevaria al nuevo animal
	std::cout << " a diferencia de " << pos->getIzq()->getA1() << " que es...(escribe una caracteristica general) Es: " << std::endl;
	std::cin.getline(_str, 40,'\n');
	animal = _str;
	animal = strSinEsp(animal);
	pos->setA1(animal);// aniade la caracteristica con el anterior animal.
}
void Akinator::addNodo(Nodo * pos, std::string animal, std::string car1, std::string car2)
{
	pos->setIzq(crearNodo());
	*pos->getIzq() = *pos;
	pos->setDer(crearNodo());
	pos->getDer()->setA1(animal);
	pos->setA2(car1);
	pos->setA1(car2);
}

void Akinator::adivinar(Nodo * pos)
{
	if (pos != NULL) {
		if (pos->getDer() != NULL && pos->getIzq() != NULL) {
			std::cout << "El animal que estas pensando, es:\n(1) " << pos->getA1() << "\n(2) " << pos->getA2() << std::endl;
			if (!opc(true)) {
				adivinar(pos->getIzq());
			}
			else {
				adivinar(pos->getDer());
			}
		}
		else {
			std::cout << "Estas pensando en " << pos->getA1() << std::endl;
			if (!opc(false)) {
				addNodo(pos);
			}
			else {
				std::cout << " S U B L I M E " << std::endl;
				system("pause");
			}
		}
	}
}

std::string Akinator::strSinEsp(std::string s)
{
	for (int i = 0; i < s.size(); i++) {// cambia los espacios de espacio continuo
		if (s[i] != ' ')continue;

		s[i] = ' ';
	}
	return s;
}
// crea 3 nodos que bocetan un akinator muy sencillo pero sirvio como base para desarrollar el actual
void Akinator::arbolBase()// fue en su momento la forma de iniciar mi arbol ahora es una reliquia, que se puede decistir de ella en un proyecto mas limpio pero esta aqui para mostrar de donde viene
{
	if (this != NULL) {
		raiz = crearNodo();
		raiz->setA1("acuatico");
		raiz->setIzq(crearNodo());
		raiz->getIzq()->setA1("pez");
		raiz->setA2("terrestre");
		raiz->setDer(crearNodo());
		raiz->getDer()->setA1("gato");
	}
}

//forma actual para salvar nodos en preorden
void Akinator::saveData()
{
	std::ofstream onFile("saveData.txt");
	onFile << "";
	onFile.close();
	if (this != NULL) {
		writeOnFile(raiz);
	}
}
// carga partida de forma de pre orden
void Akinator::loadData()
{
	int x = 1;
	raiz = crearNodo();
	readInFile(raiz, x);
}

void Akinator::readInFile(Nodo * pos, int &i)
{
	if (this != NULL) {
		int j = 0;
		std::fstream inFile("saveData.txt");// abre en modo lecutra el archivo saveData
		std::string linea="",buffer="", datos[2];
		for (int j = 0; j < i; j++) {//salta lineas hasta estar en la linea del nodo que se va a introducir 
			getline(inFile, linea);
		}
		std::stringstream stream(linea);// convierte a un tipo que puede ser separado por un char en particular
		while (getline(stream, buffer, ' ')) {
			datos[j] = buffer;
			j++;
		}
		inFile.close();
		pos->setA1(datos[0]);//se asigna a1
		pos->setA2(datos[1]);//se asigna a2
		if (datos[1] != "fin") {//mientras no sea el fin hacer un recorrido de preOrden para acomodar el arbol.
			i++;
			pos->setIzq(crearNodo());
			readInFile(pos->getIzq(), i);
			i++;
			pos->setDer(crearNodo());
			readInFile(pos->getDer(), i);
		}
	}
}
//salva los nodos en post Orden
void Akinator::writeOnFile(Nodo * pos)
{
	if (pos != NULL) {
		std::ofstream onFile("saveData.txt", std::ios_base::app);
		onFile << pos->getA1() + " " + pos->getA2() + "\n";
		onFile.close();
		if (pos->getA2() != "fin") {
			writeOnFile(pos->getIzq());
			writeOnFile(pos->getDer());
		}
	}
}

Akinator::Akinator()
{
}

Akinator::Akinator(Nodo * Raiz)
{
	raiz = Raiz;
}

Akinator::~Akinator()
{
	delete raiz;
}
