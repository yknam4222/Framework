#pragma once
#include "Include.h"

class GameObject;
class Bridge
{
private:
	GameObject* Object;
private:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;

public:
	Bridge() : Object(nullptr){}
	virtual ~Bridge() {}
};