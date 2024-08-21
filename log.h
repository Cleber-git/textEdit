#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QDate>

class Log
{
    static Log *instance;
    Log();
public:
    // ~Log();
    static Log &getInstance();
    void log(const QString &_text);
    void createFile( QFile &_file, const QString _path );
    Log(const Log&) = delete;

private:
    QString m_currentDate;
    QString m_path;
    QFile m_file;


};

#endif // LOG_H
