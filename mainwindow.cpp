#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QStandardItemModel>
#include "core.h"
#include <QString>
#include <random>
#include <QRegularExpression>
#include "dialog.h"
#include "record.h"
#include "retry.h"
#include <iostream>

Core game;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    qDebug() << QString::number(std::stoi(game.GetConstNum()));
}

void MainWindow::StartNewGame() {
    for (int i = ui->ResultTable->rowCount(); i >= 0 ; i--) {
        ui->ResultTable->removeRow(i);
    }
    ui->RezultLabel->setText("New game started! ");
    game.NewGame();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Show() {
    if (ui->ResultTable->rowCount() < game.GetScore()) {
        QTableWidgetItem  *item1 = new QTableWidgetItem(QString::fromStdString(game.GetNum()));
        QTableWidgetItem  *item2 = new QTableWidgetItem("Cows: " + QString::number(game.GetCows())
                                + "; Bulls: " + QString::number(game.GetBulls()));
        ui->ResultTable->insertRow(0);
        ui->ResultTable->setItem(0, 0, item1);
        ui->ResultTable->setItem(0, 1, item2);
    }
}



void MainWindow::on_Check_clicked() {
    QString str = ui->EnterNum->text();
    bool digit = true;
    bool same = false;
    if (str.size() == 4) {
        for (int i = 0; i < 4; i++) {
            QChar ch = str[i];
            for (int j = i + 1; j < 4; j++) {
                if (ch == str[j]) {
                    same = true;
                    break;
                }
            }
            if (same) {
                break;
            }
        }
    }
    str.toInt(&digit,10);
    if (digit && str.size() == 4 && !same) {
        game.SetNum(str.toStdString());
        ui->RezultLabel->setText("You didn't guess. Try again");
    } else {
        ui->RezultLabel->setText("Incorrect enter");
    }
    Show();
    ui->EnterNum->clear();
    if (game.isWinning()) {
        if (game.IsRecord()) {
            Dialog newRecWind;
            newRecWind.setModal(true);
            newRecWind.exec();
            if (!newRecWind.GetName().isEmpty()) {
                game.NewRecord(newRecWind.GetName());
                Record rec;
                rec.setModal(true);
                rec.exec();
            }
        }
        Retry PAWind;
        PAWind.setModal(true);
        PAWind.SetMW(this);
        PAWind.exec();
        StartNewGame();
    }
}

void MainWindow::on_NewGame_clicked() {
    StartNewGame();
}


void MainWindow::on_Records_clicked() {
    Record rec;
    rec.setModal(true);
    rec.exec();
}

