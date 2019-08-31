// tarea3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "estructuras.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

using namespace std;


int main()
{
    std::cout << "Hello World!\n"; 

	nodo *nd = NULL;

	cout << "primeros datos insertados \n";
	insertarNodo(nd, NULL, "luigi");
	insertarNodo(nd, NULL, "hammer");
	insertarNodo(nd, NULL, "mario");
	insertarNodo(nd, NULL, "peach");
	insertarNodo(nd, NULL, "pow");
	insertarNodo(nd, NULL, "fermin");
	imprimirNodosIzquierda(nd);
	crearGrafico(nd, "archivo1.txt");
	ejecutarDot("archivo1");



	cout << "elimina peach \n";
	eliminarNodo(nd, "peach");
	imprimirNodosIzquierda(nd);
	crearGrafico(nd, "archivo2.txt");
	ejecutarDot("archivo2");



	cout << "inserta shy_guy, edd \n";
	insertarNodo(nd, NULL, "shy_guy");
	insertarNodo(nd, NULL, "edd");
	imprimirNodosIzquierda(nd);
	crearGrafico(nd, "archivo3.txt");
	ejecutarDot("archivo3");



	cout << "elimina pow \n";
	eliminarNodo(nd, "pow");
	imprimirNodosIzquierda(nd);
	crearGrafico(nd, "archivo4.txt");
	ejecutarDot("archivo4");



	cout << "inserta boo kamer star whomp \n";
	insertarNodo(nd, NULL, "boo");
	insertarNodo(nd, NULL, "kamer");
	insertarNodo(nd, NULL, "star");
	insertarNodo(nd, NULL, "whomp");
	imprimirNodosIzquierda(nd);
	crearGrafico(nd, "archivo5.txt");
	ejecutarDot("archivo5");



	cout << "elimina shy_guy mario \n";
	eliminarNodo(nd, "shy_guy");
	
	imprimirNodosIzquierda(nd);
	crearGrafico(nd, "archivo6.txt");
	ejecutarDot("archivo6");

	cout << "Eliminar mario";
	eliminarNodo(nd, "mario");
	imprimirNodosIzquierda(nd);
	crearGrafico(nd, "archivo7.txt");
	ejecutarDot("archivo7");
	
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
