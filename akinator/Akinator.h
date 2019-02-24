#include<sstream>
#pragma once
#include"Nodo.h"

class Akinator
{
	Nodo* raiz = NULL;//raiz del arbol
	Nodo* crearNodo();//crea nodo
	std::string decisiones="";//a manera de string interpreta los caminos que has tenido.
public:
	bool opc(bool x);//retorna un booleano que decide a que lado del nodo ir
	Nodo* getRaiz();//retorna la direccion de la raiz
	void addNodo(Nodo* pos,std::string a2);//aniade nodo
	void addNodo(Nodo* pos, std::string animal, std::string car1, std::string car2);//para cuando se esta cargando la partida
	void addDecision(std::string path);// agrega una desicion al camino
	void adivinar(Nodo* pos);//recorre nodos hacia abajo
	std::string strSinEsp(std::string s);
	void crearArbol(Nodo* pos);//crea un arbol con un archivo de texto
	void cargarNodo(Nodo* pos, std::string camino);//desmiembra cada linea de texto y manda a crear nodo.
	void arbolBase();// crea una sencilla base para el arbol.
	void salvarNodo();//escribe en el archivo de texto de gusrdado una linea de texto con la posicion del nodo
	void saveData();
	void loadData();
	void writeOnFile(Nodo* pos);


	Akinator();
	Akinator(Nodo* Raiz);
	~Akinator();
};

