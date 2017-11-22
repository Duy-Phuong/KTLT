#include <stdio.h>
#include <stdlib.h>


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

void xuat(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}

void insert(int* a, int &n, int vt, int x)
{
	for (int i = n - 1; i >= vt; i--)
	{
		a[i + 1] = a[i];

	}
	a[vt] = x;
	n++;
}

void bai1(int* &a, int &n)
{
	for (int i = n-1; i >= 0; i--)
	{
		if (a[i] % 2 == 0)
		{
			insert(a, n, i, 0);
		}
	}
	/*printf("\nsau khi chen\n");
	xuat(a, n);*/
}

/*int findMax(int *a, int n, bool &flag){
	int max = -1;
	if (n == 0){
		if (laSoNguyenTo(a[0])){
			flag = true;
			return a[0];
		}
		flag = false;
		return max;
	}
	else{
		if (max < findMax(a, n - 1, flag) && laSoNguyenTo(findMax(a, n - 1, flag))){
			flag = true;
			max = findMax(a, n - 1, flag);
		}
	}
	return max;
}*/
}
}
void main()
{
	int* a;
	int n;
	cau4(a, n);
	xuat(a, n);
	bai1(a, n);
	printf("\nsau khi chen\n");
	//insert(a, n, 2, 0);
	xuat(a, n);
}