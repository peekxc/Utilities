//
// Created by Matt Piekenbrock on 3/17/15.
// C++ Adaptation and extension of C# code found at URL
// {http://ycouriel.blogspot.com/2010/08/c-matrix-and-vector-representation.html}
//

#ifndef PICP_VECTOR3_H
#define PICP_VECTOR3_H

#include <string>
#include <math.h>
#include <tuple>
#include <sstream>
#include <cmath>
#include <Config.h>
#include <cpp/point_types.hpp>

typedef unsigned int uint;
class Vector3 : public PointXYZ
{

public:
    /* Constructors and Destructors */
    Vector3();
    Vector3(const pfloat num);
    Vector3(const pfloat* np);
    Vector3(const pfloat nx, const pfloat ny, const pfloat nz);
		Vector3(const PointXYZ& np);
    Vector3(const Vector3& nv);
		Vector3(std::tuple <pfloat, pfloat, pfloat> v);
    ~Vector3();

    /* Instance-level Scalar Operations */
    Vector3 operator*(pfloat scalar);
    Vector3 operator/(const pfloat scalar);
    Vector3 operator+(const pfloat scalar);
    Vector3 operator-(const pfloat scalar);

	/* Instance-level Boolean Operations */
    bool operator==(const Vector3& v);
    bool operator!=(const Vector3& v);

    /* Instance-level Indexing Operations */
    pfloat operator[](uint index) const;

    /* Instance-level Vector Functions */
    Vector3 operator*(const Vector3& vec2);
    Vector3 operator/(const Vector3& vec);
    Vector3 operator+(const Vector3& vec2);
    Vector3 operator-(const Vector3& vec);
    Vector3 cross(Vector3& vec);
    pfloat dot(const Vector3& vec);
    pfloat distanceTo(Vector3& v);

	/* Class-level pure functions */
    static Vector3 cross(const Vector3& v1, const Vector3& v2);
    static Vector3 normalize(const Vector3& v);
		static pfloat distanceTo(Vector3& v1, Vector3& v2);
    static pfloat dot(const Vector3& v1, const Vector3& v2);

	/* Misc function */
    Vector3* clone();
    std::string toString();
};

#endif //_PICP_VECTOR3_H_
