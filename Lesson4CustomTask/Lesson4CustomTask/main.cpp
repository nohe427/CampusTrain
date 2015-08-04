//
//  main.cpp
//  Lesson4CustomTask
//
//  Created by Alexander Nohe on 8/4/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//
/*  Want to access dates as
 Date d(2015,8,4);
 want to access member components as in month, day, and year.
 Be able to copy a date and then advance the date by some number of days.
 d2.advance(5);
 Assumptions:
 All months have 30 days, no leap years.
 Ask if one date comes before another date. if(d.comeBefore(d2))
 default constructor always sets the date to January 1st, 2000
 */

#include <iostream>
#include "Date.h"

int main(int argc, const char * argv[]) {
    Date d(2015, 8, 4);
    Date d3;
    std::cout << d3.year() << " " << d3.month() << " " << d3.day() << " " << std::endl;
    std::cout << d.year() << " " << d.month() << " " << d.day() << " " << std::endl;
    Date d2 = d;
    std::cout << d2.year() << " " << d2.month() << " " << d2.day() << " " << std::endl;
    d2.advance(5);
    std::cout << d2.year() << " " << d2.month() << " " << d2.day() << " " << std::endl;
    d2.advance(60);
    std::cout << d2.year() << " " << d2.month() << " " << d2.day() << " " << std::endl;
    d2+=1000;
    std::cout << d2.year() << " " << d2.month() << " " << d2.day() << " " << std::endl;
    if (d.comesBefore(d2))
    {
        std::cout << "D comes before d2" << std::endl;
    }
    if (d.comesBefore(d3)) {
        std::cout << "August 2015 comes before January 2000" << std::endl;
    }
    
    Date dec(2014,12,1);
    if(dec < Date(2015,1,1))
    {
        std::cout << "TRUE" << std::endl;
    }
    std::cout << "HELLO";
    return 0;
}
