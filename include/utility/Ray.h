/**
 * @ Ray.h
 * @author  William Xiao 2005-2014. All rights reserved.
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * \brief  Simple ray representation
 *
 */

#ifndef RAY_H
#define RAY_H

#include <utility/common.h>
#include <utility/math/Vector.h>

ATELIER_UTILITY_BEGIN

template <typename _PointType, typename _VectorType> struct TRay {
	typedef _PointType                  PointType;
	typedef _VectorType                 VectorType;
	typedef typename PointType::Scalar  Scalar;

	PointType o;     ///< Ray origin
	VectorType d;    ///< Ray direction
	Scalar mint;     ///< Minimum position on the ray segment
	Scalar maxt;     ///< Maximum position on the ray segment

	/// Construct a new ray
	inline TRay() : mint(Epsilon), 
		maxt(std::numeric_limits<Scalar>::infinity()) { }
	
	/// Construct a new ray
	inline TRay(const PointType &o, const VectorType &d) : o(o), d(d), 
			mint(EPSILON), maxt(std::numeric_limits<Scalar>::infinity()) { }

	/// Construct a new ray
	inline TRay(const PointType &o, const VectorType &d, 
		Scalar mint, Scalar maxt) : o(o), d(d), mint(mint), maxt(maxt) { }

	/// Copy constructor
	inline TRay(const TRay &ray) 
	 : o(ray.o), d(ray.d), dRcp(ray.dRcp),
	   mint(ray.mint), maxt(ray.maxt) { }

	/// Return the position of a point along the ray
	inline PointType operator() (Scalar t) const { return o + t * d; }
};

ATELIER_UTILITY_END

#endif /* RAY_H */