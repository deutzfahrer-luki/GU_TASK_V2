#include "loaddata.h".h"
#include <iostream>

// Initialisierung des statischen Zeigers auf das Singleton
LoadData* LoadData::instance = nullptr;

LoadData::LoadData() {
}

LoadData* LoadData::getInstance() {
    if (instance == nullptr) {
        instance = new LoadData();
    }
    return instance;
}


void LoadData::initializeUserDropdown(QComboBox* comboBox) {
    for (const User& user : users) {
        comboBox->addItem(QString::fromStdString(user.getFullName()));
    }
}

void LoadData::initializeStateDropdown(QComboBox* comboBox) {
    for (int i = static_cast<int>(RelativeState::Started); i <= static_cast<int>(RelativeState::Finished); ++i) {
        RelativeState state = static_cast<RelativeState>(i);
        comboBox->addItem(QString::fromStdString(RelativeStateManager::getInstance().relativeStateToString(state)), QVariant(i));
    }
}

void LoadData::setDate(QDateEdit* dateEdit) {
    Date today;
    QDate todayQ = today.getQDate();
    if (todayQ.isValid()) {
        std::cout << todayQ.toString("yyyy-MM-dd").toStdString() << std::endl;
    } else {
        std::cout << "Invalid date!" << std::endl;
    }
    dateEdit->setDate(todayQ);
}
