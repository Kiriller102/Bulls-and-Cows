#include "dialog.h"
#include "ui_dialog.h"
#include <fstream>

const char* File("/Users/kiriill/Desktop/Qt\ Projects/BaC/Records.txt");

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog) {
    ui->setupUi(this);
    std::ifstream fin(File);
    for (int i = 0; i < 10; i++) {
        int num;
        std::string str;
        fin >> num;
        fin >> str;
        if (num != 0)
            StorageNames_[i] = QString::fromStdString(str);
        if (num == 0)
            StorageNames_[i] = "";
    }
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_pushButton_clicked() {
    bool CorrectInput = true;
    QString str;
    str = ui->EnterName->text();
    ui->EnterName->clear();
    for (int i = 0; i < 10; i++) {
        if (str == StorageNames_[i] && !str.isEmpty()) {
            CorrectInput = false;
        }
    }
    if (CorrectInput && !str.isEmpty()) {
        name_ = str;
        this->close();
    }
    if (!CorrectInput) {
        QFont font("Times",15);
        ui->label->setFont(font);
        ui->label->setText("This name is already taken");
    }
}



void Dialog::on_pushButton_2_clicked() {
    this->close();
}

QString Dialog::GetName() {
    return name_;
}


