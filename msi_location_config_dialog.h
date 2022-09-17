#ifndef MSI_LOCATION_CONFIG_DIALOG_H
#define MSI_LOCATION_CONFIG_DIALOG_H

#include <QDialog>

namespace Ui {
class MSI_Location_Config_Dialog;
}

class MSI_Location_Config_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit MSI_Location_Config_Dialog(QWidget *parent = nullptr);
    ~MSI_Location_Config_Dialog();

private:
    Ui::MSI_Location_Config_Dialog *ui;
};

#endif // MSI_LOCATION_CONFIG_DIALOG_H
