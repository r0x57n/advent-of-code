#include "day7.h"

#include <unordered_set>

vector<int> parseInput(string& input) {
    vector<int> nums;

    input.push_back(',');

    while (input.size()) {
        int delimPos = input.find(',');
        nums.push_back(stoi(input.substr(0, delimPos)));
        input.erase(0, delimPos + 1);
    }

    return nums;
}

template<typename T>
void Day7<T>::partA()
{
    vector<int> crabs = parseInput(this->input.at(0));

    std::unordered_set<int> checked;
    int lowestFuelCost = std::numeric_limits<int>::max();
    int lowestPosition = -1;

    for (uint i = 0; i < crabs.size(); ++i) {
        int fuelCost = 0;

        if (!checked.count(crabs.at(i))) {
            for (uint j = 0; j < crabs.size(); ++j) {
                fuelCost += std::abs(crabs.at(j) - crabs.at(i));
            }

            if (fuelCost < lowestFuelCost) {
                lowestFuelCost = fuelCost;
                lowestPosition = i;
            }

            checked.insert(crabs.at(i));
        }
    }

    printf("Fuel cost for moving all crabs to %i is: %i", lowestPosition, lowestFuelCost);
}

template<typename T>
void Day7<T>::partB()
{
    vector<int> crabs = parseInput(this->input.at(0));

    std::unordered_set<int> checked;
    long lowestFuelCost = std::numeric_limits<long>::max();
    int lowestPosition = -1;
    int arbitraryBigInt = 1000;

    /*
     * This isn't a very nice way to do this...
     * I realized that I didn't check all possible horizontal positions in partA.
     * It just happened to be that the position that costed the least fuel already
     * was inhabited by a crab. In partB, that wasn't the case, so instead we check
     * a arbitrarily large span (actually up until the largest pos wasn't the chosen
     * position for least fuel cost).
     */
    for (int pos = 0; pos < arbitraryBigInt; ++pos) {
        long fuelCost = 0;

        for (uint j = 0; j < crabs.size(); ++j) {
            long steps = std::abs(crabs.at(j) - pos);
            fuelCost += ((steps*(steps + 1)) / 2);
        }

        if (fuelCost < lowestFuelCost) {
            lowestFuelCost = fuelCost;
            lowestPosition = pos;
        }
    }

    printf("Fuel cost for moving all crabs to %i is: %lu", lowestPosition, lowestFuelCost);
}

template<typename T>
void Day7<T>::implementation()
{
    partB();
}

template class Day7<string>;
