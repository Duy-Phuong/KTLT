#include <stdio.h>
#include <stdlib.h>

typedef struct node* ref;

struct node
{
	int key;
	ref next;

};

ref getnode(int x)
{
	ref p = (ref)malloc(sizeof(struct node));
	if (p == NULL)
		return NULL;
	p->key = x;
	p->next = NULL;
	return p;
}

void addFirst(ref& head, ref& tail, int x)
{
	ref p = getnode(x);
	if (head == NULL)
	{
		head = tail = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}

void addTail(ref& head, ref& tail, int x)
{
	ref p = getnode(x);
	if (head == NULL)
	{
		head = tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}

void insert(ref p, int k)
{
	getnode(k);
	ref q;
	q->next = p->next;
	p->next = q;
}

void insertbefore(ref head, ref q, int k)//ham co chi phi tuyen tinh
{
	ref r;
	ref p = getnode(k);
	for (r = head; r->next != q; r = r->next);
	p->next = q;
	r->next = p;

}

void print(ref head)
{
	for (ref p = head; p != NULL; p = p->next)
	{
		printf("%d\t", p->key);
	}
}

void destroy(ref& head)//phai truyen tham bien de head tra ve NULL khi thuc hien xong
{
	ref q;
	while (head)
	{
		q = head;
		head = head->next;
		free(q);
	}
}
void main()
{
	int x;
	//int z;
	ref head, tail;
	head = tail = NULL;
	while (1)
	{
		printf("nhap x(neu x = 0 thoat): ");
		scanf("%d", &x);

		if (x == 0)
			break;
		//addFirst(head, tail, x);
		addTail(head, tail, x);

	}
	print(head);
	//destroy(head);
	
	print(head);
}