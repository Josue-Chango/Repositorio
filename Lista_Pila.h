#pragma once
#include <iostream>
using namespace std;

class Lista_Pila{

private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
    };
    Nodo* arriba;

public:
    Lista_Pila();
    ~Lista_Pila();
    void insertar(int valor);
    int sacar();
    void buscar(int valor);
    void imprimir();
};



