#include "Arbitro.h"

Arbitro::Arbitro()
{  
}

bool Arbitro::verificarSalidaTablero(Ficha &ficha, int movimientos, Tablero &tablero) {
  if (tablero.tablero[ficha.getPosicion()].ocupada == true
  && ficha.getPosicion()  + movimientos > 29) {
    return true;
 }
 return false;
}

int Arbitro::checkWin() {
  if (fichasLeftPlayer1 == 0 || fichasLeftPlayer2 == 0) {
    return true;
  }
  return false;
}

bool Arbitro::sigoJugando(int num_dado) {
  if ((num_dado == 2) || (num_dado == 3)) {
    return false;
  } else {
    return true;
  }
}
