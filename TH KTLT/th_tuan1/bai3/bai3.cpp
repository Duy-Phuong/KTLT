#include <stdio.h>

typedef struct
{
	int heso;
	int dong;
}MANG;

void nhap(int a[][100], int &m, int &n)
{
	printf("nhap so dong: ");
	scanf("%d", &m);
	printf("nhap so sot: ");
	scanf("%d", &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("nhap phan tu thu a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void hoanvidong(int a[][100], int m, int n, int k, int h)
{
	int t;
	for (int i = 0; i < n; i++)
	{
		t = a[k][i];
		a[k][i] = a[h][i];
		a[h][i] = t;

	}
}

void MaxDong(int a[][100], int m, int n, MANG b[], int &k)
{
	int max;
	k = 0;
	for (int i = 0; i < m; i++)
	{
		max = a[i][0];
		for (int j = 0; j < n; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
		b[k].heso = max;
		b[k].dong = i;
		k++;
	}
}

void sapxep(int a[][100], int m, int n, MANG b[100], int k)
{
	for (int i = 0; i < m-1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (b[i].heso > b[j].heso)
			{
				hoanvidong(a, m, n, b[i].dong, b[j].dong);
			}
		}
	}
}

//
void MaxDong1(int a[][100], int m, int n, int b[], int &k)
{
	int max;
	k = 0;
	for (int i = 0; i < m; i++)
	{
		max = a[i][0];
		for (int j = 0; j < n; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
		b[k] = max;
		//b[k].dong = i;
		k++;
	}
}

void sapxep1(int a[][100], int m, int n, int b[100], int k)
{
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (b[i] > b[j])
			{
				hoanvidong(a, m, n, i, j);
			}
		}
	}
}
void main()
{
	int a[100][100];
	int b[100];
	int k;
	int m, n;
	nhap(a, m, n);
	xuat(a, m, n);
	MaxDong1(a, m, n, b, k);
	sapxep1(a, m, n, b, k);
	xuat(a, m, n);

}