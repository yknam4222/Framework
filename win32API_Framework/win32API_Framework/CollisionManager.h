#pragma once
#include "Include.h"
#include "GameObject.h"

class CollisionManager
{
public:
	//구 충돌
	static bool CircleCollision(GameObject* temp, GameObject* dest)
	{
		//x값과 y값을 구한다.
		float fx = dest->GetPosition().x - temp->GetPosition().x;
		float fy = dest->GetPosition().y - temp->GetPosition().y;

		//구의 반지름의 합
		float sum = dest->GetScale().x + temp->GetScale().x;

		//거리
		float distance = sqrt((fx * fx) + (fy * fy));

		if (distance < sum)
			return true;

		return false;
	}

	// Rect 충돌
	static bool RectCollision(GameObject* temp, GameObject* dest)
	{
		if (temp->GetPosition().x + (temp->GetScale().x * 0.5f) > dest->GetPosition().x - (dest->GetScale().x * 0.5f) &&
			dest->GetPosition().x + (dest->GetScale().x * 0.5f) > temp->GetPosition().x - (temp->GetScale().x * 0.5f) &&
			temp->GetPosition().y + (temp->GetScale().y * 0.5f) > dest->GetPosition().y - (dest->GetScale().y * 0.5f) &&
			dest->GetPosition().y + (dest->GetScale().y * 0.5f) > temp->GetPosition().y - (temp->GetScale().y * 0.5f))
			return true;

		return false;
	}
};