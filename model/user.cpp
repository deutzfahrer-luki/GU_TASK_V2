#include "user.h"

User::User(const std::string& vorname, const std::string& nachname, const Date& geburtsdatum)
    : vorname(vorname), nachname(nachname), birthday(geburtsdatum) {}
