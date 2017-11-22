#include <stdio.h>
#include <math.h>

/*int tangdan(int *a, int n, int i) //gán i=0 ở hàm main
{
if (i == n - 1) return 1;
if (a[i]>a[i + 1]) return 0;
return(a, n, i + 1);
}
Bài 2
int mangdx(int *a, int n, int i) //gán i=0 ở hàm main
{
if (i >= n - 1 - i) return 1;
if (a[i] != a[n - 1 - i]) return 0;
return mangdx(a, n, i + 1);
}
Bài 3
void sodao(long n)
{
if (n<0) n = -n;
printf("%d", n % 10);
if (n / 10 != 0) return sodao(n / 10);
}*/

//bai 1
int GiaiThua(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return GiaiThua(n - 1)*(n);
}
//bai 2
int USCLN(int a, int b)
{
	if (a == b)
		return a;
	if (a>b)
		return USCLN(a - b, b);
	return USCLN(a, b - a);
}

//bai3
int TinhTong(int a[], int n)
{
	if (n == 0)
	{
		return 0;
	}
	return TinhTong(a, n - 1) + a[n - 1];
}

//bai 4
int tangdan(int *a, int n, int i) //gan i=0 ở hàm main
{
	if (i == n - 1)
		return 1;
	
	if (a[i]>a[i + 1])
		return 0;
	return tangdan(a, n, i+1);
}


void nhap(int a1[], int &n1)
{
	printf("nhap so phan tu:\n");
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		printf("Nhap phan tu a[%d]: ", i);
		scanf("%d", &a1[i]);
	}
}

//bai 5
int doixung(int *a, int n, int i) //gán i=0 ở hàm main
{
	if (i >= n - 1 - i)
		return 1;
	if (a[i] != a[n - 1 - i])
		return 0;
	return doixung(a, n, i + 1);
}

//bai 6
void sodao(int n) // n>=0
{
	/*if (n<0) return;
	printf("%d", n % 10);
	if (n / 10 != 0)
		return sodao(n / 10);*/
	if (n / 10 == 0)
		printf("%d", n%10);
	else
	{
		printf("%d", n % 10);// de truoc chia truoc
		sodao(n / 10);
		
	}
}

//bai 7
float Bai_07(int n)
{
	if (n == 0)
		return 0;
	return sqrt(Bai_07(n - 1) + 2 * n);
}

//bai 8
int Mu(int x, int n)
{
	if (n == 0)
		return 1;
	return Mu(x, n - 1) * x;
}

float bai_08(int x, int n)
{
	if (n == 0)
		return x;
	return bai_08(x, n - 1) + (float)(Mu(x, 2 * n + 1)* Mu(-1, n)) / GiaiThua(2 * n + 1);

}

//bai 9
float bai_09(int x, int n)
{
	if (n == 0)
		return 1;
	return bai_09(x, n - 1) + (float)(Mu(x, 2 * n)* Mu(-1, n)) / GiaiThua(2 * n);

}

//bai 10
void hoanvi(int &x, int &y)
{
	int t = x; 
	x = y;
	y = t;
}

void Quicksort1(int a[], int L, int R);

void Quicksort(int a[], int n)
{
	Quicksort1(a, 0, n-1);
}
void Quicksort1(int a[], int L, int R)
{
	int i = L;
	int j = R;
	int x = a[(L + R) / 2];
	do
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			hoanvi(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (L < j)
		Quicksort1(a, L, j);
	if (i > R) 
		Quicksort1(a, i, R);
}
void main()
{
	//bai 1
	//int n;
	//printf("nhap bai 1:\n");
	//printf("nhap n:\n");
	//scanf("%d", &n);
	//printf("giai thu cua %d la: %d\n", n, GiaiThua(n));
	////bai 2
	//int a, b;
	//printf("nhap bai 2:\n");
	//printf("Nhap 2 so nguyen a va b: ");
	//scanf("%d%d", &a, &b);
	//int c = USCLN(a, b);
	//printf("Uoc so chung lon nhat cua %d va %d la: %d\n", a, b, c);
	////bai 3
	//int a1[100];
	//int n1;
	//printf("nhap bai 3:\n");
	//nhap(a1, n1);
	//if (n>0)
	//{
	// printf("Mang a vua nhap la: ");
	// for (int i = 0; i<n1; i++)
	// printf("%d\t", a1[i]);
	//}
	//int kq = TinhTong(a1, n1);
	//printf("\nTong cac phan tu cua mang bang %d\n", kq);
	//bai 4
	/*int a2[100];
	int n2;
	printf("nhap bai 4:\n");
	nhap(a2, n2);
	int i = 0;
	if (tangdan(a2, n2, i) == 0)
	{
	printf("mang khong tang dan\n");
	}
	else
	{
	printf("mang tang dan\n");
	}*/
	////bai 5
	//int a3[100];
	//int n3, i1 = 0;
	//printf("nhap bai 5:\n");
	//nhap(a3, n3);
	//if (doixung(a3, n3, i1) == 0)
	//{
	//	printf("mang khong doi xung\n");
	//}
	//else
	//{
	//	printf("mang doi xung\n");
	//}
	////bai 6
	/*int n4;
	printf("nhap bai 6:\n");
	printf("nhap n:\n");
	scanf("%d", &n4);
	printf("\nso dao la:\n");
	sodao(n4);*/

	////bai 7
	/*float n5;
	printf("\nnhap bai 7:\n");
	printf("nhap n:\n");
	scanf("%f", &n5);
	n5 = Bai_07(n5);
	printf("ket qua bai 7 la: %f\n", n5);*/

	//bai 8
	/*int n6, x;
	printf("\nnhap bai 8:\n");
	printf("nhap n:\n");
	scanf("%d", &n6);
	printf("nhap x:\n");
	scanf("%d", &x);
	printf("ket qua bai 8 la: %f\n", bai_08(x, n6));*/

	////bai 9
	//int n7, x1;
	//printf("\nnhap bai 9:\n");
	//printf("nhap n:\n");
	//scanf("%d", &n7);
	//printf("nhap x:\n");
	//scanf("%d", &x1);
	//printf("ket qua bai 9 la: %f\n", bai_09(x1, n7));

	//bai 10
	int a3[100];
	int n8;
	printf("nhap bai 10:\n");
	nhap(a3, n8);
	Quicksort(a3, n8);
	for (int i = 0; i < n8; i++)
	{
		printf("%d\t ", a3[i]);
	}


}