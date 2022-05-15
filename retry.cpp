#include "retry.h"
#include "ui_retry.h"

Retry::Retry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Retry)
{
    ui->setupUi(this);
}

Retry::~Retry()
{
    delete ui;
}

void Retry::SetMW(MainWindow *MW) {
    mw_ = MW;
}

void Retry::on_buttonBox_accepted() {
    this->close();
}


void Retry::on_buttonBox_rejected() {
    mw_->close();
    this->close();
}

