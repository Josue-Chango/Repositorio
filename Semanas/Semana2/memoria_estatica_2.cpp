#include <iostream>
using namespace std;

void imprimirFibonacci(int n) {
    static int a = 0, b = 1;
    cout << b << " ";
    int temp = b;
    b = a + b;
    a = temp;
    n--;
    if (n > 0) {
        imprimirFibonacci(n);
    }
}

int main() {
    cout << "Primeros 10 números de Fibonacci: ";
    imprimirFibonacci(10);
    cout << std::endl;
    return 0;
}
