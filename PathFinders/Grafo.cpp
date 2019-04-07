#include "Grafo.h"



Grafo::Grafo()
{
}


Grafo::~Grafo()
{
	if( _nodos!=nullptr){
	    delete[] _nodos;
	}
	if (_arista != nullptr) {
		delete[] _arista;
	}
}

void Grafo::matCordCSV(std::string matriz)
{
	std::ifstream *mat = new std::ifstream(matriz + ".csv");
	int i = 0, j = 0, k = 0, x = 0;
	std::string buffer = "", eti = "";
	std::stringstream stream;
	std::getline(*mat, buffer);
	stream = std::stringstream(buffer);
	while (std::getline(stream,eti,','))
	{
		x++;
	}
	_nodoSize = x;
	_nodos = new Nodos[_nodoSize];
	std::getline(*mat, buffer);
	std::getline(*mat, buffer);
	std::getline(*mat, buffer);
	while (std::getline(*mat, buffer)) {
		stream = std::stringstream(buffer);
		while (std::getline(stream, eti, ',')) {
			if (eti[0] != '-')j++;
		}
	}
	_aristaSize = j;
	_arista = new Arista[_aristaSize];
	mat->close();
	x = 0;
	j = 0;
	*mat = std::ifstream(matriz + ".csv");
	std::getline(*mat, buffer);
	stream = std::stringstream(buffer);
	while (std::getline(stream, eti, ','))
	{
		_nodos[x++].setCodigo(eti);
	}
	std::getline(*mat, buffer);
	stream = std::stringstream(buffer);
	x = 0;
	while (std::getline(stream, eti, ','))
	{
		_nodos[x++].setEti(eti);
	}
	std::getline(*mat, buffer);
	stream = std::stringstream(buffer);
	x = 0;
	while (std::getline(stream, eti, ','))
	{
		_nodos[x++].setCordX(eti);
	}
	std::getline(*mat, buffer);
	stream = std::stringstream(buffer);
	x = 0;
	while (std::getline(stream, eti, ','))
	{
		_nodos[x++].setCordY(eti);
	}
	x = 0;
	while (std::getline(*mat, buffer))
	{
		stream = std::stringstream(buffer);
		while (std::getline(stream, eti, ','))
		{
			if (eti[0] != '-')_arista[x++]=Arista(&_nodos[j],&_nodos[i]);
		}
	}
}

void Grafo::matCordS(std::string &matriz)
{
	std::vector<Arista>* aristas=new std::vector<Arista>;
	std::fstream* mat = new std::fstream(matriz + ".txt");
	std::string buffer, eti = "", temp = "";
	std::stringstream stream, nombre;
	int  i = 0;
	float alcance = 0;
	std::cout << "Para este tipo de matriz te pido que me digas cual es el alcance que tienes al dar un paso\n";
	std::cout << "(saber que tan lejos tiene que estar un nodo alineado en el eje x o y para saber el alcance)\n";


	std::cout << "Porfavor ingrese un entero o flotante: ";
	std::cin >> buffer;
	std::cin.ignore(250, '\n');
	alcance = std::strtof((buffer).c_str(), 0);

	std::getline(*mat, buffer);
	stream = std::stringstream(buffer);
	while (std::getline(stream, eti, ','))
	{
		_nodoSize++;
	}
	mat->close();
	delete mat;
	mat = new std::fstream(matriz + ".txt");
	std::getline(*mat, buffer);
	_nodos = new Nodos[_nodoSize];
	stream = std::stringstream(buffer);
	while (std::getline(stream, eti, ','))
	{
		nombre = std::stringstream(eti);
		std::getline(nombre, temp, '|');
		_nodos[i].setEti(temp);
		std::getline(nombre, temp, ':');
		std::getline(nombre, eti);
		_nodos[i].setCords(temp, eti);
		i++;
	}

	for (int i = 0; i < _nodoSize; i++)
	{
		for (int j = 0; j < _nodoSize; j++)
		{
			if (i != j) {
				if ((_nodos[j].getCord('x') - _nodos[i].getCord('x')) <= alcance && (_nodos[j].getCord('x') - _nodos[i].getCord('x'))>0 && _nodos[i].getCord('y')== _nodos[j].getCord('y')) {
					aristas->push_back(Arista(&_nodos[i], &_nodos[j], _nodos[j].getCord('x') - _nodos[i].getCord('x')));
					aristas->push_back(Arista(&_nodos[j], &_nodos[i], _nodos[j].getCord('x') - _nodos[i].getCord('x')));
				}

				if ((_nodos[j].getCord('y') - _nodos[i].getCord('y')) <= alcance && (_nodos[j].getCord('y') - _nodos[i].getCord('y'))> 0 && _nodos[i].getCord('x') == _nodos[j].getCord('x')) {
					aristas->push_back(Arista(&_nodos[i], &_nodos[j], _nodos[j].getCord('y') - _nodos[i].getCord('y')));
					aristas->push_back(Arista(&_nodos[j], &_nodos[i], _nodos[j].getCord('y') - _nodos[i].getCord('y')));
				}
			}
		}
	}
	_aristaSize = aristas->size();
	_arista = new Arista[_aristaSize];
	for (int i = 0; i < aristas->size(); i++)
	{
		_arista[i] = aristas[0][i];
	}
	mat->close();
	delete mat;
	delete aristas;
}

void Grafo::matAdy(std::string &matriz)
{
	std::fstream* mat = new std::fstream(matriz+".txt");
	std::string buffer, eti;
	std::stringstream stream;
	std::getline(*mat, buffer);
	int j = 0, k = 0, x = 0;
	for (int i = 0; i < buffer.size(); i++)
	{
		if (buffer[i] == ',') _nodoSize++;
	}
	_nodos = new Nodos[++_nodoSize];
	stream = std::stringstream(buffer);

	while (std::getline(stream, eti, ','))
	{
		_nodos[j++].setEti(eti);
	}
	while (std::getline(*mat, buffer))
	{
		stream = std::stringstream(buffer);
		while (std::getline(stream, eti, ','))
		{
			if (eti != "0") x++;
		}
		
	}
	_aristaSize = x;
	_arista = new Arista[_aristaSize];
	mat->close();
	*mat = std::fstream(matriz + ".txt");
	std::getline(*mat, buffer);
	j = 0;
	x = 0;

	while (std::getline(*mat, buffer)) {
		k = 0;
		stream = std::stringstream(buffer);
		while (std::getline(stream, eti, ','))
		{
			if (eti != "0") (_arista[x++]) =  Arista(&_nodos[j], &_nodos[k], eti);
			k++;
		}
		j++;
	}
	mat->close();
	delete mat;
}

void Grafo::imprimirCamino(NodoViajero *camino)
{
	std::string pasos = "";
	while (camino != nullptr) {
		pasos = " " + camino->getEti() + " - " + pasos;
		camino = camino->getAnterior();
	}
	pasos[pasos.size() - 2] = '*';
	std::cout << "\nEl mejor camino fue " << pasos << std::endl;
}

void Grafo::sortVec(std::vector<NodoViajero*>* lista, int der, int izq)
{
	int i = izq, j = der;
	float p = lista[0][der]->getCosto();
	NodoViajero *temp;
	while (i <= j) {
		while (lista[0][i]->getCosto() < p)i++;
		while (lista[0][j]->getCosto() > p)j--;
		if (i <= j) {
			temp = lista[0][i];
			lista[0][i] = lista[0][j];
			lista[0][j] = temp;
			i++;
			j--;
		}
	}
	if (izq < j) sortVec(lista, j, izq);
	if (der > i) sortVec(lista, der, i);
}

Nodos * Grafo::getNodos()
{
	return _nodos;
}

Arista * Grafo::getArista()
{
	return _arista;
}

int Grafo::getNodoSize()
{
	return _nodoSize;
}

int Grafo::getAristaSize()
{
	return _aristaSize;
}
bool Grafo::interprete(std::string &matriz)
{
	std::ifstream *mat= new std::ifstream(matriz + ".txt");
	if (!*mat) {
		*mat = std::ifstream(matriz + ".csv");
		if (!*mat) {
			return false;
		}
		mat->close();
		delete mat;
		return true;
	}
	std::string buffer;
	while (std::getline(*mat, buffer))
	{
		switch (buffer[1])
		{
		case',':
			mat->close();
			delete mat;
			matAdy(matriz);
			return false;
		case'|':
			mat->close();
			delete mat;
			return true;
		default:
			break;
		}
	}

	mat->close();
	delete mat;
	return false;
}
void Grafo::matCordCons(std::string & matriz)
{
	std::ifstream *mat = new std::ifstream(matriz + ".txt");
	matCordS(matriz);
}
//hace busqueda de profundidad
void Grafo::profund(std::string &inicio)
{
	bool hay;
	std::vector<Nodos*> abiertos,cerrados;
	for (int i = 0; i < _nodoSize; i++)
	{
		if (_nodos[i].getEti() != inicio) continue;
		abiertos.push_back(&_nodos[i]);
	}
	if (abiertos.empty()) {
		std::cout << "\nNo se encontro el nodo de origen.\n";
		return;
	}
	while (!abiertos.empty()) {
		cerrados.push_back(abiertos[abiertos.size() - 1]);
		std::cout << cerrados[cerrados.size() - 1]->getEti() << " ";
		for (int i = abiertos.size() - 1; i > -1; i--)
		{
			if (cerrados[cerrados.size() - 1] == abiertos[i]) {
				abiertos.erase(abiertos.begin() + i);
			}
		}
		for (int i = 0; i < _aristaSize; i++)
		{
			hay = true;
			if (_arista[i].getOr() == cerrados[cerrados.size() - 1]) {
				for (unsigned int j = 0; j < cerrados.size(); j++)
				{
					if (!hay) break;
					hay = (_arista[i].getDe() == cerrados[j]) ? false : true;
				}
				if (hay) {
					abiertos.push_back(_arista[i].getDe());
				}
			}
		}
	}
}
//Hace un busqueda de amplitud.
void Grafo::amplitud(std::string &inicio)
{
	bool hay;
	std::vector<Nodos*> abiertos, cerrados;
	for (int i = 0; i < _nodoSize; i++)
	{
		if (_nodos[i].getEti() != inicio) continue;
		abiertos.push_back(&_nodos[i]);
	}
	if (abiertos.empty()) {
		std::cout << "\nNo se encontro el nodo de origen.\n";
		return;
	}
	while (!abiertos.empty())
	{
		cerrados.push_back(abiertos[0]);
		std::cout << cerrados[cerrados.size() - 1]->getEti() << " ";
		for (int i = abiertos.size() - 1; i > -1; i--)
		{
			if (cerrados[cerrados.size() - 1] == abiertos[i]) {
				abiertos.erase(abiertos.begin() + i);
			}
		}
		for (int i = 0; i < _aristaSize; i++)
		{
			hay = true;
			if (_arista[i].getOr() == cerrados[cerrados.size() - 1]) {
				for (int j = 0; j < cerrados.size(); j++)
				{
					if (_arista[i].getDe() == cerrados[j]) hay = false;
					if (!hay) break;
				}
				if (hay)abiertos.push_back(_arista[i].getDe());
			}
		}

	}
}
//realiza una busqueda  primero el mejor.
void Grafo::primeroMejor(std::string &inicio, std::string &objetivo, int &facP, int &facD)
{
	std::vector<NodoViajero*>*abiertos = new std::vector<NodoViajero*>, *cerrados = new std::vector<NodoViajero*>;
	bool hay;
	int max = 0, min = 0;
	while (min< _nodoSize)
	{
		if (_nodos[min].getEti() != inicio) { 
			min++;
			continue; }
		abiertos->push_back(new NodoViajero(&_nodos[min++]));

	}
	if (abiertos->empty()) {
		std::cout << "\nNo se encontro el nodo de origen.\n";
		return;
	}
	while (!abiertos->empty())
	{
		cerrados->push_back(abiertos[0][0]);
		abiertos->erase(abiertos->begin());
		for (int i = 0; i < _aristaSize; i++)
		{
			hay = true;
			if (cerrados[0][cerrados->size() - 1]->getActual()->getEti() == objetivo) {
				continue;
			}
			if (cerrados[0][cerrados->size() - 1]->getActual() == _arista[i].getOr()) {
				if (cerrados[0][cerrados->size() - 1]->getAnterior() != nullptr) {
					if (cerrados[0][cerrados->size() - 1]->getAnterior()->getActual() == _arista[i].getDe()) {
						continue;
					}
				}
				for (int j = 0; j < abiertos->size(); j++)
				{
					if (abiertos[0][j]->getActual() == _arista[i].getDe() && abiertos[0][j]->getAnterior()->getActual() == _arista[i].getOr()) hay = false;
				}
				for (int j = 1; j < cerrados->size(); j++)
				{
					if (cerrados[0][j]->getActual() == _arista[i].getDe() && cerrados[0][j]->getAnterior()->getActual() == _arista[i].getOr()) hay = false;
				}
				if (hay)abiertos->push_back(new NodoViajero(_arista[i].getDe(), cerrados[0][cerrados->size() - 1], _arista[i].getDe()->getCosto(), _arista[i].getDi(), facP, facD));
			}
		}
		if (abiertos->size() > 0) {
			max = abiertos->size() - 1;
			min = 0;
			sortVec(abiertos, max, min);
		}
	}
	if (cerrados->size() > 0) {
		max = cerrados->size() - 1;
		min = 0;
		sortVec(cerrados, max, min);
	}
	for (int i = 0; i <= cerrados->size(); i++)
	{
		if (i == cerrados->size()) {
			std::cout << "\nImposible llegar al nodo objetivo\n";
			break;
		}
		if (cerrados[0][i]->getActual()->getEti() == objetivo) {
			imprimirCamino(cerrados[0][i]);
			break;
		}
	}
	for (int i = 0; i < abiertos->size(); i++)
	{
		delete abiertos[0][i];
	}
	for (int i = 0; i < cerrados->size(); i++)
	{
		delete cerrados[0][i];
	}
	delete abiertos;
	delete cerrados;
}

void Grafo::dijkstra(std::string &inicio, int &facP, int &facD)
{
	std::vector<NodoViajero*>* abiertos = new std::vector<NodoViajero*>, *cerrados = new std::vector<NodoViajero*>;
	int max = 0, min = 0;
	for (int i = 0; i < _nodoSize; i++)// crea un vector lleno de caminos de costo infinto, exepto por el nodo raiz que valdra 0
	{
		if (_nodos[i].getEti() == inicio) {
			abiertos->push_back(new NodoViajero(&_nodos[i], 0));	
			min++;
		}
		else {
			abiertos->push_back(new NodoViajero(&_nodos[i], FLT_MAX));
		}
	}
	if (min < 1) {
		std::cout << "\nNo existe el nodo raiz\n";
		return;
	}
	while (!abiertos->empty())//mientras la lista de abiertos no este vacia 
	{
		if (abiertos->size() > 1) {
			max = abiertos->size() - 1;
			min = 0;
			sortVec(abiertos, max, min);
		}
		cerrados->push_back(abiertos[0][0]);
		abiertos->erase(abiertos->begin());
		for (int i = 0; i < _aristaSize; i++)
		{
			if (cerrados[0][cerrados->size() - 1]->getActual() == _arista[i].getOr()) {//mientras el nodo a cerrar sea el origen evaluar el destino
				for (int j = 0; j < abiertos->size(); j++)
				{
					if ((abiertos[0][j]->getActual() == _arista[i].getDe()) && (abiertos[0][j]->getCosto() > (_arista[i].getDi() * (_arista[i].getDe()->getCosto())))) {// si son iguales y de menor camino cambia
						if (abiertos[0][j]->getCosto() < NodoViajero( _arista[i].getDe(), cerrados[0][cerrados->size() - 1], _arista[i].getDe()->getCosto(), _arista[i].getDi(),facP,facD).getCosto()) break;
						*abiertos[0][j] =  NodoViajero(_arista[i].getDe(), cerrados[0][cerrados->size() - 1], _arista[i].getDe()->getCosto(), _arista[i].getDi(), facP, facD);
						break;//intercambio de caminos
					}
				}
			}
		}

	}
	for (int i = 0; i < cerrados->size(); i++)
	{
		imprimirCamino(cerrados[0][i]);
	}
	
	for (int i = 0; i < cerrados->size(); i++)
	{
		delete cerrados[0][i];
	}
	delete abiertos;
	delete cerrados;
}

void Grafo::AStar(std::string &inicio, std::string &objetivo, int &facP, int &facD)
{
	std::vector<NodoViajero*>*abiertos = new std::vector<NodoViajero*>, *cerrados = new std::vector<NodoViajero*>;
	bool hay;
	int max = 0, min = 0;
	while (min < _nodoSize)
	{
		if (_nodos[min].getEti() != inicio) {
			min++;
			continue;
		}
		abiertos->push_back(new NodoViajero(&_nodos[min++]));

	}
	if (abiertos->empty()) {
		std::cout << "\nNo se encontro el nodo de origen.\n";
		return;
	}
	while (!abiertos->empty())
	{
		cerrados->push_back(abiertos[0][0]);
		abiertos->erase(abiertos->begin());
		for (int i = 0; i < _aristaSize; i++)
		{
			hay = true;
			if (cerrados[0][cerrados->size() - 1]->getActual()->getEti() == objetivo) {
				continue;
			}
			if (cerrados[0][cerrados->size() - 1]->getActual() == _arista[i].getOr()) {
				if (cerrados[0][cerrados->size() - 1]->getAnterior() != nullptr) {
					if (cerrados[0][cerrados->size() - 1]->getAnterior()->getActual() == _arista[i].getDe()) {
						continue;
					}
				}
				for (int j = 0; j < abiertos->size(); j++)
				{
					if (abiertos[0][j]->getActual() == _arista[i].getDe() && abiertos[0][j]->getAnterior()->getActual() == _arista[i].getOr()) hay = false;
				}
				for (int j = 1; j < cerrados->size(); j++)
				{
					if (cerrados[0][j]->getActual() == _arista[i].getDe() && cerrados[0][j]->getAnterior()->getActual() == _arista[i].getOr()) hay = false;
				}
				if (hay)abiertos->push_back(new NodoViajero(_arista[i].getDe(), cerrados[0][cerrados->size() - 1], _arista[i].getDe()->getCosto(), _arista[i].getDi(), facP, facD));
			}
		}
		if (abiertos->size() > 0) {
			max = abiertos->size() - 1;
			min = 0;
			sortVec(abiertos, max, min);
		}
	}
	if (cerrados->size() > 0) {
		max = cerrados->size() - 1;
		min = 0;
		sortVec(cerrados, max, min);
	}
	for (int i = 0; i <= cerrados->size(); i++)
	{
		if (i == cerrados->size()) {
			std::cout << "\nImposible llegar al nodo objetivo\n";
			break;
		}
		if (cerrados[0][i]->getActual()->getEti() == objetivo) {
			imprimirCamino(cerrados[0][i]);
			break;
		}
	}
	for (int i = 0; i < abiertos->size(); i++)
	{
		delete abiertos[0][i];
	}
	for (int i = 0; i < cerrados->size(); i++)
	{
		delete cerrados[0][i];
	}
	delete abiertos;
	delete cerrados;
}

void GrafoCord::AStar(std::string &inicio, std::string &objetivo, int &facP, int &facD)
{
	std::vector<NodoViajero*>*abiertos = new std::vector<NodoViajero*>, *cerrados = new std::vector<NodoViajero*>;
	bool hay;
	int max = 0, min = 0,fin=0;
	while (min < _nodoSize)
	{
		if (_nodos[min].getEti() == objetivo) fin = min;
		if (_nodos[min].getEti() != inicio) {
			min++;
			continue;
		}
		abiertos->push_back(new NodoViajero(&_nodos[min++]));

	}
	if (abiertos->empty()) {
		std::cout << "\nNo se encontro el nodo de origen.\n";
		return;
	}
	while (!abiertos->empty())
	{
		cerrados->push_back(abiertos[0][0]);
		abiertos->erase(abiertos->begin());
		if (cerrados[0][cerrados->size() - 1]->getActual() == &_nodos[fin]) break;
		for (int i = 0; i < _aristaSize; i++)
		{
			hay = true;
			if (cerrados[0][cerrados->size() - 1]->getActual()->getEti() == objetivo) {
				continue;
			}
			if (cerrados[0][cerrados->size() - 1]->getActual() == _arista[i].getOr()) {
				if (cerrados[0][cerrados->size() - 1]->getAnterior() != nullptr) {
					if (cerrados[0][cerrados->size() - 1]->getAnterior()->getActual() == _arista[i].getDe()) {
						continue;
					}
				}
				for (int j = 0; j < abiertos->size(); j++)
				{
					if (abiertos[0][j]->getActual() == _arista[i].getDe() && abiertos[0][j]->getAnterior()->getActual() == _arista[i].getOr()) hay = false;
				}
				for (int j = 1; j < cerrados->size(); j++)
				{
					if (cerrados[0][j]->getActual() == _arista[i].getDe() && cerrados[0][j]->getAnterior()->getActual() == _arista[i].getOr()) hay = false;
				}
				if (hay)abiertos->push_back(new NodoViajero(_arista[i].getDe(), &_nodos[fin], cerrados[0][cerrados->size() - 1], _arista[i].getDe()->getCosto(), facP, facD));
			}
		}
		if (abiertos->size() > 0) {
			max = abiertos->size() - 1;
			min = 0;
			sortVec(abiertos, max, min);
		}
	}
	if (cerrados->size() > 0) {
		max = cerrados->size() - 1;
		min = 0;
 		sortVec(cerrados, max, min);
	}
	for (int i = 0; i <= cerrados->size(); i++)
	{
		if (i == cerrados->size()) {
			std::cout << "\nImposible llegar al nodo objetivo\n";
			break;
		}
		if (cerrados[0][i]->getActual()->getEti() == objetivo) {
			imprimirCamino(cerrados[0][i]);
			break;
		}
	}
	for (int i = 0; i < abiertos->size(); i++)
	{
		delete abiertos[0][i];
	}
	for (int i = 0; i < cerrados->size(); i++)
	{
		delete cerrados[0][i];
	}
	delete abiertos;
	delete cerrados;
}

GrafoCord::GrafoCord(std::string & nombre)
{
	std::ifstream *mat = new std::ifstream(nombre + ".txt");
	if (!*mat) {
		*mat = std::ifstream(nombre + ".csv");
		if (!*mat) {
			delete mat;
			return;
		}
		mat->close();
		delete mat;
		matCordCSV(nombre);
		return;
	}
	mat->close();
	delete mat;
	matCordS(nombre);
}
