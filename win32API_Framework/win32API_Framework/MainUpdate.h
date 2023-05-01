#pragma once
#include "Include.h"

class MainUpdate
{
private:
	HDC m_hdc;

	float StartX, StartY;
	float EndX, EndY;

	float BulletStartX, BulletStartY;
	float BulletEndX, BulletEndY;

public:
	void Start();
	void Update();
	void Render();
	void Destroy();

public:
	MainUpdate();
	~MainUpdate();
};

