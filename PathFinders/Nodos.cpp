#include "Nodos.h"



void Nodos::setEti(std::string nombre)
{
	_eti = nombre;
}

void Nodos::setCosto(std::string peso)
{
	_costo = std::strtof((peso).c_str(),0);
}

void Nodos::setCordX(std::string x)
{
	_cord[0] = std::strtof((x).c_str(), 0);
}

void Nodos::setCordY(std::string y)
{
	_cord[1] = std::strtof((y).c_str(), 0);
}

void Nodos::setCords(std::string x, std::string y)
{
	_cord[0] = std::strtof((x).c_str(), 0);
	_cord[1] = std::strtof((y).c_str(), 0);
}

void Nodos::setCodigo(std::string codigo)
{
	_codigo = codigo;
}

std::string Nodos::getEti()
{
	return _eti;
}

float Nodos::getCosto()
{
	return _costo;
}

float Nodos::getCord(char x)
{
	switch (x)
	{
	case 'x':
		return _cord[0];
	case'y':
		return _cord[1];
	default:
		break;
	}
	return 0.0f;
}

std::string Nodos::getCodi()
{
	return _codigo;
}

Nodos::Nodos()
{
}


Nodos::~Nodos()
{
}
//calcula la distancia total que tiene con el objetivo en kilometros.
void NodoViajero::setDisAFin(Nodos * objetivo)
{
	double lat1, lon1, lat2, lon2, PI= 3.141592653;
	lat1 = _actual->getCord('x');
	lon1 = _actual->getCord('y');
	lat2 = objetivo->getCord('x');
	lon2 = objetivo->getCord('y');

	double dLat = (lat2 - lat1) *
		PI / 180.0;
	double dLon = (lon2 - lon1) *
		PI / 180.0;

	lat1 = (lat1)* PI / 180.0;
	lat2 = (lat2)* PI / 180.0;

	double a = pow(sin(dLat / 2), 2) +
		pow(sin(dLon / 2), 2) *
		cos(lat1) * cos(lat2);
	double rad = 6371;
	double c = 2 * asin(sqrt(a));
	_distanciaT = rad * c;
}

void NodoViajero::setActual(Nodos *actual)
{
	_eti = actual->getEti();
	_actual = actual;
}

void NodoViajero::setPasos()
{
	if (_anterior != nullptr) {
		pasos += _anterior->getPasos();
	}
	pasos++;
}

void NodoViajero::setAnterior(NodoViajero * anterior)
{
	_anterior = anterior;
}

void NodoViajero::setPeligroT(float &peligro)
{
	if (_anterior != nullptr) {
		_peligroT += _anterior->getPeliT();
	}
	_peligroT += peligro;
}

void NodoViajero::setDistanciaT(float &distancia)
{
	if (_anterior != nullptr) {
		_distanciaT += _anterior->getDistanciaT();
	}
	_distanciaT += distancia;
}

void NodoViajero::setCosto(int &facP, int &facD)
{
	float x, y;
	x = (facP > 0) ? _peligroT * facP : 0;
	y = (facD > 0) ? _distanciaT * facD : 0;
	_costo = x + y;
	if (facD== 0&&facP==0) {
		setPasos();
		_costo = getPasos();
	}
}

void NodoViajero::setCosto(float costo)
{
	_costo = costo;
}

void NodoViajero::setDisRec(float recorrida)
{
	if (_anterior != nullptr) {
		_disRecorrida += _anterior->getDisRec();
	}
	_disRecorrida += recorrida;
}

Nodos* NodoViajero::getActual()
{
	return _actual;
}

NodoViajero * NodoViajero::getAnterior()
{
	return _anterior;
}

float NodoViajero::getPeliT()
{
	return _peligroT;
}

int NodoViajero::getPasos()
{
	return pasos;
}

float NodoViajero::getDistanciaT()
{
	return _distanciaT;
}

float NodoViajero::getDisRec()
{
	return _disRecorrida;
}

NodoViajero::NodoViajero(Nodos *actual)
{
	setActual(actual);
}

NodoViajero::NodoViajero(Nodos *actual, float costo) {
	setActual(actual);
	setCosto(costo);
}

NodoViajero::NodoViajero(Nodos * actual,Nodos* destino, NodoViajero * anterior, float peligro, int & facP, int & facD)
{
	setActual(actual);
	setAnterior(anterior);
	setPeligroT(peligro);
	setDisAFin(destino);
	setCosto(facP, facD);
}

NodoViajero::NodoViajero(Nodos * actual, Nodos * destino, NodoViajero * anterior, float distancia, float peligro, int & facP, int & facD)
{
	setActual(actual);
	setAnterior(anterior);
	setPeligroT(peligro);
	setDisAFin(destino);
	setDistanciaT(distancia);
	setDisRec(distancia);
	setCosto(facP, facD);
}

NodoViajero::NodoViajero(Nodos *actual, NodoViajero * anterior, float  peligro, float  distancia, int & facP, int & facD)
{
	setActual(actual);
	setAnterior(anterior);
	setPeligroT(peligro);
	setDistanciaT(distancia);
	setCosto(facP, facD);
}



