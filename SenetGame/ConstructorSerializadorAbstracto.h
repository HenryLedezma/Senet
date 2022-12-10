/*
*   Clase que es un constructor serializar abstracto
*/

#pragma once
#include <string>
#include <utility>
#include "Tablero.h"

/**
 @brief Serializador Abstracto
*/
class ConstructorSerializadorAbstracto
{
public:
    /**
        @brief Default constructor
    */
    ConstructorSerializadorAbstracto() = default;
    ~ConstructorSerializadorAbstracto()= default;

    /* SERIALIZADORES */
    /**
        @brief Se encarga de guardar la partida actual
        @param tablero tablero del juego
    */
    virtual void guardar(const Tablero &tablero) = 0;

    /**
        @brief Se encarga de cargar la partida
        @param tablero tablero del juego
    */
    virtual std::string  cargar(Tablero &tablero) = 0;
};

