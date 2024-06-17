
#pragma once
#include <iostream>
#include "Persona.h"

class Nodo {
    private:
        Persona dato;
        Nodo* siguiente;
    public:
        Nodo(Persona _dato) {
            dato = _dato;
            siguiente = NULL;
        }

        void setDato(Persona _dato) {
            dato = _dato;
        }

        Persona getDato() {
            return dato;
        }

        void setSiguiente(Nodo* _siguiente) {
            siguiente = _siguiente;
        }

        Nodo* getSiguiente() {
            return siguiente;
        }
        friend class ListasSimples;
};

