#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include "util/date.h"

class Task
{
public:
    Task(int id, const std::string& description, const Date& due, const std::string& assignee, const std::string& state)
        : id(id), description(description), due(due), assignee(assignee), state(state) {}

    void setDone() {
        if (state != "done") {
            state = "done";
            std::cout << "Task " << id << " marked as done.\n";
        }
    }

    int getId() const { return id; }
    std::string getDescription() const { return description; }
    std::string getAssignee() const { return assignee; }
    std::string getState() const { return state; }
    std::string getDue() const { return static_cast<std::string>(due); }

private:
    Date due; // Direktes Date-Objekt
    int id;
    std::string description;
    std::string assignee;
    std::string state;
};

#endif // TASK_H
