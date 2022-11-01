https://us05web.zoom.us/j/84003631887?pwd=TTZEbVlFcS9yc3pEZHVtSWt4RWI4dz09// vector de structs (un struc de casilla)
#include <iostream>
#include <vector>

#include "Ficha.h"
using namespace std;
class Tablero {
public:
  struct casilla {
    bool ocupada = 0;
    // 0 no y 1 sí
    int bloqueada = 0;
    Ficha::ficha *mificha;
  };
  vector<casilla> tablero;
  Ficha c;
  void inicializarTablero();
  bool verificarBarreras(Ficha::ficha *ficha, int movimientos);
  bool verificarProteccion(int posicion, int tipo);
  bool identFichaMovible(Ficha::ficha *ficha, int movimientos);
  int verificarCaida();
  void moverFicha(Ficha::ficha *ficha, int nuevaP);
};

void Tablero::inicializarTablero() {
  for (int i = 0; i < 30; i++) {
    std::cout << "hola \n";
    casilla cas;
    if (i < 10) {
      cas.ocupada = 1;
      cas.mificha = c.crearFicha(i);
    } else {
      cas.ocupada = 0;
      cas.mificha = nullptr;
    }
    cas.bloqueada = 0;
    this->tablero.push_back(cas);
  }
  std::cout << this->tablero[0].ocupada << "adios \n";
}

bool Tablero::verificarBarreras(Ficha::ficha *ficha, int movimientos) {
  int barrera = 0;
  int limite = ficha->posicion + movimientos;
  for (int i = ficha->posicion; i < limite; i++) {
    if (this->tablero[i].ocupada == 1) {
      if (this->tablero[i].mificha->jugador != ficha->jugador) {
        barrera++;
      } else {
        barrera = 0;
      }
    } else {
      barrera = 0;
    }
  }s
  if (barrera == 3) {
    return true;
  }
  return false;
}

bool Tablero::verificarProteccion(int posicion, int tipo) {
  bool mover = true;
  if ((this->tablero[posicion - 1].ocupada == 1 &&
       this->tablero[posicion - 1].mificha->jugador != tipo) ||
      (this->tablero[posicion + 1].ocupada == 1 &&
       this->tablero[posicion + 1].mificha->jugador != tipo)) {
    mover = false;
  }
  return mover;
}

bool Tablero::identFichaMovible(Ficha::ficha *ficha, int movimientos) {
  if (ficha->posicion == 26 || 28 || 29) {
    if (ficha->posicion == 26 && movimientos == 3) {
      this->tablero[26].ocupada = 0;
      this->tablero[26].mificha = NULL;
      return true;
    }
    if (ficha->posicion == 28 && movimientos == 2) {
      this->tablero[28].ocupada = 0;
      this->tablero[28].mificha = NULL;
      return true;
    }
    if (ficha->posicion == 29 && movimientos == 1) {
      this->tablero[29].ocupada = 0;
      this->tablero[29].mificha = NULL;
      return true;
    }
  }
  if ((ficha->posicion + movimientos) == 27) {
    int nuevaP = verificarCaida();
    moverFicha(ficha, nuevaP);
    return true;
  }
  bool puede;
  if (this->verificarBarreras(ficha, movimientos) == true) {
    return false;
  } else {
    if (this->tablero[ficha->posicion + movimientos].ocupada == 1) {
      if (this->verificarProteccion(ficha->posicion + movimientos,
                                    ficha->jugador)) {
        this->moverFicha(ficha, ficha->posicion + movimientos);
        return true;
      } else {
        return false;
      }
    } else {
      this->moverFicha(ficha, ficha->posicion + movimientos);
      return true;
    }
  }
}
void Tablero::moverFicha(Ficha::ficha *ficha, int nuevaP) {
  this->tablero[ficha->posicion].ocupada = 0;
  ficha->posicion = nuevaP;
  this->tablero[ficha->posicion].ocupada = 1;
}

int Tablero::verificarCaida() {
  int nuevaP = 0;
  if (this->tablero[14].ocupada == 0) {
    nuevaP = 14;
  } else {
    for (int i = 13; i > 0; i--) {
      if (this->tablero[i].ocupada == 0) {
        nuevaP = i;
        break;
      }
    }
    return nuevaP;
  }
}