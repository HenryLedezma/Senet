#include <cstdlib>
class Dado {
  int azar();
};

int Dado::azar() {
  int numero = 0;
  numero = rand() % 6;
  if (5 == numero) {
    numero = 6;
  }
  return numero;
}