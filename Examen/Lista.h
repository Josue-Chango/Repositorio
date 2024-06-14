#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

struct Nodo {
    Persona dato;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(Persona d);
};

class Lista {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    Lista();
    void Insertar(Persona dato);
    bool Buscar(string nombre1);
    void Eliminar(string nombre1);
    void Mostrar();
    void GuardarEnArchivo(const string& ruta);
};

#endif // LISTA_H
