#include "pch.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;
class NodoCajas
{
public:
	int numeroCaja;
	int turno;
	int turnoCliente;
	string estado;
	string cliente;
	int noCarreta;
	NodoCajas *anterior;
	NodoCajas *siguiente;

};