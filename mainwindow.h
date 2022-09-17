#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionClose_triggered();

    void on_actionAll_Red_triggered();

    void on_actionAll_Green_triggered();

    void on_actionAll_Blue_triggered();

    void on_actionAll_Purple_triggered();

    void on_actionAll_Black_triggered();

    void on_actionAll_Orange_triggered();

    void on_actionAll_Yellow_triggered();

    void on_actionAll_Sky_triggered();

    void on_actionAll_White_triggered();

    void on_actionAbout_triggered();

    void on_actionGet_Help_triggered();

    void on_actionTrouble_Shoot_Mode_triggered();

    void on_actionSubmit_Feedback_triggered();

    void on_actionShow_the_Code_For_Start_Up_triggered();

    void on_actionChange_Web_Browser_triggered();

    void on_actionChange_Location_of_MSI_file_triggered();

    void on_actionAll_Pink_triggered();

private:
    Ui::MainWindow *ui;
    qint32 _red=0;
    qint32 _orange=0;
    qint32 _yellow=0;
    qint32 _green=0;
    qint32 _sky=0;
    qint32 _blue=0;
    qint32 _purple=0;
    qint32 _white=0;
    qint32 _show_code=0;

    QString _webBrowser="/usr/bin/firefox";
    QString _getHelp = _webBrowser+" https://192.168.1.100/helptop42/ &";
    QString _msiLocation = "/usr/bin/msi-keyboard";
    QString _feedback = _webBrowser+" https://192.168.1.100/helptop42/index.php?feeback=ashercct &";

};
#endif // MAINWINDOW_H
