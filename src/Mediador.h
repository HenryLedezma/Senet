/*
*   Clase mediadora del juego, 
*   Ejecuta movimientos y verifica el estado del juego
*/

#ifndef MEDIADOR_H
#define MEDIADOR_H

#include "Tablero.h"
#include "Ficha.h"

/*Definicón Códigos*/
// Flag: En caso de que jugador 1 gane
#define PLAYER1_WINS 1
// Flag: En caso de que jugador 2 gane
#define PLAYER2_WINS 2
// Flag: En caso de que jugador aún nadie gane
#define NO_WIN 0

/**
 @brief Mediador del juego
*/
class Mediador {
public:
  /**
   @brief Construc. del mediador
   @param tablero tablero del juego
  */
  Mediador();

  /**
   @brief Verifica si tres fichas del tipo contrario generan un barrera 
   @param tablero tablero del juego
  */
  bool verificarBarreras(Ficha &ficha, int movimientos, Tablero &tablero);

  /**
   @brief Verifica si dos fichas del tipo contrario generan una protección
   @param tablero tablero del juego
  */
  bool verificarProteccion(int posicion, int tipo, Tablero &tablero);

  /** 
   @brief Realiza todas las verificaciones y mueve la ficha según el caso
   @param ficha ficha a mover
   @param movientos Cantidad de casillas a mover
  */
  bool realizarMovimiento(Ficha &ficha, int movimientos, Tablero &tablero);

  /** 
   @brief Intercambia dos fichas
   @param ficha ficha a mover
   @param movientos Nueva posc
  */
  void intercambiar(Ficha &ficha, int nuevaP, Tablero &tablero);

  /** 
   @brief Revisa si algún jugador ganó la partida
   @return Alguna de las 3 flags definidas
  */
  int checkWin();

  /** 
   @brief Settea el tablero con sus posc. iniciales
   @param tablero tablero del juego
  */
  void setupTablero(Tablero &tablero);

  /** 
   @brief Revisa si algún jugador ganó la partida
   @return Alguna de las 3 flags definidas
  */
  bool sigoJugando(int num_dado);

//private:
  /**
   @brief Cuando se cae en el Río Nilo
  */
  int verificarCaida(Tablero &tablero);

  /**
   @brief Realiza la acción de mover una ficha
   @param ficha ficha a mover
   @param nuevaP Nueva posición de la ficha
  */
  void moverFicha(Ficha &ficha, int nuevaP, Tablero &tablero);

  /**
   @brief Se encarga de guardar la partida actual
   @param tablero tablero del juego
  */
  void guardar(Tablero &tablero);

  /**
   @brief Se encargar de cargar la ultima partida
   @param tablero tablero del juego
  */
  void cargar(Tablero &tablero);

  /**
   Cuántas fichas restantes tiene cada jugador
  */
  int fichasLeftPlayer1 = 5;
  int fichasLeftPlayer2 = 5;
};





#endif // MEDIADOR_H