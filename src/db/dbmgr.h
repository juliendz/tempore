#ifndef DBMGR_H
#define DBMGR_H

#include <QObject>
#include <QMutex>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QHash>
#include <QHashIterator>
#include <QList>

typedef QList<QHash<QString, QVariant>* >* DB_QRES;
typedef QHash<QString, QVariant>* DB_QROW;

class DbMgr {

public:
    DbMgr();
    DB_QRES run_select_query(QString qs, DB_QROW args);
    void run_query(QString qs, QHash<QString, QVariant> args);

private:
    void init_schema();

    QSqlDatabase db_;
};

#endif // DBMGR_H
