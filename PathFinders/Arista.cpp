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

void Arista::setDisCord()
{
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
