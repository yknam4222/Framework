#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Prototype.h"

#include "NormalBullet.h"
#include "GuideBullet.h"
#include "ObjectPool.h"
#include "Bitmap.h"

Player::Player()
{
}

Player::~Player()
{
}

GameObject* Player::Start()
{
	frame.CountX = 0;
	frame.CountY = 0;
	frame.EndFrame = 7;
	frame.FrameTime = 50;

	transform.position = Vector3(WIDTH * 0.5f, HEIGHT * 0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(679 / 7, 639 / 9, 0.0f);

	Speed = 5.0f;
	Key = "Player";

	Time = GetTickCount64();
	return this;
}

int Player::Update()
{
	DWORD dwKey = GetSingle(InputManager)->GetKey();
	
	if (Time + frame.FrameTime < GetTickCount64())
	{
		Time = GetTickCount64();
		++frame.CountX;

		if (frame.CountX >= frame.EndFrame)
			frame.CountX = 0;
	}

	if (dwKey == 0)
	{
		frame.CountY = 0;
		frame.EndFrame = 7;
	}

	if (dwKey & KEYID_UP)
	{
		transform.position.y -= Speed;
		frame.CountY = 7;
		frame.EndFrame = 4;
	}

	if (dwKey & KEYID_DOWN)
	{
		transform.position.y += Speed;
		frame.CountY = 7;
		frame.EndFrame = 4;
	}

	if (dwKey & KEYID_LEFT)
	{
		transform.position.x -= Speed;
		frame.CountY = 1;
		frame.EndFrame = 7;
		Key = "PlayerFlip";
	}
		
	if (dwKey & KEYID_RIGHT)
	{
		transform.position.x += Speed;
		frame.CountY = 1;
		frame.EndFrame = 7;
		Key = "Player";
	}

	if (dwKey & KEYID_SPACE)
	{
		GetSingle(ObjectManager)->AddObject(CreateBullet<NormalBullet>("NormalBullet"));
		frame.CountY = 4;
		frame.EndFrame = 2;
	}

	if (dwKey & KEYID_CONTROL)
	{
		//GetSingle(ObjectManager)->AddObject(CreateBullet<GuideBullet>("GuideBullet"));
		frame.CountY = 2;
		frame.EndFrame = 6;
	}

	return 0;
}

void Player::Render(HDC hdc)
{
	TransparentBlt(hdc,	  // ������ ���� �׸��� ?!
		(int)transform.position.x,	// ������ ���� ������ X
		(int)transform.position.y, 	// ������ ���� ������ Y
		(int)transform.scale.x,	// ������ ���� ���κ� X
		(int)transform.scale.y, 	// ������ ���� ���κ� Y
		(*m_ImageList)[Key]->GetMemDC(),	// ������ �̹��� (������)
		transform.scale.x * frame.CountX,  // ������ ������ X
		transform.scale.y * frame.CountY,  // ������ ������ Y
		(int)transform.scale.x, 			// ����� �̹����� ũ�� ��ŭ X
		(int)transform.scale.y,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));		// �ش� ������ ����

	/*Rectangle(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));*/
}

void Player::Destroy()
{
}

template<typename T>
GameObject* Player::CreateBullet(string _key)
{
	GameObject* Obj = GetSingle(ObjectPool)->GetGameObject(_key);

	if (Obj == nullptr)
	{
		Bridge* pBridge = new T;
		pBridge->Start();
		((BulletBridge*)pBridge)->SetTarget(this);

		GameObject* ProtoObj = GetSingle(Prototype)->GetGameObject(_key);

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			Object->Start();
			Object->SetPosition(transform.position);
			Object->SetKey(_key);

			pBridge->SetObject(Object);
			Object->SetBridge(pBridge);

			return Object;
		}
		else
			return nullptr;
	}

	Obj->Start();
	Obj->SetPosition(transform.position);
	Obj->SetKey(_key);

	return Obj;
}

