#include <iostream>

using namespace std;

typedef struct
{
	int tu;
	int mau;
}SPHANSO;

void nhap(SPHANSO &p)
{
	cout << "nhap tu so: \n";
	cin >> p.tu;
	cout << "nhap mau so: \n";
	cin >> p.mau;
}

void xuat(SPHANSO p)
{
	cout << "phan so co dang: " << p.tu << "/" << p.mau << endl;
}

void rutgon(SPHANSO &p)
{
	int n = (p.tu <= p.mau) ? p.tu : p.mau;
	for (int i = 2; i <= n; i++)
	{
		while (p.tu % i == 0 && p.mau %i == 0)
		{
			p.tu /= i;
			p.mau /= i;
		}
	}
}

void quydong(SPHANSO &p1, SPHANSO &p2)
{
	p1.tu = p1.tu* p2.mau;
	p2.tu = p2.tu*p1.mau; //dat truoc vi khong se bi sai
	p1.mau = p2.mau * p1.mau;
	p2.mau = p1.mau;
}
void main()
{
	SPHANSO p1;
	nhap(p1);
	xuat(p1);
	//rutgon(p1);

	SPHANSO p2;
	nhap(p2);
	xuat(p2);

	/*quydong(p1, p2);
	xuat(p1);
	xuat(p2);*/

}