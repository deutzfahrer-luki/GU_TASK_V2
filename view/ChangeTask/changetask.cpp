#include "changetask.h"
#include "ui_changetask.h"

ChangeTask::ChangeTask(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangeTask)
{
    ui->setupUi(this);
}

ChangeTask::~ChangeTask()
{
    delete ui;
}


void ChangeTask::setDescription(const QString& desc) {
    ui->DescLine->setText(desc);
}

void ChangeTask::initializeStateDropdown(QComboBox* comboBox) {
    for (int i = static_cast<int>(RelativeDue::Irrelevant); i <= static_cast<int>(RelativeDue::Later); ++i) {
        RelativeDue state = static_cast<RelativeDue>(i);
        comboBox->addItem(QString::fromStdString(relativeDueToString(state)), QVariant(i));
    }
}

void ChangeTask::initializeUserDropdown(QComboBox* comboBox) {
    for (const User& user : users) {
        comboBox->addItem(QString::fromStdString(user.getFullName()));
    }
}
