/*
 * This is a miserable mess, please look away...
 * ... (i'm way behind on the calendar, so this'll have to do) ...
 */

#include <iostream>

#include "day4.h"

template<typename T>
void Day4<T>::partA()
{
    /*
     * Fetch the numbers to use as input.
     */
    std::string unparsedNums = this->input[0];
    unparsedNums.append(","); // it's legal as long as the input is changed in-code ;)
    vector<int> numbers;

    while (!unparsedNums.empty()) {
        numbers.push_back(stoi(unparsedNums.substr(0, unparsedNums.find(","))));
        unparsedNums.erase(0, unparsedNums.find(",") + 1);
    }

    /*
     * Fetch all the boards for easier handling.
     */
    vector<int> row;
    vector<vector<int>> board;
    vector<vector<vector<int>>> boards;

    this->input.push_back("");

    for (uint i = 2; i < this->input.size(); ++i) {
        std::string current = this->input.at(i);

        if (current.empty()) {
            boards.push_back(board);
            board.clear();
        } else {
            current.push_back(' '); // as I said earlier

            while (!current.empty()) {
                std::string num = current.substr(0, current.find(" "));

                if (!num.empty()) {
                    row.push_back(stoi(num));
                }

                current.erase(0, current.find(" ") + 1);
            }

            board.push_back(row);
            row.clear();
        }
    }

    /*
     * Finally handle the boards to find a winner.
     */
    bool winner = false;
    vector<vector<int>> winningBoard;
    int winningBoardNum = 0;

    for (int n : numbers) {
        for (uint b = 0; b < boards.size(); ++b) {
            int points[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0}
            };

            for (uint r = 0; r < boards.at(b).size(); ++r) {
                for (uint c = 0; c < boards.at(b).at(r).size(); ++c) {
                    if (n == boards.at(b).at(r).at(c)) {
                        boards.at(b).at(r).at(c) = -1;
                    }

                    if (boards.at(b).at(r).at(c) == -1) {
                        points[r][c] = 1;
                    }
                }
            }

            /*
             * We check whether this board is a winning board or not
             */
            for (int i = 0; i < 5; ++i) {
                if (points[i][0] && points[i][1] && points[i][2] && points[i][3] && points[i][4])
                    winner = true;

                if (points[0][i] && points[1][i] && points[2][i] && points[3][i] && points[4][i])
                    winner = true;

                if (winner) {
                    winningBoardNum = n;
                    winningBoard = boards.at(b);
                    break;
                }
            }

            if (winner)
                break;
        }

        if (winner) // I know, I know
            break;
    }

    /*
     * Finish by calculating what was asked for in the challenge.
     */
    int sumOfUnmarked = 0;
    for (auto row : winningBoard) {
        for (uint i = 0; i < row.size(); ++i) {
            std::cout << row.at(i) << " ";
            if (row.at(i) != -1)
                sumOfUnmarked += row.at(i);
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    printf("Sum of unmarked: %i, Last number: %i, Multiplied: %i\n",
           sumOfUnmarked, winningBoardNum, sumOfUnmarked * winningBoardNum);
}

template<typename T>
void Day4<T>::partB()
{
    // Let's do some code repeating!

    /*
     * Fetch the numbers to use as input.
     */
    std::string unparsedNums = this->input[0];
    unparsedNums.append(",");
    vector<int> numbers;

    while (!unparsedNums.empty()) {
        numbers.push_back(stoi(unparsedNums.substr(0, unparsedNums.find(","))));
        unparsedNums.erase(0, unparsedNums.find(",") + 1);
    }

    /*
     * Fetch all the boards for easier handling.
     */
    vector<int> row;
    vector<vector<int>> board;
    vector<vector<vector<int>>> boards;

    this->input.push_back("");

    for (uint i = 2; i < this->input.size(); ++i) {
        std::string current = this->input.at(i);

        if (current.empty()) {
            boards.push_back(board);
            board.clear();
        } else {
            current.push_back(' ');

            while (!current.empty()) {
                std::string num = current.substr(0, current.find(" "));

                if (!num.empty()) {
                    row.push_back(stoi(num));
                }

                current.erase(0, current.find(" ") + 1);
            }

            board.push_back(row);
            row.clear();
        }
    }

    /*
     * Finally handle the boards to find the last winner.
     */
    bool restart = true;
    vector<vector<int>> lastBoard;
    int winningNum = 0;

    while (restart) { // how to solve a problem quickly, without thought! :)
        bool winner = false;

        for (uint n : numbers) {
            for (uint b = 0; b < boards.size(); ++b) {
                int points[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}
                };

                for (uint r = 0; r < boards.at(b).size(); ++r) {
                    for (uint c = 0; c < boards.at(b).at(r).size(); ++c) {
                        if (n == boards.at(b).at(r).at(c)) {
                            boards.at(b).at(r).at(c) = -1;
                        }

                        if (boards.at(b).at(r).at(c) == -1) {
                            points[r][c] = 1;
                        }
                    }
                }

                /*
                * We check whether this board is a winning board or not
                */
                for (int i = 0; i < 5; ++i) {
                    if (points[i][0] && points[i][1] && points[i][2] && points[i][3] && points[i][4])
                        winner = true;

                    if (points[0][i] && points[1][i] && points[2][i] && points[3][i] && points[4][i])
                        winner = true;
                }

                if (winner) {
                    if (boards.size() > 1) {
                        boards.erase(boards.begin() + b); // I love time complexity!
                    } else {
                        winningNum = n;
                        lastBoard = boards.at(b);
                        restart = false;
                    }
                }

                if (winner)
                    break;
            }

            if (winner)
                break;
        }
    }

    /*
     * Finish by calculating what was asked for in the challenge.
     */
    int sumOfUnmarked = 0;
    for (auto row : lastBoard) {
        for (uint i = 0; i < row.size(); ++i) {
            std::cout << row.at(i) << " ";
            if (row.at(i) != -1)
                sumOfUnmarked += row.at(i);
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    printf("Sum of unmarked: %i, Last number: %i, Multiplied: %i\n",
           sumOfUnmarked, winningNum, sumOfUnmarked * winningNum);
}

template<typename T>
void Day4<T>::implementation()
{
    partB();
}

template class Day4<string>;
