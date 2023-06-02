#pragma once
#include "Include.h"

class Bitmap;
class ImageManager
{
private:
	static ImageManager* Instance;
public:
	static ImageManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ImageManager;
		return Instance;
	}
	
private:
	map<string, Bitmap*> m_mapImageList;
public:
	map<string, Bitmap*>* GetImageList() { return &m_mapImageList; }
private:
	ImageManager();
public:
	~ImageManager();
};

