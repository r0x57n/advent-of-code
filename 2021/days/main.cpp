#include <iostream>

#include "AbstractDay.h"
#include "day1.h"
#include "day2.h"

int main(int argc, char *argv[]) {
    Day2<string> today("day2");

    today.run();

    return 0;
}
