#include <iostream>
using namespace std;


void torres_de_hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        cout << "Mover disco 1 de la torre " << origen << " a la torre " << destino << std::endl;
    } else {
        torres_de_hanoi(n - 1, origen, destino, auxiliar);
        cout << "Mover disco " << n << " de la torre " << origen << " a la torre " << destino << std::endl;
        torres_de_hanoi(n - 1, auxiliar, origen, destino);
    }
}

int main() {

    int n = 3;
    torres_de_hanoi(n, 'A', 'B', 'C');
    return 0;
}
