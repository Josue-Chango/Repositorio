/**********************************************************/
/*         UNIVERSIDAD DE LAS FUEZAS ARMADAS-ESPE         */
/*                 PRUEBA 1 - PARCIAL II                  */
/*         AUTORES: REISHEL TIPAN, JORDY VISCAINO         */
/*            FECHA DE CREACIÓN: 05/07/2024               */
/*            FECHA DE MODIFICACIÓN: 07/07/2024           */
/**********************************************************/ 

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    string segundoNombre;
    string apellido;
    string cedula;
    string correo;
    string contrasenaInicial;
    string contrasena;

    Persona() = default;
    Persona(const string& n, const string& sN, const string& a, const string& c)
        : nombre(n), segundoNombre(sN), apellido(a), cedula(c) {}

    void setCorreo(const string& c) {
        correo = c;
    }

    string getCorreo() const {
        return correo;
    }

    void setContrasena(const string& c) {
        contrasena = c;
    }

    string getContrasena() const {
        return contrasena;
    }

    void setContrasenaInicial(const string& ci) {
        contrasenaInicial = ci;
    }

    string getContrasenaInicial() const {
        return contrasenaInicial;
    }
};

#endif
