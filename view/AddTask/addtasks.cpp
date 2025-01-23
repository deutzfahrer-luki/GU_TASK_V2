#include "addtasks.h"
#include "ui_addtasks.h"
#include "data/dataTask.h"

AddTasks::AddTasks(QWidget *parent): QDialog(parent), ui(new Ui::AddTasks) {
    ui->setupUi(this);
    setDate();
    initializeStateDropdown(ui->comboBoxState);
    initializeUserDropdown(ui->comboBoxUser);

    connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &AddTasks::addTask);
    connect(ui->buttonBoxEnter, &QDialogButtonBox::accepted, this, &AddTasks::reject);
}

AddTasks::~AddTasks() {
    delete ui;
}


/*---------- Getter from Ui ----------*/
QString AddTasks::getDescription() const {
    return ui->lineEditDesc->text();
}

QDate AddTasks::getDate() const {
    return ui->dateEdit->date();
}

QString AddTasks::getSelectedUser() const {
    return ui->comboBoxUser->currentText();
}

QString AddTasks::getSelectedState() const {
    return ui->comboBoxState->currentText();
}


/*---------- Setter for Ui ----------*/
void AddTasks::initializeStateDropdown(QComboBox* comboBox) {
    for (int i = static_cast<int>(RelativeState::Started); i <= static_cast<int>(RelativeState::Finished); ++i) {
        RelativeState state = static_cast<RelativeState>(i);
        comboBox->addItem(QString::fromStdString(RelativeStateManager::getInstance().relativeStateToString(state)), QVariant(i));
    }
}

void AddTasks::initializeUserDropdown(QComboBox* comboBox) {
    for (const User& user : users) {
        comboBox->addItem(QString::fromStdString(user.getFullName()));
    }
}



/*---------- add Task ----------*/
void AddTasks::addTask() {
    QString description = getDescription();
    QDate date = getDate();
    QString user = getSelectedUser();
    QString state = getSelectedState();

    long indexUsers = getIndexOfUsers(user.toStdString());
    Task newTask(tasks.size()+1, description.toStdString(), Date(date.toString("yyyy-MM-dd").toStdString()), users[indexUsers], RelativeStateManager::getInstance().relativeStateFromString(state.toStdString()));

    emit taskAdded(newTask);
    accept();
}


