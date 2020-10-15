#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include<QPushButton>
#include"student.h"
#include <QMessageBox>
#include <QProgressDialog>


namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:


    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Register *ui;
    Student *student;

};

#endif // REGISTER_H
