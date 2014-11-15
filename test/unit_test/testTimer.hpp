TEST( utility, Timer_01 )
{
#define ENABLE_LOG 0

    double start, stop, tick1, tick2;
	//
    //1. use std clock() function to measure elapsed time
	//
    start = stop = tick1 = tick2 = (double)clock(); // start timer and remember initial ticks

    while((stop-start)/CLOCKS_PER_SEC < 1)    // loop for 1 sec
    {
#if ENABLE_LOG
        std::cout << (tick2 - tick1) / CLOCKS_PER_SEC * 1000 << " ms." << std::endl;
#endif

        // reset timer
        tick1 = tick2;
        tick2 = stop = (double)clock();
    }

#if ENABLE_LOG
    // pause until user input
    std::cout << "\n\nPress Enter key to run Timer class...\n\n";
    char c;
    std::cin.get(c);
#endif

	//
	// 2. use Timer::getElapsedTime()
	//
    Timer t;

    // start timer
    t.start();
    tick1 = tick2 = t.getElapsedTimeInMilliSec();

    while(t.getElapsedTime() < 1)       // loop for 1 sec
    {
#if ENABLE_LOG
        std::cout << (tick2 - tick1) << " ms." << std::endl;
#endif

        tick1 = tick2;
        tick2 = t.getElapsedTimeInMilliSec();
    }

    std::cout << "Clock ticks macro - ANSI version -> CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << std::endl;
    std::cout << "Non-ANSI names for compatibility -> CLK_TCK: " << CLK_TCK << std::endl;
    std::cout << "clock()/CLOCKS_PER_SEC : "<<clock()/CLOCKS_PER_SEC << std::endl;

	EXPECT_EQ( true, true);
}
