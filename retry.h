#ifndef RETRY_H
#define RETRY_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class Retry;
}

class Retry : public QDialog
{
    Q_OBJECT

public:
    explicit Retry(QWidget *parent = nullptr);
    ~Retry();
    void SetMW(MainWindow *);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Retry *ui;
    MainWindow *mw_;
};

#endif // RETRY_H
