#include <iostream>
using namespace std;

void torres_hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
    } else {
        torres_hanoi(n - 1, origen, auxiliar, destino);
        cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
        torres_hanoi(n - 1, auxiliar, destino, origen);
    }
}

int main() {
    int n = 4;
    torres_hanoi(n, 'A', 'B', 'C');
    return 0;
}
