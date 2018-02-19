#include "ballCubeContactManifold.h"

BallCubeContactManifold::BallCubeContactManifold()
{
	m_Ball = nullptr;
	m_Cube = nullptr;
}

BallCubeContactManifold::BallCubeContactManifold(Ball *ball, Cube *cube)
{
	m_Ball = nullptr;
	m_Cube = nullptr;

	m_Ball = ball;
	m_Cube = cube;
}

BallCubeContactManifold::BallCubeContactManifold(const BallCubeContactManifold &ballCubeContactManifold)
{
	m_Ball = ballCubeContactManifold.GetBall();
	m_Cube = ballCubeContactManifold.GetCube();
}

BallCubeContactManifold & BallCubeContactManifold::operator = (const BallCubeContactManifold &ballCubeContactManifold)
{
	m_Ball = ballCubeContactManifold.GetBall();
	m_Cube = ballCubeContactManifold.GetCube();

	return *this;
}

BallCubeContactManifold::BallCubeContactManifold(BallCubeContactManifold &&ballCubeContactManifold)
{
	m_Ball = ballCubeContactManifold.GetBall();
	m_Cube = ballCubeContactManifold.GetCube();
}

BallCubeContactManifold & BallCubeContactManifold::operator = (BallCubeContactManifold &&ballCubeContactManifold)
{
	m_Ball = ballCubeContactManifold.GetBall();
	m_Cube = ballCubeContactManifold.GetCube();

	return *this;
}

BallCubeContactManifold::~BallCubeContactManifold()
{
	delete m_Ball;
	delete m_Cube;
}