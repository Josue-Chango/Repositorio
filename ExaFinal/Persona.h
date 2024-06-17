#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
private:
    string nombre1;
    string nombre2;
    string apellido;
    string cedula;

public:
    Persona();
    Persona(string n1, string n2, string a);

    void setNombre1(string n1);
    void setNombre2(string n2);
    void setApellido(string a);
    void setCedula(string c);

    string getNombre1();
    string getNombre2();
    string getApellido();
    string getCedula();
    string generarCorreo();
    string generarpasword();
    string generarencriptado(string);
    bool validarCedula();
    string generarID();
};

#endif // PERSONA_H
