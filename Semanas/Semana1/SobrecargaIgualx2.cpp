#include <iostream>
#include "SobrecargaIgualx2.h"
using namespace std;

void SobrecargaIgualx2::entrada(){
    cout << "Ingrese valor: ";
    cin >> x;
    
}

bool SobrecargaIgualx2::operator==(const SobrecargaIgualx2 &obj) {
    
    return x == obj.x;
}
void SobrecargaIgualx2::salida(){
    cout << x << endl;
}
