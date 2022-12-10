#pragma once
#include <string>
#include <utility>
#include "Tablero.h"
#include "Ficha.h"

/**
 @brief Constructor Abstracto de Reglas
*/
class ConstructorAbstractaReglas
{
public:
    /**
        @brief Default constructor
    */
    ConstructorAbstractaReglas() = default;
    ~ConstructorAbstractaReglas()= default;

    /* SERIALIZADORES */
    /**
        @brief Constructor abstracto de regla
        @param nombre Nombre de la regla
        @param ficha Ficha a mover
        @param movimientos Cantidad de casillas a mover
        @param tablero Tablero del juego
    */
    virtual bool regla(std::string nombre, Ficha &ficha, int movimientos, Tablero &tablero)= 0;

};
