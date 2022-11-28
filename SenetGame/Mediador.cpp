/*
*   Implementación de clase,
*   Ejecuta movimientos y verifica el estado del juego
*/

#include <iostream>
#include <fstream>
#include<string>
#include "Mediador.h"
using namespace std;

Mediador::Mediador() {}

int Mediador::calcularCaidaNilo(Tablero &tablero) {
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
  }
  cout << "Hubo una caída, la nueva casilla es: " << nuevaP + 1 << "!\n";
  return nuevaP;
}

int Mediador::calcularRetroceso(Ficha &ficha, int movimientos, Tablero &tablero) {
  int nuevaP = -99;
  for (int i = ficha.getPosicion(); i > 0; i--) {
    if (tablero.tablero[i].ocupada == 0) {
      nuevaP = i;
      break;
    }
  }
  if (nuevaP == -99) {
    cout << "Hubo un retroceso, la casilla continua en la misma posc: " << nuevaP + 1<< "!\n";
    return nuevaP = ficha.getPosicion();
  }
  cout << "Hubo un retroceso, la nueva casilla es: " << nuevaP + 1<< "!\n";
  return nuevaP;
}

void Mediador::moverFicha(Ficha &ficha, int nuevaP, Tablero &tablero) {
  // Si la casilla a utilizar está ocupada retrocede hasta encontrar una libre
  while (tablero.tablero[nuevaP].ocupada == true) {
    nuevaP = nuevaP - 1;
    cout << "La casilla se encuentra ocupada! Retrocede uno...\n";
  }
  // Guardar la posicion de la ficha a mover.
  int posicionActual = ficha.getPosicion();
  // Eliminar el rastro de la ficha en la casilla vieja.
  tablero.tablero[posicionActual].ocupada = 0;
  // Colocar la ficha dentro de la casilla.
  ficha.posc = nuevaP;
  tablero.tablero[nuevaP].ficha = ficha;
  tablero.tablero[nuevaP].ficha.posc = nuevaP;
  tablero.tablero[nuevaP].ocupada = 1;
}

void Mediador::intercambiar(Ficha &ficha, int nuevaP, Tablero &tablero) {
  // Verifica que las casillas a intercambiar sí se encuentren ocupadas
  if (tablero.tablero[ficha.getPosicion()].ocupada == true
  && tablero.tablero[nuevaP].ocupada == true) {
    // almena ficha en posc a intercambiar
    Ficha aux_original = tablero.tablero[ficha.getPosicion()].ficha;
    int posc_original = ficha.getPosicion();
    // hace intercambio
    tablero.tablero[posc_original].ficha = tablero.tablero[nuevaP].ficha;
    tablero.tablero[posc_original].ficha.posc = posc_original;

    tablero.tablero[nuevaP].ficha = aux_original;
    tablero.tablero[nuevaP].ficha.posc = nuevaP;
    cout << "Hubo un intercambio! Casillas: " << posc_original + 1 << ", " << nuevaP + 1 <<  "\n";
  }
}

bool Mediador::realizarMovimiento(Ficha &ficha, int movimientos, Tablero &tablero) {
  bool realizoMovimiento = false;
  bool existeBarrera = false;
  bool existeProteccion = false;
  bool saleTablero = false;
  int nuevaPosc = ficha.getPosicion() + movimientos;
  cout << "La futura posc es: " << nuevaPosc + 1 << "\n";
  bool futuraCasillaOcupada = tablero.tablero[nuevaPosc].ocupada;
  cout << "La futura posc se encuentra ocupada: " << futuraCasillaOcupada << "\n";
  bool caeNilo = nuevaPosc == 26 ? caeNilo = true : caeNilo = false;
  bool caeCasillaEspecial = reglacasillaespecial->regla("", ficha, movimientos, tablero);

  /* Caso: existe una barrera -> retrocede hasta que encuentre posc libre, desde donde está la ficha a mover */
  existeBarrera = reglabarrera->regla("",ficha, movimientos, tablero);
  if (existeBarrera) {
    nuevaPosc = calcularRetroceso(ficha, movimientos, tablero);
    moverFicha(ficha, nuevaPosc, tablero);
    realizoMovimiento = true;
    return realizoMovimiento;
  }

  /* Caso: existe una proteccion -> retrocede hasta que encuentre posc libre, desde donde está la ficha a mover */
  existeProteccion = reglaproteccion->regla("",ficha, movimientos, tablero);
  if (existeProteccion) {
    nuevaPosc = calcularRetroceso(ficha, movimientos, tablero);
    moverFicha(ficha, nuevaPosc, tablero);
    realizoMovimiento = true;
    return realizoMovimiento;
  }

  /* Caso: no existe ningúna barrera y la ficha se saldría del tablero -> se mueve con normalidad */
  saleTablero = arbitro.verificarSalidaTablero(ficha, movimientos, tablero);
  if (saleTablero == true && existeBarrera == false) {
    tablero.tablero[ficha.getPosicion()].ocupada = 0;
    (ficha.getJugadorID() == 1) ? arbitro.fichasLeftPlayer1-- :  arbitro.fichasLeftPlayer2--;
    realizoMovimiento = true;
    return realizoMovimiento;
  }

  /* Caso: la casilla no está ocupada */
  if (!futuraCasillaOcupada) {
    /* Caso: cae en casilla especial Nilo -> Retrocede hasta encontrar una casilla desocupada */
    if (caeNilo) {
      nuevaPosc = calcularCaidaNilo(tablero);
      moverFicha(ficha, nuevaPosc, tablero);
      realizoMovimiento = true;
      return realizoMovimiento;
    }
    /* Caso: no está ocupada y no cae en casilla Nilo -> Mueve la ficha con normalidad */
    cout << "Caso: posc no ocupada, procede con normalidad!\n";
    moverFicha(ficha, nuevaPosc, tablero);
    realizoMovimiento = true;
    return realizoMovimiento;
  }

  /* Caso: la casilla está ocupada */
  if (futuraCasillaOcupada) {
    /* Caso: la casilla es una especial -> retrocede hasta que encuentre posc libre, desde ficha actual */
    if (caeCasillaEspecial) {
      nuevaPosc = calcularRetroceso(ficha, movimientos, tablero);
      moverFicha(ficha, nuevaPosc, tablero);
      realizoMovimiento = true;
      return realizoMovimiento;
    }
    /* Caso no es casilla especial, no barrera, no proteccion -> Intercambio de fichas */
    intercambiar(ficha, nuevaPosc, tablero);
    realizoMovimiento = true;
    return realizoMovimiento;
  }
  return realizoMovimiento;
}


void Mediador::guardar(Tablero &tablero) {
  ofstream guardar;
  guardar.open("../partida.csv", ios::out);
  string jugador1 = "";
  string jugador2 = "";

  for (int i = 0; i < 30; i++) {
    if (tablero.tablero[i].ocupada == 1){
      if(tablero.tablero[i].ficha.jugador == 1){
        jugador1+=to_string(tablero.tablero[i].ficha.posc);
        jugador1+=",";
      }
      if(tablero.tablero[i].ficha.jugador == 2){
        jugador2+=to_string(tablero.tablero[i].ficha.posc);
        jugador2+=",";
      }
    }
  }
  jugador1.pop_back();
  jugador2.pop_back();
  guardar<<jugador1<<'\n';
  guardar<<",30,"<<'\n';
  guardar<<jugador2<<'\n';
}

void Mediador::cargar(Tablero &tablero) {
  ifstream archivo("../partida.csv");
  string linea;
  char delimitador = ',';
  int jugador = 1;
  int posicion = 0;
  int cantidadF = 0;
  // Limpiar tablero primero
  for (int i = 0; i < 30; i++) {
    tablero.tablero[i].ocupada = 0;
  }
  // Leemos todas las líneas
  while (getline(archivo, linea, delimitador)){
    if(linea == "30"){
      arbitro.fichasLeftPlayer1 = cantidadF;
      jugador = 2;
      cantidadF = 0;
    }
    if(linea != "30"){
      posicion = stoi(linea);
      tablero.tablero[posicion].ficha.jugador = jugador;
      tablero.tablero[posicion].ocupada = 1;
      tablero.tablero[posicion].ficha.posc = posicion;
      cantidadF += 1;
      arbitro.fichasLeftPlayer2 = cantidadF;
    }
  }
  archivo.close();
}
