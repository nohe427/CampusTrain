//
//  main.cpp
//  Lesson21-1
//
//  Created by Alexander Nohe on 8/7/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>

using namespace std;


typedef double (*BinaryMathFunc)(double, double);

double accumulate(BinaryMathFunc fn, double a[], int n)
{
    double z = 0;
    for (int i = 0; i < n; i++) {
        z = fn(z, a[i]);
    }
    return z;
}

inline double add(double num1, double num2)
{
    return num1 + num2;
}

inline double mul(double num1, double num2)
{
    return num1*num2;
}

int main() {
    
    double d[] = {1,2,3,4,5};
    double sum = accumulate(add, d, 5);
    double product = accumulate(mul, d, 5);
}
