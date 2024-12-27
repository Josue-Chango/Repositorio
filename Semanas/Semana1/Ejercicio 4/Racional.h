/***********************************************************************
 * Module:  Racional.h
 * Author:  josue
 * Modified: jueves, 9 de mayo de 2024 21:12:17
 * Purpose: Declaration of the class Racional
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Racional_h)
#define __Class_Diagram_1_Racional_h

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
   float Sumar(Racional Num1, Racional Num2);

protected:
private:
   int Numerador;
   int Denominador;


};

#endif