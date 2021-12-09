#ifndef DAY3_H_
#define DAY3_H_

#include "AbstractDay.h"

template<typename T>
class Day3: public AbstractDay<T> {
public:
    using AbstractDay<T>::AbstractDay;
    void implementation();

private:
    void partA();
    void partB();
};

#endif // DAY3_H_
