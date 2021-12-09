#include "day5.h"

#include <array>
#include <iostream>

/*
 * Makes the data more manageable.
 */
vector<std::array<int, 4>> getLines(vector<std::string>& input) {
    vector<std::string> unparsed = input;

    // we store the lines as lines[0][0] = first lines x1, lines[1][3] = second lines y2
    std::vector<std::array<int, 4>> lines;

    for (uint i = 0; i < unparsed.size(); ++i) {
        std::string current = unparsed.at(i);
        std::array<int, 4> line;

        line[0] = stoi(current.substr(0, current.find(",")));
        current.erase(0, current.find(",") + 1);
        line[1] = stoi(current.substr(0, current.find(" ->")));
        current.erase(0, current.find(" ->") + 4);
        line[2] = stoi(current.substr(0, current.find(",")));
        current.erase(0, current.find(",") + 1);
        line[3] = stoi(current.substr(0, current.find(" ->")));

        lines.push_back(line);
    }

    return lines;
}

template<typename T>
void Day5<T>::partA()
{
    // Parse the input
    vector<std::array<int, 4>> lines = getLines(this->input);

    // we store the map as map[x][y]
    std::vector<vector<short>> map(1000, std::vector<short>(1000, 0));

    // lets add the points to the map, while also checking for overlapping lines
    int overlaps = 0;
    for (auto line : lines) {
        int x1 = line[0];
        int y1 = line[1];
        int x2 = line[2];
        int y2 = line[3];

        if (x1 == x2) {
            int ymax = std::max(y1, y2);
            int ymin = std::min(y1, y2);

            for (int y = ymin; y <= ymax; ++y) {
                ++map.at(x1).at(y);

                if (map.at(x1).at(y) == 2) {
                    ++overlaps;
                }
            }
        } else if (y1 == y2) {
            int xmax = std::max(x1, x2);
            int xmin = std::min(x1, x2);

            for (int x = xmin; x <= xmax; ++x) {
                ++map.at(x).at(y1);

                if (map.at(x).at(y1) == 2) {
                    ++overlaps;
                }
            }
        }
    }

    printf("Amount of overlaps: %i", overlaps);
}

template<typename T>
void Day5<T>::partB()
{
    // Parse the input
    vector<std::array<int, 4>> lines = getLines(this->input);

    // we store the map as map[x][y]
    std::vector<vector<short>> map(1000, std::vector<short>(1000, 0));

    // lets add the points to the map, while also checking for overlapping lines
    int overlaps = 0;
    for (auto line : lines) {
        int x1 = line[0];
        int y1 = line[1];
        int x2 = line[2];
        int y2 = line[3];

        if (x1 == x2) { // vertical line
            int ymax = std::max(y1, y2);
            int ymin = std::min(y1, y2);

            for (int y = ymin; y <= ymax; ++y) {
                ++map.at(x1).at(y);

                if (map.at(x1).at(y) == 2)
                    ++overlaps;
            }
        } else if (y1 == y2) { // horizontal line
            int xmax = std::max(x1, x2);
            int xmin = std::min(x1, x2);

            for (int x = xmin; x <= xmax; ++x) {
                ++map.at(x).at(y1);

                if (map.at(x).at(y1) == 2)
                    ++overlaps;
            }
        } else { // diagonal line (?)
            /*
             * We find out which point is below the other, and also if it lies
             * ahead or not, and thus increment or decrement depending on.
             */

            int x = 0;
            int y = 0;
            int xx = 0;
            int yy = 0;
            int incy = 0;
            int incx = 0;

            /*
             * Yup! This needs cleanup.
             */

            // first point is below and before the second
            if (y1 < y2 && x1 < x2) {
                x = x1;
                y = y1;
                xx = x2;
                yy = y2;
                incx = 1;
                incy = 1;
            // first point is above and before the second
            } else if (y1 > y2 && x1 < x2){
                x = x1;
                y = y1;
                xx = x2;
                yy = y2;
                incx = 1;
                incy = -1;
            // first point is below and after the second
            } else if (y1 < y2 && x1 > x2) {
                x = x1;
                y = y1;
                xx = x2;
                yy = y2;
                incx = -1;
                incy = 1;
            // first point is above and after the second
            } else if (y1 > y2 && x1 > x2) {
                x = x1;
                y = y1;
                xx = x2;
                yy = y2;
                incx = -1;
                incy = -1;
            }

            while (true) {
                ++map.at(x).at(y);

                if (map.at(x).at(y) == 2)
                    ++overlaps;

                //printf("(%i, %i) -> (%i, %i)\n", x, y, xx, yy);
                if (x != xx) {
                    x += incx;
                    y += incy;
                } else {
                    break;
                }
            }
        }
    }

    printf("Amount of overlaps: %i", overlaps);
}

template<typename T>
void Day5<T>::implementation()
{
    partB();
}

template class Day5<string>;
