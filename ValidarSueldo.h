#ifndef VALIDARSUELDO_H
#define VALIDARSUELDO_H
#include <string>

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
#endif 