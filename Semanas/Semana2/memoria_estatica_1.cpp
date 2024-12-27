#include <iostream>
using namespace std;

void incremento() {
    static int contador = 0; 
    contador++;
    cout << "El valor de count es: " << contador << endl;
}

int main() {
    cout << "Llamando a incremento() 5 veces:" << endl;
    for (int i = 0; i < 5; i++) {
        incremento();
    }

    return 0;
}
