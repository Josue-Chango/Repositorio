/***********************************************************************
 * Module:  OperacionesMatematicas.h
 * Author:  josue
 * Modified: jueves, 9 de mayo de 2024 19:40:59
 * Purpose: Declaration of the class OperacionesMatematicas
 ***********************************************************************/

#if !defined(__Class_Diagram_1_OperacionesMatematicas_h)
#define __Class_Diagram_1_OperacionesMatematicas_h

#include <Racional.h>

class OperacionesMatematicas
{
public:
   virtual float Sumar(Racional Num1, Racional Num2)=0;

protected:
private:

};

#endif