#pragma once

#include <Windows.h>
#include <gl\gl.h>	// Header File For The OpenGL32 Library
#include <gl\glu.h>	// Header File For The GLu32 Library
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <functional>
#include <vector>
#include <array>
#include "ball.h"
#include "ballContactManifold.h"
#include "ballCubeContactManifold.h"
#include "bowl.h"
#include "box.h"
#include "cube.h"
#include "cubeContactManifold.h"

using namespace std;

class Simulation
{
public:
	Simulation();
	Simulation(HDC hdc);
	Simulation(const Simulation &);
	Simulation & operator = (const Simulation &);
	Simulation(Simulation &&);
	Simulation & operator = (Simulation &&);
	~Simulation();

	const HDC GetHDC() const
	{
		return m_HDC;
	}

	Bowl * GetBowl() const
	{
		return m_Bowl;
	}

	Box * GetBox() const
	{
		return m_Box;
	}

	const vector<Ball *> GetBalls() const
	{
		return m_Balls;
	}

	const vector<BallContactManifold *> GetBallContactManifold() const
	{
		return m_BallContactManifold;
	}

	const vector<BallCubeContactManifold *> GetBallCubeContactManifold() const
	{
		return m_BallCubeContactManifold;
	}

	const vector<Cube *> GetCubes() const
	{
		return m_Cubes;
	}

	const vector<CubeContactManifold *> GetCubeContactManifold() const
	{
		return m_CubeContactManifold;
	}

	const Vector3D GetCameraPosition() const
	{
		return m_CameraPosition;
	}

	const Vector3D GetCameraRotation() const
	{
		return m_CameraRotation;
	}

	const LARGE_INTEGER GetStart() const
	{
		return m_Start;
	}

	const LARGE_INTEGER GetEnd() const
	{
		return m_End;
	}

	const LARGE_INTEGER GetFrequency() const
	{
		return m_Frequency;
	}

	const bool GetChangedBool() const
	{
		return m_ChangedBool;
	}

	const bool GetCheckBool() const
	{
		return m_CheckBool;
	}

	const bool GetPauseSimulationBool() const
	{
		return m_PauseSimulationBool;
	}

	const bool GetIntegrationBool() const
	{
		return m_IntegrationBool;
	}

	const bool GetNetBool() const
	{
		return m_NetBool;
	}

	const bool GetFallBool() const
	{
		return m_FallBool;
	}

	const bool GetCameraPositionBool() const
	{
		return m_CameraPositionBool;
	}

	const bool GetCameraObjectBool() const
	{
		return m_CameraObjectBool;
	}

	const bool GetDirectionBool() const
	{
		return m_DirectionBool;
	}

	const double GetDT() const
	{
		return m_DT;
	}

	const double GetTimeScale() const
	{
		return m_TimeScale;
	}

	const double GetTime() const
	{
		return m_Time;
	}

	const double GetPreviousTime() const
	{
		return m_PreviousTime;
	}

	const double GetFPS() const
	{
		return m_FPS;
	}

	const double GetFriction() const
	{
		return m_Friction;
	}

	const double GetElasticity() const
	{
		return m_Elasticity;
	}

	const double GetRandomObject() const
	{
		return m_RandomObject;
	}

	void SetHDC(const HDC &hdc)
	{
		m_HDC = hdc;
	}

	void SetBowl(Bowl *bowl)
	{
		m_Bowl = bowl;
	}

	void SetBox(Box *box)
	{
		m_Box = box;
	}

	void SetBalls(const vector<Ball *> &balls)
	{
		m_Balls = balls;
	}

	void SetBallContactManifold(const vector<BallContactManifold *> &ballContactManifold)
	{
		m_BallContactManifold = ballContactManifold;
	}

	void SetBallCubeContactManifold(const vector<BallCubeContactManifold *> &ballCubeContactManifold)
	{
		m_BallCubeContactManifold = ballCubeContactManifold;
	}

	void SetCubes(const vector<Cube *> &cubes)
	{
		m_Cubes = cubes;
	}

	void SetCubeContactManifold(const vector<CubeContactManifold *> &cubeContactManifold)
	{
		m_CubeContactManifold = cubeContactManifold;
	}

	void SetCameraPosition(const Vector3D &cameraPosition)
	{
		m_CameraPosition = cameraPosition;
	}

	void SetCameraRotation(const Vector3D &cameraRotation)
	{
		m_CameraRotation = cameraRotation;
	}

	void SetStart(const LARGE_INTEGER &start)
	{
		m_Start = start;
	}

	void SetEnd(const LARGE_INTEGER &end)
	{
		m_End = end;
	}

	void SetFrequency(const LARGE_INTEGER &frequency)
	{
		m_Frequency = frequency;
	}

	void SetChangedBool(const bool changedBool)
	{
		m_ChangedBool = changedBool;
	}

	void SetCheckBool(const bool checkBool)
	{
		m_CheckBool = checkBool;
	}

	void SetPauseSimulationBool(const bool pauseSimulationBool)
	{
		m_PauseSimulationBool = pauseSimulationBool;
	}

	void SetIntegrationBool(const bool integrationBool)
	{
		m_IntegrationBool = integrationBool;
	}

	void SetNetBool(const bool netBool)
	{
		m_NetBool = netBool;
	}

	void SetFallBool(const bool fallBool)
	{
		m_FallBool = fallBool;
	}

	void SetCameraPositionBool(const bool cameraPositionBool)
	{
		m_CameraPositionBool = cameraPositionBool;
	}

	void SetCameraObjectBool(const bool cameraObjectBool)
	{
		m_CameraObjectBool = cameraObjectBool;
	}

	void SetDirectionBool(const bool directionBool)
	{
		m_DirectionBool = directionBool;
	}

	void SetDT(const double dt)
	{
		m_DT = dt;
	}

	void SetTimeScale(const double timeScale)
	{
		m_TimeScale = timeScale;
	}

	void SetTime(const double time)
	{
		m_Time = time;
	}

	void SetPreviousTime(const double previousTime)
	{
		m_PreviousTime = previousTime;
	}

	void SetFPS(const double fps)
	{
		m_FPS = fps;
	}

	void SetFriction(const double friction)
	{
		m_Friction = friction;
	}

	void SetElasticity(const double elasticity)
	{
		m_Elasticity = elasticity;
	}

	void SetRandomObject(const double randomObject)
	{
		m_RandomObject = randomObject;
	}

	void Update();

private:
	void SetCheckBools();
	void CheckMoving();
	void CalculateObjectPhysics();
	void DynamicCollisionDetection();
	void DynamicCollisionResponse();
	void BowlDetectionAndResponce();
	void TrayDetectionAndResponce();
	void UpdateObjectPhysics();
	void SimulationLoop();
	void Render();
	const double GetRandomBall() const;
	const double GetRandomCube() const;
	void UpdateConsole();
	void ResetSimulation();
	void CameraRotationKeyboardEvents();
	void CameraPositionKeyboardEvents();
	void ObjectKeyboardEvents();
	void KeyboardEventHandler();

private:
	HDC m_HDC;
	Bowl *m_Bowl;
	Box *m_Box;
	vector<Ball *> m_Balls;
	vector<BallContactManifold *> m_BallContactManifold;
	vector<BallCubeContactManifold *> m_BallCubeContactManifold;
	vector<Cube *> m_Cubes;
	vector<CubeContactManifold *> m_CubeContactManifold;
	Vector3D m_CameraPosition, m_CameraRotation;
	LARGE_INTEGER m_Start, m_End, m_Frequency;
	bool m_ChangedBool, m_CheckBool, m_PauseSimulationBool, m_IntegrationBool, m_NetBool, m_FallBool, m_CameraPositionBool, m_CameraObjectBool, m_DirectionBool;
	double m_DT, m_TimeScale, m_Time, m_PreviousTime, m_FPS, m_Friction, m_Elasticity, m_RandomObject;
};

