#ifndef MYSQL_H
#define MYSQL_H
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include<QMessageBox>
#include<QSqlError>

extern QString s;
class Mysql{
public:
    Mysql();
    void initsql();
    void createtable();
    bool initstu(QString ID,QString name,QString passward,QString account);
    bool loguser(QString ID,QString passward,QString account);
    bool update(int b);
    bool initapp(QString data,QString time,QString roomid);
    bool clear();
private:
    QSqlQuery *query;


};

#endif // MYSQL_H
