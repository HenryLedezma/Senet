#include "ReglaBarrera.h"

ReglaBarrera::ReglaBarrera()
{

}

ReglaBarrera::~ReglaBarrera()
{

}

bool ReglaBarrera::regla(std::string nombre, Ficha &ficha, int movimientos, Tablero &tablero){
    // Verifica que las casilla a verificar sí se encuentre ocupada
    if (tablero.tablero[ficha.getPosicion()].ocupada == true) {
      int barrera = 0;
      int limite = ficha.getPosicion() + movimientos;
      for (int i = ficha.getPosicion(); i < limite; i++) {
        if (tablero.tablero[i].ocupada == true) {
          if (tablero.tablero[i].ficha.getJugadorID() != ficha.getJugadorID()) {
            barrera++;
          } else {
            barrera = 0;
          }
          if (barrera == 3) {
            cout << "Existe una barrea!\n";
            return true;
          }
        }
      }
    }
    return false;
}


