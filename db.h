#ifndef DB_H
#define DB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QApplication>
#include <QVector>

class Db
{
public:
    Db();
    bool openDB( QSqlDatabase &_db );
    void getTitle();
    QString getBody( QString _title );

    // preciso passar o valor de referência para buscar o id
    int getId( QString _value );

    int  countRows();
    void SaveInfo(QString _title, QString _body);
    void deleteInfo(QString _title);
    void update(QString _title, QString _body);

private:
    QSqlDatabase m_db;
    QVector<QString> m_title;



};

#endif // DB_H
