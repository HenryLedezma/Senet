#include <iostream>
#include <fstream>
#include <sstream>
#include "ConstructorAbstractaReglas.h"

class ReglaProteccion: public ConstructorAbstractaReglas
{
public:
    ReglaProteccion();
    ~ReglaProteccion();
    /**
     @brief Verifica si dos fichas del tipo contrario generan una protección
     @param ficha ficha a mover
     @param movientos Cantidad de casillas a mover
     @param tablero tablero del juego
    */
    virtual bool regla(std::string nombre, Ficha &ficha, int movimientos, Tablero &tablero)override;
private:

};
