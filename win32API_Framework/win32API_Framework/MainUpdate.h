#pragma once
#include "Include.h"
#include "CollisionManager.h"

class GameObject;
class MainUpdate
{
private:
	HDC m_hdc;

	GameObject* m_pPlayer;
	GameObject* m_pEnemy;

	CollisionManager collision;
public:
	void Start();
	void Update();
	void Render();
	void Destroy();

public:
	MainUpdate();
	~MainUpdate();
};

