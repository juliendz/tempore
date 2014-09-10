#include "dbmgr.h"


DbMgr::DbMgr(){

    QFile file("db.sqlite");
    bool init_db = true;
    if(file.exists()){
        init_db = false;
    }
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    db_.setDatabaseName("db.sqlite");
    if(init_db){
        qDebug() << "Init";
        init_schema();
    }
}


void DbMgr::init_schema() {
    db_.open();
    QSqlQuery query(db_);
    QStringList schema;
    schema.append("PRAGMA foreign_keys=on;");
    schema.append("CREATE TABLE Project("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "name TEXT, "
                         "descr TEXT, "
                         "created INTEGER DEFAULT 0, "
                         "modified INTEGER DEFAULT 0, "
                         "type INTEGER DEFAULT 0, "
                         "status INTEGER DEFAULT 0"
                         ");");
    schema.append("CREATE TABLE Note("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "body TEXT, "
                         "created INTEGER, "
                         "modified INTEGER, "
                         "project_id INTEGER, "
                         "FOREIGN KEY(project_id) REFERENCES Project(id) ON DELETE CASCADE"
                         ");");
   schema.append("CREATE TABLE Tag("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "name TEXT, "
                         "descr TEXT"
                         ");");
   schema.append("CREATE TABLE ProjectTag("
                         "project_id INTEGER, "
                         "tag_id INTEGER, "
                         "FOREIGN KEY(project_id) REFERENCES Project(id) ON DELETE CASCADE,"
                         "FOREIGN KEY(tag_id) REFERENCES Tag(id) ON DELETE CASCADE"
                         ");");
   schema.append("CREATE TABLE Action("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "serial INTEGER, "
                         "subject TEXT, "
                         "created INTEGER, "
                         "modified INTEGER, "
                         "start_date TEXT, "
                         "end_date TEXT, "
                         "start_time INTEGER, "
                         "end_time INTEGER, "
                         "alarm INTEGER, "
                         "early_reminder_length INTEGER, "
                         "recurring INTEGER, "
                         "project_id INTEGER, "
                         "FOREIGN KEY(project_id) REFERENCES Project(id) ON DELETE CASCADE"
                         ");");
   schema.append("CREATE TABLE Setting("
                         "option TEXT, "
                         "value TEXT"
                         ");");

   for(int i=0; i < schema.size(); i++) {
       if(!query.exec(schema.at(i))){
           qDebug() << query.lastError();
        }

   }
   db_.close();
}



QList<QHash<QString, QVariant>* >* DbMgr::run_select_query(QString qs, QHash<QString, QVariant> args) {
    db_.open();
    QSqlQuery query(db_);
    query.prepare(qs);
    QHashIterator<QString, QVariant> iter(args);
    while (iter.hasNext()) {
        iter.next();
        query.bindValue(iter.key(), iter.value());
    }
    if (!query.exec()) {
        qDebug() << query.lastError();
    }

    QList<QHash<QString, QVariant>* >* qres = new QList<QHash<QString, QVariant>* >();
    bool continueLoop = true;
    do{
        if (query.next()) {
            QHash<QString, QVariant>* qrow = new QHash<QString, QVariant>();
            QSqlRecord rec = query.record();
            int colCount = rec.count();
            for (int i=0; i < colCount; i++) {\
                QString colName = rec.fieldName(i);
                qrow->insert(colName, query.value(i));
            }
            qres->append(qrow);
            continueLoop = true;
        }else{
            continueLoop = false;
        }
    }
    while (continueLoop);
    db_.close();
    return qres;
}



void DbMgr::run_query(QString qs, QHash<QString, QVariant> args){
    db_.open();
    QSqlQuery query(db_);
    query.prepare(qs);
    QHashIterator<QString, QVariant> iter(args);
    while (iter.hasNext()) {
        iter.next();
        query.bindValue(iter.key(), iter.value());
    }
    if (!query.exec()) {
        qDebug() << query.lastError();
    }
   db_.close();
}
