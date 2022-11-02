// vector de structs (un struc de casilla)
#include <vector>
#include <iostream>

#include "Ficha.h"
#include "Dado.h"
using namespace std;
class Tablero{
    public:
        Ficha f;
        Dado d;
        struct casilla{
            bool ocupada = 0;
            // 0 no y 1 sí
            int bloqueada = 0;
            Ficha::ficha* mificha;

        };
        vector<casilla> tablero;
        void inicializarTablero();
        bool verificarBarreras(Ficha::ficha *ficha, int movimientos);
        bool verificarProteccion(int posicion, int tipo);
        bool identFichaMovible(Ficha::ficha *ficha, int movimientos);
        int verificarCaida();
        void moverFicha(Ficha::ficha *ficha, int nuevaP);
        void intercambiar(Ficha::ficha *ficha, int nuevaP);

};

void Tablero::inicializarTablero(){
    for(int i = 0; i< 30; i++){
        casilla *cas = new casilla;
        if(i < 10){
            cas->ocupada = 1;
            cas->mificha = f.crearFicha(i);
        } else{
            cas->ocupada = 0;
            cas->mificha = nullptr;
        }
        cas->bloqueada = 0;
        this->tablero.push_back(*cas);
    }
}
bool Tablero::verificarBarreras(Ficha::ficha *ficha, int movimientos) {
  cout << "Barrera: \n";
  cout<< "Posicion de ficha actual "<<ficha->posicion<<endl;
  cout<< "Movimienots de ficha actual "<<movimientos<<endl;

  int barrera = 0;
  int limite = ficha->posicion + movimientos;
  for (int i = ficha->posicion; i < limite; i++) {
    if (this->tablero[i].ocupada == 1) {
      if (this->tablero[i].mificha->jugador != ficha->jugador) {
        barrera++;
      } else {
        barrera = 0;
      }
      if (barrera == 3) {
        return true;
      }
    }
  }


  return false;
}

bool Tablero::verificarProteccion(int posicion, int tipo) {
  //bool mover = false;
  
  //int proteccion = 0;
  if(this->tablero[posicion - 1].ocupada == 1 && this->tablero[posicion - 2].ocupada == 1){
      if(this->tablero[posicion - 1].mificha->jugador != tipo &&
        this->tablero[posicion - 2].mificha->jugador != tipo){
            return true;
      } 
  }

  if(this->tablero[posicion + 1].ocupada == 1 && this->tablero[posicion + 2].ocupada == 1){
    if(this->tablero[posicion + 1].mificha->jugador != tipo &&
        this->tablero[posicion + 2].mificha->jugador != tipo){
        return true;
    } 
  }
  return false;
}

bool Tablero::identFichaMovible(Ficha::ficha *ficha, int movimientos) {
  int verificar = -5;
  if(this->tablero[ficha->posicion+movimientos].ocupada == 1){
    verificar = this->tablero[ficha->posicion+movimientos].mificha->jugador;
    cout<<"A"<<endl;
  }
  if (this->tablero[ficha->posicion].mificha->jugador != verificar) {
    cout<<"B"<<endl;
    // Si la ficha que va a mover se haya en las casillas especiales.
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

    // Si cae en la casilla NILO
    if ((ficha->posicion + movimientos) == 27) {
        int nuevaP = verificarCaida();
        moverFicha(ficha, nuevaP);
        return true;
    }
    // Tiros normales.
    bool puede;
    // Verificar si existe alguna barrera.
    if (this->verificarBarreras(ficha, movimientos) == true) {
        cout<<"C"<<endl;
        return false;
    } else {
        // Si no existe una barrera; y la casilla está ocupada.
        if (this->tablero[ficha->posicion + movimientos].ocupada == 1) {
            // Si la ficha dentro de la casilla tiene no tiene protección.
            if (this->verificarProteccion(ficha->posicion + movimientos,
                                            ficha->jugador) == false) {
                cout<<"D"<<endl;
                this->intercambiar(ficha, ficha->posicion + movimientos);
                return true;
            } else {
                cout<<"E"<<endl;
                return false;
            }
        } else {
            cout<<"F"<<endl;
            this->moverFicha(ficha, ficha->posicion + movimientos);
        return true;
        }
    }
  } else {
      return false;
  }
}
void Tablero::moverFicha(Ficha::ficha *ficha, int nuevaP) {
  // Guardar la posicion de la ficha a mover.
  int posicionActual = ficha->posicion;
  // Eliminar el rastro de la ficha en la casilla vieja.
  this->tablero[posicionActual].mificha = NULL;
  this->tablero[posicionActual].ocupada = 0;
  // Colocar la ficha dentro de la casilla.
  ficha->posicion = nuevaP;
  this->tablero[nuevaP].mificha = ficha;
  this->tablero[nuevaP].ocupada = 1;
}

void Tablero::intercambiar(Ficha::ficha *ficha, int nuevaP) {
  // Almacenar la que se intercambia
  Ficha::ficha *aux = this->tablero[ficha->posicion].mificha;

  // Hacer el switch
  this->tablero[ficha->posicion].mificha = tablero[nuevaP].mificha;
  tablero[nuevaP].mificha->posicion = ficha->posicion;
  aux->posicion = nuevaP;
  this->tablero[nuevaP].mificha = aux;
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