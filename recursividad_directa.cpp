#include <iostream>
using namespace std;

int factorial(int n) {
    // Caso base: factorial de 0 es 1
    if (n == 0) {
        return 1;
    } else {
        // Llamada recursiva para calcular el factorial
        return n * factorial(n - 1);
    }
}

