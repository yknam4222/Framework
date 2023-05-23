#pragma once
#include "Include.h"

class GameObject;
class ObjectPool
{
public:
	Single(ObjectPool);

private:
	list<GameObject*> PoolList;

public:
	list<GameObject*>* GetList() { return &PoolList; }

public:
	GameObject* GetPoolObject();
	void RetunObject(GameObject* _Object);
private:
	ObjectPool();
public:
	~ObjectPool();
};

