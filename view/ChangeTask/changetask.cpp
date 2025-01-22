#include "changetask.h"
#include "ui_changetask.h"

ChangeTask::ChangeTask(QWidget *parent, long indexTask)
    : QDialog(parent), indexTask_(indexTask)
    , ui(new Ui::ChangeTask)
{
    ui->setupUi(this);
    setDescription(ui->DescLine);
    initializeStateDropdown(ui->comboBoxState);
    initializeUserDropdown(ui->comboBoxUser);

}

ChangeTask::~ChangeTask()
{
    delete ui;
}


void ChangeTask::setDescription(QLineEdit* descLine) {
    descLine->setText(QString::fromStdString(tasks[indexTask_].getDescription()));
}

void ChangeTask::initializeStateDropdown(QComboBox* comboBox) {
    comboBox->addItem(QString::fromStdString(relativeStateToString(tasks[indexTask_].getStateRelative())), QVariant(0));
    for (int i = static_cast<int>(RelativeState::Started); i <= static_cast<int>(RelativeState::Finished); ++i) {
        RelativeState state = static_cast<RelativeState>(i);
        if (relativeStateToString(tasks[indexTask_].getStateRelative()) != relativeStateToString(state))
        {
            comboBox->addItem(QString::fromStdString(relativeStateToString(state)), QVariant(i));
        }
    }
}

void ChangeTask::initializeUserDropdown(QComboBox* comboBox) {
    for (const User& user : users) {
        comboBox->addItem(QString::fromStdString(user.getFullName()));
    }
}
