#include <iostream>
#include "Frac.h"
using namespace std;

void Frac::in(){
    cout << "Ingrese el numerador: ";
    cin >> a;
    cout << "Ingrese el denominador: ";
    cin >> b;
}

Frac Frac::operator*(const Frac &obj){
    Frac temporal;
    temporal.a = a * obj.a;
    temporal.b = b * obj.b;
    return temporal;
}
void Frac::out(){
    cout << "La multiplicacion de las fracciones: " << a << "/" << b << endl;
}