TEST( utility, VectorTest)
{
	Vector2f v2(1.0f, 2.0f);
	Vector3f v3(3.0f, 4.0f, 5.0f);
	
	std::cout << "Here is the Vector3f v:\n" << v3 << std::endl;

	EXPECT_EQ( Vector3f(6.0f, 8.0f, 10.0f), v3 * 2.0f);
}

TEST( utility, Atelier_VectorAdd)
{
	ATELIER::UTILITY::Vector3f v1(1.0f, 2.0f, 3.0f);
	ATELIER::UTILITY::Vector3f v2(3.0f, 4.0f, 5.0f);
	unsigned int count = 10000000;
	    
	Timer t;
    t.start();
	for(unsigned int i = 0; i < count; ++i) {

		v1 = v1 + v2;
		//v1 += v2;
	}
	std::cout << "Atelier_VectorAdd: " << t.getElapsedTimeInMilliSec() <<"ms"<< std::endl;

	EXPECT_EQ( v1 + v2, Vector3f(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]));
}

TEST( utility, Eigen_VectorAdd)
{
	Eigen::Vector3f w1(1.0f, 2.0f, 3.0f);
	Eigen::Vector3f w2(3.0f, 4.0f, 5.0f);
	unsigned int count = 10000000;

	Timer t;
    t.start();
	for(unsigned int i = 0; i < count; ++i) {
		w1 = w1 + w2;
		//w1 += w2;
	}
	std::cout << "Eigen_VectorAdd:  " << t.getElapsedTimeInMilliSec() <<"ms"<< std::endl;

	EXPECT_EQ( w1 + w2, Vector3f(w1[0] + w2[0], w1[1] + w2[1], w1[2] + w2[2]));
}

/*
case1: v1 = v1 + v2;

[       OK ] utility.VectorTest (1 ms)
[ RUN      ] utility.Atelier_VectorAdd
Atelier_VectorAdd: 122.622ms
[       OK ] utility.Atelier_VectorAdd (124 ms)
[ RUN      ] utility.Eigen_VectorAdd
Eigen_VectorAdd:  34.8844ms
[       OK ] utility.Eigen_VectorAdd (37 ms)
[----------] 4 tests from utility (2167 ms total)

case2: v1 += v2;
[       OK ] utility.VectorTest (1 ms)
[ RUN      ] utility.Atelier_VectorAdd
Atelier_VectorAdd: 34.0362ms
[       OK ] utility.Atelier_VectorAdd (36 ms)
[ RUN      ] utility.Eigen_VectorAdd
Eigen_VectorAdd:  33.8063ms
[       OK ] utility.Eigen_VectorAdd (36 ms)
[----------] 4 tests from utility (2079 ms total)
*/