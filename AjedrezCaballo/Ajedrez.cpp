#include "Ajedrez.h"

// Constructor para inicializar la posición del caballo
Ajedrez::Ajedrez(int startX, int startY) : startX(startX), startY(startY) {
    // Inicializamos el tablero en 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tablero[i][j] = 0;
        }
    }
}

// Función para dibujar el tablero y los movimientos del caballo
void Ajedrez::dibujarTablero(int cellSize, int offset) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Dibujar casillas en blanco y negro
            Color color = ((i + j) % 2 == 0) ? WHITE : BLACK;
            DrawRectangle(j * cellSize + offset, i * cellSize + offset, cellSize, cellSize, color);

            // Dibujar los movimientos alcanzados por el caballo como puntos rojos
            if (tablero[i][j] == 1) {
                DrawCircle(j * cellSize + offset + cellSize / 2, i * cellSize + offset + cellSize / 2, cellSize / 5, RED);
            }
        }
    }

    // Dibujar la letra "C" en la posición inicial del caballo
    DrawText("C", startY * cellSize + offset + cellSize / 4, startX * cellSize + offset + cellSize / 6, cellSize / 2, BLUE);
}

// Función para calcular y marcar los movimientos posibles del caballo
/*void Ajedrez::dibujarMovimientosC() {
    // Marcar los movimientos posibles del caballo en el tablero
    for (auto mov : movimientosCaballo) {
        int nuevoX = startX + mov.first;
        int nuevoY = startY + mov.second;

        // Verificar si el movimiento es válido dentro del tablero
        if (nuevoX >= 0 && nuevoX < N && nuevoY >= 0 && nuevoY < N) {
            tablero[nuevoX][nuevoY] = 1; // Marca la posición en el tablero como alcanzable
        }
    }
}*/

void Ajedrez::dibujarMovimientosCRecursivo(int x, int y, int index) {
    // Movimientos posibles del caballo
    vector<pair<int, int>> movimientosCaballo = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-1, -2}, {1, -2}, {2, -1}, {-2, -1}
    };

    // Condición de parada: si ya se han procesado todos los movimientos
    if (index >= movimientosCaballo.size()) return;

    // Aplicar el movimiento actual
    auto mov = movimientosCaballo[index];
    int nuevoX = x + mov.first;
    int nuevoY = y + mov.second;

    // Verificar si el movimiento es válido dentro del tablero
    if (nuevoX >= 0 && nuevoX < N && nuevoY >= 0 && nuevoY < N) {
        tablero[nuevoX][nuevoY] = 1; // Marca la posición en el tablero como alcanzable
    }

    // Llamada recursiva para el siguiente movimiento
    dibujarMovimientosCRecursivo(x, y, index + 1);
}

// Método que inicia el proceso de marcar los movimientos del caballo
void Ajedrez::dibujarMovimientosC() {
    // Marca la posición inicial del caballo
    tablero[startX][startY] = 1; // Opción para marcar la posición inicial
    dibujarMovimientosCRecursivo(startX, startY, 0); // Inicia la recursión
}
