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
	enemy bullet이 충돌하면 충돌된걸 확인하고 충돌판정이 나면 
	bullet이 스스로 destroy를 실행하고,
	destroy가 호출이되면 objectpool에 있는 returnobject를 호출하고 
	poollist에 들어갈 수 있게끔 만들것.
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