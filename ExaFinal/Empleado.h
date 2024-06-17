#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"

class Empleado {
private:
    float sueldo;
    int id;

public:
    Empleado(float sueldo, int id);
    float getSueldo();
    void setSueldo(float);
    int getId();
    void ingresoSueldo();
    void agregarSueldo(string, string, string);
    bool validarSaldo(string, string);
    bool modificarSueldo(string, string, string);
};

#endif // EMPLEADO_H
