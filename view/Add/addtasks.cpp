#include "addtasks.h"
#include "ui_addtasks.h"

AddTasks::AddTasks(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTasks)
{
    ui->setupUi(this);
    initializeStateDropdown(ui->comboBoxState);
    initializeUserDropdown(ui->comboBoxUser);

    connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &AddTasks::addTask);
    connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &AddTasks::reject);
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

void AddTasks::addTask() {
    Task newTask(1, "Hallo", Date("224-12-24"), users[1], RelativeDue::Irrelevant);
    emit taskAdded(newTask);
    accept();
}


