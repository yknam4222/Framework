#pragma once
#include "Object.h"

class Tile : public Object
{
private:
	int check;
	Vector3 position;
	Vector3 scale;

	POINT ptMouse;

public:
	virtual Object* Start()override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;

public:
	Tile();
	virtual ~Tile();
};

