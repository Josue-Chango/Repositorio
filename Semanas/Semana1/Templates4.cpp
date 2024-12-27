#include <iostream>
using namespace std;


//Función swap para intercambiar dos valores


template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    double a = 1.2, b = 2.3;
    cout << "Antes del swap: a = " << a << ", b = " << b << endl;
    std::swap(a, b);
    cout << "Despues del swap: a = " << a << ", b = " << b << endl;
    return 0;
}