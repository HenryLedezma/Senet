#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mydialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sigTurno->hide();
    ui->turnoJug->setText("Turno: J1\nFicha : X");
    ui->endLabel->hide();
    ui->textMove->hide();
    ui->inputMove->hide();
    //Tablero
    mediador.setupTablero(tablero);

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


void MainWindow::on_tirarDado_clicked()
{
    //Dado
    int numero = 0;
    numero = 1 + arc4random() % (6-1);
    if (5 == numero){
        numero = 6;
    }
    this->dado_result = numero;
    QString resultado = QString::number(numero);
    ui->resultDado->setText(resultado);
    if(numero == 2 || numero == 3){
        this->turno = !this->turno;
    }
    //Esconde boton y enseña el otro
    ui->tirarDado->hide();
    ui->textMove->show();
    ui->inputMove->show();
}


void MainWindow::on_sigTurno_clicked()
{
    ui->tirarDado->show();
    ui->resultDado->clear();
    if(!this->turno){
        ui->turnoJug->setText("Turno: J1\nFicha : X");
    } else{
        ui->turnoJug->setText("Turno: J2\nFicha : O");
    }

    int poscCasilla = this->inputMove;
    mediador.realizarMovimiento(tablero.tablero[poscCasilla - 1].ficha, this->dado_result, tablero);
    showTablero(tablero);
    //continue_turn = mediador.sigoJugando(this->dado_result);

    //while (continue_turn);
    // Intercambio de turnos
    //(current_turn == TURN_PLAYER1) ? current_turn = TURN_PLAYER2 :  current_turn = TURN_PLAYER1;

    //Actualiza tablero del UI
    //showTablero(this->tablero);
    ui->sigTurno->hide();
    endGame();

}


void MainWindow::showTablero(Tablero tablero)
{
    //QString tipoFicha = "";
    //Casilla 1
    if(tablero.tablero[0].ocupada == 0){
        ui->casilla->setText("");
    } else {
        if(tablero.tablero[0].ficha.jugador == 1){
            ui->casilla->setText("X");
        } else {
            ui->casilla->setText("O");
        }
    }

    //Casilla 2
    if(tablero.tablero[1].ocupada == 0){
        ui->casilla_2->setText("");
    } else {
        if(tablero.tablero[1].ficha.jugador == 1){
            ui->casilla_2->setText("X");
        } else {
            ui->casilla_2->setText("O");
        }
    }

    //Casilla 3
    if(tablero.tablero[2].ocupada == 0){
        ui->casilla_3->setText("");
    } else {
        if(tablero.tablero[2].ficha.jugador == 1){
            ui->casilla_3->setText("X");
        } else {
            ui->casilla_3->setText("O");
        }
    }

    //Casilla 4
    if(tablero.tablero[3].ocupada == 0){
        ui->casilla_4->setText("");
    } else {
        if(tablero.tablero[3].ficha.jugador == 1){
            ui->casilla_4->setText("X");
        } else {
            ui->casilla_4->setText("O");
        }
    }

    //Casilla 5
    if(tablero.tablero[4].ocupada == 0){
        ui->casilla_5->setText("");
    } else {
        if(tablero.tablero[4].ficha.jugador == 1){
            ui->casilla_5->setText("X");
        } else {
            ui->casilla_5->setText("O");
        }
    }

    //Casilla 6
    if(tablero.tablero[5].ocupada == 0){
        ui->casilla_6->setText("");
    } else {
        if(tablero.tablero[5].ficha.jugador == 1){
            ui->casilla_6->setText("X");
        } else {
            ui->casilla_6->setText("O");
        }
    }

    //Casilla 7
    if(tablero.tablero[6].ocupada == 0){
        ui->casilla_7->setText("");
    } else {
        if(tablero.tablero[6].ficha.jugador == 1){
            ui->casilla_7->setText("X");
        } else {
            ui->casilla_7->setText("O");
        }
    }

    //Casilla 8
    if(tablero.tablero[7].ocupada == 0){
        ui->casilla_8->setText("");
    } else {
        if(tablero.tablero[7].ficha.jugador == 1){
            ui->casilla_8->setText("X");
        } else {
            ui->casilla_8->setText("O");
        }
    }

    //Casilla 9
    if(tablero.tablero[8].ocupada == 0){
        ui->casilla_9->setText("");
    } else {
        if(tablero.tablero[8].ficha.jugador == 1){
            ui->casilla_9->setText("X");
        } else {
            ui->casilla_9->setText("O");
        }
    }

    //Casilla 10
    if(tablero.tablero[9].ocupada == 0){
        ui->casilla_10->setText("");
    } else {
        if(tablero.tablero[9].ficha.jugador == 1){
            ui->casilla_10->setText("X");
        } else {
            ui->casilla_10->setText("O");
        }
    }

    //Casilla 11
    if(tablero.tablero[10].ocupada == 0){
        ui->casilla_11->setText("");
    } else {
        if(tablero.tablero[10].ficha.jugador == 1){
            ui->casilla_11->setText("X");
        } else {
            ui->casilla_11->setText("O");
        }
    }

    //Casilla 12
    if(tablero.tablero[11].ocupada == 0){
        ui->casilla_12->setText("");
    } else {
        if(tablero.tablero[11].ficha.jugador == 1){
            ui->casilla_12->setText("X");
        } else {
            ui->casilla_12->setText("O");
        }
    }

    //Casilla 13
    if(tablero.tablero[12].ocupada == 0){
        ui->casilla_13->setText("");
    } else {
        if(tablero.tablero[12].ficha.jugador == 1){
            ui->casilla_13->setText("X");
        } else {
            ui->casilla_13->setText("O");
        }
    }

    //Casilla 14
    if(tablero.tablero[13].ocupada == 0){
        ui->casilla_14->setText("");
    } else {
        if(tablero.tablero[13].ficha.jugador == 1){
            ui->casilla_14->setText("X");
        } else {
            ui->casilla_14->setText("O");
        }
    }

    //Casilla 15
    if(tablero.tablero[14].ocupada == 0){
        ui->casilla_15->setText("");
    } else {
        if(tablero.tablero[14].ficha.jugador == 1){
            ui->casilla_15->setText("X");
        } else {
            ui->casilla_15->setText("O");
        }
    }

    //Casilla 16
    if(tablero.tablero[15].ocupada == 0){
        ui->casilla_16->setText("");
    } else {
        if(tablero.tablero[15].ficha.jugador == 1){
            ui->casilla_16->setText("X");
        } else {
            ui->casilla_16->setText("O");
        }
    }

    //Casilla 17
    if(tablero.tablero[16].ocupada == 0){
        ui->casilla_17->setText("");
    } else {
        if(tablero.tablero[16].ficha.jugador == 1){
            ui->casilla_17->setText("X");
        } else {
            ui->casilla_17->setText("O");
        }
    }

    //Casilla 18
    if(tablero.tablero[17].ocupada == 0){
        ui->casilla_18->setText("");
    } else {
        if(tablero.tablero[17].ficha.jugador == 1){
            ui->casilla_18->setText("X");
        } else {
            ui->casilla_18->setText("O");
        }
    }

    //Casilla 19
    if(tablero.tablero[18].ocupada == 0){
        ui->casilla_19->setText("");
    } else {
        if(tablero.tablero[18].ficha.jugador == 1){
            ui->casilla_19->setText("X");
        } else {
            ui->casilla_19->setText("O");
        }
    }

    //Casilla 20
    if(tablero.tablero[19].ocupada == 0){
        ui->casilla_20->setText("");
    } else {
        if(tablero.tablero[19].ficha.jugador == 1){
            ui->casilla_20->setText("X");
        } else {
            ui->casilla_20->setText("O");
        }
    }

    //Casilla 21
    if(tablero.tablero[20].ocupada == 0){
        ui->casilla_21->setText("");
    } else {
        if(tablero.tablero[20].ficha.jugador == 1){
            ui->casilla_21->setText("X");
        } else {
            ui->casilla_21->setText("O");
        }
    }

    //Casilla 22
    if(tablero.tablero[21].ocupada == 0){
        ui->casilla_22->setText("");
    } else {
        if(tablero.tablero[21].ficha.jugador == 1){
            ui->casilla_22->setText("X");
        } else {
            ui->casilla_22->setText("O");
        }
    }

    //Casilla 23
    if(tablero.tablero[22].ocupada == 0){
        ui->casilla_23->setText("");
    } else {
        if(tablero.tablero[22].ficha.jugador == 1){
            ui->casilla_23->setText("X");
        } else {
            ui->casilla_23->setText("O");
        }
    }

    //Casilla 24
    if(tablero.tablero[23].ocupada == 0){
        ui->casilla_24->setText("");
    } else {
        if(tablero.tablero[23].ficha.jugador == 1){
            ui->casilla_24->setText("X");
        } else {
            ui->casilla_24->setText("O");
        }
    }

    //Casilla 25
    if(tablero.tablero[24].ocupada == 0){
        ui->casilla_25->setText("");
    } else {
        if(tablero.tablero[24].ficha.jugador == 1){
            ui->casilla_25->setText("X");
        } else {
            ui->casilla_25->setText("O");
        }
    }

    //Casilla 26
    if(tablero.tablero[25].ocupada == 0){
        ui->casilla_26->setText("");
    } else {
        if(tablero.tablero[25].ficha.jugador == 1){
            ui->casilla_26->setText("X");
        } else {
            ui->casilla_26->setText("O");
        }
    }

    //Casilla 27
    if(tablero.tablero[26].ocupada == 0){
        ui->casilla_27->setText("");
    } else {
        if(tablero.tablero[26].ficha.jugador == 1){
            ui->casilla_27->setText("X");
        } else {
            ui->casilla_27->setText("O");
        }
    }

    //Casilla 28
    if(tablero.tablero[27].ocupada == 0){
        ui->casilla_28->setText("");
    } else {
        if(tablero.tablero[27].ficha.jugador == 1){
            ui->casilla_28->setText("X");
        } else {
            ui->casilla_28->setText("O");
        }
    }

    //Casilla 29
    if(tablero.tablero[28].ocupada == 0){
        ui->casilla_29->setText("");
    } else {
        if(tablero.tablero[28].ficha.jugador == 1){
            ui->casilla_29->setText("X");
        } else {
            ui->casilla_29->setText("O");
        }
    }

    //Casilla 30
    if(tablero.tablero[29].ocupada == 0){
        ui->casilla_30->setText("");
    } else {
        if(tablero.tablero[29].ficha.jugador == 1){
            ui->casilla_30->setText("X");
        } else {
            ui->casilla_30->setText("O");
        }
    }

}

void MainWindow::on_inputMove_returnPressed()
{
    QString in = ui->inputMove->text();
    ui->inputMove->clear();
    ui->textMove->hide();
    ui->inputMove->hide();
    ui->sigTurno->show();
    this->inputMove = in.toInt();
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
    int end = mediador.checkWin();
    if(end != 0){
        showEndLabel();
    }
}