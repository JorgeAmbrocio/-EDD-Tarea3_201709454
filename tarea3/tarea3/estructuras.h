#pragma once;
#include <string>;

using namespace std;

struct nodo {
	string dato;
	
	nodo *padre;
	nodo *derecha;
	nodo *izquierda;
};

nodo *crearNodo(nodo *, string);
void insertarNodo(nodo *&, nodo *, string);
void imprimirNodosDerecha(nodo *& arbol);
void imprimirNodosIzquierda(nodo *& arbol);

void eliminarArbol(nodo * arbol);
void eliminarNodo(nodo *&arbol, string str);
void destruirNodo(nodo *&);

nodo *masIzquierda(nodo *);
void reemplazar(nodo * , nodo *);
void crearGrafico(nodo *, string);
string getContent(nodo *);
void ejecutarDot(string );


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



