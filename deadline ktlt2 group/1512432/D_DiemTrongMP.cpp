#include "Library.h"

void nhap(SDiem2D &a)
{
	printf("nhap hoanh do: ");
	scanf("%d", &a.x);
	printf("nhap tung do: ");
	scanf("%d", &a.y);
}

void xuat(SDiem2D a)
{
	printf("\n(%d, %d)", a.x, a.y);
}

float tinhkhoangcach(SDiem2D a1, SDiem2D a2)
{
	return sqrt((float)(a1.x - a2.x)*(a1.x - a2.x) + (a1.y - a2.y)*(a1.y - a2.y));
}

void DiemDoiXung(SDiem2D a1, SDiem2D &a2)
{
	a2.x = -a1.x;
	a2.y = -a1.y;
}

void kiemtra(SDiem2D a)
{
	if (a.x > 0 && a.y > 0)
	{
		printf("diem a thuoc goc phan tu thu I\n");
	}
	else if (a.x < 0 && a.y < 0)
	{
		printf("diem a thuoc goc phan tu thu III\n");
	}
	if (a.x < 0 && a.y > 0)
	{
		printf("diem a thuoc goc phan tu thu II\n");
	}
	else if (a.x > 0 && a.y < 0)
	{
		printf("diem a thuoc goc phan tu thu IV\n");
	}
}


//tam giac
void NhapToaDoDinh(SDiem2D a[3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("\nnhap diem thu %d: ", i + 1);
		nhap(a[i]);
	}
}