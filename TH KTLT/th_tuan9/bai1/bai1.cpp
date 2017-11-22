#include <stdio.h>

#define Max 100 //so phan tu toi da cua Stack
typedef int item; //kieu du lieu cua Stack
struct Stack
{
	int Top; //Dinh Top
	item Data[Max]; //Mang cac phan tu
};

void Init(Stack &S) //khoi tao Stack rong
{
	S.Top = 0; //Stack rong khi Top la 0
}

int Isempty(Stack S) //kiem tra Stack rong
{
	return (S.Top == 0);
}

int Isfull(Stack S) //kiem tra Stack day
{
	return (S.Top == Max); //
}

void Push(Stack &S, item x) //them phan tu vao Stack
{
	if (!Isfull(S))
	{
		S.Data[S.Top] = x; //Gan du lieu
		S.Top++; //Tang Top len 1
	}
}

int Peak(Stack S) //Lay phan tu o dau Stack nhung khong xoa
{
	return S.Data[S.Top - 1]; //Lay du lieu tai Top
}

int Pop(Stack &S) //Loai bo phan tu khoi Stack
{
	if (!Isempty(S))
	{
		S.Top--; //Giam Top
		return S.Data[S.Top]; //Lay du lieu tai Top
	}
}

void Delete(Stack &S)
{
	while (!Isempty(S))
	{
		int x = Pop(S);
	}
}

void main()
{
	Stack s;
	Init(s);
	if (Isempty(s))
		printf("ngan xep rong!\n");
	Push(s, 3);
	Push(s, 2);
	Push(s, 1);
	printf("%d\n", Peak(s));
	Pop(s);
	printf("%d\n", Peak(s));
	Delete(s);
	if (Isempty(s))
		printf("ngan xep rong!\n");
	int Front = 0;
	int z = (++Front) % 4;
	z = (++Front) % 4;
	z = (++Front) % 4;
	z = (++Front) % 4;
	z = (++Front) % 4;
	z = (++Front) % 4;
	z = (++Front) % 4;
}