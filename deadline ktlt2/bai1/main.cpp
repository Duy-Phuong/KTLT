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
	scanf("%d", &p.tu);
	printf("\nnhap mau so (khac 0): ");
	scanf("%d", &p.mau);
}

void Xuat(SPHANSO p)
{
	printf("\nphan so co dang la: %d/%d\n", p.tu, p.mau);
}

void RutGonPS(SPHANSO &p)
{
	if (p.tu <= p.mau)
	{
		for (int i = 2; i <= p.tu; i++)
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
	else
	{
		for (int i = 2; i <= p.mau; i++)
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

void tong(SPHANSO p1, SPHANSO p2, SPHANSO &p3)
{
	//quydong(p1, p2);
	p3.tu = p1.tu + p2.tu;
	p3.mau = p1.mau;
}

void hieu(SPHANSO p1, SPHANSO p2, SPHANSO &p3)
{
	//quydong(p1, p2);
	p3.tu = p1.tu - p2.tu;
	p3.mau = p1.mau;
}

void tich(SPHANSO p1, SPHANSO p2, SPHANSO &p3)
{
	p3.tu = p1.tu * p2.tu;
	p3.mau = p1.mau * p2.mau;
	RutGonPS(p3);
}
void hoanvi(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}
void thuong(SPHANSO p1, SPHANSO p2, SPHANSO &p3)
{
	hoanvi(p2.tu, p2.mau);
	tich(p1, p2, p3);
	RutGonPS(p3);
}

bool ktPSamduong(SPHANSO p)
{
	if (p.tu < 0 || p.mau < 0)
	{
		return false;// ps am
	}
	return true;// ps duong
}

void sosanh(SPHANSO p1, SPHANSO p2)
{
	quydong(p1, p2);
	if (p1.tu < p2.tu)
	{
		printf("phan so 1 nho hon phan so 2!\n");
	}
	else
	{
		if (p1.tu > p2.tu)
		{
			printf("phan so 2 nho hon phan so 1!\n");
		}
		else
		{
			printf("hai phan so bang nhau!\n");
		}
	}
}

bool ktpsToiGian(SPHANSO p)
{
	//neu tu = mau = 1?? int n = (p.tu < p.mau) ? p.tu : p.mau;
	if (p.tu <= p.mau)
	{
		for (int i = 2; i <= p.tu; i++)
		{
			if (p.tu % i == 0 && p.mau % i == 0)
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = 2; i <= p.mau; i++)
		{
			if (p.tu % i == 0 && p.mau % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}
void main()
{
	/*SPHANSO p;
	NhapPS(p);
	Xuat(p);
	RutGonPS(p);
	printf("phan so do co dang : %d/%d \n", p.tu, p.mau);*/

	//quy dong
	SPHANSO p1;
	SPHANSO p2;
	SPHANSO p3;
	NhapPS(p1);
	NhapPS(p2);
	/*quydong(p1, p2);
	Xuat(p1);
	Xuat(p2);*/
	//hieu(p1, p2, p3);
	//tich(p1, p2, p3);
	//thuong(p1, p2, p3);//k co quy dong trk thuong
	//Xuat(p3);
	sosanh(p1, p2);

}