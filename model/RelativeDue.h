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
    if (state == "Overdue")    return RelativeDue::Overdue;//
    if (state == "Today")      return RelativeDue::Today;//
    if (state == "Tomorrow")   return RelativeDue::Tomorrow;//
    if (state == "ThisWeek")   return RelativeDue::ThisWeek;//
    if (state == "ThisMonth")  return RelativeDue::ThisMonth;//
    if (state == "Later")      return RelativeDue::Later;

    throw std::invalid_argument("Unrecognized RelativeDue string: " + state);
}


inline std::string relativeDueToday(const Date& due)
{
    Date Today;
    long days = Today.daysBetween(due)*(-1);
    if (days < 0)
    {
        return relativeDueToString(RelativeDue::Overdue);
    }
    else if (days == 0)
    {
        return relativeDueToString(RelativeDue::Today);
    }
    else if (days == 1)
    {
        return relativeDueToString(RelativeDue::Tomorrow);
    }
    else if (days>1 && days<=7)
    {
        return relativeDueToString(RelativeDue::ThisWeek);
    }
    else if (days>7 && days <=30)
    {
        return relativeDueToString(RelativeDue::ThisMonth);
    }
    else if (days>30)
    {
        return relativeDueToString(RelativeDue::Later);
    }
    return "Unknown";
}





#endif // RELATIVEDUE_H
