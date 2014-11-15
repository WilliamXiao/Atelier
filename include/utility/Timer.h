/**
 * @ Timer.h
 * @author  William Xiao 2005-2014. All rights reserved.
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * \brief Single thread sample timer to measure performance
 * 1s=1000ms 
 * 1ms=1000us 
 * 1us=1000ns 
 * 1ns=1000ps
 */
#ifndef TIMER_H
#define TIMER_H
#include <utility\common.h>

ATELIER_UTILITY_BEGIN

// Move to single platform.h in the future
#ifdef _MSC_VER   // Windows system specific header
#include <windows.h>
#else          // Unix system specific header
#include <sys/time.h>
#endif

class Timer
{
public:
    Timer(); 
    ~Timer();

    void   start();                             // start timer
    void   stop();                              // stop the timer
    double getElapsedTime();                    // get elapsed time in second (s)
    double getElapsedTimeInSec();               // get elapsed time in second (s)(same as getElapsedTime)
    double getElapsedTimeInMilliSec();          // get elapsed time in millisecond (ms)
    double getElapsedTimeInMicroSec();          // get elapsed time in microsecond (us)

private:
    double startTimeInMicroSec;                 // starting time in microsecond
    double endTimeInMicroSec;                   // ending time in microsecond
    int    stopped;                             // stop flag 
#ifdef WIN32
    LARGE_INTEGER frequency;                    // ticks per second
    LARGE_INTEGER startCount;
    LARGE_INTEGER endCount;
#else
    timeval startCount;   
    timeval endCount;                      
#endif
};

ATELIER_UTILITY_END

#endif