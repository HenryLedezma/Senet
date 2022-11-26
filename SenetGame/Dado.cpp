#pragma once
#include <cstdlib>
class Dado{
    public:
        int azar();
};

int Dado::azar(){
    int numero = 0;
    numero = 1 + rand() % (6-1);
    if (5 == numero){
        numero = 6;
    }
    return numero;
}
