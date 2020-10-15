#include "login.h"
#include "ui_login.h"
#include"mysql.h"
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
   mstudent=new StudentMange(this);
    ui->setupUi(this);
    students =(Student*)parent;
    mteacher=new Teachermange(this);
    ui->password->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok) == button)
    {
        if( (ui->ID->text() == "") || (ui->password->text() == "") )
        {
            QMessageBox::information(this, tr("警告"), tr("输入不能为空！!"), QMessageBox::Ok);
            return;
        }

        QString ID = ui->ID->text();
        QString passward = ui->password->text();
        QString account=ui->comboBox->currentText();

        QProgressDialog dialog(tr("正在登录"),tr("取消"),0,30000,this);
        dialog.setWindowTitle(tr("进度"));
        dialog.setWindowModality(Qt::WindowModal);
        dialog.show();
        for(int k=0;k<30000;k++)
            {
                dialog.setValue(k);
                QCoreApplication::processEvents();
                if(dialog.wasCanceled())
                    {
                        break;
                    }
            }
        dialog.setValue(30000);

        Mysql *mysql=new Mysql;
        bool ret=mysql->loguser(ID,passward,account);
        if(!ret)
            {
                QMessageBox::information(this,tr("消息"),tr("帐号密码不匹配！"),QMessageBox::Ok);
                this->close();
                students->show();   //回到上一个窗口
                return;
            }
        QMessageBox::information(this,tr("消息"),tr("登录成功！"),QMessageBox::Ok);
        this->hide();
        if(account=="学生")
        {
        mstudent->setWindowTitle("自习室预约界面");
       mstudent->show();
        }
        else if(account=="管理员")
        {
            mteacher->setWindowTitle("管理员审核界面");
            mteacher->show();
        }
        return;
     }
    else
    {
        this->close();
        students->show();
    }
}
