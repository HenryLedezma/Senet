#include <iostream>
#include <fstream>
#include <sstream>
#include "ConstructorAbstractaReglas.h"

class ReglaBarrera : public ConstructorAbstractaReglas
{
public:
    ReglaBarrera();
    ~ReglaBarrera();
    /**
     @brief Verifica si tres fichas del tipo contrario generan un barrera
     @param ficha ficha a mover
     @param movientos Cantidad de casillas a mover
     @param tablero tablero del juego
    */
    virtual bool regla(std::string nombre, Ficha &ficha, int movimientos, Tablero &tablero)override;
private:

};
