#include <iostream>
#include "recursividad_indirecta.cpp"
using namespace std;


int main() {
    int num = 5;
    int result = fivonaci(num);
    cout << "El término " << num << " de la serie de Fibonacci es: " << result << endl;

    return 0;
}
