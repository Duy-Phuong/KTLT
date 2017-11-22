#include <stdio.h>

typedef struct node
{
	int x;
	struct node* pnext;
}NODE;

typedef struct list
{
	NODE* phead;
	NODE* ptail;
}LIST;

void Init(LIST &l)
{
	l.phead = l.ptail = NULL;
}

NODE* getNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->x = x;
		p->pnext = NULL;
	}
	return p;
}
void addLast(LIST &l, int x)
{
	NODE* p = getNode(x);
	if (p == NULL)
	{
		return;
	}
	else
	{
		if (l.phead == NULL)
		{
			l.phead = l.ptail = p;
		}
		else
		{
			l.ptail->pnext = p;
			l.ptail = p;
		}
	}
}

void print(LIST l)
{
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		printf("%4d", p->x);
	}
}


int countNode(LIST l)
{

	NODE* p = l.phead;
	int i = 0;
	while (p != NULL)
	{
		p = p->pnext;
		i++;
	}
	return i;
}

NODE* findMid(LIST l)
{
	NODE* p = l.phead;
	int n = countNode(l);
	if (n == 0)
		return NULL;
	for (int i = 1; i < (n + 1) / 2; i++)
		p = p->pnext;
	return p;
}


void tach(LIST l, LIST& l1, LIST &l2)
{
	NODE* mid = findMid(l);
	l1.phead = l.phead;
	l1.ptail = mid;
	l2.phead = mid->pnext;
	l2.ptail = l.ptail;
	mid->pnext = NULL;

}

LIST merge(LIST l1, LIST l2)// ham tron 2 ds da tang
{
	if (l2.phead == NULL)
		return l1;
	if (l1.phead == NULL)
		return l2;
	//khoi tao
	LIST l;
	Init(l);

	NODE* p = l1.phead;
	NODE* q = l2.phead;
	while (p != NULL && q != NULL)
	{
		if (p->x < q->x)
		{
			addLast(l, p->x);
			p = p->pnext;
		}
		else
		{
			addLast(l, q->x);
			q = q->pnext;
		}
	}

	while (p != NULL)
	{
		addLast(l, p->x);
		p = p->pnext;
	}

	while (q != NULL)
	{
		addLast(l, q->x);
		q = q->pnext;
	}
	return l;

}

void mergesort(LIST &l)
{
	if (l.phead == l.ptail)
		return;
	LIST l1;
	Init(l1);
	LIST l2;
	Init(l2);
	tach(l, l1, l2);
	mergesort(l1);
	mergesort(l2);
	l = merge(l1, l2);

}

void main()
{
	LIST l;
	Init(l);
	addLast(l, 3);
	addLast(l, 5);
	addLast(l, 1);
	addLast(l, 4);
	addLast(l, 9);
	addLast(l, 3);
	print(l);
	//merge_sort(l);
	//print(l);

	/*NODE* p = findMid(l);
	printf("\n%d\n", p->x);
		LIST l1;
		Init(l1);
		LIST l2;
		Init(l2);
		tach(l, l1, l2);
		printf("\nlist 1: \n");
		print(l1);
		printf("\nlist 2: \n");
		print(l2);
		LIST l3;
		Init(l3);
		l3 = merge(l1, l2);
		printf("\nlist 3: \n");
		print(l3);*/
	mergesort(l);
	printf("\nlist l: \n");
	print(l);
}



