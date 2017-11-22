#include <stdio.h>
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
int LaPTHoangHau(int a[][MAX], int d, int c, int x, int y)
{
	// xét phần từ có max dòng không
	for (int i = 0; i < c; i++)
	{
		if (a[x][y] < a[x][i])
			return 0;
	}
	// xét phần tử có phải là max cột không
	for (int i = 0; i < d; i++)
	{
		if (a[x][y] < a[i][y])
			return 0;
	}
	// là phần tử lớn nhất trên đường chéo chính của nó
	for (int i = -x; i < d; i++)
	{
		if ((x + i >= 0) && (x + i < d) && (y + i >= 0) && (y + i < c)) 
		{
			if ((a[x + i][y + i] > a[x][y]))
				return 0;
		}
	}
	// là phần tử lớn nhất trên đường chéo phụ của nó
	for (int i = -x; i < d; i++)
	{
		if ((x + i >= 0) && (x + i < d) && (y + i >= 0) && (y + i < c))
		{
			if ((a[x + i][y - i] > a[x][y]))
				return 0;
		}
	}
	return 1;
}

int DuyetPTHoangHauMatrix(int aHH[MAX], int a[][MAX], int d, int c)
{
	int dem = 0;
	for (int i = 0; i < d; i++){
		for (int j = 0; j < c; j++){
			if (LaPTHoangHau(a, d, c, i, j) == 1){
				aHH[dem] = a[i][j];
				dem++;
			}
		}
	}
	return dem;
}

void main()
{
	int aHH[MAX];
	int a[MAX][MAX];
	int d, c;
	Nhap(a, d, c);
	Xuat(a, d, c);
	int HH = DuyetPTHoangHauMatrix(aHH, a, d, c);
	printf("\n So phan tu hoang hau trong mang la: %d\n", HH);
	printf("La cac phan tu: \n");
	for (int i = 0; i < HH; i++)
	{
		printf("%d\t", aHH[i]);
	}
	printf("\n");

}