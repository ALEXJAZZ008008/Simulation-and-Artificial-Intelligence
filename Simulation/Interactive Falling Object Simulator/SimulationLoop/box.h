#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <array>
#include "tray.h"
#include "vector3D.h"

using namespace std;

class Box
{
public:
	Box();
	Box(const Box &);
	Box & operator = (const Box &);
	Box(Box &&);
	Box & operator = (Box &&);
	~Box();

	const array<Tray *, 7> Box::GetTrays() const
	{
		return m_Trays;
	}

	void Box::SetTrays(const array<Tray *, 7> &trays)
	{
		m_Trays = trays;
	}

	void CalculateObjectPhysics(const double dt);
	void UpdateObjectPhysics();
	void Render() const;

private:
	array<Tray *, 7> m_Trays;
};