#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
    private:
        string nombre;
        string apellido;
        int cedula;
        string correo;
        string password;
    public:
        Persona();
        Persona(string n1, string a, int cedula);
        Persona(string n1, string a, int cedula, string correo, string password);

        void setNombre(string n1);
        void setApellido(string a);
        void setCedula(int cedula);
        void setCorreo(string correo);
        void setPassword(string password);

        string getNombre();
        string getApellido();
        int getCedula();
        string getCorreo();
        string getPassword();
};

#endif
