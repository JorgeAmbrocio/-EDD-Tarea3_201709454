#include "pch.h"
#include "estructuras.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

estructuras::estructuras()
{
}


estructuras::~estructuras()
{
}



// CLASE ARBOL BINARIO DE BÚSQUEDA
abb::abb() {}

abb::~abb() {}

void insertarNodo(nodo *& arbol , int n) { 
	if (arbol == NULL) {
		nodo *nd = crearNodo(n);
		arbol = nd;
	}
	else {
		int valorRaiz = arbol->dato; 
		if (n < valorRaiz) {
			insertarNodo(arbol->izquierda, n);
		}
		else {
			insertarNodo(arbol->derecha,n);
		}
	}
	

}

nodo *crearNodo(int n) {
	nodo *nd = new nodo();

	nd->dato = n;
	nd->derecha = NULL;
	nd->izquierda = NULL;
	 
	return nd;
}

void imprimirNodosDerecha(nodo *& arbol) {
	
	if (arbol != NULL) {
		if (arbol->derecha != NULL) {
			imprimirNodosDerecha(arbol->derecha);
		}

		cout << arbol->dato<<"\n";

		if (arbol->izquierda != NULL) {
			imprimirNodosDerecha(arbol->izquierda);
		}

	}
}

void imprimirNodosIzquierda(nodo *& arbol) {

	if (arbol != NULL) {
		if (arbol->izquierda != NULL) {
			imprimirNodosIzquierda(arbol->izquierda);
		}

		cout << arbol->dato << "\n";

		if (arbol->derecha != NULL) {
			imprimirNodosIzquierda(arbol->derecha);
		}

	}
}

