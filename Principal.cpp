#include <iostream>
#include "Frac.h"
using namespace std;


int main(){
    Frac F1, F2, resultado;

    system("cls");

    cout << "Ingresar la primera fracion: " << endl;
    F1.in();

    cout << "Ingresar la segunda fracion: " << endl;
    F2.in();

    resultado = F1 * F2;
    resultado.out();

    return 0;

}