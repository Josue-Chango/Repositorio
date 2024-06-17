#include "ListasSimples.h"

using namespace std;

ListasSimples::ListasSimples() {
    cabeza = NULL;
}

inline void ListasSimples::Insertar(Persona _dato) {
    Nodo* nuevo = new Nodo(_dato);
    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {
        Nodo* aux = cabeza;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

inline void ListasSimples::Mostrar() {
    Nodo* aux = cabeza;
    while (aux != NULL) {
        cout <<  aux->getDato().getNombre() << " " << aux->getDato().getApellido() << " - " << aux->getDato().getCorreo() << " - " << aux->getDato().getPassword()<< endl;;
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}
