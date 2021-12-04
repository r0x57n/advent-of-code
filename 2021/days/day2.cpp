#include <iostream>

#include "day2.h"

enum command { up, down, forward, null };

command hash(string input)
{
    if (input == "up")
        return command::up;
    if (input == "down")
        return command::down;
    if (input == "forward")
        return command::forward;
    else
       return command::null;
}

template<typename T>
void Day2<T>::partA()
{
    int depth = 0;
    int h = 0;

    for (string line : this->input) {
        string command = line.substr(0, line.find(' '));
        int val = std::stoi(line.substr(line.find(' '), line.npos));

        switch(hash(command)) {
            case command::up:
                depth -= val;
                break;
            case command::down:
                depth += val;
                break;
            case command::forward:
                h += val;
                break;
            case command::null:
                std::cout << "bad input" << std::endl;
                break;
        }
    }

    std::printf("Final position: (%i, %i), multiplied: %i\n", h, depth, h * depth);
}

template<typename T>
void Day2<T>::partB()
{
    int depth = 0;
    int h = 0;
    int aim = 0;

    for (string line : this->input) {
        string command = line.substr(0, line.find(' '));
        int val = std::stoi(line.substr(line.find(' '), line.npos));

        switch(hash(command)) {
            case command::up:
                aim -= val;
                break;
            case command::down:
                aim += val;
                break;
            case command::forward:
                h += val;
                depth += val * aim;
                break;
            case command::null:
                std::cout << "bad input" << std::endl;
                break;
        }
    }

    std::printf("Final position: (%i, %i), multiplied: %i\n", h, depth, h * depth);
}

template<typename T>
void Day2<T>::implementation()
{
    partB();
}

template class Day2<string>;
