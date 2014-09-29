// Timer.cpp
#include <utility/Timer.h>
#include <stdio.h>

using namespace ART;
using namespace ART::utility;

Timer::Timer() {
	printf(" This is Timer construction. \n");
}

Timer::~Timer() {
	printf(" This is Timer de-construction. \n");
}

bool Timer::print() {

    printf(" This is Timer::print() \n");
    return true;
}

int Timer::add(int a, int b) {
    return a + b;
}