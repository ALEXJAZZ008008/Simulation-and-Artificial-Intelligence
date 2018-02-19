#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <iostream>
#include <cmath>

using namespace std;

/**
* Double precision, 3D vector class.
*/

class Vector3D
{
public:
	/**
	* Default constructor. Initialises vector to zero.
	*/
	Vector3D();

	/**
	* Construct from double. Assigns double value to all elements of vector.
	*/
	Vector3D(double);

	/**
	* Construct from three doubles. Assigns the three parameters to the
	* X,Y,Z elements of the vector.
	*/
	Vector3D(double, double, double);

	Vector3D(const Vector3D &);
	Vector3D & operator = (const Vector3D &);
	Vector3D(Vector3D &&);
	Vector3D & operator = (Vector3D &&);
	~Vector3D();

	const double Vector3D::GetX() const
	{
		return m_x;
	}

	const double Vector3D::GetY() const
	{
		return m_y;
	}

	const double Vector3D::GetZ() const
	{
		return m_z;
	}

	void Vector3D::SetX(double x)
	{
		m_x = x;
	}

	void Vector3D::SetY(double y)
	{
		m_y = y;
	}

	void Vector3D::SetZ(double z)
	{
		m_z = z;
	}

	/**
	* Vector addition. The code A = L.Add(R) is equivalent to A=L+R
	*/
	const Vector3D Add(const Vector3D &) const;

	/**
	* Vector subtraction. The code A = L.Subtract(R) is equivalent to A=L-R
	*/
	const Vector3D Subtract(const Vector3D &) const;
	const Vector3D Multiply(const double) const;
	const Vector3D Divide(const double) const;
	const Vector3D CrossProduct(const Vector3D &) const;
	const double DotProduct(const Vector3D &) const;
	const Vector3D operator + (const Vector3D &vector) const
	{
		return Add(vector);
	}
	const Vector3D operator += (const Vector3D &);
	const Vector3D operator - (const Vector3D &vector) const
	{
		return Subtract(vector);
	}
	const Vector3D operator -= (const Vector3D &);
	const Vector3D operator * (const double &n) const
	{
		return Multiply(n);
	}
	const Vector3D operator *= (const Vector3D &);
	const Vector3D operator / (const double &n) const
	{
		return Divide(n);
	}
	const Vector3D operator /= (const Vector3D &);
	const Vector3D operator ^ (const Vector3D &vector) const
	{
		return CrossProduct(vector);
	}
	const double operator * (const Vector3D &vector) const
	{
		return DotProduct(vector);
	}

	/**
	* Distance between two vectors.
	*/
	const double Distance(const Vector3D &) const;

	/**
	* Squared distance between two vectors. When comparing distances, it is
	* generally faster to compare the squared distance to avoid the square
	* root calculation.
	*/
	const double DistanceSquared(const Vector3D &) const;

	/**
	* Length of vector. This returns the length (magnitude) of the vector.
	*/
	const double Length() const;

	/**
	* Squared length of vector. This returns the squared length of the
	* vector (squared magnitude). When comparing length, it is generally
	* faster to compare the squared length to avoid the square root
	* calculation.
	*/
	const double LengthSquared() const;

	/**
	* Normalise a vector in place. If the vector is zero magnitude, then
	* the result is a zero vector.
	*/
	const Vector3D &Normalise() const;

	/**
	* Normalise a vector. The operation L.Normalise(R) replaces L with
	* the normalised (unit length) version of R. It is equivalent to
	* L=R.Normalise() but with less overhead, since a temporary object
	* is not returned.
	*/
	const Vector3D &Normalise(const Vector3D &) const;

	/**
	* Vector is near zero. Returns true if a vector is very close to zero.
	* The default tolerance can be overidden.
	*/
	const bool IsZero(const double Tolerance = 1.0E-8) const;

	/**
	* Vector is near unit-length. Returns true if vector is very close to
	* unit length. The default tolerance can be overidden.
	*/
	const bool IsUnitVector(const double Tolerance = 1.0E-8) const;

	/**
	* Vector this is near equal to V. Returns true if vector this and V are very close to equal.
	* The default tolerance can be overidden.
	*/
	const bool IsEqual(const Vector3D &, const double Tolerance = 1.0E-8) const;

	/**
	* Exact equality. Returns true if both vectors are exactly equal. It is
	* not good practice to use this operator. Use IsEqual() instead.
	*/
	const bool operator == (const Vector3D &) const;

	/**
	* Inequality operator. Returns true if the vectors are not exactly equal.
	* It is not good practice to use this operator. Use !IsEqual() instead.
	*/
	const bool operator != (const Vector3D &) const;

private:
	double m_x, m_y, m_z;
};

ostream &operator << (ostream &, const Vector3D &);
istream &operator >> (istream &, const Vector3D &);
Vector3D operator - (const Vector3D &);
Vector3D operator * (const double &n, const Vector3D &);