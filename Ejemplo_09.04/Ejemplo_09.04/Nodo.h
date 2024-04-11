#pragma once
class Nodo
{
public:
	char dato; 
	Nodo* siguiente; 
	Nodo* anterior;

	Nodo() {
		dato = '\0'; 
		siguiente = nullptr; 
		anterior = nullptr; 
	}
};

