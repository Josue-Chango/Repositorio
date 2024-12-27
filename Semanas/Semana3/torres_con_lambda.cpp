#include <iostream>
using namespace std;

template <int N>
void torres_de_hanoi(char origen, char auxiliar, char destino) {
    if (N == 1) {
        std::cout << "Mover disco 1 de la torre " << origen << " a la torre " << destino << std::endl;
    } else {
        torres_de_hanoi<N - 1>(origen, destino, auxiliar);
        cout << "Mover disco " << N << " de la torre " << origen << " a la torre " << destino << endl;
        torres_de_hanoi<N - 1>(auxiliar, origen, destino);
        
        //torres_de_hanoi<N - 1>(auxiliar, origen, destino);
    }
}

int main() {
    int n = 3;
    torres_de_hanoi<3>('A', 'B', 'C');
    return 0;
}
