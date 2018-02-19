#include "bowl.h"

Bowl::Bowl()
{
	m_Indices =
	{
		
	};

	m_Position =
	{
		
	};

	m_Radius = 0.0;

	int count = 0;

	for (int i = 0; i < 360.0; i++)
	{
		if (count < 83.0)
		{
			for (int j = 0; j < 360.0; j++)
			{
				m_Indices.at(count).at(j) = new Vector3D(0.0, 0.0, 0.0);
			}

			count++;
		}
	}
}

Bowl::Bowl(Vector3D position, double radius)
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

	int resolution = 180;
	int count = 0;

	for (int i = 0; i < resolution; i++)
	{
		double radians = (360.0 / resolution * i) * (3.1415926535897932384626433832795 / 180.0);
		double y = (sin(radians) * m_Radius) + m_Position.GetY();

		if (y <= -150.0)
		{
			for (unsigned int j = 0; j < m_Indices.at(count).size(); j++)
			{
				m_Indices.at(count).at(j) = new Vector3D(((sin((360.0 / m_Indices.at(0).size() * j) * (3.1415926535897932384626433832795 / 180.0)) * cos(radians)) * m_Radius) + m_Position.GetX(), y, ((cos((360.0 / m_Indices.at(0).size() * j) * (3.1415926535897932384626433832795 / 180.0)) * cos(radians)) * m_Radius) + m_Position.GetZ());
			}

			count++;
		}
	}
}

Bowl::Bowl(const Bowl &bowl)
{
	m_Indices = bowl.GetIndices();
	m_Position = bowl.GetPosition();

	m_Radius = bowl.GetRadius();
}

Bowl & Bowl::operator = (const Bowl &bowl)
{
	m_Indices = bowl.GetIndices();
	m_Position = bowl.GetPosition();

	m_Radius = bowl.GetRadius();

	return *this;
}

Bowl::Bowl(Bowl &&bowl)
{
	m_Indices = bowl.GetIndices();
	m_Position = bowl.GetPosition();

	m_Radius = bowl.GetRadius();
}

Bowl & Bowl::operator = (Bowl &&bowl)
{
	m_Indices = bowl.GetIndices();
	m_Position = bowl.GetPosition();

	m_Radius = bowl.GetRadius();

	return *this;
}

Bowl::~Bowl()
{
	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		for (unsigned int j = 0; j < m_Indices.at(i).size(); j++)
		{
			delete m_Indices.at(i).at(j);
		}
	}
}

void Bowl::CalculateObjectPhysics(const double dt)
{
	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		for (unsigned int j = 0; j < m_Indices.at(i).size(); j++)
		{

		}
	}
}

void Bowl::UpdateObjectPhysics()
{
	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		for (unsigned int j = 0; j < m_Indices.at(i).size(); j++)
		{

		}
	}
}

void Bowl::Render() const
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		glBegin(GL_LINE_LOOP);

		glColor3d(1.0, 0.0, 1.0);

		for (unsigned int j = 0; j < m_Indices.at(i).size(); j++)
		{
			glVertex3d(m_Indices.at(i).at(j)->GetX(), m_Indices.at(i).at(j)->GetY(), m_Indices.at(i).at(j)->GetZ());
		}

		glEnd();
	}

	for (unsigned int i = 0; i < m_Indices.at(0).size(); i++)
	{
		glBegin(GL_LINE_STRIP);

		glColor3d(1.0, 0.0, 1.0);

		for (unsigned int j = 0; j < m_Indices.size(); j++)
		{
			glVertex3d(m_Indices.at(j).at(i)->GetX(), m_Indices.at(j).at(i)->GetY(), m_Indices.at(j).at(i)->GetZ());
		}

		glEnd();
	}

	glPopMatrix();
	glEnd();
}