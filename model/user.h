#ifndef USER_H
#define USER_H

#include <iostream>
#include "util/date.h"

class User {
public:
    User(int id, const std::string& vorname, const std::string& nachname, const Date& geburtsdatum)
        : id(id), vorname(vorname), nachname(nachname), birthday(geburtsdatum) {}

    void print() const;
    void printDate() const;

    std::string getVorname() const { return this->vorname; }
    void setVorname(const std::string& vorname) { this->vorname = vorname; }

    std::string getNachname() const { return this->nachname; }
    void setNachname(const std::string& nachname) { this->nachname = nachname; }

    std::string getFullName() const { return vorname + " " + nachname; }

    Date getBirthday() const { return this->birthday; }
    void setBirthday(const Date& birthday) { this->birthday = birthday; }

    bool compareUser(User* comperative)
    {
        if (comperative->getFullName() == this->getFullName())
        {
            return true;
        }
        return false;
    }

private:
    int id;
    std::string vorname;
    std::string nachname;
    Date birthday;
};

#endif // USER_H
