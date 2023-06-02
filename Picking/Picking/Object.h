#pragma once
#include "Include.h"

class Bitmap;
class Object
{
protected:
	string Key;

	static map<string, Bitmap*>* m_ImageList;

public:
	static void SetImageList(map<string, Bitmap*>* _ImageList) { m_ImageList = _ImageList; }

public:
	virtual Object* Start()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;

public:
	Object();
	virtual ~Object();
};

