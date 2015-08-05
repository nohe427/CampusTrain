//
//  main.cpp
//  Lesson9-1
//
//  Created by Alexander Nohe on 8/4/15.
//  Copyright (c) 2015 Alexander Nohe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

template<typename T, int N = 100>
class Bag
{
private:
    int m_size;
    int m_counts[N];
    T m_items[N];
public:
    void add(T item);
    int count(T item) const;
    int uniqueSize() const;
    int count() const;
    int item(int i, T& value) const;
};

template<typename T>
void replace(T& item, T& item2)
{
    T value = item;
    T value2 = item2;
    item = value2;
    item2 = value;
}

template<typename T, int N>
void Bag<T,N>::add(T item)
{
    for (int i = 0; i < m_size; i++)
    {
        if (m_items[i] == item)
        {
            m_counts[i]++;
            while (i != 0 && m_counts[i] > m_counts[i-1]) {
                replace(m_items[i], m_items[i-1]);
                replace(m_counts[i], m_counts[i-1]);
                i--;
            }
            return;
        }
    }
    m_items [m_size] = item;
    m_counts[m_size] = 1;
    
    m_size++;
}

template<typename T, int N>
int Bag<T,N>::count(T item) const
{
    for (int i = 0; i < m_size; i++)
    {
        if (m_items[i] == item)
        {
            return m_counts[i];
        }
    }
    return 0;
}

template<typename T, int N>
int Bag<T,N>::uniqueSize() const
{
    return m_size;
}

template<typename T, int N>
int  Bag<T, N>::count() const
{
    int n = 0;
    
    for (int i = 0; i < m_size; i++)
    {
        n += m_counts[i];
    }
    
    return n;
}

template<typename T, int N>
int Bag<T, N>::item(int i, T& value) const
{
    if (i >= m_size)
        return 0;
    
    value = m_items[i];
    return m_counts[i];
}

using namespace std;

int main() {
    Bag<int> lengths;
    Bag<char, 26> letters;
    Bag<string, 20000> words;
    
    ifstream is("/Users/alexandernohe/Documents/GitHub/CampusTrain/Lesson9-1/Lesson9-1/Tale.txt");
    
    if(!is)
    {
        cerr << "Cannot open Tale.txt!" << endl;
        return 1;
    }
    
    string s;
    while (is >> s)
    {
        string w;
        for (int i=0; i < s.length(); i++)
        {
            char ch = s[i];
            
            if (isalpha(ch))
            {
                w += toupper(ch);
                letters.add(toupper(ch));
            }
        }
        lengths.add(int(w.length()));
        words.add(w);
    }
    
    cout << "-- lengths --" << endl;
    cout << "1:" << lengths.count(1) << " 2:" << lengths.count(2) << " 3:" << lengths.count(3) << " 4:" << lengths.count(4) << " 5:" << lengths.count(5) << std::endl;
    std::cout << "-- letters --" << std::endl;
    cout << "A:" << letters.count('A') << " B:" << letters.count('B') << " C:" << letters.count('C') << endl;
    std::cout << words.uniqueSize() << " out of " << words.count() << " are unique " << (double((words.uniqueSize())/double(words.count()))*100) << "%" << endl;
    
    for (int i=0; i < words.count(); i++) {
        std::string w;
        int n = words.item(i, w);
        if(n != 0)
        {
            cout << n << ":" << w << "\n";
        }
    }
    is.close();
}
