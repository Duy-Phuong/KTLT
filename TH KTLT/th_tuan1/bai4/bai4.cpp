#include <stdio.h>

//A. PHAN SO
//1.khai bao
typedef struct
{
	int tu, mau;
}SPHANSO;

void NhapPS(SPHANSO &p)
{
	printf("\nnhap tu so: ");
	scanf_s("%d", &p.tu);
	printf("\nnhap mau so (khac 0): ");
	scanf_s("%d", &p.mau);
}

void Xuat(SPHANSO p)
{
	printf("\nphan so co dang la: %d/%d\n", p.tu, p.mau);
}

void RutGonPS(SPHANSO &p)
{
	int n = (p.tu <= p.mau) ? p.tu : p.mau;
		for (int i = 2; i <= n; i++)
		{
			if (p.tu % i == 0 && p.mau % i == 0)
			{
				while (p.tu % i == 0 && p.mau % i == 0)
				{
					p.tu = p.tu / i;
					p.mau = p.mau / i;
				}
			}
		}
}

void quydong(SPHANSO &p1, SPHANSO &p2)
{
	//p3.mau = 1;
	if (p1.mau % p2.mau == 0)
	{
		int x = p1.mau / p2.mau;
		p2.tu = x * p2.tu;//phai cho ra truoc vi khi tinh mau se thay doi
		p2.mau = x * p2.mau;

	}
	else if (p2.mau % p1.mau == 0)
	{
		int x = p2.mau / p1.mau;
		p1.mau = x * p1.mau;
		p1.tu = x * p1.tu;
	}
	else if (p1.mau % p2.mau != 0 || p2.mau % p1.mau != 0)
	{
		p1.tu = p1.tu* p2.mau;
		p2.tu = p2.tu*p1.mau; //dat truoc vi khong se bi sai
		p1.mau = p2.mau * p1.mau;
		p2.mau = p1.mau;

	}
}

SPHANSO tong(SPHANSO p1, SPHANSO p2)
{
	SPHANSO p3;
	quydong(p1, p2);
	p3.tu = p1.tu + p2.tu;
	p3.mau = p1.mau;
	return p3;
}

void nhap1mangPS(SPHANSO p[100], int &n)
{
	printf("nhap n: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		NhapPS(p[i]);
	}
}

void xuatcacPS(SPHANSO p[100], int n)
{
	for (int i = 0; i < n; i++)
	{
		Xuat(p[i]);
	}
}

SPHANSO TONGPS(SPHANSO p[100], int n)
{
	
	SPHANSO s = p[0];
	for (int i = 1; i < n; i++)
	{
		s = tong(p[i], s);
	
	}
	return s;
	//Xuat(s);
}
void main()
{
	SPHANSO p[100];
	int n;
	nhap1mangPS(p, n);
	xuatcacPS(p, n);
	SPHANSO p4;
	p4 = TONGPS(p, n);
	Xuat(p4);
}