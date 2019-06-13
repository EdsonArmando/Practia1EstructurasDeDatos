#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "NodoCajas.cpp"
#include "ListaDobleCicularCompras.cpp"
//#include "ListaDobleCircularCompras.cpp"
#pragma once
using namespace std;
static NodoCajas *inicios;
static NodoCajas *fins;
class ListaDobleCajas {
private:
	ListaDobleCircularCompras listaDoble;
	int tamanioLista;

public:
	void insertarCaja(int numeroCaja, int turnos, string estado, string cliente, int noCarreta) {
		NodoCajas *nuevo = new NodoCajas();
		nuevo->numeroCaja = numeroCaja;
		nuevo->turno = turnos;
		nuevo->estado = estado;
		nuevo->cliente = cliente;
		nuevo->noCarreta = noCarreta;
		if (inicios==NULL) {
			inicios = nuevo;
			inicios->anterior = NULL;
			inicios->siguiente = NULL;
			fins = inicios;
		}else{
			nuevo->anterior = NULL;
			nuevo->siguiente = inicios;
			inicios->anterior = nuevo;
			inicios = nuevo;
		}
	}
	void sacarCliente() {
		if (inicios!=NULL) {
			inicios->anterior=NULL;
		}
		else
		{
			fins = NULL;
		}
	}
	void modificarCaja(int noCaja,string cliente,int noCarreta) {
		NodoCajas *aux = inicios;
		int cont = 0;
		while (aux != NULL)
		{
			if (aux->numeroCaja==noCaja) {
				aux->cliente = cliente;
				aux->noCarreta = noCarreta;
				aux->estado = "Ocupado";
			}
			aux = aux->siguiente;
			cont = 1;
		}
	}
	int noCajaDisponible() {
		NodoCajas *aux = inicios;
		
		while (aux != NULL)
		{
			if (aux->estado=="Libre") {
				return aux->numeroCaja;
			}
			aux = aux->siguiente;
		
		}
		return 0;
	}
	void generarDoc(string datosPila2) {
		string Cola1 = "\n subgraph cluster_4 { \n node [shape=record];\n label=\"Cajas de Pago\";\n";
		string compras = "";
		datosPila2 = datosPila2 + Cola1;
		NodoCajas *aux = inicios;
		int cont = 0;
		while (aux != NULL)
		{
			if (aux->numeroCaja!=1) {
				compras += "No_Caja_"+std::to_string(aux->numeroCaja)+"_Turno"+ std::to_string(aux->turno)+"_Estado"+aux->estado;
				compras += " -> ";
				compras += "No_Caja_"+std::to_string(aux->siguiente->numeroCaja)+"_Turno"+ std::to_string(aux->siguiente->turno)+"_Estado"+ aux->siguiente->estado;
				compras += ";\n";
				compras += "No_Caja_"+std::to_string(aux->siguiente->numeroCaja)+"_Turno"+ std::to_string(aux->siguiente->turno)+"_Estado"+aux->siguiente->estado;
				compras += " -> ";
				compras += "No_Caja_"+std::to_string(aux->numeroCaja)+"_Turno"+ std::to_string(aux->turno)+"_Estado"+aux->estado;
				compras += ";\n";
			}
			aux = aux->siguiente;
			cont = 1;
		}
		if (aux == NULL) {
			compras += "\n}";
			listaDoble.generarDoc(datosPila2+compras);
			/*ofstream file;
			file.open("C:/Users/EG/source/repos/PracticaEstructuras/PracticaEstructuras/Prueba.dot");
			file << datosPila2 + compras;
			file.close();*/
		}
	}
	void mostrarLista() {
		NodoCajas *aux = inicios;
		int cont = 0;
		while (aux!=NULL)
		{
			cout << "----------" << endl;
			cout <<aux->numeroCaja << endl;		
			cout << aux->turno << endl;
			cout << aux->estado << endl;
			cout << "----------" << endl;
			aux = aux->siguiente;
			cont = 1;
		}
	}
};