#include "ConstructorSerializadorCSV.h"


ConstructorSerializadorCSV::ConstructorSerializadorCSV()
{
}

ConstructorSerializadorCSV::~ConstructorSerializadorCSV(){

}

void ConstructorSerializadorCSV::guardar(const Tablero &tablero)
{
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

string ConstructorSerializadorCSV::cargar(Tablero &tablero){
    string fichas1 = "";
    string fichas2 = "";
    string fichas = "";
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
        //fichasLeftPlayer1 = cantidadF;
        fichas1 = to_string(cantidadF);
        jugador = 2;
        cantidadF = 0;
      }
      if(linea != "30"){
        posicion = stoi(linea);
        tablero.tablero[posicion].ficha.jugador = jugador;
        tablero.tablero[posicion].ocupada = 1;
        tablero.tablero[posicion].ficha.posc = posicion;
        cantidadF += 1;
        //fichasLeftPlayer2 = cantidadF;
        fichas2 = to_string(cantidadF);
      }
    }
    fichas = fichas1 + fichas2;
    archivo.close();
    return fichas;
}
