#ifndef DAY2_H_
#define DAY2_H_

#include "AbstractDay.h"

template<typename T>
class Day2: public AbstractDay<T> {
public:
    using AbstractDay<T>::AbstractDay;
    void implementation();

private:
    void partA();
    void partB();
};

#endif // DAY2_H_
