#include "db.h"
#include <QDebug>

Db::Db() {}

//testado: [ OK ]
bool Db::openDB( QSqlDatabase &_db ){
    m_db = _db;
    QString path = qApp->applicationDirPath();
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path + "/editoresDeTexto.db");

    if(m_db.open()){
        qDebug() << "open db [ OK ]";
        return true;
    }

    return false;
}

//testado: [ OK ]
int Db::countRows(){
    QSqlQuery query(m_db);

    QString sql;
    if(m_db.isOpen()){
        sql = "Select count(*) from Text";
        query.prepare(sql);

        if(query.exec()){

            if(query.next()){
                return query.value(1).toInt();
            }
        }else{
            qDebug() << "Não executado";
        }

    }
    return 0;
}

//testado: [ OK ]
QVector<QString> Db::getTitle(){
    QSqlQuery query(m_db);
    QString sql;

    if(m_db.isOpen()){
        sql = "Select titulo from Text";
        query.prepare(sql);
        if(query.exec()){
            qDebug() << "exec";

            while(query.next()){
                m_titleList.push_back(query.value(0).toString());
            }
        }
    }
    return m_titleList;
}

//testado [ OK ]
void Db::SaveInfo(QString _title, QString _body){
    QSqlQuery query(m_db);
    QString sql;

    if (m_db.isOpen()){
        sql = "Insert into Text (titulo, corpo) values (:title, :body)";
        query.prepare(sql);
        query.bindValue(":title", _title);
        query.bindValue(":body", _body);

        if(query.exec()){
            qDebug() << "[ Ok ]";
        }
    }
}


// testado:[ OK ]
void Db::deleteInfo(QString _title) {
    QSqlQuery query(m_db);
    QString sql;

    if (m_db.isOpen()) {
        sql = "Delete from Text where titulo= :title";
        query.prepare(sql);
        query.bindValue(":title", _title);
        if (query.exec()) {
            qDebug() << "Deletado";
        }
    }
}

// testado:[ OK ]
void Db::update(QString _title, QString _body){
    QSqlQuery query(m_db);
    QString sql;

    if(m_db.isOpen()){
        sql = "update Text set corpo = :body where titulo = :title";
        query.prepare(sql);
        query.bindValue(":body", _body);
        query.bindValue(":title", _title);

        if(query.exec()){
            qDebug() <<" Update OK";
        }
    }
}


QString Db::getBody(QString _title){
    if(m_db.isOpen()){
        QSqlQuery query(m_db);
        QString sql = "Select from Text corpo where titulo = :title";
        query.prepare(sql);
        query.bindValue(":title", _title);

        if(!query.exec() || !query.next()) return "";
        QString body = query.value(0).toString();
        return body;
    }
    return " conexão com base de dados fechada ";
}






