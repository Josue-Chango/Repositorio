#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;
};

template <typename T>
class ListaCircularDoble {
private:
    Nodo<T>* cabeza;

public:
    ListaCircularDoble() {
        cabeza = nullptr;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    void insertarInicio(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        nuevoNodo->dato = dato;

        if (estaVacia()) {
            nuevoNodo->anterior = nuevoNodo;
            nuevoNodo->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* ultimo = cabeza->anterior;
            ultimo->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
            nuevoNodo->anterior = ultimo;
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        }
    }

    void insertarFinal(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        nuevoNodo->dato = dato;

        if (estaVacia()) {
            nuevoNodo->anterior = nuevoNodo;
            nuevoNodo->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* ultimo = cabeza->anterior;
            ultimo->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
            nuevoNodo->anterior = ultimo;
            nuevoNodo->siguiente = cabeza;
        }
    }

    void eliminar(T dato) {
        if (estaVacia()) {
            return;
        }

        Nodo<T>* actual = cabeza;
        do {
            if (actual->dato == dato) {
                if (actual == cabeza) {
                    if (actual->siguiente == actual) {
                        cabeza = nullptr;
                    } else {
                        Nodo<T>* ultimo = cabeza->anterior;
                        cabeza = cabeza->siguiente;
                        cabeza->anterior = ultimo;
                        ultimo->siguiente = cabeza;
                    }
                } else {
                    actual->anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = actual->anterior;
                }
                Nodo<T>* temp = actual;
                actual = actual->siguiente;
                delete temp;
                return;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
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

    void imprimirInverso() {
        if (estaVacia()) {
            return;
        }

        Nodo<T>* actual = cabeza->anterior;
        do {
            cout << actual->dato << " ";
            actual = actual->anterior;
        } while (actual != cabeza->anterior);
        cout << endl;
    }
};

int main() {
    ListaCircularDoble<int> miLista;
    miLista.insertarInicio(10);
    miLista.insertarInicio(20);
    miLista.insertarFinal(30);
    miLista.imprimir(); // Salida: 20 10 30
    miLista.imprimirInverso(); // Salida: 30 10 20

    miLista.eliminar(10);
    miLista.imprimir(); // Salida: 20 30
    miLista.imprimirInverso(); // Salida: 30 20

    return 0;
}
