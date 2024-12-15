#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include "util/date.h"
#include "model/user.h"
#include "model/RelativeDue.h"

class Task
{
public:
    Task(int id, const std::string& description, const Date& due, const User& assignee, const RelativeDue& state)
        : id(id), description(description), due(due), assignee(assignee), state(state) {}

    void setDone() {

    }

    int getId() const { return id; }
    std::string getDescription() const { return description; }
    std::string getAssignee() const { return assignee.getFullName(); }
    RelativeDue getStateRelative() const { return state; }
    std::string getStateByString() const { return relativeDueToString(state); }
    std::string getDue() const { return static_cast<std::string>(due); }

private:
    Date due; // Direktes Date-Objekt
    int id;
    std::string description;
    User assignee;
    RelativeDue state;
};

#endif // TASK_H
