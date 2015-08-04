//
//  Date.cpp
//  Lesson4CustomTask
//
//  Created by Alexander Nohe on 8/4/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <stdio.h>
#include "Date.h"


Date::Date()
    {
        year_ = 2000;
        month_ = 1;
        day_ = 1;
    }
Date::Date(int year, int month, int day)
    {
        year_ = year;
        month_ = month;
        day_ = day;
    }
    

    
void Date::advance(int daysToAdvance)
    {
        int totalYearsToAdvance = 0;
        int totalMonthsToAdvance = 0;
        while (daysToAdvance + day_ > 30)
        {
            totalMonthsToAdvance +=1;
            daysToAdvance -=30;
        }
        while (totalMonthsToAdvance + month_ > 12)
        {
            totalMonthsToAdvance -= 12;
            totalYearsToAdvance += 1;
        }
        year_+=totalYearsToAdvance;
        month_+=totalMonthsToAdvance;
        day_+=daysToAdvance;
    }

void Date::operator +=(int daysToAdvance)
{
    int totalYearsToAdvance = 0;
    int totalMonthsToAdvance = 0;
    while (daysToAdvance + day_ > 30)
    {
        totalMonthsToAdvance +=1;
        daysToAdvance -=30;
    }
    while (totalMonthsToAdvance + month_ > 12)
    {
        totalMonthsToAdvance -= 12;
        totalYearsToAdvance += 1;
    }
    year_+=totalYearsToAdvance;
    month_+=totalMonthsToAdvance;
    day_+=daysToAdvance;
}

bool Date::comesBefore(Date dateToCompare) const
    {
        if (year_ == dateToCompare.year())
        {
            if (month_ == dateToCompare.month()) {
                if (day_ > dateToCompare.day()) {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else if (month_ > dateToCompare.month())
            {
                return false;
            }
            else {
                return true;
            }
        }
        else if (year_ < dateToCompare.year())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

bool Date::operator< (Date dateToCompare) const
{
    if (year_ == dateToCompare.year())
    {
        if (month_ == dateToCompare.month()) {
            if (day_ > dateToCompare.day()) {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (month_ > dateToCompare.month())
        {
            return false;
        }
        else {
            return true;
        }
    }
    else if (year_ < dateToCompare.year())
    {
        return true;
    }
    else
    {
        return false;
    }
}