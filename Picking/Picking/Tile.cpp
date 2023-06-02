#include "Tile.h"
#include "Bitmap.h"

Tile::Tile() : check(0)
{
}

Tile::~Tile()
{
}

Object* Tile::Start()
{
	check = 0;

	position = Vector3(100.0f, 100.0f);
	scale = Vector3(100.0f, 100.0f);

	Key = "Tile";

	return this;
}

void Tile::Update()
{
	//POINT ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	if (GetAsyncKeyState(VK_LBUTTON))
	{
	}

	if (check)
	{
		if (position.x - (scale.x * 0.5f) < ptMouse.x &&
			position.y - (scale.y * 0.5f) < ptMouse.y &&
			ptMouse.x < position.x + (scale.x * 0.5f) &&
			ptMouse.y < position.y + (scale.y * 0.5f))
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				check = !check;
				Sleep(100);
			}
		}
	}
	else
	{
		float dx = ptMouse.x - position.x;
		float dy = ptMouse.y - position.y;

		float distance = sqrt((dx * dx) + (dy * dy));

		if (distance < scale.x * 0.5f)
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				check = !check;
				Sleep(100);
			}
		}
	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		check = !check;
		Sleep(50);
	}
}

void Tile::Render(HDC hdc)
{
	/*if (check)
		Rectangle(hdc,
			int(position.x - (scale.x * 0.5f)),
			int(position.y - (scale.y * 0.5f)),
			int(position.x + (scale.x * 0.5f)),
			int(position.y + (scale.y * 0.5f)));
			
	else
		Ellipse(hdc,
			int(position.x - (scale.x * 0.5f)),
			int(position.y - (scale.y * 0.5f)),
			int(position.x + (scale.x * 0.5f)),
			int(position.y + (scale.y * 0.5f)));*/

	TransparentBlt(hdc,	  // ������ ���� �׸��� ?!
		(int)position.x,	// ������ ���� ������ X
		(int)position.y, 	// ������ ���� ������ Y
		(int)scale.x,	// ������ ���� ���κ� X
		(int)scale.y, 	// ������ ���� ���κ� Y
		(*m_ImageList)[Key]->GetMemDC(),	// ������ �̹��� (������)
		0,  // ������ ������ X
		0,	// ������ ������ Y
		(int)scale.x, 			// ����� �̹����� ũ�� ��ŭ X
		(int)scale.y,			// ����� �̹����� ũ�� ��ŭ Y
		RGB(255, 0, 255));		// �ش� ������ ����
}

void Tile::Destroy()
{
}

