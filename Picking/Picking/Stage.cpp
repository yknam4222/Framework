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

	//BitBlt(hdc,				//������ ���� �׸���
	//	0, 0, 128, 64,				//������ ���� ���������κ��� ���κб���
	//	(*m_mapImageList)["Tile"]->GetMemDC(),	//������ �̹���f
	//	0, 0,			//������ ���
	//	SRCCOPY);	// �ҽ������� ��� ������ ����

	object->Render(hdc);
}

void Stage::Destroy()
{
	delete object;
	object = nullptr;
}

