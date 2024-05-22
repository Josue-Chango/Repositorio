#include <iostream>
using namespace std;

//Funcion que comparar


auto comparar = [](int a, int b) { return a < b; };

int main(){
    cout << boolalpha << comparar(10, 20) << endl; // imprime: true
    return 0;
}