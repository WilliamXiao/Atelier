#ifndef ART_UTILITY_TIMER_H
#define ART_UTILITY_TIMER_H

namespace ART {
    namespace utility {

class Timer {
public:
	Timer();
	~Timer();
    bool print();
    int add(int a, int b);
};
} // namespace utility
} // namespace ART
#endif