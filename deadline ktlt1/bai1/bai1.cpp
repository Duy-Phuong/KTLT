//bai 1

#include <stdio.h>
void Nhap(int a[], int &m, int &n)
{
	printf("nhap m dong: ");
	scanf("%d", &m);
	printf("nhap n cot: ");
	scanf("%d", &n);
	printf("\nnhap phan tu tu 1 toi %d\n", m*n);
	for (int i = 0; i < m*n; i++)
	{
		printf("nhap phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
}
void xuat(int a[], int m, int n)
{
	for (int i = 0; i < m*n; i++)
	{
		printf("%d\t", a[i]);
	}
}

void DoMangHinhXoanOc(int a[100][100], int b[], int n, int m)
{
	int c = 0;
	int k = 0;
	while (k < n*m)//nb la so pt cua mang b
	{
	//	for (int i = c; i < (n - c); i++)
	//	{
	//		a[c][i] = b[k++];
	//	}
	//	for (int z = c + 1; z < m - c; z++)
	//	{
	//		a[z][n - c - 1] = b[k++];
	//	}
	//	for (int z = n - c - 2; z >= c; z--)
	//	{
	//		a[m - c - 1][z] = b[k++];
	//	}
	//	for (int z = m - c - 2; z > c; z--)
	//	{
	//		a[z][c] = b[k++];
	//	}
	//	c++;
		//hinh ziczac
		for (int z = 0; z < n; z++)
		{
			a[c][z] = b[k++];
		}
		c++;
		if (k >= n*m)// neu so hang cua ma tran le ta cp the bo vi day la tao mang 2 chieu moi 
			break;
		for (int z = n-1 ; z >= 0; z--)
		{
			a[c][z] = b[k++];
		}
		c++;
	}
}
void XuatMaTran(int a[100][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int b[100], a[100][100];
	int m, n;
	Nhap(b, m, n);
	xuat(b, m, n);
	printf("\nma tran sau khi do la:\n");
	DoMangHinhXoanOc(a, b, n, m);
	XuatMaTran(a, m, n);
}
