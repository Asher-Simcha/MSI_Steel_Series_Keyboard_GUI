#include "webbrowserdialog.h"
#include "ui_webbrowserdialog.h"

WebBrowserDialog::WebBrowserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WebBrowserDialog)
{
    ui->setupUi(this);
}

WebBrowserDialog::~WebBrowserDialog()
{
    delete ui;
}
