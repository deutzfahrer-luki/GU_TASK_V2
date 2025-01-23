#include "addtasks.h"
#include "ui_addtasks.h"
#include "data/dataTask.h"

AddTasks::AddTasks(QWidget *parent): QDialog(parent), ui(new Ui::AddTasks) {
    ui->setupUi(this);
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
    return ui->lineEditDesc->text(); // Beschreibung aus dem QLineEdit
}

QDate AddTasks::getDate() const {
    return ui->dateEdit->date(); // Datum aus dem QDateEdit
}

QString AddTasks::getSelectedUser() const {
    return ui->comboBoxUser->currentText(); // Ausgewählter Benutzer aus der QComboBox
}

QString AddTasks::getSelectedState() const {
    return ui->comboBoxState->currentText(); // Ausgewählter Status aus der QComboBox
}


/*---------- Setter for Ui ComboBoxes----------*/
void AddTasks::initializeStateDropdown(QComboBox* comboBox) {
    for (int i = static_cast<int>(RelativeState::Started); i <= static_cast<int>(RelativeState::Finished); ++i) {
        RelativeState state = static_cast<RelativeState>(i);
        comboBox->addItem(QString::fromStdString(relativeStateToString(state)), QVariant(i));
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
    Task newTask(tasks.size()+1, description.toStdString(), Date(date.toString("yyyy-MM-dd").toStdString()), users[indexUsers], relativeStateFromString(state.toStdString()));



    emit taskAdded(newTask);
    accept();
}


