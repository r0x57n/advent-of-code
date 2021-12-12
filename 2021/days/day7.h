#ifndef DAY7_H_
#define DAY7_H_

#include "AbstractDay.h"

template<typename T>
class Day7: public AbstractDay<T> {
public:
    using AbstractDay<T>::AbstractDay;
    void implementation();

private:
    void partA();
    void partB();
};

#endif // DAY7_H_
