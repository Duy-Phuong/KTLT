#include <stdio.h>

void nhap(int a[][15], int m, FILE* &f)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			fscanf(f, "%d", &a[i][j]);
		}
	}
}
void xuat(int a[][15], int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int a[100][15];
	int m;
	FILE* f = fopen("input.txt", "rt");
	printf("nhap so luong dong m(tuy thuoc vao so luong so nguyen trong tap tin):\n");
	scanf("%d", &m);
	nhap(a, m, f);
	xuat(a, m);
	fclose(f);
}