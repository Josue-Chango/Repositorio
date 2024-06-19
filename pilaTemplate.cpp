#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

template <typename T>
class Pila {
private:
    T *arreglo;
    int cima;
    int tamanio;

public:
    Pila(int tam) {
        tamanio = tam;
        arreglo = new T[tamanio];
        cima = -1;
    }

    bool estaVacia() {
        return cima == -1;
    }

    bool estaLlena() {
        return cima == tamanio - 1;
    }

    void push(T elemento) {
        if (estaLlena()) {
            cout << "La pila está llena" << endl;
        } else {
            arreglo[++cima] = elemento;
        }
    }

    T pop() {
        if (estaVacia()) {
            cout << "La pila está vacía" << endl;
            return T();
        } else {
            return arreglo[cima--];
        }
    }

    T verCima() {
        if (estaVacia()) {
            cout << "La pila está vacía" << endl;
            return T();
        } else {
            return arreglo[cima];
        }
    }
};

int main() {
    Pila<int> miPilaInt(5);
    miPilaInt.push(10);
    miPilaInt.push(20);
    cout << "Cima de la pila: " << miPilaInt.verCima() << endl;
    cout << "Elemento extraído: " << miPilaInt.pop() << endl;
    cout << "Cima de la pila: " << miPilaInt.verCima() << endl;

    Pila<string> miPilaString(3);
    miPilaString.push("Hola");
    miPilaString.push("Mundo");
    cout << "Cima de la pila: " << miPilaString.verCima() << endl;
    cout << "Elemento extraído: " << miPilaString.pop() << endl;
    cout << "Cima de la pila: " << miPilaString.verCima() << endl;

    return 0;
}
