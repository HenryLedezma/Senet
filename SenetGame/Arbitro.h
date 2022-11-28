#ifndef ARBITRO_H
#define ARBITRO_H
#include "Tablero.h"

class Arbitro
{
public:
    Arbitro();

    /**
     @brief Verifica si una ficha saldría del tablero al realizar el mov.
     @param ficha ficha a mover
     @param movientos Cantidad de casillas a mover
     @param tablero tablero del juego
    */
    bool verificarSalidaTablero(Ficha &ficha, int movimientos, Tablero &tablero);

    /**
     @brief Revisa si algún jugador ganó la partida
     @return Alguna de las 3 flags definidas
    */
    int checkWin();

    /**
     @brief Revisa si algún jugador ganó la partida
     @return Alguna de las 3 flags definidas
    */
    bool sigoJugando(int num_dado);

    /**
     @brief Verifica que la casilla pertenezca al jugador que va realizar el mov.
     @param ocupada (si esta ocupada o no)
     @param turno (si le toca al J1 o J2)
    */
    bool verificarTurno(bool ocupada, bool turno, int jugador);
//private:
    /**
       Cuántas fichas restantes tiene cada jugador
      */
      int fichasLeftPlayer1 = 5;
      int fichasLeftPlayer2 = 5;

};

#endif // ARBITRO_H
