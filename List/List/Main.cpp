#include <iostream>

using namespace std;

typedef struct tagNode
{
	tagNode* next;
	int value;
}NODE;

NODE* List;
NODE* End;
int Length;


void push(int value)
{
	/*
	while (nextNode->next != nullptr)
		nextNode = nextNode->next;
	*/

	//** create
	NODE* node = new NODE;

	//** initialize
	node->next = nullptr;
	node->value = value;

	End->next = node;
	End = node;

	++Length;
}

void pop()
{
	int count = Length;

	NODE* nextNode = List;
	while (0 < count)
	{
		--count;

		nextNode = nextNode->next;
	}
	
	NODE* tempNode = nextNode->next->next;

	delete nextNode->next;
	nextNode->next = nullptr;

	nextNode->next = tempNode;

	--Length;
}


void insert(int count, int value)
{
	// ** ����Ʈ�� ��� �� ������ �������� count�� ���� ũ�ٸ�
	// ** ���� �߰��� �� �����Ƿ� ����.
	if (Length < count)
		return;

	// ** ����Ʈ�� ����.
	NODE* nextNode = List;

	// ** ī��Ʈ�� �� ��ŭ ���� ���� �̵�.
	while (0 < count)
	{
		--count;

		// ** �������� �̵�
		nextNode = nextNode->next;
	}
	// ** �̵��� �����ٸ� ���ο� ��带 �߰�.

	// ** ���ο� ��� ����
	NODE* newNode = new NODE;
	newNode->next = nullptr;
	newNode->value = value;

	// ** ���� ��带 �ӽ��� ����ҿ� ����.
	NODE* tempNode = nextNode->next;

	// ** ������带 �����ϴ� ����ҿ� ���ο� ��带 ��ġ.
	nextNode->next = newNode;

	// ** ���ο� ��尡 ����Ű�� ������带 �ӽð����� �ִ� ���� ��ġ
	newNode->next = tempNode;
}

void remove(int count)
{
	if (Length < count)
		return;

	NODE* nextNode = List;
	//NODE* oldNode = nullptr;

	while (0 < count)
	{
		--count;

		// ** �������� �̵�
		//oldNode = nextNode;
		nextNode = nextNode->next;
	}

	//NODE* tempNode = nextNode->next;

	//oldNode->next = tempNode;

	NODE* tempNode = nextNode->next->next;

	delete nextNode->next;
	nextNode->next = nullptr;

	nextNode->next = tempNode;
	//delete nextNode;
	//nextNode = nullptr;
}

int main(void)
{
	// ** ù��° ���
	// create
	List = new NODE;

	// initialize
	List->next = nullptr;
	List->value = 0;

	End = List;

	//===========================================

	push(10);
	push(20);
	push(30);
	push(40);

	insert(2, 25);

	//remove(3);
	pop();
	push(50);

	// ** �ι�° ��带 nextNode �� �Ѱ��ش�.
	NODE* nextNode = List->next;

	// ** nextNode�� nullptr�� �ƴ϶�� �ݺ�.
	while (nextNode != nullptr)
	{
		// ** ���
		cout << nextNode->value << endl;

		// ** �������� �̵�
		nextNode = nextNode->next;
	}


	return 0;
}