#include "register.h"
#include "ui_register.h"
#include"mysql.h"
Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    student=(Student*)parent;

    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);//密码方式显示文本
}

Register::~Register()
{
    delete ui;
}



void Register::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        if((ui->name->text() == "") || (ui->ID->text() == "") || (ui->password->text() == "") )
        {
            QMessageBox::information(this, tr("警告"), tr("输入不能为空！!"), QMessageBox::Ok);
            return;
        }


        QString name = ui->name->text();
        QString studentID = ui->ID->text();
        QString passward = ui->password->text();

        QProgressDialog dialog(tr("正在注册"),tr("取消"), 0, 30000, this);
        dialog.setWindowTitle(tr("进度"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int k = 0; k < 30000; k++)
        {
            dialog.setValue(k);
            QCoreApplication::processEvents();
            if(dialog.wasCanceled())
            {
                break;
            }
        }
        dialog.setValue(30000);
        Mysql* mysql = new Mysql;

         mysql->createtable();

        bool ret = mysql->initstu(studentID,name, passward);
        if(ret == false)
        {
            QMessageBox::information(this, tr("消息"), tr("用户已被注册!"), QMessageBox::Ok);
            this->close();
            student->show();
            return;
        }
        QMessageBox::information(this, tr("消息"), tr("注册成功!"), QMessageBox::Ok);
        //Mparent->name = name;
        this->close();
        student->show();
    }
    else if(ui->buttonBox->button(QDialogButtonBox::Cancel) == button)
    {
        this->close();
    student->show();
    }
}
