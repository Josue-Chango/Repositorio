
#pragma once
#include "Nodo.h"
#include "Persona.h"

using namespace std;

class ListasSimples {

    private:
        Nodo* cabeza;
    public:
        ListasSimples();
        void Insertar(Persona dato);
        void Mostrar();
};

