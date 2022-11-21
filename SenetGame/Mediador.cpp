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

bool Mediador::verificarBarreras(Ficha &ficha, int movimientos, Tablero &tablero) {
  // Verifica que las casilla a verificar sí se encuentre ocupada
  if (tablero.tablero[ficha.getPosicion()].ocupada == true) {
    int barrera = 0;
    int limite = ficha.getPosicion() + movimientos;
    for (int i = ficha.getPosicion(); i < limite; i++) {
      if (tablero.tablero[i].ocupada == true) {
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
  }
  return false;
}

bool Mediador::verificarProteccion(Ficha &ficha, int movimientos, Tablero &tablero) {
  int futura_posc = ficha.getPosicion() + movimientos;
  int adversario = 0;
  (ficha.getJugadorID() == 1) ? adversario = 2 :  adversario = 1;
  bool existeProteccion = false;

  /* Caso ficha adelante */
  // Revisa que la casilla y las adyacentes estén ocupadas
  if (tablero.tablero[futura_posc].ocupada == true
  && tablero.tablero[futura_posc + 1].ocupada == true) {
    // Revisa que la casilla actual y adyacente pertenezca al adversario
    if (tablero.tablero[futura_posc].ficha.getJugadorID() == adversario
    && tablero.tablero[futura_posc + 1].ficha.getJugadorID() == adversario) {
      existeProteccion = true;
      cout << "Existe una barrea!\n";
      return existeProteccion;
    }
  }
  /* Caso ficha detrás */
  // Revisa que la casilla y las adyacentes estén ocupadas
  if (tablero.tablero[futura_posc].ocupada == true
  && tablero.tablero[futura_posc - 1].ocupada == true) {
    // Revisa que la casilla actual y adyacente pertenezca al adversario
    if (tablero.tablero[futura_posc].ficha.getJugadorID() == adversario
    && tablero.tablero[futura_posc - 1].ficha.getJugadorID() == adversario) {
      existeProteccion = true;
      cout << "Existe una barrea!\n";
      return existeProteccion;
    }
  }
  return existeProteccion;
}

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

bool Mediador::verificarCasillaEspecial(Ficha &ficha, int movimientos, Tablero &tablero) {
  int futura_posc = ficha.getPosicion() + movimientos;
  bool casilla_especial = false;
  if (futura_posc == 25
  || futura_posc == 27
  || futura_posc == 28) {
    casilla_especial = true;
  }
  return casilla_especial;
}

bool Mediador::verificarSalidaTablero(Ficha &ficha, int movimientos, Tablero &tablero) {
  if (tablero.tablero[ficha.getPosicion()].ocupada == true
  && ficha.getPosicion()  + movimientos > 29) {
    return true;
 }
 return false;
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
  bool caeCasillaEspecial = verificarCasillaEspecial(ficha, movimientos, tablero);

  /* Caso: existe una barrera -> retrocede hasta que encuentre posc libre, desde donde está la ficha a mover */
  existeBarrera = verificarBarreras(ficha, movimientos, tablero);
  if (existeBarrera) {
    nuevaPosc = calcularRetroceso(ficha, movimientos, tablero);
    moverFicha(ficha, nuevaPosc, tablero);
    realizoMovimiento = true;
    return realizoMovimiento;
  }

  /* Caso: existe una proteccion -> retrocede hasta que encuentre posc libre, desde donde está la ficha a mover */
  existeProteccion = verificarProteccion(ficha, movimientos, tablero);
  if (existeProteccion) {
    nuevaPosc = calcularRetroceso(ficha, movimientos, tablero);
    moverFicha(ficha, nuevaPosc, tablero);
    realizoMovimiento = true;
    return realizoMovimiento;
  }

  /* Caso: no existe ningúna barrera y la ficha se saldría del tablero -> se mueve con normalidad */
  saleTablero = verificarSalidaTablero(ficha, movimientos, tablero);
  if (saleTablero == true && existeBarrera == false) {
    tablero.tablero[ficha.getPosicion()].ocupada = 0;
    (ficha.getJugadorID() == 1) ? fichasLeftPlayer1-- :  fichasLeftPlayer2--;
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



void Mediador::guardar(Tablero &tablero) {
  ofstream guardar;
  guardar.open("/Users/henry/Documents/dev/Diseno/SenetGame/Partida.csv", ios::out);
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
  ifstream archivo("/Users/henry/Documents/dev/Diseno/SenetGame/Partida.csv");
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
      fichasLeftPlayer1 = cantidadF;
      jugador = 2;
      cantidadF = 0;
    }
    if(linea != "30"){
      posicion = stoi(linea);
      tablero.tablero[posicion].ficha.jugador = jugador;
      tablero.tablero[posicion].ocupada = 1;
      tablero.tablero[posicion].ficha.posc = posicion;
      cantidadF += 1;
      fichasLeftPlayer2 = cantidadF;
    }
  }
  archivo.close();
}
