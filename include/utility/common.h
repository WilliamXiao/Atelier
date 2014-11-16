/**
 * @common.h
 * @author  William Xiao 2005-2014. All rights reserved.
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Here defines variables or include basic headers needed by any Atelier file.
 */
 
#ifndef COMMON_H
#define COMMON_H

/// Global Definitions
#define ATELIER_BEGIN namespace ATELIER {
#define ATELIER_END }

#define ATELIER_UTILITY_BEGIN namespace ATELIER { namespace UTILITY {
#define ATELIER_UTILITY_END }}

#define EPSILON		 1e-4f
#define INV_PI       0.31830988618379067154f
#define INV_TWOPI    0.15915494309189533577f
#define INV_FOURPI   0.07957747154594766788f
#define SQRT_TWO     1.41421356237309504880f
#define INV_SQRT_TWO 0.70710678118654752440f

/// Basic Includes
#include <complex>      // std::complex, std::abs
#include <Eigen/Core>   // Matrix and Array classes, basic linear algebra , array manipulation
#include <Eigen/Geometry> //Transform, Translation, Scaling, Rotation2D and 3D rotations (Quaternion, AngleAxis)

ATELIER_UTILITY_BEGIN

/// Forward declarations
template <typename Scalar, int Dimension>  struct TVector;
template <typename Scalar, int Dimension>  struct TPoint;
template <typename Point, typename Vector> struct TRay;

/// Aliases of basic data structures such as vector, point, ray
typedef TVector<float, 1>       Vector1f;
typedef TVector<float, 2>       Vector2f;
typedef TVector<float, 3>       Vector3f;
typedef TVector<float, 4>       Vector4f;
typedef TVector<double, 1>      Vector1d;
typedef TVector<double, 2>      Vector2d;
typedef TVector<double, 3>      Vector3d;
typedef TVector<double, 4>      Vector4d;
typedef TVector<int, 1>         Vector1i;
typedef TVector<int, 2>         Vector2i;
typedef TVector<int, 3>         Vector3i;
typedef TVector<int, 4>         Vector4i;
typedef TPoint<float, 1>        Point1f;
typedef TPoint<float, 2>        Point2f;
typedef TPoint<float, 3>        Point3f;
typedef TPoint<float, 4>        Point4f;
typedef TPoint<double, 1>       Point1d;
typedef TPoint<double, 2>       Point2d;
typedef TPoint<double, 3>       Point3d;
typedef TPoint<double, 4>       Point4d;
typedef TPoint<int, 1>          Point1i;
typedef TPoint<int, 2>          Point2i;
typedef TPoint<int, 3>          Point3i;
typedef TPoint<int, 4>          Point4i;
typedef TRay<Point2f, Vector2f> Ray2f;
typedef TRay<Point3f, Vector3f> Ray3f;

ATELIER_UTILITY_END

#endif /* COMMON_H  */