/*
*   Clase mediadora del juego,
*   Ejecuta movimientos y verifica el estado del juego
*/

#ifndef MEDIADOR_H
#define MEDIADOR_H

#include "Tablero.h"
#include "Ficha.h"
#include "ConstructorAbstractaReglas.h"
#include "ReglaBarrera.h"
#include "ReglaCasillaEspecial.h"
#include "ReglaProteccion.h"

/*Definicón Códigos*/
// Flag: En caso de que jugador 1 gane
#define PLAYER1_WINS 1
// Flag: En caso de que jugador 2 gane
#define PLAYER2_WINS 2
// Flag: En caso de que aún nadie gane
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
   @brief Verifica si una ficha saldría del tablero al realizar el mov.
   @param ficha ficha a mover
   @param movientos Cantidad de casillas a mover
   @param tablero tablero del juego
  */
  bool verificarSalidaTablero(Ficha &ficha, int movimientos, Tablero &tablero);

  /**
   @brief Busca todas las validaciones necesarias para realizar un movimiento
   @param ficha ficha a mover
   @param movientos Cantidad de casillas a mover
   @param tablero tablero del juego
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
   @brief Revisa si algún jugador ganó la partida
   @return Alguna de las 3 flags definidas
  */
  bool sigoJugando(int num_dado);

//private:
  /**
   @brief Cuando se cae en el Río Nilo, casilla 15
   @param tablero tablero del juego
   @return La posc. que tendría la ficha después de la caída
  */
  int calcularCaidaNilo(Tablero &tablero);

  /**
   @brief Cuando no se puede avanzar, se retrocede. Calcula nueva posc.
   @param ficha ficha a mover
   @param movientos Cantidad de casillas a mover
   @param tablero tablero del juego
   @return La posc. que la ficha tendría después de retroceder
  */
  int calcularRetroceso(Ficha &ficha, int movimientos, Tablero &tablero);

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

  /**
   * Declarar reglas
  */
  ConstructorAbstractaReglas* reglaproteccion = new ReglaProteccion();
  ConstructorAbstractaReglas* reglacasillaespecial = new ReglaCasillaEspecial();
  ConstructorAbstractaReglas* reglabarrera = new ReglaBarrera();
};

#endif // MEDIADOR_H
