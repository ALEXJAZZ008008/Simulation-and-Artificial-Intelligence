#include "box.h"

Box::Box()
{
	m_Trays =
	{
		
	};

	// Left tray
	array<Vector3D, 4> indices =
	{
		Vector3D(-50.0, 0.0, -50.0),
		Vector3D(-50.0, 0.0, 50.0),
		Vector3D(-50.0, -150.0, -50.0),
		Vector3D(-50.0, -150.0, 50.0)
	};

	m_Trays.at(0) = new Tray(indices, true);

	// Right tray
	indices =
	{
		Vector3D(50.0, 0.0, -50.0),
		Vector3D(50.0, 0.0, 50.0),
		Vector3D(50.0, -150.0, -50.0),
		Vector3D(50.0, -150.0, 50.0)
	};

	m_Trays.at(1) = new Tray(indices, true);

	// Back tray
	indices =
	{
		Vector3D(-50.0, 0.0, -50.0),
		Vector3D(50.0, 0.0, -50.0),
		Vector3D(50.0, -150.0, -50.0),
		Vector3D(-50.0, -150.0, -50.0)
	};

	m_Trays.at(2) = new Tray(indices, true);

	// Front tray
	indices =
	{
		Vector3D(-50.0, 0.0, 50.0),
		Vector3D(50.0, 0.0, 50.0),
		Vector3D(50.0, -150.0, 50.0),
		Vector3D(-50.0, -150.0, 50.0)
	};

	m_Trays.at(3) = new Tray(indices, true);

	// Top tray
	indices =
	{
		Vector3D(-50.0, -30.0, 50.0),
		Vector3D(50.0, -30.0, -50.0),
		Vector3D(-50.0, -30.0, -50.0),
		Vector3D(50.0, -30.0, 50.0)
	};

	m_Trays.at(4) = new Tray(indices, false);

	// Middle tray
	indices =
	{
		Vector3D(-50.0, -75.0, 50.0),
		Vector3D(50.0, -75.0, -50.0),
		Vector3D(-50.0, -75.0, -50.0),
		Vector3D(50.0, -75.0, 50.0)

	};

	array<Vector3D, 9> holes =
	{
		Vector3D(-30.0, -75.0, 30.0),
		Vector3D(0.0, -75.0, 30.0),
		Vector3D(30.0, -75.0, 30.0),
		Vector3D(-30.0, -75.0, 0.0),
		Vector3D(0.0, -75.0, 0.0),
		Vector3D(30.0, -75.0, 0.0),
		Vector3D(-30.0, -75.0, -30.0),
		Vector3D(0.0, -75.0, -30.0),
		Vector3D(30.0, -75.0, -30.0),
	};

	m_Trays.at(5) = new Tray(indices, true, holes, 10.0);

	// Bottom tray
	indices =
	{
		Vector3D(-50.0, -120.0, 50.0),
		Vector3D(50.0, -120.0, -50.0),
		Vector3D(-50.0, -120.0, -50.0),
		Vector3D(50.0, -120.0, 50.0)
	};

	m_Trays.at(6) = new Tray(indices, true);
}

Box::Box(const Box &box)
{
	m_Trays = box.GetTrays();
}

Box & Box::operator = (const Box &box)
{
	m_Trays = box.GetTrays();

	return *this;
}

Box::Box(Box &&box)
{
	m_Trays = box.GetTrays();
}

Box & Box::operator = (Box &&box)
{
	m_Trays = box.GetTrays();

	return *this;
}

Box::~Box()
{
	for (unsigned int i = 0; i < m_Trays.size(); i++)
	{
		delete m_Trays.at(i);
	}
}

void Box::CalculateObjectPhysics(const double dt)
{
	for (unsigned int i = 0; i < m_Trays.size(); i++)
	{
		m_Trays.at(i)->CalculateObjectPhysics(dt);
	}
}

void Box::UpdateObjectPhysics()
{
	for (unsigned int i = 0; i < m_Trays.size(); i++)
	{
		m_Trays.at(i)->UpdateObjectPhysics();
	}
}

void Box::Render() const
{
	for (unsigned int i = 0; i < m_Trays.size(); i++)
	{
		m_Trays.at(i)->Render();
	}
}