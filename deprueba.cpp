#include <iostream>
#include <string>

int main() {
    std::string palabra;
    std::cout << "Introduce una palabra en inglés para traducir: ";
    std::getline(std::cin, palabra);
    std::cout << "Has introducido: " << palabra << std::endl;
    return 0;
}
