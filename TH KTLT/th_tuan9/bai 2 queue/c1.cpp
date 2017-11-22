#include <stdio.h>

#define Max 5 //so phan tu toi da cua Queue
typedef int item; //kieu du lieu

struct Queue
{
	int Front, Rear; //front: phan tu dau hang, rear: phan tu cuoi hang
	item Data[Max]; //Mang cac phan tu
	int count; //dem so phan tu cua Queue
};

void Init(Queue &Q) //khoi tao Queue rong
{
	Q.Front = 0; //phan tu dau
	Q.Rear = -1; // phan tu cuoi o -1 (khong co phan tu trong Q)
	Q.count = 0; //so phan tu bang 0
}

int Isempty(Queue Q) //kiem tra Queue rong
{
	if (Q.count == 0) //so phan tu = 0 => rong
		return 1;
	return 0;
}

int Isfull(Queue Q) //kiem tra Queue day
{
	if (Q.count == Max) //so phan tu = Max => day
		return 1;
	return 0;
}

void Push(Queue &Q, item x) //them phan tu vao cuoi Queue
{
	if (Isfull(Q)) printf("Hang doi day !");
	else
	{
		Q.Data[++Q.Rear] = x; //tang Rear len va gan phan tu vao
		Q.count++; //tang so phan tu len
	}
}

int Pop(Queue &Q) //Loai bo phan tu khoi dau hang doi
{
	if (Isempty(Q)) printf("Hang doi rong !");
	else
	{
		item x = Q.Data[Q.Front];
		for (int i = Q.Front; i<Q.Rear; i++) //di chuyen cac phan tu ve dau hang
			Q.Data[i] = Q.Data[i + 1];
		Q.Rear--; // giam vi tri phan tu cuoi xuong
		Q.count--;//giam so phan tu xuong
		return x; //tra ve phan tu lay ra
	}
}

item Qfront(Queue Q) //xem thong tin phan tu dau hang
{
	if (Isempty(Q)) printf("Hang doi rong !");
	else return Q.Data[Q.Front];
}

void Delete(Queue &Q)
{
	while (!Isempty(Q))
	{
		int x = Pop(Q);
	}
}

void Push_Circular(Queue &Q, item x) //them phan tu vao cuoi hang doi vong
{
	if (Isfull(Q)) printf("Hang doi day !");
	else
	{
		Q.Data[(++Q.Rear) % Max] = x;
		//tang Rear len va gan phan tu vao, Neu Rear dang o vi tri Max-1 thi tang ve vi tri 0
		Q.count++; //tang so phan tu len
	}
}

int Pop_Circular(Queue &Q) //Loai bo phan tu khoi dau hang doi vong
{
	if (Isempty(Q)) printf("Hang doi rong !");
	item x = Q.Data[Q.Front];
	Q.Front = (Q.Front++) % Max; // tang vi tri phan dau tien len, neu dang o Max-1 thi ve 0
	Q.count--;//giam so phan tu xuong
	return x; //tra ve phan tu lay ra
}
void main()
{
	Queue q;
	Init(q);
	if (Isempty(q))
		printf("hang doi rong!\n");
	//3 2 1 
	Push(q, 3);
	Push(q, 2);
	Push(q, 1);
	printf("%d\n", Qfront(q));
	Pop(q);
	printf("%d\n", Qfront(q));
	Delete(q);
	if (Isempty(q))
		printf("hang doi rong!\n");

}