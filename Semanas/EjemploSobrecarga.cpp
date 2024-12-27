#include <iostream>
#include "SobrecargaIgualx2.h"

using namespace std;

int main() {
    SobrecargaIgualx2 num1, num2, resultado;
    system("cls");

    cout << endl;
    num1.entrada();

    cout << endl;
    num2.entrada();

    cout << "Comparando numeros: " << endl;
    num1.salida();
    cout << "y " << endl;
    num2.salida();

    if (num1 == num2) {
        cout << "Los números son iguales." << endl;
    } else {
        cout << "Los números son diferentes." << endl;
    }

    return 0;
}

