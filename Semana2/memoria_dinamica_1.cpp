#include <iostream>
using namespace std;

int main() {
    int longitud;
    cout << "Ingresa el tamaño del array: ";
    cin >> longitud;

    int* array = new int[longitud];

    for (int i = 0; i < longitud; i++) {
        array[i] = i * 2;
    }

    cout << "Contenido del array: ";
    for (int i = 0; i < longitud; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    return 0;
}
