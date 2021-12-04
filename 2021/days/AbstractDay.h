#ifndef DAY_H_
#define DAY_H_

#include <chrono>
#include <string>
#include <vector>

using std::string;
using std::vector;

template<typename T>
class AbstractDay {
    public:
        AbstractDay(string day);
        virtual void run();

    protected:
        virtual void implementation() = 0;
        vector<T> input;

    private:
        string day;
        void loadResources();
};

#endif // DAY_H_
