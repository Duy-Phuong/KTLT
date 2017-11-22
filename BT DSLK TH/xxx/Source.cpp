#include <stdio.h>
void nhap(int a[100], int &n)
{
	printf("nhap n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("nhap vt thu %d: ", i+1);
		scanf("%d", &a[i]);
	}
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
		
	}
}

void xoa(int a[100], int &n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

void tim(int a[100], int &n, int k)
{
	int dan = 0;
	while (n > 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (dan == 0)
			{
				for (int k = 1; k <= 2; k++)
				{
					
						xoa(a, n, k);
					
				}
			}
		i--;
		if (n == 1)
		{
			break;
		}
		}
	}

}


void test(int a[100], int n, int y)
{
	int songuoi = n;
	int dan = 0;
	while (songuoi > 1)//neu k còn 1 nguoi
	{
		for (int i = 0; i < n;)//duyet hết
		{
			while (i < n)//neu chua het mang thi lap
			{
				if (dan > 0)
				{
					while (a[i + 1] == 0)
					{
						i++;
					}
				}
				if (dan == 0)//het dan
				{
					dan = y;
					while (a[i + 1] == 0)
					{
						i++;
					}
					if (a[i + 1] == 1)
					{
						i++;
					}
					if (songuoi == 1 && a[i] == 1)
					{
						printf("%d\n", i);
						break;
					}
				}
				while (dan != 0)
				{
					if (dan != 0 && a[i] == 1)
					{
						dan--;
						a[i] = 0;
						songuoi--;
						i += 2;
					}
					/*if (songuoi == 1 && a[i] == 1)
					{
						printf("%d\n", i);
						break;
					}*/
					if (dan != 0 && a[i-1] == 0)
					{
						i += 2;
						//break;
						//while (a[i + 1] == 0)
						//{
						//	i++;
						//}
						if (dan != 0 && a[i] == 1)////
						{
							dan--;
							a[i] = 0;
							songuoi--;
							i += 2;
						}
					}
					if (i >= n)
					{
						break;
					}
				}
			}
			/*if (songuoi == 1 && a[i] == 1)
			{
				printf("%d\n", i);
				break;
			}*/
		}
	}
}
void main()
{
	int a[100], n;
	nhap(a, n);
	xuat(a, n);
	printf("\nvi tri con song la:\n");
	test(a, n, 3);
	
	//xuat(a, n);
}
