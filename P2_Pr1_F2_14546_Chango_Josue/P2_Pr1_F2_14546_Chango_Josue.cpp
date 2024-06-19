/*Enunciado 2
escriba un programa que genere todas las combinaciones de caracteres de una longitud dada desde 
una cadena de entrada y verifique si cada combinacion es una palabra valida segun un diccionario 
predefinido

Detalles:
1 el programa debe pedir al usuario que ingrese una cadena de caracteres y la longitud de las combinaciones 
2 Generar todas las combinaciones posibles de la longitud dada 
3 Comparar cada combinacoion con las palabras en un diccionario predefinido (utilizar archivo 
   plano para realizar la busqueda de las palabras)
4 Imprimir todas las combinaciones que sean palabras válidas*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> generarCombinaciones(const string& entrada, int LongitudDada) {
    vector<string> combinaciones;
    string grupo(LongitudDada, '\0');
    copy(entrada.begin(), entrada.begin() + LongitudDada, grupo.begin());

    do {
        combinaciones.push_back(grupo);
    } while (next_permutation(grupo.begin(), grupo.end()));

    return combinaciones;
}

vector<string> leerDiccionario(const string& nombreArchivo) {
    vector<string> diccionario;
    ifstream archivo(nombreArchivo);
    string palabra;

    if (archivo.is_open()) {
        while (getline(archivo, palabra)) {
            diccionario.push_back(palabra);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo del diccionario." << endl;
    }

    return diccionario;
}

int main() {
    int longitud;
    cout << "Ingresa la longitud de la cadena de caracteres: ";
    cin >> longitud;
    cin.ignore();

    string cadena;
    cout << "Ingresa la cadena de caracteres: ";
    getline(cin, cadena);

    vector<string> diccionario = leerDiccionario("Diccionario.txt");
    vector<string> combinaciones = generarCombinaciones(cadena, longitud);

    cout << "Combinaciones validas:" << endl;
    for (const auto& grupo : combinaciones) {
        if (find(diccionario.begin(), diccionario.end(), grupo) != diccionario.end()) {
            cout << grupo << endl;
        }
    }

    return 0;
}
