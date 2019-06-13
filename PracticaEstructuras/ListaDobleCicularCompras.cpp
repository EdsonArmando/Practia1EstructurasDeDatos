#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "NodoCompra.cpp"
#pragma once
using namespace std;
static NodoCompra *primerod;
static NodoCompra *ultimod;

class ListaDobleCircularCompras {	
private:
	int indice = 0;
	int tamanios = 1;
	int noCarreta;
public:
	void ingresarCompra(string cliente, int noCarreta) {
		NodoCompra *nuevo = new NodoCompra();
		nuevo->cliente=cliente;
		nuevo->noCarreta=noCarreta;
		nuevo->indice = indice;
		if (primerod==NULL) {
			primerod = nuevo;
			primerod->siguiente = primerod;
			nuevo->anterior = ultimod;
			ultimod = nuevo;
		}
		else {
			ultimod->siguiente = nuevo;
			nuevo->siguiente = primerod;
			nuevo->anterior = ultimod;
			ultimod = nuevo;
			primerod->anterior = ultimod;
		}
		indice++;
		tamanios++;
	}
	string sacarCliente(int indice) {
		string cliente="";
	
		NodoCompra *actual = primerod;
		NodoCompra *anterior = ultimod;
		do {
			if (actual->indice==indice) {
				if (actual==primerod) {
					cliente = actual->cliente;
					noCarreta = actual->noCarreta;
					primerod = primerod->siguiente;
					ultimod->siguiente = ultimod;
					primerod->anterior = ultimod;
				}
				else if (actual==ultimod) {
					cliente = actual->cliente;
					noCarreta = actual->noCarreta;
					ultimod = anterior;
					primerod->anterior = ultimod;
					ultimod->siguiente = primerod;
				}else
				{
					cliente = actual->cliente;
					noCarreta = actual->noCarreta;
					anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = anterior;
				}
				
			}
			anterior = actual;
			actual = actual->siguiente;
		} while (actual!=primerod);
		return cliente;
		tamanios--;
	}
	int no_Carreta() {
		return noCarreta;
	}
	void mostrarLista() {
		NodoCompra *aux=primerod;
		
		do{
			cout << aux->noCarreta << endl;
			aux = aux->siguiente;
		} while (aux != primerod);
		
	}
	void generarDoc(string datosPila2) {
		string Cola1 = "\n subgraph cluster_5 { \n node [shape=record];\n label=\"Lista Compras\";\n";
		string compras = "";
		datosPila2 = datosPila2 + Cola1;
		NodoCompra *aux = primerod;

		do {
			
				compras += aux->cliente+"_"+std::to_string(aux->noCarreta);
				compras += " -> ";
				compras += aux->siguiente->cliente+"_"+std::to_string(aux->siguiente->noCarreta);
				compras += ";\n";
				compras += aux->siguiente->cliente+"_"+std::to_string(aux->siguiente->noCarreta);
				compras += " -> ";
				compras += aux->cliente+"_"+std::to_string(aux->noCarreta);
				compras += ";\n";
			cout << aux->noCarreta << endl;
			aux = aux->siguiente;
		} while (aux != primerod);

		if (aux == primerod) {
			compras += "\n}\n}";
			ofstream file;
			file.open("C:/Users/EG/source/repos/PracticaEstructuras/PracticaEstructuras/Prueba.dot");
			file << datosPila2 + compras;
			file.close();
		}

	}
	
};