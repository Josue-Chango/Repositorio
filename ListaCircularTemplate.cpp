
#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
};

template <typename T>
class ListaCircularSimple {
private:
    Nodo<T>* cabeza;

public:
    ListaCircularSimple() {
        cabeza = nullptr;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    void insertarInicio(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        nuevoNodo->dato = dato;

        if (estaVacia()) {
            nuevoNodo->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* ultimo = cabeza;
            while (ultimo->siguiente != cabeza) {
                ultimo = ultimo->siguiente;
            }
            ultimo->siguiente = nuevoNodo;
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        }
    }

    void insertarFinal(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        nuevoNodo->dato = dato;

        if (estaVacia()) {
            nuevoNodo->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* ultimo = cabeza;
            while (ultimo->siguiente != cabeza) {
                ultimo = ultimo->siguiente;
            }
            ultimo->siguiente = nuevoNodo;
            nuevoNodo->siguiente = cabeza;
        }
    }

    void eliminar(T dato) {
        if (estaVacia()) {
            return;
        }

        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = nullptr;

        while (actual->siguiente != cabeza && actual->dato != dato) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual->dato != dato) {
            return;
        }

        if (actual == cabeza) {
            if (actual->siguiente == cabeza) {
                cabeza = nullptr;
            } else {
                Nodo<T>* ultimo = cabeza;
                while (ultimo->siguiente != cabeza) {
                    ultimo = ultimo->siguiente;
                }
                cabeza = cabeza->siguiente;
                ultimo->siguiente = cabeza;
            }
        } else {
            anterior->siguiente = actual->siguiente;
        }

        delete actual;
    }

    void imprimir() {
        if (estaVacia()) {
            return;
        }

        Nodo<T>* actual = cabeza;
        do {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        } while (actual != cabeza);
        cout << endl;
    }
};

int main() {
    ListaCircularSimple<int> miLista;
    miLista.insertarInicio(10);
    miLista.insertarInicio(20);
    miLista.insertarFinal(30);
    miLista.imprimir(); // Salida: 20 10 30

    miLista.eliminar(10);
    miLista.imprimir(); // Salida: 20 30

    return 0;
}
