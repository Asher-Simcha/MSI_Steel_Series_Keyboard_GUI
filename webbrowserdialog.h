#ifndef WEBBROWSERDIALOG_H
#define WEBBROWSERDIALOG_H

#include <QDialog>

namespace Ui {
class WebBrowserDialog;
}

class WebBrowserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WebBrowserDialog(QWidget *parent = nullptr);
    ~WebBrowserDialog();
private:
    Ui::WebBrowserDialog *ui;
};

#endif // WEBBROWSERDIALOG_H
