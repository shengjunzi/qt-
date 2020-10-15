#include "student.h"
#include "ui_student.h"
#include"regist.h"
#include"login.h"

Student::Student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Student)
{

    ui->setupUi(this);
}

Student::~Student()
{
    delete ui;
}

void Student::on_pushButton_clicked()
{
    this->hide();
    Regist *reg=new Regist(this);
    reg->setWindowTitle("注册界面");
    reg->show();
}

void Student::on_pushButton_2_clicked()
{
    this->hide();
    Login *log=new Login(this);
    log->setWindowTitle("登陆界面");
    log->show();

}

void Student::on_pushButton_3_clicked()
{
    this->close();

}
