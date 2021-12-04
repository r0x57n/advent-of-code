#include "AbstractDay.h"

#include <iostream>
#include <fstream>

template<typename T>
AbstractDay<T>::AbstractDay(string day)
{
    this->day = day;
    this->loadResources();
}

template<typename T>
void AbstractDay<T>::run()
{
    std::cout << "Running " << this->day << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    this->implementation();
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "\nFinished in: " << duration.count() << "ms" << std::endl;
}

template<>
void AbstractDay<int>::loadResources()
{
    int line;
    string filename = day + "input";
    std::ifstream input(filename);

    if (input.is_open()) {
        while (input >> line) {
            this->input.push_back(line);
        }
    }

    input.close();
}

template<>
void AbstractDay<string>::loadResources()
{
    string line;
    string filename = day + "input";
    std::ifstream input(filename);

    if (input.is_open()) {
        while (getline(input, line)) {
            this->input.push_back(line);
        }
    }

    input.close();
}

template class AbstractDay<int>;
template class AbstractDay<string>;
