#ifndef RELATIVEDUE_H
#define RELATIVEDUE_H

#include <string>
#include <stdexcept>
#include <util/date.h>

enum class RelativeDue
{
    Irrelevant,
    Overdue,
    Today,
    Tomorrow,
    ThisWeek,
    ThisMonth,
    Later
};

inline std::string relativeDueToString(RelativeDue state) {
    switch (state) {
    case RelativeDue::Irrelevant: return "Irrelevant";
    case RelativeDue::Overdue:    return "Overdue";
    case RelativeDue::Today:      return "Today";
    case RelativeDue::Tomorrow:   return "Tomorrow";
    case RelativeDue::ThisWeek:   return "ThisWeek";
    case RelativeDue::ThisMonth:  return "ThisMonth";
    case RelativeDue::Later:      return "Later";
    default:                      return "Unknown";
    }
}

inline RelativeDue relativeDueFromString(const std::string& state) {
    if (state == "Irrelevant") return RelativeDue::Irrelevant;
    if (state == "Overdue")    return RelativeDue::Overdue;
    if (state == "Today")      return RelativeDue::Today;
    if (state == "Tomorrow")   return RelativeDue::Tomorrow;
    if (state == "ThisWeek")   return RelativeDue::ThisWeek;
    if (state == "ThisMonth")  return RelativeDue::ThisMonth;
    if (state == "Later")      return RelativeDue::Later;

    throw std::invalid_argument("Unrecognized RelativeDue string: " + state);
}

/*
std::string relativeDueToday(const Date& due)
{
    Date Today;
    Today.;
}
*/




#endif // RELATIVEDUE_H
