TEST( utility, Atelier_TransformXTransform)
{
	Eigen::Matrix4f m1;
	m1 << 1, 2, 3, 4,
	        5, 6, 7, 8,
		    9, 8, 5, 1,
		    0, 0, 0, 1;
	//std::cout << "Here is the Matrix4f m: \n" << m4x4 << std::endl;

	ATELIER::UTILITY::Transform trans1(m1);
	ATELIER::UTILITY::Transform trans2(Eigen::Matrix4f::Identity());
		
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		trans1  = trans1 * trans2;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Atelier_TransformXTransform: " << cost <<"ms"<< std::endl;
	std::cout << "Result: \n" << trans1.getMatrix() << std::endl;
	EXPECT_EQ( true, true);
}

TEST( utility, Eigen_TransformXTransform)
{
	Eigen::Matrix4f m1;
	m1 << 1, 2, 3, 4,
	        5, 6, 7, 8,
		    9, 8, 5, 1,
		    0, 0, 0, 1;
	Eigen::Affine3f trans1(m1);
	
	Eigen::Affine3f trans2(Eigen::Matrix4f::Identity());

	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		trans1  = trans1 * trans2;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Eigen_TransformXTransform: " << cost <<"ms"<< std::endl;

	Eigen::Matrix4f result = trans1.matrix();
	std::cout << "Result: \n" << result << std::endl;
	EXPECT_EQ( true, true);
}

// homogeneous transformation - Vector3f
TEST( utility, Atelier_TransformXVector3f)
{
	Eigen::Matrix4f m;
	m << 1, 2, 3, 0,
	     5, 6, 7, 0,
		 9, 8, 5, 0,
		 0, 0, 0, 1;
	ATELIER::UTILITY::Transform trans(m);

	ATELIER::UTILITY::Vector3f v(1.0f , 1.0f, 1.0f);
			
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		v  = trans * v;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Atelier_TransformXVector3f: " << cost <<"ms"<< std::endl;
	std::cout << "Result: \n" << v << std::endl;
	EXPECT_EQ( true, true);
}

TEST( utility, Eigen_TransformXVector3f)
{
	Eigen::Matrix4f m;
	m << 1, 2, 3, 0,
	      5, 6, 7, 0,
		  9, 8, 5, 0,
		  0, 0, 0, 1;
	Eigen::Affine3f trans(m);

	Eigen::Vector3f v(1.0f , 1.0f, 1.0f);
			
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		v  = trans * v;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Eigen_Affine3fXVector3f: " << cost <<"ms"<< std::endl;
	std::cout << "Result: \n" << v << std::endl;
	EXPECT_EQ( true, true);
}

// homogeneous transformation - Normal3f
TEST( utility, Atelier_TransformXNormal3f)
{
	Eigen::Matrix4f m;
	m << 1, 2, 3, 0,
	     5, 6, 7, 0,
		 9, 8, 5, 0,
		 0, 0, 0, 1;
	ATELIER::UTILITY::Transform trans(m);

	ATELIER::UTILITY::Normal3f n(1.0f , 1.0f, 1.0f);
			
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		n  = trans * n;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Atelier_TransformXNormal3f: " << cost <<"ms"<< std::endl;
	std::cout << "Result: \n" << n << std::endl;
	EXPECT_EQ( true, true);
}

// homogeneous transformation - Point3f
TEST( utility, Atelier_TransformXPoint3f)
{
	Eigen::Matrix4f m;
	m << 1, 2, 3, 2,
	      5, 6, 7, 2,
		  9, 8, 5, 2,
		  1, 2, 3, 4;
	ATELIER::UTILITY::Transform trans(m);

	ATELIER::UTILITY::Point3f p(1.0f , 1.0f, 1.0f);
			
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		p  = trans * p;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Atelier_TransformXPoint3f: " << cost <<"ms"<< std::endl;
	std::cout << "Result: \n" << p << std::endl;
	EXPECT_EQ( true, true);
}

// homogeneous transformation - Point3f
TEST( utility, Eigen_TransformXPoint3f)
{
	Eigen::Matrix4f m;
	m << 1, 2, 3, 2,
	      5, 6, 7, 2,
		  9, 8, 5, 2,
		  1, 2, 3, 4;
	Eigen::Affine3f trans(m);

	Eigen::Vector3f p(1.0f , 1.0f, 1.0f);
			
	Timer t;
    t.start();
	for(unsigned int i = 0; i < COUNT; ++i) {

		p  = trans * p;
	}
	double cost = t.getElapsedTimeInMilliSec();
	std::cout << "Eigen_Affine3fXPoint3f: " << cost <<"ms"<< std::endl;
	std::cout << "Result: \n" << p << std::endl;
	EXPECT_EQ( true, true);
}