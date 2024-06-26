#include <iostream>

int sumaNaturales(int n) {
    if (n == 0) {
        return 0; // Caso base
    } else {
        return n + sumaNaturales(n - 1); // Llamada recursiva para sumar los números anteriores al nuemro dado
    }
}