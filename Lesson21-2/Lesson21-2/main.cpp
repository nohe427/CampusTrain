//
//  main.cpp
//  Lesson21-2
//
//  Created by Alexander Nohe on 8/7/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>

using namespace std;

typedef void (*Callback)(string Message);

class Timer
{
private:
    Callback wakeup_;
    int numberOfTicks = 0;
    int lengthOfTimer = 0;
    string Message_;
public:
    void setCallback(Callback fn, string Message)
    {
        wakeup_ = fn;
        Message_ = Message;
    }
    void set(int alarmTime)
    {
        lengthOfTimer = alarmTime;
    }
    void tick()
    {
        numberOfTicks++;
        if (numberOfTicks == lengthOfTimer)
        {
            wakeup_(Message_);
        }
    }
    void reset()
    {
        numberOfTicks = 0;
    }
};



void wakeup(string Message)
{
    cout << Message << "\n";
    
    exit(1);
}

int main() {
    
    Timer t;
    t.setCallback(wakeup, "ring, rings");
    t.set(10);
    while(true)
    {
        cout << ".";
        for(int i =0; i < 100000000; i++) {}
        t.tick();
    }
}
