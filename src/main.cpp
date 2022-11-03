#include <iostream>

#include "Dado.h"
#include "Ficha.h"
#include "Tablero.h"
#include "Mediador.h"

using namespace std;

// Para testing, print del estado del juego
void printGame(Tablero tablero);

int main() {
  // Se crea y setea el tablero
  Tablero tablero = Tablero();
  Mediador mediador;

  mediador.setupTablero(tablero);
  printGame(tablero);


  // Se prueba realizar un movimiento
  mediador.realizarMovimiento(tablero.tablero[9].ficha, 2, tablero);
  printGame(tablero);

  // Se prueba realizar un movimiento
  mediador.realizarMovimiento(tablero.tablero[11].ficha, 28, tablero);
  printGame(tablero);

  mediador.checkWin();

  /* TESTING asignacion de ficha a casillas */
  printf("--------------------------------------\n");
  for (int i = 0; i < tablero.tablero.size(); i++) {
    if (tablero.tablero[i].ocupada == 1) {
      cout << "Soy la casilla: " << i << " y tengo a la ficha en la posc ";
      cout << tablero.tablero[i].ficha.getPosicion() << " \n"; 
    }
  }
  
  
}

void printGame(Tablero tablero) {
  printf("-------------------TABLERO-------------------\n");
  for (int i = 0; i < tablero.tablero.size(); i++) {
    if (tablero.tablero[i].ocupada == 1) {
      cout << tablero.tablero[i].ficha.getJugadorID() << " "; 
    } else {
      printf("Vacio ");
    }
    
    if (i == 9) {printf("\n");}
    if (i == 19) {printf("\n");}
    if (i == 29) {printf("\n");}
  }
  printf("--------------------------------------\n");
}