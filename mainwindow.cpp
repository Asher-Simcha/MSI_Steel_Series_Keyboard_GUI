#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QProcess"
#include "QDir"
#include <QFileInfo>
#include "webbrowserdialog.h"
#include "msi_location_config_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString mode, left_color, middle_color, right_color, left_intesity, middle_intesity, right_intesity;

    if(ui->radioButton_mode_normal->isChecked()){
        mode = "-m normal";
    }
    if(ui->radioButton_mode_gaming->isChecked()){
        mode = "-m gaming";
    }
//    if(ui->radioButton_mode_breathe->isChecked()){
//        mode = "-m breathe";
//    }
//    if(ui->radioButton_mode_demo->isChecked()){
//        mode = "-m demo";
//    }
//    if(ui->radioButton_mode_wave->isChecked()){
//        mode = "-m wave";
//    }

    if(ui->radioButton_left_off->isChecked()){
        left_color = "-c right,off";
    }
    if(ui->radioButton_left_red->isChecked()){
        left_color = "-c left,red";
    }
    if(ui->radioButton_left_orange->isChecked()){
        left_color = "-c left,orange";
    }
    if(ui->radioButton_left_yellow->isChecked()){
        left_color = "-c left,yellow";
    }
    if(ui->radioButton_left_green->isChecked()){
        left_color = "-c left,green";
    }
    if(ui->radioButton_left_sky->isChecked()){
        left_color = "-c left,sky";
    }
    if(ui->radioButton_left_blue->isChecked()){
        left_color = "-c left,blue";
    }
    if(ui->radioButton_left_purple->isChecked()){
        left_color = "-c left,purple";
    }
    if(ui->radioButton_left_white->isChecked()){
        left_color = "-c left,white";
    }

    if(ui->radioButton_middle_off->isChecked()){
        middle_color = "-c middle,off";
    }
    if(ui->radioButton_middle_red->isChecked()){
        middle_color = "-c middle,red";
    }
    if(ui->radioButton_middle_orange->isChecked()){
        middle_color = "-c middle,orange";
    }
    if(ui->radioButton_middle_yellow->isChecked()){
        middle_color = "-c middle,yellow";
    }
    if(ui->radioButton_middle_green->isChecked()){
        middle_color = "-c middle,green";
    }
    if(ui->radioButton_middle_sky->isChecked()){
        middle_color = "-c middle,sky";
    }
    if(ui->radioButton_middle_blue->isChecked()){
        middle_color = "-c middle,blue";
    }
    if(ui->radioButton_middle_purple->isChecked()){
        middle_color = "-c middle,purple";
    }
    if(ui->radioButton_middle_white->isChecked()){
        middle_color = "-c middle,white";
    }

    if(ui->radioButton_right_off->isChecked()){
        right_color = "-c right,off";
    }
    if(ui->radioButton_right_red->isChecked()){
        right_color = "-c right,red";
    }
    if(ui->radioButton_right_orange->isChecked()){
        right_color = "-c right,orange";
    }
    if(ui->radioButton_right_yellow->isChecked()){
        right_color = "-c right,yellow";
    }
    if(ui->radioButton_right_green->isChecked()){
        right_color = "-c right,green";
    }
    if(ui->radioButton_right_sky->isChecked()){
        right_color = "-c right,sky";
    }
    if(ui->radioButton_right_blue->isChecked()){
        right_color = "-c right,blue";
    }
    if(ui->radioButton_right_purple->isChecked()){
        right_color = "-c right,purple";
    }
    if(ui->radioButton_right_white->isChecked()){
        right_color = "-c right,white";
    }

    if(ui->radioButton_left_int_low->isChecked()){
        left_intesity = "low";
    }

    if(ui->radioButton_left_int_light->isChecked()){
        left_intesity = "light";
    }
    if(ui->radioButton_left_int_medium->isChecked()){
        left_intesity = "medium";
    }
    if(ui->radioButton_left_int_high->isChecked()){
        left_intesity = "high";
    }

    if(ui->radioButton_middle_int_low->isChecked()){
        middle_intesity = "low";
    }

    if(ui->radioButton_middle_int_light->isChecked()){
        middle_intesity = "light";
    }
    if(ui->radioButton_middle_int_medium->isChecked()){
        middle_intesity = "medium";
    }
    if(ui->radioButton_middle_int_high->isChecked()){
        middle_intesity = "high";
    }

    if(ui->radioButton_right_int_low->isChecked()){
        right_intesity = "low";
    }
    if(ui->radioButton_right_int_light->isChecked()){
        right_intesity = "light";
    }
    if(ui->radioButton_right_int_medium->isChecked()){
        right_intesity = "medium";
    }
    if(ui->radioButton_right_int_high->isChecked()){
        right_intesity = "high";
    }

QString finaloutput =mode+" "+left_color+","+left_intesity+" "+middle_color+","+middle_intesity+" "+right_color+","+right_intesity;
finaloutput = _msiLocation+" "+finaloutput;
QByteArray out = finaloutput.toLocal8Bit();
// call an external program to run
system(out);
if(_show_code==1) QMessageBox::information(this, "Final Results", finaloutput);
//qint64 status;
//status = system(out);
//QString status_out = QString::number(status);
//QMessageBox::information(this,"Results Output", status_out);

}

void MainWindow::on_actionClose_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAll_Red_triggered()
{
    QString finaloutput;
    if(_red==0){
        finaloutput ="-m normal -c left,red,high -c middle,red,high -c right,red,high";
        _red++;
    } else if (_red==1){
        finaloutput ="-m normal -c left,red,medium -c middle,red,medium -c right,red,medium";
      _red++;
    } else if(_red==2) {
        finaloutput ="-m normal -c left,red,low -c middle,red,low -c right,red,low";
        _red++;
    }else {
        finaloutput ="-m normal -c left,red,light -c middle,red,light -c right,red,light";
        _red=0;
    }
    finaloutput = _msiLocation+" "+finaloutput;
    QByteArray out = finaloutput.toLocal8Bit();
    // call another application
    system(out);
}

void MainWindow::on_actionAll_Green_triggered()
{
    QString finaloutput;
    if(_green==0){
        finaloutput ="-m normal -c left,green,high -c middle,green,high -c right,green,high";
        _green++;
    }else if(_green==1){
        finaloutput ="-m normal -c left,green,medium -c middle,green,medium -c right,green,medium";
        _green++;
    }else if(_green==2){
        finaloutput ="-m normal -c left,green,low -c middle,green,low -c right,green,low";
        _green++;
    }else{
        finaloutput ="-m normal -c left,green,light -c middle,green,light -c right,green,light";
        _green=0;
    }
    finaloutput = _msiLocation+" "+finaloutput;
    QByteArray out = finaloutput.toLocal8Bit();
    // execute another seperate program
    system(out);
}

void MainWindow::on_actionAll_Blue_triggered()
{
    QString finaloutput;
    if(_blue==0){
        finaloutput ="-m normal -c left,blue,high -c middle,blue,high -c right,blue,high";
        _blue++;
    }else if(_blue==1){
        finaloutput ="-m normal -c left,blue,medium -c middle,blue,medium -c right,blue,medium";
        _blue++;
    }else if(_blue==2){
        finaloutput ="-m normal -c left,blue,low -c middle,blue,low -c right,blue,low";
        _blue++;
    }else{
        finaloutput ="-m normal -c left,blue,light -c middle,blue,light -c right,blue,light";
        _blue=0;
    }
    finaloutput = _msiLocation+" "+finaloutput;
    QByteArray out = finaloutput.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionAll_Purple_triggered()
{
    QString finaloutput;
    if(_purple==0){
        finaloutput ="-m normal -c left,purple,high -c middle,purple,high -c right,purple,high";
        _purple++;
    }else if(_purple==1){
        finaloutput ="-m normal -c left,purple,medium -c middle,purple,medium -c right,purple,medium";
        _purple++;
    }else if(_purple==2){
        finaloutput ="-m normal -c left,purple,low -c middle,purple,low -c right,purple,low";
        _purple++;
    }else{
        finaloutput ="-m normal -c left,purple,light -c middle,purple,light -c right,purple,light";
        _purple=0;
    }finaloutput = _msiLocation+" "+finaloutput;
    QByteArray out = finaloutput.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionAll_Black_triggered()
{
    QString finaloutput =_msiLocation+"  -m normal -c left,off,high -c middle,off,high -c right,off,high";
    QByteArray out = finaloutput.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionAll_Orange_triggered()
{
    QString finaloutput;
    if(_orange==0){
        finaloutput ="-m normal -c left,orange,high -c middle,orange,high -c right,orange,high";
        _orange++;
    }else if(_orange==1){
        finaloutput ="-m normal -c left,orange,medium -c middle,orange,medium -c right,orange,medium";
        _orange++;
    }else if(_orange==2){
        finaloutput ="-m normal -c left,orange,low -c middle,orange,low -c right,orange,low";
        _orange++;
    }else{
        finaloutput ="-m normal -c left,orange,light -c middle,orange,light -c right,orange,light";
        _orange=0;
    }
    finaloutput = _msiLocation+" "+finaloutput;
    QByteArray out = finaloutput.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionAll_Yellow_triggered()
{
    QString finaloutput;
    if(_yellow==0){
        finaloutput ="-m normal -c left,yellow,high -c middle,yellow,high -c right,yellow,high";
        _yellow++;
    }else if(_yellow==1){
        finaloutput ="-m normal -c left,yellow,medium -c middle,yellow,medium -c right,yellow,medium";
        _yellow++;
    }else if(_yellow==2){
        finaloutput ="-m normal -c left,yellow,low -c middle,yellow,low -c right,yellow,low";
        _yellow++;
    }else{
        finaloutput ="-m normal -c left,yellow,light -c middle,yellow,light -c right,yellow,light";
        _yellow=0;
    }
    finaloutput = _msiLocation+" "+finaloutput;
    QByteArray out = finaloutput.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionAll_Sky_triggered()
{
    QString finaloutput;
    if(_sky==0){
        finaloutput ="-m normal -c left,sky,high -c middle,sky,high -c right,sky,high";
        _sky++;
    }else if(_sky==1){
        finaloutput ="-m normal -c left,sky,medium -c middle,sky,medium -c right,sky,medium";
        _sky++;
    }else if(_sky==2){
        finaloutput ="-m normal -c left,sky,low -c middle,sky,low -c right,sky,low";
        _sky++;
    }else{
        finaloutput ="-m normal -c left,sky,light -c middle,sky,light -c right,sky,light";
        _sky=0;
    }
    finaloutput = _msiLocation+" "+finaloutput;
    QByteArray out = finaloutput.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionAll_White_triggered()
{
    QString finaloutput;
    if(_white==0){
        finaloutput ="-m normal -c left,white,high -c middle,white,high -c right,white,high";
        _white++;
    }else if(_white==1){
        finaloutput ="-m normal -c left,white,medium -c middle,white,medium -c right,white,medium";
        _white++;
    }else if(_white==2){
        finaloutput ="-m normal -c left,white,low -c middle,white,low -c right,white,low";
        _white++;
    }else{
        finaloutput ="-m normal -c left,white,light -c middle,white,light -c right,white,light";
        _white=0;
    }
    finaloutput = _msiLocation+" "+finaloutput;
    QByteArray out = finaloutput.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionAbout_triggered()
{
    QString output;
    output ="Developed with: Qt 5.12.8\n";
    output +="on: Ubuntu 20\n";
    output +="\n";
    output += "Author: Asher Simcha\n";
    output += "Date 12/09/2021 \n";
    output +="(C) Asher's cct 2021 \n";
    output +="\n";
    output +="\n";
    QMessageBox::about(this, "About ashercct", output);
}

void MainWindow::on_actionGet_Help_triggered()
{
    QByteArray out = _getHelp.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionTrouble_Shoot_Mode_triggered()
{
    QString fileName = _msiLocation;
    QFile file(fileName);

    QString output;
    output = "asherccp seems to be missing the file: \n";
    output += "msi-keyboard\n";
    output += "\n";
    output += "IF you have a steelseries Keyboard\n";
    output += "you need to install msi-keyboard\n";
    output += "\n";
    output += "Type into the terminal/console:\n";
    output += "\n";
    output += "sudo apt-get install msi-keyboard\n";
    output += "\n";
    output += "After the Program is installed:\n";
    output += "Restart this Program\n";
    output += "\n";
    output += "And Use at your leasure!!!\n";
    // if file exists
    if(!QFile::exists(fileName)){
        QMessageBox::warning(this, "Missing Program", output);
    } else {
        QString output;
        output = "ashercct\n";
        output += "\n";
        output += "All the required Files Seem to be here.\n";
        output += "\n";
        output += "If You have a steel series keyboard\n";
        output += "and this program is not working\n";
        output += "\n";
        output += "You might want to try typing into the terminal/console\n";
        output += "\n";
        output += "/usr/bin/msi-keyboard -m normal -c left,red,high -c middle,green,high -c right,blue,high\n";
        output += "\n";
        output += "if this does not work,\n";
        output += "\n";
        output += "Make sure that the program msi-keyboard is in the /usr/bin Folder\n";
        output += "else:\n";
        output += "Make sure you have a steelseries keyboard that is compatable\n";
        output += "\n";
        output += "If your issues continues. Please send feedback\n";
        output += "Thank you for giving us, your time in feedback\n";
        output += "\n";
        QMessageBox::information(this, "Missing Program", output);
    }

}

void MainWindow::on_actionSubmit_Feedback_triggered()
{
    QString output = _feedback;

    QByteArray out = output.toLocal8Bit();
    system(out);
}

void MainWindow::on_actionShow_the_Code_For_Start_Up_triggered()
{
    if (_show_code==0) {
        ui->actionShow_the_Code_For_Start_Up->setText("Turn off the Start up Code");
        _show_code=1;
    } else {
        ui->actionShow_the_Code_For_Start_Up->setText("Show the Code For Start Up");
        _show_code=0;
    }
}

void MainWindow::on_actionChange_Web_Browser_triggered()
{
    WebBrowserDialog WBDialog;
    WBDialog.setModal(true);
    WBDialog.exec();
}

void MainWindow::on_actionChange_Location_of_MSI_file_triggered()
{
    MSI_Location_Config_Dialog MSIDialog;
    MSIDialog.setModal(true);
    MSIDialog.exec();
}
