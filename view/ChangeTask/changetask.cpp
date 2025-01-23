#include "changetask.h"

ChangeTask::ChangeTask(QWidget *parent, long indexTask)
    : QDialog(parent), indexTask_(indexTask)
    , ui(new Ui::ChangeTask)
{
    ui->setupUi(this);
    setDescription(ui->DescLine);
    LoadData::getInstance()->initializeStateDropdown(ui->comboBoxState);
    LoadData::getInstance()->initializeUserDropdown(ui->comboBoxUser);
    LoadData::getInstance()->setDate(ui->dateEdit);

    connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &ChangeTask::updateTasks);
    connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &ChangeTask::reject);
}

ChangeTask::~ChangeTask()
{
    delete ui;
}

void ChangeTask::setDescription(QLineEdit* descLine) {
    descLine->setText(QString::fromStdString(tasks[indexTask_].getDescription()));
}

void ChangeTask::updateTasks(){
    // Description changing
    std::string description = ui->DescLine->text().toStdString();
    tasks[indexTask_].setDescription(description);

    // Date changing
    QDate date = ui->dateEdit->date();
    std::string dueDate = date.toString("yyyy-MM-dd").toStdString();
    tasks[indexTask_].setDue(Date(dueDate));

    // User changing
    QString user = ui->comboBoxUser->currentText();
    long indexUsers = getIndexOfUsers(user.toStdString());
    //std::cout<<indexUsers<<" "<<user.toStdString()<<std::endl;
    tasks[indexTask_].setAssignee(users[indexUsers]);

    // State changing
    RelativeState stateRelativeState = RelativeStateManager::getInstance().relativeStateFromString(ui->comboBoxState->currentText().toStdString());
    tasks[indexTask_].setState(stateRelativeState);
}
