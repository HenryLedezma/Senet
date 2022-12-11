#ifndef JUGADOR_H
#define JUGADOR_H


#include <iostream>
#include <string>

using namespace std;

class Jugador {
    private:
        int id;
        int score;
        bool turno;
        string name;

     public:
        /**
           * @brief Setear el nombre del jugador
           * @param name Nombre del jugador
           */
          virtual void setName(string name){};
          /**
           * @brief Setear el id del jugador
           * @param id id del jugador
           */
          virtual void setId(string id){};
          /**
           * @brief Setear puntuacion
           * @param pos Posicion del jugador
           */
          virtual void setScore(int score){};
          /**
           * @brief Setear el turno del jugador
           * @param puntuacion Puntuacion del jugador
           */
          virtual void setTurno(bool turno){};
          /**
           * @brief Get nombre del jugador
           * @return Se retorna el nombre del jugador
           */
          virtual string getName(){};
          /**
           * @brief Get del id del jugador
           * @return Retorna el id del jugador
           */
          virtual int getId(){};
          /**
           * @brief Get de la puntuacion
           * @return Retorna la puntuacion del jugador
           */
          virtual int getScore(){};
          /**
           * @brief Get del turno
           * @return Retorna si es el turno o no del jugador
           */
          virtual bool getTurno(){};
};

#endif // JUGADOR_H
