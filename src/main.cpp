#include <iostream>

#include "Dado.h"
#include "Ficha.h"
#include "Tablero.h"
#include "Mediador.h"

/*Definicón Códigos*/
// Flag: En caso de el turno sea del jugador 1
#define TURN_PLAYER1 99
// Flag: En caso de el turno sea del jugador 2
#define TURN_PLAYER2 100


using namespace std;

// Para testing, print del estado del juego en consola
void printGame(Tablero tablero);

// Selecciona ficha a mover
int selectFicha();

int main() {
  // Se crea y setea el tablero
  Tablero tablero = Tablero();
  Mediador mediador;
  mediador.setupTablero(tablero);
  bool winDetected = false;         // Bool si alguien ha ganado
  int dado_result = 0;              // Resultado del dado
  int current_turn = TURN_PLAYER1;  // Turno actual, default player 1
  int who_won = 0;                  // Quién ganó la partida
  bool continue_turn = true;        // Indica si el jugador debe seguir jugando

  while (!winDetected) {
    // Revisa si alguien ha ganado
    if (mediador.checkWin() == PLAYER1_WINS) {
      winDetected = true;
      who_won = PLAYER1_WINS;
      break;
    }
    if (mediador.checkWin() == PLAYER2_WINS) {
      winDetected = true;
      who_won = PLAYER2_WINS;
      break;
    }
    // Turno como tal del jugador
    do {
      dado_result = rollDice();
      int poscCasilla = selectFicha();
      mediador.realizarMovimiento(tablero.tablero[poscCasilla - 1].ficha, dado_result, tablero);
      printGame(tablero); // borrar, testing en consola
      continue_turn = mediador.sigoJugando(dado_result);
    } while (continue_turn);
    // Intercambio de turnos
    (current_turn == TURN_PLAYER1) ? current_turn = TURN_PLAYER2 :  current_turn = TURN_PLAYER1;
  }
}

void printGame(Tablero tablero) {
  printf("-------------------TABLERO-------------------\n");
  for (int i = 0; i < tablero.tablero.size(); i++) {
    if (tablero.tablero[i].ocupada == 1) {
      cout << tablero.tablero[i].ficha.getJugadorID() << " "; 
    } else {
      printf("X ");
    }
    
    if (i == 9) {printf("\n");}
    if (i == 19) {printf("\n");}
    if (i == 29) {printf("\n");}
  }
  printf("--------------------------------------\n");
}

int selectFicha() {
  int poscCasilla = 0;
  cout << "Type num. casilla donde esta la ficha a mover: "; // Type a number and press enter
  cin >> poscCasilla; // Get user input from the keyboard
}