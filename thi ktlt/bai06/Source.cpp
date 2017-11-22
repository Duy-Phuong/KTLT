#include <stdio.h>
#include <string.h>


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

//xoa
void removeafter(LIST &l, NODE* q)
{
	NODE* r;
	if (q != l.ptail)
	{
		r = q->pnext;
		q->pnext = r->pnext;
		if (l.phead == NULL)
		{
			l.ptail = NULL;
		}
	}
}



NODE* getnodeprevious(LIST l, NODE* q)
{
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		if (p->pnext == q)
		{
			return p;
		}
	}
	return NULL;
}

void removehead(LIST &l)
{
	NODE* r = l.phead;
	l.phead = r->pnext;
	if (l.phead == NULL)
		l.ptail = NULL;
}

void removetail(LIST &l)
{
	if (l.phead == l.ptail)
	{
		l.phead = l.ptail = NULL;
	}
	else
	{
		NODE* q = getnodeprevious(l, l.ptail);
		removeafter(l, q);
	}
}

void xoa(LIST &l)
{
	NODE* q;

	for (NODE* p = l.phead->pnext; p != NULL; p = p->pnext)//ham xoa sau phai chay tu l.phead-> pnext
	{
		if (p->data.dtb < 5)
		{
			//xuat(p->data);
			q = getnodeprevious(l, p);
			removeafter(l, q);
		}
	}
	if (l.phead->data.dtb < 5)
	{
		removehead(l);
	}
}
//cau 3
int chuyensangnhiphan(int n)
{
	int k = 1, s = 0;
	while (n > 0)
	{
		int x = n % 2;
		n = n / 2;
		s = s + k*x;
		k = k * 10;
	}
	return s;
}

void nhiphan(int n)
{
	if (n / 2 == 0)
		printf("%d", n%2);
	else
	{
		nhiphan(n / 2);
		printf("%d", n % 2);// de truoc chia sau
	}
}

//bai 6
void sodao(int n) // n>=0
{
	if (n / 10 == 0)
		printf("%d", n % 10);
	else
	{
		printf("%d", n % 10);// de truoc chia truoc
		sodao(n / 10);

	}
}

void chuyensangnhiphansangthapphan(char* filename)
{
	FILE* fp = fopen(filename, "rb");
	int a[100][100];
	int m, n;
	
	fread(&m, sizeof(int), 1, fp);
	fread(&n, sizeof(int), 1, fp);
	printf("%d\t%d\n", m, n);;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fread(&a[i][j], sizeof(int), 1, fp);
			printf("%d\t", a[i][j]);
		}
	}
	fclose(fp);

}

void chuyensangnhiphan(char* filename)
{
	FILE* fp = fopen(filename, "wb");
	int a[100][100];
	int m, n;
	printf("nhap m: ");
	scanf("%d", &m);
	printf("nhap n: ");
	scanf("%d", &n);
	fwrite(&m, sizeof(int), 1, fp);
	fwrite(&n, sizeof(int), 1, fp);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("nhap phan tu a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
			fwrite(&a[i][j], sizeof(int), 1, fp);
		}
		printf("\n");
	}
	fclose(fp);

}
void main()
{
	//cau 3
	/*int n;
	printf("nhap n: ");
	scanf("%d", &n);
	printf("%d sau khi chuyen sang nhi phan la: %d\n", n, chuyensangnhiphan(n));
	nhiphan(n);*/
	//cau 5
	/*LIST l;
	nhapdslk(l);
	print(l);
	xoa(l);
	printf("\nket qua\n");
	print(l);*/

	//cau2
	/*char s[100] = "input.txt";
	chuyensangnhiphan(s);
	chuyensangnhiphansangthapphan(s);*/
	printf("%d", sizeof(int));
}







