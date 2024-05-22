#include <iostream>

using namespace std;


//Función average para calcular el promedio de dos valores


template <typename T>
T average(T a, T b) {
    return (a + b) / 2;
}

int main (){
    double a=2.5, b=3.7;
    float c = average(a,b);
    cout << "primedio = " << c;
    return 0;
}