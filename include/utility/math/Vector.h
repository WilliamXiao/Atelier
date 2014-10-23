/**
 * @Vector.h
 * @author  William Xiao 2005-2014. All rights reserved.
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * \brief 2D / 3D Point, Vector and Normal data structure
 * TODO: Evaluate if it's necessary to distinct them in ART, even though they
 * transform differently under homogeneous coordinate transformations.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <utility/common.h>

ATELIER_UTILITY_BEGIN

/**
 * \brief Generic N-dimensional vector derived from Eigen::Matrix
 */
template <typename _Scalar, int _Dimension> struct TVector : public Eigen::Matrix<_Scalar, _Dimension, 1> {
public:
	enum {
		Dimension = _Dimension
	};

	typedef _Scalar                             Scalar;
	typedef Eigen::Matrix<Scalar, Dimension, 1> Base;
	typedef TVector<Scalar, Dimension>          VectorType;
	typedef TPoint<Scalar, Dimension>           PointType;

	/// Create a new vector with constant scalar value
	inline TVector(Scalar value = (Scalar) 0) { Base::setConstant(value); }

	/// Create a new 2D vector (type error if \c Dimension != 2, see Eigen constructor)
	inline TVector(Scalar x, Scalar y) : Base(x, y) { }

	/// Create a new 3D vector (type error if \c Dimension != 3)
	inline TVector(Scalar x, Scalar y, Scalar z) : Base(x, y, z) { }

	/// Create a new 4D vector (type error if \c Dimension != 4)
	inline TVector(Scalar x, Scalar y, Scalar z, Scalar w) : Base(x, y, z, w) { }

	/// Construct a vector from MatrixBase, to friendly play with Eigen
	template <typename Derived> inline TVector(const Eigen::MatrixBase<Derived>& p)
		: Base(p) { }

	/// Assign a vector from MatrixBase, to friendly play with Eigen
    template <typename Derived> TVector &operator=(const Eigen::MatrixBase<Derived>& p) {
		this->Base::operator=(p);
		return *this;
    }
};

/**
 * \brief Generic N-dimensional point data structure based on Eigen::Matrix
 */
template <typename _Scalar, int _Dimension> struct TPoint : public Eigen::Matrix<_Scalar, _Dimension, 1> {
public:
	enum {
		Dimension = _Dimension
	};

	typedef _Scalar                             Scalar;
	typedef Eigen::Matrix<Scalar, Dimension, 1> Base;
	typedef TVector<Scalar, Dimension>          VectorType;
	typedef TPoint<Scalar, Dimension>           PointType;

	/// Create a new point with constant scalar value
	inline TPoint(Scalar value = (Scalar) 0) { Base::setConstant(value); }

	/// Create a new 2D point (type error if \c Dimension != 2)
	inline TPoint(Scalar x, Scalar y) : Base(x, y) { }

	/// Create a new 3D point (type error if \c Dimension != 3)
	inline TPoint(Scalar x, Scalar y, Scalar z) : Base(x, y, z) { }

	/// Create a new 4D point (type error if \c Dimension != 4)
	inline TPoint(Scalar x, Scalar y, Scalar z, Scalar w) : Base(x, y, z, w) { }

	/// Construct a point from MatrixBase, to friendly play with Eigen
	template <typename Derived> inline TPoint(const Eigen::MatrixBase<Derived>& p)
		: Base(p) { }

	/// Assign a point from MatrixBase, to friendly play with Eigen
    template <typename Derived> TPoint &operator=(const Eigen::MatrixBase<Derived>& p) {
		this->Base::operator=(p);
		return *this;
    }
	
};

/**
 * \brief 3-dimensional surface normal representation
 */
struct Normal3f : public Eigen::Matrix<float, 3, 1> {
public:
	enum {
		Dimension = 3
	};

	typedef float                               Scalar;
	typedef Eigen::Matrix<Scalar, Dimension, 1> Base;
	typedef TVector<Scalar, Dimension>          VectorType;
	typedef TPoint<Scalar, Dimension>           PointType;


	/// Create a new normal with constant scalar value
	inline Normal3f(Scalar value = 0.0f) { Base::setConstant(value); }

	/// Create a new 3D normal
	inline Normal3f(Scalar x, Scalar y, Scalar z) : Base(x, y, z) { }

	/// Construct a normal from MatrixBase, to friendly play with Eigen
	template <typename Derived> inline Normal3f(const Eigen::MatrixBase<Derived>& p)
		: Base(p) { }

	/// Assign a normal from MatrixBase, to friendly play with Eigen
    template <typename Derived> Normal3f &operator=(const Eigen::MatrixBase<Derived>& p) {
		this->Base::operator=(p);
		return *this;
    }
};

/// Complete the set {a} to an orthonormal base
extern void coordinateSystem(const Vector3f &a, Vector3f &b, Vector3f &c);

ATELIER_UTILITY_END

#endif /* VECTOR_H */