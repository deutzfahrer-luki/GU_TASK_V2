#include "util/date.h"
#include <iostream>
#include <sstream>
#include <iomanip>



Date::Date(int year, int month, int day) {
    std::tm tm = {};
    tm.tm_year = year - 1900; // Adjust for tm_year
    tm.tm_mon = month - 1;    // Adjust for tm_mon
    tm.tm_mday = day;

    // Convert std::tm to time_t and then to time_point
    timepoint = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}


Date::Date(const std::string& date) {
    int year, month, day;
    char delimiter;
    std::stringstream ss(date);
    if (!(ss >> year >> delimiter >> month >> delimiter >> day) || delimiter != '-') {
        throw std::invalid_argument("Invalid date format. Expected format: YYYY-MM-DD");
    }
    *this = Date(year, month, day);
}

long Date::daysBetween(const Date& other) const {
    auto diff = std::chrono::duration_cast<std::chrono::days>(timepoint - other.timepoint);
    return diff.count();
}

long Date::weeksBetween(const Date& other) const {
    return daysBetween(other) / 7;
}

std::chrono::seconds Date::operator-(const Date& other) const {
    return std::chrono::duration_cast<std::chrono::seconds>(timepoint - other.timepoint);
}

Date::operator std::string() const {
    std::time_t t = std::chrono::system_clock::to_time_t(timepoint);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&t), "%Y-%m-%d");
    return oss.str();
}
