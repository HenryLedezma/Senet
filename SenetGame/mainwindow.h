#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>

#include "Mediador.h"
#include "Tablero.h"
#include "Dado.h"
#include "Arbitro.h"
#include "ConstructorSerializadorCSV.h"
#include "QtWidgets/qlabel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/*Definicón Códigos*/
// Flag: En caso de el turno sea del jugador 1
#define TURN_PLAYER1 99
// Flag: En caso de el turno sea del jugador 2
#define TURN_PLAYER2 100


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_reglasButton_clicked();

    void on_sigTurno_clicked();

    void on_tirarDado_clicked();

    void on_inputMove_returnPressed();

    void showEndLabel();

    void showTablero(Tablero tablero);

    void endGame();

    void on_guardarButton_clicked();

    void on_cargarButton_clicked();

private:
    Ui::MainWindow *ui;
    bool turno = false;

    Arbitro arbitro;
    Tablero tablero = Tablero();
    Mediador mediador;
    ConstructorSerializadorAbstracto* serializador = new ConstructorSerializadorCSV(); // se crea el serializador
    //QVector<QLabel*> casillas;
    //bool winDetected = false;         // Bool si alguien ha ganado
    int dado_result = 0;              // Resultado del dado
    //int current_turn = TURN_PLAYER1;  // Turno actual, default player 1
    //int who_won = 0;                  // Quién ganó la partida
    //bool continue_turn = true;        // Indica si el jugador debe seguir jugando
    int inputMove = 0;

};
#endif // MAINWINDOW_H
