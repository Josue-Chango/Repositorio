#include "raylib.h"
#include "Ajedrez.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    const int margen = 10; // Margen de 1 cm (asumiendo 10 píxeles por cm)
    const int cellSize = 80; // Tamaño de cada celda en píxeles (ajústalo según prefieras)
    const int boardSize = cellSize * 8; // Tamaño total del tablero (sin márgenes)
    const int screenWidth = boardSize + margen * 2; // Ancho de la ventana
    const int screenHeight = boardSize + margen * 2; // Alto de la ventana

    InitWindow(screenWidth, screenHeight, "Ajedrez");

    int caballoX, caballoY;
    srand(time(0)); // Inicializa la semilla para números aleatorios
    caballoX = rand() % 8; // Posición aleatoria en X
    caballoY = rand() % 8; // posicion aleatoria en Y

    cout<<caballoX<<endl;
    cout<<caballoY<<endl;

    Ajedrez caballo(caballoX, caballoY);

    
    caballo.dibujarMovimientosC();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        caballo.dibujarTablero(cellSize, margen);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
