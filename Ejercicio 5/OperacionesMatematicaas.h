/***********************************************************************
 * Module:  OperacionesMatematicaas.h
 * Author:  josue
 * Modified: jueves, 9 de mayo de 2024 20:06:37
 * Purpose: Declaration of the class OperacionesMatematicaas
 ***********************************************************************/

#if !defined(__Class_Diagram_2_OperacionesMatematicaas_h)
#define __Class_Diagram_2_OperacionesMatematicaas_h

class OperacionesMatematicaas
{
public:
   virtual float Suma(void)=0;
   virtual float Resta(void)=0;
   virtual float Multiplicacion(void)=0;
   virtual float Division(void)=0;

protected:
private:

};

#endif