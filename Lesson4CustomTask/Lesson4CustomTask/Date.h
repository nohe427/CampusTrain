//
//  Date.h
//  Lesson4CustomTask
//
//  Created by Alexander Nohe on 8/4/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#ifndef Lesson4CustomTask_Date_h
#define Lesson4CustomTask_Date_h


#endif

class Date
{
public:
    Date();
    Date(int year, int month, int day);
    int year()  const { return year_;  }
    int month() const { return month_; }
    int day()   const { return day_;   }
    void advance(int daysToAdvance);
    bool comesBefore(Date dateToCompare) const;
    void operator +=(int daysToAdvance);
    bool operator< (Date dateToCompare) const;
    bool operator> (Date dateToCompare) const;
    
private:
    int year_;
    int month_;
    int day_;
};