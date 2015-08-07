//
//  main.cpp
//  Lesson21-4
//
//  Created by Alexander Nohe on 8/7/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>

using namespace std;

class IsWithinRange
{
private:
    char first_;
    char last_;
public:
    IsWithinRange(char first, char last)
    {
        first_ = first;
        last_ = last;
    }
    
    bool operator() (char c) const
    {
        if (c > first_ && c < last_) {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int count(const char* s, IsWithinRange test)
{
    int i = 0;
    string x = s;
    for (int j = 0; j < x.length(); j++) {
        if(test(s[j])) { i++; }
    }
    return i;
}

int main() {
    IsWithinRange test1('a', 'f');
    IsWithinRange test2('q','z');
    
    auto lam = [](char a1, char a2, char a3) {return (a3> a1 && a3 < a2);};
    
    while (true) {
        cout << "?";
        
        char ch;
        
        cin >> ch;
        
        if([](char a1, char a2, char a3) {return (a3> a1 && a3 < a2);}) cout << " in range1\n";
        if(lam('q','z',ch)) cout << " in range2\n";
    }
}
