//
//  main.cpp
//  lab2-2
//
//  Created by Alexander Nohe on 8/3/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>



template<typename T>
void swap(T& x, T& y)
{
    T temporaryNumber;
    temporaryNumber = x;
    T temporaryNumber2 = y;
    x = temporaryNumber2;
    y = temporaryNumber;
}

void randomize(double& x)
{
    x = double(rand()) / RAND_MAX;
}

void randomize(char& x)
{
    x = 'A' + rand() % 26;
}

void randomize(std::string& x)
{
    char c;
    
    x = "";
    
    do
    {
        randomize(c);
        
        x += c;
    }
    while (rand() % 100 > 20);
}

void randomize(int& x)
{
    x = rand();
}

void randomize(char x[])
{
    int i = 0;
    
    do
    {
        randomize(x[i++]);
    }
    while (rand() % 100 > 20 && i < 9);
    
    x[i] = '\0';
}

template<typename T>
void randomize(T a[], int n)
{
    int i = 0;
    while (i < n) {
        randomize(a[i]);
        i++;
    }
}



template<typename T>
void print(const T a[], int n)
{
    int i = 0;
    while (i < n) {
        std::cout << a[i] << std::endl;
        i++;
    }
}


template<typename T>
T& maximum(T a[], int n)
{
    int m = 0;
    for (int i =1; i < n; i++) {
        if (a[m] < a[i])
        {
            m = i;
        }
    }
    return a[m];
}

template<typename T>
void sort(T a[], int n)
{
    while (n > 0) {
        swap(a[n-1], maximum(a, n));
        n--;
    }
}

template<typename T>
void test(T a[], int n)
{
    randomize(a, 5);
    print(a, 5);
    sort(a, 5);
    std::cout << std::endl;
    print(a, 5);
    std::cout << std::endl;
}

int main() {
//    int a[10];
//    randomize(a, 10);
//    print(a, 10);
//    for (int i = 0; i < 9; i++) {
//        if (a[i] > a[i+1]) {
//            swap(a[i], a[i+1]);
//        }
//    }
//    std::cout << std::endl;
//    print(a, 10);
//    swap(a[9], maximum(a, 10));
//    std::cout << std::endl;
//    print(a, 10);
//    sort(a, 10);
//    std::cout << std::endl;
//    print(a, 10);
    
    double a[5];
    test(a, 5);
    
    char b[5];
    test(b, 5);
    
    int c[5];
    test(c, 5);
    
    std::string d[5];
    test(d, 5);
    
    //char e[10][10];
    //test(e, 10);
}

