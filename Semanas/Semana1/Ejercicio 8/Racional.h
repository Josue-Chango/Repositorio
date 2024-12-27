/***********************************************************************
 * Module:  Racional.h
 * Author:  josue
 * Modified: jueves, 9 de mayo de 2024 21:36:14
 * Purpose: Declaration of the class Racional
 ***********************************************************************/

#if !defined(__Class_Diagram_7_Racional_h)
#define __Class_Diagram_7_Racional_h

#include <OMatematicas.h>

class Racional : public OMatematicas
{
public:
   int getNumerador(void);
   void setNumerador(int newNumerador);
   int getDenominador(void);
   void setDenominador(int newDenominador);
   Racional();
   ~Racional();
   Racional Resta(Racional Num1, Racional Num2);

protected:
private:
   int Numerador;
   int Denominador;


};

#endif