#include <iostream>

using namespace std;


//Funcion eleva al cuadrado


auto cuadrado = [](int x) { return x * x; };



int main (){
    cout << cuadrado(5) << endl; // imprime: 25
    return 0;
}