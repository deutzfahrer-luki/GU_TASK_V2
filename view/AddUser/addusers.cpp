#include "addusers.h"
#include "ui_addusers.h"

AddUsers::AddUsers(QWidget *parent): QDialog(parent), ui(new Ui::AddUsers) {
    ui->setupUi(this);
}

AddUsers::~AddUsers() {
    delete ui;
}
