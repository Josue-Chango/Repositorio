#include <iostream>
#include "Lista_Pila.h"

using namespace std;

void Lista_Pila::insertar(int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = arriba;
    arriba = nuevoNodo;
}

void Lista_Pila::buscar(int valor) {
    Nodo* actual = arriba;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            cout << "El valor " << valor << " se encuentra en la pila" << endl;
        }
        actual = actual->siguiente;
    }
    cout << "El valor " << valor << " no se encuentra en la pila" << endl;
}

int Lista_Pila::sacar() {
    if (arriba == nullptr) {
        throw runtime_error("Error: la pila está vacía");
    }
    int valor = arriba->dato;
    Nodo* temp = arriba;
    arriba = arriba->siguiente;
    delete temp;
    return valor;
}

void Lista_Pila::imprimir() {
    Nodo* actual = arriba;
    cout << "Pila: ";
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

Lista_Pila::Lista_Pila() {
    arriba = nullptr;
}

Lista_Pila::~Lista_Pila() {
    while (arriba != nullptr) {
        sacar();
    }
}
