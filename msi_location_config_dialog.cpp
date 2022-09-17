#include "msi_location_config_dialog.h"
#include "ui_msi_location_config_dialog.h"

MSI_Location_Config_Dialog::MSI_Location_Config_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MSI_Location_Config_Dialog)
{
    ui->setupUi(this);
}

MSI_Location_Config_Dialog::~MSI_Location_Config_Dialog()
{
    delete ui;
}
