/*
*   Implementación de clase,
*   Simula la regla especial
*/

#include "ReglaCasillaEspecial.h"

ReglaCasillaEspecial::ReglaCasillaEspecial()
{

}

ReglaCasillaEspecial::~ReglaCasillaEspecial()
{

}

bool ReglaCasillaEspecial::regla(std::string nombre, Ficha &ficha, int movimientos, Tablero &tablero){
    int futura_posc = ficha.getPosicion() + movimientos;
    bool casilla_especial = false;
    if (futura_posc == 25
    || futura_posc == 27
    || futura_posc == 28) {
      casilla_especial = true;
    }
    return casilla_especial;
}
