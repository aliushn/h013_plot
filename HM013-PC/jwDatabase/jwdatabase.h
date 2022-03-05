#ifndef JWDATABASE_H
#define JWDATABASE_H

#include "qdebug.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QStringList>
#include <QTime>
#include <QDateTime>
#include <QtGlobal>

class jwDataBase
{
public:
    jwDataBase();

    typedef struct {
      QString UserId ;
      QString UserName ;
      QString  PassWord ;
    }studentInfo;
};

#endif // JWDATABASE_H
