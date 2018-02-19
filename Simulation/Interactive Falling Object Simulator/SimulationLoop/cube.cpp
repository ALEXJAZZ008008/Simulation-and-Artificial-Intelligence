#include "cube.h"

Cube::Cube()
{
	m_Indices =
	{
		
	};

	m_Position =
	{
		
	};

	m_NewPosition =
	{
		
	};

	m_PreviousPosition =
	{
		
	};

	m_Velocity =
	{
		
	};

	m_NewVelocity =
	{
		
	};

	m_Acceleration =
	{
		
	};

	m_Rotation =
	{
		
	};

	m_Colour =
	{
		
	};

	m_IntegrationBool = nullptr;
	m_FallBool = nullptr;

	m_CheckBool = true;

	m_Friction = nullptr;
	m_Elasticity = nullptr;

	m_Radius = 0.0;
	m_Mass = 0.0;

	m_Indices =
	{
		new Vector3D(-6.25, 6.25, 6.25),
		new Vector3D(6.25, 6.25, -6.25),
		new Vector3D(-6.25, 6.25, -6.25),
		new Vector3D(6.25, 6.25, 6.25),
		new Vector3D(-6.25, -6.25, 6.25),
		new Vector3D(6.25, -6.25, -6.25),
		new Vector3D(-6.25, -6.25, -6.25),
		new Vector3D(6.25, -6.25, 6.25)
	};

	m_Position = Vector3D(0.0, 40.0, 0.0);

	long long seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 engine(static_cast<unsigned int>(seed));
	_Binder<_Unforced, uniform_real_distribution<>, mt19937 &> random = bind(uniform_real_distribution<double>(-1.0, 1.0), engine);

	m_Velocity = Vector3D(random(), 0.0, random());
	m_Acceleration = Vector3D(0.0, -981.0, 0.0);
	m_Rotation = Vector3D(0.0, 0.0, 0.0);
	m_Colour = Vector3D(1.0, 0.0, 0.0);

	m_CheckBool = true;

	m_Radius = 6.25;
	m_Mass = 10.0;
}

Cube::Cube(bool &integrationBool, double &friction, double &elasticity, bool &fallBool)
{
	m_Indices =
	{

	};

	m_Position =
	{
		
	};

	m_NewPosition =
	{
		
	};

	m_PreviousPosition =
	{
		
	};

	m_Velocity =
	{
		
	};

	m_NewVelocity =
	{
		
	};

	m_Acceleration =
	{
		
	};

	m_Rotation =
	{
		
	};

	m_Colour =
	{
		
	};

	m_IntegrationBool = nullptr;
	m_FallBool = nullptr;

	m_CheckBool = true;

	m_Friction = nullptr;
	m_Elasticity = nullptr;

	m_Radius = 0.0;
	m_Mass = 0.0;

	m_Indices =
	{
		new Vector3D(-6.25, 6.25, 6.25),
		new Vector3D(6.25, 6.25, -6.25),
		new Vector3D(-6.25, 6.25, -6.25),
		new Vector3D(6.25, 6.25, 6.25),
		new Vector3D(-6.25, -6.25, 6.25),
		new Vector3D(6.25, -6.25, -6.25),
		new Vector3D(-6.25, -6.25, -6.25),
		new Vector3D(6.25, -6.25, 6.25)
	};

	m_Position = Vector3D(0.0, 40.0, 0.0);

	long long seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 engine(static_cast<unsigned int>(seed));
	_Binder<_Unforced, uniform_real_distribution<>, mt19937 &> random = bind(uniform_real_distribution<double>(-50.0, 50.0), engine);

	m_Velocity = Vector3D(random(), random(), random());
	m_Acceleration = Vector3D(0.0, -981.0, 0.0);
	m_Rotation = Vector3D(0.0, 0.0, 0.0);
	m_Colour = Vector3D(1.0, 0.0, 0.0);

	m_IntegrationBool = &integrationBool;
	m_FallBool = &fallBool;
	m_CheckBool = true;

	m_Radius = 6.25;
	m_Mass = 10.0;

	m_Friction = &friction;
	m_Elasticity = &elasticity;
}

Cube::Cube(const Cube &cube)
{
	m_Indices = cube.GetIndices();
	m_Position = cube.GetPosition();
	m_NewPosition = cube.GetNewPosition();
	m_PreviousPosition = cube.GetPreviousPosition();
	m_Velocity = cube.GetVelocity();
	m_NewVelocity = cube.GetNewVelocity();
	m_Acceleration = cube.GetAcceleration();
	m_Rotation = cube.GetRotation();
	m_Colour = cube.GetColour();

	m_IntegrationBool = cube.GetIntegrationBool();
	m_FallBool = cube.GetFallBool();

	m_CheckBool = cube.GetCheckBool();

	m_Friction = cube.GetFriction();
	m_Elasticity = cube.GetElasticity();

	m_Radius = cube.GetRadius();
	m_Mass = cube.GetMass();
}

Cube & Cube::operator = (const Cube &cube)
{
	m_Indices = cube.GetIndices();
	m_Position = cube.GetPosition();
	m_NewPosition = cube.GetNewPosition();
	m_PreviousPosition = cube.GetPreviousPosition();
	m_Velocity = cube.GetVelocity();
	m_NewVelocity = cube.GetNewVelocity();
	m_Acceleration = cube.GetAcceleration();
	m_Rotation = cube.GetRotation();
	m_Colour = cube.GetColour();

	m_IntegrationBool = cube.GetIntegrationBool();
	m_FallBool = cube.GetFallBool();

	m_CheckBool = cube.GetCheckBool();

	m_Friction = cube.GetFriction();
	m_Elasticity = cube.GetElasticity();

	m_Radius = cube.GetRadius();
	m_Mass = cube.GetMass();

	return *this;
}

Cube::Cube(Cube &&cube)
{
	m_Indices = cube.GetIndices();
	m_Position = cube.GetPosition();
	m_NewPosition = cube.GetNewPosition();
	m_PreviousPosition = cube.GetPreviousPosition();
	m_Velocity = cube.GetVelocity();
	m_NewVelocity = cube.GetNewVelocity();
	m_Acceleration = cube.GetAcceleration();
	m_Rotation = cube.GetRotation();
	m_Colour = cube.GetColour();

	m_IntegrationBool = cube.GetIntegrationBool();
	m_FallBool = cube.GetFallBool();

	m_CheckBool = cube.GetCheckBool();

	m_Friction = cube.GetFriction();
	m_Elasticity = cube.GetElasticity();

	m_Radius = cube.GetRadius();
	m_Mass = cube.GetMass();
}

Cube & Cube::operator = (Cube &&cube)
{
	m_Indices = cube.GetIndices();
	m_Position = cube.GetPosition();
	m_NewPosition = cube.GetNewPosition();
	m_PreviousPosition = cube.GetPreviousPosition();
	m_Velocity = cube.GetVelocity();
	m_NewVelocity = cube.GetNewVelocity();
	m_Acceleration = cube.GetAcceleration();
	m_Rotation = cube.GetRotation();
	m_Colour = cube.GetColour();

	m_IntegrationBool = cube.GetIntegrationBool();
	m_FallBool = cube.GetFallBool();

	m_CheckBool = cube.GetCheckBool();

	m_Friction = cube.GetFriction();
	m_Elasticity = cube.GetElasticity();

	m_Radius = cube.GetRadius();
	m_Mass = cube.GetMass();

	return *this;
}

Cube::~Cube()
{
	for (unsigned int i = 0; i < m_Indices.size(); i++)
	{
		delete m_Indices.at(i);
	}
}

const Vector3D Cube::Integration(const Vector3D &start, const Vector3D &increment, const double dt)
{
	Vector3D a = start;
	Vector3D b = start + (increment * (dt / 2.0));
	Vector3D c = start + (increment * (dt / 2.0));
	Vector3D d = start + (increment * dt);

	if (*m_IntegrationBool)
	{
		return (a + (b * 2.0) + (c * 2.0) + d) / 6;
	}
	else
	{
		return d;
	}
}

void Cube::CalculateObjectPhysics(const double dt)
{
	m_PreviousPosition = m_Position;

	m_NewVelocity = Integration(m_Velocity, m_Acceleration, dt);
	m_NewPosition = Integration(m_Position, m_NewVelocity, dt);
}

void Cube::DynamicCollisionDetection(Cube *cube, vector<CubeContactManifold *> &cubeContactManifold)
{
	if ((m_NewPosition - cube->GetNewPosition()).Length() < m_Radius + cube->GetRadius())
	{
		cubeContactManifold.push_back(new CubeContactManifold(this, cube));
	}
}

void Cube::DynamicCollisionDetection(Ball *ball, vector<BallCubeContactManifold *> &ballCubeContactManifold)
{
	if ((m_NewPosition - ball->GetNewPosition()).Length() < m_Radius + ball->GetRadius())
	{
		ballCubeContactManifold.push_back(new BallCubeContactManifold(ball, this));
	}
}

void Cube::ApplyFriction(const Vector3D &collisionNormal)
{
	m_NewVelocity -= Vector3D(m_NewVelocity.Normalise().GetX() * -(fabs(collisionNormal.GetX()) - 1.0), m_NewVelocity.Normalise().GetY() * -(fabs(collisionNormal.GetY()) - 1.0), m_NewVelocity.Normalise().GetZ() * -(fabs(collisionNormal.GetZ()) - 1.0)) * *m_Friction;

	if (m_NewVelocity.GetX() > -5.0 && m_NewVelocity.GetX() < 5.0)
	{
		m_NewVelocity.SetX(0.0);
	}

	if (m_NewVelocity.GetZ() > -5.0 && m_NewVelocity.GetZ() < 5.0)
	{
		m_NewVelocity.SetZ(0.0);
	}
}

void Cube::ApplyFriction(const Vector3D &collisionNormal, const Vector3D &velocity, const double dt)
{
	m_NewVelocity -= Vector3D(m_NewVelocity.Normalise().GetX() * -(fabs(collisionNormal.GetX()) - 1.0), m_NewVelocity.Normalise().GetY() * -(fabs(collisionNormal.GetY()) - 1.0), m_NewVelocity.Normalise().GetZ() * -(fabs(collisionNormal.GetZ()) - 1.0)) * *m_Friction;

	if (m_NewVelocity.GetX() > -5.0 && m_NewVelocity.GetX() < 5.0)
	{
		m_NewVelocity.SetX(0.0);
	}

	if (m_NewVelocity.GetZ() > -5.0 && m_NewVelocity.GetZ() < 5.0)
	{
		m_NewVelocity.SetZ(0.0);
	}

	if (velocity.Length() > 0.001)
	{
		m_NewPosition += velocity * dt;

		m_Rotation.SetX(m_Rotation.GetX() - ((m_NewPosition.GetZ() - m_PreviousPosition.GetZ()) / ((m_Radius * 2.0) * 3.1415926535897932384626433832795)) * 360);
		m_Rotation.SetZ(m_Rotation.GetZ() - ((m_NewPosition.GetX() - m_PreviousPosition.GetX()) / ((m_Radius * 2.0) * 3.1415926535897932384626433832795)) * 360);
	}
}

void Cube::ApplyElasticity(const Vector3D &collisionNormal)
{
	m_NewVelocity *= (Vector3D(fabs(collisionNormal.GetX()), fabs(collisionNormal.GetY()), fabs(collisionNormal.GetZ())) * log10((*m_Elasticity * 10.0))) + Vector3D(-(fabs(collisionNormal.GetX()) - 1.0), -(fabs(collisionNormal.GetY()) - 1.0), -(fabs(collisionNormal.GetZ()) - 1.0));

	if (m_NewVelocity.GetY() > -50.0 && m_NewVelocity.GetY() < 50.0)
	{
		m_NewVelocity.SetY(0.0);
	}
}

void Cube::DynamicCollisionResponse(const CubeContactManifold &cubeContactManifold, const double dt)
{
	Vector3D collisionNormal = (cubeContactManifold.GetCube1()->GetNewPosition() - cubeContactManifold.GetCube2()->GetNewPosition()).Normalise();

	double forceMagnitude = ((cubeContactManifold.GetCube1()->GetNewVelocity().DotProduct(collisionNormal) - cubeContactManifold.GetCube2()->GetNewVelocity().DotProduct(collisionNormal)) * 2.0) / (cubeContactManifold.GetCube1()->GetMass() + cubeContactManifold.GetCube1()->GetMass());

	cubeContactManifold.GetCube1()->SetNewVelocity(cubeContactManifold.GetCube1()->GetNewVelocity() - ((forceMagnitude * cubeContactManifold.GetCube2()->GetMass()) * collisionNormal));
	cubeContactManifold.GetCube2()->SetNewVelocity(cubeContactManifold.GetCube2()->GetNewVelocity() + ((forceMagnitude * cubeContactManifold.GetCube1()->GetMass()) * collisionNormal));

	Vector3D midpoint = cubeContactManifold.GetCube1()->GetPreviousPosition() - cubeContactManifold.GetCube2()->GetPreviousPosition();

	while (true)
	{
		if ((cubeContactManifold.GetCube1()->GetNewPosition() - cubeContactManifold.GetCube2()->GetNewPosition()).Length() > cubeContactManifold.GetCube1()->GetRadius() + cubeContactManifold.GetCube2()->GetRadius())
		{
			ApplyFriction(collisionNormal);
			ApplyElasticity(collisionNormal);

			cubeContactManifold.GetCube1()->SetCheckBool(true);
			cubeContactManifold.GetCube2()->SetCheckBool(true);

			return;
		}
		else
		{
			cubeContactManifold.GetCube1()->SetNewPosition(cubeContactManifold.GetCube1()->GetNewPosition() + (midpoint * 0.001));
			cubeContactManifold.GetCube2()->SetNewPosition(cubeContactManifold.GetCube2()->GetNewPosition() - (midpoint * 0.001));
		}
	}
}

void Cube::DynamicCollisionResponse(const BallCubeContactManifold &ballCubeContactManifold, const double dt)
{
	Vector3D collisionNormal = (ballCubeContactManifold.GetBall()->GetNewPosition() - ballCubeContactManifold.GetCube()->GetNewPosition()).Normalise();

	double forceMagnitude = ((ballCubeContactManifold.GetBall()->GetNewVelocity().DotProduct(collisionNormal) - ballCubeContactManifold.GetCube()->GetNewVelocity().DotProduct(collisionNormal)) * 2.0) / (ballCubeContactManifold.GetBall()->GetMass() + ballCubeContactManifold.GetBall()->GetMass());

	ballCubeContactManifold.GetBall()->SetNewVelocity(ballCubeContactManifold.GetBall()->GetNewVelocity() - ((forceMagnitude * ballCubeContactManifold.GetCube()->GetMass()) * collisionNormal));
	ballCubeContactManifold.GetCube()->SetNewVelocity(ballCubeContactManifold.GetCube()->GetNewVelocity() + ((forceMagnitude * ballCubeContactManifold.GetBall()->GetMass()) * collisionNormal));

	Vector3D midpoint = ballCubeContactManifold.GetBall()->GetPreviousPosition() - ballCubeContactManifold.GetCube()->GetPreviousPosition();

	while (true)
	{
		if ((ballCubeContactManifold.GetBall()->GetNewPosition() - ballCubeContactManifold.GetCube()->GetNewPosition()).Length() > ballCubeContactManifold.GetBall()->GetRadius() + ballCubeContactManifold.GetCube()->GetRadius())
		{
			ApplyFriction(collisionNormal);
			ApplyElasticity(collisionNormal);

			ballCubeContactManifold.GetBall()->SetCheckBool(true);

			return;
		}
		else
		{
			ballCubeContactManifold.GetBall()->SetNewPosition(ballCubeContactManifold.GetBall()->GetNewPosition() + (midpoint * 0.001));
			ballCubeContactManifold.GetCube()->SetNewPosition(ballCubeContactManifold.GetCube()->GetNewPosition() - (midpoint * 0.001));
		}
	}
}

const bool Cube::NetDetection(const Vector3D &position)
{
	return (m_NewPosition - position).Length() < m_Radius;
}

void Cube::NetResponce(const Vector3D &position, const double dt)
{
	Vector3D collisionNormal = (m_NewPosition - position).Normalise();

	double forceMagnitude = (m_NewVelocity.DotProduct(collisionNormal) * 2.0);

	m_NewVelocity -= forceMagnitude * collisionNormal;

	Vector3D midpoint = m_PreviousPosition - position;

	while (true)
	{
		if ((m_NewPosition - position).Length() > m_Radius)
		{
			ApplyFriction(collisionNormal);
			ApplyElasticity(collisionNormal);

			return;
		}
		else
		{
			m_NewPosition += midpoint * 0.001;
		}
	}
}

void Cube::NetDetectionAndResponce(const Bowl &bowl, const double dt)
{
	for (unsigned int i = 0; i < bowl.GetIndices().size(); i++)
	{
		for (unsigned int j = 0; j < bowl.GetIndices().at(i).size(); j++)
		{
			if (NetDetection(*bowl.GetIndices().at(i).at(j)))
			{
				NetResponce(*bowl.GetIndices().at(i).at(j), dt);
			}
		}
	}
}

const bool Cube::BowlDetection(const Vector3D &position, const double radius)
{
	return (m_NewPosition - position).Length() > radius - m_Radius;
}

void Cube::BowlResponce(const Vector3D &position, const double radius, const double dt)
{
	Vector3D collisionNormal = (m_NewPosition - position).Normalise();

	double forceMagnitude = (m_NewVelocity.DotProduct(collisionNormal) * 2.0);

	m_NewVelocity -= forceMagnitude * collisionNormal;

	Vector3D midpoint = m_PreviousPosition - position;

	while (true)
	{
		if ((m_NewPosition - position).Length() < radius - m_Radius)
		{
			ApplyFriction(collisionNormal);
			ApplyElasticity(collisionNormal);

			return;
		}
		else
		{
			m_NewPosition -= midpoint * 0.001;
		}
	}
}

void Cube::BowlDetectionAndResponce(const Bowl &bowl, const double dt)
{
	if (BowlDetection(bowl.GetPosition(), bowl.GetRadius()))
	{
		BowlResponce(bowl.GetPosition(), bowl.GetRadius(), dt);
	}
}

const bool Cube::TrayDetection(const Tray &tray)
{
	// Equation of plane ax + by + cz + d = 0
	// Find the normal vector for the tray
	Vector3D P = tray.GetIndices().at(0);
	Vector3D Q = tray.GetIndices().at(1);
	Vector3D R = tray.GetIndices().at(2);

	double a = ((Q.GetY() - tray.GetIndices().at(0).GetY()) * (R.GetZ() - P.GetZ())) - ((R.GetY() - P.GetY()) * (Q.GetZ() - P.GetZ()));
	double b = ((Q.GetZ() - P.GetZ()) * (R.GetX() - P.GetX())) - ((R.GetZ() - P.GetZ()) * (Q.GetX() - P.GetX()));
	double c = ((Q.GetX() - P.GetX()) * (R.GetY() - P.GetY())) - ((R.GetX() - P.GetX()) * (Q.GetY() - P.GetY()));
	double d = -((a * P.GetX()) + (b * P.GetY()) + (c * P.GetZ()));

	Vector3D normal = Vector3D(a, b, c).Normalise();

	double distance = fabs(((a * m_NewPosition.GetX()) + (b * m_NewPosition.GetY()) + (c * m_NewPosition.GetZ() + d)) / sqrt((pow(a, 2.0)) + (pow(b, 2.0)) + (pow(c, 2.0))));

	double previousPosition = (a * m_PreviousPosition.GetX()) + (b * m_PreviousPosition.GetY()) + (c * m_PreviousPosition.GetZ()) + d;
	double newPosition = (a * m_NewPosition.GetX()) + (b * m_NewPosition.GetY()) + (c * m_NewPosition.GetZ()) + d;

	return ((distance < m_Radius) || (previousPosition > 0.0 && newPosition < 0.0) || (previousPosition < 0.0 && newPosition > 0.0));
}

void Cube::TrayResponce(const Tray &tray, const double dt)
{
	if (tray.GetIndices().at(0).GetY() == tray.GetIndices().at(1).GetY() && tray.GetIndices().at(1).GetY() == tray.GetIndices().at(2).GetY() && tray.GetIndices().at(2).GetY() == tray.GetIndices().at(3).GetY())
	{
		if (m_NewPosition.GetX() < tray.GetIndices().at(0).GetX())
		{
			if ((m_NewPosition - Vector3D(tray.GetIndices().at(0).GetX(), tray.GetIndices().at(0).GetY(), m_NewPosition.GetZ())).Length() < m_Radius)
			{
				Vector3D collisionNormal = (m_NewPosition - Vector3D(tray.GetIndices().at(0).GetX(), tray.GetIndices().at(0).GetY(), m_NewPosition.GetZ())).Normalise();

				double forceMagnitude = (m_NewVelocity.DotProduct(collisionNormal) * 2.0) / m_Mass;

				m_NewVelocity = m_NewVelocity - ((forceMagnitude * m_Mass * collisionNormal));

				Vector3D midpoint = m_PreviousPosition - Vector3D(tray.GetIndices().at(0).GetX(), tray.GetIndices().at(0).GetY(), m_NewPosition.GetZ());

				while (true)
				{
					if ((m_NewPosition - Vector3D(tray.GetIndices().at(0).GetX(), tray.GetIndices().at(0).GetY(), m_NewPosition.GetZ())).Length() > m_Radius)
					{
						if (tray.GetFrictionBool())
						{
							ApplyFriction(collisionNormal, tray.GetVelocity(), dt);
						}

						ApplyElasticity(collisionNormal);

						return;
					}
					else
					{
						m_NewPosition += midpoint * 0.001;
					}
				}
			}
			else
			{
				return;
			}
		}

		if (tray.GetHolesBool())
		{
			for (unsigned int i = 0; i < tray.GetHoles().size(); i++)
			{
				if ((m_NewPosition - tray.GetHoles().at(i)->GetPosition()).Length() < tray.GetHoles().at(i)->GetRadius())
				{
					return;
				}
			}
		}

		if (m_NewPosition.GetX() < tray.GetIndices().at(1).GetX() && m_NewPosition.GetZ() < tray.GetIndices().at(0).GetZ() && m_NewPosition.GetZ() > tray.GetIndices().at(1).GetZ())
		{
			Vector3D collisionNormal = (m_NewPosition - Vector3D(m_NewPosition.GetX(), tray.GetIndices().at(0).GetY(), m_NewPosition.GetZ())).Normalise();

			double forceMagnitude = m_NewVelocity.DotProduct(collisionNormal) * 2.0;

			m_NewVelocity -= forceMagnitude * collisionNormal;

			Vector3D midpoint = m_PreviousPosition - Vector3D(m_NewPosition.GetX(), tray.GetIndices().at(0).GetY(), m_NewPosition.GetZ());

			while (true)
			{
				if ((m_NewPosition - Vector3D(m_NewPosition.GetX(), tray.GetIndices().at(0).GetY(), m_NewPosition.GetZ())).Length() > m_Radius)
				{
					if (tray.GetFrictionBool())
					{
						ApplyFriction(collisionNormal, tray.GetVelocity(), dt);
					}

					ApplyElasticity(collisionNormal);

					return;
				}
				else
				{
					m_NewPosition += midpoint * 0.001;
				}
			}
		}
	}
	else
	{
		if (tray.GetIndices().at(0).GetX() == tray.GetIndices().at(1).GetX() && tray.GetIndices().at(1).GetX() == tray.GetIndices().at(2).GetX() && tray.GetIndices().at(2).GetX() == tray.GetIndices().at(3).GetX())
		{
			Vector3D collisionNormal = (m_NewPosition - Vector3D(tray.GetIndices().at(0).GetX(), m_NewPosition.GetY(), m_NewPosition.GetZ())).Normalise();

			double forceMagnitude = m_NewVelocity.DotProduct(collisionNormal) * 2.0;

			m_NewVelocity -= forceMagnitude * collisionNormal;

			Vector3D midpoint = m_PreviousPosition - Vector3D(tray.GetIndices().at(0).GetX(), m_NewPosition.GetY(), m_NewPosition.GetZ());

			while (true)
			{
				if ((m_NewPosition - Vector3D(tray.GetIndices().at(0).GetX(), m_NewPosition.GetY(), m_NewPosition.GetZ())).Length() > m_Radius)
				{
					if (tray.GetFrictionBool())
					{
						ApplyFriction(collisionNormal, tray.GetVelocity(), dt);
					}

					ApplyElasticity(collisionNormal);

					return;
				}
				else
				{
					m_NewPosition += midpoint * 0.001;
				}
			}
		}
		else
		{
			Vector3D collisionNormal = (m_NewPosition - Vector3D(m_NewPosition.GetX(), m_NewPosition.GetY(), tray.GetIndices().at(0).GetZ())).Normalise();

			double forceMagnitude = m_NewVelocity.DotProduct(collisionNormal) * 2.0;

			m_NewVelocity -= forceMagnitude * collisionNormal;

			Vector3D midpoint = m_PreviousPosition - Vector3D(m_NewPosition.GetX(), m_NewPosition.GetY(), tray.GetIndices().at(0).GetZ());

			while (true)
			{
				if ((m_NewPosition - Vector3D(m_NewPosition.GetX(), m_NewPosition.GetY(), tray.GetIndices().at(0).GetZ())).Length() > m_Radius)
				{
					if (tray.GetFrictionBool())
					{
						ApplyFriction(collisionNormal, tray.GetVelocity(), dt);
					}

					ApplyElasticity(collisionNormal);

					return;
				}
				else
				{
					m_NewPosition += midpoint * 0.001;
				}
			}
		}
	}
}

void Cube::TrayDetectionAndResponce(const Box &box, const double dt)
{
	for (unsigned int i = 0; i < box.GetTrays().size(); i++)
	{
		if (TrayDetection(*box.GetTrays().at(i)))
		{
			TrayResponce(*box.GetTrays().at(i), dt);
		}
	}
}

void Cube::UpdateObjectPhysics()
{
	if (m_Velocity.Length() < 0.001)
	{
		if (!m_CheckBool)
		{
			m_NewVelocity = Vector3D(0.0, 0.0, 0.0);
			m_NewPosition = m_PreviousPosition;
		}

		m_Colour = Vector3D(0.0, 0.0, 1.0);

		m_CheckBool = false;
	}
	else
	{
		m_Colour = Vector3D(1.0, 0.0, 0.0);

		m_CheckBool = true;
	}

	m_Position = m_NewPosition;

	if (*m_FallBool)
	{
		if (m_Position.GetX() < -50.0 || m_Position.GetX() > 50.0)
		{
			m_Position.SetX(0.0);
		}

		if (m_Position.GetY() < -150.0)
		{
			m_Position.SetY(0.0);
		}

		if (m_Position.GetZ() < -50.0 || m_Position.GetZ() > 50.0)
		{
			m_Position.SetZ(0.0);
		}
	}

	m_Velocity = m_NewVelocity;

	m_Rotation.SetX(m_Rotation.GetX() + ((m_Position.GetZ() - m_PreviousPosition.GetZ()) / ((m_Radius * 2.0) * 3.1415926535897932384626433832795)) * 360);
	m_Rotation.SetZ(m_Rotation.GetZ() + ((m_Position.GetX() - m_PreviousPosition.GetX()) / ((m_Radius * 2.0) * 3.1415926535897932384626433832795)) * 360);
}

void Cube::Render() const
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glTranslatef(static_cast<GLfloat>(m_Position.GetX()), static_cast<GLfloat>(m_Position.GetY()), static_cast<GLfloat>(m_Position.GetZ()));

	glRotatef(static_cast<GLfloat>(m_Rotation.GetX()), 1, 0, 0);
	glRotatef(static_cast<GLfloat>(-(m_Rotation.GetZ())), 0, 0, 1);

	glBegin(GL_LINE_STRIP);

	glColor3d(m_Colour.GetX(), m_Colour.GetY(), m_Colour.GetZ());

	glVertex3d(m_Indices.at(0)->GetX(), m_Indices.at(0)->GetY(), m_Indices.at(0)->GetZ());
	glVertex3d(m_Indices.at(1)->GetX(), m_Indices.at(1)->GetY(), m_Indices.at(1)->GetZ());
	glVertex3d(m_Indices.at(2)->GetX(), m_Indices.at(2)->GetY(), m_Indices.at(2)->GetZ());
	glVertex3d(m_Indices.at(3)->GetX(), m_Indices.at(3)->GetY(), m_Indices.at(3)->GetZ());
	glVertex3d(m_Indices.at(0)->GetX(), m_Indices.at(0)->GetY(), m_Indices.at(0)->GetZ());
	glVertex3d(m_Indices.at(2)->GetX(), m_Indices.at(2)->GetY(), m_Indices.at(2)->GetZ());
	glVertex3d(m_Indices.at(3)->GetX(), m_Indices.at(3)->GetY(), m_Indices.at(3)->GetZ());
	glVertex3d(m_Indices.at(1)->GetX(), m_Indices.at(1)->GetY(), m_Indices.at(1)->GetZ());

	glEnd();

	glBegin(GL_LINE_STRIP);

	glColor3d(m_Colour.GetX(), m_Colour.GetY(), m_Colour.GetZ());

	glVertex3d(m_Indices.at(4)->GetX(), m_Indices.at(4)->GetY(), m_Indices.at(4)->GetZ());
	glVertex3d(m_Indices.at(5)->GetX(), m_Indices.at(5)->GetY(), m_Indices.at(5)->GetZ());
	glVertex3d(m_Indices.at(6)->GetX(), m_Indices.at(6)->GetY(), m_Indices.at(6)->GetZ());
	glVertex3d(m_Indices.at(7)->GetX(), m_Indices.at(7)->GetY(), m_Indices.at(7)->GetZ());
	glVertex3d(m_Indices.at(4)->GetX(), m_Indices.at(4)->GetY(), m_Indices.at(4)->GetZ());
	glVertex3d(m_Indices.at(6)->GetX(), m_Indices.at(6)->GetY(), m_Indices.at(6)->GetZ());
	glVertex3d(m_Indices.at(7)->GetX(), m_Indices.at(7)->GetY(), m_Indices.at(7)->GetZ());
	glVertex3d(m_Indices.at(5)->GetX(), m_Indices.at(5)->GetY(), m_Indices.at(5)->GetZ());

	glEnd();

	glBegin(GL_LINE_STRIP);

	glColor3d(m_Colour.GetX(), m_Colour.GetY(), m_Colour.GetZ());

	glVertex3d(m_Indices.at(0)->GetX(), m_Indices.at(0)->GetY(), m_Indices.at(0)->GetZ());
	glVertex3d(m_Indices.at(4)->GetX(), m_Indices.at(4)->GetY(), m_Indices.at(4)->GetZ());
	glVertex3d(m_Indices.at(3)->GetX(), m_Indices.at(3)->GetY(), m_Indices.at(3)->GetZ());
	glVertex3d(m_Indices.at(7)->GetX(), m_Indices.at(7)->GetY(), m_Indices.at(7)->GetZ());
	glVertex3d(m_Indices.at(1)->GetX(), m_Indices.at(1)->GetY(), m_Indices.at(1)->GetZ());
	glVertex3d(m_Indices.at(5)->GetX(), m_Indices.at(5)->GetY(), m_Indices.at(5)->GetZ());
	glVertex3d(m_Indices.at(2)->GetX(), m_Indices.at(2)->GetY(), m_Indices.at(2)->GetZ());
	glVertex3d(m_Indices.at(6)->GetX(), m_Indices.at(6)->GetY(), m_Indices.at(6)->GetZ());
	glVertex3d(m_Indices.at(0)->GetX(), m_Indices.at(0)->GetY(), m_Indices.at(0)->GetZ());
	glVertex3d(m_Indices.at(7)->GetX(), m_Indices.at(7)->GetY(), m_Indices.at(7)->GetZ());
	glVertex3d(m_Indices.at(3)->GetX(), m_Indices.at(3)->GetY(), m_Indices.at(3)->GetZ());
	glVertex3d(m_Indices.at(5)->GetX(), m_Indices.at(5)->GetY(), m_Indices.at(5)->GetZ());
	glVertex3d(m_Indices.at(1)->GetX(), m_Indices.at(1)->GetY(), m_Indices.at(1)->GetZ());
	glVertex3d(m_Indices.at(6)->GetX(), m_Indices.at(6)->GetY(), m_Indices.at(6)->GetZ());
	glVertex3d(m_Indices.at(2)->GetX(), m_Indices.at(2)->GetY(), m_Indices.at(2)->GetZ());
	glVertex3d(m_Indices.at(4)->GetX(), m_Indices.at(4)->GetY(), m_Indices.at(4)->GetZ());

	glEnd();

	glPopMatrix();
	glEnd();
}