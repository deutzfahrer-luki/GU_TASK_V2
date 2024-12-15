#ifndef DATATASK_H
#define DATATASK_H

#include "model/user.h"
#include "model/task.h"

#include <QVector>


QVector<User> users = {
    User("Lukas", "Köppl", Date(2007,9,22)),
    User("Simon", "Gunaka", Date(1900, 1,1)),
};

QVector<Task> tasks = {
    Task(1,"Finsh Homework", Date(2024,12,24), users[0], RelativeDue::Irrelevant),
    Task(2, "finish school", Date("2030-12-24"), users[1], RelativeDue::Irrelevant),
};


#endif // DATATASK_H
