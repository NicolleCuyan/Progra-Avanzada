#include "Lista.h"
#include <iostream>

// REPLACE() remplace el char por otro valor; 
/**/

bool Lista::Replace(char charARemplazar, char remplazo) {
	
	Nodo* remplazar = head;

	while (remplazar != nullptr) {

		if (remplazar->dato == charARemplazar) {

			remplazar->dato = remplazo;
			return true;
		}

		remplazar = remplazar->siguiente;

	}
}

bool Lista::Remover() {
	
	Nodo* actual = head; 

	while (actual != nullptr) {

		Nodo* temp = actual->siguiente; 

		if (actual->dato = 0) {
			if (actual == head) {
				//CASO # 1

				Nodo* siguiente = head->siguiente; 

				if (siguiente != nullptr) {

					siguiente->anterior = nullptr;
				}

				delete head; 

				head = siguiente; 

			}
			else if (actual == tail) {
				//CASO # 2
				Nodo* anterior = tail->anterior; 
				
				if (anterior != nullptr) {

					anterior->siguiente = nullptr;
				}
				//tail->anterior->siguiente = nullptr; 

				//delete de memoria el nodo

				delete tail; //se borra lo que esta en heap (borrar los datos que estan en heap) 

				tail = anterior; 
			}
			else {
				// CASO # 3 - Nodo interior

				Nodo* anterior = actual->anterior; 
				Nodo* siguiente = actual->siguiente; 

				if (anterior != nullptr) {
					anterior->siguiente = siguiente; 
				}

				if (siguiente != nullptr) {
					siguiente->anterior = anterior; 
				}

			}
		}
	}
}

void Lista::imprimirLista() {
	Nodo* actual = head; 

	while (actual != nullptr) {
		cout << actual->dato; 
		actual = actual->siguiente; 
	}
}

//ENCAPSULAMIENTO
int Lista::getLongitud() {
	return longitud; 
}

bool Lista::Add(char x) {

	longitud++;

	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->dato = x; 

	if (head == nullptr) {
		
		//CASO # 1: NO HAY ELEMENTO EN LA LISTA

		nuevoNodo->siguiente = nullptr; 
		nuevoNodo->anterior = nullptr; 

		head = nuevoNodo; 
		tail = nuevoNodo; 
	}
	else {

		//CASO # 2: YA HAY ELEMENTOS EN LA LISTA

		nuevoNodo->siguiente = nullptr;
		nuevoNodo->anterior = tail;
		tail->siguiente = nuevoNodo;
		tail = nuevoNodo;
	}
}