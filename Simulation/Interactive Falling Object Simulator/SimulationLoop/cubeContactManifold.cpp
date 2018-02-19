#include "cubeContactManifold.h"

CubeContactManifold::CubeContactManifold()
{
	m_Cube1 = nullptr;
	m_Cube2 = nullptr;
}

CubeContactManifold::CubeContactManifold(Cube *cube1, Cube *cube2)
{
	m_Cube1 = nullptr;
	m_Cube2 = nullptr;

	m_Cube1 = cube1;
	m_Cube2 = cube2;
}

CubeContactManifold::CubeContactManifold(const CubeContactManifold &cubeContactManifold)
{
	m_Cube1 = cubeContactManifold.GetCube1();
	m_Cube2 = cubeContactManifold.GetCube2();
}

CubeContactManifold & CubeContactManifold::operator = (const CubeContactManifold &cubeContactManifold)
{
	m_Cube1 = cubeContactManifold.GetCube1();
	m_Cube2 = cubeContactManifold.GetCube2();

	return *this;
}

CubeContactManifold::CubeContactManifold(CubeContactManifold &&cubeContactManifold)
{
	m_Cube1 = cubeContactManifold.GetCube1();
	m_Cube2 = cubeContactManifold.GetCube2();
}

CubeContactManifold & CubeContactManifold::operator = (CubeContactManifold &&cubeContactManifold)
{
	m_Cube1 = cubeContactManifold.GetCube1();
	m_Cube2 = cubeContactManifold.GetCube2();

	return *this;
}

CubeContactManifold::~CubeContactManifold()
{
	delete m_Cube1;
	delete m_Cube2;
}