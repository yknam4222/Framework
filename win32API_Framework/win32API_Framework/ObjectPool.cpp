#include "ObjectPool.h"


ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}

GameObject* ObjectPool::GetPoolObject()
{
	//GameObject* Obj = PoolList.pop_front();
	return Obj;
}

void ObjectPool::RetunObject(GameObject* _Object)
{
	/*
	enemy bullet�� �浹�ϸ� �浹�Ȱ� Ȯ���ϰ� �浹������ ���� 
	bullet�� ������ destroy�� �����ϰ�,
	destroy�� ȣ���̵Ǹ� objectpool�� �ִ� returnobject�� ȣ���ϰ� 
	poollist�� �� �� �ְԲ� �����.
	*/
	PoolList.push_back(_Object);
}