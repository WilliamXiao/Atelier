/**
 * @ Transform.h
 * @author  William Xiao 2005-2014. All rights reserved.
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * \brief Homogeneous coordinate transformation
 *
 * This class stores a general homogeneous coordinate transformation, such as
 * rotation, translation, uniform or non-uniform scaling, and perspective
 * transformations. The inverse of this transformation is also recorded
 * here, since it is required when transforming normal vectors.
 */

#ifndef ART_TRANSFORM_H
#define ART_TRANSFORM_H

#include <utility/common.h>
#include <utility/Ray.h>
#include <utility/math/Vector.h>

ATELIER_UTILITY_BEGIN

class Transform {
public:
	/// Create the identity transform
	Transform() : 
		m_transform(Eigen::Matrix4f::Identity()),
		m_inverse(Eigen::Matrix4f::Identity()) { }

	/// Create a new transform instance for the given matrix 
	Transform::Transform(const Eigen::Matrix4f &trafo) 
	: m_transform(trafo), m_inverse(trafo.inverse()) { }

	/// Create a new transform instance for the given matrix and its inverse
	Transform(const Eigen::Matrix4f &trafo, const Eigen::Matrix4f &inv) 
		: m_transform(trafo), m_inverse(inv) { }

	/// Return the underlying matrix
	inline const Eigen::Matrix4f &getMatrix() const {
		return m_transform;
	}

	/// Return the inverse of the underlying matrix
	inline const Eigen::Matrix4f &getInverseMatrix() const {
		return m_inverse;
	}

	/// Return the inverse transformation
	Transform inverse() const {
		return Transform(m_inverse, m_transform);
	}

	/// Concatenate with another transform
	Transform operator*(const Transform &t) const {
		return Transform(m_transform * t.getMatrix());
	};

	/// Apply the homogeneous transformation to a 3D vector
	inline Vector3f operator*(const Vector3f &v) const {
		return m_transform.topLeftCorner<3,3>() * v;
	}

	/// Apply the homogeneous transformation to a 3D normal
    inline Normal3f operator*(const Normal3f &n) const {
		return m_inverse.topLeftCorner<3, 3>().transpose() * n;
	}

	/// Transform a point by an arbitrary matrix in homogeneous coordinates
	inline Point3f operator*(const Point3f &p) const {
		Vector4f result = m_transform * Vector4f(p[0], p[1], p[2], 1.0f);
		//return result.head<3>(); // normalize or not?
		return result.head<3>() / result.w();
	}

	/// Apply the homogeneous transformation to a ray
	inline Ray3f operator*(const Ray3f &r) const {
		return Ray3f(
			operator*(r.o), 
			operator*(r.d), 
			r.mint, r.maxt
		);
	}

private:
	Eigen::Matrix4f m_transform;
	Eigen::Matrix4f m_inverse;
};

ATELIER_UTILITY_END

#endif /* ART_TRANSFORM_H */
