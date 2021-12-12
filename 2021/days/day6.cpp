#include "day6.h"

#include <cstdlib>
#include <iostream>

void extractFishies(vector<std::string>& input, vector<int>& fishies) {
    for (char c : input[0]) {
        if (c != ',') {
            fishies.push_back(c - '0');
        }
    }
}

template<typename T>
void Day6<T>::partA()
{
    // as per usual, reformat the data
    vector<int> fishies;
    extractFishies(this->input, fishies);

    int newFishies = 0;

    for (int day = 0; day < 80; ++day) {
        for (int i = 0; i < fishies.size(); ++i) {
            if (fishies.at(i) == 0) {
                ++newFishies;
                fishies.at(i) = 6;
            } else {
                --fishies.at(i);
            }
        }

        for (int n = 0; n < newFishies; ++n) {
            fishies.push_back(8);
        }

        newFishies = 0;
    }

    printf("Fishies after 80 days: %i", fishies.size());
}

template<typename T>
void Day6<T>::partB()
{
    // as per usual, reformat the data
    vector<int> oldFishies;
    vector<long> newFishies (9, 0);
    extractFishies(this->input, oldFishies);

    // a better way of doing this, since part A method would take forever
    // store the amount of fishes with day 0-8 in position 0-8 in fishies

    for (uint i = 0; i < oldFishies.size(); ++i) {
        ++newFishies.at(oldFishies.at(i));
    }

    for (int day = 0; day < 256; ++day) {
        long newborns = newFishies.at(0);

        newFishies.at(0) = newFishies.at(1);
        newFishies.at(1) = newFishies.at(2);
        newFishies.at(2) = newFishies.at(3);
        newFishies.at(3) = newFishies.at(4);
        newFishies.at(4) = newFishies.at(5);
        newFishies.at(5) = newFishies.at(6);
        newFishies.at(6) = newFishies.at(7) + newborns;
        newFishies.at(7) = newFishies.at(8);
        newFishies.at(8) = newborns;
    }

    long allFishies = 0;
    for (long fishies : newFishies) {
        allFishies += fishies;
    }

    printf("Fishies after 256 days: %lu", allFishies);
}

template<typename T>
void Day6<T>::implementation()
{
    partB();
}

template class Day6<string>;
