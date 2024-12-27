#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
void imprimir_vector(const vector<T>& datos) {
    // Función lambda para imprimir un elemento
    auto imprimir = [](const T& elemento) {
        cout << elemento << " ";
    };

    // Aplicar la función lambda a cada elemento del vector
    for_each(datos.begin(), datos.end(), imprimir);
    cout << "\n";
}

int main() {
    // Prueba con un vector de enteros
    vector<int> numeros = {5, 2, 8, 1, 9};
    imprimir_vector(numeros);

    // Prueba con un vector de cadenas
    vector<string> nombres = {"Juan", "Maria", "Pedro", "Azaela"};
    imprimir_vector(nombres);

    return 0;
}
