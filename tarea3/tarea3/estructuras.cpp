#include "pch.h"
#include "estructuras.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

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

void insertarNodo(nodo *& arbol , nodo * p, string n) { 
	if (arbol == NULL) {
		nodo *nd = crearNodo(p, n);
		arbol = nd;
	}
	else {
		string valorRaiz = arbol->dato; 
		if (n < valorRaiz) {
			insertarNodo(arbol->izquierda, arbol, n ); //+ " iz"
		}
		else {
			insertarNodo(arbol->derecha,arbol,n ); //+ " de"
		}
	}
	

}

nodo *crearNodo(nodo * p,string n) {
	nodo *nd = new nodo();

	nd->dato = n;
	nd->derecha = NULL;
	nd->izquierda = NULL;
	nd->padre = p;
	 
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

void eliminarNodo(nodo *& arbol, string str) {
	if (arbol != NULL) {
		if (arbol->dato < str) {
			// buscar el elemento por la derecha
			eliminarNodo(arbol->derecha , str);
		}
		else if (arbol->dato > str ) {
			// buscar el elemento por la izquierda
			eliminarNodo(arbol->izquierda, str);
		}
		else if (arbol->dato == str) {
			// eliminar el arbol 
			eliminarArbol( arbol);
		}
	}
	else {
		return;
	}
}


void eliminarArbol(nodo *arbol) {
	if (arbol->izquierda != NULL && arbol->derecha != NULL) {
		// recuperar el nodo mas izquierda del nodo derecha del árbol y reemplazar el valor con el nodo que queremos elimianr
		nodo *minimo = masIzquierda(arbol->derecha);
		
		arbol->dato = minimo->dato; // reemplazar el valor;
		eliminarArbol(minimo);
	}
	else if (arbol->izquierda != NULL ) {
		// reemplazar el nodo a eliminar con el valor de su hijo izquierdo
		reemplazar(arbol, arbol->izquierda);
		//destruirNodo(arbol);
	}
	else if (arbol->derecha != NULL) {
		// reemplazar el nodo a elimianr con el valor de su hijo derecha
		reemplazar(arbol, arbol->derecha);
		//destruirNodo(arbol);
	}
	else  {
		// el arbol no tiene hijos

		if (arbol->padre->izquierda != NULL && arbol->izquierda->dato == arbol->dato) {
			// es el nodo izquierda
			arbol->padre->izquierda = NULL;
		}
		else {
			arbol->padre->derecha = NULL;
		}

	}
	return;
}

nodo *masIzquierda(nodo * arbol) {
	if (arbol->izquierda != NULL) {
		return masIzquierda(arbol->izquierda);
	}
	else {
		return arbol;
	}

	
}

void reemplazar(nodo *antiguo, nodo *nuevo) {
	if (antiguo->padre) { // verifica que tenga padre
		if (antiguo->padre->izquierda != NULL && antiguo->padre->izquierda->dato == antiguo->dato) {
			// es el hijo izquierda
			antiguo->padre->izquierda = nuevo;
		}
		else {
			// es el hijo derecha
			antiguo->padre->derecha = nuevo;
		}
	}

	if (nuevo) { // si el nuevo nodo existe
		nuevo->padre = antiguo->padre;
	}

	return;
}

void destuirNodo(nodo *&arbol) {
	arbol->derecha = NULL;
	arbol->izquierda = NULL;

	delete arbol;
	return;
}

void crearGrafico(nodo *arbol, string nombre) {
	// creacion de un archivo de texto en que se encuenra código graphviz
	ofstream archivo;
	string cont = "";
	
	// crear contenido del archivo
	cont += "digraph arbol { \n size=\"7,7\";  \n node [color=lightblue2, style=filled]; \n";

	cont = cont + getContent(arbol) ;

	cont += "\n }";

	// archivo escritura

	archivo.open(nombre, ios::out);
	if (archivo.fail()) {
		// hubo un error
		cout << "No se pudo abrir el archivo";
		exit(1);
	}

	archivo << cont;

	archivo.close();
}

string getContent(nodo * arbol ) {
	string cont;
	if (arbol != NULL) {
		// arbol no es nulo

		//cont = cont + "\"" + arbol->dato + "\" ; " ;

		if (arbol->izquierda != NULL) {
			cont = cont + "\"" + arbol->dato + "\" " + "-> \"" + arbol->izquierda->dato + "\"; \n";

			cont = cont + getContent(arbol->izquierda);
		}

		if (arbol->derecha != NULL) {
			cont = cont + "\"" + arbol->dato + "\" "  + "-> \"" + arbol->derecha->dato + "\"; \n";

			cont = cont + getContent(arbol->derecha);
		}
		
		
	}

	return cont;
}

void ejecutarDot(string str) {
	

}
