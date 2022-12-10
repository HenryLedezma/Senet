#include <iostream>
#include <fstream>
#include <sstream>
#include "ConstructorAbstractaReglas.h"

/**
 @brief Simula la regla especial
*/
class ReglaCasillaEspecial : public ConstructorAbstractaReglas
{
public:
    ReglaCasillaEspecial();
    ~ReglaCasillaEspecial();
    /**
     @brief Verifica si una ficha cae en las casillas 26, 28 o 29
     @param ficha ficha a mover
     @param movientos Cantidad de casillas a mover
     @param tablero tablero del juego
    */
    virtual bool regla(std::string nombre, Ficha &ficha, int movimientos, Tablero &tablero)override;
private:

};
