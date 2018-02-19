#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <cmath>
#include <array>
#include "vector3D.h"

using namespace std;

#define _USE_MATH_DEFINES

class Hole
{
public:
	Hole();
	Hole(Vector3D, double);
	Hole(const Hole &);
	Hole & operator = (const Hole &);
	Hole(Hole &&);
	Hole & operator = (Hole &&);
	~Hole();

	const array<Vector3D *, 18> Hole::GetIndices() const
	{
		return m_Indices;
	}

	const Vector3D Hole::GetPosition() const
	{
		return m_Position;
	}

	const double Hole::GetRadius() const
	{
		return m_Radius;
	}

	void Hole::SetIndices(const array<Vector3D *, 18> &indices)
	{
		m_Indices = indices;
	}

	void Hole::SetPosition(const Vector3D &position)
	{
		m_Position = position;
	}

	void Hole::SetRadius(const double radius)
	{
		m_Radius = radius;
	}

	void Render() const;

private:
	array<Vector3D *, 18> m_Indices;
	Vector3D m_Position;
	double m_Radius;
};