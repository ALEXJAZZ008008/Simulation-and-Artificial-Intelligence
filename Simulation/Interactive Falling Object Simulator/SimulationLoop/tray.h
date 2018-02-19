#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <array>
#include "hole.h"
#include "vector3D.h"

using namespace std;

class Tray
{
public:
	Tray();
	Tray(array<Vector3D, 4> indices, bool friction);
	Tray(array<Vector3D, 4> indices, bool friction, array<Vector3D, 9> holePositions, double holeRadius);
	Tray(const Tray &);
	Tray & operator = (const Tray &);
	Tray(Tray &&);
	Tray & operator = (Tray &&);
	~Tray();

	const array<Hole *, 9>Tray::GetHoles() const
	{
		return m_Holes;
	}

	const array<Vector3D, 4> Tray::GetNewIndices() const
	{
		return m_NewIndices;
	}

	const array<Vector3D, 4> Tray::GetIndices() const
	{
		return m_Indices;
	}

	const Vector3D Tray::GetVelocity() const
	{
		return m_Velocity;
	}

	const bool Tray::GetFrictionBool() const
	{
		return m_FrictionBool;
	}

	const bool Tray::GetHolesBool() const
	{
		return m_HolesBool;
	}

	const bool Tray::GetMovingBool() const
	{
		return m_MovingBool;
	}

	void Tray::SetHoles(const array<Hole *, 9> &holes)
	{
		m_Holes = holes;
	}

	void Tray::SetNewIndices(const array<Vector3D, 4> &newIndices)
	{
		m_NewIndices = newIndices;
	}

	void Tray::SetIndices(const array<Vector3D, 4> &indices)
	{
		m_Indices = indices;
	}

	void Tray::SetVelocity(const Vector3D &velocity)
	{
		m_Velocity = velocity;
	}

	void Tray::SetFrictionBool(const bool friction)
	{
		m_FrictionBool = friction;
	}

	void Tray::SetHolesBool(const bool holesBool)
	{
		m_HolesBool = holesBool;
	}

	void Tray::SetMovingBool(const bool movingBool)
	{
		m_MovingBool = movingBool;
	}

	void CalculateObjectPhysics(const double);
	void UpdateObjectPhysics();
	void Render() const;

private:
	array<Hole *, 9> m_Holes;
	array<Vector3D, 4> m_Indices, m_NewIndices;
	Vector3D m_Velocity;
	bool m_FrictionBool, m_HolesBool, m_MovingBool;
};