#pragma once
#include "Nodo.h"
#include <string>

using namespace std; 

class Lista
{
private:
	int longitud; 
	Nodo* head; 
	Nodo* tail; 

public:
	bool Add(char x);
	int getLongitud();
	void imprimirLista();
	bool Remover();
	bool Replace(char charARemplazar, char remplazo);

	Lista() {
		longitud = 0; 
		head = nullptr; 
		tail = nullptr; 
	}
};

