#include "dbmanager.h"
#include "db.h"

#include <QSqlDatabase>


DbManager *DbManager::instance = nullptr;
DbManager::DbManager() {}

DbManager &DbManager::getInstance(){
    if(instance == nullptr){
        instance = new DbManager();
    }
    return (*instance);
}
bool DbManager::openDB( ){
    return m_db.openDB();
}

QVector<QString> DbManager::getTitle(){
    return m_db.getTitle();
}
QString DbManager::getBody( QString _title ){
    return m_db.getBody(_title);
}

void DbManager::SaveInfo(QString _title, QString _body){
    m_db.SaveInfo(_title, _body);
}

void DbManager::deleteInfo(QString _title){
    m_db.deleteInfo(_title);
}

void DbManager:: update(QString _title, QString _body){
    m_db.update(_title, _body);
}

int DbManager::countRows(){
   return m_db.countRows();
}
