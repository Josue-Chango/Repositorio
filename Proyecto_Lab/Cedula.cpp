#include <iostream>
#include <string>

bool validarCedulaEcuatoriana(const std::string& cedula) {
    if (cedula.length() != 10) {
        return false; // La cédula debe tener 10 dígitos
    }

    int coeficientes[9] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int verificador = std::stoi(cedula.substr(9, 1));
    int suma = 0;

    for (int i = 0; i < 9; i++) {
        int digito = std::stoi(cedula.substr(i, 1)) * coeficientes[i];
        suma += (digito > 9) ? digito - 9 : digito;
    }

    int residuo = suma % 10;
    int resultado = (residuo == 0) ? 0 : 10 - residuo;

    return (resultado == verificador);
}

/*int main() {
    std::string cedula;
    std::cout << "Ingrese el número de cédula: ";
    std::cin >> cedula;

    if (validarCedulaEcuatoriana(cedula)) {
        std::cout << "La cédula ecuatoriana ingresada es válida." << std::endl;
    } else {
        std::cout << "La cédula ecuatoriana ingresada no es válida." << std::endl;
    }

    return 0;
}*/
