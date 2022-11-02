#include <iostream>
#include "Tablero.h"
#include <vector>

using namespace std;

int main() {
  cout << "Soy Senet!\n";
  Tablero tab;

  tab.inicializarTablero();
  cout << "Soy Senet!\n"<<tab.tablero[8].mificha->posicion;

  // Verificar que se creó bien el tablero INICIAL:
  for(int i = 0; i < 10 ; i++){
    cout<<"El jugador es el: "<<tab.tablero[i].mificha->jugador<<endl;;
  }

  // Verificar que se efectue bien un INTERCAMBIO de fichas.
  tab.identFichaMovible(tab.tablero[0].mificha, 1);
  cout<<"\n -------INTERCAMBIAR--------\n";

   // Verificar que se creó bien el tablero INICIAL:
  for(int i = 0; i < 10 ; i++){
    cout<<"El jugador es el: "<<tab.tablero[i].mificha->jugador<<endl;;
  }

  cout<< "\n--------------SIN CAMBIOS-----------\n";
  // Verificar que NO se efectue un cambio de fichas.
  tab.identFichaMovible(tab.tablero[0].mificha, 3);
  for(int i = 0; i < 10 ; i++){
    cout<<"El jugador es el: "<<tab.tablero[i].mificha->jugador<<endl;;
  }

  // Verificar moviminto normal, sin barrera o proteccion.
  tab.identFichaMovible(tab.tablero[9].mificha, 3);
  for(int i = 0; i < 30 ; i++){
    cout<< i <<" : "<<tab.tablero[i].ocupada<<endl;;
  }
  // Verificar Protección.
  tab.identFichaMovible(tab.tablero[0].mificha, 1);
  cout<<"El jugador en "<< 0 <<" es el: "<<tab.tablero[0].mificha->jugador<<endl;
  cout<<"El jugador en "<< 1 <<" es el: "<<tab.tablero[1].mificha->jugador<<endl;
  cout<<"El jugador en "<< 2 <<" es el: "<<tab.tablero[2].mificha->jugador<<endl;
  cout<<"El jugador en "<< 3 <<" es el: "<<tab.tablero[3].mificha->jugador<<endl;


  // Verificar barrera.
  cout<<"\n--------------------------\n";
  cout<<"VER: " << tab.tablero[1].mificha->posicion<<endl;
  tab.identFichaMovible(tab.tablero[1].mificha, 2);
  for(int i = 0; i < 10 ; i++){
    cout<<"El jugador es el: "<<tab.tablero[i].mificha->jugador<<endl;
  }

  tab.identFichaMovible(tab.tablero[0].mificha, 6);
  for(int i = 0; i < 10 ; i++){
    cout<<"El jugador es el: "<<tab.tablero[i].mificha->jugador<<endl;;
  }

}