#include "Grafo.h"



//quicksort
void Grafo::sortVec(std::vector<NodoPM*>* vector,int &derecha, int &izquierda)
{
	int i = izquierda, j = derecha, p = vector[0][derecha]->getCost();
	NodoPM* temp;
	while (i <= j) {
		while (vector[0][i]->getCost() < p)i++;
		while (vector[0][j]->getCost() > p)j--;
		if (i <= j) {
			temp = vector[0][i];
			vector[0][i] = vector[0][j];
			vector[0][j] = temp;
			i++;
			j--;
		}
	}
	if (izquierda < j) sortVec(vector, j, izquierda);
	if (derecha > i) sortVec(vector, derecha, i);

}

void Grafo::printPM(NodoPM * camino)
{
	std::string ruta="";
	while (camino != NULL) {
		ruta = camino->getAct()->getEti() + ruta;
		camino = camino->getAnt();
		
	}
	std::cout << ruta << std::endl;
}

bool Grafo::wasVisited()
{
	for (int i = 0; i < nodoSize; i++)
	{
		if (nodos[i].getVisit() != 's')return false;
	}
	return true;
}

Nodo * Grafo::getNod()
{
	return nodos;
}


Arista* Grafo::getAri()
{
	return aristas;
}


std::fstream * Grafo::getTxt()
{
	std::fstream* mat = new std::fstream("Matriz.txt");
	return mat;
}

void Grafo::setNod()
{ 
	std::fstream* mat = getTxt();
	Nodo* graf;
	std::string buffer,eti;
	std::stringstream stream;
	std::getline(*mat, buffer);
	for (int i = 0; i < buffer.size(); i++)
	{
		if (buffer[i] == ',') nodoSize++;
	}
 	int j=0;
	nodos = new Nodo[nodoSize+1];
	stream = std::stringstream(buffer);
	while (std::getline(stream,eti,','))
	{
		buffer = "";
		for (int i = 0; i < eti.size(); i++)
		{
			if (eti[i] == '|') break;
			buffer += eti[i];
		}
		nodos[j].setEti(buffer);
		buffer = "";
		for (int i = buffer.size()+2; i < eti.size(); i++)
		{
			buffer += eti[i];
		}
		nodos[j].setCord(buffer);
		j++;
	}
	setAri(mat);
}
//retorna el tamanio del arreglo de aristas
int Grafo::tamLink(std::fstream *mat)
{
	std::string buffer = "",valor;
	int x = 0;
	std::stringstream stream;
	while (std::getline(*mat,buffer))
	{
		stream = std::stringstream(buffer);
		while (std::getline(stream,valor,','))
		{

			if (valor != "0")x += 1;
		}
		/*for (int i = 0; i < buffer.size(); i++) {
			if ((buffer[i] != '0') && ( buffer[i] != ',')  ) x += 1;
		}*/
	}
	mat->close();
	*mat = std::fstream("Matriz.txt");
	std::getline(*mat, buffer);
	return x;
}
//asigna las aristas a un arreglo de aristas
void Grafo::setAri(std::fstream * mat)
{
	aristaSize = (tamLink(mat));
	aristas = new Arista[aristaSize];
	std::string buffer, valor;
	Arista* x;
	int j = 0, k = 0, i = 0;
	Nodo* link;
	std::stringstream stream;
	while (std::getline(*mat, buffer)) {
		k = 0;
		stream = std::stringstream(buffer);
		while (getline(stream, valor, ','))
		{
			if (valor != "0") {
				x = new Arista(&nodos[j], &nodos[k], valor);//se crea nueva arista alojada en heap
				aristas[i] = *x;
				i++;
			}
			k++;
		}
		j++;
	}
	mat->close();
	delete mat;
}

void Grafo::print()
{
	int i = 0;
	while (i<aristaSize)
	{
		std::cout << aristas[i].getLink(0)->getEti() << " " << aristas[i].getLink(1)->getEti() << " " << aristas[i].getPeso() << "\n";
		i++;
	}
}
//hace una busqueda de profundidad de manera recursiva
bool Grafo::scope(Nodo* x,Nodo*y)
{
	std::cout << x->getEti() << std::endl;// imprime la etiqueta del nodo actual.
	x->visit();
	int i = 0;
	while (i < aristaSize)
	{
		if ((aristas[i].getLink(0) == x) && (aristas[i].getLink(1)->getVisit() != 's')) {//revisa que es nodo actual tenga nodos por vistar que no hayan sido visitados
			scope(aristas[i].getLink(1),y);//visita el nodo adyacente
		}
		i++;
	}
	return true;
}

void Grafo::resetV()
{
	int i = 0;
	while (i<nodoSize)
	{
		nodos[i].rVisit();
		i++;
	}
}

void Grafo::profun()
{
	std::vector<Nodo*> abiertos,cerrados;
	bool hay;
	int costo = 0;
	abiertos.push_back(&nodos[0]);
	while (!abiertos.empty())
	{
		cerrados.push_back(abiertos[abiertos.size() - 1]);
		std::cout << cerrados[cerrados.size() - 1]->getEti() << " ";
		for (int i = abiertos.size()-1; i > -1; i--)
		{
			if (cerrados[cerrados.size() - 1] == abiertos[i]) {
				abiertos.erase(abiertos.begin() + i);
			}
		}
		for (int i = 0; i < aristaSize; i++)
		{
			hay = true;
			if (aristas[i].getLink(0) == cerrados[cerrados.size() - 1]) {
				for (int j = 0; j < cerrados.size(); j++)
				{
					if (!hay) break;
					if (aristas[i].getLink(1) == cerrados[j]) hay = false; 
				}
				if (hay) {
					abiertos.push_back(aristas[i].getLink(1));
				}
			}
		}
	}
}

void Grafo::ampli()
{
	std::vector<Nodo*> abiertos, cerrados;
	bool hay;
	abiertos.push_back(&nodos[0]);
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
		for (int i = 0; i < aristaSize; i++)
		{
			hay = true;
			if (aristas[i].getLink(0) == cerrados[cerrados.size() - 1]) {
				for (int j = 0; j < cerrados.size(); j++)
				{
					if (aristas[i].getLink(1) == cerrados[j]) hay = false;
					if (!hay) break;
				}
				if (hay)abiertos.push_back(aristas[i].getLink(1));
			}
		}

	}
}

void Grafo::firstB(std::string inicio, std::string objetivo, float factpeligro)
{
	std::vector<NodoPM*> *abiertos = new std::vector<NodoPM*>(), *cerrados = new std::vector<NodoPM*>();
	NodoPM* nodopm = NULL;
	bool hay=true;
	float y = 0;
	int x = 0, max = 0, min = 0;
	while (x<nodoSize)
	{
		(nodos[x].getEti() != inicio) ? x++, nodopm = nodopm : nodopm = new NodoPM(&nodos[x++],0);
	}
	abiertos->push_back(nodopm);
	std::cout << "\nSe agrego " << abiertos[0][0]->getAct()->getEti() << " como nodo raiz de la busqueda.\n";
	while (!abiertos->empty())
	{
		for (int i = 0; i < aristaSize; i++)
		{
			hay = true;
			if (abiertos[0][0]->getAct() == aristas[i].getLink(0)) {
				for (int j = 0; j < cerrados->size(); j++)
				{
					if (abiertos[0][0]->getAnt() != NULL) {
						if (cerrados[0][j]->getAnt() != NULL) {
							if ((aristas[i].getLink(1) == cerrados[0][j]->getAct()) && (abiertos[0][0]->getAnt()->getAct() == cerrados[0][j]->getAnt()->getAct())) hay = false;
						}
						if (aristas[i].getLink(1) == abiertos[0][0]->getAnt()->getAct()) hay = false;
					}
					if (abiertos[0][0]->getAct()->getEti() == objetivo) hay = false;
					if (!hay) break;
				}
				if (hay) { 
					abiertos->push_back(new NodoPM(aristas[i].getLink(1), abiertos[0][0], aristas[i].getPeso() + aristas[i].getLink(1)->getVal()*factpeligro));
					std::cout << "Se agrego a abiertos " << abiertos[0][abiertos->size() - 1]->getAct()->getEti() << " desde " << abiertos[0][abiertos->size() - 1]->getAnt()->getAct()->getEti() << std::endl;
				}
			}
		}
		cerrados->push_back(abiertos[0][0]);
		abiertos->erase(abiertos->begin());
		max = abiertos->size() - 1;
		sortVec(abiertos, max, min);
		if (cerrados[0][cerrados->size() - 1]->getAct()->getEti() == objetivo){
			break;
		}
	}
	printPM(cerrados[0][cerrados->size() - 1]);
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

void Grafo::dijkstra(std::string raiz, int factPeligro)
{
	float sumP = 0, sumD = 0;
	
	std::vector<NodoPM*>* abiertos = new std::vector<NodoPM*>, *cerrados = new std::vector<NodoPM*>;
	for (int i = 0; i < nodoSize; i++)
	{
		if (nodos[i].getEti() == raiz) {
			abiertos->push_back(new NodoPM(&nodos[i], 0));
			nodos[i].visit();
		}
		else {
			abiertos->push_back(new NodoPM(&nodos[i], FLT_MAX));
		}
	}
	int max = abiertos->size() - 1, min = 0;
	sortVec(abiertos, max, min);

	while (!abiertos->empty())
	{
		for (int i = 0; i < aristaSize; i++)
		{
			if ((abiertos[0][0]->getAct() == aristas[i].getLink(0))) {
				for (int j = 0; j < abiertos->size(); j++)
				{

				}
			}
		}
	}

	delete abiertos;
	delete cerrados;
}



Grafo::Grafo()
{
}

Grafo::Grafo(int x)
{
	nodos = new Nodo[x];
}


Grafo::~Grafo()
{
	delete[] aristas;
	delete[] nodos;

}
