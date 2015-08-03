//
//  main.cpp
//  lab2-2
//
//  Created by Alexander Nohe on 8/3/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>

void randomize(int a[], int n);
void print(const int a[], int n);
void swap(int& x, int& y);
int& maximum(int a[], int n);
int greatestNumber;
void sort(int a[], int n);

int main() {
    int a[10];
    randomize(a, 10);
    print(a, 10);
    for (int i = 0; i < 9; i++) {
        if (a[i] > a[i+1]) {
            swap(a[i], a[i+1]);
        }
    }
    std::cout << std::endl;
    print(a, 10);
    swap(a[9], maximum(a, 10));
    std::cout << std::endl;
    print(a, 10);
    sort(a, 10);
    std::cout << std::endl;
    print(a, 10);
}

void swap(int& x, int& y)
{
    int temporaryNumber;
    temporaryNumber = x;
    int temporaryNumber2 = y;
    x = temporaryNumber2;
    y = temporaryNumber;
}

void randomize(int a[], int n)
{
    int i = 0;
    while (i < n) {
        a[i] = std::rand();
        i++;
    }
}

void print(const int a[], int n)
{
    int i = 0;
    while (i < n) {
        std::cout << a[i] << std::endl;
        i++;
    }
}

int& maximum(int a[], int n)
{
    greatestNumber = 0;
    for (int i =0; i < n; i++) {
        if (greatestNumber < a[i])
        {
            greatestNumber = a[i];
        }
    }
    return greatestNumber;
}

void sort(int a[], int n)
{
    while (n > -1) {
        swap(a[n-1], maximum(a, n));
        n--;
    }
}