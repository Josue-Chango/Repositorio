/***********************************************************************
 * Module:  OMatematicas.h
 * Author:  josue
 * Modified: jueves, 9 de mayo de 2024 22:25:41
 * Purpose: Declaration of the class OMatematicas
 ***********************************************************************/

#if !defined(__Class_Diagram_8_OMatematicas_h)
#define __Class_Diagram_8_OMatematicas_h

class OMatematicas
{
public:
   virtual int Suma(int Num1, int Num2)=0;
   virtual int Reste(int Num1, int Num2)=0;
   virtual int Multiplicacion(int Num1, int Num2)=0;
   virtual int Division(int Num1, int Num2)=0;

protected:
private:

};

#endif