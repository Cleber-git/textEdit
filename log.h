#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDebug>
#include <QDate>
#include <QMutex>



/**
 * @brief The Log class
 * Classe destinada à registrar logs de navegação do usuário
 */
class Log
{
    static Log *instance;
    /**
     * @brief Log
     * Método construtor privado, impedindo que outras classes o invoque
     */
    Log();
public:
    /**
     * @brief getInstance
     * Método responsável por retornar a instância da própria classe, que será única, transformando-a em um singleton
     *
     * @return @ref instance
     */
    static Log &getInstance();

    /**
     * @brief log
     * Método responsável por escrever os logs no arquivo de texto
     *
     * @param _text
     */
    void log(const QString &_text);
    Log(const Log&) = delete;

private:
    QString m_currentDate;
    QString m_path;
    QFile m_file;
    QMutex m_mutex;


};
#define LOGIN Log::getInstance()
#endif // LOG_H
