#pragma once
#include "Include.h"

class GameObject;
class ObjectManager
{
public:
	Single(ObjectManager);
//private:
//	static ObjectManager* Instance;
//
//public:
//	static ObjectManager* GetInstance()
//	{
//		if (Instance == nullptr)
//			Instance = new ObjectManager;
//
//		return Instance;
//	}
private:
	map<string, list<GameObject*>> ObjectList;
public:
	void AddObject(GameObject* _Object);

	list<GameObject*>* GetObjectList(string key);
	void Update();
	void Render(HDC _hdc);
private:
	ObjectManager();
public:
	~ObjectManager();
};
