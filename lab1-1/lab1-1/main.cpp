//
//  main.cpp
//  lab1-1
//
//  Created by Alexander Nohe on 8/3/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>
#include <iomanip>

int main()
{
    bool ws = false;
    std::cin >> std::resetiosflags(std::ios_base::skipws);
    
    std::cout << "Character? ";
    char ch;
    std::cin >> ch;
    int i = ch;
    /*
     Alternatively, we can use std::cout << int(ch) to
     print the integer value of the character
     */

    std::cout << "'" << ch << "' is " << i << std::endl;
    
    if (ch == '+')
    {
        std::cout << "PLUS";
    }
    else if (ch == '-')
    {
        std::cout << "minus";
    }
    
    if (ch == '(' || ch == ')') { std::cout << "Parenthesis";}
    
    if (ch >= 'A' && ch <= 'Z')
    {
        std::cout << "Upper Case";
    }
    
    if ((ch >= 'A' && ch <='Z') || (ch >= 'a' && ch <= 'z'))
    {
        std::cout << std::endl << "We have a letter here...";
        std::cout << "The letter before is " << char(ch-1);
    }
    else if (ch >= '0' && ch <= '9')
    {
        std::cout << std::endl << "Numerical character";
        std::cout << int(ch-'0');
    }
    else
    {
        std::cout << std::endl << "We have any other";
    }
    
    if (ch == '\n')
    {
        std::cout << std::endl << "New line entered" << std::endl;
        ws = true;
    }
    else if (ch == '\t')
    {
        std::cout << std::endl << "New tab entered" << std::endl;
        ws = true;
    }
    else if (ch == ' ')
    {
        std::cout << std::endl << "Blank space was entered" << std::endl;
        ws = true;
    }

    if(ws)
    {
        std::cout << "Whitespace entered";
    }
    
}