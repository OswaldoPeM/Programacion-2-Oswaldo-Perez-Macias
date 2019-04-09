#include "Arista.h"



void Arista::setOr(Nodos * ori)
{
	_origen = ori;
}

void Arista::setDe(Nodos * des)
{
	_destino = des;
}

void Arista::setDi(float dis)
{
	_distancia = dis;
}

void Arista::setPrecio(std::string precio)
{
	_precio = std::strtof((precio).c_str(), 0);
}

void Arista::setDisCord()
{
	double lat1, lon1, lat2, lon2, PI = 3.141592653;
	lat1 = _origen->getCord('x');
	lon1 = _origen->getCord('y');
	lat2 = _destino->getCord('x');
	lon2 = _destino->getCord('y');

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
	_distancia = rad * c;
}

float Arista::getPrecio()
{
	return _precio;
}

Nodos * Arista::getOr()
{
	return _origen;
}

Nodos * Arista::getDe()
{
	return _destino;
}

float Arista::getDi()
{
	return _distancia;
}

Arista::Arista()
{
}

Arista::Arista(Nodos * ori, Nodos * des)
{
	setOr(ori);
	setDe(des);
	setDisCord();
}

Arista::Arista(Nodos * ori, Nodos * des, float dis)
{
	setOr(ori);
	setDe(des);
	setDi(dis);
}

Arista::Arista(Nodos * ori, Nodos * des, std::string dis)
{
	setOr(ori);
	setDe(des);
	_distancia = std::strtof((dis).c_str(), 0);

}



Arista::~Arista()
{
}
