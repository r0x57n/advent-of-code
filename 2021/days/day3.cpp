#include <iostream>

#include "day3.h"

template<typename T>
void Day3<T>::partA()
{
    // counts[0][0], count of zeros at position 0
    // counts[0][1], count of ones at position 0
    int counts[12][2];

    for (int i = 0; i < 12; ++i) {
        counts[i][0] = 0;
        counts[i][1] = 0;
    }

    for (string line : this->input) {
        for(unsigned int i = 0; i < line.size(); ++i) {
            if (line.at(i) == '1')
                ++counts[i][1];
            else
                ++counts[i][0];
        }
    }

    string gamma;
    string epsilon;

    for (auto val : counts) {
        if (val[1] > val[0]) {
            gamma.push_back('0');
            epsilon.push_back('1');
        } else {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
    }

    int gammaI = stoi(gamma, nullptr, 2);
    int epsilonI = stoi(epsilon, nullptr, 2);

    printf("Gamma: %i, Epsilon: %i, Power consumption: %i", gammaI, epsilonI, gammaI * epsilonI);
}

template<typename T>
void Day3<T>::partB()
{
    vector<string> allLines = this->input;

    vector<string> zeroLines;
    vector<string> oneLines;

    for(unsigned int c = 0; c < 12; ++c) {
        for (string line : allLines) {
            if (line.at(c) == '0') {
                zeroLines.push_back(line);
            } else {
                oneLines.push_back(line);
            }
        }

        if (oneLines.size() >= zeroLines.size()) {
            allLines = oneLines;
        } else {
            allLines = zeroLines;
        }

        oneLines.clear();
        zeroLines.clear();

        if (allLines.size() == 1) {
            break;
        }
    }

    int oxygen = stoi(allLines[0], nullptr, 2);

    allLines = this->input;

    zeroLines.clear();
    oneLines.clear();

    for(unsigned int c = 0; c < 12; ++c) {
        for (string line : allLines) {
            if (line.at(c) == '0') {
                zeroLines.push_back(line);
            } else {
                oneLines.push_back(line);
            }
        }

        if (oneLines.size() < zeroLines.size()) {
            allLines = oneLines;
        } else {
            allLines = zeroLines;
        }

        oneLines.clear();
        zeroLines.clear();

        if (allLines.size() == 1) {
            break;
        }
    }

    int co2 = stoi(allLines[0], nullptr, 2);

    printf("Oxygen: %i, CO2: %i, Life support rating: %i", oxygen, co2, oxygen * co2);
}

template<typename T>
void Day3<T>::implementation()
{
    partB();
}

template class Day3<string>;
