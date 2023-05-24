#include "ObjectPool.h"
#include "GameObject.h"


ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}

void ObjectPool::RetunObject(GameObject* _Object)
{
	/*
	enemy bullet�� �浹�ϸ� �浹�Ȱ� Ȯ���ϰ� �浹������ ���� 
	bullet�� ������ destroy�� �����ϰ�,
	destroy�� ȣ���̵Ǹ� objectpool�� �ִ� returnobject�� ȣ���ϰ� 
	poollist�� �� �� �ְԲ� �����.
	*/
	//PoolList.push_back(_Object);

	map<string, list<GameObject*>>::iterator iter = PoolList.find(_Object->GetKey());

	if (iter == PoolList.end())
	{
		list<GameObject*> tempList;
		tempList.push_back(_Object);

		PoolList.insert(make_pair(_Object->GetKey(), tempList));
	}
	else
		iter->second.push_back(_Object);
}