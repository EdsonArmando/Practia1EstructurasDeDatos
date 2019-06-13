#include "pch.h"
#include <iostream>
#include "Pila1.cpp"
#include "Pila2.cpp"
#include "ListaDobleCicularCompras.cpp"
#include "ListaDobleCajas.cpp"
#include "ColaCarreta.cpp"
#include "ColaPagar.cpp"
#include <windows.h>
#include<stdlib.h>
#include <time.h>
#include <string>
#include "Prueba.cpp"
#pragma once
using namespace std;

class Menu {
	private:
		int opcion = 0,cantidaCajas;
		int indiceCliente,tamanioPila1,tamanioPila2,cliCompran;
		int cantidadCarretas = 0, ClientesPagando, ClientesComprando;
		int cliente;
		int noCarretaTemp;
		string clienteTemp;
		Prueba p;
		ListaDobleCircularCompras compras;
		Pila1 pila;
		Pila2 pila2;
		ColaPagar cola2;
		ColaCarreta cola1;
		int contCliente=0;
		int clientes = 0;
		ListaDobleCajas cajas;
		ifstream image;
public:
		void IniciarMenu() {

			cout << "Bienvenido al sistema" << endl;
			cout << "1. CantidadCajas" << endl;
			cout << "2. Cantidad Carretas Por Pila" << endl;
			cout << "3. Ingrese la cantidad Clientes Cola Carretas" << endl;
			cout << "4. Ingrese la cantidad Clientes Comprando" << endl;
			cout << "5. Ingrese cantidad Clientes Cola Pagos" << endl;
			cout << "6. Ver imagen de la simulacion" << endl;
			cout << "7. Iniciar Simulacion" << endl;
			cout << "8. Salir" << endl;
			cin >> opcion;
			OpcionesMenu(opcion);
		}

		void OpcionesMenu(int opcion) {
			switch (opcion)
			{
			case 1:
				cout << "Ingrese la cantidad Cajas" << endl;
				cin >> cantidaCajas;
				for (int i = 0; i < cantidaCajas;i++) {
					int a = rand() % 11;
					cajas.insertarCaja(i+1, a, "Libre", "", 0);
				}
				cajas.mostrarLista();
				IniciarMenu();
				break;
			case 2:
				cout << "Ingrese la cantidad Carretas" << endl;
				cin >> cantidadCarretas;
				for (int i = 0; i < cantidadCarretas;i++) {
					int a = rand() % 2;
					if (a == 0) {
						pila.apilarNodo(i+1);
					}
					else if (a == 1) {
						pila2.apilarNodo(i+1);
					}
				}
				/*pila2.mostrarLista();
				cout << "Ingrese la cantidad Carretas pila1" << endl;
				pila.mostrarLista();
				cout << "Ingrese la cantidad Carretas pila2" << endl;
				pila2.mostrarLista();*/
				IniciarMenu();
				break;
			case 3:
				cout << "Ingrese la cantidad Clientes Cola Carretas" << endl;
				cin >> cliente;
				clientes = clientes + cliente;
				for (contCliente; contCliente < clientes; contCliente++)
				{
					cola1.insertaDato("Cliente" + std::to_string(contCliente + 1));
				}
				//cola1.mostrarDatos();
				IniciarMenu();
				
				break;
			case 4:
				cout << "Ingrese la cantidad Clientes Comprando" << endl;
				cin >> ClientesComprando;
				cliCompran = cliente;
				for (cliCompran; cliCompran < cliente+ClientesComprando; cliCompran++)
				{
					compras.ingresarCompra("Cliente"+std::to_string(cliCompran+1), (cantidadCarretas++)+1);
				}
				/*compras.ingresarCompra("Cliente1",5);
				compras.ingresarCompra("Cliente2",4);
				compras.ingresarCompra("Cliente3",6);
				compras.ingresarCompra("Cliente4", 6);
				compras.ingresarCompra("Cliente5", 6);
				compras.ingresarCompra("Cliente6", 6);
				compras.ingresarCompra("Cliente7", 6);
				//compras.mostrarLista();*/
				IniciarMenu();
				break;
			case 5:
				cout << "Ingrese cantidad Clientes Cola Pagos" << endl;
				cin >> ClientesPagando;
				
				for (cliCompran; cliCompran < cliente+ ClientesComprando +ClientesPagando;cliCompran++)
				{
					cola2.insertaDato("Cliente"+std::to_string(cliCompran+1),(cantidadCarretas++)+1);
				}
				/*cola2.insertaDato("Cliente12");
				cola2.insertaDato("Cliente13");
				cout << ClientesPagando << endl;*/
				IniciarMenu();
				
				break;
			case 6:
				pila.limpiarVariables();
				pila.generarDocPila1();
				system("dot -Tpng Prueba.dot -o graf.png");
				system("graf.png");
				IniciarMenu();
				break;
			case 7:
			    indiceCliente = rand() % 99;
				tamanioPila1 = pila.getTamanio();
				tamanioPila2 = pila2.getTamanio();
				if (tamanioPila1!=0) {
					cout << tamanioPila1 << endl;
					compras.ingresarCompra(cola1.extraerCliente(), pila.retirar());
				}
				else if(tamanioPila2!=0) {
					compras.ingresarCompra(cola1.extraerCliente(), pila2.retirar());
				}
				clienteTemp = compras.sacarCliente(indiceCliente);
				if (clienteTemp!="") {
					noCarretaTemp = compras.no_Carreta();
					cola2.insertaDato(clienteTemp,noCarretaTemp);
					int noCaja = cajas.noCajaDisponible();
					if (noCaja!=0) {
						cajas.modificarCaja(noCaja, cola2.extraerCliente(), noCarretaTemp);
						pila.apilarNodo(noCarretaTemp);
					}
				}
				else {
				
				}
				ClientesComprando--;
				IniciarMenu();
				//Dar Carreta a un cliente para pasar a compras
				/*compras.ingresarCompra("Cliente4", 2);
				compras.ingresarCompra("Cliente5", 1);
				
				cola2.insertaDato("Cliente10");
				cola2.insertaDato("Cliente15");
				cola2.insertaDato(compras.sacarCliente(3));
				pila.apilarNodo(compras.no_Carreta());
				IniciarMenu();
				//cola1.extraerCliente();
				//IniciarMenu();
				/*cola1.extraerCliente();
				cola1.mostrarDatos();
				IniciarMenu();*/
				//exit(-1);
				break;
			default:
				break;
			}
		}
};
