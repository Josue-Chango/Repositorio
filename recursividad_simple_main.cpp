#include <iostream>
#include "recursividad_simple.cpp"
using namespace std;

int main() {
    int num = 5;
    int resultado = sumaNaturales(num);
    cout << "La suma de los primeros " << num << " números naturales es: " << resultado << endl;

    return 0;
}
