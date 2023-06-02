#include "Stage.h"
#include "Tile.h"
#include "Bitmap.h"
#include "ImageManager.h"
#include "Object.h"


Stage::Stage() : object(nullptr)
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	object = new Tile;
	object->Start();

	m_mapImageList = ImageManager::GetInstance()->GetImageList();

	(*m_mapImageList)["Tile"] = (new Bitmap)->LoadBmp(L"../Resource/Tile.bmp");

	Object::SetImageList(m_mapImageList);
}

void Stage::Update()
{
	object->Update();
}

void Stage::Render(HDC hdc)
{

	//BitBlt(hdc,				//복사해 넣을 그림판
	//	0, 0, 128, 64,				//복사할 영역 시작점으로부터 끝부분까지
	//	(*m_mapImageList)["Tile"]->GetMemDC(),	//복사할 이미지f
	//	0, 0,			//스케일 잡기
	//	SRCCOPY);	// 소스영역을 대상 영역에 복사

	object->Render(hdc);
}

void Stage::Destroy()
{
	delete object;
	object = nullptr;
}

