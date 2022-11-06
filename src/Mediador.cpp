/*
*   Implementación de clase, 
*   Ejecuta movimientos y verifica el estado del juego
*/

#include <iostream>
#include "Mediador.h"

using namespace std;

Mediador::Mediador() {}

bool Mediador::verificarBarreras(Ficha &ficha, int movimientos, Tablero &tablero) {
  int barrera = 0;
  int limite = ficha.getPosicion() + movimientos;
  for (int i = ficha.getPosicion(); i < limite; i++) {
    if (tablero.tablero[i].ocupada == 1) {
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
  return false;
}

bool Mediador::verificarProteccion(int posicion, int tipo, Tablero &tablero) {
  if(tablero.tablero[posicion - 1].ocupada == 1 && 
  tablero.tablero[posicion - 2].ocupada == 1) {
    if(tablero.tablero[posicion - 1].ficha.getJugadorID() != tipo 
    && tablero.tablero[posicion - 2].ficha.getJugadorID() != tipo){
      cout << "Existe una protección!\n";
      return true;
    } 
  }

  if(tablero.tablero[posicion + 1].ocupada == 1 
  && tablero.tablero[posicion + 2].ocupada == 1){
    if(tablero.tablero[posicion + 1].ficha.getJugadorID() != tipo 
    && tablero.tablero[posicion + 2].ficha.getJugadorID() != tipo){
      cout << "Existe una protección!\n";
      return true;
    }
  }
  return false;
}

int Mediador::verificarCaida(Tablero &tablero) {
  int nuevaP = 0;
  if (tablero.tablero[14].ocupada == 0) {
    nuevaP = 14;
  } else {
    for (int i = 13; i > 0; i--) {
      if (tablero.tablero[i].ocupada == 0) {
        nuevaP = i;
        break;
      }
    }
    return nuevaP;
  }
  return nuevaP;
}

void Mediador::moverFicha(Ficha &ficha, int nuevaP, Tablero &tablero) {
  // Guardar la posicion de la ficha a mover.
  int posicionActual = ficha.getPosicion();
  // Eliminar el rastro de la ficha en la casilla vieja.
  tablero.tablero[posicionActual].ocupada = 0;
  // Colocar la ficha dentro de la casilla.
  ficha.posc = nuevaP;
  tablero.tablero[nuevaP].ficha = ficha;
  tablero.tablero[nuevaP].ocupada = 1;
}

void Mediador::intercambiar(Ficha &ficha, int nuevaP, Tablero &tablero) {
  // almena ficha en posc a intercambiar
  Ficha aux_original = tablero.tablero[ficha.getPosicion()].ficha;
  int posc_original = ficha.getPosicion();

  // hace intercambio
  tablero.tablero[posc_original].ficha = tablero.tablero[nuevaP].ficha;
  tablero.tablero[nuevaP].ficha = aux_original;

  cout << "Hubo un intercambio!\n";
}

bool Mediador::realizarMovimiento(Ficha &ficha, int movimientos, Tablero &tablero) {
  // En caso de que la ficha salga del tablero
  if (ficha.getPosicion() + movimientos > 29) {
    tablero.tablero[ficha.getPosicion()].ocupada = 0;
    (ficha.getJugadorID() == 1) ? fichasLeftPlayer1-- :  fichasLeftPlayer2--;
    return true;
  }

  int verificar = -5;
  if (tablero.tablero[ficha.getPosicion() + movimientos].ocupada == 1) {
    verificar = tablero.tablero[ficha.getPosicion() + movimientos].ficha.getJugadorID();
  }

  if (tablero.tablero[ficha.getPosicion()].ficha.getJugadorID() != verificar) {
    /* TIROS ESPECIALES */
    // Si la ficha que va a mover se haya en las casillas especiales.
    if (ficha.getPosicion() == 25 || 27 || 28)
    {
      if (ficha.getPosicion() == 25 && movimientos == 3)
      {
        tablero.tablero[25].ocupada = 0;
        return true;
      }
      if (ficha.getPosicion() == 27 && movimientos == 2)
      {
        tablero.tablero[27].ocupada = 0;
        return true;
      }
      if (ficha.getPosicion() == 28 && movimientos == 1)
      {
        tablero.tablero[28].ocupada = 0;
        return true;
      }
    }

    // Si cae en la casilla NILO
    if ((ficha.getPosicion() + movimientos) == 26) {
      int nuevaP = verificarCaida(tablero);
      moverFicha(ficha, nuevaP, tablero);
      return true;
    }
    /* TIROS NORMALES */
    bool puede;
    // Verificar si existe alguna barrera.
    if (verificarBarreras(ficha, movimientos, tablero) == true) {
      return false;
    }
    else {
      // Si no existe una barrera; y la casilla está ocupada.
      if (tablero.tablero[ficha.getPosicion() + movimientos].ocupada == 1) {
        // Si la ficha dentro de la casilla tiene no tiene protección.
        if (verificarProteccion(ficha.getPosicion() + movimientos,ficha.getJugadorID(), tablero) == false) {
          intercambiar(ficha, ficha.getPosicion() + movimientos, tablero);
          return true;
        }
        else {
          return false;
        }
      }
      else {
        cout << "La ficha se mueve con normalidad!\n";
        moverFicha(ficha, ficha.getPosicion() + movimientos, tablero);
        return true;
      }
    }
  }
  else {
    return false;
  }
}

int Mediador::checkWin() {
  if (fichasLeftPlayer1 == 0) {
    return PLAYER1_WINS;
  }
  if (fichasLeftPlayer2 == 0) {
    return PLAYER2_WINS;
  }
  return NO_WIN;
}

void Mediador::setupTablero(Tablero &tablero) {
  int initial_casillas = 10;
  int jugadorID = 0;
  for (int i = 0; i < initial_casillas; i++) {
    (i % 2 == 0) ? jugadorID = 1 :  jugadorID = 2;
    Ficha ficha = Ficha(jugadorID, i);
    tablero.tablero[i].ocupada = 1;
    tablero.tablero[i].ficha = ficha;
  }
}

bool Mediador::sigoJugando(int num_dado) {
  if ((num_dado == 2) || (num_dado == 3)) {
    return false;
  } else {
    return true;
  }
}
