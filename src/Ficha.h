/*
*   Clase que simula ser una ficha del tablero
*/

#ifndef FICHA_H
#define FICHA_H

/**
 @brief Simula ser un ficha de algun jugador
*/
class Ficha {
public:
  /**
    @brief Constructor de ficha
    @param player Identificador del jugador: jug.1 = 1,jug.2 = 2
    @param pos Identifica la posción donde estará la ficha
  */
  Ficha(int player, int pos);

  /**
    @brief Default constructor
  */
  Ficha();


  /**
    @return La posición de la ficha
  */
  int getPosicion();

  /**
    @return Dueño de la ficha, 1 o 2
  */
  int getJugadorID();
  
  /**
    @return Si una ficha está protegida, 0
    0 Desprotegido
    1 Protegido
  */
  int isProtected();
  
// Commented for testing private:
  /**
   ID del jugador dueño de la ficha
  */
  int jugador;
  /**
   *Posición actual de la ficha
  */
  int posc;
  /**
   Indica si la ficha está protegida
  */
  int protegido;
};

#endif // FICHA_H