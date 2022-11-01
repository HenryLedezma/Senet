class Ficha {
public:
  struct ficha {
    // 1 jugador 1 y 2 jugador 2.
    int jugador;
    // posion del tablero donde esta
    int posicion;
    // 0 desprotegido y 1 protegido.
    int protegido;
  };
  ficha *crearFicha(int posicion);
};

Ficha::ficha *Ficha::crearFicha(int posicion) {
  ficha *fic;
  if (posicion % 2 == 0) {
    fic->jugador = 1;
  } else {
    fic->jugador = 2;
  }
  fic->posicion = posicion;
  fic->protegido = 0;
  return fic;
}
