#include <iostream>

#include "AbstractDay.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"

int main(int argc, char *argv[]) {
    Day5<string> today("day5");

    today.run();

    return 0;
}
