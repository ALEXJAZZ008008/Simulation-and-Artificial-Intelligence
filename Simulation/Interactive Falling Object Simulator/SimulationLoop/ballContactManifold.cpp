#include "ballContactManifold.h"

BallContactManifold::BallContactManifold()
{
	m_Ball1 = nullptr;
	m_Ball2 = nullptr;
}

BallContactManifold::BallContactManifold(Ball *ball1, Ball *ball2)
{
	m_Ball1 = nullptr;
	m_Ball2 = nullptr;

	m_Ball1 = ball1;
	m_Ball2 = ball2;
}

BallContactManifold::BallContactManifold(const BallContactManifold &ballContactManifold)
{
	m_Ball1 = ballContactManifold.GetBall1();
	m_Ball2 = ballContactManifold.GetBall1();
}

BallContactManifold & BallContactManifold::operator = (const BallContactManifold &ballContactManifold)
{
	m_Ball1 = ballContactManifold.GetBall1();
	m_Ball2 = ballContactManifold.GetBall1();

	return *this;
}

BallContactManifold::BallContactManifold(BallContactManifold &&ballContactManifold)
{
	m_Ball1 = ballContactManifold.GetBall1();
	m_Ball2 = ballContactManifold.GetBall1();
}

BallContactManifold & BallContactManifold::operator = (BallContactManifold &&ballContactManifold)
{
	m_Ball1 = ballContactManifold.GetBall1();
	m_Ball2 = ballContactManifold.GetBall1();

	return *this;
}

BallContactManifold::~BallContactManifold()
{
	delete m_Ball1;
	delete m_Ball2;
}