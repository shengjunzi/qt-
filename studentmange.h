#ifndef STUDENTMANGE_H
#define STUDENTMANGE_H

#include <QMainWindow>
#include<QSqlTableModel>
#include"student.h"

namespace Ui {
class StudentMange;
}

class StudentMange : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMange(QWidget *parent = nullptr);
    ~StudentMange();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::StudentMange *ui;
    QSqlTableModel *model;
   Student *students;
};

#endif // STUDENTMANGE_H
