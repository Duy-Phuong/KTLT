#include <stdio.h>
#include <stdlib.h>

typedef int item; //kieu du lieu
struct Node
{
	item Data;
	Node * Next;
};

struct Queue
{
	Node *Front, *Rear; //Node dau va Node cuoi
	int count; //dem so phan tu
};

void Init(Queue &Q)
{
	Q.Front = Q.Rear = NULL;
	Q.count = 0;
}

int Isempty(Queue Q) //kiem tra Queue rong
{
	if (Q.count == 0) //so phan tu = 0 => rong
		return 1;
	return 0;
}

Node *MakeNode(item x) //tao 1 Node
{
	Node *P = (Node*)malloc(sizeof(Node));
	P->Next = NULL;
	P->Data = x;
	return P;
}

void Push(Queue &Q, item x) //them phan tu vao cuoi Queue
{
	Node *P = MakeNode(x); //Neu Q rong
	if (Isempty(Q))
	{
		Q.Front = Q.Rear = P; //dau va cuoi deu tro den P
	}
	else //Khong rong
	{
		Q.Rear->Next = P;
		Q.Rear = P;
	}
	Q.count++; //tang so phan tu len
}

item Qfront(Queue Q) //xem thong tin phan tu dau hang
{
	if (Isempty(Q)) 
		printf("Hang doi rong !");
	else
		return Q.Front->Data;
}

int Pop(Queue &Q) //Loai bo phan tu khoi dau hang doi
{
	if (Isempty(Q))
	{
		printf("Hang doi rong !");
		return 0;
	}
	else
	{
		Node* p;
		p = Q.Front;
		item x = Q.Front->Data;
		if (Q.count == 1) //neu co 1 phan tu
			Init(Q);
		else
			Q.Front = Q.Front->Next;
		Q.count--;
		if (Q.count < 0)
		{
			Q.count = 0;
		}
		//p->Next = NULL;
		free(p);
		return x; //tra ve phan tu lay ra
	}
}

void Delete(Queue &Q)
{
	while (!Isempty(Q))
	{
		int x = Pop(Q);
		//printf("%d\n", Qfront(Q));
	}
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
	Pop(q);
	
	Delete(q);
	if (Isempty(q))
		printf("hang doi rong!\n");
}