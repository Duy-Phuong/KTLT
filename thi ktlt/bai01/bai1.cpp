#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char ma[100];
	char ten[100];
	float dtb;
}HOCSINH;

void nhap(HOCSINH &p)
{
	printf("nhap ma: ");
	fflush(stdin);
	gets(p.ma);
	printf("nhap ten: ");
	fflush(stdin);
	gets(p.ten);
	printf("nhap diem:");
	scanf("%f", &p.dtb);

}

typedef struct node
{
	HOCSINH data;
	struct node* pnext;
}NODE;

typedef struct list
{
	NODE* phead;
	NODE* ptail;
}LIST;

void init(LIST &l)
{
	l.phead = l.ptail = NULL;
}

NODE* getnode(HOCSINH p1)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	else
	{
		p->data = p1;
		p->pnext = NULL;
	}
	return p;
}

void addlast(LIST &l, HOCSINH p1)
{
	NODE* p = getnode(p1);
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

void xuat(HOCSINH p)
{
	printf("\nma: %s ---- ten: %s ----- dtb: %f\n", p.ma, p.ten, p.dtb);

}

void print(LIST l)
{
	printf("danh sach hs\n");
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		xuat(p->data);
	}
}

void nhapdslk(LIST &l)
{
	int n;
	printf("nhap n:");
	scanf("%d", &n);
	HOCSINH p;
	init(l);
	for (int i = 0; i < n; i++)
	{
		nhap(p);
		addlast(l, p);
	}
}

int dtbmax(LIST l)
{
	int max = l.phead->data.dtb;
	for (NODE* p = l.phead->pnext; p != NULL; p = p->pnext)
	{
		if (p->data.dtb > max)
		{
			max = p->data.dtb;
		}
	}
	return max;
}

void timdtbmax(LIST l)
{
	int max = dtbmax(l);
	printf("\nhoc sinh co dtb max la:\n");
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		if (p->data.dtb == max)
		{
			xuat(p->data);
		}
	}
}

void hoanvi(HOCSINH &a, HOCSINH &b)
{
	HOCSINH t = a;
	a = b;
	b = t;
}

void sapxep(LIST &l)
{
	for (NODE* p = l.phead; p != l.ptail; p = p->pnext)
	{
		for (NODE* p1 = l.phead->pnext; p1 != NULL; p1 = p1->pnext)
		{
			if (p->data.dtb > p1->data.dtb)
			{
				hoanvi(p->data, p1->data);
			}
		}
	}
	
}

void file(LIST l)
{
	FILE* f = fopen("output.txt", "wt");
	for (NODE* p1 = l.phead; p1 != NULL; p1 = p1->pnext)
	{
		fprintf(f, "ma: %s\t ten: %s\tdtb: %f\n", p1->data.ma, p1->data.ten, p1->data.dtb);
	}
	fclose(f);
}

//cau 2
int cau2a(int n, int a)
{
	if (n == 0)
	{
		return a;
	}
	if (n == 1)
	{
		return 2*a;
	}
	int x = a;
	int y = 2 * a;
	int f = 0;
	for (int i = 2; i <= n; i++)
	{
		f = 2 * y + 3 * x;
		x = y;
		y = f;
	}
	return f;
}

int cau2b(int a, int M)
{
	if (M < a) 
		return 0;
	if (M < 2*a) 
		return 1;
	int x = a, y = 2 * a, z;
	for (int i = 2;; i++)
	{
		z = 2 * y + 3 * x;
		x = y;
		y = z;
		if (z>M) return i;
	}
}

//cau 4
void cau4(int* &a, int &n)//phai co dau & trk a
{
	printf("nhap n: ");
	scanf("%d", &n);
	a = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("nhap phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
}

void cau4b(int* a, int n)
{
	int max = 0;
	int imax = -1;
	int jmax = -1;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] != a[j] && (a[i] + a[j]) > max)
			{
				max = a[i] + a[j];
				imax = i;
				jmax = j;
			}
		}
	}
	if (max == 0)
	{
		printf("mang toan phan tu giong nhau\n");
	}
	else
	{
		printf("%d va %d la 2 so co tong max bang %d\n", a[imax], a[jmax], max);
	}
}

////----------DE 2-------------
int cau2_de2(int n)
{
	if (n == 0)
	{
		return 3;
	}
	if (n == 1)
	{
		return 4;
	}
	if (n == 2)
	{
		return 5;
	}
	int x = 3;
	int y = 4;
	int z = 5;
	int f = 0;
	for (int i = 3; i <= n; i++)
	{
		f = 3 * z + 4 * y + 5 * x;
		x = y;
		y = z;
		z = f;
	}
	return f;
}

//cau 2 y 2
int cau2_de2_b(int n)
{
	if (n == 3)
	{
		return 0;
	}
	if (n == 4)
	{
		return 1;
	}
	//else// n >= 5
	//{
		int x = 3;
		int y = 4;
		int z = 5;
		int f = 0;
		for (int i = 3; i <= n; i++)
		{
			f = 3 * z + 4 * y + 5 * x;
			x = y;
			y = z;
			z = f;
			/*if (f == n)
				return i;*/
			if (f > n)
				return i-1;
		}
	//}
}

char* STRCAT(char* a, char* b)
{
	int n1 = strlen(a);
	int n2 = strlen(b);
	//char* c = (char*)malloc((n1 + n2 + 1)*sizeof(char));
	char* c = new char[n1 + n2 + 1];
	int nc = 0;
	for (int i = 0; i < n1; i++)
	{
		c[nc++] = a[i];
	}
	for (int j = 0; j < n2; j++)
	{
		c[nc++] = b[j];
	}
	c[n1+n2] = '\0';
	return c;
}

void hoanvi1(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void sapxep1(int* a, int n)
{
	if (n == 0)
		return;
	else
	{
		sapxep1(a, n - 1);
		if (a[n - 2] > a[n - 1])
		{
			hoanvi1(a[n - 2], a[n - 1]);
		}
		sapxep1(a, n - 1);
	}
}

void nhapmang(int *a, int &n)
{
	printf("nhap n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("nhap phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
}
void main()
{
	//cau1
	//LIST l;
	//nhapdslk(l);
	//print(l);
	////timdtbmax(l);
	//printf("\nket qua\n");
	//sapxep(l);
	//file(l);
	//print(l);

	//cau2
	/*int n, a;
	printf("nhap n: ");
	scanf("%d", &n);
	printf("nhap a: ");
	scanf("%d", &a);
	
	printf("dap an la: %d", cau2a(n, a));*/

	/*int a, M;
	printf("nhap M: ");
	scanf("%d", &M);
	printf("nhap a: ");
	scanf("%d", &a);
	printf("dap an la: %d", cau2b(a, M));*/

	//cau 4
	/*int* a;
	int n;
	
	cau4(a, n);
	cau4b(a, n);
	free(a);*/

	///-----DE 2-------
	//cau 2
	//int a;
	//printf("nhap a: ");
	//scanf("%d", &a);
	//printf("dap an la: %d\n", cau2_de2(a)); 

	/*int a;
	printf("nhap a: ");
	scanf("%d", &a);
	printf("dap an la: %d\n", cau2_de2_b(a));*/

	/*char* c;
	char a[] = "abc";
	char b[] = "def";
	c = STRCAT(a, b);
	puts(c);
	delete[]c;*/

	int a[100];
	int n;
	nhapmang(a, n);
	sapxep1(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}

}