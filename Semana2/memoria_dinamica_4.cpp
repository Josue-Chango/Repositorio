#include <iostream>
using namespace std;
#include <cstring>


int main() {
    int n=20;
    char* dynamicString = new char[n];
    strcpy(dynamicString, "Hola, mundo!");

    cout << "Contenido de la cadena dinámica: " << dynamicString << endl;

    delete[] dynamicString;
    return 0;
}
