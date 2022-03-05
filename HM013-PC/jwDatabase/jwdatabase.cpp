#include "jwdatabase.h"
#include <QApplication>
#include <QDebug>


 jwDataBase::jwDataBase()
{
    //建立并打开数据库
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");

    database.setHostName("localhost");  //数据库主机名
    database.setDatabaseName("scott");  //数据库名
    database.setUserName("stott");      //数据库用户名
    database.setPassword("tiger");      //数据库密码

    //qDebug()<<QApplication::applicationDirPath();
    //database.setDatabaseName(QApplication::applicationDirPath() + "/CONFIG/" + "testApple.db");
    database.setDatabaseName("D:/Index.db");

    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        qDebug() << "Succeed to connect database." ;
    }

    //创建表格
    QSqlQuery sql_query;
    //先清空一下表，可按需添加此句
    sql_query.exec("DROP TABLE student");
    //创建表格student
    if(!sql_query.exec("create table student(UserId int primary key, UserName text, PassWord text)"))
    {
        qDebug() << "Error: Fail to create table."<< sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
    // 填充表
    if(!sql_query.exec("INSERT INTO student VALUES(1, 'AppleCai', '23')"))
    {
        qDebug() << "Error: Fail to create table."<< sql_query.lastError();
    }
    else
    {
        qDebug() << "add one created!";
    }
    // 批量填充表
    QStringList names;
    names<<"小A"<<"小B"<<"小C"<<"小D"<<"小E"<<"小F"<<"小G"<<"小H"<<"小I";

    QStringList password;
    password<<"11"<<"12"<<"13"<<"21"
             <<"22"<<"23"<<"31"<<"32"<<"33";
    // 绑定关键字后才能进行操作
    sql_query.prepare("INSERT INTO student (UserId, UserName,PassWord) "
                      "VALUES (:UserId, :UserName, :PassWord)");
    qint8 i=0;
    foreach (QString name, names)       //从names表里获取每个名字
    {
        sql_query.bindValue(":UserId", i+2);                      //向绑定值里加入名字
        sql_query.bindValue(":UserName", name);      //成绩
        sql_query.bindValue(":PassWord", password[i] );    //班级
        if(!sql_query.exec())
        {
            qDebug() << "Error: Fail."<< sql_query.lastError();
        }

        i++;
    }
    // 读取sqlite
    studentInfo tmp;
    QVector<studentInfo> infoVect; //数据库缓存
    sql_query.exec("SELECT * FROM student WHERE UserId >= 5 AND UserId <= 9;");
    while(sql_query.next())
    {
        tmp.UserId = sql_query.value(0).toInt();
        tmp.UserName = sql_query.value(1).toString();
        tmp.PassWord = sql_query.value(2).toString();
        qDebug()<<tmp.UserId<<tmp.UserName<<tmp.PassWord;
        infoVect.push_back(tmp);
    }
    qDebug("done");

    //更改表中数据
    sql_query.prepare("UPDATE student SET PassWord='admin' WHERE UserName='AppleCai'");
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail."<< sql_query.lastError();
    }

    //删除表中数据
    sql_query.prepare("DELETE FROM student WHERE UserName='小H'");
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail."<< sql_query.lastError();
    }

}
