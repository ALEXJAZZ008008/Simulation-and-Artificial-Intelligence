#include "vector3D.h"

Vector3D::Vector3D()
{
	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;
}

Vector3D::Vector3D(double n)
{
	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;

	m_x = n;
	m_y = n;
	m_z = n;
}

Vector3D::Vector3D(double x, double y, double z)
{
	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;

	m_x = x;
	m_y = y;
	m_z = z;
}

Vector3D::Vector3D(const Vector3D &vector3D)
{
	m_x = vector3D.GetX();
	m_y = vector3D.GetY();
	m_z = vector3D.GetZ();
}

Vector3D & Vector3D::operator = (const Vector3D &vector3D)
{
	m_x = vector3D.GetX();
	m_y = vector3D.GetY();
	m_z = vector3D.GetZ();

	return *this;
}

Vector3D::Vector3D(Vector3D &&vector3D)
{
	m_x = vector3D.GetX();
	m_y = vector3D.GetY();
	m_z = vector3D.GetZ();
}

Vector3D & Vector3D::operator = (Vector3D &&vector3D)
{
	m_x = vector3D.GetX();
	m_y = vector3D.GetY();
	m_z = vector3D.GetZ();

	return *this;
}

Vector3D::~Vector3D()
{

}

const Vector3D Vector3D::Add(const Vector3D &vector) const
{
	return Vector3D(m_x + vector.GetX(), m_y + vector.GetY(), m_z + vector.GetZ());
}

const Vector3D Vector3D::Subtract(const Vector3D &vector) const
{
	return Vector3D(m_x - vector.GetX(), m_y - vector.GetY(), m_z - vector.GetZ());
}

const Vector3D Vector3D::Multiply(const double n) const
{
	return Vector3D(m_x * n, m_y * n, m_z * n);
}

const Vector3D Vector3D::Divide(const double n) const
{
	return Vector3D(m_x / n, m_y / n, m_z / n);
}

const Vector3D Vector3D::operator += (const Vector3D &vector)
{
	m_x += vector.GetX();
	m_y += vector.GetY();
	m_z += vector.GetZ();

	return *this;
}

const Vector3D Vector3D::operator -= (const Vector3D &vector)
{
	m_x -= vector.GetX();
	m_y -= vector.GetY();
	m_z -= vector.GetZ();

	return *this;
}

const Vector3D Vector3D::operator *= (const Vector3D &vector)
{
	m_x *= vector.GetX();
	m_y *= vector.GetY();
	m_z *= vector.GetZ();

	return *this;
}

const Vector3D Vector3D::operator /= (const Vector3D &vector)
{
	m_x /= vector.GetX();
	m_y /= vector.GetY();
	m_z /= vector.GetZ();

	return *this;
}

const Vector3D Vector3D::CrossProduct(const Vector3D &vector) const
{
	return Vector3D((m_y * vector.GetZ()) - (vector.GetZ() * m_y), (m_x * vector.GetZ()) - (vector.GetZ() * m_x), (m_x * vector.GetY()) - (vector.GetY() * m_x));
}

const double Vector3D::DotProduct(const Vector3D &vector) const
{
	return (m_x * vector.GetX()) + (m_y * vector.GetY()) + (m_z * vector.GetZ());
}

const double Vector3D::Distance(const Vector3D &vector) const
{
	return static_cast<double>(sqrt(DistanceSquared(vector)));
}

const double Vector3D::DistanceSquared(const Vector3D &vector) const
{
	return Subtract(vector).LengthSquared();
}

const double Vector3D::Length() const
{
	return sqrt(LengthSquared());
}

const double Vector3D::LengthSquared() const
{
	return ((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

const Vector3D &Vector3D::Normalise() const
{
	return Normalise(*this);
}

const Vector3D &Vector3D::Normalise(const Vector3D &vector) const
{
	double length = vector.Length();

	if (fabs(length) > 1.0E-8) // guard against divide by zero
	{
		return *new Vector3D(vector.GetX() / length, vector.GetY() / length, vector.GetZ() / length);	// normalise and return
	}
	else
	{
		return *this;
	}
}

const bool Vector3D::IsZero(const double Tolerance) const
{
	return (LengthSquared() <= Tolerance * Tolerance);
}

const bool Vector3D::IsUnitVector(const double Tolerance) const
{
	return fabs(Length() - 1.0f) <= Tolerance;
}

const bool Vector3D::IsEqual(const Vector3D &vector, const double Tolerance) const
{
	return Subtract(vector).IsZero(Tolerance);
}

const bool Vector3D::operator == (const Vector3D &vector) const
{
	return IsEqual(vector);
}

const bool Vector3D::operator != (const Vector3D &vector) const
{
	return !(IsEqual(vector));
}

ostream &operator << (ostream &stream, const Vector3D &vector)
{
	stream << "(" << vector.GetX() << "," << vector.GetY() << "," << vector.GetZ() << ")" << endl;

	return stream;
}

istream &operator >> (istream &stream, Vector3D &vector)
{
	double X, Y, Z;

	stream >> X >> Y >> Z;

	vector.SetX(X);
	vector.SetY(Y);
	vector.SetZ(Z);

	return stream;
}

Vector3D operator - (const Vector3D &vector)
{
	return Vector3D(-(vector.GetX()), -(vector.GetY()), -(vector.GetZ()));
}

Vector3D operator * (const double &n, const Vector3D &vector)
{
	return vector.Multiply(n);
}