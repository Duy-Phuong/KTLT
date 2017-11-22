#include "Library.h"

// hàm tìm ước số chung lớn nhất để tối giản phân số
int TimUCLN(int x, int y){
	if (x%y == 0)
		reTurn y;
	else
		TimUCLN(y, x%y);
}
// Tạo dãy các phân số
void TaoDayPhanSo(SPhanSo *&p, int &np){
	srand(time(NULL));
	cout << "Nhap so luong phan so trong day: ";
	cin >> np;
	cout << endl;

	long x;
	int i = 0;
	p = (SPhanSo*)calloc(np, sizeof(SPhanSo));
	while (i < np){
		x = rand() % 10;
		if (x != 0){
			p[i].Tu = x;
			x = rand() % 10;
			if (x != 0){
				p[i].Mau = x;
				i++;
			}
		}
	}
}
// xuất dãy phân số ra màn hình
void XuatDayPhanSo(SPhanSo *p, int np){
	for (int i = 0; i < np; i++){
		cout << p[i].Tu << "/" << p[i].Mau;
	}
}
// hàm rút gọn phân sô
void RutGonPhanSo(SPhanSo &x){
	int k = TimUCLN(x.Tu, x.Mau);
	x.Tu /= k;
	x.Mau /= k;
}
// function cộng hai phân số
SPhanSo TongHaiPhanSo(SPhanSo x, SPhanSo y){
	SPhanSo k;
	k.Tu = (x.Tu*y.Mau) + (y.Tu*x.Mau);
	k.Mau = (x.Mau*y.Mau);
	RutGonPhanSo(k);
	reTurn k;
}
// function trừ hai phân số
SPhanSo HieuHaiPhanSo(SPhanSo x, SPhanSo y){
	x.Tu = x.Tu*-1;
	SPhanSo k;
	k.Tu = (x.Tu*y.Mau) + (y.Tu*x.Mau);
	k.Mau = (x.Mau*y.Mau);
	RutGonPhanSo(k);
	return k;
}
// quy đồng 2 phân số
SPhanSo QuyDong(SPhanSo p1, SPhanSo p2)
{
	SPhanSo k;
	//p3.Mau = 1;
	if (p1.Mau % p2.Mau == 0) // mẫu số bằng nhau
	{
		int x = p1.Mau / p2.Mau;
		p2.Tu = x * p2.Tu;//phai cho ra truoc vi khi tinh Mau se thay doi
		p2.Mau = x * p2.Mau;

	}
	else if (p2.Mau % p1.Mau == 0)
	{
		int x = p2.Mau / p1.Mau;
		p1.Mau = x * p1.Mau;
		p1.Tu = x * p1.Tu;
	}
	else if (p1.Mau % p2.Mau != 0 || p2.Mau % p1.Mau != 0)
	{
		p1.Tu = p1.Tu* p2.Mau;
		p2.Tu = p2.Tu*p1.Mau; //dat truoc vi khong se bi sai
		p1.Mau = p2.Mau * p1.Mau;
		p2.Mau = p1.Mau;

	}
}
void tich(SPhanSo p1, SPhanSo p2, SPhanSo &p3)
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
void thuong(SPhanSo p1, SPhanSo p2, SPhanSo &p3)
{
	hoanvi(p2.tu, p2.mau);
	tich(p1, p2, p3);
	RutGonPS(p3);
}
bool ktPSamduong(SPhanSo p)
{
	if (p.tu < 0 || p.mau < 0)
	{
		return false;// ps am
	}
	return true;// ps duong
}
void sosanh(SPhanSo p1, SPhanSo p2)
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
bool ktpsToiGian(SPhanSo p)
{
	//neu tu = mau = 1??
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