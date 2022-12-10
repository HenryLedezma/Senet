/*
*   Implementación de clase,
*   Simula la regla proteccion
*/

#include "ReglaProteccion.h"

ReglaProteccion::ReglaProteccion()
{

}
ReglaProteccion::~ReglaProteccion()
{

}
bool ReglaProteccion::regla(std::string nombre, Ficha &ficha, int movimientos, Tablero &tablero){
    int futura_posc = ficha.getPosicion() + movimientos;
    int adversario = 0;
    (ficha.getJugadorID() == 1) ? adversario = 2 :  adversario = 1;
    bool existeProteccion = false;

    /* Caso ficha adelante */
    // Revisa que la casilla y las adyacentes estén ocupadas
    if (tablero.tablero[futura_posc].ocupada == true
    && tablero.tablero[futura_posc + 1].ocupada == true) {
      // Revisa que la casilla actual y adyacente pertenezca al adversario
      if (tablero.tablero[futura_posc].ficha.getJugadorID() == adversario
      && tablero.tablero[futura_posc + 1].ficha.getJugadorID() == adversario) {
        existeProteccion = true;
        cout << "Existe una barrea!\n";
        return existeProteccion;
      }
    }
    /* Caso ficha detrás */
    // Revisa que la casilla y las adyacentes estén ocupadas
    if (tablero.tablero[futura_posc].ocupada == true
    && tablero.tablero[futura_posc - 1].ocupada == true) {
      // Revisa que la casilla actual y adyacente pertenezca al adversario
      if (tablero.tablero[futura_posc].ficha.getJugadorID() == adversario
      && tablero.tablero[futura_posc - 1].ficha.getJugadorID() == adversario) {
        existeProteccion = true;
        cout << "Existe una barrea!\n";
        return existeProteccion;
      }
    }
    return existeProteccion;
}
