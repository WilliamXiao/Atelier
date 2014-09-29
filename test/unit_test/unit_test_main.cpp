// main.cpp

#include <stdio.h>
#include <gmock/gmock.h>
#include "testAll.hpp"

int main( int argc, char** argv )
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}