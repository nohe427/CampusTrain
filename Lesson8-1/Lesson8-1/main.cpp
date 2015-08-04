//
//  main.cpp
//  Lesson8-1
//
//  Created by Alexander Nohe on 8/4/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>

class Pet
{
public:
    virtual void move()
    {
        std::cout << "step" << std::endl;
    }
    
    virtual void speak(bool loud)
    {
    }
    
};

class Bird : public Pet
{
public:
    virtual void move()
    {
        std::cout << "flap" << std::endl;
    }
    
    virtual void speak(bool loud)
    {
        if (loud)
        {
            std::cout << "squawk"<< std::endl;
        }
        else
        {
            std::cout << "chirp"<< std::endl;
        }
    }
};

class Fish : public Pet
{
public:
    virtual void move()
    {
        std::cout << "swim" << std::endl;
    }
    
    virtual void speak(bool loud)
    {
        std::cout << "gurgle"<< std::endl;
    }
    
};

class Snake : public Pet
{
    virtual void move()
    {
        std::cout << "slither" << std::endl;
    }
    
    virtual void speak(bool loud)
    {
        std::cout << "hiss"<< std::endl;
    }
};

void exercise(Pet& a, int n)
{
    for (int i=0;i<n;i++)
    {
        a.move();
    }
}

void dance(Pet& a)
{
    a.speak(false);
    
    a.move();
    a.move();
    
    a.speak(true);
    
    a.move();
    
    a.speak(false);
    a.speak(false);
    
    std::cout << std::endl;
}

int main() {
    Bird b;
    Fish f;
    Snake s;
    
    exercise(b, 3);
    exercise(f, 5);
    exercise(s, 2);
    
    dance(s);
    dance(b);
    dance(f);
}
