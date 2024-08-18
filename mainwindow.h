#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>

#include "newpage.h"
#include "dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    // struct destinada a pegar a posição(x e y), altura e comprimento de uma ferramenta
    struct pos{
        int x;
        int y;
        int w;
        int h;
    };
    typedef pos POS;
    ~MainWindow();
    QPushButton* m_navigator;

    //conectar todos os widgets à um slot só e emitir um QString para obter o texto no banco de dados através do titulo fornecido

    // Método responsável por obter todos os títulos passados para o vetor @ref listTitle através do método @ref m_db.getTitle()
    void makeInit();

/**
 * @brief createWidgets
 * Método responsável por criar os botões dinamicamente de acordo com a quantidade de títulos retornados pelo método @ref m_db.getTitle.\n
 * Ele verifica se o botão é o primeiro, se sim, Define a posição de x e y da ferramenta e grava na struct @ref lastPositionButton\n
 * para o próximo botão saber onde vai ser posicionado.\n
 * Conta com a lógica do método @ref verify que guarda parte do algoritmo de organização dos widgets\n
 *
*/
    void createWidgets();

    /**
     * @brief verify
     * Método responsável por acompanhar o posicionamento dos widgets para que não passe do intervalo do tamanho da tela que estão sendo organizados. \n
     * Calcula se a posição x somado com o tamanho do widget  vai passar do tamanho da tela, se sim, ele vai direcionar o widget para a próxima linha, usando a struct que obtém as posições.
     *
     * @param currentWidth
     * @return true: Se a função puder armazenar os widgets na mesma linha.\n false: se os widgets já estiverem no fim da linha. Dessa forma o algoritmo muda a próxima posição x e y para a próxima linha.
     */
    bool verify( int _currentWidth);

    /**
     * @brief connectButtons
     *
     * Método responsável por conectar todos os widgets da lista de ferramentas ao slot @ref on_current_button_clicked
     */
    void connectButtons();

public slots:
    /**
     * @brief on_m_navigator
     *
     * Slot responspável por chamar a interface da classe @ref NewPage
     */
    void on_m_navigator(bool);

    /**
     * @brief on_current_button_clicked
     *
     * Slot responsável por verificar qual botão foi pressionado através do método *isChecked* e executar alguma função à partir disso
     */
    void on_current_button_clicked();

    void showBodyByTitle(QString _title);
private:
    Ui::MainWindow *ui;
    NewPage page;
    QVector<QPushButton*> listScreens;
    DbManager &m_db = DbManager::getInstance();
    QVector<QString> listTitle;
    POS lastPositionButton;
};
#endif // MAINWINDOW_H
