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

int length(LIST l)
{
	int i = 0;
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		printf("%4d", p->x);
		i++;
	}
	return i;
}

NODE* GetNodePointer(LIST l, int index)
{
	int chiso = 0;
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		if (chiso == index)
		{
			return p;
		}
		chiso++;
	}
	return NULL;
}


void QuickSort(LIST &l)
{
	LIST l1;
	LIST l2;
	NODE* tag;
	NODE* p;
	if (l.phead == l.ptail)//dk dung dung thu tu
	{
		return;
	}
	Init(l1);
	Init(l2);
	//co lap tag
	tag = l.phead;
	l.phead = l.phead->pnext;
	tag->pnext = NULL;
	while (l.phead != NULL)
	{
		p = l.phead;
		l.phead = l.phead->pnext;
		p->pnext = NULL;
		if (p->x <= tag->x)
		{
			addLast(l1, p->x);
		}
		else
		{
			addLast(l2, p->x);
		}
	}
	QuickSort(l1);
	QuickSort(l2);
	if (l1.phead != NULL)
	{
		l.phead = l1.phead;
		l1.ptail->pnext = tag;
	}
	else
	{
		l.phead = tag;
	}
	tag->pnext = l2.phead;
	if (l2.phead != NULL)
	{
		l.ptail = l2.ptail;
	}
	else
	{
		l.ptail = tag;
	}
}

//ham tron 2 danh sach da sap xep thanh danh sach moi theo dung thu tu
//lan luot kt 2 phan tu dau lay pt co gia tri nhỏ hon -- chen vao cuoi l den khi ca 2 rong
LIST Merge(LIST l1, LIST l2)
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

//
NODE* Getmid(LIST l)
{
		NODE* p = l.phead;
		int n = length(l);
		if (n == 0)
			return NULL;
		for (int i = 1; i < (n + 1) / 2; i++)
			p = p->pnext;
		return p;
}

void tach(LIST l, LIST &l1, LIST &l2)
{
	NODE* mid = Getmid(l);
	Init(l1);
	Init(l2);
	mid->pnext = NULL;
	//l1.phead = l.phead;
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		addLast(l1, p->x);
	}
	for (NODE* p = mid; p != NULL; p = p->pnext)
	{
		addLast(l2, p->x);
	}
}

void mergesort(list &l)
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
	l = Merge(l1, l2);
}

void hoanvi(int &x, int &y)
{
	int t = x;
	x = y; 
	y = t;
}
void selectionsort(LIST &l)
{
	NODE* min;
	for (NODE* p = l.phead; p != l.ptail; p = p->pnext)
	{
		min = p;
		for (NODE* p1 = p->pnext; p1 != NULL; p1 = p1->pnext)
		{
			if (min->x > p1->x)
			{
				min = p1;
			}			
		}
		hoanvi(min->x, p->x);
	}
}

NODE* NodeBefore(LIST S, NODE* p)
{
	if (p == S.phead)
	{
		return NULL;
	}
	else
	{
		NODE* pNode = S.phead;
		while (pNode != NULL)
		{
			if (pNode->pnext == p)
			{
				return pNode;
			}
			pNode = pNode->pnext;
		}
	}
}
void InSertSort(LIST S)
{
	for (NODE* p = S.phead->pnext; p != NULL; p = p->pnext)
	{
		int x = p->x;
		NODE* pNode = NodeBefore(S, p);
		while (pNode != NULL && pNode->x > x)
		{
			p->x = pNode->x;
			pNode = NodeBefore(S, pNode);
			p = NodeBefore(S, p);
		}
		if (pNode == NULL)
		{
			S.phead->x = x;
		}
		else
		{
			pNode = pNode->pnext;
			pNode->x = x;
		}
	}
}  


//bai2
void nhap(int** a, int &m, int &n)
{
	
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("nhap phan tu thu a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void xuat(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d   ", a[i][j]);
			
		}
		printf("\n");
	}
}

void sapxepc1(int** a, int m, int n)
{
	int z = m*n;
	for (int i = 0; i < z - 1; i++)
	{
		for (int j = i+1; j < z; j++)
		{
			if (a[i/n][i%n] > a[j/n][j%n])
			{
				hoanvi(a[i/n][i%n], a[j/n][j%n]);
			}
		}
	}

}

void DoMang2ChieuSangMang1Chieu(int** a, int m, int n, int* b, int &nb)
{
	nb = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[nb++] = a[i][j];
		}
	}
}


void SapXepMang1Chieu(int* b, int nb)
{
	for (int i = 0; i < nb - 1; i++)
	{
		for (int j = i + 1; j < nb; j++)
		{
			if (b[i] > b[j])
			{
				hoanvi(b[i], b[j]);
			}
		}
	}
}
void DoMangHinhziczac(int** a, int b[], int n, int m)
{
	int c = 0;
	int k = 0;
	while (k < n*m)
	{
		//hinh ziczac
		for (int z = 0; z < n; z++)
		{
		a[c][z] = b[k++];
		}
		c++;
		if (k >= n*m)// neu so hang cua ma tran le
			break;
		for (int z = n-1 ; z >= 0; z--)
		{
		a[c][z] = b[k++];
		}
		c++;
	}
}
void main()
{
	//LIST l;
	//Init(l);
	//printf("\n--------insertonsort---------\n");
	//addLast(l, 3);
	//addLast(l, 5);
	//addLast(l, 1);
	//addLast(l, 4);
	//addLast(l, 9);
	//print(l);
	//InSertSort(l);
	//
	//printf("\n");
	//print(l);
	//printf("\n---------quicksort---------\n");
	//LIST l1;
	//Init(l1);
	//addLast(l1, 2);
	//addLast(l1, 0);
	//addLast(l1, 1);
	//addLast(l1, 9);
	//addLast(l1, 6);
	//printf("\n");
	//print(l1);
	//QuickSort(l1);
	//printf("\n");
	//print(l1);
	//printf("\n---------quicksort---------\n");
	//LIST l12;
	//Init(l12);
	//addLast(l12, 2);
	//addLast(l12, 0);
	//addLast(l12, 1);
	//addLast(l12, 9);
	//addLast(l12, 6);
	//printf("\n");
	//print(l1);
	//selectionsort(l);
	//printf("\n");
	//print(l1);


	/*int m, n;
	printf("nhap m dong: ");
	scanf("%d", &m);
	printf("nhap n cot: ");
	scanf("%d", &n);
	int** a = new int*[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}

	printf("\n------------------cach 1------------------\n");
	nhap(a, m, n);
	xuat(a, m, n);
	printf("\nmang sau khi sap xep bang cach 1\n");
	sapxepc1(a, m, n);
	xuat(a, m, n);*/

	printf("\n------------------cach 2------------------\n");
	int m1, n1;
	
	printf("nhap m dong: ");
	scanf("%d", &m1);
	printf("nhap n cot: ");
	scanf("%d", &n1);
	int** a1 = new int*[m1];
	for (int i = 0; i < m1; i++)
	{
		a1[i] = new int[n1];
	}
	nhap(a1, m1, n1);
	xuat(a1, m1, n1);
	printf("\nmang sau khi sap xep bang cach 2\n");
	int nb;
	int z = m1*n1;
	int* b = new int[z];
	
	DoMang2ChieuSangMang1Chieu(a1, m1, n1 , b, nb);
	for (int i = 0; i < nb; i++)
	{
		printf("%d  ", b[i]);
	}
	SapXepMang1Chieu(b, nb);
	printf("\n");
	for (int i = 0; i < nb; i++)
	{
		printf("%d  ", b[i]);
	}
	DoMangHinhziczac(a1, b, n1, m1);
	printf("\n");
	xuat(a1, m1, n1);

	delete[] a1;
	//delete[] a;
	delete[] b;
}