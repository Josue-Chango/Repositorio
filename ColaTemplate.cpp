
#include <iostream>
using namespace std;

template <typename T>
class Cola {
private:
    T *arreglo;
    int frente;
    int final;
    int tamanio;
    int elementos;

public:
    Cola(int tam) {
        tamanio = tam;
        arreglo = new T[tamanio];
        frente = 0;
        final = -1;
        elementos = 0;
    }

    bool estaVacia() {
        return elementos == 0;
    }

    bool estaLlena() {
        return elementos == tamanio;
    }

    void encolar(T elemento) {
        if (estaLlena()) {
            cout << "La cola está llena" << endl;
        } else {
            final = (final + 1) % tamanio;
            arreglo[final] = elemento;
            elementos++;
        }
    }

    T desencolar() {
        if (estaVacia()) {
            cout << "La cola está vacía" << endl;
            return T();
        } else {
            T elementoFrente = arreglo[frente];
            frente = (frente + 1) % tamanio;
            elementos--;
            return elementoFrente;
        }
    }

    T verFrente() {
        if (estaVacia()) {
            cout << "La cola está vacía" << endl;
            return T();
        } else {
            return arreglo[frente];
        }
    }
};

int main() {
    Cola<int> miColaInt(5);
    miColaInt.encolar(10);
    miColaInt.encolar(20);
    cout << "Elemento en el frente de la cola: " << miColaInt.verFrente() << endl;
    cout << "Elemento desencolado: " << miColaInt.desencolar() << endl;
    cout << "Elemento en el frente de la cola: " << miColaInt.verFrente() << endl;

    Cola<string> miColaString(3);
    miColaString.encolar("Hola");
    miColaString.encolar("Mundo");
    cout << "Elemento en el frente de la cola: " << miColaString.verFrente() << endl;
    cout << "Elemento desencolado: " << miColaString.desencolar() << endl;
    cout << "Elemento en el frente de la cola: " << miColaString.verFrente() << endl;

    return 0;
}
