#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include "ball.h"
#include "cube.h"
#include "vector3D.h"

class Ball;
class Cube;

class BallCubeContactManifold
{
public:
	BallCubeContactManifold();
	BallCubeContactManifold(Ball *, Cube *);
	BallCubeContactManifold(const BallCubeContactManifold &);
	BallCubeContactManifold & operator = (const BallCubeContactManifold &);
	BallCubeContactManifold(BallCubeContactManifold &&);
	BallCubeContactManifold & operator = (BallCubeContactManifold &&);
	~BallCubeContactManifold();

	Ball * BallCubeContactManifold::GetBall() const
	{
		return m_Ball;
	}

	Cube * BallCubeContactManifold::GetCube() const
	{
		return m_Cube;
	}

	void BallCubeContactManifold::SetBall(Ball *ball)
	{
		m_Ball = ball;
	}

	void BallCubeContactManifold::SetCube(Cube *cube)
	{
		m_Cube = cube;
	}

private:
	Ball *m_Ball;
	Cube *m_Cube;
};