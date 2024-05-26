/***********************************************************************
 * Module:  Racional.h
 * Author:  josue
 * Modified: miércoles, 8 de mayo de 2024 22:21:38
 * Purpose: Declaration of the class Racional
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Racional_h)
#define __Class_Diagram_1_Racional_h

class Racional
{
public:
   int getNumerador(void);
   void setNumerador(int newNumerador);
   int getDenominador(void);
   void setDenominador(int newDenominador);
   Racional();
   ~Racional();

protected:
private:
   int numerador;
   int denominador;


};

#endif