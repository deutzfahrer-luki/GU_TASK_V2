#ifndef DATE_H
#define DATE_H

#include <string>
#include <chrono>
#include <sstream>
#include <QDate>

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

    void printout();

    QDate getQDate() {
        std::time_t tt = std::chrono::system_clock::to_time_t(timepoint);
        std::tm tm = *std::localtime(&tt);
        return QDate(tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    }
private:
    int year, month, day;
    std::chrono::system_clock::time_point timepoint;

};

#endif // DATE_H
