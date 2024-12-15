#include "addtasks.h"
#include "ui_addtasks.h"

#include "data/dataTask.h"
#include "model/RelativeDue.h"
#include "model/user.h"

AddTasks::AddTasks(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTasks)
{
    ui->setupUi(this);
    initializeStateDropdown(ui->comboBoxState);
    initializeUserDropdown(ui->comboBoxUser);
}

AddTasks::~AddTasks()
{
    delete ui;
}


void AddTasks::initializeStateDropdown(QComboBox* comboBox) {
    for (int i = static_cast<int>(RelativeDue::Irrelevant); i <= static_cast<int>(RelativeDue::Later); ++i) {
        RelativeDue state = static_cast<RelativeDue>(i);
        comboBox->addItem(QString::fromStdString(relativeDueToString(state)), QVariant(i));
    }
}

void AddTasks::initializeUserDropdown(QComboBox* comboBox) {
    for (const User& user : users) {
        comboBox->addItem(QString::fromStdString(user.getFullName()));
    }
}

