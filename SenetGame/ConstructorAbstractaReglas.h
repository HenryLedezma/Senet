#pragma once
#include <string>
#include <utility>
#include "Tablero.h"
#include "Ficha.h"

class ConstructorAbstractaReglas
{
public:
    ConstructorAbstractaReglas() = default;
    ~ConstructorAbstractaReglas()= default;

    /* SERIALIZADORES */

    virtual bool regla(std::string nombre, Ficha &ficha, int movimientos, Tablero &tablero)= 0;

};
