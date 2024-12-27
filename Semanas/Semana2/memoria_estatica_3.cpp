#include <iostream>
using namespace std;

float sumNumbers(float num) {
    static float total = 0.0;
    total += num;
    return total;
}

int main() {
    cout << "Suma acumulada: " << sumNumbers(10.5) << endl;
    cout << "Suma acumulada: " << sumNumbers(5.2) << endl;
    cout << "Suma acumulada: " << sumNumbers(7.8) << endl;
    return 0;
}
