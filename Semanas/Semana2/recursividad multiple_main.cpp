#include <iostream>
#include "recursividad_multiple.cpp"
using namespace std;

int main() {
    int base = 2;
    int exponente = 3;
    int resultado = potencia(base, exponente);
    cout << base << " elevado a la " << exponente << " es: " << resultado << endl;

    return 0;
}
