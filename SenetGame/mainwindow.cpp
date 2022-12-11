#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mydialog.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<QLabel*> casillas(30);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->sigTurno->hide();
    if(!this->turno){
        ui->turnoJug->setText("Turno: J1\nFicha : X");
    } else{
        ui->turnoJug->setText("Turno: J2\nFicha : O");
    }
    ui->endLabel->hide();
    ui->textMove->hide();
    ui->inputMove->hide();

    casillas[0] = ui->casilla_1;
    casillas[1] = ui->casilla_2;
    casillas[2] = ui->casilla_3;
    casillas[3] = ui->casilla_4;
    casillas[4] = ui->casilla_5;
    casillas[5] = ui->casilla_6;
    casillas[6] = ui->casilla_7;
    casillas[7] = ui->casilla_8;
    casillas[8] = ui->casilla_9;
    casillas[9] = ui->casilla_10;
    casillas[10] = ui->casilla_11;
    casillas[11] = ui->casilla_12;
    casillas[12] = ui->casilla_13;
    casillas[13] = ui->casilla_14;
    casillas[14] = ui->casilla_15;
    casillas[15] = ui->casilla_16;
    casillas[16] = ui->casilla_17;
    casillas[17] = ui->casilla_18;
    casillas[18] = ui->casilla_19;
    casillas[19] = ui->casilla_20;
    casillas[20] = ui->casilla_21;
    casillas[21] = ui->casilla_22;
    casillas[22] = ui->casilla_23;
    casillas[23] = ui->casilla_24;
    casillas[24] = ui->casilla_25;
    casillas[25] = ui->casilla_26;
    casillas[26] = ui->casilla_27;
    casillas[27] = ui->casilla_28;
    casillas[28] = ui->casilla_29;
    casillas[29] = ui->casilla_30;

    showTablero(tablero);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_reglasButton_clicked()
{
    MyDialog reglas;
    reglas.setModal(true);
    reglas.exec();
}


void MainWindow::on_tirarDado_clicked() {
    /* Estructura del mecanismo de azar */
    vector < int > pesos = {1, 2, 3, 4, 6};
    int lados_count = pesos.size();
    Dado <int> tablillas(lados_count, pesos);

    // Tira dado
    this->dado_result = tablillas.rollDice();
    QString resultado = QString::number(dado_result);
    ui->resultDado->setText(resultado);

    //Esconde boton y enseña el otro
    ui->tirarDado->hide();
    ui->textMove->show();
    ui->inputMove->show();
}


void MainWindow::on_sigTurno_clicked()
{
    //Cambia el turno
    if(this->dado_result == 2 || this->dado_result == 3){
        this->turno = !this->turno;
    }
    //Imprime el turno del jugador actual
    if(!this->turno){
        ui->turnoJug->setText("Turno: J1\nFicha : X");
    } else{
        ui->turnoJug->setText("Turno: J2\nFicha : O");
    }

    int poscCasilla = this->inputMove;

    mediador.realizarMovimiento(tablero.tablero[poscCasilla - 1].ficha, this->dado_result, tablero);
    showTablero(tablero);

    ui->sigTurno->hide();
    ui->tirarDado->show();
    ui->resultDado->clear();
    endGame();
}


void MainWindow::showTablero(Tablero tablero)
{
    for (int  i= 0; i < 30; i++) {
        if(tablero.tablero[i].ocupada == 0){
            casillas[i]->setText("");
        } else {
            if(tablero.tablero[i].ficha.jugador == 1){
                casillas[i]->setText("X");
            } else {
                casillas[i]->setText("O");
            }
        }
    }

}

void MainWindow::on_inputMove_returnPressed()
{
    QString in = ui->inputMove->text();
    ui->inputMove->clear();
    inputMove = in.toInt();
    int poscCasilla = inputMove;
    if(arbitro.verificarTurno(tablero.tablero[poscCasilla - 1].ocupada, turno, tablero.tablero[poscCasilla - 1].ficha.jugador)){
        ui->textMove->hide();
        ui->inputMove->hide();
        ui->sigTurno->show();
        ui->textMove->setText("¿Qué ficha desea mover? Ingresar el número de casilla en que se encuentra esta:");
    } else{
        ui->textMove->setText("Esa ficha no le pertenece, por favor intentelo de nuevo");
    }

}

void MainWindow::showEndLabel(){
    ui->endLabel->show();
    ui->sigTurno->hide();
    ui->textMove->hide();
    ui->inputMove->hide();
    ui->tirarDado->hide();
    ui->resultText->hide();
    ui->resultDado->hide();
}

void MainWindow:: endGame(){
    int end = arbitro.checkWin();
    if(end != 0){
        showEndLabel();
    }
}

void MainWindow::on_guardarButton_clicked()
{
    serializador->guardar(tablero);
}


void MainWindow::on_cargarButton_clicked()

{
    std::string fichas = serializador->cargar(tablero);
    arbitro.fichasLeftPlayer1 = int(fichas[0]);
    arbitro.fichasLeftPlayer2 = int(fichas[1]);
    showTablero(tablero);
}

