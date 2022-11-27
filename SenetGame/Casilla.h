#ifndef CASILLA_H
#define CASILLA_H
#include "Ficha.h"

/**
 @brief Simula ser una casilla del tablero
*/
class Casilla {
public:
    /**
       @brief Constructor de casilla
       @param ocupada Identifica si se encuentra ocupada
       @param bloqueada Identifica si se encuentra bloqueada
       @param ficha Representa una ficha
    */
    bool ocupada = 0;
    int bloqueada = 0;
    Ficha ficha;
    Casilla();

};

#endif // CASILLA_H
