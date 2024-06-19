#include <iostream>
using namespace std;

class Cola {
private:
    int *arreglo;
    int frente;
    int final;
    int tamanio;
    int elementos;

public:
    Cola(int tam) {
        tamanio = tam;
        arreglo = new int[tamanio];
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

    void encolar(int elemento) {
        if (estaLlena()) {
            cout << "La cola está llena" << endl;
        } else {
            final = (final + 1) % tamanio;
            arreglo[final] = elemento;
            elementos++;
        }
    }

    int desencolar() {
        if (estaVacia()) {
            cout << "La cola está vacía" << endl;
            return -1;
        } else {
            int elementoFrente = arreglo[frente];
            frente = (frente + 1) % tamanio;
            elementos--;
            return elementoFrente;
        }
    }

    int verFrente() {
        if (estaVacia()) {
            cout << "La cola está vacía" << endl;
            return -1;
        } else {
            return arreglo[frente];
        }
    }
};

int main() {
    Cola miCola(5);
    miCola.encolar(10);
    miCola.encolar(20);
    cout << "Elemento en el frente de la cola: " << miCola.verFrente() << endl;
    cout << "Elemento desencolado: " << miCola.desencolar() << endl;
    cout << "Elemento en el frente de la cola: " << miCola.verFrente() << endl;
    return 0;
}
