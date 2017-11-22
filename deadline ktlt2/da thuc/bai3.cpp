#include <stdio.h>
#include <stdlib.h>
/*
Nhập vào 2 đa thức rồi tính tổng, hiệu, tích, thương của
2 đa thức đó, kết quả trả về là 1 đa thức mới.

Yêu cầu: Phải xuất ra đầy đủ định dạng của 1 đa thức.

ĐA THỨC CÓ DẠNG: a0 * x^0 + a1 * x^1 + a2 * x^2 + ... + an * x^n
Dữ liệu trong đa thức sẽ có:
- Số bậc cao nhất của đa thức (n).
- Danh sách các hệ số của đa thức (từ a0 --> an).

Yêu cầu: Phải xuất ra theo đúng định dạng.
vd:
Đa thức 1: 1 + 2 * x^1 + 3 * x^2
Đa thức 2: 4 + 5 * x^1 + 6 * x^2 + 7 * x ^ 3
=> Đa thức 1 + Đa thức 2 = 5 + 7 * x^1 + 9 * x^2 + 7 * x^3
=> Đa thức 1 - Đa thức 2 = -3 - 3 * x^1 - 3 * x^2 - 7 * x^3
=> Đa thức 1 * Đa thức 2 = 4 + 13 * x^1 + 28 * x^2 + 34 * x^3 + 32 * x^4 + 21 * x^5.
=> Đa thức 1 / Đa thức 2: Tự nháp.
*/


typedef struct
{
	int n; // Số bậc cao nhất của đa thức.
	float *HeSo; // Mảng danh sách các hệ số.
}SDATHUC;


void NhapDaThuc(SDATHUC *x)
{
	do
	{
		printf("\nNhap vao so bac cua da thuc: ");
		scanf("%d", &x->n);

		if (x->n < 1)
		{
			printf("\nSo bac cua da thuc phai >= 1. Xin kiem tra lai !");
		}
	} while (x->n < 1);

//	x->HeSo = new float[x->n + 1];
	x->HeSo = (float*)malloc((x->n + 1) * sizeof(float));
	for (int i = 0; i <= x->n; i++)
	{
		printf("\nNhap vao he so thu %d la: ", i);
		scanf("%f", &x->HeSo[i]);
	}
}

void XuatDaThuc(SDATHUC* x)
{
	if (x->n == 1)
	{
		//cout << x->HeSo[0] << " + ";
		//cout << x->HeSo[1] << " * x";
		printf("\n%f + %f * x\n", x->HeSo[0], x->HeSo[1]);
	}
	else
	{
		//cout << x->HeSo[0] << " + ";
		//cout << x->HeSo[1] << " * x + ";
		printf("\n%f + %f * x + ", x->HeSo[0], x->HeSo[1]);
		for (int i = 2; i < x->n; i++)
		{
			//cout << x->HeSo[i] << " * x^" << i << " + ";
			printf("%f * x^ %d + ", x->HeSo[i], i);
		}
		//cout << x->HeSo[x->n] << " * x^" << x->n;
		printf("%f * x^%d\n", x->HeSo[x->n], x->n);
	}
}

void tinhtong(SDATHUC *a, SDATHUC *b, SDATHUC *c)
{
	if (a->n < b->n)
	{
		c->n = b->n;
		c->HeSo = (float*)calloc(c->n + 1, sizeof(float));
		for (int i = 0; i <= c->n; i++)
		{
			if (i <= a->n)
			{
			//	printf("%f %f", a->HeSo[i], b->HeSo[i]);
				c->HeSo[i] = a->HeSo[i] + b->HeSo[i];
			}
			else
			{
				c->HeSo[i] = b->HeSo[i];
			}
		}
	}
	else //if (a->n >= b->n)
	{
		c->n = a->n;
		c->HeSo = (float*)calloc(c->n + 1, sizeof(float));//cap phat
		for (int i = 0; i <= c->n; i++)
		{
			if (i <= b->n)
			{
				//	printf("%f %f", a->HeSo[i], b->HeSo[i]);
				c->HeSo[i] = a->HeSo[i] + b->HeSo[i];
			}

			else
			{
				c->HeSo[i] = a->HeSo[i];
			}
		}
	}
	XuatDaThuc(c);
}

void tinhhieu(SDATHUC *a, SDATHUC *b, SDATHUC *c)
{
	if (a->n < b->n)
	{
		c->n = b->n;
		c->HeSo = (float*)calloc(c->n, sizeof(float));
		for (int i = 0; i <= c->n; i++)
		{
			if (i <= a->n)
			{
				//	printf("%f %f", a->HeSo[i], b->HeSo[i]);
				c->HeSo[i] = a->HeSo[i] - b->HeSo[i];
			}
			else
			{
				c->HeSo[i] = -b->HeSo[i];//am
			}
		}
	}
	else //if (a->n >= b->n)
	{
		c->n = a->n;
		c->HeSo = (float*)calloc(c->n, sizeof(float));//cap phat
		for (int i = 0; i <= c->n; i++)
		{
			if (i <= b->n)
			{
				//	printf("%f %f", a->HeSo[i], b->HeSo[i]);
				c->HeSo[i] = a->HeSo[i] - b->HeSo[i];
			}

			else
			{
				c->HeSo[i] = -a->HeSo[i];
			}
		}
	}
	XuatDaThuc(c);
}

float TinhGiaTriDaThuc(SDATHUC* a, float x)
{
	float gt = a->HeSo[0];
	float lt = 1;
	for (int i = 1; i <= a->n; i++)
	{
		lt *= x;			//phai dat gia tri khac neu k thi khi chay ra thi x nhu cu
		gt += a->HeSo[i]*lt;
	}
	return gt;
}

SDATHUC* timdathucdaoham(SDATHUC *a)
{
	SDATHUC* daoham;
	daoham->HeSo = (float*)calloc(a->n, sizeof(float));//cap phat toi bac ham so -1
	if (a->n == 0)
	{
		daoham->n = 0;
		daoham->HeSo = 0;
		return daoham;
	}
	daoham->n = a->n - 1;
	for (int i = 0; i <= daoham->n; i++)
	{
		daoham->HeSo[i] = a->HeSo[i + 1] * (i + 1);
	}
	return daoham;
}
/*dathuc timdathucdaoham(dathuc f)
{
	dathuc daoham;
	if (f.n == 0)
	{
		daoham.n = 0;
		daoham.a[0] = 0;
		return daoham;
	}
	daoham.n = f.n - 1;
	for (int i = 0; i < daoham.n + 1; i++)
	{
		daoham.a[i] = f.a[i + 1] * (i + 1);
	}
	return daoham;
}

float tinhdaoham(dathuc f, float x)
{
	dathuc g = timdathucdaoham(f);
	return tinhgiatri(g, x);
}*/



void main()
{
	SDATHUC *x = new SDATHUC;
	SDATHUC *y = new SDATHUC;
	SDATHUC *z = new SDATHUC;
	//SDATHUC n;
	NhapDaThuc(x);
	XuatDaThuc(x);

	//NhapDaThuc(y);
	//XuatDaThuc(y);

	//tinhtong(x, y, z);
	//float k= TinhGiaTriDaThuc(x, 2);
	//printf("%f\n", k);
	y = timdathucdaoham(x);
	XuatDaThuc(y);
	delete x;
	delete y;
	delete z;
}