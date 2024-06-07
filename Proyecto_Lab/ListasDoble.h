#ifndef LISTASDOBLE_H
#define LISTASDOBLE_H

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

class ListaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaDoble();
    void Insertar(Persona dato);
    bool Buscar(string nombre1);
    void Eliminar(string nombre1);
    void Mostrar();
    void GuardarEnArchivo(const string& ruta);
};

#endif // LISTASDOBLE_H
