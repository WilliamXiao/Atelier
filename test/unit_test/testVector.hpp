TEST( utility, VectorTest)
{
	Vector2f v2(1.0f, 2.0f);
	Vector3f v3(3.0f, 4.0f, 5.0f);
	
	std::cout << "Here is the Vector3f v:\n" << v3 << std::endl;

	EXPECT_EQ( Vector3f(6.0f, 8.0f, 10.0f), v3 * 2.0f);
}

TEST( utility, VectorAdd)
{
	Vector3f v1(1.0f, 2.0f, 3.0f);
	Vector3f v2(3.0f, 4.0f, 5.0f);
	
	unsigned int count = 10000000;
#if 1
	for(unsigned int i = 0; i < count; ++i) {
		//1931 ms
		v1 += v2;
	}
#else
	for(unsigned int i = 0; i < count; ++i) {
		//5534 ms
		v1 = Vector3f(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
	}
#endif
	std::cout << "Here is the vector v:\n" << v1 << std::endl;

	EXPECT_EQ( v1 + v2, Vector3f(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]));
}