// Created by Matt Piekenbrock on 3/17/15.
// C++ Adaptation and extension of C# code found at URL
// {http://ycouriel.blogspot.com/2010/08/c-matrix-and-vector-representation.html}

#include <cpp/Vector3.h>

/* Constructors and Destructors */
Vector3::Vector3()
{ x = 0, y = 0, z = 0; }

Vector3::Vector3(const pfloat num)
{ x = num, y = num, z = num; }

Vector3::Vector3(const pfloat* np)
{ x = np[0], y = np[1], z = np[2]; }

Vector3::Vector3(const pfloat nx, const pfloat ny, const pfloat nz)
{ x = nx, y = ny, z = nz; }

Vector3::Vector3(const PointXYZ& np)
{ x = np.x, y = np.y, z = np.z;  }

Vector3::Vector3(const Vector3& nv)
{ x = nv.x, y = nv.y, z = nv.z; }

Vector3::Vector3(std::tuple <pfloat, pfloat, pfloat> v)
{ x = std::get <0>(v), y = std::get <1>(v), z = std::get <2>(v); }

Vector3::~Vector3()
{ x = 0, y = 0, z = 0; }

/* Instance-level Scalar Operations */
Vector3 Vector3::operator*(pfloat scalar)
{ return *new Vector3(x * scalar, y * scalar, z * scalar); }

Vector3 Vector3::operator/(const pfloat scalar)
{ return *new Vector3(x / scalar, y / scalar, z / scalar); }

Vector3 Vector3::operator+(const pfloat scalar)
{ return  Vector3(x + scalar, y + scalar, z + scalar); }

Vector3 Vector3::operator-(const pfloat scalar)
{ return Vector3(x - scalar, y - scalar, z - scalar); }

/* Instance-level Boolean Operations */
bool Vector3::operator==(const Vector3& v)
{ return (x == v.x && y == v.y && z == v.z); }

bool Vector3::operator!=(const Vector3& v)
{ return (x != v.x || y != v.y || z != v.z); }

/* Instance-level Indexing Operations */
pfloat Vector3::operator[](uint index) const
{ return data[index]; }

/* Instance-level Vector Functions */
Vector3 Vector3::operator*(const Vector3& vec2)
{ return Vector3(x * vec2.x, y * vec2.y, z * vec2.z); }

Vector3 Vector3::operator/(const Vector3& vec2)
{ return Vector3(x / vec2.x, y / vec2.y, z / vec2.z); }

Vector3 Vector3::operator+(const Vector3& vec2)
{ return Vector3(x + vec2.x, y + vec2.y, z + vec2.z); }

Vector3 Vector3::operator-(const Vector3& vec2)
{ return Vector3(x - vec2.x, y - vec2.y, z - vec2.z); }

pfloat Vector3::dot(const Vector3& vec)
{ return x * vec.x + y * vec.y + z * vec.z; }

Vector3 Vector3::cross(Vector3& v)
{ return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }


pfloat Vector3::distanceTo(Vector3& v)
{
	pfloat dx = x - v.x;
	pfloat dy = y - v.y;
	pfloat dz = z - v.z;
	return (pfloat) sqrt(dx * dx + dy * dy + dz * dz);
}

/* Class-level pure functions */
Vector3 Vector3::cross(const Vector3& v1, const Vector3& v2)
{ return Vector3((v1[1] * v2[2]) - (v1[2] * v2[1]), (v1[2] * v2[0]) - (v1[0] * v2[2]), (v1[0] * v2[1]) - (v1[1] * v2[0])); }

Vector3 Vector3::normalize(const Vector3& v1)
{
	pfloat mag = (pfloat) sqrt(dot(v1, v1));
	mag = (mag == 0) ? 1 : mag;
	return Vector3(v1[0] / mag, v1[1] / mag, v1[2] / mag);
}

pfloat Vector3::distanceTo(Vector3& v1, Vector3& v2)
{
	pfloat dx = v1.x - v2.x;
	pfloat dy = v1.y - v2.y;
	pfloat dz = v1.z - v2.z;
	return (pfloat) sqrt(dx * dx + dy * dy + dz * dz);
}

pfloat Vector3::dot(const Vector3& v1, const Vector3& v2)
{ return ((v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2])); }

/* Misc functions */
Vector3* Vector3::clone()
{ return new Vector3(this->x, this->y, this->z); }

std::string Vector3::toString()
{
	std::ostringstream ss;
	ss << x << " " << y << " " << z;
	return ss.str();
}

