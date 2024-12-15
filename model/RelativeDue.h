#ifndef RELATIVEDUE_H
#define RELATIVEDUE_H

#include <string>

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

// Helper-Funktion zur Umwandlung von RelativeDue in einen String
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

#endif // RELATIVEDUE_H
