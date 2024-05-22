#include <iostream>
#include <vector>
using namespace std;


//Función sum para calcular la suma de los elementos de un vector:


template <typename T>
T suma(const vector<T>& v) {
    T result = 0;
    for (const auto& element : v) {
        result += element;
    }
    return result;
}

int main(){
    vector<double> VectorD = {2.5 , 3.5 , 4.5 , 5.5};
    double Resultado = suma(VectorD);
    cout << "Resultado = " << Resultado;
    return 0;
}