#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <cmath>
#include <array>
#include "vector3D.h"

using namespace std;

#define _USE_MATH_DEFINES

class Bowl
{
public:
	Bowl();
	Bowl(Vector3D, double);
	Bowl(const Bowl &);
	Bowl & operator = (const Bowl &);
	Bowl(Bowl &&);
	Bowl & operator = (Bowl &&);
	~Bowl();

	const array<array<Vector3D *, 72>, 41> Bowl::GetIndices() const
	{
		return m_Indices;
	}

	const Vector3D Bowl::GetPosition() const
	{
		return m_Position;
	}

	const double Bowl::GetRadius() const
	{
		return m_Radius;
	}

	void Bowl::SetIndices(const array<array<Vector3D *, 72>, 41> &indices)
	{
		m_Indices = indices;
	}

	void Bowl::SetPosition(const Vector3D &position)
	{
		m_Position = position;
	}

	void Bowl::SetRadius(double bowlRadius)
	{
		m_Radius = bowlRadius;
	}

	void CalculateObjectPhysics(const double);
	void UpdateObjectPhysics();
	void Render() const;

private:
	array<array<Vector3D *, 72>, 41> m_Indices;
	Vector3D m_Position;
	double m_Radius;
};