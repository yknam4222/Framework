#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>

using namespace std;

// 타일 가로 세로 최대 갯수
#define COUNT_X 5
#define COUNT_Y 5

// 타일 최대 갯수
const int MAX = COUNT_X * COUNT_Y;

// 색
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

// 전방 선언
void Text(const float& _x, const float& _y, const string& _str, int _color);
void SetCorsorPosition(const float& _x, const float& _y);
void SetColor(const int& _color);
bool CheckTileList(int _index);

typedef struct tagVector3
{
	float x, y;

	tagVector3() : x(0.0f), y(0.0f) {}
	tagVector3(float _x, float _y) : x(_x), y(_y) {}

}Vector3;

typedef struct tagTile
{
	Vector3 position[4];
	string tile[4];
	int option;
	int index;
	int value;
	int color;
	bool check;

	void Render()
	{
		switch (option)
		{
		case 0:
			color = 15;
			break;

		case 1:
			color = 12;
			break;
		}

		for (int i = 0; i < 4; ++i)
			Text(position[i].x, position[i].y, tile[i], color);
	}

	tagTile() : option(0), check(false) {}

}Tile;

typedef struct tagInfo
{
	Vector3 position;
	string tile;
	int option;
	tagInfo() : position(Vector3(0.0f, 0.0f)), option(0) {}

}Info;

// 타일 크기
const Vector3 scale(6, 3);

list<Tile*> BlackTileList;

int main(void)
{
	BlackTileList.clear();

	// 타일 위치
	vector<Tile*>TileList;

	int x = 0;
	int y = 0;

	for (int i = 0; i < COUNT_Y * COUNT_X; ++i)
	{
		Tile* tile = new Tile;

		tile->tile[0] = "┌─┐";
		tile->position[0] = Vector3(x * scale.x, y * scale.y);

		tile->tile[1] = "│　│";
		tile->position[1] = Vector3(x * scale.x, y * scale.y + 1);

		tile->tile[2] = "└─┘";
		tile->position[2] = Vector3(x * scale.x, y * scale.y + 2);

		tile->option = 0;
		tile->color = 15;
		tile->index = y * COUNT_X + x;
		tile->value = tile->index + 1;
		tile->check = true;

		x++;

		if (x == COUNT_X)
		{
			x = 0;
			y++;
		}

		TileList.push_back(tile);
	}

	for (int i = 0; i < COUNT_X * COUNT_Y * 2; ++i)
	{
		int random1 = rand() % 25;
		int random2 = rand() % 25;

		if (random1 == random2)
			continue;
		else
		{
			int value = TileList[random1]->value;
			TileList[random1]->value = TileList[random2]->value;
			TileList[random2]->value = value;
		}
	}

	for (int i = 0; i < COUNT_X * COUNT_Y; ++i)
	{
		char* buffer = new char[4];

		_itoa(TileList[i]->value, buffer, 10);

		TileList[i]->position[3] = Vector3(TileList[i]->position[1].x + 2, TileList[i]->position[1].y);
		TileList[i]->tile[3] = string(buffer);
	}

	// Target
	Info Cursur;

	Cursur.position = Vector3(20.0f, 10.0f);
	Cursur.option = 0;

	/*srand((unsigned int)GetTickCount64());

	for (int i = 0; i < 3; ++i)
	{
		int random = rand() % 25;

		TileList[random]->option = 1;

		BlackTileList.push_back(TileList[random]);
	}*/


	// 커서가 위치한 타일의 인덱스
	int X = int(Cursur.position.x / scale.x);
	int Y = int(Cursur.position.y / scale.y);

	int index = Y * COUNT_Y + X;

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time + 50 < GetTickCount64())
		{
			time = GetTickCount64();

			// 화면 청소
			system("cls");

			if (GetAsyncKeyState(VK_UP))
			{
				if (index < MAX &&
					0 <= index - COUNT_X &&
					CheckTileList(index - COUNT_X))
					index -= COUNT_X;
			}

			if (GetAsyncKeyState(VK_DOWN))
			{
				if (index + COUNT_X < MAX &&
					0 <= index  &&
					CheckTileList(index + COUNT_X))
					index += COUNT_X;
			}

			if (GetAsyncKeyState(VK_LEFT))
			{
				if (index % COUNT_X != 0 && 
					CheckTileList(index - 1))
					index -= 1;
			}

			if (GetAsyncKeyState(VK_RIGHT))
			{
				if (index % COUNT_X -4 != 0 &&
					CheckTileList(index + 1))
					index += 1;
			}

			if (GetAsyncKeyState(VK_SPACE))
			{
				Text(57, 14, "Input!", 10);
				TileList[index]->option = !TileList[index]->option;
			}

			// 출력
			for (int i = 0; i < TileList.size(); ++i)
			{
				if (index == i)
				{
					Text(TileList[index]->position[0].x,
						TileList[index]->position[0].y,
						TileList[index]->tile[0],
						10);

					Text(TileList[index]->position[1].x,
						TileList[index]->position[1].y,
						TileList[index]->tile[1],
						10);

					Text(TileList[index]->position[2].x,
						TileList[index]->position[2].y,
						TileList[index]->tile[2],
						10);

					Text(TileList[index]->position[3].x,
						TileList[index]->position[3].y,
						TileList[index]->tile[3],
						10);
				}
				else
					TileList[i]->Render();
			}

			// CPU가 연산을 하지 않는 상태.
			//Sleep(50);
		}
	}


	SetColor(GRAY);

	return 0;
}

void SetCorsorPosition(const float& _x, const float& _y)
{
	COORD pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(const int& _color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

void Text(const float& _x, const float& _y, const string& _str, int _color = 15)
{
	SetColor(_color);
	SetCorsorPosition(_x, _y);
	cout << _str << endl;
}

bool CheckTileList(int _index)
{
	for (list<Tile*>::iterator iter = BlackTileList.begin(); iter != BlackTileList.end(); ++iter)
	{
		if ((*iter)->index == _index)
			return false;
	}
	return true;
}