#include <iostream>
using namespace std;

int main() {
    int* dynamicInt = new int;
    *dynamicInt = 42;

    cout << "Valor del entero dinámico: " << *dynamicInt << endl;

    delete dynamicInt;
    return 0;
}
