#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include "ball.h"
#include "vector3D.h"

class Ball;

class BallContactManifold
{
public:
	BallContactManifold();
	BallContactManifold(Ball *, Ball *);
	BallContactManifold(const BallContactManifold &);
	BallContactManifold & operator = (const BallContactManifold &);
	BallContactManifold(BallContactManifold &&);
	BallContactManifold & operator = (BallContactManifold &&);
	~BallContactManifold();

	Ball * BallContactManifold::GetBall1() const
	{
		return m_Ball1;
	}

	Ball * BallContactManifold::GetBall2() const
	{
		return m_Ball2;
	}

	void BallContactManifold::SetBall1(Ball *ball)
	{
		m_Ball1 = ball;
	}

	void BallContactManifold::SetBall2(Ball *ball)
	{
		m_Ball2 = ball;
	}

private:
	Ball *m_Ball1, *m_Ball2;
};