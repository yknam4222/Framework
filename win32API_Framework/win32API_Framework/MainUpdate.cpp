#include "MainUpdate.h"

MainUpdate::MainUpdate()
{
	
}

MainUpdate::~MainUpdate()
{
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	StartX = 100;
	StartY = 100;

	EndX = 200;
	EndY = 200;

	BulletStartX = 150;
	BulletStartY = 250;
	BulletEndX = 270;
	BulletEndY = 260;
}

void MainUpdate::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		EndY -= 0.001;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		EndY += 0.001;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		EndX -= 0.001;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		EndX += 0.001;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		BulletStartX+=1;
		//BulletStartY+=0.001;
		BulletEndX += 1;
		//BulletEndY += 0.001;
	}
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, StartX, StartY, EndX, EndY);

	Rectangle(m_hdc, BulletStartX, BulletStartY, BulletEndX, BulletEndY);
}

void MainUpdate::Destroy()
{
}

