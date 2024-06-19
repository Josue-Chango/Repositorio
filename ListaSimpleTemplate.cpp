#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
};

template <typename T>
class ListaSimple {
private:
    Nodo<T>* cabeza;

public:
    ListaSimple() {
        cabeza = nullptr;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    void insertarInicio(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void insertarFinal(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = nullptr;

        if (estaVacia()) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void eliminar(T dato) {
        if (estaVacia()) {
            return;
        }

        if (cabeza->dato == dato) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }

        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = nullptr;
        while (actual != nullptr && actual->dato != dato) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            return;
        }

        anterior->siguiente = actual->siguiente;
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
};

int main() {
    ListaSimple<int> miListaInt;
    miListaInt.insertarInicio(10);
    miListaInt.insertarInicio(20);
    miListaInt.insertarFinal(30);
    miListaInt.imprimir(); // Salida: 20 10 30

    miListaInt.eliminar(10);
    miListaInt.imprimir(); // Salida: 20 30

    ListaSimple<string> miListaString;
    miListaString.insertarInicio("Hola");
    miListaString.insertarFinal("Mundo");
    miListaString.imprimir(); // Salida: Hola Mundo

    return 0;
}
