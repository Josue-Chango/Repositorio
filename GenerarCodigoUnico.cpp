#include <iostream>
using namespace std;


#include <iostream>
#include <string>
#include <random>
#include <ctime>

std::string generarCodigoUnico() {
    // Semilla para el generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());

    // Crear una distribución uniforme de 0 a 9 para generar dígitos
    std::uniform_int_distribution<> digitos(0, 9);

    std::string codigo = "";

    // Generar 8 dígitos aleatorios para formar el código único
    for (int i = 0; i < 8; i++) {
        codigo += std::to_string(digitos(gen));
    }

    return codigo;
}

int main() {
    std::string codigoUnico = generarCodigoUnico();
    std::cout << "Código único generado: " << codigoUnico << std::endl;
    return 0;
}
