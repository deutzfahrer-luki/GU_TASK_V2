#include "dataTask.h"

// Define users and tasks here, initialized as needed
QVector<User> users = {
    User(1,"--choose--", "", Date(1900, 1,1)),
    User(2,"Lukas", "Köppl", Date(2007,9,22)),
    User(3,"Simon", "Gunaka", Date(1900, 1,1)),
};

QVector<Task> tasks = {
    Task(1,"Finish Homework", Date(2024,12,24), users[0], RelativeState::Finished),
    Task(2, "Finish School", Date("2030-12-24"), users[1], RelativeState::Staying),
    Task(3, "Finish School", Date("2030-12-24"), users[1], RelativeState::Finished),
    Task(4, "Finish School", Date("2030-12-24"), users[1], RelativeState::Working),

};


void removeTask(uint8_t taskIdToDelete)
{
    auto it = std::remove_if(tasks.begin(), tasks.end(), [taskIdToDelete](const Task& task) {
        return task.getId() == taskIdToDelete;
    });
}

long getIndexOfUsers(std::string user)
{
    for (unsigned int i = 0; users.size(); i++)
    {
        if (user == users[i].getFullName())
        {
            return i;
        }
    }
    return -1;
}
