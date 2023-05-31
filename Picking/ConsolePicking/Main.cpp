#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>

using namespace std;

// Ÿ�� ���� ���� �ִ� ����
#define COUNT_X 7
#define COUNT_Y 4


#define BLACK						0
#define DARKBLUE				1
#define DARKGREEN		    2
#define DARKSKYBLUE		3
#define DARKRED				4
#define DARKPURPLE			5
#define DARKYELLOW			6
#define GRAY						7
#define DARKGRAY				8
#define BLUE						9
#define GREEN						10
#define SKYBLUE					11
#define RED							12
#define PURPLE					13
#define YELLOW					14
#define WHITE						15



typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f), y(0.0f) {}
	tagVector3(float _x, float _y) : x(_x), y(_y) {}

}Vector3;

void SetCorsorPosition(const float& _x, const float& _y);
void SetColor(int _color);
void Text(const float& _x, const float& _y, const string& _str);

int main(void)
{
	// Ÿ�� ��ġ
	Vector3 position;
	position.x = 3;
	position.y = 2;

	// Ÿ�� ũ��
	Vector3 scale;
	scale.x = 6;
	scale.y = 3;

	Vector3 indexpos;
	indexpos.x = 3;
	indexpos.y = 2;
	int checkindex = 0;

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 50 < GetTickCount64())
		{
			time = GetTickCount64();

			// ȭ�� û��
			system("cls");

			for (int y = 0; y < COUNT_Y; ++y)
			{
				for (int x = 0; x < COUNT_X; ++x)
				{
					SetColor(GRAY);

					// Ÿ�� ���
					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y,
						"������");

					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 1,
						"������");

					Text(position.x - (scale.x * 0.5f) + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 2,
						"������");

					// index Ȯ��
					int index = y * COUNT_X + x;

					char* buffer = new char[4];
					_itoa(index, buffer, 10);

					SetColor(RED);

					Text(position.x - 1 + scale.x * x,
						position.y - (scale.y * 0.5f) + scale.y * y + 1,
						string(buffer));

					
					_itoa(checkindex, buffer, 10);
					SetColor(BLUE);
					Text(indexpos.x - 1 ,
						indexpos.y - 1 ,
						string(buffer));

					
				}
			}
			// CPU�� ������ ���� �ʴ� ����.
			//Sleep(50);
			if (GetAsyncKeyState(VK_RIGHT))
			{
				checkindex++;
				indexpos.x += 6;
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				checkindex--;
				indexpos.x -= 6;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				checkindex += 7;
				indexpos.y += 3;
			}
			else if (GetAsyncKeyState(VK_UP))
			{
				checkindex -= 7;
				indexpos.y -= 3;
			}
		}
	}

	
		SetColor(GRAY);

	return 0;
}

void SetCorsorPosition(const float& _x, const float& _y)
{
	COORD pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(int _color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

void Text(const float& _x, const float& _y, const string& _str)
{
	SetCorsorPosition(_x, _y);
	cout << _str << endl;
}
