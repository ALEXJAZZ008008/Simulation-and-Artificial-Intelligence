#include "simulation.h"

Simulation::Simulation()
{
	m_HDC =
	{

	};

	m_Bowl = nullptr;
	m_Box = nullptr;

	m_Balls =
	{

	};

	m_BallContactManifold =
	{

	};

	m_BallCubeContactManifold =
	{

	};

	m_Cubes =
	{

	};

	m_CubeContactManifold =
	{

	};

	m_CameraPosition =
	{

	};
	
	m_CameraRotation =
	{

	};

	m_Start =
	{

	};
	
	m_End =
	{

	};
	
	m_Frequency =
	{

	};

	m_ChangedBool = false;
	m_CheckBool = false; 
	m_PauseSimulationBool = false; 
	m_IntegrationBool = false; 
	m_NetBool = false; 
	m_FallBool = false; 
	m_CameraPositionBool = false; 
	m_CameraObjectBool = false; 
	m_DirectionBool = false;

	m_DT = 0.0;
	m_TimeScale = 0.0; 
	m_Time = 0.0; 
	m_PreviousTime = 0.0; 
	m_FPS = 0.0; 
	m_Friction = 0.0; 
	m_Elasticity = 0.0; 
	m_RandomObject = 0.0;

	m_Bowl = new Bowl(Vector3D(0.0, 0.0, 0.0), 200.0);
	m_Box = new Box();

	m_CameraPosition = Vector3D(0.0, 0.0, 0.0);
	m_CameraRotation = Vector3D(0.0, 0.0, 0.0);

	m_ChangedBool = true;
	m_CheckBool = true;
	m_PauseSimulationBool = false;
	m_IntegrationBool = true;
	m_NetBool = false;
	m_FallBool = false;
	m_CameraPositionBool = true;
	m_CameraObjectBool = true;
	m_DirectionBool = true;

	m_DT = 0.0;
	m_TimeScale = 1.0;
	m_Time = 0.0;
	m_PreviousTime = 0.0;
	m_FPS = 0.0;
	m_Friction = 0.5;
	m_Elasticity = 0.5;

	QueryPerformanceCounter(&m_Start);
	QueryPerformanceFrequency(&m_Frequency);
}

Simulation::Simulation(HDC hdc)
{
	m_HDC =
	{

	};

	m_Bowl = nullptr;
	m_Box = nullptr;

	m_Balls =
	{

	};

	m_BallContactManifold =
	{

	};

	m_BallCubeContactManifold =
	{

	};

	m_Cubes =
	{

	};

	m_CubeContactManifold =
	{

	};

	m_CameraPosition =
	{

	};

	m_CameraRotation =
	{

	};

	m_Start =
	{

	};

	m_End =
	{

	};

	m_Frequency =
	{

	};

	m_ChangedBool = false;
	m_CheckBool = false;
	m_PauseSimulationBool = false;
	m_IntegrationBool = false;
	m_NetBool = false;
	m_FallBool = false;
	m_CameraPositionBool = false;
	m_CameraObjectBool = false;
	m_DirectionBool = false;

	m_DT = 0.0;
	m_TimeScale = 0.0;
	m_Time = 0.0;
	m_PreviousTime = 0.0;
	m_FPS = 0.0;
	m_Friction = 0.0;
	m_Elasticity = 0.0;
	m_RandomObject = 0.0;

	m_HDC = hdc;

	m_Bowl = new Bowl(Vector3D(0.0, 0.0, 0.0), 200.0);
	m_Box = new Box();

	m_CameraPosition = Vector3D(0.0, 0.0, 0.0);
	m_CameraRotation = Vector3D(0.0, 0.0, 0.0);

	m_ChangedBool = true;
	m_CheckBool = true;
	m_PauseSimulationBool = false;
	m_IntegrationBool = true;
	m_NetBool = false;
	m_FallBool = false;
	m_CameraPositionBool = true;
	m_CameraObjectBool = true;
	m_DirectionBool = true;

	m_DT = 0.0;
	m_TimeScale = 1.0;
	m_Time = 0.0;
	m_PreviousTime = 0.0;
	m_FPS = 0.0;
	m_Friction = 0.5;
	m_Elasticity = 0.5;

	QueryPerformanceCounter(&m_Start);
	QueryPerformanceFrequency(&m_Frequency);
}

Simulation::Simulation(const Simulation &simulation)
{
	m_HDC = simulation.GetHDC();

	m_Bowl = simulation.GetBowl();
	m_Box = simulation.GetBox();

	m_Balls = simulation.GetBalls();
	m_BallContactManifold = simulation.GetBallContactManifold();
	m_BallCubeContactManifold = simulation.GetBallCubeContactManifold();
	m_Cubes = simulation.GetCubes();
	m_CubeContactManifold = simulation.GetCubeContactManifold();
	m_CameraPosition = simulation.GetCameraPosition();
	m_CameraRotation = simulation.GetCameraRotation();
	m_Start = simulation.GetStart();
	m_End = simulation.GetEnd();
	m_Frequency = simulation.GetFrequency();

	m_ChangedBool = simulation.GetChangedBool();
	m_CheckBool = simulation.GetCheckBool();
	m_PauseSimulationBool = simulation.GetPauseSimulationBool();
	m_IntegrationBool = simulation.GetIntegrationBool();
	m_NetBool = simulation.GetNetBool();
	m_FallBool = simulation.GetFallBool();
	m_CameraPositionBool = simulation.GetCameraPositionBool();
	m_CameraObjectBool = simulation.GetCameraObjectBool();
	m_DirectionBool = simulation.GetDirectionBool();

	m_DT = simulation.GetDT();
	m_TimeScale = simulation.GetTimeScale();
	m_Time = simulation.GetTime();
	m_PreviousTime = simulation.GetPreviousTime();
	m_FPS = simulation.GetFPS();
	m_Friction = simulation.GetFriction();
	m_Elasticity = simulation.GetElasticity();
	m_RandomObject = simulation.GetRandomObject();
}

Simulation & Simulation::operator = (const Simulation &simulation)
{
	m_HDC = simulation.GetHDC();

	m_Bowl = simulation.GetBowl();
	m_Box = simulation.GetBox();

	m_Balls = simulation.GetBalls();
	m_BallContactManifold = simulation.GetBallContactManifold();
	m_BallCubeContactManifold = simulation.GetBallCubeContactManifold();
	m_Cubes = simulation.GetCubes();
	m_CubeContactManifold = simulation.GetCubeContactManifold();
	m_CameraPosition = simulation.GetCameraPosition();
	m_CameraRotation = simulation.GetCameraRotation();
	m_Start = simulation.GetStart();
	m_End = simulation.GetEnd();
	m_Frequency = simulation.GetFrequency();

	m_ChangedBool = simulation.GetChangedBool();
	m_CheckBool = simulation.GetCheckBool();
	m_PauseSimulationBool = simulation.GetPauseSimulationBool();
	m_IntegrationBool = simulation.GetIntegrationBool();
	m_NetBool = simulation.GetNetBool();
	m_FallBool = simulation.GetFallBool();
	m_CameraPositionBool = simulation.GetCameraPositionBool();
	m_CameraObjectBool = simulation.GetCameraObjectBool();
	m_DirectionBool = simulation.GetDirectionBool();

	m_DT = simulation.GetDT();
	m_TimeScale = simulation.GetTimeScale();
	m_Time = simulation.GetTime();
	m_PreviousTime = simulation.GetPreviousTime();
	m_FPS = simulation.GetFPS();
	m_Friction = simulation.GetFriction();
	m_Elasticity = simulation.GetElasticity();
	m_RandomObject = simulation.GetRandomObject();

	return *this;
}

Simulation::Simulation(Simulation &&simulation)
{
	m_HDC = simulation.GetHDC();

	m_Bowl = simulation.GetBowl();
	m_Box = simulation.GetBox();

	m_Balls = simulation.GetBalls();
	m_BallContactManifold = simulation.GetBallContactManifold();
	m_BallCubeContactManifold = simulation.GetBallCubeContactManifold();
	m_Cubes = simulation.GetCubes();
	m_CubeContactManifold = simulation.GetCubeContactManifold();
	m_CameraPosition = simulation.GetCameraPosition();
	m_CameraRotation = simulation.GetCameraRotation();
	m_Start = simulation.GetStart();
	m_End = simulation.GetEnd();
	m_Frequency = simulation.GetFrequency();

	m_ChangedBool = simulation.GetChangedBool();
	m_CheckBool = simulation.GetCheckBool();
	m_PauseSimulationBool = simulation.GetPauseSimulationBool();
	m_IntegrationBool = simulation.GetIntegrationBool();
	m_NetBool = simulation.GetNetBool();
	m_FallBool = simulation.GetFallBool();
	m_CameraPositionBool = simulation.GetCameraPositionBool();
	m_CameraObjectBool = simulation.GetCameraObjectBool();
	m_DirectionBool = simulation.GetDirectionBool();

	m_DT = simulation.GetDT();
	m_TimeScale = simulation.GetTimeScale();
	m_Time = simulation.GetTime();
	m_PreviousTime = simulation.GetPreviousTime();
	m_FPS = simulation.GetFPS();
	m_Friction = simulation.GetFriction();
	m_Elasticity = simulation.GetElasticity();
	m_RandomObject = simulation.GetRandomObject();
}

Simulation & Simulation::operator = (Simulation &&simulation)
{
	m_HDC = simulation.GetHDC();

	m_Bowl = simulation.GetBowl();
	m_Box = simulation.GetBox();

	m_Balls = simulation.GetBalls();
	m_BallContactManifold = simulation.GetBallContactManifold();
	m_BallCubeContactManifold = simulation.GetBallCubeContactManifold();
	m_Cubes = simulation.GetCubes();
	m_CubeContactManifold = simulation.GetCubeContactManifold();
	m_CameraPosition = simulation.GetCameraPosition();
	m_CameraRotation = simulation.GetCameraRotation();
	m_Start = simulation.GetStart();
	m_End = simulation.GetEnd();
	m_Frequency = simulation.GetFrequency();

	m_ChangedBool = simulation.GetChangedBool();
	m_CheckBool = simulation.GetCheckBool();
	m_PauseSimulationBool = simulation.GetPauseSimulationBool();
	m_IntegrationBool = simulation.GetIntegrationBool();
	m_NetBool = simulation.GetNetBool();
	m_FallBool = simulation.GetFallBool();
	m_CameraPositionBool = simulation.GetCameraPositionBool();
	m_CameraObjectBool = simulation.GetCameraObjectBool();
	m_DirectionBool = simulation.GetDirectionBool();

	m_DT = simulation.GetDT();
	m_TimeScale = simulation.GetTimeScale();
	m_Time = simulation.GetTime();
	m_PreviousTime = simulation.GetPreviousTime();
	m_FPS = simulation.GetFPS();
	m_Friction = simulation.GetFriction();
	m_Elasticity = simulation.GetElasticity();
	m_RandomObject = simulation.GetRandomObject();

	return *this;
}

Simulation::~Simulation()
{
	delete m_Bowl;
	delete m_Box;

	for (unsigned int i = 0; i < m_Balls.size(); i++)
	{
		delete m_Balls.at(i);
	}

	for (unsigned int i = 0; i < m_Cubes.size(); i++)
	{
		delete m_Cubes.at(i);
	}

	for (unsigned int i = 0; i < m_BallContactManifold.size(); i++)
	{
		delete m_BallContactManifold.at(i);
	}

	for (unsigned int i = 0; i < m_BallCubeContactManifold.size(); i++)
	{
		delete m_BallCubeContactManifold.at(i);
	}

	for (unsigned int i = 0; i < m_CubeContactManifold.size(); i++)
	{
		delete m_CubeContactManifold.at(i);
	}
}

void Simulation::SetCheckBools()
{
	for (unsigned int i = 0; i < m_Balls.size(); i++)
	{
		m_Balls.at(i)->SetCheckBool(true);
	}

	for (unsigned int i = 0; i < m_Cubes.size(); i++)
	{
		m_Cubes.at(i)->SetCheckBool(true);
	}
}

void Simulation::CheckMoving()
{
	if (m_Box->GetTrays().at(4)->GetMovingBool() || m_Box->GetTrays().at(6)->GetMovingBool() || m_CheckBool)
	{
		SetCheckBools();

		m_CheckBool = false;
	}
}

//**************************Update the physics calculations on each object***********************
void Simulation::CalculateObjectPhysics()
{
	if (m_NetBool)
	{
		m_Bowl->CalculateObjectPhysics(m_DT);
	}

	m_Box->CalculateObjectPhysics(m_DT);

	for (unsigned int i = 0; i < m_Balls.size(); i++)
	{
		m_Balls.at(i)->CalculateObjectPhysics(m_DT);
	}

	for (unsigned int i = 0; i < m_Cubes.size(); i++)
	{
		m_Cubes.at(i)->CalculateObjectPhysics(m_DT);
	}
}

//**************************Handle dynamic collisions***********************
void Simulation::DynamicCollisionDetection()
{
	for (unsigned int i = 0; i < m_Balls.size(); i++)
	{
		if (m_Balls.at(i)->GetCheckBool())
		{
			for (unsigned int j = i + 1; j < m_Balls.size(); j++)
			{
				m_Balls.at(i)->DynamicCollisionDetection(m_Balls.at(j), m_BallContactManifold);
			}
		}
	}

	for (unsigned int i = 0; i < m_Balls.size(); i++)
	{
		if (m_Balls.at(i)->GetCheckBool())
		{
			for (unsigned int j = 0; j < m_Cubes.size(); j++)
			{
				m_Balls.at(i)->DynamicCollisionDetection(m_Cubes.at(j), m_BallCubeContactManifold);
			}
		}
	}

	for (unsigned int i = 0; i < m_Cubes.size(); i++)
	{
		for (unsigned int j = i + 1; j < m_Cubes.size(); j++)
		{
			m_Cubes.at(i)->DynamicCollisionDetection(m_Cubes.at(j), m_CubeContactManifold);
		}
	}

	for (unsigned int i = 0; i < m_Cubes.size(); i++)
	{
		for (unsigned int j = 0; j < m_Balls.size(); j++)
		{
			m_Cubes.at(i)->DynamicCollisionDetection(m_Balls.at(j), m_BallCubeContactManifold);
		}
	}
}

//**************************Handle dynamic collision responses***********************
void Simulation::DynamicCollisionResponse()
{
	for (unsigned int i = 0; i < m_BallContactManifold.size(); ++i)
	{
		m_BallContactManifold.at(i)->GetBall1()->DynamicCollisionResponse(*m_BallContactManifold.at(i), m_DT);
	}

	for (unsigned int i = 0; i < m_CubeContactManifold.size(); ++i)
	{
		m_CubeContactManifold.at(i)->GetCube1()->DynamicCollisionResponse(*m_CubeContactManifold.at(i), m_DT);
	}

	for (unsigned int i = 0; i < m_BallCubeContactManifold.size(); ++i)
	{
		m_BallCubeContactManifold.at(i)->GetBall()->DynamicCollisionResponse(*m_BallCubeContactManifold.at(i), m_DT);
	}
}

void Simulation::BowlDetectionAndResponce()
{
	if (m_NetBool)
	{
		for (unsigned int i = 0; i < m_Balls.size(); i++)
		{
			if (m_Balls.at(i)->GetCheckBool() && m_Balls.at(i)->GetNewPosition().GetY() < -150.0)
			{
				m_Balls.at(i)->NetDetectionAndResponce(*m_Bowl, m_DT);
			}
		}

		for (unsigned int i = 0; i < m_Cubes.size(); i++)
		{
			if (m_Cubes.at(i)->GetCheckBool() && m_Cubes.at(i)->GetNewPosition().GetY() < -150.0)
			{
				m_Cubes.at(i)->NetDetectionAndResponce(*m_Bowl, m_DT);
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < m_Balls.size(); i++)
		{
			if (m_Balls.at(i)->GetCheckBool() && m_Balls.at(i)->GetNewPosition().GetX() > -100.0 && m_Balls.at(i)->GetNewPosition().GetX() < 100.0 && m_Balls.at(i)->GetNewPosition().GetY() < -150.0 && m_Balls.at(i)->GetNewPosition().GetZ() > -100.0 && m_Balls.at(i)->GetNewPosition().GetZ() < 100.0)
			{
				m_Balls.at(i)->BowlDetectionAndResponce(*m_Bowl, m_DT);
			}
		}

		for (unsigned int i = 0; i < m_Cubes.size(); i++)
		{
			if (m_Cubes.at(i)->GetCheckBool() && m_Cubes.at(i)->GetNewPosition().GetX() > -100.0 && m_Cubes.at(i)->GetNewPosition().GetX() < 100.0 && m_Cubes.at(i)->GetNewPosition().GetY() < -150.0 && m_Cubes.at(i)->GetNewPosition().GetZ() > -100.0 && m_Cubes.at(i)->GetNewPosition().GetZ() < 100.0)
			{
				m_Cubes.at(i)->BowlDetectionAndResponce(*m_Bowl, m_DT);
			}
		}
	}
}

void Simulation::TrayDetectionAndResponce()
{
	for (unsigned int i = 0; i < m_Balls.size(); i++)
	{
		if (m_Balls.at(i)->GetCheckBool() && m_Balls.at(i)->GetNewPosition().GetX() > -50.0 && m_Balls.at(i)->GetNewPosition().GetX() < 50.0 && m_Balls.at(i)->GetNewPosition().GetY() > -150.0 && m_Balls.at(i)->GetNewPosition().GetY() < 0.0 && m_Balls.at(i)->GetNewPosition().GetZ() > -50.0 && m_Balls.at(i)->GetNewPosition().GetZ() < 50.0)
		{
			m_Balls.at(i)->TrayDetectionAndResponce(*m_Box, m_DT);
		}
	}

	for (unsigned int i = 0; i < m_Cubes.size(); i++)
	{
		if (m_Cubes.at(i)->GetCheckBool() && m_Cubes.at(i)->GetNewPosition().GetX() > -50.0 && m_Cubes.at(i)->GetNewPosition().GetX() < 50.0 && m_Cubes.at(i)->GetNewPosition().GetY() > -150.0 && m_Cubes.at(i)->GetNewPosition().GetY() < 0.0 && m_Cubes.at(i)->GetNewPosition().GetZ() > -50.0 && m_Cubes.at(i)->GetNewPosition().GetZ() < 50.0)
		{
			m_Cubes.at(i)->TrayDetectionAndResponce(*m_Box, m_DT);
		}
	}
}

//**************************Update the physics calculations on each object***********************
void Simulation::UpdateObjectPhysics()
{
	if (m_NetBool)
	{
		m_Bowl->UpdateObjectPhysics();
	}

	m_Box->UpdateObjectPhysics();

	for (unsigned int i = 0; i < m_Balls.size(); i++)
	{
		m_Balls.at(i)->UpdateObjectPhysics();

		if (m_Balls.at(i)->GetPosition().GetY() < -200.0)
		{
			m_Balls.erase(m_Balls.begin() + i);

			i--;
		}
	}

	for (unsigned int i = 0; i < m_Cubes.size(); i++)
	{
		m_Cubes.at(i)->UpdateObjectPhysics();

		if (m_Cubes.at(i)->GetPosition().GetY() < -200.0)
		{
			m_Cubes.erase(m_Cubes.begin() + i);

			i--;
		}
	}

	reverse(m_Balls.begin(), m_Balls.end());
	reverse(m_Cubes.begin(), m_Cubes.end());

	if (m_DirectionBool)
	{
		m_DirectionBool = false;
	}
	else
	{
		m_DirectionBool = true;
	}
}

void Simulation::SimulationLoop()
{
	// calculate dt based on the simulation loop rate using a timer
	QueryPerformanceCounter(&m_End);

	m_DT = static_cast<double>((m_End.QuadPart - m_Start.QuadPart) / static_cast<double>(m_Frequency.QuadPart));
	m_Time += m_DT;
	m_DT *= m_TimeScale;

	m_FPS = 1.0 / m_DT;

	m_Start = m_End;

	if (!m_PauseSimulationBool)
	{
		CheckMoving();

		// Calculate the physic calculations on all objects (e.g. new position, velocity, etc)
		CalculateObjectPhysics();

		// Clear the manifold so that we can calculate all collisions for this simulation loop
		m_BallContactManifold.clear();
		m_CubeContactManifold.clear();
		m_BallCubeContactManifold.clear();

		// Find dynamic collisions for all objects and add to contact manifold 
		DynamicCollisionDetection();

		// Handle dynamic collision responses using the contact manifold
		DynamicCollisionResponse();

		BowlDetectionAndResponce();

		TrayDetectionAndResponce();

		// Update the physics calculations on all objects (e.g. new position, velocity, etc)
		UpdateObjectPhysics();
	}
}

//**************************Render and display the scene in OpenGL***********************
void Simulation::Render()								// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	gluLookAt(0.0, 0.0, 500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glRotatef(static_cast<GLfloat>(m_CameraRotation.GetX()), 1, 0, 0);
	glRotatef(static_cast<GLfloat>(m_CameraRotation.GetY()), 0, 1, 0);

	if (m_CameraPositionBool)
	{
		glTranslatef(static_cast<GLfloat>(m_CameraPosition.GetX()), static_cast<GLfloat>(m_CameraPosition.GetY() + 80.0), static_cast<GLfloat>(m_CameraPosition.GetZ()));
	}
	else
	{
		if (m_CameraObjectBool)
		{
			if (m_Cubes.size() < 1.0)
			{
				m_CameraPositionBool = true;
				m_CameraObjectBool = true;

				return;
			}

			if (m_DirectionBool)
			{
				glTranslatef(static_cast<GLfloat>(-m_Cubes.at(static_cast<size_t>(m_RandomObject))->GetPosition().GetX()), static_cast<GLfloat>(-m_Cubes.at(static_cast<size_t>(m_RandomObject))->GetPosition().GetY()), static_cast<GLfloat>(-(m_Cubes.at(static_cast<size_t>(m_RandomObject))->GetPosition().GetZ()) + 400));
			}
			else
			{
				glTranslatef(static_cast<GLfloat>(-m_Cubes.at(static_cast<size_t>((m_Cubes.size() - 1) - m_RandomObject))->GetPosition().GetX()), static_cast<GLfloat>(-m_Cubes.at(static_cast<size_t>((m_Cubes.size() - 1) - m_RandomObject))->GetPosition().GetY()), static_cast<GLfloat>(-(m_Cubes.at(static_cast<size_t>((m_Cubes.size() - 1) - m_RandomObject))->GetPosition().GetZ()) + 400));
			}
		}
		else
		{
			if (m_Balls.size() < 1.0)
			{
				m_CameraPositionBool = true;
				m_CameraObjectBool = true;

				return;
			}

			if (m_DirectionBool)
			{
				glTranslatef(static_cast<GLfloat>(-m_Balls.at(static_cast<size_t>(m_RandomObject))->GetPosition().GetX()), static_cast<GLfloat>(-m_Balls.at(static_cast<size_t>(m_RandomObject))->GetPosition().GetY()), static_cast<GLfloat>(-(m_Balls.at(static_cast<size_t>(m_RandomObject))->GetPosition().GetZ()) + 400));
			}
			else
			{
				glTranslatef(static_cast<GLfloat>(-m_Balls.at(static_cast<size_t>((m_Balls.size() - 1) - m_RandomObject))->GetPosition().GetX()), static_cast<GLfloat>(-m_Balls.at(static_cast<size_t>((m_Balls.size() - 1) - m_RandomObject))->GetPosition().GetY()), static_cast<GLfloat>(-(m_Balls.at(static_cast<size_t>((m_Balls.size() - 1) - m_RandomObject))->GetPosition().GetZ()) + 400));
			}
		}
	}

	m_Bowl->Render();
	m_Box->Render();

	for (unsigned int i = 0; i < m_Balls.size(); i++)
	{
		m_Balls.at(i)->Render();
	}

	for (unsigned int i = 0; i < m_Cubes.size(); i++)
	{
		m_Cubes.at(i)->Render();
	}

	SwapBuffers(m_HDC);									// Swap Buffers (Double Buffering)
}

const double Simulation::GetRandomBall() const
{
	long long seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 engine(static_cast<unsigned int>(seed));
	_Binder<_Unforced, uniform_int_distribution<>, mt19937 &> random = bind(uniform_int_distribution<int>(0, m_Balls.size() - 1), engine);

	return random();
}

const double Simulation::GetRandomCube() const
{
	long long seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 engine(static_cast<unsigned int>(seed));
	_Binder<_Unforced, uniform_int_distribution<>, mt19937 &> random = bind(uniform_int_distribution<int>(0, m_Cubes.size() - 1), engine);

	return random();
}

void Simulation::UpdateConsole()
{
	cout << "Frames:\t\t\t" << m_FPS << endl;

	if (m_IntegrationBool)
	{
		cout << "Integration:\t\tRunge Kutta" << endl;
	}
	else
	{
		cout << "Integration:\t\tEuler" << endl;
	}

	cout << "Balls:\t\t\t" << m_Balls.size() << endl;
	cout << "Cubes:\t\t\t" << m_Cubes.size() << endl;
	cout << "Time:\t\t\t" << m_TimeScale << endl;

	cout << "Friction:\t\t" << m_Friction << endl;
	cout << "Elasticity:\t\t" << m_Elasticity << endl;

	if (m_PauseSimulationBool)
	{
		cout << "Paused:\t\t\tTrue" << endl;
	}
	else
	{
		cout << "Paused:\t\t\tFalse" << endl;
	}

	if (m_NetBool)
	{
		cout << "Bowl:\t\t\tNet" << endl;
	}
	else
	{
		cout << "Bowl:\t\t\tBowl" << endl;
	}

	if (m_FallBool)
	{
		cout << "Fall:\t\t\tInfinitely" << endl;
	}
	else
	{
		cout << "Fall:\t\t\tFinitely" << endl;
	}

	if (m_CameraPositionBool)
	{
		cout << "Camera:\t\t\tFree" << endl;
	}
	else
	{
		cout << "Camera:\t\t\tLocked" << endl;
	}

	cout << endl;
}

void Simulation::ResetSimulation()
{
	m_Bowl = new Bowl(Vector3D(0.0, 0.0, 0.0), 200.0);
	m_Box = new Box();

	m_Balls.clear();
	m_BallContactManifold.clear();
	m_BallCubeContactManifold.clear();
	m_Cubes.clear();
	m_CubeContactManifold.clear();

	m_CameraPosition = Vector3D(0.0, 0.0, 0.0);
	m_CameraRotation = Vector3D(0.0, 0.0, 0.0);

	m_CheckBool = true;
	m_PauseSimulationBool = false;
	m_IntegrationBool = true;
	m_NetBool = false;
	m_FallBool = false;
	m_CameraPositionBool = true;
	m_CameraObjectBool = true;

	m_TimeScale = 1.0;
	m_Friction = 0.5;
	m_Elasticity = 0.5;

	m_ChangedBool = true;
}

void Simulation::CameraRotationKeyboardEvents()
{
	if (GetAsyncKeyState('Z'))
	{
		m_CameraRotation.SetX(m_CameraRotation.GetX() + 1.0);
	}

	if (GetAsyncKeyState('X'))
	{
		m_CameraRotation.SetX(m_CameraRotation.GetX() - 1.0);
	}

	if (GetAsyncKeyState('Q'))
	{
		m_CameraRotation.SetY(m_CameraRotation.GetY() + 1.0);
	}

	if (GetAsyncKeyState('E'))
	{
		m_CameraRotation.SetY(m_CameraRotation.GetY() - 1.0);
	}
}

void Simulation::CameraPositionKeyboardEvents()
{
	if (GetAsyncKeyState('W'))
	{
		m_CameraPosition.SetY(m_CameraPosition.GetY() - 1.0);
	}

	if (GetAsyncKeyState('S'))
	{
		m_CameraPosition.SetY(m_CameraPosition.GetY() + 1.0);
	}

	if (GetAsyncKeyState('A'))
	{
		m_CameraPosition.SetX(m_CameraPosition.GetX() + 1.0);
	}

	if (GetAsyncKeyState('D'))
	{
		m_CameraPosition.SetX(m_CameraPosition.GetX() - 1.0);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_CameraPosition.SetZ(m_CameraPosition.GetZ() + 1.0);
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_CameraPosition.SetZ(m_CameraPosition.GetZ() - 1.0);
	}
}

void Simulation::ObjectKeyboardEvents()
{
	if (GetAsyncKeyState('1'))
	{
		m_Balls.push_back(new Ball(m_IntegrationBool, m_Friction, m_Elasticity, m_FallBool));

		m_ChangedBool = true;
	}
	else
	{
		if (GetAsyncKeyState('2'))
		{
			m_Cubes.push_back(new Cube(m_IntegrationBool, m_Friction, m_Elasticity, m_FallBool));

			m_ChangedBool = true;
		}
	}

	if (GetAsyncKeyState('3'))
	{
		m_Box->GetTrays().at(4)->SetVelocity(Vector3D(10.0, 0.0, 0.0));
	}

	if (GetAsyncKeyState('4'))
	{
		m_Box->GetTrays().at(4)->SetVelocity(Vector3D(-20.0, 0.0, 0.0));
	}

	if (GetAsyncKeyState('5'))
	{
		m_Box->GetTrays().at(6)->SetVelocity(Vector3D(10.0, 0.0, 0.0));
	}

	if (GetAsyncKeyState('6'))
	{
		m_Box->GetTrays().at(6)->SetVelocity(Vector3D(-20.0, 0.0, 0.0));
	}

	if (GetAsyncKeyState('R'))
	{
		ResetSimulation();
	}

	if (GetAsyncKeyState('P'))
	{
		if (m_PauseSimulationBool)
		{
			m_PauseSimulationBool = false;
		}
		else
		{
			m_PauseSimulationBool = true;
		}

		m_ChangedBool = true;
	}

	if (GetAsyncKeyState(VK_SHIFT))
	{
		if (m_IntegrationBool)
		{
			m_IntegrationBool = false;
		}
		else
		{
			m_IntegrationBool = true;
		}

		m_ChangedBool = true;
	}

	if (m_Balls.size() > 0)
	{
		if (GetAsyncKeyState(' '))
		{
			if (m_CameraObjectBool)
			{
				if (m_CameraPositionBool)
				{
					m_CameraPositionBool = false;

					m_RandomObject = GetRandomBall();

					m_CameraObjectBool = false;
				}
				else
				{
					m_CameraPositionBool = true;
				}
			}
			else
			{
				if (m_Cubes.size() > 0.0)
				{
					m_RandomObject = GetRandomCube();
				}
				else
				{
					m_CameraPositionBool = true;
				}

				m_CameraObjectBool = true;
			}

			m_ChangedBool = true;
		}
	}
	else
	{
		if (m_Cubes.size() > 0.0)
		{
			if (GetAsyncKeyState(' '))
			{
				if (m_CameraPositionBool)
				{
					m_RandomObject = GetRandomCube();

					m_CameraObjectBool = true;
					m_CameraPositionBool = false;
				}
				else
				{
					m_CameraPositionBool = true;
				}

				m_ChangedBool = true;
			}
		}
	}

	if (GetAsyncKeyState('U'))
	{
		m_TimeScale = m_TimeScale + 0.1;

		m_ChangedBool = true;
	}

	if (GetAsyncKeyState('J'))
	{
		m_TimeScale = m_TimeScale - 0.1;

		m_ChangedBool = true;
	}

	if (GetAsyncKeyState('I'))
	{
		m_Friction = m_Friction + 0.1;

		m_ChangedBool = true;
	}

	if (GetAsyncKeyState('K'))
	{
		m_Friction = m_Friction - 0.1;

		if (m_Friction < 0.0)
		{
			m_Friction = 0.0;
		}
		else
		{
			m_ChangedBool = true;
		}
	}

	if (GetAsyncKeyState('O'))
	{
		m_Elasticity = m_Elasticity + 0.1;

		if (m_Elasticity > 1.0)
		{
			m_Elasticity = 1.0;
		}
		else
		{
			m_ChangedBool = true;
		}
	}

	if (GetAsyncKeyState('L'))
	{
		m_Elasticity = m_Elasticity - 0.1;

		if (m_Elasticity < 0.1)
		{
			m_Elasticity = 0.1;
		}
		else
		{
			m_ChangedBool = true;
		}
	}

	if (GetAsyncKeyState('N'))
	{
		if (m_NetBool)
		{
			m_NetBool = false;
		}
		else
		{
			m_NetBool = true;
		}

		m_ChangedBool = true;
	}

	if (GetAsyncKeyState(VK_MENU))
	{
		if (m_FallBool)
		{
			m_FallBool = false;
		}
		else
		{
			m_FallBool = true;
		}

		m_ChangedBool = true;
	}

	if (GetAsyncKeyState(VK_CONTROL))
	{
		m_ChangedBool = true;

		m_CheckBool = true;
	}
}

void Simulation::KeyboardEventHandler()
{
	CameraRotationKeyboardEvents();

	if (m_CameraPositionBool)
	{
		CameraPositionKeyboardEvents();
	}

	if (m_Time > m_PreviousTime + 0.25)
	{
		m_PreviousTime = m_Time;

		ObjectKeyboardEvents();
	}

	if (m_ChangedBool)
	{
		m_ChangedBool = false;

		thread updateConsole(&Simulation::UpdateConsole, this);
		updateConsole.join();
	}
}

void Simulation::Update()
{
	thread simulationLoop(&Simulation::SimulationLoop, this);
	simulationLoop.join();

	Render();

	KeyboardEventHandler();
}