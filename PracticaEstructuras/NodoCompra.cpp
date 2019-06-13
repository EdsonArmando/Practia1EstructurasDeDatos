#include "pch.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;
class NodoCompra {
public:
	string cliente;
	int noCarreta;
	int indice;
	NodoCompra *siguiente;
	NodoCompra *anterior;

};