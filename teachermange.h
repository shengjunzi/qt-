#ifndef TEACHERMANGE_H
#define TEACHERMANGE_H
#include"student.h"
#include <QMainWindow>
#include<QSqlTableModel>
namespace Ui {
class Teachermange;
}

class Teachermange : public QMainWindow
{
    Q_OBJECT

public:
    explicit Teachermange(QWidget *parent = nullptr);
    ~Teachermange();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Teachermange *ui;
    QSqlTableModel *model;
   Student *students;
   QSqlTableModel *model1;
   QSqlTableModel *model2;
};

#endif // TEACHERMANGE_H
