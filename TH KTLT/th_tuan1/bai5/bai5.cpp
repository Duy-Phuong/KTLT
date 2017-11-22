#include <stdio.h>

typedef struct
{
	char hoten[100];
	char mssv[100];
	float toan, nmlt, ktlt;
}SV;

void nhap1sv(SV &p)
{
	printf("\nnhap thong tin sv: ");
	fflush(stdin);
	printf("\nnhap ho ten: ");
	gets(p.hoten);
	printf("nhap mssv: ");
	gets(p.mssv);
	printf("nhap diem toan: ");
	scanf("%f", &p.toan);
	printf("nhap diem nmlt: ");
	scanf("%f", &p.nmlt);
	printf("nhap diem ktlt: ");
	scanf("%f", &p.ktlt);
}
void nhap(SV a[100], int &n)
{
	printf("nhap so sinh vien: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		nhap1sv(a[i]);
	}
}

void xuat(SV p)
{
	printf("sinh vien co diem cao nhat la:\n");
	puts(p.hoten);
	puts(p.mssv);
	printf("diem toan: %f\n", p.toan);
}

float tinhdiemtb(float a, float b, float c)
{
	return (a + b + c) / 3;
}

float timsv(SV a[100], int n)//tim dtb max
{

	int max = -1;
	for (int i = 1; i < n; i++)
	{
		if (a[i].toan >= 5)
		{
			if (max == -1 || tinhdiemtb(a[i].toan, a[i].nmlt, a[i].ktlt) > max)
			{
				max = tinhdiemtb(a[i].toan, a[i].nmlt, a[i].ktlt);
			}
		}
	}
	return max;
}

void xuatthongtin(SV a[100], int n)
{
	int max = timsv(a, n);
	if (max == -1)
	{
		printf("khong co sinh vien nao!\n");
	}
	for (int i = 0; i < n; i++)
	{
		if (tinhdiemtb(a[i].toan, a[i].nmlt, a[i].ktlt) == max && a[i].toan > 5)//loai tru nhung th bang mã nhung toán < 5
		{
			xuat(a[i]);
		}
		
	}
}
void main()
{
	SV a[100];
	int n;
	nhap(a, n);
	xuatthongtin(a, n);
}