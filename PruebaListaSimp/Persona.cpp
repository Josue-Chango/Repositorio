#include "Persona.h"
#include <algorithm> 
#include <cctype>    

Persona::Persona() : nombre(""), apellido(""), cedula(0), correo(""), password("") {}

Persona::Persona(string n1, string a, int cedula) : nombre(n1), apellido(a), cedula(cedula){}

Persona::Persona(string n1, string a, int cedula, string co, string pass) : nombre(n1), apellido(a), cedula(cedula),  correo(co), password(pass) {}

void Persona::setNombre(string n1) {
    nombre = n1;
}

void Persona::setApellido(string a) {
    apellido = a;
}

void Persona::setCedula(int c) {
    cedula = c;
}

int Persona::getCedula() {
    return cedula;
}

string Persona::getNombre() {
    return nombre;
}

string Persona::getApellido() {
    return apellido;
}

void Persona::setCorreo(string correo) {
    this->correo = correo;
}

string Persona::getCorreo() {
    return correo;
}

void Persona::setPassword(string pass) {
    this->password = pass;
}

string Persona::getPassword() {
    return password;
}