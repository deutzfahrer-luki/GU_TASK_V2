#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include "util/date.h"
#include "model/user.h"
#include "model/RelativeDue.h"
#include "model/RelativeState.h"

class Task
{
public:
    Task(int id, const std::string& description, const Date& due, const User& assignee, const RelativeState& state)
        : id(id), description(description), due(due), assignee(assignee), state(state) {}

    int getId() const { return id; }
    std::string getDescription() const { return description; }
    std::string getAssignee() const { return assignee.getFullName(); }
    User getUser() { return assignee; }
    RelativeState getStateRelative() const { return state; }
    std::string getStateByString() const { return relativeStateToString(state); }
    std::string getDue() const { return static_cast<std::string>(due); }
    // QDate getDate() const { return due.getQDate(); } Error

    void setDescription(const std::string& newDescription) { description = newDescription; }
    void setAssignee(const User& newAssignee) { assignee = newAssignee; }
    void setState(const RelativeState& newState) { state = newState; }
    void setDue(const Date& newDue) { due = newDue; }

private:
    Date due; // Direktes Date-Objekt
    int id;
    std::string description;
    User assignee;
    RelativeState state;
};

#endif // TASK_H
