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

void NodoViajero::setDisTCord(Nodos * objetivo)
{
	float x, y;
	x = (_actual->getCord('x') - objetivo->getCord('x'));
	if (x < 0)x = -x;
	y = (_actual->getCord('y') - objetivo->getCord('y'));
	if (y < 0)y = -y;
	_distanciaT = x + y;
}

void NodoViajero::setActual(Nodos *actual)
{
	_eti = actual->getEti();
	_actual = actual;
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
		_distanciaT = _anterior->getDistanciaT();
	}
	_distanciaT += distancia;
}

void NodoViajero::setCosto(int &facP, int &facD)
{
	float x, y;
	x = (facP > 0) ? _peligroT * facP : 0;
	y = (facD > 0) ? _distanciaT * facD : 0;
	_costo = x + y;
}

void NodoViajero::setCosto(float costo)
{
	_costo = costo;
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

float NodoViajero::getDistanciaT()
{
	return _distanciaT;
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
	setDisTCord(destino);
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



