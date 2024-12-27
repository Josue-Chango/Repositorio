/***********************************************************************
 * Module:  Decimal.h
 * Author:  josue
 * Modified: jueves, 9 de mayo de 2024 20:13:27
 * Purpose: Declaration of the class Decimal
 ***********************************************************************/

#if !defined(__Class_Diagram_2_Decimal_h)
#define __Class_Diagram_2_Decimal_h

#include <OperacionesMatematicaas.h>

class Decimal : public OperacionesMatematicaas
{
public:
   float getNumero(void);
   void setNumero(float newNumero);
   Decimal();
   ~Decimal();
   float Suma(void);
   float Resta(void);
   float Multiplicacion(void);
   float Division(void);

protected:
private:
   float Numero;


};

#endif