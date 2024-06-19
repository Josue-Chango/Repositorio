#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;
};

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    ListaDoble() {
        cabeza = nullptr;
        cola = nullptr;
    }

    bool estaVacia() {
        return cabeza == nullptr && cola == nullptr;
    }

    void insertarInicio(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        nuevoNodo->dato = dato;
        nuevoNodo->anterior = nullptr;
        nuevoNodo->siguiente = cabeza;

        if (estaVacia()) {
            cola = nuevoNodo;
        } else {
            cabeza->anterior = nuevoNodo;
        }
        cabeza = nuevoNodo;
    }

    void insertarFinal(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        nuevoNodo->dato = dato;
        nuevoNodo->anterior = cola;
        nuevoNodo->siguiente = nullptr;

        if (estaVacia()) {
            cabeza = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
        }
        cola = nuevoNodo;
    }

    void eliminar(T dato) {
        if (estaVacia()) {
            return;
        }

        Nodo<T>* actual = cabeza;
        while (actual != nullptr && actual->dato != dato) {
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            return;
        }

        if (actual == cabeza) {
            cabeza = actual->siguiente;
        } else {
            actual->anterior->siguiente = actual->siguiente;
        }

        if (actual == cola) {
            cola = actual->anterior;
        } else {
            actual->siguiente->anterior = actual->anterior;
        }

        delete actual;
    }

    void imprimir() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void imprimirInverso() {
        Nodo<T>* actual = cola;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->anterior;
        }
        cout << endl;
    }
};

int main() {
    ListaDoble<int> miListaInt;
    miListaInt.insertarInicio(10);
    miListaInt.insertarInicio(20);
    miListaInt.insertarFinal(30);
    miListaInt.imprimir(); // Salida: 20 10 30
    miListaInt.imprimirInverso(); // Salida: 30 10 20

    miListaInt.eliminar(10);
    miListaInt.imprimir(); // Salida: 20 30
    miListaInt.imprimirInverso(); // Salida: 30 20

    ListaDoble<string> miListaString;
    miListaString.insertarInicio("Hola");
    miListaString.insertarFinal("Mundo");
    miListaString.imprimir(); // Salida: Hola Mundo
    miListaString.imprimirInverso(); // Salida: Mundo Hola

    return 0;
}
