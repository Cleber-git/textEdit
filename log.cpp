#include "log.h"
#include <QApplication>

Log *Log::instance = nullptr;

Log::Log() {
    QDate *date = new QDate;
    QString currentDate = date->currentDate().toString("ddMMyyyy");

    m_path = qApp->applicationDirPath() + "/Log/" + currentDate + ".txt";
    m_file.setFileName(m_path);

    if(!m_file.open(QIODevice::WriteOnly | QIODevice::Append)){
        qDebug()<< "Arquivo de log não pôde ser aberto";
        return;
    }
}

void Log::log(const QString &_text){
    m_mutex.lock();
    QTime *time = new QTime;
    QString currentHour = time->currentTime().toString("hh:mm:ss:mm");
    QTextStream out(&m_file);
    out << "[ " << currentHour << " ] " << _text << "\n";
    m_mutex.unlock();
}

Log &Log::getInstance(){
    if(instance == nullptr){
        instance = new Log();
    }
    return (*instance);

}
