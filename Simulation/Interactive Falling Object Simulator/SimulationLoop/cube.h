#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <cmath>
#include <chrono>
#include <random>
#include <functional>
#include <array>
#include "ball.h"
#include "ballCubeContactManifold.h"
#include "bowl.h"
#include "box.h"
#include "cubeContactManifold.h"
#include "textureLoader.h"
#include "tray.h"
#include "vector3D.h"

using namespace std;

#define _USE_MATH_DEFINES

class Ball;
class BallCubeContactManifold;
class CubeContactManifold;

class Cube
{
public:
	Cube();
	Cube(bool &, double &, double &, bool &);
	Cube(const Cube &);
	Cube & operator = (const Cube &);
	Cube(Cube &&);
	Cube & operator = (Cube &&);
	~Cube();

	const array<Vector3D *, 8> Cube::GetIndices() const
	{
		return m_Indices;
	}

	const Vector3D Cube::GetPosition() const
	{
		return m_Position;
	}

	const Vector3D Cube::GetNewPosition() const
	{
		return m_NewPosition;
	}

	const Vector3D Cube::GetPreviousPosition() const
	{
		return m_PreviousPosition;
	}

	const Vector3D Cube::GetVelocity() const
	{
		return m_Velocity;
	}

	const Vector3D Cube::GetNewVelocity() const
	{
		return m_NewVelocity;
	}

	const Vector3D Cube::GetAcceleration() const
	{
		return m_Acceleration;
	}

	const Vector3D Cube::GetRotation() const
	{
		return m_Rotation;
	}

	const Vector3D Cube::GetColour() const
	{
		return m_Colour;
	}

	bool * Cube::GetIntegrationBool() const
	{
		return m_IntegrationBool;
	}

	bool * Cube::GetFallBool() const
	{
		return m_FallBool;
	}

	const bool Cube::GetCheckBool() const
	{
		return m_FallBool;
	}

	double * Cube::GetFriction() const
	{
		return m_Friction;
	}

	double * Cube::GetElasticity() const
	{
		return m_Elasticity;
	}

	const double Cube::GetRadius() const
	{
		return m_Radius;
	}

	const double Cube::GetMass() const
	{
		return m_Mass;
	}

	void Cube::SetIndices(const array<Vector3D *, 8> &indices)
	{
		m_Indices = indices;
	}

	void Cube::SetPosition(const Vector3D &position)
	{
		m_Position = position;
	}

	void Cube::SetNewPosition(const Vector3D &newPosition)
	{
		m_NewPosition = newPosition;
	}

	void Cube::SetPreviousPosition(const Vector3D &previousPosition)
	{
		m_PreviousPosition = previousPosition;
	}

	void Cube::SetVelocity(const Vector3D &velocity)
	{
		m_Velocity = velocity;
	}

	void Cube::SetNewVelocity(const Vector3D &newVelocity)
	{
		m_NewVelocity = newVelocity;
	}

	void Cube::SetAcceleration(const Vector3D &acceleration)
	{
		m_Acceleration = acceleration;
	}

	void Cube::SetRotation(const Vector3D &rotation)
	{
		m_Rotation = rotation;
	}

	void Cube::SetColour(const Vector3D &colour)
	{
		m_Colour = colour;
	}

	void Cube::SetIntegrationBool(bool *integrationBool)
	{
		m_IntegrationBool = integrationBool;
	}

	void Cube::SetFallBool(bool *fallBool)
	{
		m_FallBool = fallBool;
	}

	void Cube::SetCheckBool(const bool checkBool)
	{
		m_CheckBool = checkBool;
	}

	void Cube::SetFriction(double *friction)
	{
		m_Friction = friction;
	}

	void Cube::SetElasticity(double *elasticity)
	{
		m_Elasticity = elasticity;
	}

	void Cube::SetRadius(const double radius)
	{
		m_Radius = radius;
	}

	void Cube::SetMass(const double mass)
	{
		m_Mass = mass;
	}

	const Vector3D Integration(const Vector3D &, const Vector3D &, const double);
	void CalculateObjectPhysics(double);
	void DynamicCollisionDetection(Cube *, vector<CubeContactManifold *> &);
	void DynamicCollisionDetection(Ball *, vector<BallCubeContactManifold *> &);
	void ApplyFriction(const Vector3D &);
	void ApplyFriction(const Vector3D &, const Vector3D &, const double );
	void ApplyElasticity(const Vector3D &);
	void DynamicCollisionResponse(const CubeContactManifold &, const double );
	void DynamicCollisionResponse(const BallCubeContactManifold &, const double );
	const bool NetDetection(const Vector3D &);
	void NetResponce(const Vector3D &, const double );
	void NetDetectionAndResponce(const Bowl &, const double );
	const bool BowlDetection(const Vector3D &, const double );
	void BowlResponce(const Vector3D &, const double , const double );
	void BowlDetectionAndResponce(const Bowl &, const double );
	const bool TrayDetection(const Tray &);
	void TrayResponce(const Tray &, const double );
	void TrayDetectionAndResponce(const Box &, const double );
	void UpdateObjectPhysics();
	void Render() const;

private:
	array<Vector3D *, 8> m_Indices;
	Vector3D m_Position, m_NewPosition, m_PreviousPosition, m_Velocity, m_NewVelocity, m_Acceleration, m_Rotation, m_Colour;
	bool *m_IntegrationBool, *m_FallBool;
	bool m_CheckBool;
	double *m_Friction, *m_Elasticity;
	double m_Radius, m_Mass;
};