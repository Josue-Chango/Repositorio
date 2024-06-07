#include "ListasDoble.h"
#include <fstream>

// Constructor del nodo
Nodo::Nodo(Persona d) : dato(d), siguiente(NULL), anterior(NULL) {}

// Constructor de la lista doble
ListaDoble::ListaDoble() : cabeza(NULL), cola(NULL) {}

void ListaDoble::Insertar(Persona dato) {
    Nodo* nuevo = new Nodo(dato);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
    }
    else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

bool ListaDoble::Buscar(string nombre1) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->dato.getNombre1() == nombre1) {
            cout << "Dato encontrado: " << nombre1 << endl;
            return true;
        }
        actual = actual->siguiente;
    }
    cout << "Dato no encontrado" << endl;
    return false;
}

void ListaDoble::Eliminar(string nombre1) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->dato.getNombre1() == nombre1) {
            if (actual->anterior) {
                actual->anterior->siguiente = actual->siguiente;
            }
            else {
                cabeza = actual->siguiente;
            }
            if (actual->siguiente) {
                actual->siguiente->anterior = actual->anterior;
            }
            else {
                cola = actual->anterior;
            }
            delete actual;
            cout << "Dato eliminado: " << nombre1 << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Dato no encontrado para eliminar" << endl;
}

void ListaDoble::Mostrar() {
    Nodo* actual = cabeza;
    while (actual) {
        cout << actual->dato.getNombre1() << " " << actual->dato.getNombre2() << " " << actual->dato.getApellido() << " - " << actual->dato.generarCorreo() << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}

void ListaDoble::GuardarEnArchivo(const string& ruta) {
    ofstream archivo(ruta, ios::app); // Abrir en modo añadir
    if (archivo.is_open()) {
        Nodo* actual = cabeza;
        while (actual) {
            archivo << actual->dato.getNombre1() << " "
                << actual->dato.getNombre2() << " "
                << actual->dato.getApellido() << " "
                << actual->dato.generarCorreo() << endl;
            actual = actual->siguiente;
        }
        archivo.close();
        cout << "Datos guardados en " << ruta << endl;
    }
    else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}
