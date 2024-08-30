#include "raylib.h"
#include <chrono>
#include <vector>
#include <iostream>
#include <functional>

// Define el tamaño de la ventana
const int screenWidth = 800;
const int screenHeight = 600;

// Función de medición de tiempo usando templates
template<typename Func>
std::vector<float> MedirTiempo(Func&& funcion, const std::vector<int>& tamaños) {
    std::vector<float> tiempos;
    tiempos.reserve(tamaños.size());

    for (int tamaño : tamaños) {
        auto start = std::chrono::high_resolution_clock::now();

        // Llamar a la función con el tamaño dado
        funcion(tamaño);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duracion = end - start;
        tiempos.push_back(duracion.count());
    }

    return tiempos;
}

// Función que grafica los resultados con un plano cartesiano
void GraficarOrdenDeComplejidad(const std::vector<int>& tamaños, const std::vector<float>& tiempos, Color color) {
    // Dibujar plano cartesiano
    DrawLine(50, 550, 750, 550, BLACK); // Eje X
    DrawLine(50, 550, 50, 50, BLACK);  // Eje Y

    // Etiquetas de los ejes
    DrawText("Tamaño", 700, 560, 20, BLACK);
    DrawText("Tiempo", 10, 50, 20, BLACK);

    // Normalizar y graficar
    for (size_t i = 1; i < tamaños.size(); i++) {
        float x1 = 50 + (tamaños[i - 1] - tamaños[0]) / (float)(tamaños.back() - tamaños[0]) * 700;
        float y1 = 550 - (tiempos[i - 1] / tiempos.back()) * 500;
        float x2 = 50 + (tamaños[i] - tamaños[0]) / (float)(tamaños.back() - tamaños[0]) * 700;
        float y2 = 550 - (tiempos[i] / tiempos.back()) * 500;

        DrawLine((int)x1, (int)y1, (int)x2, (int)y2, color);
    }
}

// Funciones de ejemplo con diferentes complejidades
void constantTimeFunction(int tamaño) {
    int result = tamaño * tamaño; // Operación constante
}

void linearTimeFunction(int tamaño) {
    std::vector<int> arr(tamaño);
    for (int i = 0; i < tamaño; ++i) {
        arr[i] = i * i;
    }
}

void quadraticTimeFunction(int tamaño) {
    std::vector<int> arr(tamaño);
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            int result = arr[i] * arr[j];
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Búsqueda binaria para O(log n)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // No encontrado
}

void binarySearchWrapper(int tamaño) {
    int* arr = new int[tamaño];
    for (int i = 0; i < tamaño; ++i) arr[i] = i;
    binarySearch(arr, tamaño, tamaño / 2);
    delete[] arr;
}



int main() {
    // Inicializar la ventana
    InitWindow(screenWidth, screenHeight, "Graficar Orden de Complejidad");

    // Definir los tamaños de entrada
    std::vector<int> tamaños = { 10, 50, 100, 200, 400, 800, 1600 };

    // Medir tiempos para cada función
    auto tiemposLineales = MedirTiempo(linearTimeFunction, tamaños);
    //auto tiemposCuadraticos = MedirTiempo(quadraticTimeFunction, tamaños);
    //auto tiemposLogaritmicos = MedirTiempo(binarySearch, tamaños);
    //auto tiemposFuncion = MedirTiempo( , tamaños);


    // Configurar el sistema de coordenadas
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Graficar los tiempos de ejecución
        GraficarOrdenDeComplejidad(tamaños, tiemposLineales, RED);
        //GraficarOrdenDeComplejidad(tamaños, tiemposCuadraticos, BLUE);
        //GraficarOrdenDeComplejidad(tamaños, tiemposLogaritmicos, GREEN);
        //GraficarOrdenDeComplejidad(tamaños, tiemposFuncion, GREEN);

        DrawText("Orden de Complejidad", 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow(); // Cierra la ventana y libera recursos

    return 0;
}