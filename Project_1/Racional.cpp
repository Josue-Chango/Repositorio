/***********************************************************************
 * Module:  Racional.cpp
 * Author:  josue
 * Modified: miércoles, 8 de mayo de 2024 22:21:38
 * Purpose: Implementation of the class Racional
 ***********************************************************************/

#include "Racional.h"

////////////////////////////////////////////////////////////////////////
// Name:       Racional::getNumerador()
// Purpose:    Implementation of Racional::getNumerador()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Racional::getNumerador(void)
{
   return numerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::setNumerador(int newNumerador)
// Purpose:    Implementation of Racional::setNumerador()
// Parameters:
// - newNumerador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Racional::setNumerador(int newNumerador)
{
   numerador = newNumerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::getDenominador()
// Purpose:    Implementation of Racional::getDenominador()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Racional::getDenominador(void)
{
   return denominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::setDenominador(int newDenominador)
// Purpose:    Implementation of Racional::setDenominador()
// Parameters:
// - newDenominador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Racional::setDenominador(int newDenominador)
{
   denominador = newDenominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::Racional()
// Purpose:    Implementation of Racional::Racional()
// Return:     
////////////////////////////////////////////////////////////////////////

Racional::Racional()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Racional::~Racional()
// Purpose:    Implementation of Racional::~Racional()
// Return:     
////////////////////////////////////////////////////////////////////////

Racional::~Racional()
{
   // TODO : implement
}