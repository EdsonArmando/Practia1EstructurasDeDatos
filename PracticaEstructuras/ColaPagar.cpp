#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "NodoColaPagar.cpp"
#include "ColaCarreta.cpp"
#pragma once
using namespace std;
static NodoColaPagar *raiz;
static NodoColaPagar *fondo;
class ColaPagar {

private:
	ColaCarreta cola2;
public:
	bool estaVacia() {
		if (raiz == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void insertaDato(string dato,int noCarretass) {
		NodoColaPagar* nuevo = new NodoColaPagar();
		nuevo->cliente = dato;
		nuevo->noCarreta=noCarretass;
		nuevo->siguiente = NULL;
		if (estaVacia()) {
			raiz = nuevo;
			fondo = nuevo;
		}
		else
		{
			fondo->siguiente = nuevo;
			fondo = nuevo;
		}
	}
	void mostrarDatos() {
		NodoColaPagar* aux = raiz;
		while (aux != NULL)
		{
			cout << aux->cliente << endl;
			aux = aux->siguiente;
		}
	}
	void generarDoc(string datosPila2) {
		int cont = 0;
		string datosCola1 = "";
		string Cola1 = "\n subgraph cluster_2 { \n  label=\"Cola Pagar\"; \n struct3 [label =\"";
		datosPila2 = datosPila2 + Cola1;
		NodoColaPagar* aux = raiz;
		while (aux != NULL)
		{
			datosCola1 += "<f";
			datosCola1 += std::to_string(cont);
			datosCola1 += ">";
			datosCola1 += aux->cliente;
			datosCola1 += "|";
			aux = aux->siguiente;
			cont++;
		}
		if (aux == NULL) {
			if (estaVacia()) {
				datosCola1 = "<f0> ";
			}
			size_t tam = datosCola1.length();
			datosCola1.erase(tam - 1);
			datosCola1 += "\"];\n}";
			cola2.generarDoc(datosPila2+datosCola1);
			/*ofstream file;
			file.open("C:/Users/EG/source/repos/PracticaEstructuras/PracticaEstructuras/Prueba.dot");
			file << datosPila2 + datosCola1;
			file.close();*/
		}
	}
	string extraerCliente() {
		string clientess;
		if (!estaVacia()) {
			if (raiz == fondo) {
				clientess = raiz->cliente;
				raiz = NULL;
				fondo = NULL;
			}
			else {
				clientess = raiz->cliente;
				raiz = raiz->siguiente;
			}
		}
		return clientess;
	}
};