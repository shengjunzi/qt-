#include"mysql.h"
Mysql::Mysql()
{

}

void Mysql::initsql()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("abc");      //数据源名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("zcs");                               //登录用户
    db.setPassword("admin");                           //密码
    if(!db.open())                                      //打开数据库
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
        return ;                                   //打开失败
    }
    else
        qDebug()<<"database open success!";
    return;
}
void Mysql::createtable()
{
        query=new QSqlQuery;
        /*用户表*/
       query->exec("create table if not exists dbo.student(studentID NVARCHAR(30) PRIMARY KEY ,name VARCHAR(30) UNIQUE NOT NULL,  passward VARCHAR(30) UNIQUE NOT NULL)");
       query->exec("create table dbo.teacher(teacherID NVARCHAR(30) PRIMARY KEY ,name VARCHAR(30) UNIQUE NOT NULL,  passward VARCHAR(30) UNIQUE NOT NULL)");

}
bool Mysql::initstu(QString ID,QString name,QString passward,QString account)
{
    query=new QSqlQuery;

    if(account=="学生")
    {
    QString str=QString("insert into dbo.student values('%1','%2','%3')").arg(ID).arg(name).arg(passward);
    bool ret=query->exec(str);
    return ret;
    }
    else if(account=="管理员")
    {
        QString str=QString("insert into dbo.teacher values('%1','%2','%3')").arg(ID).arg(name).arg(passward);
        bool ret=query->exec(str);
        return ret;

    }
}
bool Mysql::loguser(QString ID,QString passward,QString account)
{
    query=new QSqlQuery;
     if(account=="学生")
     {
    QString str=QString("select * from dbo.student where studentID= '%1' and passward = '%2' ").arg(ID).arg(passward);
    query->exec(str);
    query->last();
    int record=query->at()+1;
    if(record==0)
        return false;

    s=query->value(0).toString();
     }
     else if(account=="管理员")
     {
         QString str=QString("select * from dbo.teacher where teacherID= '%1' and passward = '%2' ").arg(ID).arg(passward);
         query->exec(str);
         query->last();
         int record=query->at()+1;
         if(record==0)
             return false;

         s=query->value(0).toString();

     }
    return true;
}
bool Mysql::clear()
{
    query=new QSqlQuery;
    query->exec("select *from dbo.rooms");
    bool ret=query->exec("update dbo.rooms set accept=100");
    return ret;
}
bool Mysql::update(int b)
{




    if(b==0)
    {
       query=new QSqlQuery;
       query->exec("select *from dbo.rooms where roomid='401'");
      int y;
       if(query->next())
       {
        y=query->value(2).toInt();
       y--;
        qDebug()<<y;
       }
      else qDebug()<<"wu";
        QString str=QString("update dbo.rooms set accept='%1' where roomid='401'").arg(y);
        bool ret=query->exec(str);
        qDebug()<<ret;
        return ret;
    }
    else if(b==1)
    {   query=new QSqlQuery;
        query->exec("select *from dbo.rooms where roomid='402'");
       int y;
        if(query->next())
        {
         y=query->value(2).toInt();
        y--;
         qDebug()<<y;
        }
       else qDebug()<<"wu";

        QString str=QString("update dbo.rooms set accept='%1' where roomid='402'").arg(y);
         bool ret=query->exec(str);
         return ret;
     }
    else if(b==2)
    {
         query=new QSqlQuery;
        query->exec("select *from dbo.rooms where roomid='403'");
       int y;
        if(query->next())
        {
         y=query->value(2).toInt();
        y--;
         qDebug()<<y;
        }
       else qDebug()<<"wu";
        QString str=QString("update dbo.room set accept='%1' where roomid='403'").arg(y);
         bool ret=query->exec(str);
         return ret;
    }
}
bool Mysql::initapp(QString data, QString time, QString roomid)
{

    query=new QSqlQuery;
    QString str=QString("insert into dbo.app values('%1','%2','%3','%4','%5')").arg(s).arg(data).arg(time).arg(roomid).arg(0);
    bool ret=query->exec(str);
    return ret;
}
