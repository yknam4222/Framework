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
	enemy bullet이 충돌하면 충돌된걸 확인하고 충돌판정이 나면 
	bullet이 스스로 destroy를 실행하고,
	destroy가 호출이되면 objectpool에 있는 returnobject를 호출하고 
	poollist에 들어갈 수 있게끔 만들것.
	*/
	PoolList.push_back(_Object);
}