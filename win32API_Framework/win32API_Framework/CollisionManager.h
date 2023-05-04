#pragma once
#include "Include.h"
#include "GameObject.h"

class CollisionManager
{
public:
	//�� �浹
	static bool CircleCollision(GameObject* temp, GameObject* dest)
	{
		//x���� y���� ���Ѵ�.
		float fx = dest->GetPosition().x - temp->GetPosition().x;
		float fy = dest->GetPosition().y - temp->GetPosition().y;

		//���� �������� ��
		float sum = dest->GetScale().x + temp->GetScale().x;

		//�Ÿ�
		float distance = sqrt((fx * fx) + (fy * fy));

		if (distance < sum)
			return true;

		return false;
	}

	// Rect �浹
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