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
	    
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		//v1 = v1 + v2;
		//v1 += v2;
		v1.noalias() = v1 + v2;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Atelier_VectorAdd: " << cost <<"ms"<< std::endl;
	
	EXPECT_EQ( v1 + v2, Vector3f(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]));
}

TEST( utility, Eigen_VectorAdd)
{
	Eigen::Vector3f w1(1.0f, 2.0f, 3.0f);
	Eigen::Vector3f w2(3.0f, 4.0f, 5.0f);

	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {
		//w1 = w1 + w2;
		w1 += w2;
		//w1.noalias() = w1 + w2;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Eigen_VectorAdd:  " << cost <<"ms"<< std::endl;

	EXPECT_EQ( w1 + w2, Vector3f(w1[0] + w2[0], w1[1] + w2[1], w1[2] + w2[2]));
}

TEST( utility, Atelier_VectorDot)
{
	ATELIER::UTILITY::Vector3f v1(1.0f, 2.0f, 3.0f);
	ATELIER::UTILITY::Vector3f v2(3.0f, 4.0f, 5.0f);
	float result = 0.0f;
	    
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		result = v1.dot(v2); // almost zero cost
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Atelier_VectorDot: " << cost <<"ms"<< std::endl;
	
	EXPECT_EQ( true, true);
}

TEST( utility, Atelier_VectorCross)
{
	// need #include <Eigen/Geometry> for cross operation
	ATELIER::UTILITY::Vector3f v1(1.0f, 2.0f, 3.0f);
	ATELIER::UTILITY::Vector3f v2(3.0f, 4.0f, 5.0f);
	ATELIER::UTILITY::Vector3f v3(6.0f, 7.0f, 8.0f);
	
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		// v1 = v1.cross(v2); // bad performance!
		v3 = v1.cross(v2);    // good ! almost zero cost as dot
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Atelier_VectorCross: " << cost <<"ms"<< std::endl;
	
	EXPECT_EQ( true, true);
}

/*
Conclusion:
1. To calculate " v1  = v1 + v2", 
   The best way is " v1 += v2" or "v1.noalias() = v1 + v2". Case 2 and Case 3 get similar performance.
2. "ATELIER::UTILITY::Vector3f" derived from "Eigen::Vector3f", the temporary construction cost in case 1 is huge.
3. To do DOT or CROSS operation, you must use explicit functions ie. v1.dot(v2), v1.cross(v2).
Reference:
http://eigen.tuxfamily.org/dox/TopicWritingEfficientProductExpression.html
http://eigen.tuxfamily.org/dox/group__QuickRefPage.html
http://stackoverflow.com/questions/10366054/c-performance-in-eigen-library
*/

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

optimizated:
[ RUN      ] utility.Atelier_VectorAdd
Atelier_VectorAdd: 132.448ms
[       OK ] utility.Atelier_VectorAdd (134 ms)
[ RUN      ] utility.Eigen_VectorAdd
Eigen_VectorAdd:  10.6463ms
[       OK ] utility.Eigen_VectorAdd (12 ms)
[----------] 4 tests from utility (2155 ms total)


case2: v1 += v2;
[ RUN      ] utility.Atelier_VectorAdd
Atelier_VectorAdd: 34.0362ms
[       OK ] utility.Atelier_VectorAdd (36 ms)
[ RUN      ] utility.Eigen_VectorAdd
Eigen_VectorAdd:  33.8063ms
[       OK ] utility.Eigen_VectorAdd (36 ms)
[----------] 4 tests from utility (2079 ms total)

optimized
[ RUN      ] utility.Atelier_VectorAdd
Atelier_VectorAdd: 10.0732ms
[       OK ] utility.Atelier_VectorAdd (11 ms)
[ RUN      ] utility.Eigen_VectorAdd
Eigen_VectorAdd:  10.8244ms
[       OK ] utility.Eigen_VectorAdd (12 ms)
[----------] 4 tests from utility (2031 ms total)

case 3. v1.noalias() = v1 + v2; 
optimized

[       OK ] utility.VectorTest (1 ms)
[ RUN      ] utility.Atelier_VectorAdd
Atelier_VectorAdd: 10.402ms
[       OK ] utility.Atelier_VectorAdd (12 ms)
[ RUN      ] utility.Eigen_VectorAdd
Eigen_VectorAdd:  10.7497ms
[       OK ] utility.Eigen_VectorAdd (12 ms)
[----------] 4 tests from utility (2031 ms total)
*/

