#include <iostream>
#include <fstream>
#include <sstream>
#include "ConstructorSerializadorAbstracto.h"

class ConstructorSerializadorCSV : public ConstructorSerializadorAbstracto
{
public:
    ConstructorSerializadorCSV();
    ~ConstructorSerializadorCSV();

    /* SERIALIZADORES */
    /**
     @brief Se encarga de guardar la partida actual
     @param tablero tablero del juego
    */
    virtual void guardar(const Tablero &tablero) override;
    virtual string cargar(Tablero &tablero) override;
private:

};
