#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "NodoColaCarreta.cpp"
#include "ListaDobleCajas.cpp"
#pragma once
using namespace std;
static NodoColaCarreta *raizz;
static NodoColaCarreta *fondos;
class ColaCarreta {

public:
	ListaDobleCajas cajas;
	bool estaVacia() {
		if (raizz ==NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void insertaDato(string dato) {
		NodoColaCarreta* nuevo = new NodoColaCarreta();
		nuevo->cliente = dato;
		nuevo->siguiente = NULL;
		if (estaVacia()) {
			raizz = nuevo;
			fondos = nuevo;
		}
		else
		{
			fondos->siguiente = nuevo;
			fondos = nuevo;
		}
	}
	void mostrarDatos() {
		NodoColaCarreta* aux = raizz;
		while (aux!=NULL)
		{
			cout << aux->cliente << endl;
			aux = aux->siguiente;
		}
	}
	void generarDoc(string datosPila2) {
		int cont = 0;
		string datosCola1 = "";
		string Cola1 = "\n subgraph cluster_3 { \n  label=\"Cola para Carretas\"; \n struct4 [label =\"";
		datosPila2 = datosPila2 + Cola1;
		NodoColaCarreta* aux = raizz;
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
			cajas.generarDoc(datosPila2+datosCola1);
			/*ofstream file;
			file.open("C:/Users/EG/source/repos/PracticaEstructuras/PracticaEstructuras/Prueba.dot");
			file << datosPila2 + datosCola1;
			file.close();*/
		}
	}
	string extraerCliente() {
		string cliente;
		if (!estaVacia()) {
			if (raizz==fondos) {
				cliente = raizz->cliente;
				raizz = NULL;
				fondos = NULL;
				return cliente;
			}
			else {
				cliente = raizz->cliente;
				raizz = raizz->siguiente;
				return cliente;
			}
		}
	}
};