#include "studentmange.h"
#include "ui_studentmange.h"
#include<QComboBox>
#include"mysql.h"
#include<QTableView>
StudentMange::StudentMange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMange)
{
    ui->setupUi(this);
    students=(Student*)parent;
}

StudentMange::~StudentMange()
{
    delete ui;
}

void StudentMange::on_pushButton_clicked()
{

    QString date=ui->comboBox->currentText();
    QString time=ui->comboBox_2->currentText();
    QString roomid=ui->comboBox_3->currentText();
    int index=ui->comboBox_3->currentIndex();
    Mysql* mysql = new Mysql;
    bool c=mysql->update(index);

    bool d=mysql->initapp(date,time,roomid);
    if(c)
    {   if(d)
        QMessageBox::information(this, tr("消息"), tr("预约成功!"), QMessageBox::Ok);
        else
         QMessageBox::information(this, tr("消息"), tr("预约失败!"), QMessageBox::Ok);
    }
    else
    QMessageBox::information(this, tr("消息"), tr("预约失败!"), QMessageBox::Ok);
 }

void StudentMange::on_pushButton_2_clicked()
{
    model=new QSqlTableModel(this);
    model->setTable("rooms");
    ui->tableView->setModel(model);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"教室号");
     model->setHeaderData(1,Qt::Horizontal,"总座位");
      model->setHeaderData(2,Qt::Horizontal,"剩余");
      ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
      return ;
}

void StudentMange::on_pushButton_4_clicked()
{
    model=new QSqlTableModel(this);
    model->setTable("app");
    ui->tableView_2->setModel(model);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"学号");
     model->setHeaderData(1,Qt::Horizontal,"日期");
      model->setHeaderData(2,Qt::Horizontal,"时间");
      model->setHeaderData(3,Qt::Horizontal,"教室");
      model->setHeaderData(4,Qt::Horizontal,"预约状态");
      ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
      return ;
}

void StudentMange::on_pushButton_3_clicked()
{
    this->close();
    students->show();

}
