
#include <stdio.h>
#include <conio.h>  
#define MAX 10  


void swap(int &x, int &y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void hoanvi(int mang[], int n, int k)
{
	int j;

	if (k == 1)
	{
		printf("\n");
		for (j = 0; j<n; j++)
			printf("%d ", mang[j]);
	}
	else
	for (j = k - 1; j >= 0; j--)
	{
		swap(mang[k - 1], mang[j]);
		hoanvi(mang, n, k - 1);
		swap(mang[j], mang[k - 1]);
	}
}

void main()
{
	int mang[MAX], n;
	int i;
	printf("\nCho biet so phan tu (N < 10) : ");
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		mang[i] = i + 1;
	hoanvi(mang, n, n);
	getch();
}