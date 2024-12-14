#ifndef DATE_H
#define DATE_H

#include <string>
#include <chrono>
#include <sstream>

class Date
{
public:
    Date() : timepoint(std::chrono::system_clock::now()) {}
    Date(int year, int month, int day);
    Date(const std::string& date);

    long daysBetween(const Date& other) const;
    long weeksBetween(const Date& other) const;

    std::chrono::seconds operator-(const Date& other) const;
    operator std::string() const;

private:
    std::chrono::system_clock::time_point timepoint;

};

#endif // DATE_H
