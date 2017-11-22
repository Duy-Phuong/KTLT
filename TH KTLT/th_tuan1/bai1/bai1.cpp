#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void Nhap(int a[][MAX], int &d, int &c)
{
	do
	{
		printf("So dong: ");
		scanf_s("%d", &d);
	} while (d < 1);
	do
	{
		printf("So cot: ");
		scanf_s("%d", &c);
	} while (c < 1);

	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("nhap phan tu thu a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}
void Xuat(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d \t", a[i][j]);
		}
		printf("\n");
	}
}

int LaPhanTuMax(int a[][MAX], int d, int c, int x, int y)
{
	for (int i = -1; i < 2; i++)
	{
		if (x + i >= 0 && x + i < d)
		{
			for (int j = -1; j < 2; j++)
			{
				if (y + j >= 0 && y + j < c)
				{
					if (a[x][y] < a[x + i][y + j])
						return 0;
				}
			}
		}
	}
	return 1;
}
int DemPhanTuCucDaiTrongMang(int b[], int a[][MAX], int d, int c)
{
	int dem = 0;
	for (int i = 0; i < d; i++){
		for (int j = 0; j < c; j++){
			if (LaPhanTuMax(a, d, c, i, j) == 1)
			{
				b[dem] = a[i][j];
				dem++;
			}
		}
	}
	return dem;
}

void main()
{
	int a[MAX][MAX];
	int d, c;
	Nhap(a, d, c);
	Xuat(a, d, c);
	int b[MAX];
	int k = DemPhanTuCucDaiTrongMang(b, a, d, c);
	printf("So phan tu cuc dai trong mang la: %d\n\n", k);
	printf("la cac phan tu: \n\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d\t", b[i]);
	}
}