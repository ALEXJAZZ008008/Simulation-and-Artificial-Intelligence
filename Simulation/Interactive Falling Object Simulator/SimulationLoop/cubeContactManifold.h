#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include "cube.h"
#include "vector3D.h"

class Cube;

class CubeContactManifold
{
public:
	CubeContactManifold();
	CubeContactManifold(Cube *, Cube *);
	CubeContactManifold(const CubeContactManifold &);
	CubeContactManifold & operator = (const CubeContactManifold &);
	CubeContactManifold(CubeContactManifold &&);
	CubeContactManifold & operator = (CubeContactManifold &&);
	~CubeContactManifold();

	Cube * CubeContactManifold::GetCube1() const
	{
		return m_Cube1;
	}

	Cube * CubeContactManifold::GetCube2() const
	{
		return m_Cube2;
	}

	void CubeContactManifold::SetCube1(Cube *cube)
	{
		m_Cube1 = cube;
	}

	void CubeContactManifold::SetCube2(Cube *cube)
	{
		m_Cube2 = cube;
	}

private:
	Cube *m_Cube1, *m_Cube2;
};

