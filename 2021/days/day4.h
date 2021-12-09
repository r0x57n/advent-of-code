#ifndef DAY4_H_
#define DAY4_H_

#include "AbstractDay.h"

template<typename T>
class Day4: public AbstractDay<T> {
public:
    using AbstractDay<T>::AbstractDay;
    void implementation();

private:
    void partA();
    void partB();
};

#endif // DAY4_H_
