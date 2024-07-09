/**********************************************************/
/*       UNIVERSIDAD DE LAS FUEZAS ARMADAS-ESPE           */
/*                 PRUEBA 1 - PARCIAL II                  */
/*         AUTORES: REISHEL TIPAN, JORDY VISCAINO         */
/*            FECHA DE CREACIÓN: 05/07/2024               */
/*            FECHA DE MODIFICACIÓN: 07/07/2024           */
/**********************************************************/

#ifndef NODO_H
#define NODO_H

#include "Persona.h"

class Nodo {
public:
    Persona dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(const Persona& p) : dato(p), siguiente(nullptr), anterior(nullptr) {}
};

#endif
