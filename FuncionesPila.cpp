#include <iostream>
using namespace std;

class Pila {
private:
    int *arreglo;
    int cima;
    int tamanio;

public:
    Pila(int tam) {
        tamanio = tam;
        arreglo = new int[tamanio];
        cima = -1;
    }

    bool estaVacia() {
        return cima == -1;
    }

    bool estaLlena() {
        return cima == tamanio - 1;
    }

    void push(int elemento) {
        if (estaLlena()) {
            cout << "La pila está llena" << endl;
        } else {
            arreglo[++cima] = elemento;
        }
    }

    int pop() {
        if (estaVacia()) {
            cout << "La pila está vacía" << endl;
            return -1;
        } else {
            return arreglo[cima--];
        }
    }

    int verCima() {
        if (estaVacia()) {
            cout << "La pila está vacía" << endl;
            return -1;
        } else {
            return arreglo[cima];
        }
    }
};

int main() {
    Pila miPila(5);
    miPila.push(10);
    miPila.push(20);
    cout << "Cima de la pila: " << miPila.verCima() << endl;
    cout << "Elemento extraído: " << miPila.pop() << endl;
    cout << "Cima de la pila: " << miPila.verCima() << endl;
    return 0;
}
