#include "teachermange.h"
#include "ui_teachermange.h"
#include<QSqlRecord>
#include"mysql.h"
Teachermange::Teachermange(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Teachermange)
{
    ui->setupUi(this);
    students=(Student*)parent;
    model=new QSqlTableModel(this);
    model->setTable("app");
    ui->tableView->setModel(model);
    model1=new QSqlTableModel(this);
    model1->setTable("rooms");
    ui->tableView_2->setModel(model1);
    model2=new QSqlTableModel(this);
    model2->setTable("student");
     ui->tableView_3->setModel(model2);

}

Teachermange::~Teachermange()
{
    delete ui;
}

void Teachermange::on_pushButton_clicked()
{
    model->submitAll();
}

void Teachermange::on_pushButton_4_clicked()
{

    model1->setTable("rooms");
    ui->tableView_2->setModel(model1);
    model1->select();
    model1->setHeaderData(0,Qt::Horizontal,"教室号");
     model1->setHeaderData(1,Qt::Horizontal,"总座位");
      model1->setHeaderData(2,Qt::Horizontal,"剩余");
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model1->submitAll();
      return;
}

void Teachermange::on_pushButton_3_clicked()
{


      int row=model1->rowCount();
      model1->insertRow(row);
      model1->submitAll();
}

void Teachermange::on_pushButton_6_clicked()
{


      QItemSelectionModel *smodel=ui->tableView_2->selectionModel();
      QModelIndexList list =smodel->selectedRows();
      for(int i=0;i<list.size();i++)
      {
          model1->removeRow(list.at(i).row());
      }
}

void Teachermange::on_pushButton_5_clicked()
{
    model2->select();
    model2->setHeaderData(0,Qt::Horizontal,"学号");
     model2->setHeaderData(1,Qt::Horizontal,"姓名");
      model2->setHeaderData(2,Qt::Horizontal,"密码");
      ui->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
      return ;
}

void Teachermange::on_pushButton_7_clicked()
{
    this->close();
    students->show();
}

void Teachermange::on_pushButton_8_clicked()
{

    model->select();
    model->setHeaderData(0,Qt::Horizontal,"学号");
     model->setHeaderData(1,Qt::Horizontal,"日期");
      model->setHeaderData(2,Qt::Horizontal,"时间");
      model->setHeaderData(3,Qt::Horizontal,"教室");
      model->setHeaderData(4,Qt::Horizontal,"预约状态");
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

void Teachermange::on_pushButton_2_clicked()
{
    int row=model->rowCount();
    model->removeRows(0,row);
    Mysql* mysql = new Mysql;
    int a=mysql->clear();
    if(a == true)
    {
        QMessageBox::information(this, tr("消息"), tr("清除成功!"), QMessageBox::Ok);
        return;
    }
}
