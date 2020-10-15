
#include"mysql.h"
#include <QApplication>
#include"student.h"
QString s;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mysql sql;
    sql.initsql();

    Student w;
    w.setWindowTitle("自习室预约系统");
    w.show();
    return a.exec();
}
