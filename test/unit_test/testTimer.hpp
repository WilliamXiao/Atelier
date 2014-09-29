TEST( utility, TimerPrint )
{
	Timer	test1;

	EXPECT_EQ( true, test1.print() );
}

TEST( utility, TimerAdd )
{
	Timer	test2;

    EXPECT_EQ( 2, test2.add(1, 1) );
}