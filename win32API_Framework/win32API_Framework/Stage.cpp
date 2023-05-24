#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "Prototype.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "ObjectPool.h"
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
	test = GetSingle(ObjectPool)->GetList("Bullet");
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	//list<GameObject*>* BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");
	
	if (EnemyList != nullptr && !EnemyList->empty())
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
		BulletList = GetSingle(ObjectManager)->GetObjectList("Bullet");
	
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
	//list<GameObject*>* BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");

	if (m_pPlayer)
		m_pPlayer->Render(hdc);

	GetSingle(ObjectManager)->Render(hdc);

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

