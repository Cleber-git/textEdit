#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include "db.h"
#include <QVector>

class DbManager
{
public:
    static DbManager &getInstance();
    DbManager(const DbManager&) = delete;
    bool openDB( QSqlDatabase &_db );
    QVector<QString> getTitle();
    QString getBody( QString _title );

    // preciso passar o valor de referência para buscar o id
    int  countRows();
    void SaveInfo(QString _title, QString _body);
    void deleteInfo(QString _title);
    void update(QString _title, QString _body);

private:
    DbManager();
    static DbManager *instance;
    Db m_db;

};

#endif // DBMANAGER_H
