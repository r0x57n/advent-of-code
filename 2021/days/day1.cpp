#include <iostream>

#include "day1.h"

template<typename T>
void Day1<T>::partA()
{
    int increments = 0;

    for (unsigned int i = 1; i <= this->input.size(); ++i) {
        if (this->input[i - 1] < this->input[i])
            ++increments;
    }

    std::cout << "Increments: " << increments << std::endl;
}

template<typename T>
void Day1<T>::partB()
{
    int increments = 0;
    vector<int> subs;

    for (unsigned int i = 0; i + 2 <= this->input.size(); ++i) {
        subs.push_back(this->input[i] + this->input [i + 1] + this->input[i + 2]);
    }

    for (unsigned int i = 1; i <= subs.size(); ++i) {
        if (subs[i - 1] < subs[i])
            ++increments;
    }

    std::cout << "Increments: " << increments << std::endl;
}

template<typename T>
void Day1<T>::implementation()
{
    partB();
}

template class Day1<int>;
