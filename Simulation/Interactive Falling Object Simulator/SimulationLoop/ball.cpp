#include "ball.h"

Ball::Ball()
{
	m_Texture =
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

	m_Texture = TextureLoader::LoadBMP("checker.bmp");

	m_Position = Vector3D(0.0, 40.0, 0.0);

	long long seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 engine(static_cast<unsigned int>(seed));
	_Binder<_Unforced, uniform_real_distribution<>, mt19937 &> random = bind(uniform_real_distribution<double>(-1.0, 1.0), engine);

	m_Velocity = Vector3D(random(), 0.0, random());
	m_Acceleration = Vector3D(0.0, -981.0, 0.0);
	m_Rotation = Vector3D(0.0, 0.0, 0.0);
	m_Colour = Vector3D(1.0, 0.0, 0.0);

	m_CheckBool = true;

	m_Radius = 5.0;
	m_Mass = 20.0;
}

Ball::Ball(bool &integrationBool, double &friction, double &elasticity, bool &fallBool)
{
	m_Texture =
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

	m_Texture = TextureLoader::LoadBMP("checker.bmp");

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

	m_Radius = 5.0;
	m_Mass = 20.0;

	m_Friction = &friction;
	m_Elasticity = &elasticity;
}

Ball::Ball(const Ball &ball)
{
	m_Texture = ball.GetTexture();
	m_Position = ball.GetPosition();
	m_NewPosition = ball.GetNewPosition();
	m_PreviousPosition = ball.GetPreviousPosition();
	m_Velocity = ball.GetVelocity();
	m_NewVelocity = ball.GetNewVelocity();
	m_Acceleration = ball.GetAcceleration();
	m_Rotation = ball.GetRotation();
	m_Colour = ball.GetColour();

	m_IntegrationBool = ball.GetIntegrationBool();
	m_FallBool = ball.GetFallBool();

	m_CheckBool = ball.GetCheckBool();

	m_Friction = ball.GetFriction();
	m_Elasticity = ball.GetElasticity();

	m_Radius = ball.GetRadius();
	m_Mass = ball.GetMass();
}

Ball & Ball::operator = (const Ball &ball)
{
	m_Texture = ball.GetTexture();
	m_Position = ball.GetPosition();
	m_NewPosition = ball.GetNewPosition();
	m_PreviousPosition = ball.GetPreviousPosition();
	m_Velocity = ball.GetVelocity();
	m_NewVelocity = ball.GetNewVelocity();
	m_Acceleration = ball.GetAcceleration();
	m_Rotation = ball.GetRotation();
	m_Colour = ball.GetColour();

	m_IntegrationBool = ball.GetIntegrationBool();
	m_FallBool = ball.GetFallBool();

	m_CheckBool = ball.GetCheckBool();

	m_Friction = ball.GetFriction();
	m_Elasticity = ball.GetElasticity();

	m_Radius = ball.GetRadius();
	m_Mass = ball.GetMass();

	return *this;
}

Ball::Ball(Ball &&ball)
{
	m_Texture = ball.GetTexture();
	m_Position = ball.GetPosition();
	m_NewPosition = ball.GetNewPosition();
	m_PreviousPosition = ball.GetPreviousPosition();
	m_Velocity = ball.GetVelocity();
	m_NewVelocity = ball.GetNewVelocity();
	m_Acceleration = ball.GetAcceleration();
	m_Rotation = ball.GetRotation();
	m_Colour = ball.GetColour();

	m_IntegrationBool = ball.GetIntegrationBool();
	m_FallBool = ball.GetFallBool();

	m_CheckBool = ball.GetCheckBool();

	m_Friction = ball.GetFriction();
	m_Elasticity = ball.GetElasticity();

	m_Radius = ball.GetRadius();
	m_Mass = ball.GetMass();
}

Ball & Ball::operator = (Ball &&ball)
{
	m_Texture = ball.GetTexture();
	m_Position = ball.GetPosition();
	m_NewPosition = ball.GetNewPosition();
	m_PreviousPosition = ball.GetPreviousPosition();
	m_Velocity = ball.GetVelocity();
	m_NewVelocity = ball.GetNewVelocity();
	m_Acceleration = ball.GetAcceleration();
	m_Rotation = ball.GetRotation();
	m_Colour = ball.GetColour();

	m_IntegrationBool = ball.GetIntegrationBool();
	m_FallBool = ball.GetFallBool();

	m_CheckBool = ball.GetCheckBool();

	m_Friction = ball.GetFriction();
	m_Elasticity = ball.GetElasticity();

	m_Radius = ball.GetRadius();
	m_Mass = ball.GetMass();

	return *this;
}

Ball::~Ball()
{

}

const Vector3D Ball::Integration(const Vector3D &start, const Vector3D &increment, double dt)
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

void Ball::CalculateObjectPhysics(const double dt)
{
	m_PreviousPosition = m_Position;

	m_NewVelocity = Integration(m_Velocity, m_Acceleration, dt);
	m_NewPosition = Integration(m_Position, m_NewVelocity, dt);
}

void Ball::DynamicCollisionDetection(Ball *ball, vector<BallContactManifold *> &ballContactManifold)
{
	if ((m_NewPosition - ball->GetNewPosition()).Length() < m_Radius + ball->GetRadius())
	{
		ballContactManifold.push_back(new BallContactManifold(this, ball));
	}
}

void Ball::DynamicCollisionDetection(Cube *cube, vector<BallCubeContactManifold *> &ballCubeContactManifold)
{
	if ((m_NewPosition - cube->GetNewPosition()).Length() < m_Radius + cube->GetRadius())
	{
		ballCubeContactManifold.push_back(new BallCubeContactManifold(this, cube));
	}
}

void Ball::ApplyFriction(const Vector3D &collisionNormal)
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

void Ball::ApplyFriction(const Vector3D &collisionNormal, const Vector3D &velocity, double dt)
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

void Ball::ApplyElasticity(Vector3D collisionNormal)
{
	m_NewVelocity *= (Vector3D(fabs(collisionNormal.GetX()), fabs(collisionNormal.GetY()), fabs(collisionNormal.GetZ())) * log10((*m_Elasticity * 10.0))) + Vector3D(-(fabs(collisionNormal.GetX()) - 1.0), -(fabs(collisionNormal.GetY()) - 1.0), -(fabs(collisionNormal.GetZ()) - 1.0));

	if (m_NewVelocity.GetY() > -50.0 && m_NewVelocity.GetY() < 50.0)
	{
		m_NewVelocity.SetY(0.0);
	}
}

void Ball::DynamicCollisionResponse(const BallContactManifold &ballContactManifold, double dt)
{
	Vector3D collisionNormal = (ballContactManifold.GetBall1()->GetNewPosition() - ballContactManifold.GetBall2()->GetNewPosition()).Normalise();

	double forceMagnitude = ((ballContactManifold.GetBall1()->GetNewVelocity().DotProduct(collisionNormal) - ballContactManifold.GetBall2()->GetNewVelocity().DotProduct(collisionNormal)) * 2.0) / (ballContactManifold.GetBall1()->GetMass() + ballContactManifold.GetBall1()->GetMass());

	ballContactManifold.GetBall1()->SetNewVelocity(ballContactManifold.GetBall1()->GetNewVelocity() - ((forceMagnitude * ballContactManifold.GetBall2()->GetMass()) * collisionNormal));
	ballContactManifold.GetBall2()->SetNewVelocity(ballContactManifold.GetBall2()->GetNewVelocity() + ((forceMagnitude * ballContactManifold.GetBall1()->GetMass()) * collisionNormal));

	Vector3D midpoint = ballContactManifold.GetBall1()->GetPreviousPosition() - ballContactManifold.GetBall2()->GetPreviousPosition();

	while (true)
	{
		if ((ballContactManifold.GetBall1()->GetNewPosition() - ballContactManifold.GetBall2()->GetNewPosition()).Length() > ballContactManifold.GetBall1()->GetRadius() + ballContactManifold.GetBall2()->GetRadius())
		{
			ApplyFriction(collisionNormal);
			ApplyElasticity(collisionNormal);

			ballContactManifold.GetBall1()->SetCheckBool(true);
			ballContactManifold.GetBall2()->SetCheckBool(true);

			return;
		}
		else
		{
			ballContactManifold.GetBall1()->SetNewPosition(ballContactManifold.GetBall1()->GetNewPosition() + (midpoint * 0.001));
			ballContactManifold.GetBall2()->SetNewPosition(ballContactManifold.GetBall2()->GetNewPosition() - (midpoint * 0.001));
		}
	}
}

void Ball::DynamicCollisionResponse(const BallCubeContactManifold &ballCubeContactManifold, double dt)
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

const bool Ball::NetDetection(const Vector3D &position)
{
	return (m_NewPosition - position).Length() < m_Radius;
}

void Ball::NetResponce(const Vector3D &position, double dt)
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

void Ball::NetDetectionAndResponce(const Bowl &bowl, double dt)
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

const bool Ball::BowlDetection(const Vector3D &position, double radius)
{
	return (m_NewPosition - position).Length() > radius - m_Radius;
}

void Ball::BowlResponce(const Vector3D &position, double radius, double dt)
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

void Ball::BowlDetectionAndResponce(const Bowl &bowl, double dt)
{
	if (BowlDetection(bowl.GetPosition(), bowl.GetRadius()))
	{
		BowlResponce(bowl.GetPosition(), bowl.GetRadius(), dt);
	}
}

const bool Ball::TrayDetection(const Tray &tray)
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

void Ball::TrayResponce(const Tray &tray, double dt)
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

void Ball::TrayDetectionAndResponce(const Box &box, double dt)
{
	for (unsigned int i = 0; i < box.GetTrays().size(); i++)
	{
		if (TrayDetection(*box.GetTrays().at(i)))
		{
			TrayResponce(*box.GetTrays().at(i), dt);
		}
	}
}

void Ball::UpdateObjectPhysics()
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

void Ball::Render() const
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glTranslatef(static_cast<GLfloat>(m_Position.GetX()), static_cast<GLfloat>(m_Position.GetY()), static_cast<GLfloat>(m_Position.GetZ()));

	glRotatef(static_cast<GLfloat>(m_Rotation.GetX()), 1, 0, 0);
	glRotatef(static_cast<GLfloat>(-(m_Rotation.GetZ())), 0, 0, 1);

	glColor3d(m_Colour.GetX(), m_Colour.GetY(), m_Colour.GetZ());

	glBindTexture(GL_TEXTURE_2D, m_Texture);	// Select Our Texture

	GLUquadric *quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);

	gluSphere(quadric, m_Radius, 20, 20);

	glPopMatrix();
	glEnd();
}