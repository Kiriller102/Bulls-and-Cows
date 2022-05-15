#ifndef RECORD_H
#define RECORD_H

#include <QDialog>
#include <fstream>

namespace Ui {
class Record;
}

class Record : public QDialog
{
    Q_OBJECT

public:
    explicit Record(QWidget *parent = nullptr);
    ~Record();

    void show();

private slots:
    void on_ClearAll_clicked();

private:
    Ui::Record *ui;
};

#endif // RECORD_H
