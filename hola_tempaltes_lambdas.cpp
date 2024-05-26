#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <functional>
#include <algorithm>

template <typename T>
void ingreso(T *p, int t) {
    for (int i = 0; i < t; i++) {
        scanf("%d", &p[i]);
    }
}

template <typename T>
void impresion(T *p, int t) {
    std::cout << "{ ";
    std::for_each(p, p + t, [&](T x) { std::cout << x << " "; });
    std::cout << "}" << std::endl;
}

template <typename T>
void proceso(T *p, int t, T e) {
    std::for_each(p, p + t, [&](T &x) { x *= e; });
}

int main() {
    int t, e;
    int *ptr = new int[10];

    std::cout << "Ingrese el tamaño: ";
    std::cin >> t;

    std::cout << "Ingrese los valores: ";
    ingreso(ptr, t);

    std::cout << "Valores originales: ";
    impresion(ptr, t);

    std::cout << "Ingrese el escalar: ";
    std::cin >> e;

    proceso(ptr, t, e);

    std::cout << "Valores procesados: ";
    impresion(ptr, t);

    delete[] ptr;
    return 0;
}
