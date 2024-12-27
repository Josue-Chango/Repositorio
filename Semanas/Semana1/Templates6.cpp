#include <iostream>
#include <vector>

using namespace std;


//Función find para buscar un elemento en un vector:



template <typename T>
T Buscar(const vector<T>& v, const T& element) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == element) {
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> VectorInt = {10, 20, 30, 40, 50};
    int BuscarValor = 30;
    int Espacio = Buscar(VectorInt, BuscarValor);
    if (Espacio == -1) {
        cout << "Elemento " << BuscarValor << " no se encuentra en el vector" << endl;
    } else {
        cout << "Elemento " << BuscarValor << " encontrado en el espacio " << Espacio << "." << endl;
    }

    return 0;
}