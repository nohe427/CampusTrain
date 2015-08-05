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

template<typename T>
class Bag
{
private:
    int m_size;
    int m_capacity;
    int* m_counts;
    T* m_items;
    
    void copy(const Bag<T>& b);
public:
    Bag(int capacity = 5);
    Bag(const Bag<T>& b);
    ~Bag();
    void add(T item);
    int count(T item) const;
    int uniqueSize() const;
    int count() const;
    int item(int i, T& value) const;
    Bag<T>& operator=(const Bag<T>& b);
};

template<typename T>
Bag<T>::Bag(int capactiy)
{
    m_capacity = capactiy;
    m_size = 0;
    m_counts = new int[capactiy];
    m_items = new T[capactiy];
    
}

template<typename T>
void Bag<T>::copy(const Bag<T>& b)
{
    m_size = b.m_size;
    m_capacity = b.m_capacity;
    
    m_counts = new int[m_capacity];
    m_items = new T[m_capacity];
    
    for (int i = 0; i < m_size; i++) {
        m_counts[i] = b.m_counts[i];
        m_items[i] = b.m_items[i];
    }
}

template<typename T>
Bag<T>::~Bag<T>()
{
    delete [] m_counts;
    delete [] m_items;
}

template<typename T>
Bag<T>& Bag<T>::operator=(const Bag<T>& b)
{
    if(this == &b) {return *this;}
    
    delete [] m_counts;
    delete [] m_items;
    
    copy(b);
    
    return *this;
    
}

template<typename T>
Bag<T>::Bag(const Bag<T>& b)
{
    copy(b);
}

template<typename T>
void replace(T& item, T& item2)
{
    T value = item;
    T value2 = item2;
    item = value2;
    item2 = value;
}

template<typename T>
void Bag<T>::add(T item)
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
    
    if (m_size == m_capacity)
    {
        m_capacity *= 2;
        
        int* newcounts = new int[m_capacity];
        T* newitems = new T[m_capacity];
        
        for (int i = 0; i < m_size; i++) {
            newcounts[i] = m_counts[i];
            newitems[i] = m_items[i];
        }
        m_counts = newcounts;
        m_items = newitems;
    }
    
    m_items [m_size] = item;
    m_counts[m_size] = 1;
    
    m_size++;
}

template<typename T>
int Bag<T>::count(T item) const
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

template<typename T>
int Bag<T>::uniqueSize() const
{
    return m_size;
}

template<typename T>
int  Bag<T>::count() const
{
    int n = 0;
    
    for (int i = 0; i < m_size; i++)
    {
        n += m_counts[i];
    }
    
    return n;
}

template<typename T>
int Bag<T>::item(int i, T& value) const
{
    if (i >= m_size)
        return 0;
    
    value = m_items[i];
    return m_counts[i];
}

using namespace std;

int main() {
    Bag<int> lengths;
    Bag<char> letters;
    Bag<string> words;
    
    ifstream is("/Users/alexandernohe/Downloads/labs_icpp/Exercises/Skeletons/Tale.txt");
    
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
