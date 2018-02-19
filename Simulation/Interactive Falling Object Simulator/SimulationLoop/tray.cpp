#include "tray.h"

Tray::Tray()
{
	m_Holes =
	{
		
	};
	
	m_Indices =
	{

	};
	
	m_NewIndices =
	{

	};

	m_Velocity =
	{

	};

	m_FrictionBool = false;
	m_HolesBool = false;
	m_MovingBool = false;

	m_HolesBool = false;
	m_MovingBool = false;
}

Tray::Tray(array<Vector3D, 4> indices, bool friction)
{
	m_Holes =
	{

	};

	m_Indices =
	{

	};

	m_NewIndices =
	{

	};

	m_Velocity =
	{

	};

	m_FrictionBool = false;
	m_HolesBool = false;
	m_MovingBool = false;

	for (unsigned int i = 0; i < 9; i++)
	{
		m_Holes.at(i) = new Hole();
	}

	m_Indices = indices;

	m_FrictionBool = friction;
	m_HolesBool = false;
	m_MovingBool = false;
}

Tray::Tray(array<Vector3D, 4> indices, bool friction, array<Vector3D, 9> holePositions, double holeRadius)
{
	m_Holes =
	{

	};

	m_Indices =
	{

	};

	m_NewIndices =
	{

	};

	m_Velocity =
	{

	};

	m_FrictionBool = false;
	m_HolesBool = false;
	m_MovingBool = false;

	for (unsigned int i = 0; i < holePositions.size(); i++)
	{
		m_Holes.at(i) = new Hole(holePositions.at(i), holeRadius);
	}

	m_Indices = indices;

	m_FrictionBool = friction;
	m_HolesBool = true;
	m_MovingBool = false;
}

Tray::Tray(const Tray &tray)
{
	m_Holes = tray.GetHoles();
	m_Indices = tray.GetIndices();
	m_NewIndices = tray.GetNewIndices();

	m_Velocity = tray.GetVelocity();

	m_FrictionBool = tray.GetFrictionBool();
	m_HolesBool = tray.GetHolesBool();
	m_MovingBool = tray.GetMovingBool();
}

Tray & Tray::operator = (const Tray &tray)
{
	m_Holes = tray.GetHoles();
	m_Indices = tray.GetIndices();
	m_NewIndices = tray.GetNewIndices();

	m_Velocity = tray.GetVelocity();

	m_FrictionBool = tray.GetFrictionBool();
	m_HolesBool = tray.GetHolesBool();
	m_MovingBool = tray.GetMovingBool();

	return *this;
}

Tray::Tray(Tray &&tray)
{
	m_Holes = tray.GetHoles();
	m_Indices = tray.GetIndices();
	m_NewIndices = tray.GetNewIndices();

	m_Velocity = tray.GetVelocity();

	m_FrictionBool = tray.GetFrictionBool();
	m_HolesBool = tray.GetHolesBool();
	m_MovingBool = tray.GetMovingBool();
}

Tray & Tray::operator = (Tray &&tray)
{
	m_Holes = tray.GetHoles();
	m_Indices = tray.GetIndices();
	m_NewIndices = tray.GetNewIndices();

	m_Velocity = tray.GetVelocity();

	m_FrictionBool = tray.GetFrictionBool();
	m_HolesBool = tray.GetHolesBool();
	m_MovingBool = tray.GetMovingBool();

	return *this;
}

Tray::~Tray()
{
	for (unsigned int i = 0; i < m_Holes.size(); i++)
	{
		delete m_Holes.at(i);
	}
}

void Tray::CalculateObjectPhysics(const double dt)
{
	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		m_NewIndices.at(i) = Vector3D(m_Indices.at(i).GetX() + (m_Velocity.GetX() * dt), m_Indices.at(i).GetY(), m_Indices.at(i).GetZ());
	}

	if (m_Velocity.Length() > 0.001)
	{
		m_MovingBool = true;
	}

	if (m_NewIndices.at(0).GetX() > 50.0 || m_NewIndices.at(0).GetX() < -50.0)
	{
		for (unsigned int i = 0; i < m_Indices.size(); i++)
		{
			m_NewIndices.at(i).SetX(m_Indices.at(i).GetX());
			m_NewIndices.at(i).SetY(m_Indices.at(i).GetY());
			m_NewIndices.at(i).SetZ(m_Indices.at(i).GetZ());
		}

		m_Velocity = Vector3D(0.0, 0.0, 0.0);

		m_MovingBool = false;
	}
}

void Tray::UpdateObjectPhysics()
{
	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		m_Indices.at(i).SetX(m_NewIndices.at(i).GetX());
		m_Indices.at(i).SetY(m_NewIndices.at(i).GetY());
		m_Indices.at(i).SetZ(m_NewIndices.at(i).GetZ());
	}
}

void Tray::Render() const
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glBegin(GL_LINE_STRIP);

	glColor3d(0.0, 1.0, 0.0);

	glVertex3d(m_Indices.at(0).GetX(), m_Indices.at(0).GetY(), m_Indices.at(0).GetZ());
	glVertex3d(m_Indices.at(1).GetX(), m_Indices.at(1).GetY(), m_Indices.at(1).GetZ());
	glVertex3d(m_Indices.at(2).GetX(), m_Indices.at(2).GetY(), m_Indices.at(2).GetZ());
	glVertex3d(m_Indices.at(3).GetX(), m_Indices.at(3).GetY(), m_Indices.at(3).GetZ());
	glVertex3d(m_Indices.at(0).GetX(), m_Indices.at(0).GetY(), m_Indices.at(0).GetZ());
	glVertex3d(m_Indices.at(2).GetX(), m_Indices.at(2).GetY(), m_Indices.at(2).GetZ());
	glVertex3d(m_Indices.at(3).GetX(), m_Indices.at(3).GetY(), m_Indices.at(3).GetZ());
	glVertex3d(m_Indices.at(1).GetX(), m_Indices.at(1).GetY(), m_Indices.at(1).GetZ());

	glEnd();

	if (m_HolesBool)
	{
		for (unsigned int i = 0; i < m_Holes.size(); i++)
		{
			m_Holes.at(i)->Render();
		}
	}

	glPopMatrix();
	glEnd();
}