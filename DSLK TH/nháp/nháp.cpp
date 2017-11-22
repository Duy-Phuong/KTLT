#include <stdio.h>
#include <math.h>

typedef struct
{
	int x;
} Data;

typedef struct tagNode
{
	Data info;
	struct tagNode* pNext;
} Node;

typedef struct tagList
{
	Node* pHead;
	Node* pTail;
} List;

void InitList(List& l)
{
	l.pHead = l.pTail = NULL;
}

Node* CreateNode(Data info)
{
	Node* p = new  Node;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->info = info;
		p->pNext = NULL;
	}
	return p;
}

void AddHead(List& l, Node* pNewNode)
{
	if (l.pHead == NULL) // Tức là danh sách bị rỗng
	{
		l.pHead = l.pTail = pNewNode;
	}
	else
	{
		pNewNode->pNext = l.pHead; // p quăng dây để tham gia vào danh sách
		l.pHead = pNewNode; // p chính thức đã đứng dầu danh sách
	}
}

Node* AddHead(List& l, Data info)
{
	Node* p = CreateNode(info);
	if (p == NULL)
		return NULL;

	else
	{
		AddHead(l, p);
		return p;
	}
	return NULL;
}

void PrintList(List l, char* str)
{
	printf("%s", str);
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		printf("%4d", p->info.x);
	}
}

float Bai20(int n, int start)	// Lần đầu tiên gọi start = n 
{
	if (n == 0)
	{
		return 0;
	}

	return sqrt((start - n + 1) + Bai20(n - 1, start));
}
void main()
{
	/*int n, i = 0;
	scanf("%d", &n);
	float x = Bai20(n, n);
	printf("%f\n", x);*/
	List l;

	// Khởi tạo dslk
	InitList(l);

	// Chèn nút có giá trị 8 vào đầu dslk
	Data info;
	info.x = 8;
	AddHead(l, info);
	PrintList(l, "Chen nut 8 vao dau:\t\t");
}