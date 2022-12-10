#include <iostream>
#include <fstream>
#include <sstream>
#include "ConstructorSerializadorAbstracto.h"

/**
 @brief Serializador CVS
*/
class ConstructorSerializadorCSV : public ConstructorSerializadorAbstracto
{
public:
    /**
        @brief Default constructor
    */
    ConstructorSerializadorCSV();
    ~ConstructorSerializadorCSV();

    /* SERIALIZADORES */
    /**
     @brief Se encarga de guardar la partida actual
     @param tablero tablero del juego
    */

    virtual void guardar(const Tablero &tablero) override;
    /**
     @brief Se encarga de cargar la partida
     @param tablero tablero del juego
    */
    virtual string cargar(Tablero &tablero) override;
private:

};
