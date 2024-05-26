/***********************************************************************
 * Module:  Enteros.h
 * Author:  josue
 * Modified: jueves, 9 de mayo de 2024 22:27:02
 * Purpose: Declaration of the class Enteros
 ***********************************************************************/

#if !defined(__Class_Diagram_8_Enteros_h)
#define __Class_Diagram_8_Enteros_h

#include <OMatematicas.h>

class Enteros : public OMatematicas
{
public:
   int getNum(void);
   void setNum(int newNum);
   Enteros();
   ~Enteros();
   int Suma(int Num1, int Num2);
   int Reste(int Num1, int Num2);
   int Multiplicacion(int Num1, int Num2);
   int Division(int Num1, int Num2);

protected:
private:
   int Num;


};

#endif