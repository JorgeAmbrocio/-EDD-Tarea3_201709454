#pragma once
#include <string>;

using namespace std;

struct nodo {
	int dato;
	
	nodo *derecha;
	nodo *izquierda;

};

nodo *crearNodo(int);
void imprimirNodosDerecha(nodo *& arbol);
void imprimirNodosIzquierda(nodo *& arbol);
void insertarNodo(nodo *&, int);

class abb {
public :
	abb();
	~abb();

	nodo raiz;

};




class estructuras
{
public:
	estructuras();
	~estructuras();
};



