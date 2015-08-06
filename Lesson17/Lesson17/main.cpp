//
//  main.cpp
//  Lesson17
//
//  Created by Alexander Nohe on 8/6/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>

using namespace std;

class Pet
{
private:
    string m_name;
public:
    virtual void move()
    {
        std::cout << "step" << std::endl;
    }
    
    virtual void speak(bool loud) = 0;
    Pet(string name)
    {
        m_name = name;
    }
    virtual string name()
    {
        return m_name;
    }
    virtual ~Pet()
    {
        cout << m_name << " has died\n";
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
    Bird(string name)
    :Pet(name)
    {
        
    }
    virtual ~Bird()
    {
        cout << "Bird died";
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
    Fish(string name)
    :Pet(name)
    {
        
    }
    ~Fish()
    {
        cout << "Fish drowned\n";
    }
    
};

class Snake : public Pet
{
public:
    int m_length;
    virtual void move()
    {
        std::cout << "slither" << std::endl;
    }
    
    virtual void speak(bool loud)
    {
        std::cout << "hiss"<< std::endl;
    }
    Snake(int length, string name)
    :Pet(name)
    {
        m_length = length;
    }
    ~Snake()
    {
        cout << "Snake ded\n";
    }
};

class Cat : public Pet
{
public:
    virtual void move()
    {
        cout << "strut\n";
    }
    
    virtual void speak(bool loud)
    {
        if(loud)
        {
            cout << "meow\n";
        }
        else
        {
            cout << "purr\n";
        }
    }
    Cat(string name)
    :Pet(name)
    {
        
    }
    virtual ~Cat()
    {
        cout << "Cat ate too much\n";
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

void chorus(Pet* pets[], int n, bool loud)
{
    for (int i = 0; i < n; i++)
    {
        pets[i]->speak(loud);
        
        cout << endl;
    }
}

int main() {
    
    const int NPETS = 4;
    Pet* pets[NPETS];
    
    pets[0] = new Fish("Nemo");
    pets[1] = new Bird("Tweety");
    pets[2] = new Snake(4, "Kaa");
    pets[3] = new Cat("Fluffy");
    
    for (int i=0; i<NPETS; i++)
    {
        cout << pets[i]->name() << " ";
    }
    
    cout << endl;
    
    chorus(pets, NPETS, false);
    chorus(pets, NPETS, true);
    chorus(pets, NPETS, false);
    chorus(pets, NPETS, true);
    chorus(pets, NPETS, true);
    
    for (int i=0; i < NPETS; i++)
    {
        delete pets[i];
    }
}
