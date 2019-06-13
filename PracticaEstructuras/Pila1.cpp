#include "pch.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <Winuser.h>
#include "Pila2.cpp"
#include "Nodos.cpp"
#pragma once
using namespace std;
static int tamanioss;
class Pila1 {
private:
	Pila2 pila2;
	Nodos *inicio;
	
	string texto = "digraph {\n rankdir=LR; \n node [shape=record];";
	string pila1 = "subgraph cluster_0 { \n  label=\"Pila Carretas 1\"; \n struct1 [label =\"";
	string datosPila1="";
	int cont = 0;
public:
	int getTamanio() {
		return tamanioss;
	}
	void apilarNodo(int valor) {
		Nodos* nuevo = new Nodos();
		nuevo->identificador = valor;
		if (inicio==NULL) {
			inicio = nuevo;
		}
		else {
			nuevo->siguiente = inicio;
				inicio = nuevo;
		}
		tamanioss++;
	}
	int retirar() {
		int noCarreta;
		noCarreta = inicio->identificador;
		inicio = inicio->siguiente;
		tamanioss--;
		return noCarreta;
	}
	void mostrarLista() {
		Nodos *aux = inicio;
		while (aux!=NULL)
		{
			cout << aux->identificador << endl;
			aux = aux->siguiente;
		}
	}
	void limpiarVariables() {
		datosPila1 = "";
	}
	void generarDocPila1() {
		Nodos *aux = inicio;
		datosPila1 = "";
		while (aux != NULL)
		{
			datosPila1 += "<f";
			datosPila1 += std::to_string(cont);
			datosPila1 += ">";
			datosPila1 += std::to_string(aux->identificador);
			datosPila1 += "|";
			aux = aux->siguiente;
			cont++;
		}
		if (aux==NULL) {
			if (inicio==NULL) {
				datosPila1 = "<f0> ";
			}
			size_t tam = datosPila1.length();
			datosPila1.erase(tam-1);
			datosPila1 += "\"];\n}";
			pila2.generarDocPila2(texto+pila1+datosPila1);
			/*ofstream file;
			file.open("C:/Users/EG/source/repos/PracticaEstructuras/PracticaEstructuras/Prueba.dot");
			file << texto+pila1+datosPila1;
			file.close();*/
			
		}
	}
};