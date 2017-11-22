#include <stdio.h>

//khai bao
typedef struct tagnote
{
	int data;
	struct tagnote* pNext;

}NODE;

typedef struct taglist
{
	NODE* pHead;
	NODE* pTail;
}LIST;

//khởi tạo
void INIT(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

//NHAP note
NODE* getnote(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}

//them dau
void addhead(LIST &l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addtail(LIST &l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

//nhap mang
void nhap(LIST &l, int a)
{
	INIT(l);
	int n;
	for (int i = 0; i < a; i++)
	{
		printf("nhap  n:");
		scanf("%d", &n);
		NODE* p = getnote(n);
		addhead(l, p);
	}
}

void xuat(LIST l)
{
	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		printf("%4d", p->data);
		
	}
}



/*void GiaiPhong(LIST &l)
{
	NOTE *p; // Khai báo Node p.
	while (l.phead != NULL)
	{
		p = l.phead; // Cho p trỏ tới Head
		l.phead = l.phead->pnext; // Head trốn sang thằng bên cạnh
		delete p; // giải phóng p (cũng chính là giải phóng Head ban đầu)
	}
}*/
void main()
{
	LIST l;
	nhap(l, 5);
	xuat(l);
	//GiaiPhong(l);

}