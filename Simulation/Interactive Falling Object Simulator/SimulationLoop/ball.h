#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <cmath>
#include <chrono>
#include <random>
#include <functional>
#include "ballContactManifold.h"
#include "ballContactManifold.h"
#include "bowl.h"
#include "box.h"
#include "cube.h"
#include "textureLoader.h"
#include "tray.h"
#include "vector3D.h"

using namespace std;

#define _USE_MATH_DEFINES

class BallContactManifold;
class BallCubeContactManifold;
class Cube;

class Ball
{
public:
	Ball();
	Ball(bool &, double &, double &, bool &);
	Ball(const Ball &);
	Ball & operator = (const Ball &);
	Ball(Ball &&);
	Ball & operator = (Ball &&);
	~Ball();

	const GLuint Ball::GetTexture() const
	{
		return m_Texture;
	}

	const Vector3D Ball::GetPosition() const
	{
		return m_Position;
	}

	const Vector3D Ball::GetNewPosition() const
	{
		return m_NewPosition;
	}

	const Vector3D Ball::GetPreviousPosition() const
	{
		return m_PreviousPosition;
	}

	const Vector3D Ball::GetVelocity() const
	{
		return m_Velocity;
	}

	const Vector3D Ball::GetNewVelocity() const
	{
		return m_NewVelocity;
	}

	const Vector3D Ball::GetAcceleration() const
	{
		return m_Acceleration;
	}

	const Vector3D Ball::GetRotation() const
	{
		return m_Rotation;
	}

	const Vector3D Ball::GetColour() const
	{
		return m_Colour;
	}

	bool * Ball::GetIntegrationBool() const
	{
		return m_IntegrationBool;
	}

	bool * Ball::GetFallBool() const
	{
		return m_FallBool;
	}

	const bool Ball::GetCheckBool() const
	{
		return m_CheckBool;
	}

	double * Ball::GetFriction() const
	{
		return m_Friction;
	}

	double * Ball::GetElasticity() const
	{
		return m_Elasticity;
	}

	const double Ball::GetRadius() const
	{
		return m_Radius;
	}

	const double Ball::GetMass() const
	{
		return m_Mass;
	}

	void Ball::SetTexture(const GLuint &texture)
	{
		m_Texture = texture;
	}

	void Ball::SetPosition(const Vector3D &position)
	{
		m_Position = position;
	}

	void Ball::SetNewPosition(const Vector3D &newPosition)
	{
		m_NewPosition = newPosition;
	}

	void Ball::SetPreviousPosition(const Vector3D &previousPosition)
	{
		m_PreviousPosition = previousPosition;
	}

	void Ball::SetVelocity(const Vector3D &velocity)
	{
		m_Velocity = velocity;
	}

	void Ball::SetNewVelocity(const Vector3D &newVelocity)
	{
		m_NewVelocity = newVelocity;
	}

	void Ball::SetAcceleration(const Vector3D &acceleration)
	{
		m_Acceleration = acceleration;
	}

	void Ball::SetRotation(const Vector3D &rotation)
	{
		m_Rotation = rotation;
	}

	void Ball::SetColour(const Vector3D &colour)
	{
		m_Colour = colour;
	}

	void Ball::SetIntegrationBool(bool *integrationBool)
	{
		m_IntegrationBool = integrationBool;
	}

	void Ball::SetFallBool(bool *fallBool)
	{
		m_FallBool = fallBool;
	}

	void Ball::SetCheckBool(const bool checkBool)
	{
		m_CheckBool = checkBool;
	}

	void Ball::SetFriction(double *friction)
	{
		m_Friction = friction;
	}

	void Ball::SetElasticity(double *elasticity)
	{
		m_Elasticity = elasticity;
	}

	void Ball::SetRadius(const double radius)
	{
		m_Radius = radius;
	}

	void Ball::SetMass(const double mass)
	{
		m_Mass = mass;
	}

	const Vector3D Integration(const Vector3D &, const Vector3D &, const double);
	void CalculateObjectPhysics(const double);
	void DynamicCollisionDetection(Ball *, vector<BallContactManifold *> &);
	void DynamicCollisionDetection(Cube *, vector<BallCubeContactManifold *> &);
	void ApplyFriction(const Vector3D &);
	void ApplyFriction(const Vector3D &, const Vector3D &, const double);
	void ApplyElasticity(const Vector3D);
	void DynamicCollisionResponse(const BallContactManifold &, const double);
	void DynamicCollisionResponse(const BallCubeContactManifold &, const double);
	const bool NetDetection(const Vector3D &);
	void NetResponce(const Vector3D &, const double);
	void NetDetectionAndResponce(const Bowl &, const double);
	const bool BowlDetection(const Vector3D &, const double);
	void BowlResponce(const Vector3D &, const double , const double);
	void BowlDetectionAndResponce(const Bowl &, const double);
	const bool TrayDetection(const Tray &);
	void TrayResponce(const Tray &, const double);
	void TrayDetectionAndResponce(const Box &, const double);
	void UpdateObjectPhysics();
	void Render() const;

private:
	GLuint m_Texture;
	Vector3D m_Position, m_NewPosition, m_PreviousPosition, m_Velocity, m_NewVelocity, m_Acceleration, m_Rotation, m_Colour;
	bool *m_IntegrationBool, *m_FallBool;
	bool m_CheckBool;
	double *m_Friction, *m_Elasticity;
	double m_Radius, m_Mass;
};