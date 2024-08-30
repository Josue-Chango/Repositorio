#ifndef AJEDREZ_H
#define AJEDREZ_H

#include "raylib.h"
#include <vector>
#include <utility>

using namespace std;

class Ajedrez {
private:
    static const int N = 8; // Tamaño del tablero (8x8)
    int tablero[N][N];
    int startX, startY;
    vector<pair<int, int>> movimientosCaballo = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }; // Movimientos posibles del caballo

public:
    Ajedrez(int startX, int startY);
    void dibujarTablero(int cellSize, int offset);
    void dibujarMovimientosC();
    void dibujarMovimientosCRecursivo(int x, int y, int index);
};

#endif
