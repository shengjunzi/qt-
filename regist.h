#ifndef REGIST_H
#define REGIST_H

#include <QMainWindow>
#include<QPushButton>
#include"student.h"
#include <QMessageBox>
#include <QProgressDialog>

namespace Ui {
class Regist;
}

class Regist : public QMainWindow
{
    Q_OBJECT

public:
    explicit Regist(QWidget *parent = nullptr);
    ~Regist();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Regist *ui;
    Student *student;
};

#endif // REGIST_H
