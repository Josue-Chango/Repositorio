/*               UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
                 DESCRIPCION DEL PROBLEMA: 9 REINAS
            AUTOR: GERMÁN CÁCERES, JOSUE CHANGO, BRYAN JACOME- GRUPO 3
                    FECHA DE CREACIÓN: 20-08-2024
                  FECHA DE MODIFICACIÓN: 20-08-2024             */

#include <iostream>
#include <vector>

using namespace std;

const int N = 9; // Número de reinas

// Función para verificar si es seguro colocar una reina en (fila, col)
bool esSeguro(vector<int>& posicion, int fila, int col) {
    for (int i = 0; i < fila; i++) {
        // Verificar si hay una reina en la misma columna o en las diagonales
        if (posicion[i] == col || 
            posicion[i] - i == col - fila || 
            posicion[i] + i == col + fila) {
            return false;
        }
    }
    return true;
}

// Función recursiva para resolver el problema
void resolverNReinas(vector<int>& posicion, int fila, int& count) {
    if (fila == N) {
        count++; // Encontró una solución
        return;
    }

    for (int col = 0; col < N; col++) {
        if (esSeguro(posicion, fila, col)) {
            posicion[fila] = col; // Colocar reina
            resolverNReinas(posicion, fila + 1, count); // Llamada recursiva
        }
    }
}

int main() {
    vector<int> posicion(N); // Almacena las posiciones de las reinas
    int count = 0; // Contador de soluciones
    resolverNReinas(posicion, 0, count); // Iniciar la solución

    cout << "Total de soluciones para 9 reinas: " << count << endl;

    return 0;
}
