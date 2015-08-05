//
//  main.cpp
//  Lesson15-1
//
//  Created by Alexander Nohe on 8/5/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>

using namespace std;

class Item //used to test automatic destruction when an exception is hit
{
public:
    Item();
    ~Item();
};

Item::Item()
{
    cout << "I AM ALIVE!!!!\n";
}

Item::~Item()
{
    cout << "Well I had a good run...\n";
}


class Overflow
{
public:
    Overflow(int value, int max);
    
    int m_value;
    int m_max;
};

Overflow::Overflow(int value, int max)
{
    m_value = value;
    m_max = max;
}

enum Xcpt {
    NEGATIVE,
    ODD
};

void process(int i)
{
    Item item = Item();
    if (i ==0)
        throw "zero";
    if (i > 99)
        throw Overflow(i, 99);
    if (i < 0)
        throw NEGATIVE;
    if (i % 2)
        throw ODD;
    
    cout << "process " << i << endl;
}

void transform(int i)
{
    try
    {
        process(i);
    }
    catch(Xcpt xcpt)
    {
        switch (xcpt) {
            case NEGATIVE:
                cerr << "negative\n";
                break;
                
            case ODD:
                cerr << "odd\n";
                break;
        }
    }
    catch (Overflow& xcpt)
    {
        cout << "Max value " << xcpt.m_max << "\n";
        cout << "Value used " << xcpt.m_value << "\n";
    }
    catch(...)
    {
        cerr << "unknown exception\n";
    }
}

int main() {
    transform(-1);
    transform(4);
    transform(7);
    transform(100);
    transform(0);
    //process(7); //This should break the code....
}
