/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Ejercicio de suma de numeros racionales
 * Autor:  Josue Chango
 * Creación: jueves, 9 de mayo de 2024
 * Modificación: jueves, 9 de mayo de 2024
 * Module:  Racional.h
 ***********************************************************************/

#if !defined(__Class_Diagram_3_Racional_h)
#define __Class_Diagram_3_Racional_h

#include <OperacionesMatematicas.h>

class Racional : public OperacionesMatematicas
{
public:
   int getNumerador(void);
   void setNumerador(int newNumerador);
   int getDenominador(void);
   void setDenominador(int newDenominador);
   Racional();
   ~Racional();
   int suma(Racional num1, Racional Num2);

protected:
private:
   int numerador;
   int denominador;


};

#endif