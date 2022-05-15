#include "record.h"
#include "core.h"
#include "ui_record.h"
#include <QFile>
#include <QString>

const char *FileName2 = "/Users/kiriill/Desktop/Qt\ Projects/BaC/Records.txt";

Record::Record(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Record) {
    ui->setupUi(this);
    show();
}

Record::~Record() {
    delete ui;
}

void Record::show() {
    std::string str;
    int num;
    std::ifstream fin(FileName2);
    for (int i = 0; i < 10; i++) {
        fin >> num;
        fin >> str;
        if (num != 0) {
            ui->tableWidget->insertRow(i);
            if (num != 0) {
                QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(num));
                QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(str));
                ui->tableWidget->setItem(i,0,item1);
                ui->tableWidget->setItem(i,1 ,item2);
            }
        }
    }
    fin.close();
}




void Record::on_ClearAll_clicked() {
    std::ofstream fout(FileName2);
    for (int i = 0; i < 10; i++) {
        fout << 0 << " -\n";
    }
    fout.close();
    show();
    for (int i = ui->tableWidget->rowCount(); i >= 0; i--) {
        ui->tableWidget->removeRow(i);
    }
}

