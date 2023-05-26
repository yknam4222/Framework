#pragma once
#include "Include.h"

class Bitmap;
class Bridge;
class GameObject
{
protected:
	Transform transform;
	float Speed;
	Bridge* pBridge;
	string Key;

	static map<string, Bitmap*>* m_ImageList;
public:
	static void SetImageList(map<string, Bitmap*>* _ImageList) { m_ImageList = _ImageList; }

public:
	virtual GameObject* Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;

public:
	virtual GameObject* Clone()PURE;
public:
	string GetKey() { return Key; }
	GameObject* SetKey(const string& _key) 
	{
		Key = _key;
		return this;
	}

	Transform GetTransform() { return transform; }
	//void SetTransform(Transform _transform) { transform = _transform; }

	Vector3 GetPosition() { return transform.position; }
	void SetPosition(Vector3 _position) { transform.position = _position; }

	Vector3 GetScale() { return transform.scale; }
	void SetScale(Vector3 _scale) { transform.scale = _scale; }

	void SetBridge(Bridge* bridge) { pBridge = bridge; }
public:
	GameObject(); 
	GameObject(Transform _transform) : transform(_transform), Speed(0.0f), pBridge(nullptr) {}
	virtual ~GameObject();
};

