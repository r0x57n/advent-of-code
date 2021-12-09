#ifndef DAY5_H_
#define DAY5_H_

#include "AbstractDay.h"

template<typename T>
class Day5: public AbstractDay<T> {
public:
    using AbstractDay<T>::AbstractDay;
    void implementation();

private:
    void partA();
    void partB();
};

#endif // DAY5_H_
