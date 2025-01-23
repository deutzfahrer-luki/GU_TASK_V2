#ifndef DATATASK_H
#define DATATASK_H

#include <QVector>
#include "model/user.h"
#include "model/task.h"

// Declare users and tasks as external variables
extern QVector<User> users;
extern QVector<Task> tasks;

long getIndexOfUsers(std::string user);

#endif // DATATASK_H
