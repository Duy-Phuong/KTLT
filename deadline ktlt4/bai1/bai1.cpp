#include <stdio.h>
#include <stdlib.h>

void nhap(int* a, int &n)
{
	printf("nhap phan n phan tu: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("nhap phan phan tu thu %d: ", i);
		scanf("%d", &a[i]);
		
	}
}

void xuat(int* a, int n)
{
	printf("\nmang sau khi nhap la:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}

}

bool KiemTraMangDoiXung(int *a, int n)
{
	for (int i = 0; i < n/2; i++)
	{
		if (a[i] != a[n - 1 - i])
		{
			return false;
		}
	}
	return true;
}

void TaoMang(int* a, int n, int* b, int &nb)
{
	nb = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[nb++] = a[i];
		}

	}
}

int Timvtscln(int* a, int n)
{
	int vtscln = -1;// gia su chua co
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			if (vtscln == -1 || vtscln != -1 && a[i] > a[vtscln])
			{
				vtscln = i;
			}
		}
	}
	return vtscln;
}

void xoa(int* a, int &n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	--n;
}

void chen(int* a, int &n, int vt, int x)
{
	for (int i = n - 1; i >= vt; i--)
	{
		a[i + 1] = a[i];
	}
	a[vt] = x;
	++n;
}
void main()
{
	int n, nb;
	int* a = (int*)malloc(15 * sizeof(int));
	int* b = (int*)malloc(15 * sizeof(int));
	nhap(a, n);
	xuat(a, n);
	if (KiemTraMangDoiXung(a, n))
	{
		printf("mang doi xung\n");
	}
	else
	{
		printf("\nmang khong doi xung\n");
	}
	//bai 2
	printf("tao mang voi so chan:\n");
	TaoMang(a, n, b, nb);
	xuat(b, nb);

	//bai 3
	int k = Timvtscln(a, n);
	if (k == -1)
	{
		printf("\nmang toan so le\n");
	}
	else
	{
		printf("\nvi tri so chan lon nhat trong mang la: %d\n", k);
	}
	//bai 4
	printf("mang sau khi xoa tai vi tri so 2 la: \n");
	xoa(a, n, 2);
	xuat(a, n);
	//bai 5
	printf("mang sau khi chen tai vi tri so 1 gia tri 0 la: \n");
	chen(a, n, 1, 0);
	xuat(a, n);

	free(a);
	free(b);
}