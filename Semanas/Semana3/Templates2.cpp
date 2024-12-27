#include <iostream>
using namespace std;

//Función max para encontrar el máximo de dos valores


template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << std::max(10, 20) << endl; // Output: 20
    cout << std::max(3.14, 2.71) << endl; // Output: 3.14
    return 0;
}
