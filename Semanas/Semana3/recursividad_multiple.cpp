#include <iostream>

int potencia(int base, int exponente) {
    if (exponente == 0) {
        return 1; // Caso base
    } else {
        return base * potencia(base, exponente - 1); // Llamada recursiva para calcular la potencia
    }
}