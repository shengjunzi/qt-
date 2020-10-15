#ifndef LOGIN_H
#define LOGIN_H
#include"studentmange.h"
#include <QMainWindow>
#include<QPushButton>
#include <QMessageBox>
#include <QProgressDialog>
#include"student.h"
#include"teachermange.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Login *ui;
    Student *students;
    StudentMange *mstudent;
    Teachermange *mteacher;
};

#endif // LOGIN_H
