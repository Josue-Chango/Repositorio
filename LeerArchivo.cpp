#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

void leerArchivo(string nombreA) {
    ifstream archivo;
    archivo.open(nombreA);

    if (archivo.is_open()) {
        stringstream contenido;
        contenido << archivo.rdbuf();
        archivo.close();

        cout << contenido.str() << endl;
    } else {
        cout << "No se pudo abrir el archivo " << nombreA << "." << endl;
    }
}