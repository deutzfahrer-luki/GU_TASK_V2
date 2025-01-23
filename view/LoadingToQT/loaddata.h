#ifndef LOADDATA_H
#define LOADDATA_H

#include <QComboBox>
#include <QDateEdit>

#include "data/dataTask.h"
#include "model/user.h"
#include "model/task.h"
#include "model/RelativeState.h"


class LoadData
{
public:
    static LoadData* getInstance();

    void initializeUserDropdown(QComboBox* comboBox);
    void initializeStateDropdown(QComboBox* comboBox);
    void setDate(QDateEdit* dateEdit);

private:
    LoadData();
    static LoadData* instance;
    LoadData(const LoadData&) = delete;
    LoadData& operator=(const LoadData&) = delete;
};

#endif // LOADDATA_H
