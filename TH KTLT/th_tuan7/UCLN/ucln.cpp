#include <stdio.h>

//bai 1
int UCLN(int a, int b)
{
	if (a == b)
		return a;
	if (a > b)
		return UCLN(a - b, b);
	else
		return UCLN(b - a, a);
}
int TimUCLN(int n, int c[])
{
	if (n == 2)
		return UCLN(c[0], c[1]);
	return UCLN(c[n-1],TimUCLN(n - 1, c));
}
//bai 5
int Fibo(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return Fibo(n - 1) + Fibo(n - 2);
}
void main()
{
	// bai1
	int n, a, b;
	int c[100];
	printf("bai 1\n");
	printf("nhap so phan tu n(n >= 2):");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("nhap phan tu thu %d: ", i);
		scanf("%d", &c[i]);
	}
	printf("uoc chung lon nhat cua day la: %d\n", TimUCLN(n, c));
	//bai 5
	int n5;
	printf("bai 5\n");
	printf("nhap n:");
	scanf("%d", &n5);
	// printf("ket qua cua day fibonacci la: %d\n", Fibo(n));
	for (int i = 0; i <= n5; i++)
	{
		printf("%d\t", Fibo(i));
	}
}