#pragma once
#include <string>
#include <utility>
#include "Tablero.h"

class ConstructorSerializadorAbstracto
{
public:
    ConstructorSerializadorAbstracto() = default;
    ~ConstructorSerializadorAbstracto()= default;

    /* SERIALIZADORES */
    virtual void guardar(const Tablero &tablero) = 0;
    virtual std::string  cargar(Tablero &tablero) = 0;
};

