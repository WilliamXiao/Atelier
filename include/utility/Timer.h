#ifndef TIMER_H
#define TIMER_H

#include <utility/common.h>

ATELIER_UTILITY_BEGIN

class Timer {
public:
	Timer();
	~Timer();
    bool print();
    int add(int a, int b);
};
ATELIER_UTILITY_END

#endif