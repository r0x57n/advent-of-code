#ifndef DAY6_H_
#define DAY6_H_

#include "AbstractDay.h"

template<typename T>
class Day6: public AbstractDay<T> {
public:
    using AbstractDay<T>::AbstractDay;
    void implementation();

private:
    void partA();
    void partB();
};

#endif // DAY6_H_
