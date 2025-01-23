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
    setDate();

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

void ChangeTask::initializeStateDropdown(QComboBox* comboBox) {
    comboBox->clear();
    comboBox->addItem(QString::fromStdString(RelativeStateManager::getInstance().relativeStateToString(tasks[indexTask_].getStateRelative())), QVariant(0));
    for (int i = static_cast<int>(RelativeState::Started); i <= static_cast<int>(RelativeState::Finished); ++i) {
        RelativeState state = static_cast<RelativeState>(i);
        if (RelativeStateManager::getInstance().relativeStateToString(tasks[indexTask_].getStateRelative()) != RelativeStateManager::getInstance().relativeStateToString(state))
        {
            comboBox->addItem(QString::fromStdString(RelativeStateManager::getInstance().relativeStateToString(state)), QVariant(i));
        }
    }
}

void ChangeTask::initializeUserDropdown(QComboBox* comboBox) {
    comboBox->clear();
    User assignee = tasks[indexTask_].getUser();
    comboBox->addItem(QString::fromStdString(assignee.getFullName()));
    for (const User& user : users) {
        if (user.getFullName() != assignee.getFullName())
        {
            comboBox->addItem(QString::fromStdString(user.getFullName()));
        }
    }
}

void ChangeTask::setDate(){
    QDate date = QDate::fromString(QString::fromStdString(tasks[indexTask_].getDue()), "yyyy-MM-dd");
    ui->dateEdit->setDate(date);   
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

    RelativeState stateRelativeState = RelativeStateManager::getInstance().relativeStateFromString(ui->comboBoxState->currentText().toStdString());
    tasks[indexTask_].setState(stateRelativeState);
}
