#ifndef DAY1_H_
#define DAY1_H_

#include "AbstractDay.h"

template<typename T>
class Day1: public AbstractDay<T> {
public:
    using AbstractDay<T>::AbstractDay;
    void implementation();

private:
    void partA();
    void partB();
};

#endif // DAY1_H_
