#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "Prototype.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "ObjectPool.h"
#include "Bitmap.h"
#include "ImageManager.h"

//#ifdef UNICODE
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
//#else
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
//#endif
Stage::Stage() : m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{

}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	GetSingle(Prototype)->Start();

	{
		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject("Player");

		GameObject* obj = ObjectFactory<Player>::CreateObject();

		if (ProtoObj != nullptr)
		{
			m_pPlayer = ProtoObj->Clone();
			m_pPlayer->Start();
		}
	}

	{
		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject("Enemy");

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			GetSingle(ObjectManager)->AddObject(Object->Start());
		}
	}
	EnemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");

	m_mapImageList = GetSingle(ImageManager)->GetImageList();

	/*m_mapImageList->insert(
		make_pair("BackGround", (new Bitmap)->LoadBmp(L"../Resource/Stage/BackGround.bmp")));

	m_mapImageList->insert(
		make_pair("Buffer", (new Bitmap)->LoadBmp(L"../Resource/Stage/Buffer.bmp")));*/

	(*m_mapImageList)["BackGround"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/BackGround.bmp");
	(*m_mapImageList)["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/Buffer.bmp");
	(*m_mapImageList)["Player"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/Player.bmp");
	(*m_mapImageList)["PlayerFlip"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/PlayerFlip.bmp");

	GameObject::SetImageList(m_mapImageList);
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	GetSingle(ObjectManager)->Update();

	//list<GameObject*>* BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");

	/*if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Update();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			if ((*iter)->Update() == 1 && (*iter)->GetScale().x ==30.0f)
			{
				(*iter)->Destroy();
			}
		}
	}
	else
		BulletList = GetSingle(ObjectManager)->GetObjectList("Bullet");*/

		/*if (test != nullptr && !test->empty())
		{
			printf("%d\n", test->size());
		}
		else
			test = GetSingle(ObjectPool)->Gettest("Bullet");*/

	return 0;
}




void Stage::Render(HDC hdc)
{

	BitBlt((*m_mapImageList)["Buffer"]->GetMemDC(),				//��f���� ���� �׸���
		0, 0, WIDTH, HEIGHT,				//������ ���� ���������κ��� ���κб���
		(*m_mapImageList)["BackGround"]->GetMemDC(),	//������ �̹���
		0, 0,			//������ ���
		SRCCOPY);	// �ҽ������� ��� ������ ����

	if (m_pPlayer)
		m_pPlayer->Render(
			(*m_mapImageList)["Buffer"]->GetMemDC());

	
	GetSingle(ObjectManager)->Render((*m_mapImageList)["Buffer"]->GetMemDC());


	BitBlt(hdc,				//������ ���� �׸���
		0, 0, WIDTH, HEIGHT,				//������ ���� ���������κ��� ���κб���
		(*m_mapImageList)["Buffer"]->GetMemDC(),	//������ �̹���f
		0, 0,			//������ ���
		SRCCOPY);	// �ҽ������� ��� ������ ����

	/*if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Render(hdc);
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Render(hdc);
	}
	else
		BulletList = GetSingle(ObjectManager)->GetObjectList("Bullet");*/
#ifdef DEBUG
	list<GameObject*>* enemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");
	list<GameObject*>* normalList = GetSingle(ObjectManager)->GetObjectList("NormalBullet");
	list<GameObject*>* guideList = GetSingle(ObjectManager)->GetObjectList("GuideBullet");

	if (enemyList != nullptr && !enemyList->empty())
	{
		char* enemyCount = new char[128];
		_itoa(enemyList->size(), enemyCount, 10);
		TextOut(hdc, 50, 50, (LPCWSTR)enemyCount, strlen(enemyCount));
	}

	if (normalList != nullptr && !normalList->empty())
	{
		char* NormalCount = new char[128];
		_itoa(normalList->size(), NormalCount, 10);
		TextOutA(hdc, 50, 70, NormalCount, strlen(NormalCount));
	}

	if (guideList != nullptr && !guideList->empty())
	{
		char* GuideCount = new char[128];
		_itoa(guideList->size(), GuideCount, 10);
		TextOutA(hdc, 50, 90, GuideCount, strlen(GuideCount));
	}

	if (guideList != nullptr && !guideList->empty())
	{
		//Buffer ����
		//�迭�� ���̴� �߿����� ����. (����ϸ� ��)
		char* GuideBuffer = new char[1024];

		//������ ���ڿ��� ��ȯ. 10������ ��ȯ��.
		_itoa(guideList->size(), GuideBuffer, 10);

		//���ڿ� �����͸� string���� ��ȯ.
		string str(GuideBuffer);

		//���ڿ� ������ �迭 ����
		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		//�����ڵ����·� ����
		wchar_t* t = new wchar_t[(int)str.size()];

		//���ڿ� ����
		mbstowcs(t, str.c_str(), (int)str.size());

		//���
		TextOut(hdc, 50, 110, (LPCWSTR)t, (int)str.size());
	}

	list<GameObject*>* NormalBulletList = GetSingle(ObjectPool)->GetList("NormalBullet");
	list<GameObject*>* GuideBulletList = GetSingle(ObjectPool)->GetList("GuideBullet");

	if (NormalBulletList != nullptr && !NormalBulletList->empty())
	{
		//Buffer ����
		//�迭�� ���̴� �߿����� ����. (����ϸ� ��)
		char* normalBuffer = new char[1024];

		//������ ���ڿ��� ��ȯ. 10������ ��ȯ��.
		_itoa(NormalBulletList->size(), normalBuffer, 10);

		//���ڿ� �����͸� string���� ��ȯ.
		string str(normalBuffer);

		//���ڿ� ������ �迭 ����
		delete[] normalBuffer;
		normalBuffer = nullptr;

		//�����ڵ����·� ����
		wchar_t* t = new wchar_t[(int)str.size()];

		//���ڿ� ����
		mbstowcs(t, str.c_str(), (int)str.size());

		//���
		TextOut(hdc, 120, 70, (LPCWSTR)t, (int)str.size());
	}
#endif
}

void Stage::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		EnemyList->clear();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		BulletList->clear();
	}
}

