#ifndef DBMGR_H
#define DBMGR_H

typedef QList<QHash<QString, QVariant>* >* DB_QRES;
typedef QHash<QString, QVariant>* DB_QROW;

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
#include <QList>

class DbMgr {

public:
    DbMgr();
    QList<QHash<QString, QVariant>* >*  run_select_query(QString qs, QHash<QString, QVariant> args);
    void run_query(QString qs, QHash<QString, QVariant> args);

private:
    void init_schema();

    QSqlDatabase db_;
};

#endif // DBMGR_H
