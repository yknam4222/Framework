#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	float Speed;
	GameObject* Target;
public:
	virtual void Start()PURE;
	virtual void Update(Transform& transform)PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;

public:
	void SetTarget(GameObject* target) { Target = target; }
public:
	BulletBridge() : Speed(0.0f), Target(nullptr) {}
	virtual ~BulletBridge() {}
};