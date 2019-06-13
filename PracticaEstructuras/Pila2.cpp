#include "pch.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <Winuser.h>
#include "NodoPila2.cpp"
#include "Prueba.cpp"
#include "ColaPagar.cpp"
#pragma once
using namespace std;
static NodoPila2 *inicio;
static int tamanio;
class Pila2 {
public:
	ColaPagar cola;
	
public:
	int getTamanio() {
		return tamanio;
	}
	 void apilarNodo(int valor) {
		NodoPila2* nuevo = new NodoPila2();
		nuevo->identificador = valor;
		if (inicio == NULL) {
			inicio = nuevo;
		}
		else {
			nuevo->siguiente = inicio;
			inicio = nuevo;
		}
		tamanio++;
	}
	 int retirar() {
		int noCarretas;
		noCarretas = inicio->identificador;
		inicio = inicio->siguiente;
		tamanio--;
		return noCarretas;
	}
	 void mostrarLista() {
		NodoPila2 *aux = inicio;
		while (aux != NULL)
		{
			cout << aux->identificador << endl;
			aux = aux->siguiente;
		}
	}
	void generarDocPila2(string datosPila1) {
		int cont = 0;
		string datosPila2 = "";
		string pilas2 = "\n subgraph cluster_1 { \n  label=\"Pila Carretas 2\"; \n struct2 [label =\"";
		datosPila1 = datosPila1 + pilas2;
		NodoPila2 *aux = inicio;
		while (aux != NULL)
		{
			datosPila2 += "<f";
			datosPila2 += std::to_string(cont);
			datosPila2 += ">";
			datosPila2 += std::to_string(aux->identificador);
			datosPila2 += "|";
			aux = aux->siguiente;
			cont++;
		}
		if (inicio == NULL) {
			datosPila2 = "<f0> ";
		}
		if (aux == NULL) {
			size_t tam = datosPila2.length();
			datosPila2.erase(tam - 1);
			datosPila2 += "\"];\n}";
			cola.generarDoc(datosPila1+datosPila2);
			/*ofstream file;
			file.open("C:/Users/EG/source/repos/PracticaEstructuras/PracticaEstructuras/Prueba.dot");
			file << datosPila1 + datosPila2;
			file.close();*/
		}
	}
};