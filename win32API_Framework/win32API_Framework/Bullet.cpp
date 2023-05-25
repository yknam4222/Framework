#include "Bullet.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "ObjectPool.h"
#include "NormalBullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

GameObject* Bullet::Start()
{
	transform.position = Vector3(0.0f, 0.0f, 0.0f);
	transform.direction = Vector3(1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(30.0f, 30.0f, 0.0f);

	Key = "Bullet";

	return this;
}



int Bullet::Update()
{
	if (pBridge)
		pBridge->Update(transform);

	//transform.position += transform.direction * Speed;

	/*if (transform.position.x > WIDTH)
		return 1;*/
	list<GameObject*>* EnemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			if (CollisionManager::CircleCollision(this, (*iter)))
				return 1;
	}
	if (transform.position.x > WIDTH)
		return 1;
	else 
		return 0;
}

void Bullet::Render(HDC hdc)
{
	if (pBridge)
		pBridge->Render(hdc);
}

void Bullet::Destroy()
{
	this->SetScale(transform.scale * 0.5f);
	//GetSingle(ObjectPool)->RetunObject(this);
	GetSingle(ObjectPool)->RetunObject(this);

}

