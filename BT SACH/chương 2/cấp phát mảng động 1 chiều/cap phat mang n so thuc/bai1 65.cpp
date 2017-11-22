#include <stdio.h>
#include <stdlib.h>

//cap phat mang n so thuc

void Xuat(float* a, int n)//binh thuong
{
	for (int i = 0; i < n; i++)
	{
		printf("%f\t", a[i]);
	}
}

float* Nhap( int &n)
{
	printf("nhap n: ");
	scanf_s("%d", &n);
	if (n <= 0)
		return NULL;
	float* a = (float*)calloc(n, sizeof(float));
	for (int i = 0; i < n; i++)
	{
		printf("nhap phan tu thu %d: ", i);
		scanf_s("%f", &a[i]);
	}
	return a;

}

void Nhap2222(float* &a,int &n)//phai co dau & de a thay doi
{
	printf("nhap n: ");
	scanf_s("%d", &n);
	
	a = (float*)calloc(n, sizeof(float));
	for (int i = 0; i < n; i++)
	{
		printf("nhap phan tu thu %d: ", i);
		scanf_s("%f", &a[i]);
	}
}
 // cap phat mang n so thuc dung bien cau truc
typedef struct
{
	int n;
	float* member;
}floatarr;

void CapPhat(floatarr* a, int n)
{
	a->n = n;
	a->member = (float*)calloc(n, sizeof(float));
}

void NHAP1(floatarr* a)
{ 
	int m;
	printf("nhap m: ");
	scanf_s("%d", &m);
	CapPhat(a, m);
	for (int i = 0; i < a->n; i++)
	{
		printf("nhap phan tu thu %d: ", i);
		scanf_s("%f", &(a->member[i]));
	}

}
void FREE(floatarr* a)
{
	free(a->member);
}

void XUAT1(floatarr* a)
{
	for (int i = 0; i < a->n; i++)
	{
		printf("%f\t", (a->member[i]));
	}
}


void main()
{
	float* a;
	int n;
	//a= Nhap(n);
	//Nhap2222(a, n);
	Xuat(a, n);
	free(a);

	/*floatarr a;
	NHAP1(&a);
	XUAT1(&a);
	FREE(&a);*/


}