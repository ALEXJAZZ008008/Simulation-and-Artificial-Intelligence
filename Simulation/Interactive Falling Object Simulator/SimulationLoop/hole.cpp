#include "hole.h"

Hole::Hole()
{
	m_Indices =
	{
		
	};

	m_Position =
	{
		
	};

	m_Radius = 0.0;

	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		m_Indices.at(i) = new Vector3D(0.0, 0.0, 0.0);
	}
}

Hole::Hole(Vector3D position, double radius)
{
	m_Indices =
	{

	};

	m_Position =
	{
		
	};

	m_Radius = 0.0;

	m_Position = position;

	m_Radius = radius;

	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		m_Indices.at(i) = new Vector3D((sin((360.0 / m_Indices.size() * i) * (3.1415926535897932384626433832795 / 180.0)) * m_Radius) + m_Position.GetX(), m_Position.GetY(), (cos((360.0 / m_Indices.size() * i) * (3.1415926535897932384626433832795 / 180.0)) * m_Radius) + m_Position.GetZ());
	}
}

Hole::Hole(const Hole &hole)
{
	m_Indices = hole.GetIndices();
	m_Position = hole.GetPosition();

	m_Radius = hole.GetRadius();
}

Hole & Hole::operator = (const Hole &hole)
{
	m_Indices = hole.GetIndices();
	m_Position = hole.GetPosition();

	m_Radius = hole.GetRadius();

	return *this;
}

Hole::Hole(Hole &&hole)
{
	m_Indices = hole.GetIndices();
	m_Position = hole.GetPosition();

	m_Radius = hole.GetRadius();
}

Hole & Hole::operator = (Hole &&hole)
{
	m_Indices = hole.GetIndices();
	m_Position = hole.GetPosition();

	m_Radius = hole.GetRadius();

	return *this;
}

Hole::~Hole()
{
	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		delete m_Indices.at(i);
	}
}

void Hole::Render() const
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glBegin(GL_LINE_LOOP);

	glColor3d(1.0, 1.0, 1.0);

	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		glVertex3d(m_Indices.at(i)->GetX(), m_Indices.at(i)->GetY(), m_Indices.at(i)->GetZ());
	}

	glPopMatrix();
	glEnd();
}