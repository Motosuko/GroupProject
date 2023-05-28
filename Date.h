#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Date {

private:
    int year;              // Year
    int month;          // Month 
    int day;               // Day

public:
    vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // Initialize the static map in  class    
    // Constructor that takes a year, a month  and a day
    // Constructor implementation
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }
    // Destructor implementation
    ~Date() {}
    // Returns the year
    int getYear() {
        return year;
    }
    // Returns the month
    int getMonth() {
        return month;
    }

    // Returns the day
    int getDay() {
        return day;
    }
    int operator-(Date& other) {

        // Calculate the number of days in the current year and the other year
        int days1 = getDay();
        int days2 = other.getDay();
        for (int i = 0; i < getMonth(); i++) {
            days1 += days[i];
        }
        for (int i = 0; i < other.getMonth(); i++) {
            days2 += days[i];
        }
        // Check if the years are different and add the number of days in between
        if (getYear() != other.getYear()) {
            // Assume that there are 365 days in a year
            int diff = abs(getYear() - other.getYear());
            cout << diff;
            int sign = (getYear() > other.getYear()) ? 1 : -1;
            days1 += sign * 365 * diff;
            // Return the difference between the two dates

        }
        return abs(days1 - days2);
    }
};