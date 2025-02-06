#include "changetask.h"
#include "ui_changetask.h"


ChangeTask::ChangeTask(QWidget *parent, long indexTask)
    : QDialog(parent)
    , ui(new Ui::ChangeTask)
{
    ui->setupUi(this);


    if (indexTask>=0) // Change Task
    {
        indexTask_ = indexTask;
        setDescriptionByTasks(ui->DescLine);
        setDateByTasks();
        this->setWindowTitle("Change");
        connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &ChangeTask::updateTasks);
        initializeStateDropdownChange(ui->comboBoxState);
        initializeUserDropdownChange(ui->comboBoxUser);
    }

    else if (indexTask<0) // Add Task
    {
        indexTask_=0;
        this->setWindowTitle("Add");
        setDateToday();
        connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &ChangeTask::addTasks);
        initializeStateDropdownAdd(ui->comboBoxState);
        initializeUserDropdownAdd(ui->comboBoxUser);
    }

    connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &ChangeTask::reject);


}

ChangeTask::~ChangeTask()
{
    delete ui;
}

void ChangeTask::setDescriptionByTasks(QLineEdit* descLine) {
    descLine->setText(QString::fromStdString(tasks[indexTask_].getDescription()));
}

void ChangeTask::initializeStateDropdownChange(QComboBox* comboBox) {
    comboBox->clear();
    comboBox->addItem(QString::fromStdString(relativeStateToString(tasks[indexTask_].getStateRelative())), QVariant(0));
    for (int i = static_cast<int>(RelativeState::Started); i <= static_cast<int>(RelativeState::Finished); ++i) {
        RelativeState state = static_cast<RelativeState>(i);
        if (relativeStateToString(tasks[indexTask_].getStateRelative()) != relativeStateToString(state))
        {
            comboBox->addItem(QString::fromStdString(relativeStateToString(state)), QVariant(i));
        }
    }
}

void ChangeTask::initializeUserDropdownChange(QComboBox* comboBox) {
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

void ChangeTask::initializeStateDropdownAdd(QComboBox* comboBox) {
    comboBox->clear();
    for (int i = static_cast<int>(RelativeState::Started); i <= static_cast<int>(RelativeState::Finished); ++i) {
        RelativeState state = static_cast<RelativeState>(i);
            comboBox->addItem(QString::fromStdString(relativeStateToString(state)), QVariant(i));
    }
}

void ChangeTask::initializeUserDropdownAdd(QComboBox* comboBox) {
    comboBox->clear();
    QString nullUser = "chosse User";
    comboBox->addItem(nullUser);
    for (const User& user : users) {
        comboBox->addItem(QString::fromStdString(user.getFullName()));
    }
}

void ChangeTask::setDateByTasks(){
    QDate date = QDate::fromString(QString::fromStdString(tasks[indexTask_].getDue()), "yyyy-MM-dd");
    ui->dateEdit->setDate(date);   
}

void ChangeTask::setDateToday(){
    QDate today = QDate::currentDate();
    qDebug()<<today.toString();
    ui->dateEdit->setDate(today);
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

    tasks[indexTask_].setAssignee(users[indexUsers]);

    RelativeState stateRelativeState = relativeStateFromString(ui->comboBoxState->currentText().toStdString());
    tasks[indexTask_].setState(stateRelativeState);
}

void ChangeTask::addTasks() {
    std::string description = ui->DescLine->text().toStdString();

    QDate date = ui->dateEdit->date();

    QString user = ui->comboBoxUser->currentText();

    RelativeState state = relativeStateFromString(ui->comboBoxState->currentText().toStdString());

    long indexUsers = getIndexOfUsers(user.toStdString());

    Task newTask(tasks.size()+1, description, Date(date.toString("yyyy-MM-dd").toStdString()), users[indexUsers], state);
}
