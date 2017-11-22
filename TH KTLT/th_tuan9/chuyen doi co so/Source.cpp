#include <stdio.h>

#define Max 100 //so phan tu toi da cua Stack
typedef char item; //kieu du lieu cua Stack
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

int Pop(Stack &S) //Loai bo phan tu khoi Stack
{
	if (!Isempty(S))
	{
		S.Top--; //Giam Top
		return S.Data[S.Top]; //Lay du lieu tai Top
	}
}

void main()
{
	char num[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	Stack S; // khai bao Stack voi kieu du lieu la int

	int coSo, n, du;

	printf("Nhap so can chuyen: ");
	scanf("%d", &n);

	printf("Nhap co so can chuyen: ");
	scanf("%d", &coSo);

	Init(S);

	// chuyen doi bang cach dua vao Stack
	while (n != 0) 
	{
		du = n % coSo;
		Push(S, num[du]);
		n = n / coSo;
	}

	// Xuat ra
	while (!Isempty(S)) 
	{
		printf("%c", Pop(S));
		//Pop(S);
	}

}